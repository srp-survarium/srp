# SPDX-License-Identifier: GPL-3.0-or-later
import concurrent.futures
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location("menu_fixture", Path(__file__).parents[1] / "tools/menu_fixture.py")
fixture = importlib.util.module_from_spec(spec)
spec.loader.exec_module(fixture)


class RoomContract(unittest.TestCase):
    def setUp(self):
        self.registry = fixture.Registry()
        self.sequence = 0

    def call(self, op, player="alice", **fields):
        self.sequence += 1
        return self.registry.dispatch(dict(v="1", id=str(self.sequence), player=player, op=op, **fields))

    def create(self):
        response = self.call("create", name="A match", map="rudnya", capacity="2")
        self.assertTrue(response["ok"], response)
        return response["result"]["room"]["id"]

    def test_final_slot_is_atomic(self):
        room = self.create()
        def join(index):
            return self.registry.dispatch(dict(v="1", id="race", player=f"player-{index}", op="join", match=room))
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
            results = list(pool.map(join, range(32)))
        self.assertEqual(sum(r["ok"] for r in results), 1)
        self.assertEqual(len(self.registry.rooms[room]["players"]), 2)

    def test_replay_does_not_create_twice_or_change_old_response(self):
        fields = dict(v="1", id="create", player="alice", op="create", name="A", map="rudnya", capacity="2")
        first = self.registry.dispatch(fields)
        room = first["result"]["room"]["id"]
        self.call("join", "bob", match=room)
        replay = self.registry.dispatch(fields)
        self.assertEqual(first, replay)
        self.assertEqual(replay["result"]["room"]["players"], ["alice"])
        self.assertEqual(len(self.registry.rooms), 1)
        self.assertFalse(self.registry.dispatch(dict(fields, name="Changed"))["ok"])

    def test_creator_departure_closes_room(self):
        room = self.create()
        self.call("join", "bob", match=room)
        self.assertTrue(self.call("leave", match=room)["ok"])
        self.assertFalse(self.call("room", "bob", match=room)["ok"])
        self.assertEqual(self.call("list")["result"]["rooms"], [])

    def test_ready_permissions_and_no_fake_game_admission(self):
        room = self.create()
        self.call("join", "bob", match=room)
        self.assertIn("creator", self.call("start", "bob", match=room)["error"])
        self.assertIn("ready", self.call("start", match=room)["error"])
        self.call("ready", match=room, ready="1")
        self.call("ready", "bob", match=room, ready="1")
        self.assertIn("not connected", self.call("start", match=room)["error"])
        self.assertEqual(self.registry.rooms[room]["state"], "waiting")

    def test_old_generation_and_nonmembers_are_rejected(self):
        room = self.create()
        self.assertFalse(self.call("ready", "stranger", match=room, ready="1")["ok"])
        replacement = fixture.Registry()
        response = replacement.dispatch(dict(v="1", id="1", player="alice", op="join", match=room))
        self.assertFalse(response["ok"])


if __name__ == "__main__":
    unittest.main()
