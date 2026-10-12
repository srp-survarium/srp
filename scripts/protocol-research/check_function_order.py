#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Measure source-line/address ordering in vostok-pdb evidence databases.

Source file is a TU proxy, not raw compiland ownership. Ignore headers, duplicate
line starts and folded address aliases. This tests an ordering heuristic; it does
not recover compiler flags or guarantee ordering in an unexamined executable.
"""
import argparse
import bisect
import collections
import json
import sqlite3
from pathlib import Path


def metrics(values):
    tails = []
    inversions = 0
    seen = []
    for v in values:
        p = bisect.bisect_left(tails, v)
        if p == len(tails):
            tails.append(v)
        else:
            tails[p] = v
        inversions += len(seen) - bisect.bisect_right(seen, v)
        bisect.insort(seen, v)
    pairs = len(values) * (len(values) - 1) // 2
    return dict(functions=len(values), inversions=inversions, pairs=pairs,
                inversion_rate=inversions / pairs if pairs else 0,
                increasing_subsequence=len(tails),
                forward_neighbors=sum(a < b for a, b in zip(values, values[1:])))


def read_database(path):
    db = sqlite3.connect(path.resolve().as_uri() + '?mode=ro', uri=True)
    meta = dict(db.execute('select * from metadata'))
    groups = collections.defaultdict(list)
    owners = collections.defaultdict(set)
    for file, va in db.execute('select file,rva+image_base from functions'):
        owners[va].add(file)
    # Include header/unknown/ambiguous functions as intervening addresses, so
    # filtering to .cpp files cannot make their clustering look artificially good.
    physical = sorted(owners)
    ranks = {va: i for i, va in enumerate(physical)}
    file_positions = collections.defaultdict(list)
    for va in physical:
        if len(owners[va]) == 1:
            file_positions[next(iter(owners[va]))].append(ranks[va])
    rows = db.execute('select f.name,f.mangled,f.file,f.rva+f.image_base,p.statements_json '
                      'from functions f join function_payloads p on f.id=p.function_id')
    for name, mangled, file, va, raw in rows:
        if not file.lower().endswith(('.cpp', '.c', '.cc')):
            continue
        statements = json.loads(raw)
        lines = [s['line'] for s in statements if s.get('file') == file and s.get('line', 0) > 0]
        if lines:
            groups[file].append(dict(name=name, mangled=mangled, line=min(lines), va=va))
    result = {}
    for file, funcs in groups.items():
        lines = collections.Counter(f['line'] for f in funcs)
        addresses = collections.Counter(f['va'] for f in funcs)
        unique = [f for f in funcs if lines[f['line']] == 1 and addresses[f['va']] == 1]
        if len(unique) >= 4:
            ordered = sorted(unique, key=lambda f: f['line'])
            positions = file_positions[file]
            runs = []
            for position in positions:
                if runs and position == runs[-1][-1] + 1:
                    runs[-1].append(position)
                else:
                    runs.append([position])
            span = positions[-1] - positions[0] + 1 if positions else 0
            layout = dict(unambiguous_functions=len(positions), runs=len(runs),
                          longest_run=max(map(len, runs), default=0),
                          address_span_functions=span,
                          span_purity=len(positions) / span if span else 0,
                          runs_va=[[hex(physical[r[0]]), hex(physical[r[-1]]), len(r)] for r in runs])
            result[file] = dict(**metrics([f['va'] for f in ordered]),
                                layout=layout, source_order=ordered)
    return dict(metadata=meta, files=result)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('database', nargs='+', type=Path)
    p.add_argument('--output', required=True, type=Path)
    args = p.parse_args()
    result = {str(path): read_database(path) for path in args.database}
    for path, data in result.items():
        files = data['files']
        print(path, 'eligible files:', len(files), 'fully source ordered:',
              sum(f['inversions'] == 0 for f in files.values()))
        for file, f in files.items():
            if any(t in file for t in ('network_client_handler.cpp', 'udp_match_connection.cpp',
                                       'game_world_core.cpp', 'player_input.cpp')):
                print(file, {k: v for k, v in f.items() if k not in ('source_order', 'layout')})
                print('layout:', {k: v for k, v in f['layout'].items() if k != 'runs_va'})
                print('first by line:', [(x['line'], hex(x['va']), x['name']) for x in f['source_order'][:5]])
        data['summary'] = dict(files=len(files), fully_source_ordered=sum(f['inversions'] == 0 for f in files.values()))
    # Across-build test: keep source-file and unique decorated identities shared
    # by the first and each later database; compare their relative VA orders.
    comparisons = []
    baseline = result[str(args.database[0])]
    for other_path in args.database[1:]:
        other = result[str(other_path)]
        files = {}
        for file in baseline['files'].keys() & other['files'].keys():
            a = baseline['files'][file]['source_order']
            b = other['files'][file]['source_order']
            ac = collections.Counter(x['mangled'] for x in a)
            bc = collections.Counter(x['mangled'] for x in b)
            by_name = {x['mangled']: x for x in b if x['mangled'] and bc[x['mangled']] == 1}
            shared = [x for x in sorted(a,key=lambda x:x['va']) if x['mangled'] in by_name and ac[x['mangled']] == 1]
            if len(shared) >= 4:
                files[file] = metrics([by_name[x['mangled']]['va'] for x in shared])
        comparisons.append(dict(base=str(args.database[0]), other=str(other_path), files=files))
        print('shared function address ordering vs', other_path)
        for file, f in files.items():
            if 'network_client' in file or 'udp_match_connection' in file:
                print(file, f)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(dict(databases=result, comparisons=comparisons),indent=2)+'\n')


if __name__ == '__main__':
    main()
