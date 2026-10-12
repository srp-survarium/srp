-- SPDX-License-Identifier: GPL-3.0-or-later
-- Version-neutral persistence. Wire IDs belong only in catalog_bindings.
CREATE TABLE accounts (
    id TEXT PRIMARY KEY,
    username TEXT NOT NULL UNIQUE COLLATE NOCASE CHECK(length(username) BETWEEN 3 AND 32),
    display_name TEXT NOT NULL CHECK(length(display_name) BETWEEN 1 AND 64),
    created_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now'))
) STRICT;
CREATE TABLE identities (
    provider TEXT NOT NULL,
    subject TEXT NOT NULL,
    account_id TEXT NOT NULL REFERENCES accounts(id),
    PRIMARY KEY(provider, subject)
) STRICT;
CREATE TABLE catalog (
    key TEXT PRIMARY KEY,
    kind TEXT NOT NULL CHECK(kind IN ('item','map','mode','faction','skill','quest','achievement','currency','season','ruleset','title','booster')),
    name TEXT NOT NULL,
    description TEXT NOT NULL DEFAULT '',
    properties TEXT NOT NULL DEFAULT '{}' CHECK(json_valid(properties) AND json_type(properties)='object'),
    UNIQUE(key, kind)
) STRICT;
CREATE TABLE catalog_bindings (
    build TEXT NOT NULL,
    kind TEXT NOT NULL,
    wire_id TEXT NOT NULL,
    catalog_key TEXT NOT NULL,
    PRIMARY KEY(build, kind, wire_id),
    FOREIGN KEY(catalog_key, kind) REFERENCES catalog(key, kind)
) STRICT;
CREATE TABLE item_instances (
    id TEXT PRIMARY KEY,
    owner_id TEXT NOT NULL REFERENCES accounts(id),
    item_key TEXT NOT NULL,
    kind TEXT NOT NULL DEFAULT 'item' CHECK(kind='item'),
    quantity INTEGER NOT NULL DEFAULT 1 CHECK(quantity BETWEEN 1 AND 1000000000),
    condition INTEGER NOT NULL DEFAULT 10000 CHECK(condition BETWEEN 0 AND 10000),
    acquired_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now')),
    expires_at TEXT,
    attributes TEXT NOT NULL DEFAULT '{}' CHECK(json_valid(attributes) AND json_type(attributes)='object'),
    UNIQUE(id, owner_id),
    FOREIGN KEY(item_key, kind) REFERENCES catalog(key, kind)
) STRICT;
CREATE INDEX inventory_owner ON item_instances(owner_id);
CREATE TABLE loadouts (
    id TEXT PRIMARY KEY,
    owner_id TEXT NOT NULL REFERENCES accounts(id),
    name TEXT NOT NULL,
    UNIQUE(id, owner_id),
    UNIQUE(owner_id, name)
) STRICT;
CREATE TABLE loadout_slots (
    loadout_id TEXT NOT NULL,
    owner_id TEXT NOT NULL,
    slot TEXT NOT NULL,
    item_id TEXT NOT NULL,
    PRIMARY KEY(loadout_id, slot),
    UNIQUE(loadout_id, item_id),
    FOREIGN KEY(loadout_id, owner_id) REFERENCES loadouts(id, owner_id) ON DELETE CASCADE,
    FOREIGN KEY(item_id, owner_id) REFERENCES item_instances(id, owner_id) ON DELETE CASCADE
) STRICT;
CREATE TABLE level_definitions (
    track TEXT NOT NULL,
    level INTEGER NOT NULL CHECK(level>=1),
    min_xp INTEGER NOT NULL CHECK(min_xp BETWEEN 0 AND 9000000000000000),
    PRIMARY KEY(track, level),
    UNIQUE(track, min_xp),
    FOREIGN KEY(track) REFERENCES progression_tracks(key)
) STRICT;
CREATE TABLE progression (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    track TEXT NOT NULL,
    xp INTEGER NOT NULL DEFAULT 0 CHECK(xp BETWEEN 0 AND 9000000000000000),
    skill_points INTEGER NOT NULL DEFAULT 0 CHECK(skill_points BETWEEN 0 AND 1000000000),
    PRIMARY KEY(account_id, track),
    FOREIGN KEY(track) REFERENCES progression_tracks(key)
) STRICT;
CREATE TABLE progression_tracks (key TEXT PRIMARY KEY, name TEXT NOT NULL) STRICT;
CREATE VIEW current_levels AS
 SELECT p.*, COALESCE((SELECT MAX(l.level) FROM level_definitions l
 WHERE l.track=p.track AND l.min_xp<=p.xp),1) AS level,
 (SELECT MIN(l.min_xp) FROM level_definitions l WHERE l.track=p.track AND l.min_xp>p.xp) AS next_level_xp
 FROM progression p;
