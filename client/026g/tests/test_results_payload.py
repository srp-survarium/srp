# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise the actual C bounds validator without loading any game code."""
import ctypes
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest


class ResultsPayload(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.work = tempfile.TemporaryDirectory(prefix='srp-results-validator-')
        cls.addClassCleanup(cls.work.cleanup)
        library = Path(cls.work.name) / 'validator.so'
        source = Path(__file__).resolve().parents[1] / 'tools/results.c'
        subprocess.run([os.environ.get('CC', 'cc'), '-shared', '-fPIC', '-O2',
                        '-DRESULTS_PARSER_ONLY', str(source), '-o', str(library)], check=True)
        cls.library = ctypes.CDLL(str(library))
        cls.check = cls.library.results_valid_payload
        cls.check.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.c_uint]
        cls.check.restype = ctypes.c_int

    def valid(self, data):
        array = (ctypes.c_ubyte * len(data)).from_buffer_copy(data)
        return bool(self.check(array, len(data)))

    @staticmethod
    def payload(count, local):
        time = 98750
        data = bytearray(struct.pack('<4BIIIHH4B', 1, time//50 & 255, local, 2,
            time, 1, (1 << count)-1, 3, 2, 0, count, local % 2, 0))
        for slot in range(count):
            name = ('Player' + str(slot+1)).encode()
            data.extend(struct.pack('<IBBHHHhBB64s', slot+1, slot%2, 0, 10,
                                    4, 2, 7, len(name), 0, name))
        return data

    def test_valid_rosters_and_every_truncation(self):
        for count in range(1, 21):
            data = self.payload(count, count-1)
            self.assertTrue(self.valid(data))
            for end in range(len(data)):
                self.assertFalse(self.valid(data[:end]), (count, end))
            self.assertFalse(self.valid(data + b'\0'))

    def test_invalid_identity_masks_and_names(self):
        data = self.payload(2, 1)
        for offset, value in [(0, 2), (1, 0), (2, 2), (3, 4), (12, 0), (12, 4),
                              (20, 3), (21, 0), (21, 21), (22, 0), (23, 1),
                              (28, 2), (29, 1), (38, 64), (39, 1), (40, 0),
                              (47, 1)]:
            bad = data.copy()
            bad[offset] = value
            self.assertFalse(self.valid(bad), (offset, value))


if __name__ == '__main__':
    unittest.main()
