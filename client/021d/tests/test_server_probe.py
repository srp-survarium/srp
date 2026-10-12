# SPDX-License-Identifier: GPL-3.0-or-later
from pathlib import Path
import json
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
from prepare_server_probe import prepare


class ServerSnapshot(unittest.TestCase):
    def setUp(self):
        self.work = tempfile.TemporaryDirectory()
        self.addCleanup(self.work.cleanup)
        self.source = Path(self.work.name) / "source"
        self.output = Path(self.work.name) / "copy"
        (self.source / "src").mkdir(parents=True)
        (self.source / "tests/nested").mkdir(parents=True)
        (self.source / "Cargo.toml").write_text('[package]\nname="match-server-021d"\nversion.workspace=true\n')
        (self.source / "src/protocol.rs").write_bytes(b'// protocol bytes must stay unchanged\r\n')
        (self.source / "tests/nested/check.rs").write_bytes(b'// integration test\n')

    def test_snapshot_preserves_source_and_nested_tests_and_records_explicit_dialect(self):
        prepare(self.source, self.output)
        for name in ("src/protocol.rs", "tests/nested/check.rs"):
            self.assertEqual((self.source / name).read_bytes(), (self.output / name).read_bytes())
        metadata = json.loads((self.output / "srp-probe-manifest.json").read_text())
        self.assertEqual(metadata["source_transformations"], [])
        self.assertEqual(metadata["launch_arguments"], ["--protocol", "srp1"])
        self.assertIn("Cargo.toml", metadata["input_sha256"])
        with self.assertRaises(ValueError):
            prepare(self.source, self.output)

    def test_refuses_legacy_package_changed_dependencies_and_output_inside_source(self):
        with self.assertRaises(ValueError):
            prepare(self.source, self.source / "copy")
        protocol = self.source / "src/protocol.rs"
        protocol.unlink()
        with self.assertRaises(ValueError):
            prepare(self.source, self.output)
        self.assertFalse(self.output.exists())
        protocol.write_text("// restored")
        with (self.source / "Cargo.toml").open("a") as out:
            out.write('[dependencies]\nnew_library="1"\n')
        with self.assertRaises(ValueError):
            prepare(self.source, self.output)
        self.assertFalse(self.output.exists())
