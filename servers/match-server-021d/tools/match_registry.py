# SPDX-License-Identifier: GPL-3.0-or-later
"""Local match allocation for the retail menu integration service.

Uses the integrated server's explicit SRP1 protocol. Accounts/loadouts remain
development fixtures; every started room gets a real, isolated UDP server.
"""
import os
from pathlib import Path
import socket
import subprocess
import struct
import threading
import time

from menu_fixture import Registry, RoomUnavailable


class MatchProcess:
    ADMISSION_TIMEOUT_SECONDS = 120

    def __init__(self, executable, directory, sessions, match_seconds=None,
                 query_status=None, query_results=None):
        directory.mkdir(parents=True, exist_ok=False)
        self.sessions_file = directory / "sessions"
        with os.fdopen(os.open(self.sessions_file, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600), "w") as out:
            for slot, session in enumerate(sessions):
                out.write(f"{session} {slot}\n")
        # The child currently accepts a port, not an inherited socket. If
        # another process wins this bind race, readiness fails before redirects.
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as reservation:
            reservation.bind(("127.0.0.1", 0))
            self.port = reservation.getsockname()[1]
        self.ready = threading.Event()
        self.listening = False
        self.process = None
        self.reader = None
        self.identity = None
        self.control = directory / "control.sock"
        self.query_results = query_results
        self.query_status = query_status
        self.started = time.monotonic()
        try:
            command = [str(executable), "--protocol", "srp1",
                       str(self.sessions_file), str(self.port), str(len(sessions))]
            if match_seconds is not None or query_status is not None:
                command.append(str(match_seconds if match_seconds is not None else 600))
            if query_status is not None:
                command.append(str(self.control))
            self.process = subprocess.Popen(
                command,
                stdin=subprocess.DEVNULL, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                text=True, errors="replace", bufsize=1)
            self.reader = threading.Thread(target=self._read, args=(directory / "server.log",), daemon=True)
            self.reader.start()
            self.ready.wait(3)
            if not self.listening or self.process.poll() is not None:
                raise ValueError("The match server could not start. Try again.")
            if query_status is not None:
                status = query_status(self.control)
                if status is None or status[2:] != ("waiting", 0):
                    raise ValueError("The match server did not confirm a fresh generation")
                self.identity = status[:2]
        except BaseException:
            self.stop()
            raise

    def _read(self, path):
        try:
            with path.open("w") as log:
                for line in self.process.stdout:
                    log.write(line)
                    log.flush()
                    if line.startswith(f"v0.21d test server on 127.0.0.1:{self.port},"):
                        self.listening = line.rstrip().endswith(", protocol=srp1")
                        self.ready.set()
        finally:
            self.ready.set()

    def poll(self):
        return self.process.poll()

    def retired(self):
        """Native allocations own one generation; community processes may reuse it.

        Keep a generous initial loading grace for the complete starting roster.
        An unavailable status reply is not evidence that a live game is empty.
        """
        if self.identity is None or self.query_status is None:
            return False
        status = self.query_status(self.control)
        if status is None:
            return False
        if status[:2] != self.identity:
            return True
        return (status[2] == "waiting"
                and time.monotonic() - self.started >= self.ADMISSION_TIMEOUT_SECONDS)

    def results(self, slot):
        if self.identity is not None and self.query_results is not None:
            return self.query_results(self.control, self.identity, slot)
        return None

    def stop(self):
        if self.process is not None:
            if self.process.poll() is None:
                self.process.terminate()
                try:
                    self.process.wait(2)
                except subprocess.TimeoutExpired:
                    self.process.kill()
                    self.process.wait()
            if self.reader is not None:
                self.reader.join(timeout=1)
            if self.process.stdout is not None:
                self.process.stdout.close()
        self.sessions_file.unlink(missing_ok=True)
        self.control.unlink(missing_ok=True)


