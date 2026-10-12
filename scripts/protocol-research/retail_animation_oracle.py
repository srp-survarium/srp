#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Check captured 0.26g0 animation boundaries with the original decoder.

Inputs are complete, trusted E2 snapshot bodies exported by inspect_capture.
Runs retail decode_data (0x3a9900), including its time/float dictionary readers.
Never use this native harness on malformed/untrusted input. No game is launched.
"""
import argparse
import json
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

CALL = r'''
    mov dword ptr [object+4], offset object+16
    mov dword ptr [object+8], offset object+16
    mov dword ptr [object+12], offset object+0x1010
    mov dword ptr [object+0x1010], offset object+0x101c
    mov dword ptr [object+0x1014], offset object+0x101c
    mov dword ptr [object+0x1018], offset object+0x201c
    push offset reader
    mov eax, offset object
    mov edx, 0x3a9900
    call edx
    mov eax, [reader+4]
    sub eax, offset record+4
    mov [result], eax
    mov eax, [object+8]
    sub eax, offset object+16
    shr eax, 2
    mov [result+4], eax
    mov eax, [object+0x1014]
    sub eax, offset object+0x101c
    shr eax, 2
    mov [result+8], eax
'''


def block(data, cursor):
    size, = struct.unpack_from('<H', data, cursor)
    end = cursor + 2 + size
    assert end <= len(data)
    return [cursor + 2, end]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--tsv', type=Path, help='write native animation regression vectors')
    p.add_argument('snapshots', type=Path, nargs='+')
    args = p.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + CALL + ASM[end:]
    asm = asm.replace('mov edx, 36', 'mov edx, 12').replace('cmp eax, 36', 'cmp eax, 12')
    asm = asm.replace('stack: .skip', 'object: .skip 8272\n.align 16\nstack: .skip')
    states = []
    for path in args.snapshots:
        data = path.read_bytes()
        mask, = struct.unpack_from('<I', data)
        assert mask < (1 << 20)
        states.append(dict(path=str(path), data=data, mask=mask, cursor=4, players=[]))
    vectors = {}
    for slot in range(20):
        pending = []
        for state in states:
            if not state['mask'] & (1 << slot):
                continue
            data = state['data']
            player = dict(slot=slot, state=block(data, state['cursor']), animation=None)
            state['players'].append(player)
            cursor = player['state'][1]
            flag = data[cursor]
            state['cursor'] = cursor + 1
            if flag:
                pending.append(state)
        if not pending:
            continue
        windows = [s['data'][s['cursor']:s['cursor'] + 512] for s in pending]
        output = run_oracle(args.exe, args.work, asm, windows, output_size=12)
        for index, state in enumerate(pending):
            consumed, times, floats = struct.unpack_from('<III', output, index * 12)
            assert 0 < consumed <= len(windows[index]) <= 512
            start = state['cursor']
            state['cursor'] += consumed
            state['players'][-1]['animation'] = [start, state['cursor']]
            data = windows[index][:consumed]
            vectors[data.hex()] = dict(consumed=consumed, times=times, floats=floats)
    for state in states:
        state['blocks'] = []
        for _ in range(6):
            bounds = block(state['data'], state['cursor'])
            state['blocks'].append(bounds)
            state['cursor'] = bounds[1]
        assert state['cursor'] == len(state['data']), state['path']
        del state['data']
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(dict(exe_sha256=SHA256, decoder='0x3a9900',
                                         states=states, animations=vectors), indent=2) + '\n')
    if args.tsv:
        args.tsv.parent.mkdir(parents=True, exist_ok=True)
        args.tsv.write_text('# Native decoder 0x3a9900; SHA256 ' + SHA256 + '\n'
            '# animation bytes\tconsumed bytes\ttimes\tfloats\n' + ''.join(
                f'{data}\t{v["consumed"]}\t{v["times"]}\t{v["floats"]}\n'
                for data, v in sorted(vectors.items())))
    print(f'{len(states)} snapshots consumed exactly; {len(vectors)} distinct native animation vectors')


if __name__ == '__main__':
    main()
