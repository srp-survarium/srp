# SPDX-License-Identifier: GPL-3.0-or-later
import concurrent.futures
import json
from pathlib import Path
import sqlite3
import sys
import tempfile
import unittest
import uuid

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from store import Conflict, Invalid, Store


class StoreTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.store = Store(Path(self.temp.name) / 'test.sqlite3')
        self.store.initialize()
        self.run_command('import_catalog', entries=[
            {'key': key, 'kind': kind, 'name': key} for key, kind in
            [('rifle', 'item'), ('silver', 'currency'), ('school', 'map'),
             ('battery', 'mode'), ('season-1', 'season'), ('scavengers', 'faction')]],
            tracks=[{'key': 'test', 'name': 'Test progression', 'levels': [
                {'level': 1, 'min_xp': 0}, {'level': 2, 'min_xp': 100}, {'level': 3, 'min_xp': 300}]}])
        self.alice = self.run_command('create_account', username='alice')['account_id']
        self.bob = self.run_command('create_account', username='bob')['account_id']

    def run_command(self, action, **kwargs):
        return self.store.command({'request_id': str(uuid.uuid4()), 'action': action, **kwargs})

    def test_persistence_restart_and_migration_idempotence(self):
        other = Store(self.store.path)
        other.initialize()
        self.assertEqual(other.account(self.alice)['username'], 'alice')
        with other.connection() as db:
            self.assertEqual(db.execute('PRAGMA foreign_key_check').fetchall(), [])
            self.assertEqual(db.execute('PRAGMA user_version').fetchone()[0], 1)

    def test_concurrent_initialization(self):
        fresh = Store(Path(self.temp.name) / 'fresh.sqlite3')
        with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
            list(pool.map(lambda _: fresh.initialize(), range(3)))
        self.assertEqual(fresh.catalog(), [])

    def test_duplicate_grant_and_conflicting_replay(self):
        command = {'request_id': 'same', 'action': 'grant_item', 'account_id': self.alice, 'item_key': 'rifle'}
        first = self.store.command(command)
        self.assertEqual(first, self.store.command(command))
        self.assertEqual(len(self.store.account(self.alice)['items']), 1)
        with self.assertRaises(Conflict):
            self.store.command({**command, 'quantity': 2})

    def test_concurrent_duplicate_rewards(self):
        command = {'request_id': 'reward', 'action': 'wallet', 'account_id': self.alice,
                   'currency_key': 'silver', 'delta': 10, 'reason': 'test'}
        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
            results = list(pool.map(lambda _: self.store.command(command), range(8)))
        self.assertTrue(all(result == {'balance': 10} for result in results))
        self.assertEqual(self.store.account(self.alice)['wallets'][0]['balance'], 10)

    def test_equipment_ownership_and_unique_slot(self):
        item = self.run_command('grant_item', account_id=self.alice, item_key='rifle')['item_id']
        bob_loadout = self.run_command('create_loadout', account_id=self.bob, name='Primary')['loadout_id']
        with self.assertRaises(Conflict):
            self.run_command('equip', account_id=self.bob, loadout_id=bob_loadout, slot='weapon1', item_id=item)
        own = self.run_command('create_loadout', account_id=self.alice, name='Primary')['loadout_id']
        self.run_command('equip', account_id=self.alice, loadout_id=own, slot='weapon1', item_id=item)
        with self.assertRaises(Conflict):
            self.run_command('equip', account_id=self.alice, loadout_id=own, slot='weapon2', item_id=item)
        self.run_command('equip', account_id=self.alice, loadout_id=own, slot='weapon1', item_id=None)
        self.assertEqual(self.store.account(self.alice)['slots'], [])

    def test_wrong_catalog_kind_is_not_an_item(self):
        with self.assertRaises(Conflict):
            self.run_command('grant_item', account_id=self.alice, item_key='school')

    def test_wallet_cannot_be_negative_and_rolls_back_ledger(self):
        self.run_command('wallet', account_id=self.alice, currency_key='silver', delta=10, reason='grant')
        with self.assertRaises(Conflict):
            self.run_command('wallet', account_id=self.alice, currency_key='silver', delta=-11, reason='spend')
        self.assertEqual(self.store.account(self.alice)['wallets'][0]['balance'], 10)
        with self.store.connection() as db:
            self.assertEqual(db.execute('SELECT COUNT(*) FROM wallet_entries').fetchone()[0], 1)

    def test_level_is_derived_from_xp_and_track_is_immutable_once_used(self):
        self.run_command('award_xp', account_id=self.alice, track='test', xp=110)
        state = self.store.account(self.alice)['progression'][0]
        self.assertEqual((state['level'], state['next_level_xp']), (2, 300))
        with self.assertRaises(Conflict):
            self.run_command('import_catalog', tracks=[{'key': 'test', 'name': 'Changed', 'levels': [{'level': 1, 'min_xp': 0}]}])
        with self.assertRaises(Invalid):
            self.run_command('import_catalog', tracks=[{'key': 'bad', 'name': 'Bad', 'levels': [{'level': 1, 'min_xp': 1}]}])

    def start(self):
        self.run_command('start_match', match_id='m1', build='test-build', map_key='school', mode_key='battery')

    def test_match_rewards_atomic_and_exactly_once(self):
        self.start()
        self.run_command('presence', account_id=self.alice, match_id='m1', state='match')
        command = dict(request_id='result', action='finish_match', match_id='m1', season_key='season-1', players=[
            {'account_id': self.alice, 'outcome': 'win', 'kills': 4, 'deaths': 1, 'rating': 1020,
             'progression': {'track': 'test', 'xp': 350}, 'currencies': [{'currency_key': 'silver', 'delta': 25}]}])
        result = self.store.command(command)
        self.assertEqual(result, self.store.command(command))
        with self.assertRaises(Conflict):
            self.store.command({**command, 'request_id': 'another-result'})
        profile = self.store.account(self.alice)
        self.assertEqual(profile['stats'][0]['kills'], 4)
        self.assertEqual(profile['progression'][0]['level'], 3)
        self.assertEqual(profile['wallets'][0]['balance'], 25)
        self.assertEqual(profile['ratings'][0]['rating'], 1020)
        self.assertEqual(profile['presence'], [])
        with self.store.connection() as db:
            self.assertEqual(db.execute('SELECT COUNT(*) FROM rating_history').fetchone()[0], 1)

    def test_invalid_result_rolls_back_all_players_and_rewards(self):
        self.start()
        with self.assertRaises(Conflict):
            self.run_command('finish_match', match_id='m1', players=[
                {'account_id': self.alice, 'outcome': 'win', 'progression': {'track': 'test', 'xp': 100}},
                {'account_id': 'missing-account', 'outcome': 'loss'}])
        self.assertEqual(self.store.account(self.alice)['progression'], [])
        with self.store.connection() as db:
            self.assertIsNone(db.execute('SELECT finished_at FROM matches').fetchone()[0])
            self.assertEqual(db.execute('SELECT COUNT(*) FROM match_results').fetchone()[0], 0)

    def test_presence_expires_and_rejects_other_owners_loadout(self):
        loadout = self.run_command('create_loadout', account_id=self.bob, name='Primary')['loadout_id']
        with self.assertRaises(Conflict):
            self.run_command('presence', account_id=self.alice, state='lobby', loadout_id=loadout)
        self.run_command('presence', account_id=self.alice, state='lobby')
        self.assertEqual(len(self.store.account(self.alice)['presence']), 1)
        with self.store.connection() as db:
            db.execute('UPDATE presence SET expires_at=0')
            db.commit()
        self.assertEqual(self.store.account(self.alice)['presence'], [])

    def test_catalog_mapping_separates_builds(self):
        self.run_command('import_catalog', bindings=[
            {'build': build, 'kind': 'item', 'wire_id': wire, 'catalog_key': 'rifle'}
            for build, wire in [('old', '13'), ('new', '67')]])
        with self.store.connection() as db:
            self.assertEqual(db.execute('SELECT COUNT(*) FROM catalog_bindings').fetchone()[0], 2)

    def test_backup_is_consistent_and_reopens(self):
        destination = Path(self.temp.name) / 'backup.sqlite3'
        self.store.backup(destination)
        backup = Store(destination)
        backup.initialize()
        self.assertEqual(backup.account(self.alice)['username'], 'alice')
        with self.assertRaises(Invalid):
            self.store.backup(self.store.path)

    def test_bad_inputs_and_unknown_accounts(self):
        for value in [True, -1, 0, 1.5, '2', 10**30]:
            with self.assertRaises(Invalid):
                self.run_command('grant_item', account_id=self.alice, item_key='rifle', quantity=value)
        with self.assertRaises(Conflict):
            self.run_command('create_account', username='ALICE')

    def test_progress_kind_is_checked_on_update(self):
        self.run_command('set_progress', account_id=self.alice, catalog_key='scavengers', kind='faction', value=100)
        with self.assertRaises(Conflict):
            self.run_command('set_progress', account_id=self.alice, catalog_key='scavengers', kind='skill', value=200)
        self.assertEqual(self.store.account(self.alice)['progress'][0]['value'], 100)

    def test_future_schema_is_rejected(self):
        with self.store.connection() as db:
            db.execute('PRAGMA user_version=2')
        with self.assertRaises(Invalid):
            self.store.initialize()

    def test_group_ownership_schema_references_real_accounts(self):
        with self.store.connection() as db:
            with self.assertRaises(sqlite3.IntegrityError):
                db.execute("INSERT INTO social_groups VALUES('s','squad','Squad','unknown')")


if __name__ == '__main__':
    unittest.main()
