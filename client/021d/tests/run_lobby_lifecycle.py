#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise native lobby disconnects and allocator shutdown over real sockets.

Uses an isolated fixture process and locally supplied server/certificate inputs.
No game clients or existing services are touched. Test accounts are disposable.
"""
import argparse
import http.client
import json
from pathlib import Path
import signal
import socket
import ssl
import struct
import subprocess
import sys
import time
from urllib.parse import urlencode


def exact(sock, count):
    data = bytearray()
    while len(data) < count:
        chunk = sock.recv(count - len(data))
        if not chunk:
            raise AssertionError("Unexpected connection close")
        data.extend(chunk)
    return bytes(data)


def read_frame(sock):
    length = exact(sock, 1)[0]
    if not length:
        length = struct.unpack("<H", exact(sock, 2))[0]
    return exact(sock, length)


def available_ports():
    # Reserve a consecutive range while checking it. The fixture still has to
    # win the subsequent bind race and announce readiness before testing.
    for base in range(22000, 29000, 5):
        held = []
        try:
            for port in range(base, base + 5):
                sock = socket.socket()
                held.append(sock)
                sock.bind(("127.0.0.1", port))
            return base
        except OSError:
            pass
        finally:
            for sock in held:
                sock.close()
    raise RuntimeError("No available local service port range")


def until(check, description, timeout=5):
    deadline = time.monotonic() + timeout
    while True:
        if check():
            return
        if time.monotonic() >= deadline:
            raise AssertionError("Timed out: " + description)
        time.sleep(.05)


def login(base, account):
    # Only the isolated disposable fixture: the retail protocol negotiates TLS
    # after its plaintext version exchange and requires legacy TLS settings.
    with socket.create_connection(("127.0.0.1", base), timeout=3) as raw:
        raw.sendall(b"\x01" + bytes([len(account)]) + account
                    + b"0.21d".ljust(12, b"\0") + bytes(5))
        assert exact(raw, 1) == b"\x0b"
        context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
        context.check_hostname = False
        context.verify_mode = ssl.CERT_NONE
        context.set_ciphers("ALL:@SECLEVEL=0")
        with context.wrap_socket(raw, server_hostname="localhost") as secure:
            secure.sendall(b"\x07fixture")
            assert exact(secure, 1) == b"\x08"
            exact(secure, exact(secure, 1)[0])  # Browser host.
            exact(secure, exact(secure, 1)[0])  # Browser path.
            session = struct.unpack("<I", exact(secure, 4))[0]
            exact(secure, 12)  # Lobby and messaging addresses.
            return session


def connect_lobby(base, session):
    sock = socket.create_connection(("127.0.0.1", base + 1), timeout=3)
    sock.sendall(b"\x0b\x26" + struct.pack("<I", session) + bytes(6))
    assert read_frame(sock) == b"\x30\x00"
    return sock


def run(args, work):
    base = available_ports()
    log_path = work / "lifecycle-service.log"
    matches = work / "matches"
    script = Path(__file__).resolve().parents[1] / "tools/lobby_fixture.py"
    command = [sys.executable, "-u", str(script), "--front-door", str(args.front_door.resolve()),
               "--cert", str(args.cert.resolve()), "--key", str(args.key.resolve()),
               "--base-port", str(base), "--match-server", str(args.match_server.resolve()),
               "--match-work", str(matches), "--require-recovery", "--match-results"]
    sockets = []
    sequence = 0

    def call(session, op, **fields):
        nonlocal sequence
        sequence += 1
        body = urlencode(dict(v="1", id=str(sequence), op=op, **fields))
        connection = http.client.HTTPConnection("127.0.0.1", base + 4, timeout=4)
        try:
            connection.request("POST", "/v1/menu", body, {
                "Authorization": f"SRP-Native-021d {session:08x}",
                "X-SRP-Match-Protocol": "SRP1-48-R1"})
            response = connection.getresponse()
            assert response.status == 200, response.status
            return json.loads(response.read())
        finally:
            connection.close()

    def accepted(session, op, **fields):
        answer = call(session, op, **fields)
        assert answer["ok"], answer
        return answer["result"]

    def lobby(session):
        sock = connect_lobby(base, session)
        sockets.append(sock)
        return sock

    with log_path.open("w") as log:
        service = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
        try:
            def ready():
                if service.poll() is not None:
                    raise AssertionError("Fixture failed to start; see " + str(log_path))
                return "Native lobby fixture:" in log_path.read_text()
            until(ready, "fixture readiness")
            alice, bob, carol = [login(base, account) for account in
                                  (b"lifecycle-alice", b"lifecycle-bob", b"lifecycle-carol")]
            a, b, c = [lobby(session) for session in (alice, bob, carol)]
            room = accepted(alice, "create", name="Departure", map="school", capacity=2)["room"]["id"]
            accepted(bob, "join", match=room)
            accepted(bob, "ready", match=room, ready=1)
            # Retail 0x27 cancels a native matchmaking order; it is not a ping
            # and cannot cancel an SRP menu reservation. Only 0x28 is echoed.
            a.sendall(b"\x05\x27\x11\x22\x33\x44\x05\x28\x55\x66\x77\x88")
            assert read_frame(a) == b"\x37\x55\x66\x77\x88"
            retained = accepted(alice, "room", match=room)["room"]
            assert len(retained["players"]) == 2 and retained["ready"] == ["local-2"]
            print("PASS: cancellation leaves the room intact; only native 0x28 gets ping reply 0x37", flush=True)
            b.close()
            until(lambda: len(accepted(alice, "room", match=room)["room"]["players"]) == 1,
                  "disconnected member reservation removal")
            assert accepted(alice, "room", match=room)["room"]["ready"] == []
            accepted(carol, "join", match=room)
            print("PASS: disconnected ready member frees the final slot", flush=True)

            b = lobby(bob)
            separate = accepted(bob, "create", name="Independent", map="school", capacity=2)["room"]["id"]
            replacement = lobby(alice)
            a.close()
            # The old handler must actually finish before checking that it did
            # not remove the replacement connection or its room membership.
            until(lambda: log_path.read_text().count("Lobby: EOFError:") >= 2,
                  "superseded lobby handler exit")
            assert len(accepted(alice, "room", match=room)["room"]["players"]) == 2
            replacement.close()
            until(lambda: call(carol, "room", match=room).get("code") == "room_unavailable",
                  "creator disconnect closes the waiting room")
            accepted(bob, "room", match=separate)
            print("PASS: old socket cannot evict its replacement; creator disconnect closes only its room", flush=True)

            active = accepted(carol, "create", name="Handoff", map="school", capacity=2)["room"]["id"]
            accepted(carol, "ready", match=active, ready=1)
            accepted(carol, "start", match=active)
            redirect = read_frame(c)
            assert redirect[0] == 0x33
            host_length = redirect[1]
            match_port = struct.unpack_from("<H", redirect, 2 + host_length)[0]
            c.close()
            until(lambda: log_path.read_text().count("Lobby: EOFError:") >= 4,
                  "normal match-loading lobby handoff")
            rooms = accepted(bob, "list")["rooms"]
            assert any(r["id"] == active and r["state"] == "playing" and len(r["players"]) == 1
                       for r in rooms)
            assert len(list(matches.glob("*/sessions"))) == 1
            server_logs = list(matches.glob("*/server.log"))
            assert len(server_logs) == 1 and ", protocol=srp1" in server_logs[0].read_text()
            assert len(list(matches.glob("*/control.sock"))) == 1
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as probe:
                try:
                    probe.bind(("127.0.0.1", match_port))
                except OSError:
                    pass
                else:
                    raise AssertionError("Allocated match is not listening")
            print("PASS: real allocated server and grants survive the loading handoff", flush=True)

            service.send_signal(signal.SIGTERM)
            assert service.wait(timeout=10) == 0
            assert not list(matches.glob("*/sessions")), "Session grants were not removed"
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as probe:
                probe.bind(("127.0.0.1", match_port))
            print("PASS: SIGTERM releases the match server socket and deletes grants", flush=True)
        finally:
            for sock in sockets:
                sock.close()
            if service.poll() is None:
                service.terminate()
                try:
                    service.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    service.kill()
                    service.wait()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--front-door", required=True, type=Path)
    parser.add_argument("--match-server", required=True, type=Path)
    parser.add_argument("--cert", required=True, type=Path)
    parser.add_argument("--key", required=True, type=Path)
    parser.add_argument("--work", required=True, type=Path)
    args = parser.parse_args()
    args.work.mkdir(parents=True, exist_ok=False)
    run(args, args.work.resolve())


if __name__ == "__main__":
    main()
