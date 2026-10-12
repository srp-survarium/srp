# SPDX-License-Identifier: GPL-3.0-or-later
"""Small version-neutral SQLite store. All mutations are atomic and replay-safe."""
import hashlib
import json
import re
import sqlite3
import time
import uuid
from contextlib import closing, contextmanager
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
KINDS = {'item', 'map', 'mode', 'faction', 'skill', 'quest', 'achievement',
         'currency', 'season', 'ruleset', 'title', 'booster'}
MAX_VALUE = 9_000_000_000_000_000


class Invalid(ValueError):
    pass


class Conflict(Invalid):
    pass


class Missing(Invalid):
    pass


def text(data, key, default=None, limit=128):
    value = data.get(key, default)
    if not isinstance(value, str) or not value.strip() or len(value) > limit or any(ord(c) < 32 for c in value):
        raise Invalid(f'{key} must be a nonempty string of at most {limit} characters')
    return value


def number(data, key, default=0, minimum=0, maximum=MAX_VALUE):
    value = data.get(key, default)
    if type(value) is not int or not minimum <= value <= maximum:
        raise Invalid(f'{key} must be an integer between {minimum} and {maximum}')
    return value


def obj(value):
    if not isinstance(value, dict):
        raise Invalid('expected a JSON object')
    return value


def array(data, key, limit=1000):
    value = data.get(key, [])
    if not isinstance(value, list) or len(value) > limit:
        raise Invalid(f'{key} must be a list of at most {limit} entries')
    return value


def encoded(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), allow_nan=False)


def now():
    return datetime.now(timezone.utc).isoformat()


