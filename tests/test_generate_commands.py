"""Tests for generate_commands.py.

The generated C++ is the product, so besides checking the Python structures
these tests compile the emitted parser with g++ (natively, or through the
ert-host-tests docker image when g++ is not installed) and feed it characters.
"""

import re
import shutil
import subprocess
import sys
from pathlib import Path

import pytest
import yaml

import generate_commands as gc

ROOT = Path(__file__).resolve().parent.parent
YAML_PATH = ROOT / "commands.yaml"
BASENAME = "fc_commands_generated"

# Every committed generated pair: (yaml, basename, namespace). The FC pair is
# emitted without a namespace, the PRC pair inside prc_cli.
PAIRS = [
    ("commands.yaml", BASENAME, None),
    ("prc_commands.yaml", "prc_commands_generated", "prc_cli"),
]
pairs = pytest.mark.parametrize("yaml_name,basename,namespace", PAIRS, ids=[b for _, b, _ in PAIRS])


def leaves_of(text):
    leaves = []
    gc.flatten(yaml.safe_load(text), "", leaves)
    return leaves


def emit(text, out_dir, basename="gen", namespace=None):
    """Run the real CLI on yaml text, like CI does."""
    src = out_dir / "in.yaml"
    src.write_text(text, newline="\n")
    cmd = [sys.executable, str(ROOT / "generate_commands.py"), str(src), str(out_dir), basename]
    if namespace:
        cmd += ["--namespace", namespace]
    subprocess.run(cmd, check=True, capture_output=True, text=True)
    return out_dir / f"{basename}.hpp", out_dir / f"{basename}.cpp"


def run_cxx(workdir, shell_cmd):
    """Run a shell command where g++ exists: natively, else in the docker image."""
    if shutil.which("g++"):
        return subprocess.run(["bash", "-c", shell_cmd], cwd=workdir, capture_output=True, text=True)
    return subprocess.run(
        ["docker", "run", "--rm", "-v", f"{workdir}:/src", "-w", "/src",
         "ert-host-tests", "bash", "-c", shell_cmd],
        capture_output=True, text=True,
    )


def have_cxx():
    if shutil.which("g++"):
        return True
    if shutil.which("docker"):
        probe = subprocess.run(["docker", "image", "inspect", "ert-host-tests"], capture_output=True)
        return probe.returncode == 0
    return False


needs_cxx = pytest.mark.skipif(not have_cxx(), reason="no g++ and no ert-host-tests docker image")

SMALL = """
b:
  "%bool":
    "%run": f_bool
i:
  "%int":
    "%run": f_int
fl:
  "%float":
    "%run": f_float
v:
  "%void":
    "%run": f_void
g:
  h:
    "%bool":
      "%run": g_h
"""


def test_type_signatures_in_header(tmp_path):
    hpp, _ = emit(SMALL, tmp_path)
    text = hpp.read_text()
    assert "void (*f_bool)(void* ctx, bool value);" in text
    assert "void (*f_int)(void* ctx, int value);" in text
    assert "void (*f_float)(void* ctx, float value);" in text
    assert "void (*f_void)(void* ctx);" in text
    assert "void (*g_h)(void* ctx, bool value);" in text


def test_type_parse_expressions_in_source(tmp_path):
    _, cpp = emit(SMALL, tmp_path)
    text = cpp.read_text()
    assert "drv->f_int(ctx->handler_ctx, strtol(ctx->arg_buffer, nullptr, 10));" in text
    assert "drv->f_float(ctx->handler_ctx, strtof(ctx->arg_buffer, nullptr));" in text
    assert 'if (strcmp(ctx->arg_buffer, "open") == 0 || strcmp(ctx->arg_buffer, "on") == 0) {' in text
    assert 'strcmp(ctx->arg_buffer, "close") == 0 || strcmp(ctx->arg_buffer, "off") == 0' in text
    assert "drv->f_bool(ctx->handler_ctx, true);" in text
    assert "drv->f_bool(ctx->handler_ctx, false);" in text
    assert "drv->on_bad_argument(ctx->handler_ctx);" in text
    assert "drv->f_void(ctx->handler_ctx);" in text


def test_leaf_paths_join_ancestors():
    assert ("g h", "bool", "g_h") in leaves_of(SMALL)


def test_unknown_type_exits():
    with pytest.raises(SystemExit, match="unknown type 'string'"):
        gc.build_trie([("x", "string", "f")])


