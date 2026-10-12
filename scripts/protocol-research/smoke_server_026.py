#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise the 0.26 endpoint over UDP with two synthetic peers, not game clients."""
import argparse
import json
import lzma
import re
import socket
import struct
import subprocess
import time


class Peer:
    def __init__(self, endpoint):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.socket.bind(('127.0.0.1', 0))
        self.socket.connect(endpoint)
        self.socket.settimeout(2)
        self.sequence = 0
        self.ack = 0

    def send(self, opcode, body=b'', ack=None):
        # A seven-position ack horizon with only its implicit newest bit set.
        self.socket.send(bytes([self.sequence, self.ack if ack is None else ack, 0, opcode]) + body)
        self.sequence = (self.sequence + 1) & 255

    def receive(self, opcode):
        deadline = time.monotonic() + 2
        while time.monotonic() < deadline:
            data = self.socket.recv(513)
            assert 4 <= len(data) <= 512
            self.ack = data[0]
            end, control = len(data), data[2]
            while control & 128:
                end -= 1
                assert end >= 3
                control = data[end]
            assert control & 1 == 0, 'smoke test expects single-message packets'
            body = data[3:end]
            if body[0] == opcode:
                return body, data[0]
        raise AssertionError(f'no {opcode:02x} received')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--server', default='target/debug/match-server-026')
    args = parser.parse_args()
    process = subprocess.Popen([args.server, '--bind', '127.0.0.1:0', '--players', '2'],
                               stderr=subprocess.PIPE, text=True)
    peers = []
    try:
        line = process.stderr.readline()
        match = re.search(r'endpoint: 127\.0\.0\.1:(\d+)', line)
        assert match, line
        port = int(match[1])
        expanded_sizes = []
        for slot in range(2):
            peer = Peer(('127.0.0.1', port))
            peers.append(peer)
            session = struct.pack('<I', 100 + slot)
            peer.send(0xd8, session + b'\0')
            ports, _ = peer.receive(0xe3)
            assert ports[1:] == struct.pack('<HH', port, port)
            peer.send(0xd9, session)
            options, original_sequence = peer.receive(0xe4)
            assert options[2] == slot
            stream = lzma.decompress(options[3:], format=lzma.FORMAT_RAW,
                                     filters=[{'id': lzma.FILTER_LZMA2, 'dict_size': 32768}])
            assert stream[-140:-138] == bytes([61, 2])
            assert b'Player1' in stream and b'Player2' in stream
            expanded_sizes.append(len(stream))
            # Deliberately withhold the ack, observe a retransmission, then
            # acknowledge the original generation rather than the retry.
            retried, retry_sequence = peer.receive(0xe4)
            assert retried == options and retry_sequence != original_sequence
            peer.send(0xda, ack=original_sequence)
        for peer in peers:
            clock, _ = peer.receive(0xe5)
            assert clock[2] == 1 and len(clock) == 9
            peer.send(0xfc)
        actions = bytes.fromhex('0102000080000040')
        peers[0].send(0xdc, bytes([1]) + actions)
        forwarded, _ = peers[1].receive(0xeb)
        assert forwarded == bytes([0xeb, 1, 0]) + actions
        retried, _ = peers[1].receive(0xeb)
        assert retried == forwarded
        peers[1].send(0xfc)
        peers[0].send(0xfa)
        closed, _ = peers[0].receive(0xfb)
        assert closed == b'\xfb'
        departed, _ = peers[1].receive(0xea)
        assert len(departed) == 3 and departed[2] == 0
        peers[1].send(0xfa)
        closed, _ = peers[1].receive(0xfb)
        assert closed == b'\xfb'
        peers[0].sequence = 0
        peers[0].send(0xd8, struct.pack('<I', 200) + b'\0')
        ports, _ = peers[0].receive(0xe3)
        assert ports[1:] == struct.pack('<HH', port, port)
        print(json.dumps({'synthetic_peers': 2, 'expanded_options_bytes': expanded_sizes,
                          'startup_retry': 'pass', 'input_relay_and_retry': 'pass',
                          'disconnect': 'pass', 'membership_removal': 'pass',
                          'fresh_match_after_disconnect': 'pass',
                          'live_game_validation': False}, indent=2))
    finally:
        for peer in peers:
            peer.socket.close()
        process.terminate()
        try:
            process.wait(timeout=2)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()
        process.stderr.close()


if __name__ == '__main__':
    main()
