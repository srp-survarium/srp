#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build a verified client patch package from local retail files and SRP source.

Writes a new output directory only. Does not install into or launch the game.
The generated executable/archive contain retail data and are local artifacts,
not files to add to the open-source distribution.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys

import patch_exe
import patch_swf

RETAIL_DB_SHA256 = "e28cc2878e0e2f04ab9ab0a1861034622af487a491bf230ea24f44e9af9715a4"
CLIENT = Path(__file__).resolve().parents[1]


def sha256(path):
    with path.open("rb") as source:
        return hashlib.file_digest(source, "sha256").hexdigest()


def expect(path, digest):
    actual = sha256(path)
    if actual != digest:
        raise ValueError(f"Unsupported or modified input: {path} (SHA256 {actual})")


def run(command):
    subprocess.run([str(value) for value in command], check=True)


def write_json(path, value):
    with path.open("x", encoding="utf-8") as output:
        json.dump(value, output, indent=2)
        output.write("\n")


def prepare(args):
    game = args.game.resolve()
    output = args.output.resolve()
    if args.output.exists() or args.output.is_symlink():
        raise ValueError("Output exists; choose a new directory")
    if output == game or game in output.parents:
        raise ValueError("Build output must be outside the retail installation")
    retail_exe = game / "binaries/x86/survarium.exe"
    retail_db = game / "resources.db"
    expect(retail_exe, patch_exe.RETAIL_SHA256)
    expect(retail_db, RETAIL_DB_SHA256)
    if not args.ffdec.is_file():
        raise ValueError("FFDec jar was not found; supply the complete pinned distribution")
    # Snapshot every build source fingerprint before any subprocess runs.
    sources = {}
    for folder, suffixes in (("dll", {".c", ".h", ".def"}), ("ui", {".as"}),
                             ("tools", {".py", ".java"}),
                             ("vendor/resources-db", {".rs", ".toml", ".lock"})):
        for path in sorted((CLIENT / folder).rglob("*")):
            if path.is_file() and path.suffix in suffixes:
                sources[str(path.relative_to(CLIENT))] = sha256(path)
    output.mkdir(parents=True, exist_ok=False)
    work = output / "work"
    work.mkdir()
    payload = output / "payload"
    binaries = payload / "binaries/x86"
    binaries.mkdir(parents=True)

    archive_tool = args.archive_tool.resolve() if args.archive_tool else None
    if archive_tool is None:
        run([args.cargo, "build", "--locked", "--release", "--manifest-path",
             CLIENT / "vendor/resources-db/Cargo.toml", "--target-dir", work / "archive-build"])
        suffix = ".exe" if sys.platform == "win32" else ""
        archive_tool = work / "archive-build/release" / ("resources-db" + suffix)
    tool_hash = sha256(archive_tool)
    original_movie = work / "retail-lobby_menu.swf"
    run([archive_tool, "extract-member", retail_db, "flash_movies/lobby_menu.swf", original_movie])
    expect(original_movie, patch_swf.RETAIL_SHA256)

    exe, exe_manifest = patch_exe.patch(retail_exe.read_bytes())
    (binaries / "survarium.exe").write_bytes(exe)
    dll = binaries / "srp-client-021d.dll"
    run([sys.executable, CLIENT / "tools/build_dll.py", "--cc", args.cc, "--output", dll]
        + [value for directory in args.library_dir for value in ("--library-dir", directory)])
    swf_work = work / "swf"
    swf_work.mkdir()
    movie, movie_manifest = patch_swf.patch(original_movie, CLIENT / "ui/SrpMenu.as",
        args.ffdec.resolve(), args.java, args.javac, swf_work)
    donor_dir = work / "donor/flash_movies"
    donor_dir.mkdir(parents=True)
    patched_movie = donor_dir / "lobby_menu.swf"
    patched_movie.write_bytes(movie)
    donor = work / "donor.db"
    run([archive_tool, "pack", donor_dir.parent, donor])
    run([archive_tool, "overlay-db", retail_db, donor, payload / "resources.db"])
    extracted = work / "verified-lobby_menu.swf"
    run([archive_tool, "extract-member", payload / "resources.db", "flash_movies/lobby_menu.swf", extracted])
    expect(extracted, movie_manifest["output_sha256"])
    # Refuse a success manifest if a source or retail input changed mid-build.
    expect(retail_exe, patch_exe.RETAIL_SHA256)
    expect(retail_db, RETAIL_DB_SHA256)
    for name, digest in sources.items():
        expect(CLIENT / name, digest)
    expect(archive_tool, tool_hash)
    files = {
        "binaries/x86/survarium.exe": {"before": patch_exe.RETAIL_SHA256,
                                     "after": exe_manifest["output_sha256"]},
        "binaries/x86/srp-client-021d.dll": {"before": None, "after": sha256(dll)},
        "resources.db": {"before": RETAIL_DB_SHA256, "after": sha256(payload / "resources.db")},
    }
    manifest = {
        "schema": "srp-client-package-v1", "target": "retail-0.21d-build-2010",
        "files": files,
        "patches": [
            {"id": "srp-loader-v1", "requires": ["retail-0.21d-build-2010"], **exe_manifest},
            {"id": "srp-menu-v1", "requires": ["srp-loader-v1"], **movie_manifest},
            {"id": "srp-match-recovery-v1", "requires": ["srp-loader-v1"],
             "opt_in": "SRP_MATCH_PROTOCOL=1", "capability": "SRP1-48-R1"},
        ],
        "build_sources_sha256": sources,
        "tools": {"archive_sha256": tool_hash, "ffdec_jar_sha256": sha256(args.ffdec),
                  "cc": args.cc, "java": args.java, "javac": args.javac},
        "verification": {"movie_extracted_from_output": True,
                         "untouched_archive_members": "byte-compared by resources-db overlay"},
    }
    # This file is the completion marker. A failed build has no package.json
    # and can never be mistaken for a verified package by an installer.
    write_json(output / "package.json", manifest)
    print(f"Verified local patch package: {output}")
    print("Retail installation unchanged. Installation is a separate step.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("game", type=Path, help="retail game directory containing resources.db and binaries")
    parser.add_argument("output", type=Path, help="new package directory outside the game installation")
    parser.add_argument("--ffdec", required=True, type=Path)
    parser.add_argument("--archive-tool", type=Path, help="optional prebuilt vendored resources-db")
    parser.add_argument("--cargo", default="cargo")
    parser.add_argument("--cc", default="i686-w64-mingw32-gcc")
    parser.add_argument("--library-dir", action="append", default=[], type=Path)
    parser.add_argument("--java", default="java")
    parser.add_argument("--javac", default="javac")
    args = parser.parse_args()
    try:
        prepare(args)
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        parser.exit(1, f"Build failed: {error}\nNo verified package was produced.\n")


if __name__ == "__main__":
    main()
