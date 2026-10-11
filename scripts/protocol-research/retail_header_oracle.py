#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Run 0.26g0's original UDP header parser as a freestanding Linux x86-64 ELF.

Requires GNU as/ld and Linux x86-64 compatibility-mode support. Only the hash-checked
retail .text section is mapped, at its original VA. The game entry point, DLL
imports and networking are never called. Generated executables stay in --work.
Produces deterministic test vectors from the actual retail parser, not from a
second implementation of the codec. Do not use this harness for malformed
inputs: the original parser reads past the end before rejecting some packets.
"""
import argparse
import hashlib
import json
import random
import struct
import subprocess
from pathlib import Path
from function_candidates import Image

SHA256 = 'ac33d9937015c2299bf62cc6b127cb308b48a3475b30fff2ddd65479ae3bf153'

ASM = r'''
.intel_syntax noprefix
.section .retail,"ax"
.incbin "retail-text.bin"
.section .text
.global _start
.code64
_start:
    mov rsp, offset stack_end
    xor ebp, ebp
read_record:
    xor eax, eax
    xor edi, edi
    lea esi, [record + rbp]
    mov edx, 516
    sub edx, ebp
    syscall
    test eax, eax
    jz finished
    js failed
    add ebp, eax
    cmp ebp, 516
    jb read_record
    mov eax, [record]
    cmp eax, 512
    ja failed
    cmp eax, 3
    jb failed
    mov [reader+8], eax
    mov dword ptr [reader], offset record+4
    mov dword ptr [reader+4], offset record+4
    mov edi, offset result
    xor eax, eax
    mov ecx, 9
    rep stosd
    push 0x23
    push offset parse32
    retfq
.code32
parse32:
    mov ax, 0x2b
    mov ds, ax
    mov es, ax
    push offset result+16
    push offset result+12
    push offset result+8
    push offset reader
    mov edx, offset result+4
    mov edi, offset result+20
    mov eax, 0x3fa0a0
    call eax
    add esp, 16
    mov [result], al
    push 0x33
    push offset write64
    retf
.code64
write64:
    mov eax, 1
    mov edi, 1
    mov esi, offset result
    mov edx, 36
    syscall
    cmp eax, 36
    jne failed
    xor ebp, ebp
    jmp read_record
finished:
    test ebp, ebp
    jnz failed
    mov eax, 60
    xor edi, edi
    syscall
failed:
    mov eax, 60
    mov edi, 1
    syscall
.section .bss
.align 16
record: .skip 516
reader: .skip 12
result: .skip 36
.align 16
stack: .skip 131072
stack_end:
.section .note.GNU-stack,"",@progbits
'''


def run_oracle(exe, work, assembly, packets, *, output_size=36, map_data=False):
    image = Image(exe)
    if hashlib.sha256(image.data).hexdigest() != SHA256:
        raise ValueError('expected unmodified retail 0.26g0 build 2777')
    work.mkdir(parents=True, exist_ok=True)
    section = next(s for s in image.sections if s[0] == '.text')
    assert section[1] == 0x11000
    (work / 'retail-text.bin').write_bytes(image.read(section[1], section[2]))
    extra_layout = ''
    if map_data:
        for i, (name, va, size, offset, flags) in enumerate(image.sections):
            if name not in ('.rdata', '.data'):
                continue
            (work / f'section-{i}.bin').write_bytes(image.data[offset:offset+size])
            attrs = 'aw' if flags & 0x80000000 else 'a'
            assembly += f'\n.section .retail{i},"{attrs}"\n.incbin "section-{i}.bin"\n'
            extra_layout += f' . = {va}; .retail{i} : {{ *(.retail{i}) }}\n'
            rest = max(0, image.virtual_sizes[va] - size)
            if rest:
                assembly += f'\n.section .retailbss{i},"aw",@nobits\n.skip {rest}\n'
                extra_layout += f' .retailbss{i} (NOLOAD) : {{ *(.retailbss{i}) }}\n'
    (work / 'oracle.s').write_text(assembly)
    (work / 'oracle.ld').write_text('ENTRY(_start)\nSECTIONS {\n'
        ' . = 0x11000; .retail : { *(.retail) }\n'
        + extra_layout + ' . = 0x20000000; .text : { *(.text) }\n'
        ' . = 0x21000000; .bss : { *(.bss) }\n}\n')
    subprocess.run(['as', '--64', '-o', 'oracle.o', 'oracle.s'], cwd=work, check=True)
    subprocess.run(['ld', '-m', 'elf_x86_64', '-T', 'oracle.ld', '-o', 'oracle', 'oracle.o'],
                   cwd=work, check=True)
    assert all(3 <= len(p) <= 512 for p in packets)
    raw = b''.join(struct.pack('<I', len(p)) + p.ljust(512, b'\0') for p in packets)
    process = subprocess.run([str((work / 'oracle').resolve())], input=raw,
                             stdout=subprocess.PIPE, check=True)
    assert len(process.stdout) == len(packets) * output_size
    return process.stdout


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--exe', type=Path, required=True)
    p.add_argument('--work', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--tsv', type=Path, help='also write the Rust test fixture')
    args = p.parse_args()
    rng = random.Random(2777)
    packets = []
    # Every short control byte, then each legal extension count and bit position.
    for control in range(128):
        packets.append(bytes([0x17, 0x29, control, 0xfe]))
    for count in range(1, 19):
        for sample in range(16):
            control = [rng.randrange(128) | 128 for _ in range(count)]
            control.append(rng.randrange(128))
            if count == 18:
                # At most 128 ack bits: the last control byte is just the flag.
                control[-1] &= 1
            packets.append(bytes([rng.randrange(256), rng.randrange(256), control[0],
                                  0xfe, *reversed(control[1:])]))
    output = run_oracle(args.exe, args.work, ASM, packets)
    vectors = []
    for i, packet in enumerate(packets):
        ok, seq, ack, bits, single, hi, lo = struct.unpack_from('<IIIIIQQ', output, i * 36)
        assert ok == 1
        vectors.append(dict(packet=packet.hex(), sequence=seq, ack_sequence=ack,
                            ack_bits=bits, single=bool(single), ack_mask=f'{hi:016x}{lo:016x}'))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(dict(exe_sha256=SHA256, parser_va='0x3fa0a0',
                                         vectors=vectors), indent=2) + '\n')
    if args.tsv:
        args.tsv.parent.mkdir(parents=True, exist_ok=True)
        args.tsv.write_text('# Retail 0.26g0 parser 0x3fa0a0; SHA256 ' + SHA256 + '\n'
            '# packet\tsequence\tack_sequence\tack_bits\tsingle\tack_mask\n' + ''.join(
                '\t'.join(map(str, [v['packet'], v['sequence'], v['ack_sequence'],
                                   v['ack_bits'], int(v['single']), v['ack_mask']])) + '\n'
                for v in vectors))
    print(f'{len(vectors)} vectors generated by the retail header parser')


if __name__ == '__main__':
    main()
