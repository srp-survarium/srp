#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Local v0.21d native-menu service; disposable test accounts only.

Uses this server package's login/browser/chat and durable identity store.
Accepts arbitrary nonempty test credentials. Binds loopback only. Supplies
menu identity from a live native lobby session, never from the form's player.
Optional --match-server allocates real local games with explicit SRP1 mode.
"""
import argparse
from functools import partial
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import importlib.util
import json
from pathlib import Path
import re
import signal
import ssl
import struct
import threading
from types import SimpleNamespace
from urllib.parse import parse_qs

from menu_fixture import Registry
from match_registry import MatchProcess, MatchRegistry, MatchWorkspace


def messaging_handler(front, registry):
    class Messaging(front.Messaging):
        def match_memberships(self):
            if not isinstance(registry, MatchRegistry):
                return {}
            # Public account indices differ from a room's static roster slots.
            return {int(player.removeprefix("local-")) - 1: membership
                    for player, membership in registry.chat_memberships().items()}
    return Messaging


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--front-door", default=Path(__file__).with_name("front_door.py"), type=Path)
    parser.add_argument("--state", type=Path, help="private account/token and match-order checkpoint across service restarts")
    parser.add_argument("--cert", required=True, type=Path)
    parser.add_argument("--key", required=True, type=Path)
    parser.add_argument("--base-port", type=int, default=19031)
    parser.add_argument("--match-server", type=Path, help="integrated match-server-021d binary (selects --protocol srp1)")
    parser.add_argument("--match-work", type=Path, help="private directory for per-match grants and logs")
    parser.add_argument("--match-seconds", type=int, help="local match time limit, 1 to 65535 seconds")
    parser.add_argument("--match-results", action="store_true", help="retain native results from the server control socket")
    parser.add_argument("--require-recovery", action="store_true",
                        help="require the SRP1-48-R1 DLL before match admission")
    args = parser.parse_args()
    if not 1024 <= args.base_port <= 65530:
        parser.error("base port must leave space for five loopback services")
    if bool(args.match_server) != bool(args.match_work):
        parser.error("--match-server and --match-work must be provided together")
    if (args.match_results or args.match_seconds is not None) and not args.match_server:
        parser.error("match duration/results require --match-server")
    if args.match_seconds is not None and not 1 <= args.match_seconds <= 65535:
        parser.error("match seconds must be between 1 and 65535")
    spec = importlib.util.spec_from_file_location("srp_front_door", args.front_door)
    front = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(front)
    if args.match_server and not callable(getattr(front, "match_status", None)):
        parser.error("this front door does not support generation-bound match status")
    if args.match_results and not callable(getattr(front, "match_results", None)):
        parser.error("this front door does not support generation-bound match results")
    front.ARGS = SimpleNamespace(login_port=args.base_port, lobby_port=args.base_port+1,
                                messaging_port=args.base_port+2, browser_port=args.base_port+3)
    workspace = MatchWorkspace(args.match_work) if args.match_server else None
    front.STATE = front.LocalState(16, args.state)
    front.TLS = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    front.TLS.set_ciphers("ALL:@SECLEVEL=0")
    front.TLS.minimum_version = ssl.TLSVersion.TLSv1
    front.TLS.load_cert_chain(args.cert, args.key)
    registry = Registry()
    connections = {}
    protocols = {}
    lock = threading.RLock()

    def session_for(player):
        return front.STATE.sessions[int(player.removeprefix("local-")) - 1]

    def redirect(player, port, team, match_id):
        connection = connections.get(session_for(player))
        if connection is None:
            raise ValueError("Lobby disconnected before admission")
        body = b"\x33" + front.string("127.0.0.1") + struct.pack("<HIB", port, match_id, team)
        connection.sendall(front.frame(body))
        print(f"menu match redirect: player={player}, port={port}", flush=True)

    if args.match_server:
        supported = {"SRP1-48-R1"} if args.require_recovery else {"SRP1-48", "SRP1-48-R1"}
        registry = MatchRegistry(session_for, lambda p: session_for(p) in connections,
                                 lambda p: protocols.get(session_for(p)) in supported,
                                 redirect, args.match_server, args.match_work,
                                 launcher=partial(MatchProcess, match_seconds=args.match_seconds,
                                     workspace=workspace,
                                     query_status=front.match_status,
                                     query_results=front.match_results if args.match_results else None),
                                 next_order=front.STATE.next_match_order,
                                 identity=lambda p: int(p.removeprefix("local-")))
        lock = registry.lock

    class Lobby(front.Handler):
        def run(self):
            message = front.read_frame(self.request)
            if len(message) != 11 or message[0] != 0x26:
                raise ValueError("invalid lobby sign-in")
            session = struct.unpack_from("<I", message, 1)[0]
            requested_match = struct.unpack_from("<I", message, 6)[0]
            wants_results = bool(message[5]) or requested_match not in (0, 0xffffffff)
            slot = front.STATE.slot(session)
            self.request.settimeout(None)
            with lock:
                connections[session] = self.request
                protocols.pop(session, None)
                if isinstance(registry, MatchRegistry):
                    registry.lobby_connected(f"local-{slot + 1}")
            try:
                with lock:
                    self.request.sendall(front.frame(b"\x30\x00"))
                    if wants_results and isinstance(registry, MatchRegistry):
                        packet = registry.results_for(f"local-{slot + 1}",
                            None if requested_match in (0, 0xffffffff) else requested_match)
                        if packet is not None:
                            self.request.sendall(front.frame(packet))
                            print(f"native results delivered: slot={slot}, bytes={len(packet)}", flush=True)
                print(f"lobby connected: slot={slot}; awaiting menu admission", flush=True)
                while True:
                    message = front.read_frame(self.request)
                    print(f"lobby request: slot={slot}, opcode={message[0]:02x}, size={len(message)}", flush=True)
                    if message[0] == 0x28 and len(message) == 5:
                        with lock:
                            self.request.sendall(front.frame(b"\x37" + message[1:]))
                    elif message[:2] == b"\x21\x13" and len(message) == 6 and isinstance(registry, MatchRegistry):
                        with lock:
                            packet = registry.results_for(f"local-{slot + 1}", struct.unpack_from("<I", message, 2)[0])
                            if packet is not None:
                                self.request.sendall(front.frame(packet))
            finally:
                with lock:
                    if connections.get(session) is self.request:
                        del connections[session]
                        protocols.pop(session, None)
                        registry.lobby_disconnected(f"local-{slot + 1}")

    class Menu(BaseHTTPRequestHandler):
        def do_POST(self):
            if self.path != "/v1/menu":
                self.send_error(404)
                return
            auth = re.fullmatch(r"SRP-Native-021d ([0-9a-f]{8})",
                                self.headers.get("Authorization", ""))
            if not auth:
                self.send_error(401, "Native lobby sign-in required")
                return
            session = int(auth[1], 16)
            try:
                length = int(self.headers.get("Content-Length", "0"))
                if not 0 < length < 4096:
                    raise ValueError("invalid body length")
                fields = parse_qs(self.rfile.read(length).decode("ascii"),
                                  strict_parsing=True, max_num_fields=20)
                if any(len(v) != 1 for v in fields.values()):
                    raise ValueError("duplicate field")
                form = {k: v[0] for k, v in fields.items()}
            except (ValueError, UnicodeError):
                self.send_error(400)
                return
            with lock:
                if session not in connections:
                    self.send_error(401, "Native lobby is no longer connected")
                    return
                slot = front.STATE.slot(session)
                # Compatibility claim from the DLL on this live native session.
                # This prevents accidental incompatible admission; it is not
                # an anti-cheat attestation or an authentication credential.
                protocols[session] = self.headers.get("X-SRP-Match-Protocol", "")
                form["player"] = f"local-{slot + 1}"
                result = registry.dispatch(form)
            payload = json.dumps(result).encode("ascii")
            try:
                self.send_response(200)
                self.send_header("Content-Type", "application/json")
                self.send_header("Content-Length", str(len(payload)))
                self.end_headers()
                self.wfile.write(payload)
                self.wfile.flush()
            except (BrokenPipeError, ConnectionResetError):
                pass
            finally:
                # A disconnected HTTP caller may already have committed Start.
                # Admission is session-bound and happens once, independently of retries.
                if isinstance(registry, MatchRegistry):
                    registry.flush_redirects()
            print(f"menu request: slot={slot}, op={form.get('op')}, ok={result['ok']}", flush=True)

        def log_message(self, *_args):
            pass

    servers, started = [], []
    stop = threading.Event()
    previous_term = signal.signal(signal.SIGTERM, lambda *_args: stop.set())
    try:
        for port, handler in [(front.ARGS.login_port, front.Login),
                              (front.ARGS.lobby_port, Lobby),
                              (front.ARGS.messaging_port, messaging_handler(front, registry))]:
            servers.append(front.TCP(port, handler))
        servers.append(ThreadingHTTPServer(("127.0.0.1", front.ARGS.browser_port), front.Browser))
        servers.append(ThreadingHTTPServer(("127.0.0.1", args.base_port+4), Menu))
        for server in servers:
            threading.Thread(target=server.serve_forever, daemon=True).start()
            started.append(server)
        mode = "local match allocation" if args.match_server else "no gameplay"
        print(f"Native lobby fixture: login {args.base_port}, menu {args.base_port+4}; {mode}", flush=True)
        while not stop.wait(1):
            if isinstance(registry, MatchRegistry):
                registry.reap()
    except KeyboardInterrupt:
        pass
    finally:
        if isinstance(registry, MatchRegistry):
            registry.shutdown()
        for server in started:
            server.shutdown()
        for server in servers:
            server.server_close()
        front.STATE.close()
        if workspace is not None:
            workspace.close()
        signal.signal(signal.SIGTERM, previous_term)


if __name__ == "__main__":
    main()
