#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build/run the isolated native serializer probe against exact retail 0.21d."""
import argparse
import hashlib
import os
from pathlib import Path
import subprocess

from patch_exe import RETAIL_SHA256


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("retail_exe", type=Path)
    parser.add_argument("--cc", default="i686-w64-mingw32-gcc")
    parser.add_argument("--library-dir", action="append", default=[], type=Path)
    parser.add_argument("--work", type=Path, required=True)
    parser.add_argument("--wine", help="Wine binary on non-Windows hosts")
    parser.add_argument("--wine-prefix", type=Path, help="Dedicated probe prefix")
    args = parser.parse_args()
    retail = args.retail_exe.resolve()
    if hashlib.sha256(retail.read_bytes()).hexdigest() != RETAIL_SHA256:
        parser.error("Executable SHA256 is not the supported retail 0.21d build")
    if os.name != "nt" and (not args.wine or not args.wine_prefix):
        parser.error("Non-Windows execution requires --wine and --wine-prefix")
    args.work.mkdir(parents=True, exist_ok=True)
    output = args.work.resolve() / "native-snapshot-probe.exe"
    if output == retail:
        parser.error("Probe output must not overwrite the retail executable")
    source = Path(__file__).resolve().parents[1] / "tests/native_snapshot_probe.c"
    subprocess.run([args.cc, "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
                    "-static", str(source), str(source.parent.parent / "dll/native_match.c"),
                    str(source.parent.parent / "dll/native_tree.c"),
                    str(source.parent.parent / "dll/native_snapshot.c"),
                    str(source.parent.parent / "dll/native_roundtrip.c"),
                    str(source.parent.parent / "dll/native_recovery.c"),
                    "-o", str(output)]
                   + ["-L" + str(p) for p in args.library_dir], check=True)
    env = os.environ.copy()
    command = [str(output), str(retail)]
    if os.name != "nt":
        env.update(WINEPREFIX=str(args.wine_prefix.resolve()), WINEDEBUG="-all")
        # Wine's default Z: mapping exposes absolute host paths.
        command = [args.wine, str(output), "Z:" + str(retail).replace("/", "\\")]
    subprocess.run(command, env=env, check=True, timeout=60)


if __name__ == "__main__":
    main()
