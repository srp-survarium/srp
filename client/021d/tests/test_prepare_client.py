# SPDX-License-Identifier: GPL-3.0-or-later
"""Preparation must reject unsafe destinations before writing any output."""
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import prepare_client


class PreparationGuards(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.game = self.root / "game"
        (self.game / "binaries/x86").mkdir(parents=True)
        self.exe = self.game / "binaries/x86/survarium.exe"
        self.exe.write_bytes(b"different game build")
        (self.game / "resources.db").write_bytes(b"original resources")

    def prepare(self, output):
        prepare_client.prepare(SimpleNamespace(game=self.game, output=output))

    def test_unknown_retail_build_produces_no_output(self):
        output = self.root / "package"
        with self.assertRaisesRegex(ValueError, "Unsupported or modified input"):
            self.prepare(output)
        self.assertFalse(output.exists())
        self.assertEqual(self.exe.read_bytes(), b"different game build")
        self.assertEqual((self.game / "resources.db").read_bytes(), b"original resources")

    def test_existing_destination_is_untouched(self):
        output = self.root / "package"
        output.mkdir()
        marker = output / "package.json"
        marker.write_bytes(b"previous verified package")
        with self.assertRaisesRegex(ValueError, "Output exists"):
            self.prepare(output)
        self.assertEqual(marker.read_bytes(), b"previous verified package")
        self.assertEqual(list(output.iterdir()), [marker])

    def test_output_inside_retail_installation_is_rejected(self):
        output = self.game / "new-package"
        with self.assertRaisesRegex(ValueError, "outside the retail installation"):
            self.prepare(output)
        self.assertFalse(output.exists())


if __name__ == "__main__":
    unittest.main()
