#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build an isolated 0.26g0 native results UI probe with a labeled test row.

This is not live results delivery. The normal client builder is unchanged.
Requires a GCC-compatible compiler with x86 code generation, and GNU binutils.
"""
import argparse
import importlib.util
import json
import re
import subprocess
from pathlib import Path

WRAPPER = r'''
.intel_syntax noprefix
.text
.global results_probe_jump
results_probe_jump:
    push esi
    mov esi, ecx
    call 0x29aaf0
    mov ecx, esi
    push 0
    call 0x29eda0
    mov edx, esi
    xor eax, eax
    call 0x2203a0
    push esi
    call results_probe
    add esp, 4
    pop esi
    jmp 0x27a81f
.att_syntax prefix
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--exe', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--work', type=Path, required=True)
    parser.add_argument('--cc', default='cc')
    args = parser.parse_args()
    if args.exe.resolve() == args.output.resolve() or args.output.exists():
        parser.error('Use a new output filename and retain the retail executable')
    root = Path(__file__).resolve().parents[2]
    source = root / 'client/026g/tools/patch_exe.py'
    spec = importlib.util.spec_from_file_location('patch_026', source)
    patcher = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(patcher)
    args.work.mkdir(parents=True, exist_ok=True)
    compiled = args.work / 'probe.s'
    subprocess.run([args.cc, '-m32', '-march=i686', '-mfpmath=387', '-Os',
        '-ffreestanding', '-fno-pic', '-fno-pie', '-fno-stack-protector',
        '-fno-asynchronous-unwind-tables', '-S',
        str(Path(__file__).with_name('native_results_probe_026.c')), '-o', str(compiled)], check=True)
    assembly = compiled.read_text()
    # The appended PE section is RX; the probe uses stack locals only. Fold its
    # string/number constants into .text, and reject compiler-added writable data.
    if re.search(r'^\s*\.(?:data|bss)(?:\s|$)', assembly, re.M):
        raise ValueError('Probe unexpectedly requires writable static storage')
    assembly = re.sub(r'^\s*\.section\s+\.rodata[^\n]*', '\n.text', assembly, flags=re.M)
    for section in re.findall(r'^\s*\.section\s+([^\n]+)', assembly, re.M):
        if not section.startswith('.note.GNU-stack'):
            raise ValueError(f'Unexpected probe section: {section}')
    combined = args.work / 'combined.S'
    combined.write_text(source.with_name('direct_match.S').read_text() + WRAPPER + assembly)
    data, manifest = patcher.patch(args.exe.read_bytes(), True, True,
        assembly_file=combined,
        extra_hooks=[('results_probe_jump', 0x27a81a, 'e8d1020200')])
    manifest['purpose'] = 'Native UI diagnostic; labeled test data, not live match results'
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    (args.work / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(manifest['output_sha256'], args.output)


if __name__ == '__main__':
    main()
