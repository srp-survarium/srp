# SPDX-License-Identifier: GPL-3.0-or-later

"""Read-only identification of the researched Skhid binary; does not install hooks."""
import argparse
import hashlib
from pathlib import Path
import struct

EXPECTED_SHA256 = "166d25bcc49f6e1b83fc0d85c25e822c85c7284d4d846143358ca2f28bd31ddf"
IMAGE_BASE = 0x10000
SITES = {
    0x124F9: bytes.fromhex("9090"),
    0x12A10: bytes.fromhex("31c0c3"),
    0x27A505: bytes.fromhex("e91eab1a0a9090"),
    0x27AEA1: bytes.fromhex("e95aa11a0a90"),
    0x27CC53: bytes.fromhex("32"),
}


def verify(path):
    data = path.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != EXPECTED_SHA256:
        raise ValueError(f"unsupported executable SHA-256: {digest}")
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if data[:2] != b"MZ" or data[pe:pe + 4] != b"PE\0\0":
        raise ValueError("not a PE executable")
    machine, count = struct.unpack_from("<HH", data, pe + 4)
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    if machine != 0x14C or struct.unpack_from("<I", data, pe + 52)[0] != IMAGE_BASE:
        raise ValueError("wrong architecture/image base")
    sections = []
    for index in range(count):
        offset = pe + 24 + optional_size + index * 40
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from("<IIII", data, offset + 8)
        sections.append((rva, min(virtual_size, raw_size), raw_offset))
    for va, expected in SITES.items():
        rva = va - IMAGE_BASE
        matches = [raw + rva - start for start, size, raw in sections
                   if start <= rva and rva + len(expected) <= start + size]
        if len(matches) != 1 or data[matches[0]:matches[0] + len(expected)] != expected:
            raise ValueError(f"unexpected bytes at preferred VA {va:#x}")
    return digest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("executable", type=Path)
    args = parser.parse_args()
    try:
        digest = verify(args.executable)
    except (OSError, ValueError, struct.error) as error:
        parser.exit(1, f"Rejected: {error}\n")
    print(f"Identified researched Skhid build: {digest}")
    print("No executable changes made. This check does not certify runtime safety.")


if __name__ == "__main__":
    main()
