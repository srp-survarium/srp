# SPDX-License-Identifier: GPL-3.0-or-later
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).parents[1] / "tools"))
from match_registry import MatchProcess, MatchRegistry


class Child:
    def __init__(self, _exe, _directory, sessions, accounts, all_accounts):
        self.accounts = accounts + [a for a in all_accounts if a not in accounts]
        self.identity = ("abc", 1)
        self.control = Path("unused")
        self.port = 12001
        self.stopped = False
        self.mask = (1 << len(sessions)) - 1
        self.query_status = lambda _: (*self.identity, "running", self.mask)
        self.changes = []
        self.next_result = "ok"

    def poll(self):
        return 0 if self.stopped else None

    def stop(self):
        self.stopped = True

    def change_admission(self, operation, slot, session):
        self.changes.append((operation, slot, session))
        if self.next_result == "ok" and operation == "revoke":
            self.mask &= ~(1 << slot)
        return self.next_result


class LateAdmission(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.redirects = []
        self.sequence = 0
        self.registry = MatchRegistry(lambda p: int(p[6:]) * 101, lambda p: True,
            lambda p: True, lambda *r: self.redirects.append(r), "/unused/server",
            self.directory.name, Child, identity=lambda p: int(p[6:]), all_accounts=[1, 2, 3, 4])
        self.addCleanup(self.registry.shutdown)
        self.room = self.call("create", "local-3", name="Live", map="school", capacity="2")["result"]["room"]["id"]
        self.call("ready", "local-3", match=self.room, ready="1")
        self.call("start", "local-3", match=self.room)
        self.registry.flush_redirects()
        self.child = self.registry.processes[self.room]

    def call(self, op, player, **fields):
        self.sequence += 1
        return self.registry.dispatch(dict(v="1", id=str(self.sequence), op=op, player=player, **fields))

    def test_late_join_uses_reserved_identity_but_enforces_room_capacity(self):
        answer = self.call("join", "local-1", match=self.room)
        self.assertTrue(answer["ok"], answer)
        self.assertEqual(self.child.changes, [("admit", 1, 101)])
        self.registry.flush_redirects()
        self.assertEqual(self.redirects[-1], ("local-1", 12001, 1, 1))
        self.assertEqual(self.child.accounts, [3, 1, 2, 4])
        self.assertFalse(self.call("join", "local-2", match=self.room)["ok"])
        self.assertEqual(len(self.child.changes), 1)

    def test_lobby_return_revokes_old_transport_then_rejoin_keeps_identity_and_other_player(self):
        self.call("join", "local-1", match=self.room)
        self.child.mask = 3
        self.registry.lobby_connected("local-1")
        self.assertEqual(self.child.changes[-1], ("revoke", 1, 101))
        self.assertNotIn("local-1", self.registry.admitted)
        self.assertFalse(self.child.stopped)
        self.assertTrue(self.call("join", "local-1", match=self.room)["ok"])
        self.assertEqual(self.child.changes[-1], ("admit", 1, 101))
        self.assertEqual(self.registry.routes["local-1"], (self.room, 1, 1))

    def test_lost_confirmation_reserves_capacity_until_retry_or_expiry(self):
        self.child.next_result = None
        with patch("match_registry.time.monotonic", return_value=100):
            self.assertFalse(self.call("join", "local-1", match=self.room)["ok"])
        self.assertIn("local-1", self.registry.admitted)
        self.assertFalse(self.call("join", "local-2", match=self.room)["ok"])
        self.child.next_result = "ok"
        with patch("match_registry.time.monotonic", return_value=221):
            self.registry.reap()
        self.assertNotIn("local-1", self.registry.admitted)
        self.assertEqual(self.child.changes[-1], ("revoke", 1, 101))
        self.assertFalse(self.child.stopped)

    def test_connected_player_outlives_load_deadline_and_udp_departure_frees_slot(self):
        self.call("join", "local-1", match=self.room)
        self.child.mask = 3
        self.registry.reap()
        self.assertNotIn("local-1", self.registry.loading)
        with patch("match_registry.time.monotonic", return_value=10**12):
            self.registry.reap()
        self.assertIn("local-1", self.registry.admitted)
        self.child.mask = 1
        self.registry.reap()
        self.assertNotIn("local-1", self.registry.admitted)
        self.assertFalse(self.child.stopped)

    def test_failed_late_redirect_releases_only_that_player(self):
        self.call("join", "local-1", match=self.room)
        def disconnected(*_args):
            raise OSError("connection gone")
        self.registry.redirect = disconnected
        self.registry.flush_redirects()
        self.assertEqual(self.registry.rooms[self.room]["players"], ["local-3"])
        self.assertFalse(self.child.stopped)

    def test_failed_repeat_join_does_not_remove_an_existing_member(self):
        self.call("join", "local-1", match=self.room)
        self.child.mask = 3
        self.child.next_result = "occupied"
        self.assertFalse(self.call("join", "local-1", match=self.room)["ok"])
        self.assertIn("local-1", self.registry.admitted)

    def test_initial_member_departure_between_polls_has_bounded_reservation(self):
        self.registry.shutdown()
        room = self.call("create", "local-3", name="Initial pair", map="school", capacity="2")["result"]["room"]["id"]
        self.call("join", "local-1", match=room)
        for player in ("local-3", "local-1"):
            self.call("ready", player, match=room, ready="1")
        with patch("match_registry.time.monotonic", return_value=100):
            self.call("start", "local-3", match=room)
        child = self.registry.processes[room]
        child.mask = 1  # Second initial player departed before any status poll.
        with patch("match_registry.time.monotonic", return_value=221):
            self.registry.reap()
        self.assertNotIn("local-1", self.registry.admitted)
        self.assertIn("local-3", self.registry.admitted)
        self.assertFalse(child.stopped)


class AdmissionRetry(unittest.TestCase):
    def test_lost_reply_reuses_revision_and_revoke_supersedes_pending_grant(self):
        process = MatchProcess.__new__(MatchProcess)
        process.identity = ("abc", 1)
        process.control = Path("unused")
        process.accounts = [3, 1]
        process.pending = {}
        process.revision = 0
        calls = []
        def query(*args):
            calls.append(args)
            return None
        process.query_admission = query
        self.assertIsNone(process.change_admission("admit", 1, 101))
        self.assertIsNone(process.change_admission("admit", 1, 101))
        self.assertEqual(calls[0], calls[1])
        process.change_admission("revoke", 1, 101)
        self.assertGreater(calls[2][3], calls[1][3])


if __name__ == "__main__":
    unittest.main()
