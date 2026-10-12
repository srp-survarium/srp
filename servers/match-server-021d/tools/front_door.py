#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Loopback-only v0.21d test login/browser/lobby/chat; optional local checkpoint.

Wire evidence: sign_in_on_connected 0x23e759, on_sign_in_answer_received
0x23dce1, lobby sign_in_on_packet_received 0x19d2f2 and match redirect
0x1a1dec. This companion gets fixed-roster test clients to the Rust match
service. Any nonempty test account/password is accepted; never logs either.
"""
import argparse
import fcntl
import http.server
import json
import math
import os
from pathlib import Path
import secrets
import select
import socket
import socketserver
import ssl
import sqlite3
import struct
import threading
import tempfile
import time
import urllib.parse


def exact(sock, length):
    output = bytearray()
    while len(output) < length:
        chunk = sock.recv(length - len(output))
        if not chunk:
            raise EOFError('connection closed')
        output.extend(chunk)
    return bytes(output)


def string(value):
    encoded = value.encode('ascii')
    if len(encoded) > 255:
        raise ValueError('string too long')
    return bytes([len(encoded)]) + encoded


def frame(body):
    if not 0 < len(body) <= 65535:
        raise ValueError('invalid message length')
    return (bytes([len(body)]) if len(body) < 256 else b'\0' + struct.pack('<H', len(body))) + body


def read_frame(sock):
    length = exact(sock, 1)[0]
    if not length:
        length = struct.unpack('<H', exact(sock, 2))[0]
    if not 0 < length <= 4096:
        raise ValueError('invalid incoming message length')
    return exact(sock, length)


def match_status(path):
    """Fresh request/reply, never infer availability from an old status file."""
    nonce = secrets.randbits(64)
    try:
        with tempfile.TemporaryDirectory(prefix='srp-021d-route-') as directory:
            with socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM) as sock:
                sock.bind(str(Path(directory) / 'reply'))
                sock.settimeout(.25)
                sock.connect(str(path))
                sock.send(f'status {nonce}'.encode('ascii'))
                fields = sock.recv(256).decode('ascii').split()
        if len(fields) != 6 or fields[:2] != ['v1', str(nonce)]:
            return None
        instance, generation, phase, occupied = fields[2:]
        generation, occupied = int(generation), int(occupied)
        if (not 0 < len(instance) <= 32 or any(c not in '0123456789abcdef' for c in instance)
                or not 0 < generation < 2**64 or not 0 <= occupied < 2**20
                or phase not in ('waiting', 'starting', 'running', 'finished')):
            return None
        return instance, generation, phase, occupied
    except (OSError, ValueError):
        return None


def match_admission(path, identity, operation, revision, slot, account, session):
    """Retry one immutable mutation; a lost reply must not create a new grant."""
    if operation not in ('admit', 'revoke'):
        raise ValueError('invalid admission operation')
    instance, generation = identity
    request = f'{operation} {revision} {instance} {generation} {slot} {account} {session}'.encode('ascii')
    try:
        with tempfile.TemporaryDirectory(prefix='srp-021d-admit-') as directory:
            with socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM) as sock:
                sock.bind(str(Path(directory) / 'reply'))
                sock.settimeout(.25)
                sock.connect(str(path))
                for _ in range(3):
                    sock.send(request)
                    try:
                        fields = sock.recv(256).decode('ascii').split()
                    except socket.timeout:
                        continue
                    if (len(fields) == 6 and fields[:5] == ['v1', str(revision), instance, str(generation), str(slot)]
                            and fields[5] in ('ok', 'invalid', 'stale', 'conflict', 'unavailable', 'occupied')):
                        return fields[5]
    except (OSError, ValueError):
        pass
    return None


def match_results(path, identity, slot):
    """Only accept the routed match's retained native reply for this account."""
    instance, generation = identity
    nonce = secrets.randbits(64)
    try:
        with tempfile.TemporaryDirectory(prefix='srp-021d-results-') as directory:
            with socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM) as sock:
                sock.bind(str(Path(directory) / 'reply'))
                sock.settimeout(.25)
                sock.connect(str(path))
                sock.send(f'results {nonce} {generation} {slot}'.encode('ascii'))
                fields = sock.recv(8192).decode('ascii').split()
        if len(fields) != 6 or fields[:4] != ['v1', str(nonce), instance, str(generation)]:
            return None
        if not 0 < int(fields[4]) < 2**32:
            return None
        packet = bytes.fromhex(fields[5])
        if not 2 < len(packet) <= 4096 or packet[:2] != b'\x36\x13':
            return None
        return packet
    except (OSError, ValueError):
        return None


