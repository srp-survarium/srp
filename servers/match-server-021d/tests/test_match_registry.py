# SPDX-License-Identifier: GPL-3.0-or-later
import concurrent.futures
from pathlib import Path
import sys
import struct
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
from match_registry import MatchRegistry, MatchProcess


class AllocationRetirement(unittest.TestCase):
    def process(self, status):
        # Exercise the status policy without spawning a child for each case.
        process = MatchProcess.__new__(MatchProcess)
        process.identity = ("abc", 1)
        process.query_status = lambda _path: status
        process.control = Path("/unused/control.sock")
        process.started = 1000
        return process

    def test_empty_admission_has_loading_grace_but_expires(self):
        process = self.process(("abc", 1, "waiting", 0))
        with patch("match_registry.time.monotonic", return_value=1119):
            self.assertFalse(process.retired())
        with patch("match_registry.time.monotonic", return_value=1120):
            self.assertTrue(process.retired())

    def test_partial_roster_gets_loading_grace_but_cannot_wait_forever(self):
        process = self.process(("abc", 1, "waiting", 1))
        with patch("match_registry.time.monotonic", return_value=1119):
            self.assertFalse(process.retired())
        with patch("match_registry.time.monotonic", return_value=1120):
            self.assertTrue(process.retired())

    def test_bootstrapping_playing_or_finished_peers_outlive_admission_deadline(self):
        for phase in ("starting", "running", "finished"):
            process = self.process(("abc", 1, phase, 1))
            with patch("match_registry.time.monotonic", return_value=9999):
                self.assertFalse(process.retired(), phase)

    def test_reset_generation_retires_without_waiting_for_a_lobby_return(self):
        process = self.process(("abc", 2, "waiting", 0))
        with patch("match_registry.time.monotonic", return_value=1001):
            self.assertTrue(process.retired())

    def test_missing_status_does_not_close_a_potentially_live_game(self):
        process = self.process(None)
        with patch("match_registry.time.monotonic", return_value=9999):
            self.assertFalse(process.retired())


class Process:
    def __init__(self, port):
        self.port = port
        self.exit_code = None
        self.stopped = False

    def poll(self):
        return self.exit_code

    def stop(self):
        self.stopped = True
        self.exit_code = 0


