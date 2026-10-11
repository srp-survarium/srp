#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Explicitly admit local test slots to the front door's next empty match.

This is a local operator action, not native Play UI or automatic requeue.
No session token or account password is accepted or printed.
"""
import argparse
from pathlib import Path
import secrets
import socket
import tempfile


def request(path, command):
    nonce = secrets.randbits(64)
    with tempfile.TemporaryDirectory(prefix='srp-021d-queue-') as directory:
        with socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM) as sock:
            sock.bind(str(Path(directory) / 'reply'))
            sock.settimeout(2)
            sock.connect(str(path))
            sock.send(command(nonce).encode('ascii'))
            fields = sock.recv(512).decode('ascii').split()
    if fields[:2] != ['v1', str(nonce)]:
        raise ValueError('invalid control response')
    if fields[2:3] == ['error']:
        raise ValueError('control rejected: ' + ' '.join(fields[3:]))
    return fields[2:]


def queue(path, slots):
    status = request(path, lambda nonce: f'status {nonce}')
    if len(status) != 4 or status[2:] != ['waiting', '0']:
        raise ValueError('match is not empty and waiting')
    instance, generation = status[:2]
    if (not 0 < len(instance) <= 32 or any(c not in '0123456789abcdef' for c in instance)
            or not 0 < int(generation) < 2**64):
        raise ValueError('invalid match identity')
    if not slots or len(set(slots)) != len(slots) or any(not 0 <= n < 20 for n in slots):
        raise ValueError('slots must be unique integers from 0 to 19')
    result = request(path, lambda nonce:
                     f'queue {nonce} {instance} {generation} ' + ','.join(map(str, slots)))
    if result != ['queued', instance, generation]:
        raise ValueError('invalid admission response')
    return instance, int(generation)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--control', required=True, type=Path)
    parser.add_argument('--slots', required=True, nargs='+', type=int)
    args = parser.parse_args()
    try:
        instance, generation = queue(args.control, args.slots)
    except (OSError, ValueError) as error:
        parser.exit(1, f'{error}\n')
    print(f'Queued slots {args.slots} for instance {instance}, generation {generation}')
