#!/usr/bin/env python3
"""Generates <basename>.hpp/.cpp from a command-tree YAML file.

Usage: generate_commands.py <commands.yaml> <output_dir> [basename]
  basename defaults to "commands_generated" if not given.

Builds a character-level trie: each leaf's full path (its ancestor keys
joined by single spaces, plus one trailing space) becomes a literal
sequence of state transitions. The state reached right after that
literal sequence is an "argument state" for that leaf -- from there,
every character up to \\n is appended to a buffer; \\n triggers parsing
the buffer per the leaf's declared type and calling its driver function.
"""

import os
import sys
import yaml

TYPE_INFO = {
    "float": {"cpp_type": "float", "parse_expr": "strtof(ctx->arg_buffer, nullptr)"},
    "bool":  {"cpp_type": "bool",  "parse_expr": 'strcmp(ctx->arg_buffer, "on") == 0'},
    # Zero-argument trigger commands (e.g. "prc ignite"): fires as soon as
    # \n is typed right after the literal path, no argument buffered at
    # all -- cpp_type is None rather than a real type, so the driver
    # function takes no value parameter (just void* ctx).
    "void":  {"cpp_type": None,   "parse_expr": None},
}

ARG_BUFFER_SIZE = 32  # usable chars; +1 more reserved for the NUL terminator


class TrieNode:
    def __init__(self, node_id):
        self.id = node_id
        self.children = {}      # char -> TrieNode
        self.arg_leaf = None    # (type, function) if this is an argument state


def flatten(node, prefix, leaves):
    type_keys = [k for k in node.keys() if k.startswith("%") and k != "%run"]
    if len(type_keys) == 1 and len(node) == 1:
        type_name = type_keys[0][1:]  # strip leading '%'
        function = node[type_keys[0]]["%run"]
        leaves.append((prefix, type_name, function))
        return
    for key, child in node.items():
        child_prefix = prefix + (" " if prefix else "") + key
        flatten(child, child_prefix, leaves)

def build_trie(leaves):
    next_id = [0]

    def new_node():
        node = TrieNode(next_id[0])
        next_id[0] += 1
        return node

    root = new_node()

    for path, type_name, function in leaves:
        if type_name not in TYPE_INFO:
            sys.exit(f"unknown type '{type_name}' for command '{path}'")
        # Trailing space separates the command name from its argument
        # (e.g. "main lox " then "open") -- but void commands take no
        # argument at all, so there's nothing for a user to type after
        # the command name, and requiring that space before \n anyway
        # means the command could never actually be typed naturally.
        is_void = TYPE_INFO[type_name]["parse_expr"] is None
        literal = path if is_void else path + " "
        node = root
        for ch in literal:
            if ch not in node.children:
                node.children[ch] = new_node()
            node = node.children[ch]
        node.arg_leaf = (type_name, function)

    return root, next_id[0]


def collect_states(root):
    states = []
    stack = [root]
    seen = set()
    while stack:
        node = stack.pop()
        if node.id in seen:
            continue
        seen.add(node.id)
        states.append(node)
        stack.extend(node.children.values())
    states.sort(key=lambda n: n.id)
    return states


def generate_header(states, leaves, basename):
    functions = sorted({(f, t) for (_, t, f) in leaves})

    lines = []
    lines.append("// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.")
    lines.append("#pragma once")
    lines.append("")
    lines.append("#include <cstdint>")
    lines.append("")
    lines.append("#include <cstdlib>")
    lines.append("")
    lines.append("#include <cstring>")
    lines.append("")
    lines.append("enum State {")
    for s in states:
        lines.append(f"    State_{s.id},")
    lines.append("};")
    lines.append("")
    lines.append("struct driver {")
    for function, type_name in functions:
        cpp_type = TYPE_INFO[type_name]["cpp_type"]
        if cpp_type is None:
            lines.append(f"    void (*{function})(void* ctx);")
        else:
            lines.append(f"    void (*{function})(void* ctx, {cpp_type} value);")
    lines.append("};")
    lines.append("")
    lines.append("struct context {")
    lines.append("    State state = State_0;")
    lines.append(f"    char arg_buffer[{ARG_BUFFER_SIZE + 1}];")
    lines.append("    uint8_t arg_len = 0;")
    lines.append("    void* handler_ctx = nullptr;")
    lines.append("};")
    lines.append("")
    lines.append("void push_char(context* ctx, const driver* drv, char c);")
    lines.append("")
    return "\n".join(lines)


def generate_source(states, basename):
    lines = []
    lines.append("// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.")
    lines.append(f'#include "{basename}.hpp"')
    lines.append("")
    lines.append("#include <cstdlib>")
    lines.append("")
    lines.append("void push_char(context* ctx, const driver* drv, char c) {")
    lines.append("    switch (ctx->state) {")

    for s in states:
        lines.append(f"    case State_{s.id}: {{")
        if s.arg_leaf is not None:
            type_name, function = s.arg_leaf
            parse_expr = TYPE_INFO[type_name]["parse_expr"]
            if parse_expr is None:
                # void: fires immediately on \n, no argument buffered.
                # Any other character just resets to State_0 -- a trigger
                # command takes no argument, so "prc ignite x\n" is
                # treated as a mistyped command rather than silently
                # firing anyway.
                lines.append("        if (c == '\\n') {")
                lines.append(f"            drv->{function}(ctx->handler_ctx);")
                lines.append("            ctx->state = State_0;")
                lines.append("        } else {")
                lines.append("            ctx->state = State_0;")
                lines.append("        }")
            else:
                lines.append("        if (c == '\\n') {")
                lines.append(f"            ctx->arg_buffer[ctx->arg_len] = '\\0';")
                lines.append(f"            drv->{function}(ctx->handler_ctx, {parse_expr});")
                lines.append("            ctx->state = State_0;")
                lines.append("            ctx->arg_len = 0;")
                lines.append(f"        }} else if (ctx->arg_len < {ARG_BUFFER_SIZE}) {{")
                lines.append("            ctx->arg_buffer[ctx->arg_len++] = c;")
                lines.append("        }")
        else:
            lines.append("        switch (c) {")
            for ch, child in sorted(s.children.items()):
                escaped = "' '" if ch == " " else f"'{ch}'"
                lines.append(f"        case {escaped}: ctx->state = State_{child.id}; break;")
            lines.append("        default: ctx->state = State_0; break;")
            lines.append("        }")
        lines.append("        break;")
        lines.append("    }")

    lines.append("    }")
    lines.append("}")
    lines.append("")
    return "\n".join(lines)


def main():
    if len(sys.argv) < 3:
        sys.exit(f"usage: {sys.argv[0]} <commands.yaml> <output_dir> [basename]")

    yaml_path = sys.argv[1]
    output_dir = sys.argv[2]
    basename = sys.argv[3] if len(sys.argv) > 3 else "commands_generated"

    with open(yaml_path) as f:
        tree = yaml.safe_load(f)

    leaves = []
    flatten(tree, "", leaves)

    root, _ = build_trie(leaves)
    states = collect_states(root)

    with open(os.path.join(output_dir, f"{basename}.hpp"), "w") as f:
        f.write(generate_header(states, leaves, basename))
    with open(os.path.join(output_dir, f"{basename}.cpp"), "w") as f:
        f.write(generate_source(states, basename))

    print(f"Generated {len(states)} states from {len(leaves)} command(s).")


if __name__ == "__main__":
    main()