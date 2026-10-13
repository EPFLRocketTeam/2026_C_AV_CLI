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


def leaves_of(text):
    leaves = []
    gc.flatten(yaml.safe_load(text), "", leaves)
    return leaves


def emit(text, out_dir, basename="gen"):
    """Run the real CLI on yaml text, like CI does."""
    src = out_dir / "in.yaml"
    src.write_text(text, newline="\n")
    subprocess.run(
        [sys.executable, str(ROOT / "generate_commands.py"), str(src), str(out_dir), basename],
        check=True, capture_output=True, text=True,
    )
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
    assert (
        'drv->f_bool(ctx->handler_ctx, (strcmp(ctx->arg_buffer, "open") == 0 '
        '|| strcmp(ctx->arg_buffer, "on") == 0));'
    ) in text
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


def test_real_yaml_counts_match_committed_output():
    leaves = leaves_of(YAML_PATH.read_text())
    root, _ = gc.build_trie(leaves)
    states = gc.collect_states(root)
    hpp = (ROOT / f"{BASENAME}.hpp").read_text()
    cpp = (ROOT / f"{BASENAME}.cpp").read_text()
    assert len(re.findall(r"^    State_\d+,$", hpp, re.M)) == len(states)
    assert len(re.findall(r"^    case State_\d+: \{$", cpp, re.M)) == len(states)
    callbacks = {f for _, _, f in leaves}
    assert len(re.findall(r"^    void \(\*\w+\)\(void\* ctx", hpp, re.M)) == len(callbacks)
    assert len(re.findall(r"drv->\w+\(ctx->handler_ctx", cpp)) == len(leaves)


def test_committed_output_is_in_sync(tmp_path):
    emit(YAML_PATH.read_text(), tmp_path, BASENAME)
    for ext in ("hpp", "cpp"):
        fresh = (tmp_path / f"{BASENAME}.{ext}").read_bytes()
        committed = (ROOT / f"{BASENAME}.{ext}").read_bytes()
        assert fresh == committed, f"{BASENAME}.{ext} is stale, rerun generate_commands.py"


def test_generation_is_deterministic(tmp_path):
    a, b = tmp_path / "a", tmp_path / "b"
    a.mkdir()
    b.mkdir()
    emit(YAML_PATH.read_text(), a, BASENAME)
    emit(YAML_PATH.read_text(), b, BASENAME)
    for ext in ("hpp", "cpp"):
        assert (a / f"{BASENAME}.{ext}").read_bytes() == (b / f"{BASENAME}.{ext}").read_bytes()


@needs_cxx
def test_real_generated_cpp_compiles(tmp_path):
    emit(YAML_PATH.read_text(), tmp_path, BASENAME)
    res = run_cxx(tmp_path, f"g++ -std=c++20 -Wall -Werror -fsyntax-only -I. {BASENAME}.cpp")
    assert res.returncode == 0, res.stderr


def harness(leaves):
    funcs = sorted({(f, t) for _, t, f in leaves})
    out = ['#include "gen.hpp"', "#include <cstdio>", "#include <string>"]
    for f, t in funcs:
        if t == "void":
            out.append(f'static void {f}(void*) {{ std::printf("{f}\\n"); }}')
        elif t == "float":
            out.append(f'static void {f}(void*, float v) {{ std::printf("{f} %g\\n", v); }}')
        else:
            out.append(f'static void {f}(void*, {t} v) {{ std::printf("{f} %d\\n", v); }}')
    out.append("int main() {")
    out.append("  driver d = {" + ", ".join(f for f, _ in funcs) + "};")
    out.append("  context c; std::string all; int ch;")
    out.append("  while ((ch = std::getchar()) != EOF) all.push_back((char)ch);")
    # A NUL byte separates cases: reset the context and print a marker line.
    out.append('  for (char x : all) { if (x == 0) { c = context(); std::puts("--"); } '
               "else push_char(&c, &d, x); }")
    out.append('  std::puts("--");')
    out.append("}")
    return "\n".join(out)


def run_cases(tmp_path, text, cases):
    """Compile the generated parser for yaml text and feed it each case; return output lines per case."""
    emit(text, tmp_path)
    (tmp_path / "main.cpp").write_text(harness(leaves_of(text)), newline="\n")
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

