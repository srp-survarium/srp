# SPDX-License-Identifier: GPL-3.0-or-later
"""Real messaging sockets with allocator-owned, non-account-ordered rosters."""
import importlib.util
import itertools
from pathlib import Path
import socket
import struct
import sys
import tempfile
import threading
import time
import unittest

sys.path.insert(0, str(Path(__file__).parents[1] / 'tools'))
from match_registry import MatchRegistry
from native_menu import messaging_handler

spec = importlib.util.spec_from_file_location('native_chat_front', Path(__file__).parents[1] / 'tools/front_door.py')
front = importlib.util.module_from_spec(spec)
spec.loader.exec_module(front)


class Child:
    port = 29001
    exit_code = None

    def poll(self):
        return self.exit_code

    def stop(self):
        self.exit_code = 0


class NativeChat(unittest.TestCase):
    def setUp(self):
        front.STATE = front.LocalState(5)
        self.addCleanup(front.STATE.close)
        self.tokens = [front.STATE.assign(f'account-{i}'.encode())[1] for i in range(5)]
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.children = []
        self.sequence = itertools.count(1)
        self.registry = MatchRegistry(lambda p: self.tokens[int(p[6:]) - 1],
            lambda p: True, lambda p: True, lambda *args: None,
            '/unused/server', self.directory.name, launcher=self.launch,
            next_order=itertools.count(41).__next__)
        self.addCleanup(self.registry.shutdown)
        # Account slot 1 is team 0; account slot 0 is team 1 in this room.
        self.first = self.start([1, 0, 2])
        self.second = self.start([3, 4])
        self.server = front.TCP(0, messaging_handler(front, self.registry))
        self.worker = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.worker.start()
        self.sockets = []

    def tearDown(self):
        for sock in self.sockets:
            sock.close()
        self.server.shutdown()
        self.server.server_close()
        self.worker.join(timeout=2)

    def launch(self, *args):
        child = Child()
        self.children.append(child)
        return child

    def call(self, slot, op, **fields):
        result = self.registry.dispatch(dict(v='1', id=str(next(self.sequence)),
            player=f'local-{slot + 1}', op=op, **fields))
        self.assertTrue(result['ok'], result)
        return result['result']

    def start(self, slots):
        room = self.call(slots[0], 'create', name='Chat', map='school', capacity=str(len(slots)))['room']['id']
        for slot in slots[1:]:
            self.call(slot, 'join', match=room)
        for slot in slots:
            self.call(slot, 'ready', match=room, ready='1')
        self.call(slots[0], 'start', match=room)
        self.registry.flush_redirects()
        return room

    def subscribe(self, sock, slot, group):
        groups = (0, 10, 0xffffffff, 0, 1, group, group, group, 0)
        sock.sendall(front.frame(b'\xc5' + struct.pack('<9I', *groups)))
        deadline = time.monotonic() + 2
        while time.monotonic() < deadline:
            with front.STATE.lock:
                peer = front.STATE.messaging.get(slot)
                if peer and peer.subscriptions == groups:
                    return
            time.sleep(.005)
        self.fail('subscriptions were not applied')

    def connect(self, slot, group):
        sock = socket.create_connection(self.server.server_address, timeout=1)
        self.sockets.append(sock)
        sock.sendall(front.frame(b'\xc3' + struct.pack('<I', self.tokens[slot]) + b'\x05'))
        self.assertEqual(front.read_frame(sock), b'\xca' + front.string(f'Local {slot + 1}'))
        self.subscribe(sock, slot, group)
        return sock

    def send(self, sock, group=41, channel=5, text=b'hello', recipient=b''):
        sock.sendall(front.frame(b'\xc1' + struct.pack('<I', group)
            + bytes([len(recipient)]) + recipient + bytes([channel, len(text)]) + text))

    def received(self, sock, sender, channel=5, text=b'hello'):
        self.assertEqual(front.read_frame(sock), b'\xc9\x05' + struct.pack('<I', sender + 1)
            + front.string(f'Local {sender + 1}') + bytes([channel, len(text)]) + text)

    def silent(self, *sockets):
        for sock in sockets:
            sock.settimeout(.08)
            with self.assertRaises(socket.timeout):
                sock.recv(1)
            sock.settimeout(1)

    def test_membership_blocks_cross_room_subscriptions_and_forged_groups(self):
        a, b, c, d, e = [self.connect(i, 41) for i in range(5)]
        self.send(b)
        self.received(a, 1)
        self.received(c, 1)
        self.silent(b, d, e)
        self.send(d)  # An outsider subscribes and sends to another match.
        self.silent(a, b, c, e)
        for slot, sock in [(3, d), (4, e)]:
            self.subscribe(sock, slot, 42)
        self.send(d, group=42)
        self.received(e, 3)
        self.send(b, group=42)
        self.silent(a, c, d, e)

    def test_team_uses_match_roster_and_rejects_opposing_channel(self):
        a, b, c = [self.connect(i, 41) for i in range(3)]
        self.send(b, channel=6)
        self.received(c, 1, channel=6)
        self.silent(a, b)
        self.send(b, channel=7)  # Account parity would incorrectly permit it.
        self.silent(a, c)
        self.send(a, channel=6)
        self.silent(b, c)

    def test_returned_player_loses_match_permission_but_private_chat_remains(self):
        a, b, c = [self.connect(i, 41) for i in range(3)]
        self.registry.lobby_connected('local-1')
        self.send(b)
        self.received(c, 1)
        self.silent(a)
        self.send(a)
        self.silent(b, c)
        self.send(a, group=0, channel=4, recipient=b'local 2')
        self.received(b, 0, channel=4)

    def test_child_exit_revokes_membership_before_periodic_reap(self):
        a, b = [self.connect(i, 41) for i in range(2)]
        self.children[0].exit_code = 1
        self.send(b)
        self.silent(a)
        self.assertNotIn('local-1', self.registry.chat_memberships())

    def test_next_admission_uses_new_order_and_new_team_with_same_connection(self):
        a, b = [self.connect(i, 41) for i in range(2)]
        self.registry.close_room(self.first)
        self.start([0, 1])  # Account 1 changes to team 0; new order is 43.
        for slot, sock in [(0, a), (1, b)]:
            self.subscribe(sock, slot, 43)
        self.send(a, group=41)
        self.silent(b)
        self.send(a, group=43)
        self.received(b, 0)
        self.send(a, group=43, channel=7)
        self.silent(b)

    def test_no_gameplay_registry_has_no_match_chat_membership(self):
        from menu_fixture import Registry
        handler = object.__new__(messaging_handler(front, Registry()))
        self.assertEqual(handler.match_memberships(), {})


if __name__ == '__main__':
    unittest.main()
