#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Snapshot the integrated 0.21d server into an isolated Cargo package.

Copies Rust source and tests verbatim; never edits the source checkout or
rewrites its protocol. Run the resulting executable with --protocol srp1.
"""
import argparse
import hashlib
import json
from pathlib import Path
import tomllib


MANIFEST = b'''[package]
name = "match-server-021d"
version = "0.0.0"
edition = "2024"
license = "GPL-3.0-or-later"
'''


def prepare(source, output):
    if output.exists() or output.is_symlink():
        raise ValueError("Output already exists")
    source = source.resolve()
    if output.resolve() == source or source in output.resolve().parents:
        raise ValueError("Output must be outside the source checkout")
    manifest = (source / "Cargo.toml").read_bytes()
    package = tomllib.loads(manifest.decode())
    if package.get("package", {}).get("name") != "match-server-021d":
        raise ValueError("Expected the integrated match-server-021d package")
    # The current package is dependency-free. A changed manifest needs review
    # instead of silently omitting dependencies from the isolated build.
    if any(package.get(k) for k in ("dependencies", "dev-dependencies", "build-dependencies", "target", "features")):
        raise ValueError("Server manifest changed; review the standalone build")
    files = {p.relative_to(source): p.read_bytes()
             for folder in ("src", "tests") for p in (source / folder).rglob("*.rs")}
    if Path("src/protocol.rs") not in files:
        raise ValueError("Use the integrated server with explicit --protocol srp1 support; legacy source rewriting is retired")
    original = {str(p): hashlib.sha256(data).hexdigest() for p, data in files.items()}
    original["Cargo.toml"] = hashlib.sha256(manifest).hexdigest()
    for name, digest in original.items():
        if hashlib.sha256((source / name).read_bytes()).hexdigest() != digest:
            raise ValueError("Server source changed during copying; retry from a stable snapshot")
    output.mkdir(parents=True)
    for path, data in files.items():
        destination = output / path
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(data)
    (output / "Cargo.toml").write_bytes(MANIFEST)
    (output / "srp-probe-manifest.json").write_text(json.dumps({
        "source": str(source), "input_sha256": original,
        "source_transformations": [], "launch_arguments": ["--protocol", "srp1"],
    }, indent=2) + "\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path, help="integrated servers/match-server-021d directory")
    parser.add_argument("output", type=Path, help="new standalone Cargo package")
    args = parser.parse_args()
    try:
        prepare(args.source, args.output)
    except (OSError, ValueError) as error:
        parser.exit(1, f"Cannot prepare server snapshot: {error}\n")
    print(args.output)
    print("Rust sources/tests copied unchanged. Launch with --protocol srp1.")


if __name__ == "__main__":
    main()
