# SPDX-License-Identifier: GPL-3.0-or-later
"""Format guards plus optional tests against locally supplied retail artifacts."""
import os
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import patch_exe
import patch_swf


class SWFGuards(unittest.TestCase):
    def test_original_tag_encoding_is_preserved(self):
        # Deliberately use a long tag header for a small payload. Re-encoding
        # it as a short header would break the untouched-tag guarantee.
        header = b"\x08\x00\x00\x18\x01\x00"
        raw = struct.pack("<HI", (77 << 6) | 63, 3) + b"abc"
        movie = b"FWS\x15" + struct.pack("<I", 8 + len(header) + len(raw) + 2)
        movie += header + raw + b"\0\0"
        version, parsed_header, tags = patch_swf.unpack(movie)
        self.assertEqual(tags[0][2], raw)
        self.assertEqual(patch_swf.pack(version, parsed_header, tags, False), movie)

    def test_truncated_tag_is_rejected(self):
        header = b"\x08\x00\x00\x18\x01\x00"
        body = header + struct.pack("<H", (77 << 6) | 5) + b"x"
        movie = b"FWS\x15" + struct.pack("<I", 8 + len(body)) + body
        with self.assertRaisesRegex(ValueError, "Truncated SWF tag payload"):
            patch_swf.unpack(movie)

    def test_bytes_after_end_are_rejected(self):
        body = b"\x08\x00\x00\x18\x01\x00\0\0unexpected"
        with self.assertRaisesRegex(ValueError, "after End"):
            patch_swf.unpack(b"FWS\x15" + struct.pack("<I", len(body) + 8) + body)


class PEGuards(unittest.TestCase):
    def test_unknown_build_is_rejected_before_parsing(self):
        with self.assertRaisesRegex(ValueError, "untouched retail"):
            patch_exe.patch(b"not an executable")

    @unittest.skipUnless(os.environ.get("SRP_RETAIL_EXE"), "Set SRP_RETAIL_EXE for retail integration")
    def test_loader_preserves_every_original_section(self):
        original = Path(os.environ["SRP_RETAIL_EXE"]).read_bytes()
        result, manifest = patch_exe.patch(original)
        before, after = patch_exe.PE(original), patch_exe.PE(result)
        self.assertEqual(after.count, before.count + 1)
        self.assertEqual(after.sections[:-1], before.sections)
        for rva, size, raw in before.sections:
            self.assertEqual(original[raw:raw + size], result[raw:raw + size])
        self.assertEqual(before.imports(), after.imports())
        self.assertEqual(patch_exe.u32(result, after.opt + 16), after.sections[-1][0])
        self.assertEqual(manifest["original_entry_rva"], hex(patch_exe.u32(original, before.opt + 16)))
        self.assertEqual(result[after.opt + 128:after.opt + 136], bytes(8))
        # Reapplying the retail patch to an already modified input must fail.
        with self.assertRaisesRegex(ValueError, "untouched retail"):
            patch_exe.patch(result)


if __name__ == "__main__":
    unittest.main()
