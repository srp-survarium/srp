#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Execute the 0.26g0 time-limit rule predicate at its real deadline boundaries."""
import argparse
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

CALL = r'''
    mov eax, [record+4]
    mov [object+0x12c], eax
    mov eax, [record+12]
    mov [object+0x148], eax
    mov eax, [record+16]
    mov [object+0x138], eax
    mov eax, [record+20]
    mov [object+0x13c], eax
    push dword ptr [record+8]
    mov ecx, offset object
    mov edx, 0x318360
    call edx
    movzx eax, al
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
    asm = asm.replace('stack: .skip', 'object: .skip 336\n.align 16\nstack: .skip')
    cases = []
    for match_ms, wait_ms in [(900_000, 300_000), (90_000, 300_000), (600_000, 60_000)]:
        for state in range(4):
            for elapsed in sorted({0, wait_ms - 1, wait_ms, wait_ms + 1, match_ms - 1, match_ms, match_ms + 1}):
                cases.append((20500, 20500 + elapsed, state, match_ms, wait_ms))
    output = run_oracle(args.exe, args.work, asm,
                        [struct.pack('<5I', *case) for case in cases], output_size=4)
    results = struct.unpack('<' + 'I' * len(cases), output)
    assert all(result in (0, 1) for result in results)
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.write_text('# Retail 0x318360; SHA256 ' + SHA256 + '\n'
        '# start\tcurrent\tstate\tmatch_ms\twait_ms\tcompleted\n'
        + ''.join('\t'.join(map(str, (*case, result))) + '\n' for case, result in zip(cases, results)))
    print(f'{len(cases)} native completion results captured')


if __name__ == '__main__':
    main()
