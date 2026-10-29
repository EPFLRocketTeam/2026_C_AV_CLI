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
    for s in sum(state_groups(states), []):
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


def state_groups(states):
    """Split the states into literal, void argument and typed argument states.

    The State enum lists them in that order (root first, so State_0 stays 0
    and a zeroed context is at the root), then State_Sink. push_char then
    tells the three kinds apart with two range checks and dispatches each
    kind through its own dense switch, so the state independent handling
    (newline, sink, argument buffer) is emitted once instead of per state.
    """
    literal = [s for s in states if s.arg_leaf is None]
    void = [s for s in states if s.arg_leaf is not None and s.arg_leaf[0] == "void"]
    typed = [s for s in states if s.arg_leaf is not None and s.arg_leaf[0] != "void"]
    return literal, void, typed


def state_groups(states):
    """Split the states into literal, void argument and typed argument states.

    The State enum lists them in that order (root first, so State_0 stays 0
    and a zeroed context is at the root), then State_Sink. push_char tells
    the three kinds apart with two range checks and dispatches each kind
    through its own dense switch, so the state independent handling
    (newline, sink, argument buffer) is emitted once instead of per state.
    """
    literal = [s for s in states if s.arg_leaf is None]
    void = [s for s in states if s.arg_leaf is not None and s.arg_leaf[0] == "void"]
    typed = [s for s in states if s.arg_leaf is not None and s.arg_leaf[0] != "void"]
    return literal, void, typed


# Local function pointer per argument type in push_char's argument switches.
POINTER = {"void": "fn_void", "bool": "fn_bool", "int": "fn_int", "float": "fn_float"}


def generate_source(states, basename, namespace=None):
    """Emit push_char.

    Per state code is only what depends on the state: a literal state's
    edges, and for an argument state which driver member to call. The
    argument switches only pick that member into a local pointer; the
    guarded call happens once per argument type after the switch, so a
    board that binds only part of the driver gets a silent no op instead of
    a jump through nullptr, at the cost of one check per type rather than
    one per command. Everything else is emitted once: a typed argument state
    appends any character but a newline to the buffer, a newline in a
    literal state or State_Sink ends the line as an unknown command (unless
    the line was empty), and any character with no edge goes to State_Sink.
    """
    literal, void, typed = state_groups(states)
    first_void = len(literal)
    first_typed = len(literal) + len(void)
    typed_kinds = sorted({s.arg_leaf[0] for s in typed})

    def pointer_decl(type_name):
        cpp_type = TYPE_INFO[type_name]["cpp_type"]
        args = "void*" if cpp_type is None else f"void*, {cpp_type}"
        return f"void (*{POINTER[type_name]})({args}) = nullptr;"

    lines = []
    lines.append("// GENERATED FILE -- do not edit by hand. Regenerate with generate_commands.py.")
    lines.append(f'#include "{basename}.hpp"')
    lines.append("")
    lines.append("#include <cstdlib>")
    lines.append("")
    if namespace:
        lines.append(f"namespace {namespace} {{")
        lines.append("")
    if "bool" in typed_kinds:
        words = lambda ws: " || ".join(f'strcmp(arg, "{w}") == 0' for w in ws)
        lines.append("// 1 for open or on, 0 for close or off, -1 for anything else.")
        lines.append("static int parse_bool(const char* arg) {")
        lines.append(f"    if ({words(BOOL_TRUE)}) return 1;")
        lines.append(f"    if ({words(BOOL_FALSE)}) return 0;")
        lines.append("    return -1;")
        lines.append("}")
        lines.append("")
    lines.append("void push_char(context* ctx, const driver* drv, char c) {")
    lines.append("    // State enum order: literal states, void argument states, typed")
    lines.append("    // argument states, State_Sink.")
    lines.append("    const int state = ctx->state;")
    lines.append("")

    if typed:
        lines.append(f"    if (state >= {first_typed} && state != State_Sink) {{")
        lines.append("        // typed argument state: buffer until the newline, then parse and call")
        lines.append("        if (c != '\\n') {")
        lines.append(f"            if (ctx->arg_len < {ARG_BUFFER_SIZE}) ctx->arg_buffer[ctx->arg_len++] = c;")
        lines.append("            return;")
        lines.append("        }")
        lines.append("        ctx->arg_buffer[ctx->arg_len] = '\\0';")
        lines.append("        ctx->state = State_0;")
        lines.append("        ctx->arg_len = 0;")
        for type_name in typed_kinds:
            lines.append(f"        {pointer_decl(type_name)}")
        if "bool" in typed_kinds:
            lines.append("        bool is_bool = false;")
        lines.append("        switch (state) {")
        for s in typed:
            type_name, function = s.arg_leaf
            extra = " is_bool = true;" if type_name == "bool" else ""
            lines.append(f"        case State_{s.id}: {POINTER[type_name]} = drv->{function};{extra} break;")
        lines.append("        }")
        branches = []
        if "bool" in typed_kinds:
            branches.append(("is_bool", [
                "const int value = parse_bool(ctx->arg_buffer);",
                f"if (value < 0) {{ if (drv->{BAD_ARGUMENT} != nullptr) drv->{BAD_ARGUMENT}(ctx->handler_ctx); }}",
                "else if (fn_bool != nullptr) fn_bool(ctx->handler_ctx, value == 1);",
            ]))
        for type_name in typed_kinds:
            if type_name == "bool":
                continue
            p = POINTER[type_name]
            parse_expr = TYPE_INFO[type_name]["parse_expr"]
            branches.append((f"{p} != nullptr", [f"{p}(ctx->handler_ctx, {parse_expr});"]))
        for i, (cond, body) in enumerate(branches):
            lines.append(f"        {'if' if i == 0 else '} else if'} ({cond}) {{")
            for b in body:
                lines.append(f"            {b}")
        lines.append("        }")
        lines.append("        return;")
        lines.append("    }")
        lines.append("")

    lines.append("    if (c == '\\n') {")
    lines.append("        ctx->state = State_0;")
    if void:
        lines.append(f"        if (state >= {first_void} && state < {first_typed}) {{")
        lines.append("            // void argument state: the newline right after the path fires it")
        lines.append(f"            {pointer_decl('void')}")
        lines.append("            switch (state) {")
        for s in void:
            lines.append(f"            case State_{s.id}: fn_void = drv->{s.arg_leaf[1]}; break;")
        lines.append("            }")
        lines.append("            if (fn_void != nullptr) fn_void(ctx->handler_ctx);")
        lines.append("            return;")
        lines.append("        }")
    lines.append("        // a literal state or State_Sink: the line matched no command,")
    lines.append("        // unless it was empty (still at the root)")
    lines.append(f"        if (state != State_0 && drv->{UNKNOWN_COMMAND} != nullptr) drv->{UNKNOWN_COMMAND}(ctx->handler_ctx);")
    lines.append("        return;")
    lines.append("    }")
    lines.append("")
    lines.append("    switch (state) {")
    for s in literal:
        lines.append(f"    case State_{s.id}:")
        lines.append("        switch (c) {")
        for ch, child in sorted(s.children.items()):
            escaped = "' '" if ch == " " else f"'{ch}'"
            lines.append(f"        case {escaped}: ctx->state = State_{child.id}; return;")
        lines.append("        }")
        lines.append("        break;")
    lines.append("    }")
    lines.append("    // no edge for c (or a stray character after a void command): wait in")
    lines.append("    // State_Sink for the newline, so the rest of the line cannot run")
    lines.append("    ctx->state = State_Sink;")
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