class Store:
    def __init__(self, path):
        self.path = str(path)

    @contextmanager
    def connection(self):
        db = sqlite3.connect(self.path, timeout=5)
        db.row_factory = sqlite3.Row
        db.execute('PRAGMA foreign_keys=ON')
        try:
            yield db
        finally:
            db.close()

    def initialize(self):
        Path(self.path).parent.mkdir(parents=True, exist_ok=True)
        with self.connection() as db:
            deadline = time.monotonic() + 5
            while True:
                try:
                    db.execute('PRAGMA journal_mode=WAL')
                    break
                except sqlite3.OperationalError as error:
                    # Changing journal mode can return BUSY immediately despite
                    # busy_timeout when another process is initializing the file.
                    if error.sqlite_errorcode != sqlite3.SQLITE_BUSY or time.monotonic() >= deadline:
                        raise
                    time.sleep(0.05)
            # One migration for the initial release. Refuse newer schemas.
            # Acquire the write lock before reading the version, including on
            # concurrent first startup; execute statements without executescript
            # (which would implicitly commit and release that lock).
            db.execute('BEGIN IMMEDIATE')
            version = db.execute('PRAGMA user_version').fetchone()[0]
            if version > 1:
                raise Invalid('database is newer than this server')
            if version == 0:
                sql = (ROOT / 'database/migrations/001_initial.sql').read_text()
                statement = ''
                for line in sql.splitlines(keepends=True):
                    statement += line
                    if sqlite3.complete_statement(statement):
                        db.execute(statement)
                        statement = ''
                db.execute('PRAGMA user_version=1')
            db.commit()

    @staticmethod
    def require(db, account):
        if not db.execute('SELECT 1 FROM accounts WHERE id=?', (account,)).fetchone():
            raise Missing('account not found')

    def command(self, data):
        obj(data)
        request = text(data, 'request_id')
        action = text(data, 'action')
        methods = {'create_account': self.create_account, 'import_catalog': self.import_catalog,
                   'grant_item': self.grant_item, 'create_loadout': self.create_loadout,
                   'equip': self.equip, 'wallet': self.wallet, 'award_xp': self.award_xp,
                   'set_progress': self.set_progress, 'start_match': self.start_match,
                   'finish_match': self.finish_match, 'presence': self.presence}
        if action not in methods:
            raise Invalid('unknown action')
        digest = hashlib.sha256(encoded(data).encode()).hexdigest()
        with self.connection() as db:
            try:
                db.execute('BEGIN IMMEDIATE')
                previous = db.execute('SELECT * FROM commands WHERE request_id=?', (request,)).fetchone()
                if previous:
                    if previous['request_hash'] != digest:
                        raise Conflict('request_id already used for a different command')
                    return json.loads(previous['response'])
                result = methods[action](db, data)
                db.execute('INSERT INTO commands(request_id,request_hash,response) VALUES(?,?,?)',
                           (request, digest, encoded(result)))
                db.commit()
                return result
            except sqlite3.IntegrityError as error:
                raise Conflict('operation violates an ownership, reference, balance or uniqueness constraint') from error

    def create_account(self, db, data):
        username = text(data, 'username', limit=32)
        if not re.fullmatch(r'[a-zA-Z0-9_\-]{3,32}', username):
            raise Invalid('username must contain 3–32 letters, digits, underscores or hyphens')
        account = str(uuid.uuid4())
        db.execute('INSERT INTO accounts(id,username,display_name) VALUES(?,?,?)',
                   (account, username, text(data, 'display_name', username, 64)))
        identity = data.get('identity')
        if identity is not None:
            obj(identity)
            db.execute('INSERT INTO identities VALUES(?,?,?)',
                       (text(identity, 'provider'), text(identity, 'subject', limit=256), account))
        return {'account_id': account}

    def import_catalog(self, db, data):
        entries = array(data, 'entries')
        for entry in entries:
            obj(entry)
            kind = text(entry, 'kind')
            if kind not in KINDS:
                raise Invalid('unknown catalog kind')
            description = entry.get('description', '')
            if not isinstance(description, str) or len(description) > 10000:
                raise Invalid('description must be a string of at most 10000 characters')
            db.execute('''INSERT INTO catalog(key,kind,name,description,properties) VALUES(?,?,?,?,?)
                ON CONFLICT(key) DO UPDATE SET name=excluded.name,
                description=excluded.description,properties=excluded.properties''',
                       (text(entry, 'key'), kind, text(entry, 'name'),
                        description, encoded(obj(entry.get('properties', {})))))
            current = db.execute('SELECT kind FROM catalog WHERE key=?', (entry['key'],)).fetchone()[0]
            if current != kind:
                raise Conflict('catalog kind is immutable')
        for binding in array(data, 'bindings'):
            obj(binding)
            db.execute('INSERT INTO catalog_bindings VALUES(?,?,?,?)',
                       tuple(text(binding, k) for k in ('build', 'kind', 'wire_id', 'catalog_key')))
        for track in array(data, 'tracks'):
            obj(track)
            key = text(track, 'key')
            db.execute('INSERT INTO progression_tracks VALUES(?,?) ON CONFLICT(key) DO UPDATE SET name=excluded.name',
                       (key, text(track, 'name')))
            levels = array(track, 'levels')
            if not levels:
                raise Invalid('a progression track needs levels beginning with level 1 at 0 XP')
            checked = [(number(obj(row), 'level', minimum=1), number(row, 'min_xp')) for row in levels]
            if checked[0] != (1, 0) or any(a[0]+1 != b[0] or a[1] >= b[1] for a, b in zip(checked, checked[1:])):
                raise Invalid('levels must be consecutive with strictly increasing XP, starting at (1,0)')
            # Published tracks are immutable once used: changing thresholds would
            # silently change every player's level. Import a new track key instead.
            old = [tuple(r) for r in db.execute('SELECT level,min_xp FROM level_definitions WHERE track=? ORDER BY level', (key,))]
            if old and old != checked and db.execute('SELECT 1 FROM progression WHERE track=? LIMIT 1', (key,)).fetchone():
                raise Conflict('progression track is in use; create a new track key')
            db.execute('DELETE FROM level_definitions WHERE track=?', (key,))
            db.executemany('INSERT INTO level_definitions VALUES(?,?,?)', [(key, *row) for row in checked])
        return {'imported': len(entries)}

    def grant_item(self, db, data):
        item = str(uuid.uuid4())
        account = text(data, 'account_id')
        self.require(db, account)
        db.execute('''INSERT INTO item_instances(id,owner_id,item_key,quantity,condition,attributes)
                   VALUES(?,?,?,?,?,?)''', (item, account, text(data, 'item_key'),
                   number(data, 'quantity', 1, 1, 1_000_000_000), number(data, 'condition', 10000, 0, 10000),
                   encoded(obj(data.get('attributes', {})))))
        return {'item_id': item}

    def create_loadout(self, db, data):
        loadout = str(uuid.uuid4())
        db.execute('INSERT INTO loadouts VALUES(?,?,?)',
                   (loadout, text(data, 'account_id'), text(data, 'name', limit=64)))
        return {'loadout_id': loadout}

    def equip(self, db, data):
        owner, loadout, slot = (text(data, k) for k in ('account_id', 'loadout_id', 'slot'))
        if not db.execute('SELECT 1 FROM loadouts WHERE id=? AND owner_id=?', (loadout, owner)).fetchone():
            raise Missing('owned loadout not found')
        if data.get('item_id') is None:
            db.execute('DELETE FROM loadout_slots WHERE loadout_id=? AND slot=?', (loadout, slot))
        else:
            item = text(data, 'item_id')
            db.execute('''INSERT INTO loadout_slots VALUES(?,?,?,?) ON CONFLICT(loadout_id,slot)
                       DO UPDATE SET item_id=excluded.item_id''', (loadout, owner, slot, item))
        return {'loadout_id': loadout, 'slot': slot, 'item_id': data.get('item_id')}

    def wallet(self, db, data):
        account, currency = text(data, 'account_id'), text(data, 'currency_key')
        delta = number(data, 'delta', minimum=-MAX_VALUE)
        db.execute('INSERT INTO wallets(account_id,currency_key) VALUES(?,?) ON CONFLICT DO NOTHING', (account, currency))
        db.execute('UPDATE wallets SET balance=balance+? WHERE account_id=? AND currency_key=?', (delta, account, currency))
        db.execute('INSERT INTO wallet_entries(account_id,currency_key,delta,reason) VALUES(?,?,?,?)',
                   (account, currency, delta, text(data, 'reason', limit=256)))
        return {'balance': db.execute('SELECT balance FROM wallets WHERE account_id=? AND currency_key=?', (account, currency)).fetchone()[0]}

    def award_xp(self, db, data):
        account, track = text(data, 'account_id'), text(data, 'track')
        db.execute('''INSERT INTO progression(account_id,track,xp,skill_points) VALUES(?,?,?,?)
            ON CONFLICT(account_id,track) DO UPDATE SET xp=xp+excluded.xp,
            skill_points=skill_points+excluded.skill_points''',
                   (account, track, number(data, 'xp'), number(data, 'skill_points', maximum=1_000_000_000)))
        return dict(db.execute('SELECT * FROM current_levels WHERE account_id=? AND track=?', (account, track)).fetchone())

    def set_progress(self, db, data):
        db.execute('''INSERT INTO account_progress(account_id,catalog_key,kind,value,rank,state,details)
            VALUES(?,?,?,?,?,?,?) ON CONFLICT(account_id,catalog_key) DO UPDATE SET
            kind=excluded.kind,value=excluded.value,rank=excluded.rank,state=excluded.state,details=excluded.details''',
                   (text(data, 'account_id'), text(data, 'catalog_key'), text(data, 'kind'),
                    number(data, 'value'), number(data, 'rank'), text(data, 'state', 'active'),
                    encoded(obj(data.get('details', {})))))
        return {'updated': True}

    def start_match(self, db, data):
        match = text(data, 'match_id')
        db.execute('INSERT INTO matches(id,build,map_key,mode_key,started_at) VALUES(?,?,?,?,?)',
                   (match, text(data, 'build'), text(data, 'map_key'), text(data, 'mode_key'), now()))
        return {'match_id': match}

    def finish_match(self, db, data):
        match = text(data, 'match_id')
        row = db.execute('SELECT * FROM matches WHERE id=?', (match,)).fetchone()
        if row is None:
            raise Missing('match not found')
        if row['finished_at'] is not None:
            raise Conflict('match already finished')
        players = array(data, 'players', 256)
        if not players:
            raise Invalid('match must contain results')
        for player in players:
            obj(player)
            account = text(player, 'account_id')
            db.execute('''INSERT INTO match_results(match_id,account_id,team,outcome,kills,deaths,assists,score,details)
                VALUES(?,?,?,?,?,?,?,?,?)''', (match, account, number(player, 'team'), text(player, 'outcome'),
                number(player, 'kills'), number(player, 'deaths'), number(player, 'assists'),
                number(player, 'score', minimum=-MAX_VALUE), encoded(obj(player.get('details', {})))))
            if 'progression' in player:
                self.award_xp(db, {**obj(player['progression']), 'account_id': account})
            for award in array(player, 'currencies'):
                self.wallet(db, {**obj(award), 'account_id': account, 'reason': f'match:{match}'})
            if 'rating' in player:
                rating = number(player, 'rating', maximum=1_000_000_000)
                season = text(data, 'season_key')
                old = db.execute('SELECT rating FROM ratings WHERE account_id=? AND season_key=? AND mode_key=?',
                                 (account, season, row['mode_key'])).fetchone()
                db.execute('''INSERT INTO ratings(account_id,season_key,mode_key,rating,peak,games) VALUES(?,?,?,?,?,1)
                    ON CONFLICT(account_id,season_key,mode_key) DO UPDATE SET rating=excluded.rating,
                    peak=MAX(peak,excluded.rating),games=games+1''', (account, season, row['mode_key'], rating, rating))
                db.execute('INSERT INTO rating_history VALUES(?,?,?,?,?,?)',
                           (match, account, season, row['mode_key'], old[0] if old else None, rating))
        db.execute('UPDATE matches SET finished_at=? WHERE id=?', (now(), match))
        db.execute('DELETE FROM presence WHERE match_id=?', (match,))
        return {'match_id': match, 'players': len(players)}

    def presence(self, db, data):
        account = text(data, 'account_id')
        state = text(data, 'state')
        match = data.get('match_id')
        if state in ('loading', 'match'):
            row = db.execute('SELECT finished_at FROM matches WHERE id=?', (text(data, 'match_id'),)).fetchone()
            if row is None or row[0] is not None:
                raise Conflict('presence requires an active match')
        elif state == 'lobby' and match is not None:
            raise Invalid('lobby presence must not reference a match')
        until = int(time.time()) + number(data, 'ttl', 60, 1, 300)
        db.execute('''INSERT INTO presence VALUES(?,?,?,?,?) ON CONFLICT(account_id) DO UPDATE SET
            match_id=excluded.match_id,loadout_id=excluded.loadout_id,state=excluded.state,expires_at=excluded.expires_at''',
                   (account, match, data.get('loadout_id'), state, until))
        return {'expires_at': until}

    def account(self, account):
        with self.connection() as db:
            db.execute('BEGIN')  # All sections from the same snapshot.
            self.require(db, account)
            result = dict(db.execute('SELECT * FROM accounts WHERE id=?', (account,)).fetchone())
            queries = {
                'items': 'SELECT * FROM item_instances WHERE owner_id=? ORDER BY id',
                'loadouts': 'SELECT * FROM loadouts WHERE owner_id=? ORDER BY name',
                'slots': 'SELECT * FROM loadout_slots WHERE owner_id=? ORDER BY loadout_id,slot',
                'progression': 'SELECT * FROM current_levels WHERE account_id=? ORDER BY track',
                'wallets': 'SELECT currency_key,balance FROM wallets WHERE account_id=? ORDER BY currency_key',
                'ratings': 'SELECT * FROM ratings WHERE account_id=? ORDER BY season_key,mode_key',
                'progress': 'SELECT * FROM account_progress WHERE account_id=? ORDER BY catalog_key',
                'stats': 'SELECT * FROM lifetime_stats WHERE account_id=?',
                'matches': 'SELECT * FROM match_results WHERE account_id=? ORDER BY rowid DESC LIMIT 100',
                'groups': 'SELECT g.* FROM social_groups g JOIN group_members m ON m.group_id=g.id WHERE m.account_id=?',
                'entitlements': 'SELECT * FROM entitlements WHERE account_id=?',
            }
            for name, query in queries.items():
                result[name] = [dict(r) for r in db.execute(query, (account,))]
            result['presence'] = [dict(r) for r in db.execute('''SELECT p.*,m.map_key FROM presence p
                LEFT JOIN matches m ON m.id=p.match_id WHERE p.account_id=? AND p.expires_at>?''', (account, int(time.time())))]
            return result

    def catalog(self):
        with self.connection() as db:
            return [dict(r) for r in db.execute('SELECT * FROM catalog ORDER BY kind,key')]

    def backup(self, destination):
        if Path(destination).resolve() == Path(self.path).resolve():
            raise Invalid('backup destination must differ from the source')
        with self.connection() as source, closing(sqlite3.connect(destination)) as dest:
            source.backup(dest)