class StateStore:
    """Single-writer, private SQLite checkpoint for the local fixture only."""
    def __init__(self, path):
        self.lock_fd = os.open(str(path) + '.lock', os.O_CREAT | os.O_RDWR | os.O_NOFOLLOW, 0o600)
        self.db = None
        try:
            fcntl.flock(self.lock_fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
            fd = os.open(path, os.O_CREAT | os.O_RDWR | os.O_NOFOLLOW, 0o600)
            try:
                if os.fstat(fd).st_mode & 0o077:
                    raise ValueError('state file must be private (mode 0600)')
            finally:
                os.close(fd)
            self.db = sqlite3.connect(path, isolation_level=None, check_same_thread=False)
            self.db.execute('PRAGMA synchronous=FULL')
            self.db.execute('CREATE TABLE IF NOT EXISTS checkpoint (id INTEGER PRIMARY KEY CHECK(id=1), payload TEXT NOT NULL)')
            self.db.execute('CREATE TABLE IF NOT EXISTS menu_order (id INTEGER PRIMARY KEY CHECK(id=1), value INTEGER NOT NULL)')
        except Exception:
            self.close()
            raise

    def load(self):
        size = self.db.execute('SELECT length(payload) FROM checkpoint WHERE id=1').fetchone()
        if size is None:
            return None
        if not 0 < size[0] <= 131072:
            raise ValueError('invalid state checkpoint size')
        try:
            return json.loads(self.db.execute('SELECT payload FROM checkpoint WHERE id=1').fetchone()[0])
        except (ValueError, TypeError):
            raise ValueError('invalid state checkpoint') from None

    def save(self, value):
        body = json.dumps(value, separators=(',', ':'), allow_nan=False)
        try:
            self.db.execute('BEGIN IMMEDIATE')
            self.db.execute('INSERT INTO checkpoint VALUES (1, ?) ON CONFLICT(id) DO UPDATE SET payload=excluded.payload', (body,))
            self.db.execute('COMMIT')
        except sqlite3.Error:
            if self.db.in_transaction:
                try:
                    self.db.execute('ROLLBACK')
                except sqlite3.Error:
                    pass
            raise OSError('could not persist local fixture state') from None

    def close(self):
        if self.db is not None:
            self.db.close()
            self.db = None
        if self.lock_fd is not None:
            os.close(self.lock_fd)
            self.lock_fd = None

    def next_match_order(self):
        """Reserve a native u32 order before allocating a child or redirecting."""
        try:
            self.db.execute('BEGIN IMMEDIATE')
            row = self.db.execute('SELECT value FROM menu_order WHERE id=1').fetchone()
            previous = row[0] if row is not None else 0
            if type(previous) is not int or not 0 <= previous < 0xfffffffe:
                raise ValueError('invalid or exhausted native match-order counter')
            order = previous + 1
            self.db.execute('INSERT INTO menu_order VALUES (1, ?) ON CONFLICT(id) DO UPDATE SET value=excluded.value', (order,))
            self.db.execute('COMMIT')
            return order
        except (sqlite3.Error, ValueError):
            if self.db.in_transaction:
                try:
                    self.db.execute('ROLLBACK')
                except sqlite3.Error:
                    pass
            raise OSError('could not reserve native match order') from None


class LocalState:
    def __init__(self, count, path=None):
        if not 1 <= count <= 20:
            raise ValueError('invalid roster size')
        self.lock = threading.Lock()
        self.store = None
        self.persistence_failed = False
        self.match_order = 0
        self.accounts = {}
        self.redirected_slots = set()
        self.messaging = {}
        self.match_routes = {}
        self.queued_routes = {}
        self.redirect_until = {}
        self.sessions = secrets.SystemRandom().sample(range(1, 2**32), count)
        if path is not None:
            self.store = StateStore(path)
            try:
                saved = self.store.load()
                if saved is None:
                    self.persist()
                else:
                    self.restore(saved, count)
            except Exception:
                self.store.close()
                raise

    def check_storage(self):
        if self.persistence_failed:
            raise OSError('local state persistence failed; restart required')

    def persist(self):
        if self.store is None:
            return
        mono, wall = time.monotonic(), time.time()
        value = {'version': 1, 'sessions': self.sessions,
                 'accounts': {account.hex(): slot for account, slot in self.accounts.items()},
                 'redirected': sorted(self.redirected_slots), 'routes': self.match_routes,
                 'queued': self.queued_routes,
                 'leases': {slot: wall + max(0, deadline - mono)
                            for slot, deadline in self.redirect_until.items()}}
        try:
            self.store.save(value)
        except Exception:
            # A failed checkpoint must never be followed by an externally
            # acknowledged in-memory mutation. Fail closed until restart.
            self.persistence_failed = True
            raise OSError('could not persist local fixture state') from None

    def restore(self, value, count):
        try:
            if not isinstance(value, dict) or set(value) != {'version', 'sessions', 'accounts', 'redirected', 'routes', 'queued', 'leases'}:
                raise ValueError()
            if type(value['version']) is not int or value['version'] != 1:
                raise ValueError()
            sessions = value['sessions']
            if (not isinstance(sessions, list) or len(sessions) != count
                    or any(type(n) is not int or not 0 < n < 2**32 for n in sessions)
                    or len(set(sessions)) != count):
                raise ValueError()
            accounts = {bytes.fromhex(key): slot for key, slot in value['accounts'].items()}
            if (len(accounts) != len(value['accounts']) or len(accounts) > count
                    or any(not 0 < len(account) <= 255 or type(slot) is not int for account, slot in accounts.items())
                    or sorted(accounts.values()) != list(range(len(accounts)))):
                raise ValueError()
            def slot_key(key):
                n = int(key)
                if str(n) != key or not 0 <= n < count:
                    raise ValueError()
                return n
            def routes(name):
                result = {}
                for key, identity in value[name].items():
                    if not isinstance(identity, list) or len(identity) != 2:
                        raise ValueError()
                    instance, generation = identity
                    if (not isinstance(instance, str) or not 0 < len(instance) <= 32
                            or any(c not in '0123456789abcdef' for c in instance)
                            or type(generation) is not int or not 0 < generation < 2**64):
                        raise ValueError()
                    result[slot_key(key)] = (instance, generation)
                return result
            restored_routes, queued = routes('routes'), routes('queued')
            redirected = value['redirected']
            if (not isinstance(redirected, list) or any(type(n) is not int or not 0 <= n < count for n in redirected)
                    or len(set(redirected)) != len(redirected)):
                raise ValueError()
            leases = {}
            mono, wall = time.monotonic(), time.time()
            for key, deadline in value['leases'].items():
                if type(deadline) not in (int, float) or not math.isfinite(deadline) or deadline < 0:
                    raise ValueError()
                # A backwards wall-clock change cannot create an unbounded lease.
                leases[slot_key(key)] = mono + min(30, max(0, deadline - wall))
            self.sessions, self.accounts = sessions, accounts
            self.match_routes, self.queued_routes = restored_routes, queued
            self.redirected_slots, self.redirect_until = set(redirected), leases
        except (ValueError, TypeError, AttributeError, KeyError, OverflowError):
            raise ValueError('invalid or incompatible local state checkpoint') from None

    def close(self):
        with self.lock:
            self.persistence_failed = True
            if self.store is not None:
                self.store.close()

    def assign(self, account):
        with self.lock:
            self.check_storage()
            if not isinstance(account, bytes) or not 0 < len(account) <= 255:
                raise ValueError('invalid test account')
            if account not in self.accounts:
                if len(self.accounts) >= len(self.sessions):
                    raise ValueError('test roster is full')
                self.accounts[account] = len(self.accounts)
                self.persist()
            slot = self.accounts[account]
            return slot, self.sessions[slot]

    def next_match_order(self):
        with self.lock:
            self.check_storage()
            if self.store is not None:
                try:
                    return self.store.next_match_order()
                except OSError:
                    self.persistence_failed = True
                    raise
            if self.match_order >= 0xfffffffe:
                raise OSError('native match-order counter exhausted')
            self.match_order += 1
            return self.match_order

    def slot(self, session):
        with self.lock:
            self.check_storage()
            return self.sessions.index(session)

    def first_match(self, slot):
        with self.lock:
            self.check_storage()
            if slot in self.redirected_slots:
                return False
            self.redirected_slots.add(slot)
            self.persist()
            return True

    def route_match(self, slot, status):
        if status is None:
            return False
        instance, generation, phase, occupied = status
        identity = instance, generation
        with self.lock:
            self.check_storage()
            if phase not in ('waiting', 'running') or occupied & (1 << slot):
                return False
            previous = self.match_routes.get(slot)
            queued = self.queued_routes.get(slot) == identity
            if slot in self.queued_routes and not queued:
                return False  # An explicit reservation cannot follow a reset.
            if previous is not None and not queued and (previous != identity or phase != 'running'):
                return False
            now = time.monotonic()
            # Concurrent lobby sockets must not redirect one account twice
            # while its first redirect is still establishing the UDP peer.
            if now < self.redirect_until.get(slot, 0):
                return False
            self.match_routes[slot] = identity
            self.redirected_slots.add(slot)
            self.redirect_until[slot] = now + 30
            self.persist()
            return True

    def queue_match(self, slots, identity, status):
        """Explicit local admission to one empty generation, never auto-requeue."""
        if status is None or status[:2] != identity:
            raise ValueError('stale-match')
        if status[2:] != ('waiting', 0):
            raise ValueError('match-not-empty')
        if (not slots or len(set(slots)) != len(slots)
                or any(not 0 <= slot < len(self.sessions) for slot in slots)):
            raise ValueError('invalid-slots')
        with self.lock:
            self.check_storage()
            # Validate the entire batch before changing any account's route.
            if any(self.match_routes.get(slot) == identity
                   and self.queued_routes.get(slot) != identity for slot in slots):
                raise ValueError('already-routed')
            for slot in slots:
                if self.queued_routes.get(slot) != identity:
                    self.queued_routes[slot] = identity
                    self.redirect_until[slot] = 0
            self.persist()


def read_sessions(path, count):
    fd = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
    with os.fdopen(fd) as source:
        if os.fstat(source.fileno()).st_mode & 0o077:
            raise ValueError('session file must be private (mode 0600)')
        body = source.read(4097)
    try:
        rows = [line.split() for line in body.splitlines()]
        if (len(body) > 4096 or len(rows) != count
                or any(len(row) != 2 or int(row[1]) != slot for slot, row in enumerate(rows))):
            raise ValueError()
        sessions = [int(row[0]) for row in rows]
        if len(set(sessions)) != count or any(not 0 < n < 2**32 for n in sessions):
            raise ValueError()
        return sessions
    except ValueError:
        raise ValueError('invalid session file') from None


def configure_sessions(state, path, reuse=False):
    """Export durable tokens without silently replacing a running roster."""
    if reuse:
        if state.store is not None:
            raise ValueError('--reuse-sessions cannot be combined with --state')
        state.sessions = read_sessions(path, len(state.sessions))
        return
    if state.store is not None:
        try:
            sessions = read_sessions(path, len(state.sessions))
        except FileNotFoundError:
            pass
        else:
            if sessions != state.sessions:
                raise ValueError('session file does not match state checkpoint')
            return
    with os.fdopen(os.open(path, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600), 'w') as output:
        for slot, session in enumerate(state.sessions):
            output.write(f'{session} {slot}\n')
        output.flush()
        os.fsync(output.fileno())


class LobbyControlHandler(socketserver.BaseRequestHandler):
    def handle(self):
        data, sock = self.request
        nonce = None
        try:
            if len(data) > 256:
                return
            fields = data.decode('ascii').split()
            if len(fields) < 2:
                return
            nonce = int(fields[1])
            if not 0 <= nonce < 2**64:
                return
            status = match_status(ARGS.match_control)
            if fields[0] == 'status' and len(fields) == 2:
                if status is None:
                    raise ValueError('match-unavailable')
                reply = f'v1 {nonce} ' + ' '.join(map(str, status))
            elif fields[0] == 'queue' and len(fields) == 5:
                identity = fields[2], int(fields[3])
                slots = [int(slot) for slot in fields[4].split(',')]
                STATE.queue_match(slots, identity, status)
                reply = f'v1 {nonce} queued {identity[0]} {identity[1]}'
                print(f'next match queued: generation={identity[1]}, slots={slots}', flush=True)
            else:
                raise ValueError('invalid-command')
        except (UnicodeError, ValueError, OSError) as error:
            if nonce is None:
                return
            # Error text contains no request bytes or account/session data.
            reason = str(error) if str(error) in {
                'stale-match', 'match-not-empty', 'invalid-slots', 'already-routed',
                'match-unavailable', 'invalid-command'} else 'invalid-command'
            reply = f'v1 {nonce} error {reason}'
        try:
            sock.sendto(reply.encode('ascii'), self.client_address)
        except OSError:
            pass


class LobbyControl(socketserver.UnixDatagramServer):
    max_packet_size = 257

    def __init__(self, path):
        self.owns_path = False
        super().__init__(str(path), LobbyControlHandler)
        try:
            os.chmod(path, 0o600)
        except OSError:
            self.server_close()
            raise

    def server_bind(self):
        super().server_bind()
        self.owns_path = True

    def server_close(self):
        super().server_close()
        if self.owns_path:
            Path(self.server_address).unlink(missing_ok=True)
            self.owns_path = False


class TCP(socketserver.ThreadingTCPServer):
    allow_reuse_address = True
    daemon_threads = True
    # Bound simultaneous test connections; malformed clients cannot grow threads indefinitely.
    def process_request(self, request, address):
        if not self.limit.acquire(blocking=False):
            request.close()
            return
        try:
            super().process_request(request, address)
        except BaseException:
            self.limit.release()
            raise

    def process_request_thread(self, request, address):
        try:
            super().process_request_thread(request, address)
        finally:
            self.limit.release()

    def __init__(self, port, handler):
        self.limit = threading.BoundedSemaphore(16)
        super().__init__(('127.0.0.1', port), handler)


class Handler(socketserver.BaseRequestHandler):
    def handle(self):
        self.request.settimeout(30)
        try:
            self.run()
        except (EOFError, OSError, ValueError) as error:
            print(f'{type(self).__name__}: {type(error).__name__}: {error}', flush=True)


class Login(Handler):
    def run(self):
        sock = self.request
        if exact(sock, 1) != b'\x01':
            raise ValueError('only sign-in is supported')
        account = exact(sock, exact(sock, 1)[0])
        version = exact(sock, 12).split(b'\0', 1)[0]
        exact(sock, 5)  # queue flag and previous queue order ID
        if version != b'0.21d':
            sock.sendall(b'\x14')
            return
        sock.sendall(b'\x0b')
        with TLS.wrap_socket(sock, server_side=True) as secure:
            password = exact(secure, exact(secure, 1)[0])
            if not account or not password:
                secure.sendall(b'\x0a')
                return
            del password
            slot, session = STATE.assign(account)
            endpoint = socket.inet_aton('127.0.0.1')
            reply = (b'\x08' + string(f'127.0.0.1:{ARGS.browser_port}')
                     + string('/servers?unused=1') + struct.pack('<I', session)
                     + endpoint + struct.pack('<H', ARGS.lobby_port)
                     + endpoint + struct.pack('<H', ARGS.messaging_port))
            secure.sendall(reply)
            print(f'login accepted: slot={slot}, version=0.21d', flush=True)


class Browser(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        query = urllib.parse.parse_qs(urllib.parse.urlsplit(self.path).query)
        kind = query.get('type', [''])[0]
        port = {'2': ARGS.lobby_port, '4': ARGS.messaging_port}.get(kind)
        if port is None:
            self.send_error(400)
            return
        body = f'127.0.0.1:{port}'.encode('ascii')
        self.send_response(200)
        self.send_header('Content-Length', str(len(body)))
        self.end_headers()
        self.wfile.write(body)
        print(f'browser route: type={kind}', flush=True)

    def log_message(self, *args):
        pass


class Lobby(Handler):
    def run(self):
        message = read_frame(self.request)
        if len(message) != 11 or message[0] != 0x26:
            raise ValueError(f'expected v0.21d lobby sign-in, got opcode={message[0]:02x} size={len(message)}')
        slot = STATE.slot(struct.unpack_from('<I', message, 1)[0])
        self.request.sendall(frame(b'\x30\x00'))
        # The sign-in handler installs the normal callback before processing
        # the next framed message. An idle lobby need not send a query first.
        control = getattr(ARGS, 'match_control', None)
        redirected = False
        results_sent = False
        discard_order = message[5] != 0
        requested_match = struct.unpack_from('<I', message, 6)[0]
        # Native normal finish requests no explicit ID (ffffffff) in our tested
        # build; the authenticated route identifies its just-completed match.
        with STATE.lock:
            result_identity = STATE.match_routes.get(slot)
        wants_results = discard_order or requested_match == 1
        # select() lets the lobby observe a slot being released while idle.
        # Once a frame begins, preserve partial-read framing with a bounded
        # read deadline instead of restarting a parser after every poll timeout.
        self.request.settimeout(30)
        while True:
            if control and wants_results and result_identity and not results_sent:
                packet = match_results(control, result_identity, slot)
                if packet is not None:
                    self.request.sendall(frame(packet))
                    results_sent = True
                    print(f'match results sent: slot={slot}, generation={result_identity[1]}', flush=True)
            if not redirected:
                allowed = (STATE.route_match(slot, match_status(control)) if control
                           else STATE.first_match(slot))
                if allowed:
                    redirect = b'\x33' + string('127.0.0.1') + struct.pack('<HIB', ARGS.match_port, 1, slot % 2)
                    self.request.sendall(frame(redirect))
                    print(f'match redirect sent: slot={slot}', flush=True)
                    redirected = True
                elif not control:
                    print(f'lobby retained: slot={slot}, automatic redirect already used', flush=True)
                    redirected = True  # No lifecycle query: retain one-shot policy.
            if not select.select([self.request], [], [], .25)[0]:
                continue
            message = read_frame(self.request)
            print(f'lobby message: slot={slot}, opcode={message[0]:02x}, size={len(message)}', flush=True)
            if message[:2] == b'\x21\x13' and len(message) == 6:
                wants_results = struct.unpack_from('<I', message, 2)[0] == 1
                results_sent = False
            # Client 0x28 is ping_server; 0x27 carries a matchmaking order
            # cancellation, not a timestamp. See LOBBY-CONTRACT.txt.
            if message[0] == 0x28 and len(message) == 5:
                self.request.sendall(frame(b'\x37' + message[1:]))


class Messaging(Handler):
    def match_memberships(self):
        """Snapshot account slot -> (match identity, wire group, team).

        The native allocator overrides this for its independent room rosters.
        Acquire any routing lock before the relay's messaging-state lock.
        """
        with STATE.lock:
            return {slot: (STATE.match_routes.get(slot), 1, slot % 2)
                    for slot in STATE.redirected_slots}

    def send(self, body):
        # Concurrent senders must never interleave TCP frames to one receiver.
        with self.write_lock:
            self.request.sendall(frame(body))

    def relay(self, message):
        # on_message_typed 0x19b0ff: c1,u32 group,u8-string recipient,
        # u8 channel,u8-string text. Sender identity is supplied by sign-in.
        if len(message) < 8:
            raise ValueError('truncated chat message')
        group = struct.unpack_from('<I', message, 1)[0]
        end_name = 6 + message[5]
        if message[5] > 63 or end_name + 2 > len(message):
            raise ValueError('invalid chat recipient')
        recipient = message[6:end_name]
        channel, size = message[end_name:end_name + 2]
        text = message[end_name + 2:]
        if len(text) != size or b'\0' in text or b'\0' in recipient:
            raise ValueError('invalid chat text length')
        if not text:
            return
        memberships = self.match_memberships() if channel in (5, 6, 7) else {}
        with STATE.lock:
            if STATE.messaging.get(self.slot) is not self:
                return
            peers = list(STATE.messaging.values())
            if channel == 4:
                recipients = [p for p in peers if recipient.lower() == f'Local {p.slot + 1}'.encode().lower()]
            elif channel == 1:
                allowed = group != 0xffffffff and self.subscriptions[1] == group
                recipients = [p for p in peers if allowed and p.subscriptions[channel] == group]
            elif channel in (5, 6, 7):
                sender = memberships.get(self.slot)
                allowed = (sender is not None and group == sender[1]
                           and (channel == 5 or channel == 6 + sender[2]))
                recipients = []
                if allowed:
                    for peer in peers:
                        target = memberships.get(peer.slot)
                        if (target is not None and target[:2] == sender[:2]
                                and peer.subscriptions[channel] == group
                                and (channel == 5 or target[2] == sender[2])):
                            recipients.append(peer)
            else:
                recipients = []  # Clan/squad/system channels have no test service.
        # process_incoming_text_message 0x19b858: c9,u8 source type,u32
        # account ID,u8-string name,u8 channel,u8-string text. Type5=account.
        outgoing = (b'\xc9\x05' + struct.pack('<I', self.slot + 1)
                    + string(f'Local {self.slot + 1}') + bytes([channel, size]) + text)
        delivered = 0
        for peer in recipients:
            if peer is self:
                continue  # on_message_typed already adds the local UI message.
            try:
                peer.send(outgoing)
                delivered += 1
            except OSError:
                try:
                    peer.request.shutdown(socket.SHUT_RDWR)
                except OSError:
                    pass
        print(f'chat relayed: slot={self.slot}, channel={channel}, recipients={delivered}', flush=True)

    def run(self):
        message = read_frame(self.request)
        if len(message) != 6 or message[0] != 0xc3:
            raise ValueError('expected messaging sign-in')
        slot = STATE.slot(struct.unpack_from('<I', message, 1)[0])
        if message[5] != 5:
            raise ValueError('only account messaging clients are supported')
        self.slot = slot
        self.write_lock = threading.Lock()
        self.subscriptions = (0,) * 9
        # sign_in_on_packet_received VA 0x1b32a0 expects 0xca + u8 string.
        self.request.sendall(frame(b'\xca' + string(f'Local {slot + 1}')))
        self.request.settimeout(None)
        print(f'messaging signed in: slot={slot}', flush=True)
        with STATE.lock:
            previous = STATE.messaging.get(slot)
            STATE.messaging[slot] = self
        if previous is not None:
            try:
                previous.request.shutdown(socket.SHUT_RDWR)
            except OSError:
                pass
        try:
            while True:
                message = read_frame(self.request)
                print(f'messaging message: slot={slot}, opcode={message[0]:02x}, size={len(message)}', flush=True)
                if message[0] == 0xc5:
                    if len(message) != 37:
                        raise ValueError('invalid channel subscription length')
                    with STATE.lock:
                        self.subscriptions = struct.unpack('<9I', message[1:])
                elif message[0] == 0xc1:
                    self.relay(message)
        finally:
            with STATE.lock:
                if STATE.messaging.get(slot) is self:
                    del STATE.messaging[slot]


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cert', required=True, type=Path)
    parser.add_argument('--key', required=True, type=Path)
    parser.add_argument('--sessions', required=True, type=Path)
    parser.add_argument('--reuse-sessions', action='store_true', help='reuse private local-test tokens across front-door restarts')
    parser.add_argument('--state', type=Path, help='private SQLite checkpoint for accounts, tokens and match routes across front-door restarts')
    parser.add_argument('--match-control', type=Path, help='match server local control socket; enables same-match reconnect routing')
    parser.add_argument('--lobby-control', type=Path, help='optional mode-0600 local socket for explicitly queuing the next match')
    parser.add_argument('--players', type=int, choices=range(1, 21), default=2)
    for name, default in [('login', 12021), ('lobby', 12022), ('match', 12023), ('messaging', 12024), ('browser', 18021)]:
        parser.add_argument(f'--{name}-port', type=int, default=default)
    ARGS = parser.parse_args()
    if ARGS.lobby_control and not ARGS.match_control:
        parser.error('--lobby-control requires --match-control')
    if ARGS.state and ARGS.reuse_sessions:
        parser.error('--reuse-sessions cannot be combined with --state')
    TLS = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    TLS.set_ciphers('ALL:@SECLEVEL=0')
    TLS.minimum_version = ssl.TLSVersion.TLSv1
    TLS.load_cert_chain(ARGS.cert, ARGS.key)
    STATE = LocalState(ARGS.players, ARGS.state)
    servers = []
    started = []
    try:
        configure_sessions(STATE, ARGS.sessions, ARGS.reuse_sessions)
        for port, handler in [(ARGS.login_port, Login), (ARGS.lobby_port, Lobby), (ARGS.messaging_port, Messaging)]:
            servers.append(TCP(port, handler))
        servers.append(http.server.ThreadingHTTPServer(('127.0.0.1', ARGS.browser_port), Browser))
        if ARGS.lobby_control:
            servers.append(LobbyControl(ARGS.lobby_control))
        for server in servers:
            threading.Thread(target=server.serve_forever, daemon=True).start()
            started.append(server)
        print(f'v0.21d local test front door ready; login=127.0.0.1:{ARGS.login_port}', flush=True)
        threading.Event().wait()
    except KeyboardInterrupt:
        pass
    finally:
        for server in started:
            server.shutdown()
        for server in servers:
            server.server_close()
        STATE.close()
