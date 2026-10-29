#!/usr/bin/env python3
"""Generates <basename>.hpp/.cpp from a command-tree YAML file.

Usage: generate_commands.py <commands.yaml> <output_dir> [basename] [--namespace NAME]
  basename defaults to "commands_generated" if not given.
  --namespace wraps every emitted declaration and definition in
  namespace NAME { }, so two generated pairs can live in one binary.

Builds a character-level trie: each leaf's full path (its ancestor keys
joined by single spaces, plus one trailing space) becomes a literal
sequence of state transitions. The state reached right after that
literal sequence is an "argument state" for that leaf -- from there,
every character up to \\n is appended to a buffer; \\n triggers parsing
the buffer per the leaf's declared type and calling its driver function.

A character with no edge sends the parser to State_Sink, which only a
newline leaves, so "xfsm ignite" runs nothing. A bool argument must be
open, close, on or off; anything else runs nothing and calls the optional
driver member on_bad_argument if it is bound. A non-empty line that matches
no command calls the optional driver member on_unknown_command if it is
bound.
"""

import argparse
import os
import sys
import yaml

TYPE_INFO = {
    "int":   {"cpp_type": "int", "parse_expr": "strtol(ctx->arg_buffer, nullptr, 10)"},
    "float": {"cpp_type": "float", "parse_expr": "strtof(ctx->arg_buffer, nullptr)"},
    # bool is emitted by its own branch in generate_source: true for open or
    # on, false for close or off, anything else is a bad argument.
    "bool":  {"cpp_type": "bool",  "parse_expr": None},
    # Zero-argument trigger commands (e.g. "prc ignite"): fires as soon as
    # \n is typed right after the literal path, no argument buffered at
    # all -- cpp_type is None rather than a real type, so the driver
    # function takes no value parameter (just void* ctx).
    "void":  {"cpp_type": None,   "parse_expr": None},
}

ARG_BUFFER_SIZE = 32  # usable chars; +1 more reserved for the NUL terminator

BAD_ARGUMENT = "on_bad_argument"  # optional driver members, always emitted last
UNKNOWN_COMMAND = "on_unknown_command"
RESERVED = (BAD_ARGUMENT, UNKNOWN_COMMAND)
BOOL_TRUE = ("open", "on")
BOOL_FALSE = ("close", "off")

CPP_KEYWORDS = frozenset("""
alignas alignof and and_eq asm auto bitand bitor bool break case catch char
char8_t char16_t char32_t class compl concept const consteval constexpr
constinit const_cast continue co_await co_return co_yield decltype default
delete do double dynamic_cast else enum explicit export extern false float for
friend goto if inline int long mutable namespace new noexcept not not_eq
nullptr operator or or_eq private protected public register reinterpret_cast
requires return short signed sizeof static static_assert static_cast struct
switch template this thread_local throw true try typedef typeid typename union
unsigned using virtual void volatile wchar_t while xor xor_eq
""".split())


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
        is_void = type_name == "void"
        literal = path if is_void else path + " "
        node = root
        for ch in literal:
            if node.arg_leaf is not None:
                sys.exit(f"command '{path}' extends another command that ends at a prefix of it")
            if ch not in node.children:
                node.children[ch] = new_node()
            node = node.children[ch]
        if node.arg_leaf is not None:
            sys.exit(f"duplicate command '{path}'")
        if node.children:
            sys.exit(f"command '{path}' is a prefix of another command")
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


def generate_header(states, leaves, basename, namespace=None):
    functions = sorted({(f, t) for (_, t, f) in leaves})
    seen = {}
    for function, type_name in functions:
        if function in RESERVED:
            sys.exit(f"function name '{function}' is reserved for an optional driver callback")
        if seen.setdefault(function, type_name) != type_name:
            sys.exit(f"function '{function}' is used with two types: {seen[function]} and {type_name}")

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
    if namespace:
        lines.append(f"namespace {namespace} {{")
        lines.append("")
    lines.append("enum State {")
    for s in states:
        lines.append(f"    State_{s.id},")
    lines.append("    State_Sink,")
    lines.append("};")
    lines.append("")
    lines.append("struct driver {")
    for function, type_name in functions:
        cpp_type = TYPE_INFO[type_name]["cpp_type"]
        if cpp_type is None:
            lines.append(f"    void (*{function})(void* ctx);")
        else:
            lines.append(f"    void (*{function})(void* ctx, {cpp_type} value);")
    lines.append("    // Optional: called when a bool argument is not open, close, on or off.")
    lines.append(f"    void (*{BAD_ARGUMENT})(void* ctx) = nullptr;")
    lines.append("    // Optional: called when a non-empty line matches no command.")
    lines.append(f"    void (*{UNKNOWN_COMMAND})(void* ctx) = nullptr;")
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
    if namespace:
        lines.append(f"}}  // namespace {namespace}")
        lines.append("")
    return "\n".join(lines)


