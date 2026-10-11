#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise retail 0.26g0 lobby framing using its own metadata vtable methods.

Native lobby uses the same UDP envelope/frame parser as matches. Both metadata
slots point to 0x26e370; length getter 0x26e390 marks every application message
variable. Skip 86/A7: their jump-table entries have no valid metadata target.
"""
import argparse
import struct
from pathlib import Path
from retail_header_oracle import ASM, SHA256, run_oracle
from retail_frame_oracle import FRAME_CALL


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--tsv', type=Path, required=True)
    args = p.parse_args()
    call = FRAME_CALL.replace('0xd8', '0x2e').replace('0xf6', '0xaa')
    call = call.replace('0x279670', '0x26e390').replace('0x279650', '0x26e370').replace('0x279630', '0x26e370')
    # Ordered messages store their wire delivery byte in frame+20; ordinary
    # reliable messages use frame+19. Match-only fixtures did not exercise this.
    call = call.replace('    movzx eax, byte ptr [frame+19]', '''    movzx eax, byte ptr [frame+19]
    test byte ptr [frame+18], 0x40
    jz delivery_byte_ready
    movzx eax, byte ptr [frame+20]
delivery_byte_ready:''')
    start = ASM.index('    push offset result+16')
    end = ASM.index('    push 0x33', start)
    asm = ASM[:start] + call + ASM[end:]
    asm = asm.replace('stack: .skip', 'vector: .skip 12\nframe: .skip 28\ngetter: .skip 12\nvtable: .skip 12\n.align 16\nstack: .skip')
    unique_ids = (set(range(0x2e,0x51)) | set(range(0x80,0xab))) - {0x86,0x9f,0xa7}
    cases = []
    for opcode in [*range(0x2e,0x51), *range(0x80,0xab)]:
        if opcode in (0x86,0xa7): continue
        for single in (False,True):
            for body in (b'\x01\x02\x03\x04',):
                prefix = bytes([opcode,73]) if opcode in unique_ids else bytes([opcode])
                cases.append(bytes([single,opcode>=0x80,20])+prefix+(b'' if single else bytes([len(body)]))+body)
    for opcode in (0x87,0xa1):
        for single in (False,True):
            for part in (0,1):
                prefix = bytes([0xff,opcode])+ (bytes([73]) if opcode in unique_ids else b'')
                prefix += bytes([part]+([2] if part==0 else []))
                cases.append(bytes([single,1,20])+prefix+(b'' if single else b'\xff\x00\x01')+bytes(range(256)))
    output = run_oracle(args.exe,args.work,asm,cases)
    rows=[]
    for i,case in enumerate(cases):
        ok,consumed,size,opcode,unique,part,count,flags,metadata=struct.unpack_from('<9I',output,i*36)
        assert ok==1 and consumed==len(case)-3,(i,case.hex(),ok,consumed)
        rows.append('\t'.join(map(str,[case[3:].hex(),case[0],case[1],case[2],size,opcode,unique,part,count,flags,metadata])))
    args.tsv.parent.mkdir(parents=True,exist_ok=True)
    args.tsv.write_text('# Retail lobby parser 0x3fa240, metadata 0x26e370/0x26e390; SHA256 '+SHA256+'\n'
        '# frame\tsingle\tserver\tplayers\tbody_bytes\tid\tunique\tpart\tcount\tflags\tmetadata\n'+'\n'.join(rows)+'\n')
    print(f'{len(rows)} lobby frames accepted by the retail parser')


if __name__=='__main__': main()
