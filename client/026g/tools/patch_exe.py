#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build a separate development executable from hash-matched retail 0.26g0.

The resource verification certificate comes from this exact pinned executable.
Skip its obsolete PKI chain check while retaining resource RSA verification.
This does not patch the TLS/login certificate validation path.
"""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import tempfile
from pathlib import Path

RETAIL_SHA256 = 'ac33d9937015c2299bf62cc6b127cb308b48a3475b30fff2ddd65479ae3bf153'
PATCHES = [
    ('archival_resource_signing_certificate', 0x13509, 'e802f5ffff', '31c0909090'),
    # Preserve the CreateMutexA failure path; accept ERROR_ALREADY_EXISTS.
    ('multiple_instances', 0x124f9, '7409', '9090'),
    # Keep the measured memory size and the existing unknown-size fallback.
    # Suppress only the fatal diagnostic for a nonzero value below 320 MiB.
    ('legacy_minimum_vram_warning', 0x106411, '730f', 'eb0f'),
]


def patch(original, direct_match=False, snapshots=False, *, assembly_file=None, extra_hooks=(), results=False, rejoin=False, cc='cc'):
    if snapshots and not direct_match:
        raise ValueError('Snapshot extension currently requires --direct-match')
    if results and not snapshots:
        raise ValueError('Results extension requires --snapshots')
    if rejoin and not results:
        raise ValueError('Rejoin requires --results')
    if (assembly_file is not None or extra_hooks) and not direct_match:
        raise ValueError('Additional hook sources require the direct-match code section')
    if hashlib.sha256(original).hexdigest() != RETAIL_SHA256:
        raise ValueError('Expected unmodified 0.26g0 build 2777; input SHA256 differs')
    pe = struct.unpack_from('<I', original, 0x3c)[0]
    opt = pe + 24
    base = struct.unpack_from('<I', original, opt + 28)[0]
    count = struct.unpack_from('<H', original, pe + 6)[0]
    sections = opt + struct.unpack_from('<H', original, pe + 20)[0]
    data = bytearray(original)
    edits = []
    patches = list(PATCHES)
    if direct_match:
        # No authenticated lobby profile exists on the development path. The
        # retail null branch nevertheless calls its statistics reset routine.
        # Skip that reset only when the original profile-owner check is null.
        patches.append(('direct_match_without_lobby_statistics', 0x27a1d1, '33c0', 'eb05'))
    if snapshots:
        # The transport validates the getter's opcode range before consulting
        # its length/delivery callbacks. Extend only this match client's ranges.
        patches.append(('snapshot_server_message_range', 0x27a153, 'c64605f6', 'c64605f8' if results else 'c64605f7'))
        patches.append(('snapshot_client_message_range', 0x27a15b, 'c64607e1', 'c64607e2'))
    for name, va, expected_hex, replacement_hex in patches:
        expected, replacement = bytes.fromhex(expected_hex), bytes.fromhex(replacement_hex)
        assert len(expected) == len(replacement)
        offset = None
        for n in range(count):
            _, rva, size, raw = struct.unpack_from('<IIII', original, sections + 40*n + 8)
            if base+rva <= va and va+len(expected) <= base+rva+size:
                offset = raw + va-base-rva
                break
        if offset is None or original[offset:offset+len(expected)] != expected:
            raise ValueError(f'Patch precondition failed: {name} at {va:#x}')
        data[offset:offset+len(replacement)] = replacement
        edits.append(dict(name=name, va=hex(va), offset=hex(offset),
                          before=expected_hex, after=replacement_hex))
    if direct_match:
        section_alignment, file_alignment = struct.unpack_from('<II', original, opt + 32)
        align = lambda value, boundary: (value + boundary - 1) // boundary * boundary
        section_rows = [struct.unpack_from('<IIII', original, sections + 40*n + 8)
                        for n in range(count)]
        first_raw = min(raw for _, _, size, raw in section_rows if size)
        header = sections + 40*count
        added_headers = 2 if rejoin else 1
        if header+40*added_headers > first_raw or any(original[header:header+40*added_headers]):
            raise ValueError('No spare section-header slot')
        rva = align(max(rva + max(virtual, size) for virtual, rva, size, _ in section_rows),
                    section_alignment)
        raw = align(len(data), file_alignment)
        state_rva = rva + 0x10000
        with tempfile.TemporaryDirectory(prefix='srp-026-patch-') as folder:
            work = Path(folder)
            source = Path(assembly_file or Path(__file__).with_name('direct_match.S'))
            if results:
                compiled = work/'results.s'
                subprocess.run([cc, '-m32', '-march=i686', '-mfpmath=387', '-Os',
                    f'-DWITH_REJOIN={int(rejoin)}',
                    '-ffreestanding', '-fno-pic', '-fno-pie', '-fno-stack-protector',
                    '-fno-asynchronous-unwind-tables', '-S',
                    str(Path(__file__).with_name('results.c')), '-o', str(compiled)], check=True)
                assembly = compiled.read_text()
                if rejoin:
                    rejoin_assembly = work/'rejoin.s'
                    subprocess.run([cc, '-m32', '-march=i686', '-mfpmath=387', '-Os',
                        '-ffreestanding', '-fno-pic', '-fno-pie', '-fno-stack-protector',
                        '-fno-asynchronous-unwind-tables', f'-DREJOIN_STATE={hex(base+state_rva)}',
                        '-S', str(Path(__file__).with_name('rejoin.c')),
                        '-o', str(rejoin_assembly)], check=True)
                    assembly += '\n' + rejoin_assembly.read_text().replace('.L', '.Lrejoin')
                if re.search(r'^\s*\.(?:data|bss)(?:\s|$)', assembly, re.M):
                    raise ValueError('Results handler unexpectedly requires writable static storage')
                assembly = re.sub(r'^\s*\.section\s+\.rodata[^\n]*', '\n.text', assembly, flags=re.M)
                for section in re.findall(r'^\s*\.section\s+([^\n]+)', assembly, re.M):
                    if not section.startswith('.note.GNU-stack'):
                        raise ValueError(f'Unexpected results section: {section}')
                combined = work/'combined.S'
                combined.write_text(source.read_text() + '\n.att_syntax prefix\n' + assembly)
                source = combined
            subprocess.run(['as', '--32', '--defsym', f'WITH_SNAPSHOTS={int(snapshots)}',
                            '--defsym', f'WITH_RESULTS={int(results)}',
                            '--defsym', f'WITH_REJOIN={int(rejoin)}', '-o', str(work/'hook.o'),
                            str(source)], check=True)
            subprocess.run(['ld', '-m', 'elf_i386', '-Ttext', hex(base+rva),
                            '-o', str(work/'hook.elf'), str(work/'hook.o')], check=True)
            subprocess.run(['objcopy', '-O', 'binary', '--only-section=.text',
                            str(work/'hook.elf'), str(work/'hook.bin')], check=True)
            code = (work/'hook.bin').read_bytes()
            symbols = {}
            for row in subprocess.check_output(['nm', '-n', str(work/'hook.elf')], text=True).splitlines():
                parts = row.split()
                if len(parts) == 3:
                    symbols[parts[2]] = int(parts[0], 16)
        raw_size = align(len(code), file_alignment)
        if rejoin and raw_size > state_rva-rva:
            raise ValueError('Hook code overlaps the rejoin state section')
        data.extend(bytes(raw-len(data)))
        data.extend(code + bytes(raw_size-len(code)))
        struct.pack_into('<8sIIIIIIHHI', data, header, b'.srp\0\0\0\0', len(code), rva,
                         raw_size, raw, 0, 0, 0, 0, 0x60000020)
        struct.pack_into('<H', data, pe+6, count+added_headers)
        struct.pack_into('<I', data, opt+56, align(rva+len(code), section_alignment))
        struct.pack_into('<I', data, opt+4, struct.unpack_from('<I', data, opt+4)[0]+raw_size)
        if rejoin:
            state_raw = align(len(data), file_alignment)
            state_size = align(512, file_alignment)
            data.extend(bytes(state_raw+state_size-len(data)))
            struct.pack_into('<8sIIIIIIHHI', data, header+40, b'.srpd\0\0\0', 512,
                             state_rva, state_size, state_raw, 0, 0, 0, 0, 0xc0000040)
            struct.pack_into('<I', data, opt+56, align(state_rva+512, section_alignment))
            struct.pack_into('<I', data, opt+8, struct.unpack_from('<I', data, opt+8)[0]+state_size)
            edits.append(dict(name='rejoin_endpoint_state', va=hex(base+state_rva),
                              offset=hex(state_raw), size=512, permissions='RW'))
        hook_va = 0x1ec0e1
        for _, section_rva, size, section_raw in section_rows:
            if base+section_rva <= hook_va < base+section_rva+size:
                hook_offset = section_raw+hook_va-base-section_rva
                break
        before = bytes.fromhex('e8fa150000')
        assert data[hook_offset:hook_offset+5] == before
        after = b'\xe8' + struct.pack('<i', base+rva-hook_va-5)
        data[hook_offset:hook_offset+5] = after
        edits.append(dict(name='development_direct_match', va=hex(hook_va),
                          offset=hex(hook_offset), before=before.hex(), after=after.hex(),
                          code_va=hex(base+rva), code_offset=hex(raw), code=code.hex()))
        hooks = list(extra_hooks)
        if results:
            hooks.append(('results_mouse', 0x26cff0, '51568bf18b46b0'))
        if rejoin:
            hooks.append(('rejoin_key', 0x26cb60, '8d81bc2f0000'))
        if snapshots:
            hooks += [
                ('snapshot_ready', 0x27ae9a, 'c683681c1f00ff'),
                ('snapshot_length', 0x279670, '558bec83e4f8'),
                ('snapshot_delivery', 0x279a60, '81c128ffffff'),
                ('snapshot_server_delivery', 0x279b10, '81c11dffffff'),
                ('snapshot_request', 0x27a300, '558bec83ec64'),
            ]
        if hooks:
            for name, va, expected_hex in hooks:
                expected = bytes.fromhex(expected_hex)
                for _, section_rva, size, section_raw in section_rows:
                    if base+section_rva <= va < base+section_rva+size:
                        offset = section_raw+va-base-section_rva
                        break
                if data[offset:offset+len(expected)] != expected:
                    raise ValueError(f'Patch precondition failed: {name}')
                after = b'\xe9' + struct.pack('<i', symbols[name]-va-5) + b'\x90'*(len(expected)-5)
                data[offset:offset+len(expected)] = after
                edits.append(dict(name=name, va=hex(va), offset=hex(offset),
                                  before=expected.hex(), after=after.hex(), code_va=hex(symbols[name])))
    # Keep the original certificate table: resource verification extracts its
    # public key. The modified executable itself is no longer Authenticode-valid.
    return bytes(data), dict(build='0.26g0 build 2777', input_sha256=RETAIL_SHA256,
                             output_sha256=hashlib.sha256(data).hexdigest(), patches=edits)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--manifest', type=Path, required=True)
    parser.add_argument('--direct-match', action='store_true',
                        help='Development hook: automatically join -server=host:port after UI initialization')
    parser.add_argument('--snapshots', action='store_true', help='E2 startup upload and F7 historical-state requests; requires --direct-match')
    parser.add_argument('--results', action='store_true', help='Receive F8 match results and render the native results UI; requires --snapshots')
    parser.add_argument('--rejoin', action='store_true', help='F6 after closing results rejoins the launch endpoint; requires --results')
    parser.add_argument('--cc', default='cc', help='GCC-compatible x86 compiler for --results')
    args = parser.parse_args()
    if args.source.resolve() == args.output.resolve():
        parser.error('Use a separate output path; keep the retail executable')
    data, manifest = patch(args.source.read_bytes(), args.direct_match, args.snapshots,
                           results=args.results, rejoin=args.rejoin, cc=args.cc)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    args.manifest.parent.mkdir(parents=True, exist_ok=True)
    args.manifest.write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps(manifest, indent=2))


if __name__ == '__main__':
    main()