def generate_source(states, basename, namespace=None):
    lines = []
    lines.append("// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.")
    lines.append(f'#include "{basename}.hpp"')
    lines.append("")
    lines.append("#include <cstdlib>")
    lines.append("")
    if namespace:
        lines.append(f"namespace {namespace} {{")
        lines.append("")
    lines.append("void push_char(context* ctx, const driver* drv, char c) {")
    lines.append("    switch (ctx->state) {")

    for s in states:
        lines.append(f"    case State_{s.id}: {{")
        if s.arg_leaf is not None:
            type_name, function = s.arg_leaf
            parse_expr = TYPE_INFO[type_name]["parse_expr"]
            if type_name == "void":
                # void: fires immediately on \n, no argument buffered.
                # Any other character goes to State_Sink -- a trigger
                # command takes no argument, so "prc ignite x\n" is
                # treated as a mistyped command rather than silently
                # firing anyway.
                lines.append("        if (c == '\\n') {")
                lines.append(f"            drv->{function}(ctx->handler_ctx);")
                lines.append("            ctx->state = State_0;")
                lines.append("        } else {")
                lines.append("            ctx->state = State_Sink;")
                lines.append("        }")
            elif type_name == "bool":
                def words(ws):
                    return " || ".join(f'strcmp(ctx->arg_buffer, "{w}") == 0' for w in ws)
                lines.append("        if (c == '\\n') {")
                lines.append(f"            ctx->arg_buffer[ctx->arg_len] = '\\0';")
                lines.append(f"            if ({words(BOOL_TRUE)}) {{")
                lines.append(f"                drv->{function}(ctx->handler_ctx, true);")
                lines.append(f"            }} else if ({words(BOOL_FALSE)}) {{")
                lines.append(f"                drv->{function}(ctx->handler_ctx, false);")
                lines.append(f"            }} else if (drv->{BAD_ARGUMENT} != nullptr) {{")
                lines.append(f"                drv->{BAD_ARGUMENT}(ctx->handler_ctx);")
                lines.append("            }")
                lines.append("            ctx->state = State_0;")
                lines.append("            ctx->arg_len = 0;")
                lines.append(f"        }} else if (ctx->arg_len < {ARG_BUFFER_SIZE}) {{")
                lines.append("            ctx->arg_buffer[ctx->arg_len++] = c;")
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
            # A newline with no edge ends a mistyped or partial command
            # (reported, except an empty line at the root); any other
            # unknown character waits in State_Sink for it.
            if s.id == 0:
                lines.append("        case '\\n': ctx->state = State_0; break;")
            else:
                lines.append("        case '\\n':")
                lines.append("            ctx->state = State_0;")
                lines.append(f"            if (drv->{UNKNOWN_COMMAND} != nullptr) drv->{UNKNOWN_COMMAND}(ctx->handler_ctx);")
                lines.append("            break;")
            lines.append("        default: ctx->state = State_Sink; break;")
            lines.append("        }")
        lines.append("        break;")
        lines.append("    }")

    lines.append("    case State_Sink: {")
    lines.append("        if (c == '\\n') {")
    lines.append("            ctx->state = State_0;")
    lines.append(f"            if (drv->{UNKNOWN_COMMAND} != nullptr) drv->{UNKNOWN_COMMAND}(ctx->handler_ctx);")
    lines.append("        }")
    lines.append("        break;")
    lines.append("    }")
    lines.append("    }")
    lines.append("}")
    lines.append("")
    if namespace:
        lines.append(f"}}  // namespace {namespace}")
        lines.append("")
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Generate the command parser from a command-tree YAML file.")
    parser.add_argument("yaml_path", metavar="commands.yaml")
    parser.add_argument("output_dir")
    parser.add_argument("basename", nargs="?", default="commands_generated")
    parser.add_argument("--namespace", metavar="NAME", help="wrap the emitted code in namespace NAME { }")
    args = parser.parse_args()

    yaml_path = args.yaml_path
    output_dir = args.output_dir
    basename = args.basename
    namespace = args.namespace
    if namespace is not None and (not namespace.isidentifier() or namespace in CPP_KEYWORDS):
        sys.exit(f"namespace '{namespace}' is not a C++ identifier")

    with open(yaml_path) as f:
        tree = yaml.safe_load(f)

    leaves = []
    flatten(tree, "", leaves)

    root, _ = build_trie(leaves)
    states = collect_states(root)

    with open(os.path.join(output_dir, f"{basename}.hpp"), "w", newline="\n") as f:
        f.write(generate_header(states, leaves, basename, namespace))
    with open(os.path.join(output_dir, f"{basename}.cpp"), "w", newline="\n") as f:
        f.write(generate_source(states, basename, namespace))

    print(f"Generated {len(states)} states from {len(leaves)} command(s).")


if __name__ == "__main__":
    main()