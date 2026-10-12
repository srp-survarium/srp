#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Execute retail battery score updates and their delayed completion predicate.

The synthetic objects model only fields touched by 0x313a50 and 0x314230.
No world simulation, imports, or callbacks are executed. Output verifies the
statistics-handler/subobject offset as well as the three-second victory delay.
"""
import argparse
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

CALL = r'''
    mov eax, [record+4]
    mov [rule+0x144], al
    mov [stats+0x31d4], ax
    mov edx, [record+8]
    mov [rule+0x145], dl
    mov [stats+0x31d6], dx
    mov ecx, 2
    cmp eax, edx
    je winner_ready
    mov ecx, 0
    ja winner_ready
    mov ecx, 1
winner_ready:
    mov [stats+0x31e4], ecx
    mov eax, [record+12]
    mov [event], eax
    mov eax, [record+16]
    mov [event+4], eax
    mov eax, [record+24]
    shl eax, 2
    add eax, offset items
    mov [rule+0x114], eax
    mov dword ptr [rule+0x110], offset items
    mov eax, [record+28]
    mov [rule+0x15c], eax
    mov byte ptr [rule+0x160], 0xff
    mov dword ptr [rule+0x158], offset core
    mov dword ptr [core+0x18fa8], offset stats
    push dword ptr [record+20]
    push offset event
    push 2
    mov ecx, offset rule
    mov eax, 0x313a50
    call eax
    movzx eax, byte ptr [rule+0x144]
    mov [result], eax
    movzx eax, byte ptr [rule+0x145]
    mov [result+4], eax
    movzx eax, word ptr [stats+0x31d4]
    mov [result+8], eax
    movzx eax, word ptr [stats+0x31d6]
    mov [result+12], eax
    mov eax, [stats+0x31e4]
    mov [result+16], eax
    mov eax, [rule+0x15c]
    mov [result+20], eax
    push dword ptr [record+32]
    mov ecx, offset rule
    mov eax, 0x314230
    call eax
    mov [result+24], eax
    movzx eax, byte ptr [rule+0x160]
    mov [result+28], eax
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, required=True)
    parser.add_argument('--work', type=Path, required=True)
    parser.add_argument('--tsv', type=Path, required=True)
    args = parser.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + CALL + ASM[end:]
    asm = asm.replace('mov edx, 36', 'mov edx, 32').replace('cmp eax, 36', 'cmp eax, 32')
    asm = asm.replace('stack: .skip',
        'rule: .skip 368\nevent: .skip 8\nitems: .skip 64\n'
        'core: .skip 102320\nstats: .skip 12800\n.align 16\nstack: .skip')
    cases = []
    for first, second in [(0, 0), (4, 4), (9, 0), (0, 9), (10, 0), (0, 10)]:
        for team in [0, 1]:
            for action in [0, 1]:
                # Never model a removal from an empty container.
                if action == 1 and [first, second][team] == 0:
                    continue
                for deadline in [0xffffffff, 22000]:
                    for probe in [20499, 23499, 23500, 23501]:
                        cases.append((first, second, team, action, 20500, 10, deadline, probe))
    output = run_oracle(args.exe, args.work, asm,
        [struct.pack('<8I', *case) for case in cases], output_size=32)
    results = list(struct.iter_unpack('<8I', output))
    for case, result in zip(cases, results):
        first, second, team, action, now, total, deadline, probe = case
        points = [first, second]
        flag = 255
        if deadline == 0xffffffff:
            points[team] += 1 if action == 0 else -1
            if total in points:
                deadline, flag = now + 3000, 0
        winner = 2 if points[0] == points[1] else int(points[1] > points[0])
        expected = (*points, *points, winner, deadline,
                    int(deadline != 0xffffffff and deadline <= probe), flag)
        if result != expected:
            raise ValueError(f'native battery semantics differ: {case}: {result} != {expected}')
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.write_text('# Retail 0x313a50 and 0x314230; SHA256 ' + SHA256 + '\n'
        '# first\tsecond\tteam\taction\tnow\ttotal\told_deadline\tprobe\t'
        'new_first\tnew_second\tscore_first\tscore_second\twinner\tdeadline\tcompleted\tflag\n'
        + ''.join('\t'.join(map(str, (*case, *result))) + '\n'
                  for case, result in zip(cases, results)))
    print(f'{len(cases)} native battery update/completion cases captured')


if __name__ == '__main__':
    main()