def test_void_literal_has_no_trailing_space_and_arg_types_do():
    root, _ = gc.build_trie([("v", "void", "f_void"), ("b", "bool", "f_bool")])
    assert root.children["v"].arg_leaf == ("void", "f_void")
    assert root.children["b"].arg_leaf is None
    assert root.children["b"].children[" "].arg_leaf == ("bool", "f_bool")


def test_arg_buffer_is_bounded_in_emitted_code(tmp_path):
    hpp, cpp = emit(SMALL, tmp_path)
    assert f"char arg_buffer[{gc.ARG_BUFFER_SIZE + 1}];" in hpp.read_text()
    # every argument state (bool, int, float, g h) carries the guard
    assert cpp.read_text().count(f"ctx->arg_len < {gc.ARG_BUFFER_SIZE}") == 4


@pairs
def test_real_yaml_counts_match_committed_output(yaml_name, basename, namespace):
    leaves = leaves_of((ROOT / yaml_name).read_text())
    root, _ = gc.build_trie(leaves)
    states = gc.collect_states(root)
    hpp = (ROOT / f"{basename}.hpp").read_text()
    cpp = (ROOT / f"{basename}.cpp").read_text()
    assert len(re.findall(r"^    State_\d+,$", hpp, re.M)) == len(states)
    assert len(re.findall(r"^    case State_\d+: \{$", cpp, re.M)) == len(states)
    callbacks = {f for _, _, f in leaves}
    # every yaml callback plus the optional on_bad_argument member
    assert len(re.findall(r"^    void \(\*\w+\)\(void\* ctx", hpp, re.M)) == len(callbacks) + 1
    # a bool leaf calls its function twice (true, false) and on_bad_argument once
    bools = sum(1 for _, t, _ in leaves if t == "bool")
    assert len(re.findall(r"drv->\w+\(ctx->handler_ctx", cpp)) == len(leaves) + 2 * bools


@pairs
def test_committed_output_is_in_sync(tmp_path, yaml_name, basename, namespace):
    emit((ROOT / yaml_name).read_text(), tmp_path, basename, namespace)
    for ext in ("hpp", "cpp"):
        fresh = (tmp_path / f"{basename}.{ext}").read_bytes()
        committed = (ROOT / f"{basename}.{ext}").read_bytes()
        assert fresh == committed, f"{basename}.{ext} is stale, rerun generate_commands.py"


@pairs
def test_generation_is_deterministic(tmp_path, yaml_name, basename, namespace):
    a, b = tmp_path / "a", tmp_path / "b"
    a.mkdir()
    b.mkdir()
    emit((ROOT / yaml_name).read_text(), a, basename, namespace)
    emit((ROOT / yaml_name).read_text(), b, basename, namespace)
    for ext in ("hpp", "cpp"):
        assert (a / f"{basename}.{ext}").read_bytes() == (b / f"{basename}.{ext}").read_bytes()


# The FC and PRC firmware build with gnu++17 in CubeIDE, the host tests with c++20.
STDS = pytest.mark.parametrize("std", ["c++20", "gnu++17"])


@needs_cxx
@pairs
@STDS
def test_real_generated_cpp_compiles(tmp_path, yaml_name, basename, namespace, std):
    emit((ROOT / yaml_name).read_text(), tmp_path, basename, namespace)
    res = run_cxx(tmp_path, f"g++ -std={std} -Wall -Werror -fsyntax-only -I. {basename}.cpp")
    assert res.returncode == 0, res.stderr


# --- --namespace ---------------------------------------------------------------

def test_namespace_wraps_every_emitted_symbol(tmp_path):
    hpp, cpp = emit(SMALL, tmp_path, namespace="ns")
    h, c = hpp.read_text(), cpp.read_text()
    # opened after the includes, before the first symbol, closed at the very end
    assert h.index("#include <cstring>") < h.index("namespace ns {") < h.index("enum State {")
    assert h.rstrip().endswith("}  // namespace ns")
    assert c.index('#include "gen.hpp"') < c.index("namespace ns {") < c.index("void push_char(")
    assert c.rstrip().endswith("}  // namespace ns")


def test_no_namespace_emits_none(tmp_path):
    hpp, cpp = emit(SMALL, tmp_path)
    assert "namespace" not in hpp.read_text()
    assert "namespace" not in cpp.read_text()


