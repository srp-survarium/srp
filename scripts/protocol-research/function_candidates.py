#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Find stripped PE function candidates from a vostok-pdb SQLite index.

Requires capstone. Masks only HIGHLOW relocations and direct control-flow
addresses, preserving constants, registers, stack/member offsets and instruction
sizes. Reports all collisions; a unique hit is still a candidate, not proof of
semantic equivalence. Shared string xrefs also locate functions that changed.
"""
import argparse
import bisect
import hashlib
import json
import re
import sqlite3
import struct
from pathlib import Path


class Image:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        pe = struct.unpack_from('<I', self.data, 0x3c)[0]
        if self.data[pe:pe + 4] != b'PE\0\0':
            raise ValueError('not a PE image')
        opt = pe + 24
        if struct.unpack_from('<H', self.data, opt)[0] != 0x10b:
            raise ValueError('expected PE32')
        self.base = struct.unpack_from('<I', self.data, opt + 28)[0]
        self.sections = []
        self.virtual_sizes = {}
        count = struct.unpack_from('<H', self.data, pe + 6)[0]
        start = opt + struct.unpack_from('<H', self.data, pe + 20)[0]
        for i in range(count):
            p = start + 40 * i
            name = self.data[p:p + 8].rstrip(b'\0').decode()
            vs, rva, size, off = struct.unpack_from('<IIII', self.data, p + 8)
            flags = struct.unpack_from('<I', self.data, p + 36)[0]
            self.sections.append((name, self.base + rva, size, off, flags))
            self.virtual_sizes[self.base + rva] = vs
        self.relocs = set()
        rva, size = struct.unpack_from('<II', self.data, opt + 96 + 5 * 8)
        if rva and size:
            p = self.offset(self.base + rva)
            end = p + size
            while p < end:
                page, block_size = struct.unpack_from('<II', self.data, p)
                if block_size < 8 or p + block_size > end:
                    raise ValueError('invalid relocation block')
                for q in range(p + 8, p + block_size, 2):
                    entry = struct.unpack_from('<H', self.data, q)[0]
                    if entry >> 12 == 3:
                        self.relocs.add(self.base + page + (entry & 0xfff))
                p += block_size

    def offset(self, va):
        for _, start, size, off, _ in self.sections:
            if start <= va < start + size:
                return off + va - start
        raise ValueError(f'VA {va:#x} has no file bytes')

    def read(self, va, size):
        off = self.offset(va)
        return self.data[off:off + size]

    def strings(self):
        result = {}
        for _, va, size, off, flags in self.sections:
            if flags & 0x20000000:
                continue
            for m in re.finditer(rb'[\x20-\x7e]{8,}\x00', self.data[off:off + size]):
                result[va + m.start()] = m[0][:-1].decode('ascii')
        return result

    def string_refs(self):
        strings = self.strings()
        result = {}
        for va in sorted(self.relocs):
            try:
                dest = struct.unpack('<I', self.read(va, 4))[0]
            except (ValueError, struct.error):
                continue
            if dest in strings:
                result.setdefault(strings[dest], []).append(va)
        return result


def signature(image, va, size, disassembler):
    import capstone
    code = image.read(va, size)
    mask = bytearray(b'\xff' * len(code))
    for r in image.relocs:
        if va <= r < va + size:
            mask[r - va:r - va + 4] = b'\0' * min(4, size - (r - va))
    consumed = 0
    for ins in disassembler.disasm(code, va):
        consumed += ins.size
        if (ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP)) and ins.imm_size:
            pos = ins.address - va + ins.imm_offset
            mask[pos:pos + ins.imm_size] = b'\0' * ins.imm_size
    if consumed != size:
        return None  # Do not accept partially decoded signatures.
    runs = [(m.start(), code[m.start():m.end()]) for m in re.finditer(b'\xff+', mask)]
    if not runs:
        return None
    anchor_off, anchor = max(runs, key=lambda x: len(x[1]))
    if len(anchor) < 8 or sum(bool(x) for x in mask) < 24:
        return None  # Tiny accessors are not useful identities.
    return code, mask, anchor_off, anchor


def main():
    import capstone
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--database', required=True, type=Path)
    ap.add_argument('--source', required=True, type=Path)
    ap.add_argument('--target', required=True, type=Path)
    ap.add_argument('--function', action='append', default=[])
    ap.add_argument('--output', required=True, type=Path)
    args = ap.parse_args()
    source, target = Image(args.source), Image(args.target)
    db = sqlite3.connect(f'{args.database.resolve().as_uri()}?mode=ro', uri=True)
    metadata = dict(db.execute('select * from metadata'))
    source_hash = hashlib.sha256(source.data).hexdigest()
    if metadata.get('exe_sha256') != source_hash:
        raise ValueError('source executable does not match the evidence database SHA256')
    rows = list(db.execute('select name,rva+image_base,size from functions order by rva'))
    rows = [r for r in rows if any(s.lower() in r[0].lower() for s in args.function)] if args.function else rows
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    src_refs, dst_refs = source.string_refs(), target.string_refs()
    refs = sorted((va, text) for text, vas in src_refs.items() for va in vas)
    ref_addresses = [x[0] for x in refs]
    output = []
    for name, va, size in rows:
        if size < 24:
            continue
        sig = signature(source, va, size, md)
        hits = []
        if sig:
            code, mask, anchor_off, anchor = sig
            for _, start, n, off, flags in target.sections:
                if not flags & 0x20000000:
                    continue
                body = target.data[off:off + n]
                p = body.find(anchor)
                while p >= 0:
                    begin = p - anchor_off
                    if begin >= 0 and begin + len(code) <= len(body):
                        candidate = body[begin:begin + len(code)]
                        if all(not m or a == b for a, b, m in zip(code, candidate, mask)):
                            hits.append(hex(start + begin))
                    p = body.find(anchor, p + 1)
        string_hits = []
        left = bisect.bisect_left(ref_addresses, va)
        right = bisect.bisect_left(ref_addresses, va + size)
        for address, string in refs[left:right]:
            if string in dst_refs:
                string_hits.append(dict(string=string, source_xref=hex(address),
                                        target_xrefs=[hex(v) for v in dst_refs[string]]))
        if hits or string_hits:
            output.append(dict(name=name, source_va=hex(va), source_size=size,
                               masked_code_candidates=hits, string_xrefs=string_hits))
    result = dict(source_sha256=source_hash,
                  target_sha256=hashlib.sha256(target.data).hexdigest(),
                  functions_considered=len(rows), candidates=output)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(f'{len(output)}/{len(rows)} functions have code or string candidates; '
          f'{sum(len(x["masked_code_candidates"]) == 1 for x in output)} unique code candidates')


if __name__ == '__main__':
    main()
