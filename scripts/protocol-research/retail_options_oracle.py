#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise 0.26g0's complete match-options reader with equipment and inventory.

The original dictionary lookup reads a local two-entry dictionary (weapon 3,
stackable ammunition 7). Original code is unmodified. All 20 player slots are
read. Checks use the resulting object, not a second wire-format decoder.
"""
import argparse
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle

SIZE = 0x57840
CALL = r'''
    mov edi, offset result
    xor eax, eax
    mov ecx, 89617
    rep stosd
    mov dword ptr [dictionary+0x130], offset dictionary_entries
    mov dword ptr [dictionary+0x134], 2
    mov word ptr [dictionary_entries], 3
    mov word ptr [dictionary_entries+0x3a0], 7
    mov byte ptr [dictionary_entries+0x3a0+0x22a], 1
    mov ebx, offset result+4
    mov edx, 20
init_player:
    lea edi, [ebx+0x1568]
    mov ecx, 69
init_item:
    lea eax, [edi+0x20]
    mov [edi+0x14], eax
    mov [edi+0x18], eax
    add eax, 64
    mov [edi+0x1c], eax
    lea eax, [edi+0x6c]
    mov [edi+0x60], eax
    mov [edi+0x64], eax
    add eax, 72
    mov [edi+0x68], eax
    add edi, 0xb4
    dec ecx
    jnz init_item
    add ebx, 0x45fc
    dec edx
    jnz init_player
    push offset dictionary
    push offset result+4
    mov eax, offset reader
    mov edx, 0x1f0e70
    call edx
    mov eax, [reader+4]
    sub eax, offset record+4
    mov [result], eax
'''


def u32(value): return struct.pack('<I', value)
def string(value): return bytes([len(value)]) + value


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + CALL + ASM[end:]
    asm = asm.replace('mov edx, 36', f'mov edx, {SIZE+4}').replace('cmp eax, 36', f'cmp eax, {SIZE+4}')
    asm = asm.replace('result: .skip 36', f'result: .skip {SIZE+4}')
    asm = asm.replace('stack: .skip', 'dictionary: .skip 312\ndictionary_entries: .skip 1856\n.align 16\nstack: .skip')
    # A non-stackable weapon, a stackable ammunition item, present slots 7/8,
    # modifiers straddling the 64-bit boundary, and both extension vector types.
    body = bytes([1]) + string(b'Tester') + string(b'SRP') + u32(123456)
    body += bytes([1, 2]) # one profile, two inventory elements
    body += bytes([2]) + u32(777) + string(b'Loadout')
    body += u32((1 << 7) | (1 << 8)) + struct.pack('<4H', 0, 1, 1, 120)
    mask = (1 << 0) | (1 << 63) | (1 << 67)
    body += struct.pack('<QQ', mask >> 64, mask & ((1 << 64)-1))
    body += struct.pack('<3f', 1.25, 2.5, 3.75)
    body += u32(1001) + struct.pack('<H', 3) + struct.pack('<3I', 10000, 17, 19)
    body += bytes([1]) + u32(33) + bytes([1])
    body += bytes([1]) + struct.pack('<IIQB', 44, 55, 0x123456789abc, 3)
    body += u32(1002) + struct.pack('<H', 7) + u32(120) + bytes([0, 0])
    body += (bytes([255, 0, 0]) + u32(0) + bytes([0, 0])) * 19
    body += bytes([61, 1]) + u32(1234) + struct.pack('<H', 10)
    body += struct.pack('<28f', *[i + 0.5 for i in range(28)]) + bytes(range(20))
    output = run_oracle(args.exe, args.work, asm, [body], output_size=SIZE+4, map_data=True)
    assert struct.unpack_from('<I', output)[0] == len(body)
    obj = output[4:]
    assert obj[8:15] == b'Tester\0'
    assert obj[0x48:0x4c] == b'SRP\0'
    assert struct.unpack_from('<I', obj, 0x45ec)[0] == 1
    assert struct.unpack_from('<I', obj, 0x45f4)[0] == 123456
    assert obj[0x57] == 1 and obj[0x1564] == 2
    assert obj[0x58:0x60] == b'Loadout\0'
    assert struct.unpack_from('<I', obj, 0x754)[0] == 777 and obj[0x758] == 2
    assert struct.unpack_from('<4H', obj, 0x98+7*4) == (0, 1, 1, 120)
    for index, value in [(0,1.25),(63,2.5),(67,3.75)]:
        assert struct.unpack_from('<f', obj, 0xf4+4*index)[0] == value
    assert struct.unpack_from('<I', obj, 0x1568)[0] == 1001
    assert struct.unpack_from('<H', obj, 0x156c)[0] == 3
    assert struct.unpack_from('<3I', obj, 0x1570) == (10000,17,19)
    assert struct.unpack_from('<I', obj, 0x1588)[0] == 33 and obj[0x158c] == 1
    assert struct.unpack_from('<IIQB', obj, 0x15d4) == (44,55,0x123456789abc,3)
    assert struct.unpack_from('<I', obj, 0x1568+0xb4+8)[0] == 120
    assert obj[0x577b4:0x577b6] == bytes([61,1])
    assert struct.unpack_from('<I', obj, 0x577b0)[0] == 1234
    assert struct.unpack_from('<H', obj, 0x577b6)[0] == 10
    assert struct.unpack_from('<28f', obj, 0x577bc) == tuple(i+0.5 for i in range(28))
    assert obj[0x5782c:0x57840] == bytes(range(20))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text('# Retail match-options reader 0x1f0e70; SHA256 ' + SHA256 + '\n' + body.hex() + '\n')
    print(f'{len(body)}-byte roster/equipment stream consumed and all selected fields verified by retail reader')


if __name__ == '__main__': main()
