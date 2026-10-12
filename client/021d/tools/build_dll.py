#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build the x86 bridge with MinGW-w64; no game or Scaleform SDK needed."""
import argparse
from pathlib import Path
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--cc", default="i686-w64-mingw32-gcc")
parser.add_argument("--output", required=True, type=Path)
parser.add_argument("--library-dir", action="append", default=[], type=Path)
args = parser.parse_args()
args.output.parent.mkdir(parents=True, exist_ok=True)
source = Path(__file__).resolve().parents[1] / "dll/bridge.c"
subprocess.run([args.cc, "-std=c11", "-shared", "-O2", "-Wall", "-Wextra", "-Werror",
                "-static", "-static-libgcc", "-Wl,--no-insert-timestamp",
                "-Wl,--image-base,0x69000000", "-o", str(args.output),
                str(source.with_name("srp-client-021d.def")),
                str(source), str(source.with_name("menu_http.c")),
                str(source.with_name("native_session.c")),
                str(source.with_name("native_match.c")), "-lwinhttp"]
               + [str(source.with_name("native_tree.c")), str(source.with_name("native_snapshot.c")),
                  str(source.with_name("native_roundtrip.c")), str(source.with_name("native_recovery.c"))]
               + ["-L" + str(p) for p in args.library_dir], check=True)