@pytest.mark.parametrize("name", ["not a name", "int", "namespace", "and"])
def test_namespace_must_be_an_identifier(tmp_path, name):
    src = tmp_path / "in.yaml"
    src.write_text(SMALL, newline="\n")
    res = subprocess.run(
        [sys.executable, str(ROOT / "generate_commands.py"), str(src), str(tmp_path), "gen",
         "--namespace", name],
        capture_output=True, text=True,
    )
    assert res.returncode != 0
    assert "not a C++ identifier" in res.stderr


def strip_namespace(text, name):
    return text.replace(f"namespace {name} {{\n\n", "").replace(f"\n}}  // namespace {name}\n", "").rstrip("\n")


@pytest.mark.parametrize("yaml_name", ["commands.yaml", "prc_commands.yaml"])
def test_namespace_only_adds_the_wrapper(tmp_path, yaml_name):
    # Byte identity of the un-namespaced output, against fresh output rather
    # than committed files: with the wrapper lines removed, the two match.
    plain, wrapped = tmp_path / "plain", tmp_path / "wrapped"
    plain.mkdir()
    wrapped.mkdir()
    text = (ROOT / yaml_name).read_text()
    emit(text, plain, "gen")
    emit(text, wrapped, "gen", "ns")
    for ext in ("hpp", "cpp"):
        a = (plain / f"gen.{ext}").read_text()
        b = (wrapped / f"gen.{ext}").read_text()
        assert "namespace" not in a
        assert strip_namespace(b, "ns") == a.rstrip("\n")


def test_reserved_bad_argument_name_is_rejected():
    with pytest.raises(SystemExit, match="reserved"):
        gc.generate_header([], [("a", "void", "on_bad_argument")], "x")


@needs_cxx
@STDS
def test_both_committed_pairs_link_into_one_binary(tmp_path, std):
    # The PRC pair lives in prc_cli, so it does not collide with the FC pair's
    # global State, driver, context and push_char.
    for yaml_name, basename, namespace in PAIRS:
        emit((ROOT / yaml_name).read_text(), tmp_path, basename, namespace)
    (tmp_path / "both.cpp").write_text(
        '#include "fc_commands_generated.hpp"\n'
        '#include "prc_commands_generated.hpp"\n'
        "int main() { context a; prc_cli::context b; return a.arg_len + b.arg_len; }\n",
        newline="\n",
    )
    res = run_cxx(
        tmp_path,
        f"g++ -std={std} -Wall -Werror -I. both.cpp fc_commands_generated.cpp prc_commands_generated.cpp -o both && ./both",
    )
    assert res.returncode == 0, res.stderr + res.stdout


def harness(leaves, namespace=None, bind_bad=True):
    funcs = sorted({(f, t) for _, t, f in leaves})
    out = ['#include "gen.hpp"', "#include <cstdio>", "#include <string>"]
    if namespace:
        out.append(f"using namespace {namespace};")
    out.append('[[maybe_unused]] static void on_bad(void*) { std::printf("bad\\n"); }')
    for f, t in funcs:
        if t == "void":
            out.append(f'static void {f}(void*) {{ std::printf("{f}\\n"); }}')
        elif t == "float":
            out.append(f'static void {f}(void*, float v) {{ std::printf("{f} %g\\n", v); }}')
        else:
            out.append(f'static void {f}(void*, {t} v) {{ std::printf("{f} %d\\n", v); }}')
    out.append("int main() {")
    out.append("  driver d = {" + ", ".join(f for f, _ in funcs) + "};")
    if bind_bad:
        out.append("  d.on_bad_argument = on_bad;")
    out.append("  context c; std::string all; int ch;")
    out.append("  while ((ch = std::getchar()) != EOF) all.push_back((char)ch);")
    # A NUL byte separates cases: reset the context and print a marker line.
    out.append('  for (char x : all) { if (x == 0) { c = context(); std::puts("--"); } '
               "else push_char(&c, &d, x); }")
    out.append('  std::puts("--");')
    out.append("}")
    return "\n".join(out)


def run_cases(tmp_path, text, cases, namespace=None, bind_bad=True):
    """Compile the generated parser for yaml text and feed it each case; return output lines per case."""
    emit(text, tmp_path, namespace=namespace)
    (tmp_path / "main.cpp").write_text(harness(leaves_of(text), namespace, bind_bad), newline="\n")
    (tmp_path / "cases.bin").write_bytes(b"\0".join(c.encode() for c in cases))
    res = run_cxx(
        tmp_path,
        "g++ -std=c++20 -Wall -Werror -fsanitize=address,undefined -I. main.cpp gen.cpp -o h "
        "&& ./h < cases.bin",
    )
    assert res.returncode == 0, res.stderr + res.stdout
    chunks = res.stdout.replace("\r", "").split("--\n")[:-1]
    assert len(chunks) == len(cases)
    return [c.splitlines() for c in chunks]


