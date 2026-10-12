#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise real 0.26 clients on explicitly selected, isolated X displays.

Waits for the server's initial state barrier, then alternates movement keys.
Use with separate Xvfb/Wine desktops and --restore-once-after-ms 25000:
the opening countdown suppresses input until roughly 20500 ms.
This sends real input; use dedicated test displays and Wine prefixes.
"""
import argparse
import os
from pathlib import Path
import subprocess
import time


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--display', action='append', required=True)
    parser.add_argument('--server-log', type=Path, required=True)
    parser.add_argument('--xdotool', default='xdotool')
    parser.add_argument('--duration', type=float, default=40)
    parser.add_argument('--timeout', type=float, default=70)
    args = parser.parse_args()
    if args.duration <= 0 or args.timeout <= 0:
        parser.error('duration and timeout must be positive')
    deadline = time.monotonic() + args.timeout
    while time.monotonic() < deadline:
        if (args.server_log.exists()
                and 'All startup states acknowledged' in args.server_log.read_text()):
            break
        time.sleep(.1)
    else:
        raise SystemExit('Initial state barrier was not reached')

    peers = []
    try:
        for display in args.display:
            env = dict(os.environ, DISPLAY=display)
            result = subprocess.run(
                [args.xdotool, 'search', '--name', '^Survarium v0.26g'],
                env=env, text=True, capture_output=True)
            windows = result.stdout.splitlines()
            if result.returncode != 0 and not windows:
                raise SystemExit(f'{display}: no live 0.26 window; check the client timeout')
            if len(windows) != 1:
                raise RuntimeError(f'{display}: expected exactly one 0.26 test window')
            peers.append(env)
            subprocess.run([args.xdotool, 'windowfocus', windows[0]], env=env, check=True)
        print(f'Cycling movement for {args.duration:g} seconds on {args.display}', flush=True)
        end = time.monotonic() + args.duration
        step = 0
        while time.monotonic() < end:
            old, key = ('d', 'a') if step % 2 else ('a', 'd')
            for env in peers:
                subprocess.run([args.xdotool, 'keyup', old, 'keydown', key],
                               env=env, check=True)
            step += 1
            time.sleep(.25)
    finally:
        for env in peers:
            subprocess.run([args.xdotool, 'keyup', 'a', 'keyup', 'd'], env=env, check=False)
    print('Movement released; leave clients running to collect settled hashes', flush=True)


if __name__ == '__main__':
    main()