CREATE TABLE wallets (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    currency_key TEXT NOT NULL,
    kind TEXT NOT NULL DEFAULT 'currency' CHECK(kind='currency'),
    balance INTEGER NOT NULL DEFAULT 0 CHECK(balance BETWEEN 0 AND 9000000000000000),
    PRIMARY KEY(account_id,currency_key),
    FOREIGN KEY(currency_key,kind) REFERENCES catalog(key,kind)
) STRICT;
CREATE TABLE wallet_entries (
    id INTEGER PRIMARY KEY,
    account_id TEXT NOT NULL REFERENCES accounts(id),
    currency_key TEXT NOT NULL,
    delta INTEGER NOT NULL,
    reason TEXT NOT NULL,
    created_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now')),
    FOREIGN KEY(account_id,currency_key) REFERENCES wallets(account_id,currency_key)
) STRICT;
CREATE TABLE ratings (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    season_key TEXT NOT NULL,
    season_kind TEXT NOT NULL DEFAULT 'season' CHECK(season_kind='season'),
    mode_key TEXT NOT NULL,
    mode_kind TEXT NOT NULL DEFAULT 'mode' CHECK(mode_kind='mode'),
    rating INTEGER NOT NULL CHECK(rating BETWEEN 0 AND 1000000000),
    peak INTEGER NOT NULL CHECK(peak>=rating),
    games INTEGER NOT NULL DEFAULT 0 CHECK(games>=0),
    PRIMARY KEY(account_id,season_key,mode_key),
    FOREIGN KEY(season_key,season_kind) REFERENCES catalog(key,kind),
    FOREIGN KEY(mode_key,mode_kind) REFERENCES catalog(key,kind)
) STRICT;
-- Faction reputation/rank, allocated skills, quest progress, achievements,
-- unlocks and boosters share a small typed, extensible record format.
CREATE TABLE account_progress (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    catalog_key TEXT NOT NULL,
    kind TEXT NOT NULL CHECK(kind IN ('faction','skill','quest','achievement','title','booster')),
    value INTEGER NOT NULL DEFAULT 0 CHECK(value>=0),
    rank INTEGER NOT NULL DEFAULT 0 CHECK(rank>=0),
    state TEXT NOT NULL DEFAULT 'active' CHECK(state IN ('locked','active','completed','claimed','expired')),
    expires_at TEXT,
    details TEXT NOT NULL DEFAULT '{}' CHECK(json_valid(details) AND json_type(details)='object'),
    PRIMARY KEY(account_id,catalog_key),
    FOREIGN KEY(catalog_key,kind) REFERENCES catalog(key,kind)
) STRICT;
CREATE TABLE matches (
    id TEXT PRIMARY KEY,
    build TEXT NOT NULL,
    map_key TEXT NOT NULL,
    map_kind TEXT NOT NULL DEFAULT 'map' CHECK(map_kind='map'),
    mode_key TEXT NOT NULL,
    mode_kind TEXT NOT NULL DEFAULT 'mode' CHECK(mode_kind='mode'),
    started_at TEXT NOT NULL,
    finished_at TEXT,
    FOREIGN KEY(map_key,map_kind) REFERENCES catalog(key,kind),
    FOREIGN KEY(mode_key,mode_kind) REFERENCES catalog(key,kind)
) STRICT;
CREATE TABLE match_results (
    match_id TEXT NOT NULL REFERENCES matches(id),
    account_id TEXT NOT NULL REFERENCES accounts(id),
    team INTEGER NOT NULL CHECK(team>=0),
    outcome TEXT NOT NULL CHECK(outcome IN ('win','loss','draw','abandoned')),
    kills INTEGER NOT NULL DEFAULT 0 CHECK(kills>=0),
    deaths INTEGER NOT NULL DEFAULT 0 CHECK(deaths>=0),
    assists INTEGER NOT NULL DEFAULT 0 CHECK(assists>=0),
    score INTEGER NOT NULL DEFAULT 0,
    details TEXT NOT NULL DEFAULT '{}' CHECK(json_valid(details) AND json_type(details)='object'),
    PRIMARY KEY(match_id,account_id)
) STRICT;
CREATE VIEW lifetime_stats AS
 SELECT account_id, COUNT(*) AS matches, SUM(outcome='win') AS wins,
 SUM(outcome='loss') AS losses, SUM(kills) AS kills, SUM(deaths) AS deaths,
 SUM(assists) AS assists, SUM(score) AS score FROM match_results GROUP BY account_id;
