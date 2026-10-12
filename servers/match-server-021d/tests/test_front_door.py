# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise reconnect behavior over real loopback TCP framing."""
import importlib.util
from pathlib import Path
import socket
import stat
import struct
import threading
import tempfile
import time
from unittest.mock import patch
from types import SimpleNamespace
import unittest

spec = importlib.util.spec_from_file_location('front_door', Path(__file__).parents[1] / 'tools/front_door.py')
front = importlib.util.module_from_spec(spec)
spec.loader.exec_module(front)
queue_spec = importlib.util.spec_from_file_location('queue_match', Path(__file__).parents[1] / 'tools/queue_match.py')
queue_tool = importlib.util.module_from_spec(queue_spec)
queue_spec.loader.exec_module(queue_tool)


class PersistentState(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory(prefix='srp-state-test-')
        self.path = Path(self.directory.name) / 'state.sqlite'
        self.states = []

    def tearDown(self):
        for state in self.states:
            state.close()
        self.directory.cleanup()

    def open(self, count=2):
        state = front.LocalState(count, self.path)
        self.states.append(state)
        return state

    def test_restart_preserves_accounts_tokens_and_one_shot_admission(self):
        state = self.open()
        a, b = state.assign(b'account-a'), state.assign(b'account-b')
        self.assertTrue(state.first_match(a[0]))
        state.close()
        restored = self.open()
        self.assertEqual(restored.assign(b'account-b'), b)
        self.assertEqual(restored.assign(b'account-a'), a)
        self.assertFalse(restored.first_match(a[0]))
        self.assertTrue(restored.first_match(b[0]))
        self.assertEqual(stat.S_IMODE(self.path.stat().st_mode), 0o600)

    def test_native_match_orders_are_committed_before_return_and_never_reused(self):
        state = self.open()
        self.assertEqual(state.next_match_order(), 1)
        self.assertEqual(state.next_match_order(), 2)
        state.close()
        restored = self.open()
        self.assertEqual(restored.next_match_order(), 3)
        restored.store.db.execute('UPDATE menu_order SET value=?', (0xfffffffe,))
        with self.assertRaises(OSError):
            restored.next_match_order()
        self.assertEqual(restored.store.db.execute('SELECT value FROM menu_order').fetchone()[0], 0xfffffffe)

    def test_failed_order_reservation_blocks_admission_until_restart(self):
        state = self.open()
        self.assertEqual(state.next_match_order(), 1)
        state.store.db.execute('PRAGMA query_only=ON')
        with self.assertRaises(OSError):
            state.next_match_order()
        with self.assertRaisesRegex(OSError, 'restart required'):
            state.assign(b'after-failure')
        state.close()
        self.assertEqual(self.open().next_match_order(), 2)

    def test_routes_reservations_and_remaining_lease_survive_restart(self):
        state = self.open()
        state.assign(b'account-a')
        with patch.object(front.time, 'monotonic', return_value=100), patch.object(front.time, 'time', return_value=1000):
            self.assertTrue(state.route_match(0, ('aa', 1, 'running', 0)))
            state.queue_match([1], ('aa', 2), ('aa', 2, 'waiting', 0))
        state.close()
        with patch.object(front.time, 'monotonic', return_value=200), patch.object(front.time, 'time', return_value=1010):
            restored = self.open()
            self.assertEqual(restored.redirect_until[0], 220)
            self.assertFalse(restored.route_match(0, ('aa', 1, 'running', 0)))
            self.assertFalse(restored.route_match(1, ('bb', 1, 'waiting', 0)))
            self.assertTrue(restored.route_match(1, ('aa', 2, 'waiting', 0)))
        with patch.object(front.time, 'monotonic', return_value=221):
            self.assertFalse(restored.route_match(0, ('aa', 2, 'running', 0)))
            self.assertTrue(restored.route_match(0, ('aa', 1, 'running', 0)))

    def test_backwards_wall_clock_cannot_extend_lease_beyond_thirty_seconds(self):
        state = self.open()
        with patch.object(front.time, 'monotonic', return_value=100), patch.object(front.time, 'time', return_value=1000):
            state.route_match(0, ('aa', 1, 'running', 0))
        state.close()
        with patch.object(front.time, 'monotonic', return_value=200), patch.object(front.time, 'time', return_value=500):
            self.assertEqual(self.open().redirect_until[0], 230)

    def test_second_writer_and_incompatible_roster_do_not_reset_checkpoint(self):
        state = self.open()
        identity = state.assign(b'account-a')
        with self.assertRaises(OSError):
            self.open()
        state.close()
        with self.assertRaises(ValueError):
            self.open(3)
        restored = self.open()
        self.assertEqual(restored.assign(b'account-a'), identity)

    def test_invalid_checkpoint_is_rejected_without_replacement(self):
        state = self.open()
        for body in ['not json', '{"version":99}']:
            state.store.db.execute('UPDATE checkpoint SET payload=?', (body,))
            state.close()
            with self.assertRaises(ValueError):
                self.open()
            store = front.StateStore(self.path)
            self.assertEqual(store.db.execute('SELECT payload FROM checkpoint').fetchone()[0], body)
            store.close()
            # Repair explicitly only to exercise the next corrupt variant.
            self.path.unlink()
            state = self.open()

    def test_failed_transaction_never_acknowledges_assignment_or_leaks_on_restart(self):
        state = self.open()
        identity = state.assign(b'account-a')
        state.store.db.execute('PRAGMA query_only=ON')
        with self.assertRaisesRegex(OSError, 'could not persist'):
            state.assign(b'account-b')
        for operation in [lambda: state.assign(b'account-a'), lambda: state.slot(identity[1]),
                          lambda: state.first_match(0),
                          lambda: state.route_match(0, ('aa', 1, 'waiting', 0)),
                          lambda: state.queue_match([0], ('aa', 1), ('aa', 1, 'waiting', 0))]:
            with self.assertRaisesRegex(OSError, 'restart required'):
                operation()
        state.close()
        restored = self.open()
        self.assertEqual(restored.accounts, {b'account-a': 0})
        self.assertEqual(restored.assign(b'account-a'), identity)

    def test_session_export_is_private_reusable_and_never_silently_replaced(self):
        state = self.open()
        path = Path(self.directory.name) / 'sessions'
        front.configure_sessions(state, path)
        original = path.read_bytes()
        self.assertEqual(stat.S_IMODE(path.stat().st_mode), 0o600)
        state.close()
        restored = self.open()
        front.configure_sessions(restored, path)
        self.assertEqual(path.read_bytes(), original)
        other = front.LocalState(2)
        other.sessions = list(reversed(restored.sessions))
        path.unlink()
        front.configure_sessions(other, path)
        mismatched = path.read_bytes()
        with self.assertRaisesRegex(ValueError, 'does not match'):
            front.configure_sessions(restored, path)
        self.assertEqual(path.read_bytes(), mismatched)
        with self.assertRaises(ValueError):
            front.configure_sessions(restored, path, reuse=True)
        path.unlink()
        front.configure_sessions(restored, path)
        self.assertEqual(path.read_bytes(), original)
        path.chmod(0o644)
        with self.assertRaisesRegex(ValueError, 'private'):
            front.configure_sessions(restored, path)


class LobbyReconnect(unittest.TestCase):
    def test_finished_player_stays_in_lobby_and_ping_still_works(self):
        front.STATE = front.LocalState(2)
        front.ARGS = SimpleNamespace(match_port=12023)
        slot, token = front.STATE.assign(b'local-test')
        other_slot, other_token = front.STATE.assign(b'second-test')
        server = front.TCP(0, front.Lobby)
        worker = threading.Thread(target=server.serve_forever, daemon=True)
        worker.start()
        def connect(session):
            sock = socket.create_connection(server.server_address, timeout=2)
            sock.sendall(front.frame(b'\x26' + struct.pack('<I', session) + bytes(6)))
            self.assertEqual(front.read_frame(sock), b'\x30\x00')
            return sock
        try:
            with connect(token) as sock:
                redirect = front.read_frame(sock)
                self.assertEqual(redirect, b'\x33\x09' + b'127.0.0.1' + struct.pack('<HIB', 12023, 1, slot % 2))
            with connect(token) as sock:
                ping = b'\x28\x78\x56\x34\x12'
                sock.sendall(front.frame(ping))
                # Any unsolicited match redirect would be the next frame and
                # fail this assertion, reproducing the live match-end bug.
                self.assertEqual(front.read_frame(sock), b'\x37' + ping[1:])
            with connect(other_token) as sock:
                self.assertEqual(front.read_frame(sock)[-1], other_slot % 2)
        finally:
            server.shutdown()
            server.server_close()
            worker.join(timeout=2)


class ChatRelay(unittest.TestCase):
    def setUp(self):
        front.STATE = front.LocalState(3)
        self.tokens = [front.STATE.assign(f'chat-test-{i}'.encode())[1] for i in range(3)]
        front.STATE.redirected_slots.update(range(3))
        self.server = front.TCP(0, front.Messaging)
        self.worker = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.worker.start()
        self.sockets = []

    def tearDown(self):
        for sock in self.sockets:
            sock.close()
        self.server.shutdown()
        self.server.server_close()
        self.worker.join(timeout=2)

    def connect(self, slot):
        sock = socket.create_connection(self.server.server_address, timeout=1)
        self.sockets.append(sock)
        sock.sendall(front.frame(b'\xc3' + struct.pack('<I', self.tokens[slot]) + b'\x05'))
        self.assertEqual(front.read_frame(sock), b'\xca' + front.string(f'Local {slot + 1}'))
        groups = [0, 10, 0xffffffff, 0, 1, 1, 0, 0, 0]
        groups[6 + slot % 2] = 1
        sock.sendall(front.frame(b'\xc5' + struct.pack('<9I', *groups)))
        deadline = time.monotonic() + 2
        while time.monotonic() < deadline:
            with front.STATE.lock:
                p = front.STATE.messaging.get(slot)
                if p is not None and p.subscriptions == tuple(groups):
                    return sock
            time.sleep(.005)
        self.fail('subscription was not processed')

    def send_chat(self, sock, channel=5, text=b'hello', recipient=b'', group=1):
        body = (b'\xc1' + struct.pack('<I', group) + bytes([len(recipient)])
                + recipient + bytes([channel, len(text)]) + text)
        # Exercise real TCP framing across a partial write.
        encoded = front.frame(body)
        sock.sendall(encoded[:3])
        sock.sendall(encoded[3:])

    def expected(self, slot, channel, text):
        return (b'\xc9\x05' + struct.pack('<I', slot + 1)
                + front.string(f'Local {slot + 1}') + bytes([channel, len(text)]) + text)

    def silent(self, sock):
        sock.settimeout(.08)
        with self.assertRaises(socket.timeout):
            sock.recv(1)
        sock.settimeout(1)

    def test_match_team_private_and_general_routing_without_sender_echo(self):
        a, b, c = [self.connect(i) for i in range(3)]
        self.send_chat(a)
        for peer in (b, c):
            self.assertEqual(front.read_frame(peer), self.expected(0, 5, b'hello'))
        self.silent(a)
        self.send_chat(a, 6, b'team')
        self.assertEqual(front.read_frame(c), self.expected(0, 6, b'team'))
        self.silent(b)
        self.send_chat(a, 7, b'wrong team')
        self.silent(b)
        self.silent(c)
        self.send_chat(a, 4, b'private', b'local 2', 0)
        self.assertEqual(front.read_frame(b), self.expected(0, 4, b'private'))
        self.silent(c)
        self.send_chat(b, 1, 'hello café'.encode(), group=10)
        for peer in (a, c):
            self.assertEqual(front.read_frame(peer), self.expected(1, 1, 'hello café'.encode()))

    def test_messaging_reconnect_replaces_old_socket_without_losing_new_registration(self):
        a, b = self.connect(0), self.connect(1)
        with front.STATE.lock:
            previous = front.STATE.messaging[1]
        replacement = self.connect(1)
        self.assertEqual(b.recv(1), b'')
        deadline = time.monotonic() + 2
        while time.monotonic() < deadline:
            with front.STATE.lock:
                current = front.STATE.messaging.get(1)
                if current is not None and current is not previous:
                    break
            time.sleep(.005)
        self.send_chat(a, text=b'after reconnect')
        self.assertEqual(front.read_frame(replacement), self.expected(0, 5, b'after reconnect'))
        self.send_chat(replacement, text=b'back')
        self.assertEqual(front.read_frame(a), self.expected(1, 5, b'back'))

    def test_malformed_chat_disconnects_only_sender(self):
        a, b, c = [self.connect(i) for i in range(3)]
        a.sendall(front.frame(b'\xc1\x01\0\0\0\0\x05\x05x'))
        self.assertEqual(a.recv(1), b'')
        self.send_chat(b)
        self.assertEqual(front.read_frame(c), self.expected(1, 5, b'hello'))


class LiveMatchRouting(unittest.TestCase):
    def setUp(self):
        front.STATE = front.LocalState(2)
        self.token = front.STATE.assign(b'returning-account')[1]
        self.directory = tempfile.TemporaryDirectory(prefix='srp-routing-test-')
        self.control_path = str(Path(self.directory.name) / 'control')
        self.control = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
        self.control.bind(self.control_path)
        self.control.settimeout(.05)
        self.status = ('aa', 1, 'waiting', 0)
        self.wrong_nonce = False
        self.result = None
        self.stop = threading.Event()
        def reply():
            while not self.stop.is_set():
                try:
                    data, address = self.control.recvfrom(64)
                    fields = data.decode().split()
                    kind, nonce = fields[:2]
                    if kind == 'results':
                        if self.result is not None:
                            instance, generation, packet = self.result
                            body = f'v1 {nonce} {instance} {generation} 15000 {packet.hex()}'
                        else:
                            body = f'v1 {nonce} aa {fields[2]} missing'
                        self.control.sendto(body.encode(), address)
                        continue
                    self.assertEqual(kind, 'status')
                    status = self.status
                    if status is not None:
                        if self.wrong_nonce:
                            nonce = str(int(nonce) + 1)
                        body = f'v1 {nonce} ' + ' '.join(map(str, status))
                        self.control.sendto(body.encode(), address)
                except (socket.timeout, FileNotFoundError, ConnectionRefusedError):
                    continue
        self.control_worker = threading.Thread(target=reply, daemon=True)
        self.control_worker.start()
        front.ARGS = SimpleNamespace(match_port=12023, match_control=Path(self.control_path))
        self.server = front.TCP(0, front.Lobby)
        self.worker = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.worker.start()
        self.sockets = []

    def tearDown(self):
        for sock in self.sockets:
            sock.close()
        self.server.shutdown()
        self.server.server_close()
        self.worker.join(timeout=2)
        self.stop.set()
        self.control_worker.join(timeout=2)
        self.control.close()
        self.directory.cleanup()

    def connect(self, finished=False):
        sock = socket.create_connection(self.server.server_address, timeout=2)
        self.sockets.append(sock)
        tail = b'\xff' + struct.pack('<I', 0xffffffff) + b'\xff' if finished else bytes(6)
        sock.sendall(front.frame(b'\x26' + struct.pack('<I', self.token) + tail))
        self.assertEqual(front.read_frame(sock), b'\x30\0')
        return sock

    def redirected(self, sock):
        self.assertEqual(front.read_frame(sock), b'\x33\x09' + b'127.0.0.1' + struct.pack('<HIB', 12023, 1, 0))

    def retained(self, sock):
        sock.sendall(front.frame(b'\x28\x12\x34\x56\x78'))
        self.assertEqual(front.read_frame(sock), b'\x37\x12\x34\x56\x78')

    def test_cancel_order_is_not_echoed_as_ping_or_allowed_to_change_operator_reservation(self):
        self.status = ('aa', 1, 'starting', 0)
        sock = self.connect()
        front.STATE.queue_match([0], ('aa', 2), ('aa', 2, 'waiting', 0))
        # Independent binary-derived messages: discard_playing_order writes
        # 0x27 + u32 order ID at 0x19e562; ping_server is enum 0x28.
        # No native matchmaking order was issued by this operator fixture.
        sock.sendall(front.frame(bytes.fromhex('27 01 00 00 00')))
        sock.sendall(front.frame(bytes.fromhex('28 04 03 02 01')))
        self.assertEqual(front.read_frame(sock), bytes.fromhex('37 04 03 02 01'))
        self.assertEqual(front.STATE.queued_routes, {0: ('aa', 2)})
        self.assertNotIn(0, front.STATE.match_routes)

    def test_same_account_waits_for_slot_release_and_rejoins_same_live_match(self):
        first = self.connect()
        self.redirected(first)
        duplicate = self.connect()
        self.retained(duplicate)  # Redirect lease blocks a concurrent socket.
        duplicate.close()
        first.close()
        self.status = ('aa', 1, 'running', 3)
        with front.STATE.lock:
            front.STATE.redirect_until[0] = 0
        returning = self.connect()
        self.retained(returning)  # Old UDP peer still owns the slot.
        self.status = ('aa', 1, 'running', 2)
        self.redirected(returning)  # No new lobby request required.
        self.assertEqual(front.STATE.match_routes[0], ('aa', 1))

    def test_front_door_restart_keeps_results_bound_to_original_account_and_match(self):
        path = Path(self.directory.name) / 'state.sqlite'
        front.STATE = front.LocalState(2, path)
        self.token = front.STATE.assign(b'returning-account')[1]
        other = front.STATE.assign(b'other-account')
        first = self.connect()
        self.redirected(first)
        first.close()
        self.server.shutdown()
        self.server.server_close()
        self.worker.join(timeout=2)
        front.STATE.close()
        front.STATE = front.LocalState(2, path)
        try:
            self.assertEqual(front.STATE.assign(b'other-account'), other)
            self.assertEqual(front.STATE.assign(b'returning-account'), (0, self.token))
            self.server = front.TCP(0, front.Lobby)
            self.worker = threading.Thread(target=self.server.serve_forever, daemon=True)
            self.worker.start()
            self.status = ('aa', 2, 'waiting', 0)
            self.result = ('aa', 1, b'\x36\x13retained')
            returning = self.connect(finished=True)
            self.assertEqual(front.read_frame(returning), b'\x36\x13retained')
            self.retained(returning)
            returning.close()
        finally:
            self.server.shutdown()
            self.server.server_close()
            self.worker.join(timeout=2)
            front.STATE.close()

    def test_finish_empty_reset_and_other_match_never_requeue_returning_account(self):
        first = self.connect()
        self.redirected(first)
        first.close()
        with front.STATE.lock:
            front.STATE.redirect_until[0] = 0
        for status in [('aa', 1, 'finished', 2), ('aa', 2, 'waiting', 0),
                       ('aa', 2, 'running', 2), ('bb', 1, 'running', 2)]:
            self.status = status
            sock = self.connect()
            self.retained(sock)
            sock.close()

    def test_missing_or_stale_status_and_starting_cohort_do_not_redirect(self):
        self.status = None
        sock = self.connect()
        self.retained(sock)
        self.assertNotIn(0, front.STATE.redirected_slots)
        self.status = ('aa', 1, 'starting', 2)
        self.retained(sock)
        self.status = ('aa', 1, 'running', 2)
        self.wrong_nonce = True
        self.assertIsNone(front.match_status(self.control_path))
        self.retained(sock)
        self.wrong_nonce = False
        self.redirected(sock)

    def test_finished_signin_waits_for_results_from_the_routed_generation_only(self):
        first = self.connect()
        self.redirected(first)
        first.close()
        self.status = ('aa', 2, 'waiting', 0)
        returning = self.connect(finished=True)
        self.retained(returning)
        # A later match or server incarnation cannot fill this result screen.
        for identity in [('aa', 2), ('bb', 1)]:
            self.result = (*identity, b'\x36\x13test')
            self.assertIsNone(front.match_results(self.control_path, ('aa', 1), 0))
        self.result = ('aa', 1, b'\x36\x13test')
        self.assertEqual(front.read_frame(returning), b'\x36\x13test')
        self.retained(returning)  # No repeated reply or automatic match redirect.

    def test_explicit_operator_queue_redirects_idle_lobby_once_for_one_generation(self):
        first = self.connect()
        self.redirected(first)
        first.close()
        self.status = ('aa', 2, 'waiting', 0)
        self.result = ('aa', 1, b'\x36\x13test')
        returning = self.connect(finished=True)
        self.assertEqual(front.read_frame(returning), b'\x36\x13test')
        self.retained(returning)
        path = Path(self.directory.name) / 'lobby-control'
        operator = front.LobbyControl(path)
        worker = threading.Thread(target=operator.serve_forever, daemon=True)
        worker.start()
        try:
            self.assertEqual(stat.S_IMODE(path.stat().st_mode), 0o600)
            with self.assertRaises(OSError):
                front.LobbyControl(path)
            self.assertTrue(path.exists())  # Failed bind must not unlink another service.
            self.assertEqual(queue_tool.queue(path, [0]), ('aa', 2))
            self.redirected(returning)  # Same idle TCP connection, no relogin.
            self.assertEqual(front.STATE.match_routes[0], ('aa', 2))
            duplicate = self.connect()
            self.retained(duplicate)  # Explicit admission still obeys the lease.
            duplicate.close()
            self.status = ('aa', 2, 'running', 3)
            with self.assertRaises(ValueError):
                queue_tool.queue(path, [0])
            returning.close()
            self.status = ('aa', 3, 'waiting', 0)
            after_next_finish = self.connect(finished=True)
            self.result = None
            self.retained(after_next_finish)  # Permission for generation 2 expired.
            self.assertEqual(front.STATE.match_routes[0], ('aa', 2))
        finally:
            operator.shutdown()
            operator.server_close()
            worker.join(timeout=2)
        self.assertFalse(path.exists())

    def test_queue_batch_is_atomic_and_rejects_stale_identity_or_busy_match(self):
        front.STATE.match_routes[0] = ('aa', 1)
        empty = ('aa', 2, 'waiting', 0)
        for slots, identity, status in [
            ([0, 20], ('aa', 2), empty), ([0, 0], ('aa', 2), empty),
            ([], ('aa', 2), empty), ([0], ('aa', 1), empty),
            ([0], ('bb', 2), empty), ([0], ('aa', 2), None),
            ([0], ('aa', 2), ('aa', 2, 'running', 0)),
            ([0], ('aa', 2), ('aa', 2, 'waiting', 1)),
        ]:
            with self.assertRaises(ValueError):
                front.STATE.queue_match(slots, identity, status)
            self.assertEqual(front.STATE.queued_routes, {})
            self.assertEqual(front.STATE.match_routes, {0: ('aa', 1)})
        front.STATE.queue_match([0, 1], ('aa', 2), empty)
        self.assertEqual(front.STATE.queued_routes, {0: ('aa', 2), 1: ('aa', 2)})
        self.assertTrue(front.STATE.route_match(0, empty))
        # Retrying a queued request never clears an active redirect lease.
        lease = front.STATE.redirect_until[0]
        front.STATE.queue_match([0, 1], ('aa', 2), empty)
        self.assertEqual(front.STATE.redirect_until[0], lease)
        self.assertFalse(front.STATE.route_match(0, empty))
        self.assertFalse(front.STATE.route_match(1, ('bb', 1, 'waiting', 0)))
        self.assertFalse(front.STATE.route_match(0, ('aa', 3, 'waiting', 0)))


if __name__ == '__main__':
    unittest.main()
