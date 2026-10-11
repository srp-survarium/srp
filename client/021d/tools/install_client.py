#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Verify, install and restore a locally built retail 0.21d patch package.

Close the game before installation or restoration. Originals remain in the
installation's .srp-021d directory until restoration succeeds. No force mode:
unknown files, linked paths and modified backups require manual review.
"""
import argparse
from contextlib import contextmanager
import json
import os
from pathlib import Path
import re
import shutil
import stat
import sys

from prepare_client import RETAIL_DB_SHA256, sha256
from patch_exe import RETAIL_SHA256

ORIGINALS = {
    "binaries/x86/survarium.exe": RETAIL_SHA256,
    "binaries/x86/srp-client-021d.dll": None,
    "resources.db": RETAIL_DB_SHA256,
}
INSTALL_ORDER = ("resources.db", "binaries/x86/srp-client-021d.dll", "binaries/x86/survarium.exe")
RESTORE_ORDER = ("binaries/x86/survarium.exe", "resources.db", "binaries/x86/srp-client-021d.dll")
STATE = ".srp-021d"
LOCK = ".srp-021d.lock"


def safe_path(root, name):
    """All callers use fixed paths, never path names supplied by a manifest."""
    current = root
    for part in Path(name).parts:
        if part in ("..", "") or Path(part).is_absolute():
            raise ValueError("Unsafe managed path")
        current = current / part
        try:
            info = current.lstat()
        except FileNotFoundError:
            continue
        if stat.S_ISLNK(info.st_mode) or getattr(info, "st_file_attributes", 0) & 0x400:
            raise ValueError(f"Linked or reparse path is not supported: {current}")
    return current


def file_hash(path):
    if not path.exists():
        return None
    if not path.is_file():
        raise ValueError(f"Expected a regular file: {path}")
    return sha256(path)


def require_hash(path, expected):
    actual = file_hash(path)
    if actual != expected:
        raise ValueError(f"File changed or wrong build: {path}; expected {expected}, found {actual}")


def sync_dir(path):
    if os.name != "nt":
        descriptor = os.open(path, os.O_RDONLY | os.O_DIRECTORY)
        try:
            os.fsync(descriptor)
        finally:
            os.close(descriptor)


def copy_verified(source, destination, expected):
    missing = []
    parent = destination.parent
    while not parent.exists():
        missing.append(parent)
        parent = parent.parent
    for parent in reversed(missing):
        parent.mkdir()
        sync_dir(parent.parent)
    shutil.copy2(source, destination)
    with destination.open("rb") as output:
        os.fsync(output.fileno())
    require_hash(destination, expected)
    sync_dir(destination.parent)


def validate_manifest(manifest):
    if (not isinstance(manifest, dict) or manifest.get("schema") != "srp-client-package-v1"
            or manifest.get("target") != "retail-0.21d-build-2010"):
        raise ValueError("Unsupported package schema or target")
    files = manifest.get("files")
    if not isinstance(files, dict) or set(files) != set(ORIGINALS):
        raise ValueError("Package must contain exactly the three supported client files")
    for name, original in ORIGINALS.items():
        item = files[name]
        if (not isinstance(item, dict) or set(item) != {"before", "after"}
                or item["before"] != original
                or not isinstance(item["after"], str)
                or not re.fullmatch("[0-9a-f]{64}", item["after"])
                or item["after"] == original):
            raise ValueError(f"Invalid package file contract: {name}")
    return manifest


def load_package(package):
    manifest_path = safe_path(package, "package.json")
    manifest = validate_manifest(json.loads(manifest_path.read_text(encoding="utf-8")))
    for name in ORIGINALS:
        require_hash(safe_path(package, "payload/" + name), manifest["files"][name]["after"])
    return manifest


def verify_targets(game, manifest, version):
    for name in ORIGINALS:
        require_hash(safe_path(game, name), manifest["files"][name][version])


def check_closed(game):
    # Wine maps the Windows EXE/DLL into a host process. This catches that
    # case even when /proc/PID/exe points to Wine rather than the game.
    if sys.platform.startswith("linux"):
        managed = {str(game / name) for name in ORIGINALS}
        for process in Path("/proc").iterdir():
            if not process.name.isdigit():
                continue
            try:
                lines = (process / "maps").read_text().splitlines()
            except (OSError, UnicodeError):
                continue
            for line in lines:
                fields = line.split(maxsplit=5)
                if len(fields) == 6 and fields[5].removesuffix(" (deleted)") in managed:
                    raise ValueError(f"Close the game before modifying it (process {process.name})")


@contextmanager
def installation_lock(game):
    path = safe_path(game, LOCK)
    with path.open("a+b") as handle:
        if handle.tell() == 0:
            handle.write(b"0")
            handle.flush()
        handle.seek(0)
        try:
            if os.name == "nt":
                import msvcrt
                msvcrt.locking(handle.fileno(), msvcrt.LK_NBLCK, 1)
            else:
                import fcntl
                fcntl.flock(handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
        except OSError as error:
            raise ValueError("Another installer or launcher is using this directory") from error
        try:
            yield
        finally:
            handle.seek(0)
            if os.name == "nt":
                msvcrt.locking(handle.fileno(), msvcrt.LK_UNLCK, 1)
            else:
                fcntl.flock(handle.fileno(), fcntl.LOCK_UN)
    # Keep the small lock file: unlinking it could let two callers lock
    # different inodes. OS advisory locks release automatically after a crash.


def write_journal(state, journal):
    temp = safe_path(state, "journal.tmp")
    with temp.open("w", encoding="utf-8") as output:
        json.dump(journal, output, indent=2)
        output.write("\n")
        output.flush()
        os.fsync(output.fileno())
    os.replace(temp, safe_path(state, "journal.json"))
    sync_dir(state)


def read_journal(state):
    journal = json.loads(safe_path(state, "journal.json").read_text(encoding="utf-8"))
    if (not isinstance(journal, dict) or journal.get("schema") != "srp-client-install-v1"
            or journal.get("phase") not in {"preparing", "installing", "installed", "restoring", "restored"}):
        raise ValueError("Unsupported install journal")
    validate_manifest(journal["package"])
    return journal


def check_state_tree(state):
    allowed_files = {"journal.json", "journal.tmp"}
    for folder in ("original", "new", "restore"):
        allowed_files.update(folder + "/" + name for name in ORIGINALS)
    allowed_dirs = {str(parent) for name in allowed_files for parent in Path(name).parents if str(parent) != "."}
    for path in state.rglob("*"):
        name = path.relative_to(state).as_posix()
        safe_path(state, name)
        if (path.is_dir() and name not in allowed_dirs) or (not path.is_dir() and name not in allowed_files):
            raise ValueError(f"Unexpected file in install state; preserve and review it: {path}")


def checkpoint(_event):
    """Fault-injection seam for interruption tests; production does nothing."""


def verify_installation(game):
    """Caller holds installation_lock while using this verification result."""
    state = safe_path(game, STATE)
    check_state_tree(state)
    journal = read_journal(state)
    if journal["phase"] != "installed":
        raise ValueError("Installation is incomplete; run recover before launching")
    manifest = journal["package"]
    verify_targets(game, manifest, "after")
    for name, original in ORIGINALS.items():
        if original is not None:
            require_hash(safe_path(state, "original/" + name), original)
    return manifest


def install(game, package):
    game, package = game.resolve(strict=True), package.resolve(strict=True)
    if package == game or game in package.parents:
        raise ValueError("Package must be outside the installation")
    manifest = load_package(package)
    with installation_lock(game):
        check_closed(game)
        state = safe_path(game, STATE)
        if state.exists():
            check_state_tree(state)
            journal = read_journal(state)
            if journal["phase"] == "installed" and journal["package"]["files"] == manifest["files"]:
                verify_targets(game, manifest, "after")
                for name, original in ORIGINALS.items():
                    if original is not None:
                        require_hash(safe_path(state, "original/" + name), original)
                return "Already installed; files and backups verified."
            raise ValueError("An installation already exists or was interrupted; restore it before installing")
        verify_targets(game, manifest, "before")
        state.mkdir()
        sync_dir(game)
        checkpoint("state_created")
        journal = {"schema": "srp-client-install-v1", "phase": "preparing", "package": manifest}
        write_journal(state, journal)
        sync_dir(game)
        checkpoint("preparing")
        for name, original in ORIGINALS.items():
            if original is not None:
                copy_verified(safe_path(game, name), safe_path(state, "original/" + name), original)
            copy_verified(safe_path(package, "payload/" + name), safe_path(state, "new/" + name),
                          manifest["files"][name]["after"])
            checkpoint("staged:" + name)
        verify_targets(game, manifest, "before")
        check_closed(game)
        journal["phase"] = "installing"
        write_journal(state, journal)
        checkpoint("installing")
        for name in INSTALL_ORDER:
            target = safe_path(game, name)
            staged = safe_path(state, "new/" + name)
            require_hash(target, ORIGINALS[name])
            require_hash(staged, manifest["files"][name]["after"])
            os.replace(staged, target)
            sync_dir(target.parent)
            sync_dir(staged.parent)
            checkpoint("installed:" + name)
        verify_targets(game, manifest, "after")
        journal["phase"] = "installed"
        write_journal(state, journal)
        checkpoint("installed")
        return "Installed and verified. Originals retained in .srp-021d."


def restore(game):
    game = game.resolve(strict=True)
    with installation_lock(game):
        check_closed(game)
        state = safe_path(game, STATE)
        if not state.exists():
            for name, original in ORIGINALS.items():
                require_hash(safe_path(game, name), original)
            return "No patch installed; retail files verified."
        check_state_tree(state)
        if not safe_path(state, "journal.json").exists():
            # Crash before the initial journal rename, or during final cleanup.
            # Either is recoverable only when every game file is already retail.
            for name, original in ORIGINALS.items():
                require_hash(safe_path(game, name), original)
            shutil.rmtree(state)
            sync_dir(game)
            return "Retail files verified; incomplete installer metadata removed."
        journal = read_journal(state)
        manifest = journal["package"]
        # Preflight every managed file and needed backup before restoring any.
        changes = []
        for name in RESTORE_ORDER:
            current = file_hash(safe_path(game, name))
            before, after = ORIGINALS[name], manifest["files"][name]["after"]
            if current not in (before, after):
                raise ValueError(f"Managed file was changed outside this installer: {name}; preserving it")
            if journal["phase"] == "preparing" and current != before:
                raise ValueError("Game files changed during package preparation; preserving them")
            if current != before:
                if before is not None:
                    require_hash(safe_path(state, "original/" + name), before)
                changes.append(name)
        for name in changes:
            if ORIGINALS[name] is not None:
                copy_verified(safe_path(state, "original/" + name), safe_path(state, "restore/" + name), ORIGINALS[name])
        journal["phase"] = "restoring"
        write_journal(state, journal)
        checkpoint("restoring")
        for name in changes:
            target = safe_path(game, name)
            require_hash(target, manifest["files"][name]["after"])
            if ORIGINALS[name] is None:
                target.unlink()
            else:
                staged = safe_path(state, "restore/" + name)
                require_hash(staged, ORIGINALS[name])
                os.replace(staged, target)
                sync_dir(staged.parent)
            sync_dir(target.parent)
            checkpoint("restored:" + name)
        for name, original in ORIGINALS.items():
            require_hash(safe_path(game, name), original)
        journal["phase"] = "restored"
        write_journal(state, journal)
        checkpoint("restored")
        # Delete only the checked, installer-owned tree after retail verifies.
        check_state_tree(state)
        shutil.rmtree(state)
        sync_dir(game)
        return "Retail files restored and verified; installed DLL removed."


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="operation", required=True)
    for name in ("check", "install"):
        command = commands.add_parser(name)
        command.add_argument("game", type=Path)
        command.add_argument("package", type=Path)
    for name in ("restore", "recover"):
        command = commands.add_parser(name)
        command.add_argument("game", type=Path)
    args = parser.parse_args()
    try:
        if args.operation == "check":
            manifest = load_package(args.package.resolve(strict=True))
            verify_targets(args.game.resolve(strict=True), manifest, "before")
            result = "Package and retail inputs verified; no files changed."
        elif args.operation == "install":
            result = install(args.game, args.package)
        else:
            result = restore(args.game)
        print(result)
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.exit(1, f"Operation stopped: {error}\nIf an install was interrupted, run recover with the same game directory.\n")


if __name__ == "__main__":
    main()
