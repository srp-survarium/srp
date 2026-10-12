#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Reproduce the 0.26g0 timer table from an extracted gameplay config tree.

Uses binary-config-cli's indented dump. Missing configs and modes without a
leading time-limit rule are recorded in JSON but excluded from the timer TSV.
The table describes configuration, not proof that a map can load successfully.
"""
import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path


def decode(cli, path):
    text = subprocess.check_output(
        [str(cli), 'print-binary-config', '--input', str(path)], text=True)
    # The printer's root label can contain a control character; only child
    # indentation and scalar syntax are relevant here.
    root, stack = {}, [(-1, {})]
    stack[0] = (-1, root)
    for line in text.splitlines():
        indent = len(line) - len(line.lstrip(' '))
        if indent == 0 or not line.strip():
            continue
        while stack[-1][0] >= indent:
            stack.pop()
        parent = stack[-1][1]
        group = re.fullmatch(r'\s*([^\[\]]+)\[\d+\]', line)
        if group:
            key = group[1]
            if key in parent:
                raise ValueError(f'duplicate key {key!r} in {path}')
            parent[key] = {}
            stack.append((indent, parent[key]))
        else:
            key, separator, value = line.strip().partition(': ')
            if not separator or key in parent:
                raise ValueError(f'unexpected config line {line!r} in {path}')
            parent[key] = json.loads(value)
    return root


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--gameplay', type=Path, required=True)
    parser.add_argument('--cli', type=Path, required=True)
    parser.add_argument('--json', type=Path, required=True)
    parser.add_argument('--tsv', type=Path, required=True)
    parser.add_argument('--results-tsv', type=Path,
                        help='Also emit battery-mode metadata for the results reader')
    args = parser.parse_args()
    maps = decode(args.cli, args.gameplay / 'db_static_dictionaries')['maps_dict']
    rows, timers, result_modes, seen = [], [], [], set()
    for entry in sorted(maps.values(), key=lambda entry: entry['id']):
        ident, name = entry['id'], entry['cfg_mode_name']
        if not isinstance(ident, int) or not 0 <= ident <= 255 or ident in seen:
            raise ValueError(f'invalid or duplicate map id: {ident}')
        seen.add(ident)
        relative = Path(name)
        if relative.is_absolute() or '..' in relative.parts or any(c in name for c in '\t\r\n'):
            raise ValueError(f'invalid map config path: {name!r}')
        path = args.gameplay / 'game_modes' / relative
        row = dict(id=ident, name=name)
        rows.append(row)
        if not path.is_file():
            row['missing'] = True
            continue
        row['sha256'] = hashlib.sha256(path.read_bytes()).hexdigest()
        mode = decode(args.cli, path)['mode']
        params = mode.get('parameters', {})
        for key in ['match_time', 'wait_time', 'countdown_time']:
            row[key] = params.get(key)
        rules = mode.get('rules', {})
        row['rules'] = [rules[key] for key in sorted(rules, key=int)]
        if mode.get('mode') == 2 and 88 in row['rules']:
            items = params.get('victory_items_count')
            if type(items) is not int or not 1 <= items <= 10:
                raise ValueError(f'invalid battery count in {name}: {items}')
            result_modes.append(f'{ident}\t2\t{items}\t{name}\t{row["sha256"]}')
        if not row['rules'] or row['rules'][0] != 93:
            continue
        values = [row[key] for key in ['match_time', 'wait_time', 'countdown_time']]
        if any(type(value) is not int or value <= 0 for value in values):
            raise ValueError(f'invalid timer parameters: {row}')
        if values[0] * 1000 > 0xffffffff or values[1] * 60000 > 0xffffffff:
            raise ValueError(f'timer overflows native milliseconds: {row}')
        timers.append('\t'.join(map(str, [ident, *values, name, row['sha256']])))
    args.json.parent.mkdir(parents=True, exist_ok=True)
    args.tsv.parent.mkdir(parents=True, exist_ok=True)
    args.json.write_text(json.dumps(rows, indent=2) + '\n')
    args.tsv.write_text(
        '# 0.26g0 local gameplay configs; generated from mode-timers.json evidence.\n'
        '# id\tmatch_seconds\twait_minutes\tcountdown_seconds\tname\tconfig_sha256\n'
        + '\n'.join(timers) + '\n')
    print(f'{len(rows)} map entries, {len(timers)} leading time-limit rules, '
          f'{sum(row.get("missing", False) for row in rows)} missing configs')
    if args.results_tsv:
        args.results_tsv.parent.mkdir(parents=True, exist_ok=True)
        args.results_tsv.write_text('# map\tmode\tvictory_items\tconfig\tsha256\n'
                                   + '\n'.join(result_modes) + '\n')


if __name__ == '__main__':
    main()
