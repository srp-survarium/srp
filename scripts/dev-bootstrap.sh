#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Linux dev bootstrapper — the counterpart to survarium-dev-bootstrap.bat.
#
# Launches the mock servers in a tmux session, one window each:
#   * srp      — the unified binary (login + browser + lobby + match, one process)
#   * login / lobby / browser / match — `tail -F` of that server's log file, so
#     logs stay separable even though the servers share the `srp` process.
#
# Run it from inside the dev shell (so cargo + tmux are on PATH):
#   nix develop
#   ./scripts/dev-bootstrap.sh
#
# Point the game client at the login server, e.g.:
#   survarium.exe -no_splash_screen -client=<host>:1234
#
set -euo pipefail

# Repo root = parent of this script's directory.
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

SESSION="srp"

for tool in cargo tmux; do
  if ! command -v "$tool" >/dev/null 2>&1; then
    echo "error: '$tool' not found — run this from inside 'nix develop'." >&2
    exit 1
  fi
done

# The srp binary creates logs/ itself, but make it up front so the `tail -F`
# windows have something to watch immediately.
mkdir -p logs

# Start fresh.
tmux kill-session -t "$SESSION" 2>/dev/null || true

tmux new-session -d -s "$SESSION" -n srp     -c "$ROOT" 'cargo run --bin srp'
tmux new-window  -t "$SESSION"    -n login   -c "$ROOT" 'tail -F logs/login.log'
tmux new-window  -t "$SESSION"    -n lobby   -c "$ROOT" 'tail -F logs/lobby.log'
tmux new-window  -t "$SESSION"    -n browser -c "$ROOT" 'tail -F logs/browser.log'
tmux new-window  -t "$SESSION"    -n match   -c "$ROOT" 'tail -F logs/match.log'

tmux select-window -t "$SESSION:srp"
tmux attach-session -t "$SESSION"
