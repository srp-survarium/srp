#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Loopback-only menu fixture. No authentication, allocation, or gameplay.

Models room operations for testing the actual UI and asynchronous DLL bridge.
It must never be advertised as a playable server or exposed on a public port.
"""
import argparse
import copy
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import secrets
import threading
import time
from urllib.parse import parse_qs


class RoomUnavailable(ValueError):
    """The caller's displayed room is no longer accessible."""


class Registry:
    def __init__(self):
        self.lock = threading.Lock()
        self.rooms = {}
        self.responses = {}
        self.generation = secrets.token_hex(8)
        self.maps = ["rudnya", "school"]

    def lobby_disconnected(self, player):
        """Release waiting-room reservations on native lobby disconnect.

        A playing client normally closes its lobby transport while loading.
        Its membership belongs to the match lifecycle, not this connection.
        """
        with self.lock:
            for room_id, room in list(self.rooms.items()):
                if room["state"] != "waiting" or player not in room["players"]:
                    continue
                if room["owner"] == player:
                    del self.rooms[room_id]
                else:
                    room["players"].remove(player)
                    if player in room["ready"]:
                        room["ready"].remove(player)

    def dispatch(self, form):
        with self.lock:
            return copy.deepcopy(self._dispatch(form))

    def _dispatch(self, form):
        op, player, request_id = (form.get(k, "") for k in ("op", "player", "id"))
        if form.get("v") != "1" or not player or len(player) > 40 or not request_id:
            return {"ok": False, "error": "Invalid fixture request."}
        key = (player, request_id)
        previous = self.responses.get(key)
        if previous:
            return copy.deepcopy(previous[1]) if previous[0] == form else {
                "ok": False, "error": "Request ID reused with different parameters."}
        try:
            result = self.operate(op, player, form)
            answer = {"ok": True, "result": result}
        except ValueError as error:
            answer = {"ok": False, "error": str(error)}
            if isinstance(error, RoomUnavailable):
                answer["code"] = "room_unavailable"
        # A bounded fixture lifetime; production needs session-aware retention.
        if len(self.responses) >= 4096:
            self.responses.clear()
        self.responses[key] = (dict(form), copy.deepcopy(answer))
        return answer

    def operate(self, op, player, form):
        if op == "capabilities":
            return {"version": 1, "fixture": True, "player": player, "maps": self.maps,
                    "modes": ["team_deathmatch"], "max_players": 16}
        if op == "list":
            return {"rooms": list(self.rooms.values())[:100]}
        if op == "create":
            if any(player in r["players"] for r in self.rooms.values()):
                raise ValueError("Leave your current room first.")
            name = form.get("name", "").strip()
            map_id = form.get("map", "")
            try:
                capacity = int(form.get("capacity", ""))
            except ValueError:
                raise ValueError("Capacity must be a number.") from None
            if not 1 <= len(name) <= 48 or any(ord(c) < 32 for c in name):
                raise ValueError("Use a room name of 1–48 characters.")
            if map_id not in self.maps or not 2 <= capacity <= 16:
                raise ValueError("Unsupported map or capacity.")
            if len(self.rooms) >= 100:
                raise ValueError("Fixture room limit reached.")
            ident = self.generation + "-" + secrets.token_hex(4)
            room = {"id": ident, "name": name, "map": map_id, "capacity": capacity,
                    "owner": player, "players": [player], "ready": [], "state": "waiting"}
            self.rooms[ident] = room
            return {"room": room}
        room = self.rooms.get(form.get("match", ""))
        if room is None:
            raise RoomUnavailable("This room has closed. Refresh the browser.")
        if op == "join":
            if room["state"] != "waiting":
                raise ValueError("This room has already started.")
            if player not in room["players"]:
                if any(player in r["players"] for r in self.rooms.values()):
                    raise ValueError("Leave your current room first.")
                if len(room["players"]) >= room["capacity"]:
                    raise ValueError("This room is full.")
                room["players"].append(player)
        elif player not in room["players"]:
            raise RoomUnavailable("You are not a member of this room.")
        elif op == "leave":
            if room["owner"] == player:
                del self.rooms[room["id"]]
            else:
                room["players"].remove(player)
                if player in room["ready"]:
                    room["ready"].remove(player)
            return {"left": True}
        elif op == "ready":
            if room["state"] != "waiting":
                raise ValueError("Readiness can only change before starting.")
            if form.get("ready") not in ("0", "1"):
                raise ValueError("Invalid readiness value.")
            if player in room["ready"]:
                room["ready"].remove(player)
            if form["ready"] == "1":
                room["ready"].append(player)
        elif op == "start":
            if room["owner"] != player:
                raise ValueError("Only the creator can start this room.")
            if room["state"] != "waiting" or set(room["players"]) != set(room["ready"]):
                raise ValueError("All players must be ready.")
            # Explicitly no fake endpoint or pretend successful game admission.
            raise ValueError("Menu fixture only: gameplay allocation is not connected yet.")
        elif op != "room":
            raise ValueError("Unknown operation.")
        return {"room": room}


def handler(registry, delay):
    class Handler(BaseHTTPRequestHandler):
        def do_POST(self):
            if self.path != "/v1/menu":
                self.send_error(404)
                return
            if self.headers.get("Authorization") is not None:
                self.send_error(401, "This preview fixture cannot validate native lobby sessions")
                return
            try:
                length = int(self.headers.get("Content-Length", "0"))
                if not 0 < length < 4096:
                    raise ValueError("Invalid body length")
                fields = parse_qs(self.rfile.read(length).decode("ascii"),
                                  strict_parsing=True, max_num_fields=20)
                if any(len(v) != 1 for v in fields.values()):
                    raise ValueError("Duplicate field")
                form = {k: v[0] for k, v in fields.items()}
                time.sleep(delay)
                response = registry.dispatch(form)
                payload = json.dumps(response, ensure_ascii=True).encode("ascii")
            except (ValueError, UnicodeError):
                self.send_error(400)
                return
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(payload)))
            self.end_headers()
            try:
                self.wfile.write(payload)
            except (BrokenPipeError, ConnectionResetError):
                pass

        def log_message(self, *_args):
            pass
    return Handler


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--port", type=int, default=19022)
    parser.add_argument("--delay", type=float, default=0)
    args = parser.parse_args()
    if args.delay < 0:
        parser.error("delay must be nonnegative")
    server = ThreadingHTTPServer(("127.0.0.1", args.port), handler(Registry(), args.delay))
    print(f"Menu fixture: http://127.0.0.1:{server.server_port}/v1/menu", flush=True)
    server.serve_forever()