class MatchAllocation(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.connected = {"alice", "bob", "carol"}
        self.compatible = set(self.connected)
        self.sessions = {"alice": 101, "bob": 202, "carol": 303}
        self.launches = []
        self.redirects = []
        self.sequence = 0
        self.registry = MatchRegistry(self.sessions.__getitem__, self.connected.__contains__,
            self.compatible.__contains__,
            lambda *values: self.redirects.append(values), "/unused/server", self.directory.name,
            self.launch)
        self.addCleanup(self.registry.shutdown)

    def launch(self, executable, directory, sessions):
        process = Process(21000 + len(self.launches))
        self.launches.append((list(sessions), process))
        return process

    def call(self, op, player="alice", **fields):
        self.sequence += 1
        return self.registry.dispatch(dict(v="1", id=str(self.sequence), player=player, op=op, **fields))

    def room(self, player="alice"):
        result = self.call("create", player, name="Real match", map="school", capacity="2")
        self.assertTrue(result["ok"], result)
        return result["result"]["room"]["id"]

    def test_start_requires_owner_ready_and_connected_roster(self):
        room = self.room()
        self.call("join", "bob", match=room)
        self.assertFalse(self.call("start", "bob", match=room)["ok"])
        self.assertFalse(self.call("start", match=room)["ok"])
        self.call("ready", match=room, ready="1")
        self.call("ready", "bob", match=room, ready="1")
        self.connected.remove("bob")
        self.assertFalse(self.call("start", match=room)["ok"])
        self.assertEqual(self.launches, [])
        self.connected.add("bob")
        self.compatible.remove("bob")
        result = self.call("start", match=room)
        self.assertFalse(result["ok"])
        self.assertIn("SRP_MATCH_PROTOCOL=1", result["error"])
        self.assertEqual(self.launches, [])
        self.assertEqual(self.registry.pending_redirects, [])
        self.compatible.add("bob")
        self.assertTrue(self.call("start", match=room)["ok"])
        self.assertEqual(self.launches[0][0], [101, 202])
        self.registry.flush_redirects()
        self.assertEqual(self.redirects, [("alice", 21000, 0, 1), ("bob", 21000, 1, 1)])
        self.assertFalse(self.call("join", "carol", match=room)["ok"])

    def test_simultaneous_retry_allocates_and_redirects_once(self):
        room = self.room()
        self.call("ready", match=room, ready="1")
        request = dict(v="1", id="same-start", op="start", player="alice", match=room)
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
            results = list(pool.map(lambda _: self.registry.dispatch(request), range(20)))
        self.assertTrue(all(r == results[0] and r["ok"] for r in results))
        self.assertEqual(len(self.launches), 1)
        self.registry.flush_redirects()
        self.registry.flush_redirects()
        self.assertEqual(self.redirects, [("alice", 21000, 0, 1)])

    def test_failed_durable_order_reservation_never_launches_or_redirects(self):
        room = self.room()
        self.call("ready", match=room, ready="1")
        def failed():
            raise OSError("checkpoint unavailable")
        self.registry.next_order = failed
        result = self.call("start", match=room)
        self.assertFalse(result["ok"])
        self.assertEqual(self.launches, [])
        self.registry.flush_redirects()
        self.assertEqual(self.redirects, [])
        self.assertEqual(self.registry.rooms[room]["state"], "waiting")

    def test_results_survive_last_departure_and_follow_admitted_slots_and_orders(self):
        for order in (1, 2):
            room = self.room("carol")
            self.call("join", "alice", match=room)
            for player in ("carol", "alice"):
                self.call("ready", player, match=room, ready="1")
            self.assertTrue(self.call("start", "carol", match=room)["ok"])
            self.assertIsNone(self.registry.results_for("alice"))
            process = self.launches[-1][1]
            def results(slot):
                self.assertFalse(process.stopped)
                return b"\x36\x13\x01\0\0\0" + bytes([slot])
            process.results = results
            self.registry.flush_redirects()
            self.assertEqual(self.redirects[-2:], [("carol", process.port, 0, order), ("alice", process.port, 1, order)])
            for player, slot in (("carol", 0), ("alice", 1)):
                self.registry.lobby_connected(player)
                expected = b"\x36\x13" + struct.pack("<I", order) + bytes([slot])
                self.assertEqual(self.registry.results_for(player, order), expected)
                self.assertIsNone(self.registry.results_for(player, order - 1))
            self.assertTrue(process.stopped)
            self.assertEqual(self.registry.routes, {})
            self.assertIsNotNone(self.registry.results_for("carol", order))
            self.assertIsNone(self.registry.results_for("bob", order))

    def test_missing_or_malformed_results_do_not_prevent_cleanup(self):
        for packet in (None, b"", b"\x36\x13\x01\0\0\0", b"\x36\x13\x02\0\0\0x", b"x" * 4097):
            room = self.room()
            self.call("ready", match=room, ready="1")
            self.call("start", match=room)
            process = self.launches[-1][1]
            process.results = lambda slot: packet
            self.registry.lobby_connected("alice")
            self.assertTrue(process.stopped)
            self.assertIsNone(self.registry.results_for("alice"))

    def test_departure_preserves_others_then_frees_last_allocation(self):
        room = self.room()
        self.call("join", "bob", match=room)
        for player in ("alice", "bob"):
            self.call("ready", player, match=room, ready="1")
        self.call("start", match=room)
        self.registry.flush_redirects()
        self.registry.lobby_connected("alice")
        self.assertEqual(self.call("room", match=room)["code"], "room_unavailable")
        self.assertEqual(self.registry.rooms[room]["players"], ["bob"])
        self.assertEqual(self.registry.rooms[room]["owner"], "bob")
        self.assertFalse(self.launches[0][1].stopped)
        second = self.room("alice")
        self.call("ready", match=second, ready="1")
        self.call("start", match=second)
        self.assertEqual(self.launches[1][0], [101])
        self.assertNotEqual(self.launches[0][1].port, self.launches[1][1].port)
        self.registry.lobby_connected("bob")
        self.assertNotIn(room, self.registry.rooms)
        self.assertTrue(self.launches[0][1].stopped)
        self.assertIn(second, self.registry.rooms)
        self.assertEqual(self.call("room", "bob", match=room)["code"], "room_unavailable")

    def test_failed_launch_has_no_admission_and_failed_redirect_closes_match(self):
        room = self.room()
        self.call("ready", match=room, ready="1")
        def fail(*_args):
            raise OSError("test failure")
        self.registry.launcher = fail
        self.assertFalse(self.call("start", match=room)["ok"])
        self.assertEqual(self.registry.rooms[room]["state"], "waiting")
        self.assertEqual(self.registry.admitted, {})
        self.registry.launcher = self.launch
        self.assertTrue(self.call("start", match=room)["ok"])
        self.registry.redirect = fail
        self.registry.flush_redirects()
        self.assertNotIn(room, self.registry.rooms)
        self.assertEqual(self.registry.admitted, {})
        self.assertTrue(self.launches[0][1].stopped)

    def test_child_exit_clears_room_and_grants(self):
        room = self.room()
        self.call("ready", match=room, ready="1")
        self.call("start", match=room)
        self.launches[0][1].exit_code = 1
        self.registry.reap()
        self.assertEqual(self.registry.rooms, {})
        self.assertEqual(self.registry.admitted, {})
        self.registry.flush_redirects()
        self.assertEqual(self.redirects, [])

    def test_retired_child_saves_all_results_then_frees_capacity_without_lobby_return(self):
        room = self.room("carol")
        self.call("join", "alice", match=room)
        for player in ("carol", "alice"):
            self.call("ready", player, match=room, ready="1")
        self.assertTrue(self.call("start", "carol", match=room)["ok"])
        process = self.launches[-1][1]
        process.retired = lambda: True
        def results(slot):
            self.assertFalse(process.stopped)
            return b"\x36\x13\x01\0\0\0" + bytes([slot])
        process.results = results
        self.registry.reap()
        self.assertTrue(process.stopped)
        self.assertEqual(self.registry.processes, {})
        self.assertEqual(self.registry.rooms, {})
        self.assertEqual(self.registry.admitted, {})
        self.assertEqual(self.registry.routes, {})
        self.registry.flush_redirects()
        self.assertEqual(self.redirects, [])
        for player, slot in (("carol", 0), ("alice", 1)):
            self.registry.lobby_connected(player)
            self.assertEqual(self.registry.results_for(player, 1),
                             b"\x36\x13\x01\0\0\0" + bytes([slot]))
            self.assertIsNone(self.registry.results_for(player, 2))
        self.assertTrue(self.call("create", "alice", name="Next", map="school", capacity="2")["ok"])

    def test_expired_empty_child_cleans_up_without_fabricating_results(self):
        room = self.room()
        self.call("ready", match=room, ready="1")
        self.assertTrue(self.call("start", match=room)["ok"])
        process = self.launches[-1][1]
        process.retired = lambda: True
        process.results = lambda slot: None
        self.registry.reap()
        self.assertTrue(process.stopped)
        self.assertEqual(self.registry.processes, {})
        self.assertIsNone(self.registry.results_for("alice"))

    def test_waiting_disconnect_releases_ready_slot_and_creator_closes_room(self):
        room = self.room()
        self.call("join", "bob", match=room)
        self.call("ready", "bob", match=room, ready="1")
        self.registry.lobby_disconnected("bob")
        self.registry.lobby_disconnected("bob")  # Duplicate notification is harmless.
        self.assertEqual(self.registry.rooms[room]["players"], ["alice"])
        self.assertEqual(self.registry.rooms[room]["ready"], [])
        self.assertTrue(self.call("join", "carol", match=room)["ok"])
        self.registry.lobby_disconnected("alice")
        self.assertNotIn(room, self.registry.rooms)
        self.assertEqual(self.call("room", "carol", match=room)["code"], "room_unavailable")
        self.assertTrue(self.call("create", "carol", name="Next", map="school", capacity="2")["ok"])
        self.assertEqual(self.launches, [])

    def test_lobby_handoff_does_not_release_started_membership(self):
        room = self.room()
        self.call("join", "bob", match=room)
        for player in ("alice", "bob"):
            self.call("ready", player, match=room, ready="1")
        self.call("start", match=room)
        self.registry.flush_redirects()
        for player in ("alice", "bob"):
            self.connected.remove(player)
            self.registry.lobby_disconnected(player)
        self.assertEqual(self.registry.rooms[room]["players"], ["alice", "bob"])
        self.assertEqual(self.registry.admitted, {"alice": room, "bob": room})
        self.assertFalse(self.launches[0][1].stopped)
        self.assertEqual(len(self.redirects), 2)


if __name__ == "__main__":
    unittest.main()
