# SPDX-License-Identifier: GPL-3.0-or-later
"""Filesystem interruption/rollback tests using small independent payloads."""
import hashlib
import json
import mmap
from pathlib import Path
import sys
import subprocess
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import install_client as installer


def digest(data):
    return hashlib.sha256(data).hexdigest()


class Interrupted(BaseException):
    pass


class Installation(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.game = self.root / "game"
        self.package = self.root / "package"
        self.before = {
            "binaries/x86/survarium.exe": b"retail exe",
            "binaries/x86/srp-client-021d.dll": None,
            "resources.db": b"retail resources",
        }
        self.after = {name: b"patched:" + name.encode() for name in self.before}
        self.originals = {name: digest(data) if data is not None else None for name, data in self.before.items()}
        self.manifest = {"schema": "srp-client-package-v1", "target": "retail-0.21d-build-2010",
                         "files": {name: {"before": self.originals[name], "after": digest(self.after[name])}
                                   for name in self.before}}
        for name, data in self.before.items():
            path = self.game / name
            path.parent.mkdir(parents=True, exist_ok=True)
            if data is not None:
                path.write_bytes(data)
                path.chmod(0o640)
            path = self.package / "payload" / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(self.after[name])
        self.save_manifest()
        (self.game / "user-settings.cfg").write_bytes(b"preserve my settings")
        self.addCleanup(patch.stopall)
        patch.dict(installer.ORIGINALS, self.originals, clear=True).start()

    def save_manifest(self):
        (self.package / "package.json").write_text(json.dumps(self.manifest))

    def assert_retail(self):
        for name, data in self.before.items():
            path = self.game / name
            if data is None:
                self.assertFalse(path.exists())
            else:
                self.assertEqual(path.read_bytes(), data)
                self.assertEqual(path.stat().st_mode & 0o777, 0o640)
        self.assertEqual((self.game / "user-settings.cfg").read_bytes(), b"preserve my settings")

    def snapshot(self):
        return {name: (self.game / name).read_bytes() if (self.game / name).exists() else None
                for name in self.before}

    def interrupt(self, event):
        def callback(actual):
            if actual == event:
                raise Interrupted(actual)
        return patch.object(installer, "checkpoint", callback)

    def test_install_repeat_and_restore_preserve_originals_and_other_files(self):
        installer.install(self.game, self.package)
        self.assertEqual(self.snapshot(), self.after)
        self.assertIn("Already installed", installer.install(self.game, self.package))
        installer.restore(self.game)
        self.assert_retail()
        self.assertFalse((self.game / installer.STATE).exists())
        self.assertIn("No patch installed", installer.restore(self.game))

    def test_every_install_checkpoint_recovers(self):
        events = ["state_created", "preparing", *["staged:" + n for n in self.before],
                  "installing", *["installed:" + n for n in installer.INSTALL_ORDER], "installed"]
        for event in events:
            with self.subTest(event=event):
                with self.interrupt(event), self.assertRaises(Interrupted):
                    installer.install(self.game, self.package)
                installer.restore(self.game)
                self.assert_retail()
                self.assertFalse((self.game / installer.STATE).exists())

    def test_every_restore_checkpoint_recovers(self):
        for event in ["restoring", *["restored:" + n for n in installer.RESTORE_ORDER], "restored"]:
            with self.subTest(event=event):
                installer.install(self.game, self.package)
                with self.interrupt(event), self.assertRaises(Interrupted):
                    installer.restore(self.game)
                installer.restore(self.game)
                self.assert_retail()

    def test_hard_process_exit_releases_lock_and_recovers(self):
        # Exit without Python finally blocks, after replacing the archive but
        # before installing the DLL/EXE. The journal must suffice on its own.
        code = """
import json, os, sys
from pathlib import Path
sys.path.insert(0, sys.argv[1])
import install_client as installer
installer.ORIGINALS = json.loads(sys.argv[4])
def crash(event):
    if event == 'installed:resources.db':
        os._exit(91)
installer.checkpoint = crash
installer.install(Path(sys.argv[2]), Path(sys.argv[3]))
"""
        result = subprocess.run([sys.executable, "-c", code,
            str(Path(installer.__file__).parent), str(self.game), str(self.package),
            json.dumps(self.originals)], check=False)
        self.assertEqual(result.returncode, 91)
        self.assertEqual((self.game / "resources.db").read_bytes(), self.after["resources.db"])
        self.assertEqual((self.game / "binaries/x86/survarium.exe").read_bytes(), self.before["binaries/x86/survarium.exe"])
        installer.restore(self.game)
        self.assert_retail()

    def test_partial_staging_copy_leaves_game_intact_and_recovers(self):
        copy = installer.copy_verified
        def fail(source, destination, expected):
            if "/new/" in destination.as_posix():
                destination.parent.mkdir(parents=True, exist_ok=True)
                destination.write_bytes(b"incomplete copy")
                raise OSError("simulated disk full")
            copy(source, destination, expected)
        with patch.object(installer, "copy_verified", fail), self.assertRaises(OSError):
            installer.install(self.game, self.package)
        self.assert_retail()
        installer.restore(self.game)
        self.assert_retail()

    @unittest.skipUnless(sys.platform.startswith("linux"), "Linux process-map guard")
    def test_mapped_game_file_blocks_install(self):
        with (self.game / "resources.db").open("rb") as source:
            with mmap.mmap(source.fileno(), 0, access=mmap.ACCESS_READ):
                with self.assertRaisesRegex(ValueError, "Close the game"):
                    installer.install(self.game, self.package)
        self.assert_retail()

    def test_partial_final_cleanup_without_journal_recovers(self):
        installer.install(self.game, self.package)
        with self.interrupt("restored"), self.assertRaises(Interrupted):
            installer.restore(self.game)
        (self.game / installer.STATE / "journal.json").unlink()
        installer.restore(self.game)
        self.assert_retail()

    def test_invalid_payload_or_extra_manifest_path_never_changes_game(self):
        for invalid in ([], None, "not a manifest"):
            (self.package / "package.json").write_text(json.dumps(invalid))
            with self.assertRaisesRegex(ValueError, "Unsupported package"):
                installer.install(self.game, self.package)
            self.assert_retail()
        self.save_manifest()
        path = self.package / "payload/resources.db"
        path.write_bytes(b"truncated")
        with self.assertRaisesRegex(ValueError, "wrong build"):
            installer.install(self.game, self.package)
        self.assert_retail()
        self.assertFalse((self.game / installer.STATE).exists())
        path.write_bytes(self.after["resources.db"])
        self.manifest["files"]["../../outside"] = self.manifest["files"]["resources.db"]
        self.save_manifest()
        with self.assertRaisesRegex(ValueError, "exactly"):
            installer.install(self.game, self.package)
        self.assert_retail()

    def test_modified_game_or_backup_blocks_entire_restore(self):
        installer.install(self.game, self.package)
        game_archive = self.game / "resources.db"
        game_archive.write_bytes(b"another patch")
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, "changed outside"):
            installer.restore(self.game)
        self.assertEqual(self.snapshot(), before)
        game_archive.write_bytes(self.after["resources.db"])
        backup = self.game / installer.STATE / "original/resources.db"
        backup.write_bytes(b"broken backup")
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, "wrong build"):
            installer.restore(self.game)
        self.assertEqual(self.snapshot(), before)
        backup.write_bytes(self.before["resources.db"])
        installer.restore(self.game)
        self.assert_retail()

    def test_unknown_state_files_are_preserved(self):
        installer.install(self.game, self.package)
        extra = self.game / installer.STATE / "personal.txt"
        extra.write_bytes(b"keep")
        with self.assertRaisesRegex(ValueError, "Unexpected file"):
            installer.restore(self.game)
        self.assertEqual(extra.read_bytes(), b"keep")
        self.assertEqual(self.snapshot(), self.after)

    def test_linked_target_or_backup_is_rejected(self):
        target = self.game / "resources.db"
        original = self.game / "external.db"
        target.rename(original)
        target.symlink_to(original)
        with self.assertRaisesRegex(ValueError, "Linked"):
            installer.install(self.game, self.package)
        self.assertEqual(original.read_bytes(), self.before["resources.db"])
        target.unlink()
        original.rename(target)
        installer.install(self.game, self.package)
        backup = self.game / installer.STATE / "original/resources.db"
        backup.unlink()
        backup.symlink_to(target)
        with self.assertRaisesRegex(ValueError, "Linked"):
            installer.restore(self.game)
        self.assertEqual(self.snapshot(), self.after)

    def test_busy_installation_lock_is_not_stolen(self):
        with installer.installation_lock(self.game):
            with self.assertRaisesRegex(ValueError, "Another installer"):
                installer.install(self.game, self.package)
        self.assert_retail()

    def test_different_package_requires_restore(self):
        installer.install(self.game, self.package)
        self.after["resources.db"] = b"next menu version"
        (self.package / "payload/resources.db").write_bytes(self.after["resources.db"])
        self.manifest["files"]["resources.db"]["after"] = digest(self.after["resources.db"])
        self.save_manifest()
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, "restore it"):
            installer.install(self.game, self.package)
        self.assertEqual(self.snapshot(), before)
        installer.restore(self.game)
        self.assert_retail()


if __name__ == "__main__":
    unittest.main()
