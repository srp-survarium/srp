#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Capture native 0.26g0 recomputed scoreboard scores from event counters."""
import argparse
import random
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

CALL = r'''
    mov esi, offset record+4
    mov edi, offset object+8
    mov ecx, 42
    rep movsd
    mov esi, offset record+172
    mov edi, offset options+0x577bc
    mov ecx, 28
    rep movsd
    mov dword ptr [object+0x323c], offset options
    mov byte ptr [object+0x3240], 1
    mov dword ptr [object+0x3218], 0
    mov edi, offset object
    mov eax, 0x26dc30
    call eax
    movsx eax, word ptr [object+0x31f0]
    mov [result], eax
'''

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--tsv', type=Path, required=True)
    args = p.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + CALL + ASM[end:]
    asm = asm.replace('mov edx, 36', 'mov edx, 4').replace('cmp eax, 36', 'cmp eax, 4')
    asm = asm.replace('stack: .skip',
        'object: .skip 12900\noptions: .skip 359000\n.align 16\nstack: .skip')
    cases = []
    for event in range(28):
        for count in [1, 49, 50, 51, 100]:
            events = [0] * 84
            events[event * 3] = count
            cases.append((events, [1.] * 28))
    rng = random.Random(2777)
    for _ in range(32):
        cases.append(([rng.randrange(300) for _ in range(84)],
                      [rng.choice([0., 0.5, 1., 2., 10.]) for _ in range(28)]))
    records = [struct.pack('<84H28f', *events, *weights) for events, weights in cases]
    output = run_oracle(args.exe, args.work, asm, records, output_size=4, map_data=True)
    scores = struct.unpack('<' + 'i' * len(cases), output)
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.write_text('# Retail 0x26dc30; SHA256 ' + SHA256 + '\n'
        '# events_84u16_and_weights_28f32_hex\tscore_i16\n'
        + ''.join(record.hex() + '\t' + str(score) + '\n'
                  for record, score in zip(records, scores)))
    print(f'{len(cases)} native recomputed scores captured')

if __name__ == '__main__':
    main()
