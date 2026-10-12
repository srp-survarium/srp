#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Generate valid match-message fixtures using 0.26g0's original parser.

Uses the hash-gated compatibility-mode harness in retail_header_oracle.py.
Calls only the original framing/metadata routines, with a local fixed vector
and local metadata vtable. Each input has one frame; bundle mode still exercises
the original variable-length prefix parser. No game state or imports are used.
"""
import argparse
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

FRAME_CALL = r'''
    mov eax, [record]
    sub eax, 3
    mov [reader+8], eax
    mov dword ptr [reader], offset record+7
    mov dword ptr [reader+4], offset record+7
    mov dword ptr [vector], offset frame
    mov dword ptr [vector+4], offset frame
    mov dword ptr [vector+8], offset frame+28
    mov dword ptr [getter], offset vtable
    mov byte ptr [getter+4], 0xd8
    mov byte ptr [getter+5], 0xf6
    movzx eax, byte ptr [record+6]
    add eax, 7
    shr eax, 3
    mov [getter+8], al
    mov dword ptr [vtable+8], 0x279670
    mov eax, 0x279650
    cmp byte ptr [record+5], 0
    jne server_metadata
    mov eax, 0x279630
server_metadata:
    mov [vtable+4], eax
    movzx edx, byte ptr [record+4]
    push edx
    push offset vector
    mov ecx, offset reader
    mov eax, offset getter
    mov edx, 0x3fa240
    call edx
    add esp, 8
    mov [result], al
    mov eax, [reader+4]
    sub eax, offset record+7
    mov [result+4], eax
    mov eax, [frame+8]
    mov [result+8], eax
    movzx eax, byte ptr [frame+23]
    mov [result+12], eax
    movzx eax, byte ptr [frame+19]
    mov [result+16], eax
    movzx eax, byte ptr [frame+21]
    mov [result+20], eax
    movzx eax, byte ptr [frame+22]
    mov [result+24], eax
    movzx eax, byte ptr [frame+24]
    and eax, 3
    mov [result+28], eax
    movzx eax, byte ptr [frame+18]
    mov [result+32], eax
'''


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--tsv', type=Path, required=True)
    args = p.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + FRAME_CALL + ASM[end:]
    asm = asm.replace('stack: .skip', 'vector: .skip 12\nframe: .skip 28\ngetter: .skip 12\nvtable: .skip 12\n.align 16\nstack: .skip')
    cases = []
    sizes = [5,4,0,6,9,10,2,5,0,0,None,4,None,7,4,2,None,2,2,10,11,None,None,2,4,1,2,3,2,1,None]
    for id in range(0xd8, 0xf7):
        if id == 0xe2: continue
        unique = 0xe4 <= id <= 0xe8 or id == 0xf6
        for single in (False, True):
            prefix = bytes([id, 73]) if unique else bytes([id])
            if id in (0xed, 0xee):
                body = bytes([12] + ([49] if id == 0xee else []) + [1, 0, 8]) + bytes(range(16))
            else:
                body = bytes(range(sizes[id - 0xd8] or 0)) if sizes[id - 0xd8] is not None else b'\x01\x02\x03\x04'
            length = b'' if single or sizes[id - 0xd8] is not None or id in (0xed, 0xee) else bytes([len(body)])
            cases.append(bytes([single, id >= 0xe3, 20]) + prefix + length + body)
    for id in (0xe4, 0xe8, 0xf6):
        for single in (False, True):
            for index in (0, 1):
                body = bytes(range(256))
                prefix = bytes([0xff, id, 73, index] + ([2] if index == 0 else []))
                length = b'' if single else b'\xff\x00\x01'
                cases.append(bytes([single, 1, 20]) + prefix + length + body)
    for id in range(0xfa, 0xff):
        cases.append(bytes([1, 1, 20, id]))
    output = run_oracle(args.exe, args.work, asm, cases)
    rows = []
    for i, case in enumerate(cases):
        ok, consumed, size, id, unique, index, count, flags, metadata = struct.unpack_from('<9I', output, i*36)
        assert ok == 1 and consumed == len(case) - 3, (i, case.hex(), ok, consumed)
        rows.append('\t'.join(map(str, [case[3:].hex(), case[0], case[1], case[2], size, id, unique, index, count, flags, metadata])))
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.write_text('# Retail 0.26g0 parser 0x3fa240; SHA256 ' + SHA256 + '\n'
        '# frame\tsingle\tserver\tplayers\tbody_bytes\tid\tunique\tpart\tcount\tflags\tmetadata\n'
        + '\n'.join(rows) + '\n')
    print(f'{len(rows)} frames accepted by the retail message parser')


if __name__ == '__main__':
    main()
