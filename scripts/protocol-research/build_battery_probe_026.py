#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Build an isolated 0.26g0 native battery-completion diagnostic.

Invokes ten synthetic native deposit events after 30 seconds. Use only with
a private test server. This does not establish physical battery delivery.
Requires a GCC-compatible compiler with x86 code generation, and GNU binutils.
"""
import argparse
import importlib.util
import json
import re
import subprocess
from pathlib import Path

SAVE_PROBE = r"""
.intel_syntax noprefix
.text
.global battery_probe_save
battery_probe_save:
    pushfd
    pushad
    push dword ptr [esp+40]
    call battery_probe
    add esp, 4
    popad
    popfd
    push ecx
    push ebx
    push ebp
    mov ebp, [esp+16]
    jmp 0x2d2577
"""


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
        str(Path(__file__).with_name('native_battery_probe_026.c')), '-o', str(compiled)], check=True)
    assembly = compiled.read_text().replace('.L', '.Lbattery')
    # The appended PE section is RX; the probe uses stack locals only. Fold its
    # string/number constants into .text, and reject compiler-added writable data.
    if re.search(r'^\s*\.(?:data|bss)(?:\s|$)', assembly, re.M):
        raise ValueError('Probe unexpectedly requires writable static storage')
    assembly = re.sub(r'^\s*\.section\s+\.rodata[^\n]*', '\n.text', assembly, flags=re.M)
    for section in re.findall(r'^\s*\.section\s+([^\n]+)', assembly, re.M):
        if not section.startswith('.note.GNU-stack'):
            raise ValueError(f'Unexpected probe section: {section}')
    combined = args.work / 'combined.S'
    original = source.with_name('direct_match.S').read_text()
    combined.write_text(original + SAVE_PROBE + '\n.att_syntax prefix\n' + assembly + '\n.intel_syntax noprefix\n')
    data, manifest = patcher.patch(args.exe.read_bytes(), True, True,
        assembly_file=combined, results=True, cc=args.cc,
        extra_hooks=[('battery_probe_save', 0x2d2570, '5153558b6c2410')])
    manifest['purpose'] = 'Diagnostic only: ten synthetic native battery events, not physical delivery'
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)
    (args.work / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(manifest['output_sha256'], args.output)


if __name__ == '__main__':
    main()
