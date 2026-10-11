#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Check raw LZMA2 streams against 0.26g0's original decoder (VA 0x3ee810).

The client supplies dictionary property 6 (32 KiB) out of band. The harness
uses a local bump allocator for the SDK decoder and compares every output byte.
Requires Python's lzma module, plus the shared native oracle requirements.
"""
import argparse
import lzma
import random
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

CAPACITY = 65537
OUTPUT_SIZE = CAPACITY + 16
CALL = r'''
    mov dword ptr [allocator], offset allocate32
    mov dword ptr [allocator+4], offset free32
    mov dword ptr [heap_used], 0
    mov dword ptr [result+4], 65536
    push offset allocator
    push offset result+8
    push offset record+4
    push offset result+4
    push offset result+16
    mov ecx, offset reader+8
    mov eax, 6
    mov edx, 0x3ee810
    call edx
    add esp, 20
    mov [result], eax
    mov eax, [reader+8]
    mov [result+12], eax
'''
ALLOCATOR = r'''
.code32
allocate32:
    mov edx, [esp+8]
    add edx, 15
    and edx, -16
    mov eax, [heap_used]
    add edx, eax
    cmp edx, 2097152
    ja allocation_failed
    mov [heap_used], edx
    add eax, offset heap
    ret
allocation_failed:
    xor eax, eax
    ret
free32:
    ret
'''


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--tsv', type=Path, required=True)
    args = p.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + CALL.replace('65536', str(CAPACITY)) + ASM[end:]
    asm = asm.replace('mov edx, 36', f'mov edx, {OUTPUT_SIZE}').replace('cmp eax, 36', f'cmp eax, {OUTPUT_SIZE}')
    asm = asm.replace('result: .skip 36', f'result: .skip {OUTPUT_SIZE}')
    asm = asm.replace('.section .bss', ALLOCATOR + '\n.section .bss')
    asm = asm.replace('stack: .skip', 'allocator: .skip 8\nheap_used: .skip 4\n.align 16\nheap: .skip 2097152\nstack: .skip')
    rng = random.Random(2777)
    cases = [(b'Hello world', 100), (bytes(range(256)), 16),
             (bytes(rng.randrange(256) for _ in range(96)), 1), (b'A', 65536),
             (b'match_options\0player\0inventory\0', 500)]
    compressed = [lzma.compress(seed * repeat, format=lzma.FORMAT_RAW,
        filters=[dict(id=lzma.FILTER_LZMA2, dict_size=32768, lc=4, lp=0, pb=2, preset=9)])
        for seed, repeat in cases]
    output = run_oracle(args.exe, args.work, asm, compressed, output_size=OUTPUT_SIZE, map_data=True)
    for i, (seed, repeat) in enumerate(cases):
        result, length, status, used = struct.unpack_from('<4I', output, i*OUTPUT_SIZE)
        assert result == 0 and length == len(seed)*repeat and used == len(compressed[i]), (i,result,length,status,used)
        assert output[i*OUTPUT_SIZE+16:i*OUTPUT_SIZE+16+length] == seed*repeat
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.write_text('# Raw LZMA2 verified by retail decoder 0x3ee810; SHA256 ' + SHA256 + '\n'
        '# seed\trepeat\tcompressed\n' + ''.join(
            f'{seed.hex()}\t{repeat}\t{data.hex()}\n' for (seed, repeat), data in zip(cases, compressed)))
    print(f'{len(cases)} raw LZMA2 streams decoded byte-for-byte by retail code')


if __name__ == '__main__':
    main()