CREATE TABLE rating_history (
    match_id TEXT NOT NULL,
    account_id TEXT NOT NULL,
    season_key TEXT NOT NULL,
    mode_key TEXT NOT NULL,
    previous_rating INTEGER,
    rating INTEGER NOT NULL,
    PRIMARY KEY(match_id,account_id,season_key,mode_key),
    FOREIGN KEY(match_id,account_id) REFERENCES match_results(match_id,account_id),
    FOREIGN KEY(account_id,season_key,mode_key) REFERENCES ratings(account_id,season_key,mode_key)
) STRICT;
-- A lease records current map/match without claiming crashed clients stay online.
CREATE TABLE presence (
    account_id TEXT PRIMARY KEY REFERENCES accounts(id),
    match_id TEXT REFERENCES matches(id),
    loadout_id TEXT,
    state TEXT NOT NULL CHECK(state IN ('lobby','loading','match')),
    expires_at INTEGER NOT NULL,
    FOREIGN KEY(loadout_id,account_id) REFERENCES loadouts(id,owner_id)
) STRICT;
CREATE TABLE social_groups (
    id TEXT PRIMARY KEY,
    kind TEXT NOT NULL CHECK(kind IN ('squad','clan')),
    name TEXT NOT NULL,
    owner_id TEXT NOT NULL REFERENCES accounts(id)
) STRICT;
CREATE TABLE group_members (
    group_id TEXT NOT NULL REFERENCES social_groups(id) ON DELETE CASCADE,
    account_id TEXT NOT NULL REFERENCES accounts(id),
    role TEXT NOT NULL DEFAULT 'member' CHECK(role IN ('leader','officer','member')),
    PRIMARY KEY(group_id,account_id)
) STRICT;
CREATE TABLE group_invites (
    group_id TEXT NOT NULL REFERENCES social_groups(id) ON DELETE CASCADE,
    account_id TEXT NOT NULL REFERENCES accounts(id),
    invited_by TEXT NOT NULL REFERENCES accounts(id),
    expires_at TEXT NOT NULL,
    PRIMARY KEY(group_id,account_id)
) STRICT;
CREATE TABLE relationships (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    other_id TEXT NOT NULL REFERENCES accounts(id),
    state TEXT NOT NULL CHECK(state IN ('pending','friend','blocked')),
    CHECK(account_id<>other_id),
    PRIMARY KEY(account_id,other_id)
) STRICT;
CREATE TABLE inbox (
    id TEXT PRIMARY KEY,
    account_id TEXT NOT NULL REFERENCES accounts(id),
    subject TEXT NOT NULL,
    body TEXT NOT NULL,
    created_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now')),
    read_at TEXT
) STRICT;
CREATE TABLE entitlements (
    account_id TEXT NOT NULL REFERENCES accounts(id),
    key TEXT NOT NULL,
    expires_at TEXT,
    details TEXT NOT NULL DEFAULT '{}' CHECK(json_valid(details) AND json_type(details)='object'),
    PRIMARY KEY(account_id,key)
) STRICT;
-- Retries are replayed only when the complete request matches the original.
CREATE TABLE commands (
    request_id TEXT PRIMARY KEY,
    request_hash TEXT NOT NULL,
    response TEXT NOT NULL CHECK(json_valid(response)),
    created_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%fZ','now'))
) STRICT;
