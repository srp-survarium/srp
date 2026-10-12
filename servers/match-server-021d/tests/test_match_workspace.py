# SPDX-License-Identifier: GPL-3.0-or-later
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
from match_registry import MatchWorkspace


class WorkspaceOwnership(unittest.TestCase):
    def test_restart_cleans_only_owned_allocations_and_preserves_evidence(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            marked = root / "old-match"
            unknown = root / "other-work"
            for directory in (marked, unknown):
                directory.mkdir()
                (directory / "sessions").write_text("private grant")
                (directory / "control.sock").touch()
                (directory / "server.log").write_text("evidence")
            (marked / ".srp-allocation").write_text(MatchWorkspace.MARKER)
            owner = MatchWorkspace(root)
            try:
                self.assertFalse((marked / "sessions").exists())
                self.assertFalse((marked / "control.sock").exists())
                self.assertEqual((marked / "server.log").read_text(), "evidence")
                self.assertTrue((unknown / "sessions").exists())
            finally:
                owner.close()
            self.assertTrue((root / ".owner.lock").exists())

    def test_surviving_child_keeps_exclusive_ownership_after_parent_closes(self):
        with tempfile.TemporaryDirectory() as tmp:
            owner = MatchWorkspace(tmp)
            child = subprocess.Popen([sys.executable, "-c", "import sys; sys.stdin.read()"],
                                     stdin=subprocess.PIPE, pass_fds=(owner.fd,))
            try:
                with self.assertRaises(BlockingIOError):
                    MatchWorkspace(tmp)
                owner.close()
                with self.assertRaises(BlockingIOError):
                    MatchWorkspace(tmp)
                child.stdin.close()
                child.wait(timeout=5)
                restarted = MatchWorkspace(tmp)
                restarted.close()
            finally:
                owner.close()
                if child.poll() is None:
                    child.kill()
                    child.wait()
                if child.stdin is not None:
                    child.stdin.close()

    def test_marked_symlink_directory_cannot_delete_external_grants(self):
        with tempfile.TemporaryDirectory() as tmp, tempfile.TemporaryDirectory() as other:
            target = Path(other)
            (target / ".srp-allocation").write_text(MatchWorkspace.MARKER)
            (target / "sessions").write_text("untouched")
            (Path(tmp) / "link").symlink_to(target, target_is_directory=True)
            owner = MatchWorkspace(tmp)
            owner.close()
            self.assertEqual((target / "sessions").read_text(), "untouched")


if __name__ == "__main__":
    unittest.main()