@needs_cxx
def test_parser_runtime_behaviour(tmp_path):
    out = run_cases(tmp_path, SMALL, [
        "b on\n", "b open\n", "b off\n", "i 42\n", "fl 1.5\n", "g h on\n",
        "v\n", "v x\n", "vv\n", "zzz\n", "v\nb on\n",
    ])
    assert out == [
        ["f_bool 1"], ["f_bool 1"], ["f_bool 0"], ["f_int 42"], ["f_float 1.5"],
        ["g_h 1"], ["f_void"], [], [], [], ["f_void", "f_bool 1"],
    ]


@needs_cxx
def test_bool_takes_only_open_close_on_off(tmp_path):
    out = run_cases(tmp_path, SMALL, ["b open\n", "b on\n", "b close\n", "b off\n", "b maybe\n", "b opened\n",
                                      "b \n", "g h clsoe\n", "b on\n"])
    assert out == [["f_bool 1"], ["f_bool 1"], ["f_bool 0"], ["f_bool 0"], ["bad"], ["bad"],
                   ["bad"], ["bad"], ["f_bool 1"]]


@needs_cxx
def test_bad_bool_with_no_callback_bound_runs_nothing(tmp_path):
    out = run_cases(tmp_path, SMALL, ["b maybe\n", "b off\n"], bind_bad=False)
    assert out == [[], ["f_bool 0"]]


@needs_cxx
def test_unknown_character_sinks_until_newline(tmp_path):
    # Before, State_0 looped on the unknown character and "xv" ran v.
    out = run_cases(tmp_path, SMALL, ["xv\n", "xb on\n", "vx\nv\n", "g x h on\n", "b on\n", "\n\nv\n"])
    assert out == [[], [], ["f_void"], [], ["f_bool 1"], ["f_void"]]


@needs_cxx
def test_namespaced_parser_behaves_the_same(tmp_path):
    out = run_cases(tmp_path, SMALL, ["b on\n", "b open\n", "b off\n", "g h on\n", "v\n", "zzz\n"], "ns")
    assert out == [["f_bool 1"], ["f_bool 1"], ["f_bool 0"], ["g_h 1"], ["f_void"], []]


@needs_cxx
def test_void_fires_on_newline_with_no_argument(tmp_path):
    out = run_cases(tmp_path, SMALL, ["v", "v\n", "v \n"])
    # no newline yet: nothing fired; newline right after the path fires; a stray space cancels
    assert out == [[], ["f_void"], []]


@needs_cxx
def test_overlong_argument_is_truncated_not_overflowed(tmp_path):
    n = gc.ARG_BUFFER_SIZE
    kept = "1" + "0" * (n - 1)
    out = run_cases(tmp_path, SMALL, ["fl " + kept + "9" * 200 + "\n", "fl 7\n"])
    assert out[0] == [f"f_float {float(kept):g}"]
    # arg_len was reset after the long one, so the next argument is clean
    assert out[1] == ["f_float 7"]


# --- defects: each of these failed against the original generator -----------

def test_duplicate_path_is_rejected():
    with pytest.raises(SystemExit, match="duplicate"):
        gc.build_trie([("a b", "bool", "f1"), ("a b", "bool", "f2")])


def test_void_command_that_prefixes_another_is_rejected():
    # "abort" fires on newline, so "abort_all" below it would be unreachable
    with pytest.raises(SystemExit, match="prefix"):
        gc.build_trie([("abort", "void", "f1"), ("abort_all", "void", "f2")])


def test_argument_command_that_prefixes_another_is_rejected():
    with pytest.raises(SystemExit, match="prefix"):
        gc.build_trie([("a", "bool", "f1"), ("a b", "bool", "f2")])


def test_same_function_with_two_types_is_rejected():
    with pytest.raises(SystemExit, match="f1"):
        gc.generate_header([], [("a", "bool", "f1"), ("b", "int", "f1")], "x")


def test_emitted_files_use_lf_line_endings(tmp_path):
    hpp, cpp = emit(SMALL, tmp_path)
    assert b"\r" not in hpp.read_bytes()
    assert b"\r" not in cpp.read_bytes()