class MatchRegistry(Registry):
    """All methods run under the shared lobby/registry RLock.

    sessions resolves authenticated public player IDs; connected checks the
    native lobby, and redirect sends its stock match-admission notification.
    These callbacks never derive authorization from HTTP form fields.
    """
    def __init__(self, sessions, connected, compatible, redirect, executable, work, launcher=MatchProcess, next_order=None):
        super().__init__()
        self.lock = threading.RLock()
        self.maps = ["school"]
        self.sessions = sessions
        self.connected = connected
        self.compatible = compatible
        self.redirect = redirect
        self.executable = Path(executable).resolve()
        self.work = Path(work).resolve()
        self.launcher = launcher
        self.next_order = next_order
        self.processes = {}
        self.admitted = {}
        self.routes = {}
        self.completed = {}
        self.pending_redirects = []
        self.attempt = 0

    def operate(self, op, player, form):
        self.reap()
        if op == "capabilities":
            return {"version": 1, "fixture": False, "local_test": True,
                    "player": player, "maps": self.maps, "modes": ["battery_hunt"],
                    "mode_label": "Battery hunt", "max_players": 16,
                    "late_join": False}
        room = self.rooms.get(form.get("match", ""))
        if op == "start":
            if room is None:
                raise RoomUnavailable("This room has closed. Refresh the browser.")
            if room["owner"] != player:
                raise ValueError("Only the creator can start this room.")
            if room["state"] != "waiting" or set(room["players"]) != set(room["ready"]):
                raise ValueError("All players must be ready.")
            if len(self.processes) >= 8:
                raise ValueError("All match servers are busy. Try again later.")
            if any(not self.connected(p) for p in room["players"]):
                raise ValueError("A player disconnected. Everyone must be in the lobby.")
            if any(not self.compatible(p) for p in room["players"]):
                raise ValueError("Every player must enable SRP_MATCH_PROTOCOL=1 and restart the game.")
            grants = [self.sessions(p) for p in room["players"]]
            if self.next_order is None:
                if self.attempt >= 0xfffffffe:
                    raise ValueError("Match order IDs exhausted.")
                self.attempt += 1
            else:
                try:
                    self.attempt = self.next_order()
                except OSError:
                    raise ValueError("Could not save match admission. Restart the local service.") from None
            try:
                process = self.launcher(self.executable,
                    self.work / f"{room['id']}-{self.attempt}", grants)
            except (OSError, ValueError) as error:
                raise ValueError("The match server could not start. Try again.") from error
            self.processes[room["id"]] = process
            room["state"] = "playing"
            for slot, member in enumerate(room["players"]):
                self.admitted[member] = room["id"]
                self.routes[member] = (room["id"], slot, self.attempt)
                self.completed.pop(member, None)
                self.pending_redirects.append((member, room["id"], process.port, slot % 2, self.attempt))
            return {"room": room}
        if op == "leave" and room and room["state"] != "waiting":
            raise ValueError("Use Leave match in the game's options menu.")
        return super().operate(op, player, form)

    def flush_redirects(self):
        with self.lock:
            pending, self.pending_redirects = self.pending_redirects, []
            for player, room_id, port, team, match_id in pending:
                if self.admitted.get(player) != room_id:
                    continue
                try:
                    self.redirect(player, port, team, match_id)
                except (OSError, ValueError):
                    # Some earlier players may already be loading. Closing this
                    # allocation lets them reconnect; never relabel it waiting.
                    self.close_room(room_id)

    def lobby_connected(self, player):
        with self.lock:
            room_id = self.admitted.pop(player, None)
            room = self.rooms.get(room_id)
            if room is None:
                return
            route = self.routes.pop(player, None)
            process = self.processes.get(room_id)
            self.retain_results(player, route, process)
            room["players"].remove(player)
            if player in room["ready"]:
                room["ready"].remove(player)
            if not room["players"]:
                self.close_room(room_id)
            elif room["owner"] == player:
                room["owner"] = room["players"][0]

    def retain_results(self, player, route, process):
        if route and process and callable(getattr(process, "results", None)):
            packet = process.results(route[1])
            if (isinstance(packet, bytes) and 6 < len(packet) <= 4096
                    and packet[:6] == b"\x36\x13\x01\x00\x00\x00"):
                # The server's local fixture uses ID 1. Only replace its
                # verified order field with the ID used for this admission.
                self.completed[player] = (route[2], packet[:2] + struct.pack("<I", route[2]) + packet[6:])

    def results_for(self, player, match_id=None):
        with self.lock:
            result = self.completed.get(player)
            if result and (match_id is None or match_id == result[0]):
                return result[1]
            return None

    def chat_memberships(self):
        """Snapshot authenticated room membership; subscriptions grant nothing."""
        with self.lock:
            live = {room for room, process in self.processes.items()
                    if process.poll() is None}
            return {player: (room, order, slot % 2)
                    for player, (room, slot, order) in self.routes.items()
                    if room in live and self.admitted.get(player) == room}

    def close_room(self, room_id):
        self.rooms.pop(room_id, None)
        process = self.processes.pop(room_id, None)
        if process is not None:
            process.stop()
        self.admitted = {p: r for p, r in self.admitted.items() if r != room_id}
        self.routes = {p: r for p, r in self.routes.items() if r[0] != room_id}
        self.pending_redirects = [r for r in self.pending_redirects if r[1] != room_id]

    def reap(self):
        with self.lock:
            for room_id, process in list(self.processes.items()):
                if process.poll() is not None:
                    self.close_room(room_id)
                elif callable(getattr(process, "retired", None)) and process.retired():
                    # The last UDP departure advances the child's generation
                    # even when nobody returns to the lobby. Preserve the old
                    # generation's results before reclaiming this allocation.
                    for player, route in list(self.routes.items()):
                        if route[0] == room_id:
                            self.retain_results(player, route, process)
                    self.close_room(room_id)

    def shutdown(self):
        with self.lock:
            for room_id in list(self.processes):
                self.close_room(room_id)
