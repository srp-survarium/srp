#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Add a position-independent DLL bootstrap to a copy of retail 0.21d."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

RETAIL_SHA256 = "def82eeaed9d544b2e1c1e0ec971f7359c24a942dd52ace6b45e6d82e7c34a0a"


def u16(data, pos):
    return struct.unpack_from("<H", data, pos)[0]


def u32(data, pos):
    return struct.unpack_from("<I", data, pos)[0]


def align(value, boundary):
    return (value + boundary - 1) // boundary * boundary


class PE:
    def __init__(self, data):
        self.data = data
        self.pe = u32(data, 60)
        if data[:2] != b"MZ" or data[self.pe:self.pe + 4] != b"PE\0\0":
            raise ValueError("Not a PE file")
        self.opt = self.pe + 24
        if u16(data, self.pe + 4) != 0x14c or u16(data, self.opt) != 0x10b:
            raise ValueError("Expected x86 PE32")
        self.table = self.opt + u16(data, self.pe + 20)
        self.count = u16(data, self.pe + 6)
        self.sections = []
        for i in range(self.count):
            pos = self.table + 40 * i
            self.sections.append((u32(data, pos + 12), u32(data, pos + 16), u32(data, pos + 20)))

    def offset(self, rva):
        for start, size, raw in self.sections:
            if start <= rva < start + size:
                return raw + rva - start
        raise ValueError(f"RVA {rva:#x} has no file bytes")

    def imports(self):
        result = {}
        pos = self.offset(u32(self.data, self.opt + 104))
        while any(self.data[pos:pos + 20]):
            lookup, _, _, _, iat = struct.unpack_from("<5I", self.data, pos)
            at = self.offset(lookup or iat)
            index = 0
            while (name_rva := u32(self.data, at + index * 4)):
                if not name_rva & 0x80000000:
                    name_pos = self.offset(name_rva) + 2
                    end = self.data.index(0, name_pos)
                    name = bytes(self.data[name_pos:end]).decode("ascii")
                    result[name] = iat + index * 4
                index += 1
            pos += 20
        return result


def bootstrap(rva, entry, imports):
    code = bytearray(b"\x9c\x60\xe8\0\0\0\0\x5b\x81\xeb")
    code += struct.pack("<I", rva + 7)  # EBX = actual image base
    strings, failures = [], []

    def lea(opcode, label):
        code.extend(opcode)
        strings.append((len(code), label))
        code.extend(b"\0" * 4)

    def call(name):
        code.extend(b"\xff\x93" + struct.pack("<I", imports[name]))

    def check():
        code.extend(b"\x85\xc0\x0f\x84")
        failures.append(len(code))
        code.extend(b"\0" * 4)

    lea(b"\x8d\x83", "dll")
    code += b"\x50"
    call("LoadLibraryA")
    check()
    lea(b"\x8d\x8b", "init")
    code += b"\x51\x50"
    call("GetProcAddress")
    check()
    code += b"\xff\xd0"  # srp_initialize(), outside loader lock
    check()
    code += b"\x61\x9d\xe9"
    code += struct.pack("<I", (entry - (rva + len(code) + 4)) & 0xffffffff)
    failed = len(code)
    code += b"\x68" + struct.pack("<I", 0x53525001)
    call("ExitProcess")
    code += b"\xcc"
    labels = {}
    for label, value in (("dll", b"srp-client-021d.dll\0"), ("init", b"srp_initialize\0")):
        labels[label] = len(code)
        code += value
    for pos, label in strings:
        struct.pack_into("<I", code, pos, rva + labels[label])
    for pos in failures:
        struct.pack_into("<i", code, pos, failed - (pos + 4))
    return code


def patch(original):
    if hashlib.sha256(original).hexdigest() != RETAIL_SHA256:
        raise ValueError("Expected untouched retail 0.21d build 2010; input is not supported")
    data = bytearray(original)
    pe = PE(data)
    header = pe.table + pe.count * 40
    if header + 40 > u32(data, pe.opt + 60) or any(data[header:header + 40]):
        raise ValueError("No empty section-header slot")
    rva = align(u32(data, pe.opt + 56), u32(data, pe.opt + 32))
    raw = align(len(data), u32(data, pe.opt + 36))
    entry = u32(data, pe.opt + 16)
    code = bootstrap(rva, entry, pe.imports())
    raw_size = align(len(code), u32(data, pe.opt + 36))
    data += bytes(raw - len(data)) + code + bytes(raw_size - len(code))
    struct.pack_into("<8s6I2HI", data, header, b".srp\0\0\0\0", len(code), rva,
                     raw_size, raw, 0, 0, 0, 0, 0x60000020)
    struct.pack_into("<H", data, pe.pe + 6, pe.count + 1)
    struct.pack_into("<I", data, pe.opt + 16, rva)
    struct.pack_into("<I", data, pe.opt + 4, u32(data, pe.opt + 4) + raw_size)
    struct.pack_into("<I", data, pe.opt + 56, align(rva + len(code), u32(data, pe.opt + 32)))
    struct.pack_into("<I", data, pe.opt + 64, 0)  # Optional image checksum
    struct.pack_into("<II", data, pe.opt + 128, 0, 0)  # Original signature no longer applies
    return bytes(data), {"input_sha256": RETAIL_SHA256,
                         "output_sha256": hashlib.sha256(data).hexdigest(),
                         "bootstrap_rva": hex(rva), "original_entry_rva": hex(entry),
                         "dll": "srp-client-021d.dll", "export": "srp_initialize"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    if args.output.exists():
        parser.error("Output exists; never overwrite an existing game executable")
    result, manifest = patch(args.source.read_bytes())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(result)
    args.output.with_suffix(".manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
