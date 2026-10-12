<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP account database and website

A small, version-neutral persistence service and a static server-instructions page.
Python 3.11+ and SQLite 3.38+ are the only dependencies; there is no package install,
frontend build, external font, JavaScript, or hosted-service dependency.

The one-screen Gruvbox website contains a short guide and the Discord invite linked from the
[Vostok repository](https://github.com/srp-survarium/vostok):
<https://discord.gg/hDp78JMC4a>. It exposes no player data or account controls.
`static/` can also be served by any ordinary static web server, independently of
SQLite and the private API. Edit `static/index.html` to publish verified client
instructions or a public game address later.

## Run

From the repository root:

```sh
python3 servers/account-server/server.py init
python3 servers/account-server/server.py serve
# Open http://127.0.0.1:8080
```

The default database is `target/accounts.sqlite3`, outside tracked source. Use
`--db /path/to/accounts.sqlite3`, `--host`, and `--port` on the command line.
The HTTP API is disabled unless `SRP_ACCOUNT_TOKEN` is set. Local administration
through the CLI works without a token. The standalone service does not change
the existing Rust services or automatically connect to a game client.

## Database coverage

| Area | Stored data |
| --- | --- |
| Accounts | Stable UUID, username, display name; external provider identities |
| Catalog | Items, maps, modes, factions, skills, quests, achievements, currencies, seasons, rulesets, titles, boosters; extensible properties |
| Build mappings | Separate `(build, kind, wire_id)` mapping to canonical catalog keys |
| Ownership | Individually owned item instances, quantity, condition, upgrades/attributes, expiry |
| Loadouts | Named loadouts and slots; composite foreign keys reject another account's items |
| Progression | XP tracks, level thresholds, derived current level and next-level XP, unspent skill points |
| Economy | Currency balances, immutable-by-service transaction entries, nonnegative balances |
| Rating | Per-mode/per-season current and peak rating, game counts, per-match history |
| Player progress | Faction reputation/rank, skill allocations, quest state, achievements, titles, boosters |
| Matches | Build, map, mode, timestamps; outcomes, team, kills/deaths/assists, scores, arbitrary objective statistics |
| Current state | Expiring presence lease, current match/map, selected owned loadout |
| Social | Squads/clans, memberships, roles, expiring invitations, friends/blocks |
| Other account state | Inbox and entitlements such as premium access |
| Retry protection | Unique command ID + content hash and cached response in the same transaction |

These are persistence primitives, not a claim that every retail field or rule is
recovered. No retail item catalog, prices, XP curve, rating algorithm, loadout
compatibility rules, or rewards are invented or automatically seeded. Import
verified data as it becomes available. Build-dependent extensions fit in JSON
properties; established fields can get additive migrations later. The examples
are deliberately marked `example.*` and are not loaded by normal startup.

Current commands implement accounts, catalog imports, item grants, loadouts,
equipment, wallets, XP, typed progress, presence and complete match results.
Social/inbox/entitlement tables are schema foundations; their gameplay workflows
and APIs are not implemented here. User authentication, native lobby integration,
match admission, item trading/consumption, shop purchases and expiry enforcement
belong to a subsequent game-service adapter. The 0.26 roster tokens are not
account credentials and have not been connected to this database.

## Commands

All writes accept JSON on stdin. Every command needs a unique `request_id` and
`action`. Retrying an identical request returns its previous result; reusing an
ID with different contents is rejected. All actions execute under a SQLite
write transaction, including the retry record. Do not delete retry records while
callers may still replay them.

```sh
python3 servers/account-server/server.py command < servers/account-server/examples/catalog.json
printf '%s\n' '{"request_id":"create-alice-1","action":"create_account","username":"alice"}' \
  | python3 servers/account-server/server.py command
# Copy the returned account_id into subsequent commands.
python3 servers/account-server/server.py account --account-id ACCOUNT_UUID
```

An optional `identity: {"provider": "...", "subject": "..."}` on account creation
binds a unique identity supplied by a trusted authentication service. This is
not a password or bearer-token store.

| Action | Required fields in addition to `request_id`/`action` |
| --- | --- |
| `create_account` | `username`; optional `display_name`, `identity` |
| `import_catalog` | `entries` of `{key,kind,name,description?,properties?}`; optional `bindings` of `{build,kind,wire_id,catalog_key}` and `tracks` of `{key,name,levels:[{level,min_xp}]}` |
| `grant_item` | `account_id`, `item_key`; optional `quantity` (1), `condition` (10000), `attributes` |
| `create_loadout` | `account_id`, `name` |
| `equip` | `account_id`, `loadout_id`, `slot`, `item_id` (null to unequip) |
| `wallet` | `account_id`, `currency_key`, signed `delta`, `reason` |
| `award_xp` | `account_id`, `track`, `xp`; optional awarded `skill_points` |
| `set_progress` | `account_id`, `catalog_key`, `kind`; optional `value`, `rank`, `state`, `details` |
| `start_match` | `match_id`, `build`, `map_key`, `mode_key` |
| `presence` | `account_id`, `state` (`lobby`, `loading`, `match`); active `match_id` for loading/match, optional `loadout_id`, `ttl` (1–300 seconds, default 60) |
| `finish_match` | `match_id`, nonempty `players`; `season_key` when applying ratings |

Each `finish_match.players` entry requires `account_id` and `outcome` (`win`,
`loss`, `draw`, `abandoned`). Optional fields: `team`, `kills`, `deaths`, `assists`,
`score`, `details`, absolute `rating`, `progression: {track,xp,skill_points?}`,
`currencies: [{currency_key,delta}]`. The trusted game server chooses rewards and
rating policy; this service commits them atomically with results. A bad player
or reward rolls back the entire match. A finished match cannot pay out twice,
even under a different request ID. Lifetime stats and current levels are derived
from persisted records. Used XP curves are immutable: publish a new track to
change policy without silently changing existing levels.

## Private HTTP API

Generate a service credential, keep it outside source, and set it in the process
environment. It must contain at least 32 printable ASCII characters.

```sh
export SRP_ACCOUNT_TOKEN="$(python3 -c 'import secrets; print(secrets.token_urlsafe(32))')"
python3 servers/account-server/server.py serve
```

Authenticated routes require `Authorization: Bearer <SRP_ACCOUNT_TOKEN>`:

- `POST /api/v1/commands` — same JSON contract as the CLI; `Content-Type: application/json`.
- `GET /api/v1/accounts/{uuid}` — inventory, loadouts, progression, wallets, ratings, statistics and recent results.
- `GET /api/v1/catalog` — catalog records.

`GET /healthz` is public and only reports database availability. Mutations use
HTTP 200, validation errors 400, missing credentials 401, missing records 404,
conflicts 409, oversized bodies 413 and database availability errors 503. There
are no public registration or inventory mutation endpoints. One service token
has administrative access to all records; it is not a player credential.

For public hosting, serve `static/` directly with your web server and keep this
service on loopback. If proxying the service, proxy only `/`, `/index.html`,
`/style.css`, `/favicon.svg` publicly; keep `/api/` on the private network. Use
HTTPS for any nonlocal connection carrying the service credential. The small
stdlib server has bounded concurrent handlers, timeouts, request limits and
static-file allowlisting; use a reverse proxy for public traffic.

## Backups and migrations

```sh
python3 servers/account-server/server.py backup --output /path/to/backup.sqlite3
python3 -m unittest discover -s servers/account-server/tests -v
```

Backups use SQLite's online backup API, including committed WAL contents. Store
backups away from the public document root. To restore, stop the service and use
the backup as a new `--db` path. Initialization runs the first migration in a
transaction and records `PRAGMA user_version=1`; newer schema versions are
rejected. Foreign keys are enabled on every connection. Concurrent first starts
and write retries are covered by tests. SQLite must live on a local filesystem.

This change has no Rust dependency or workspace changes. It can land independently
of the generic server PRs and serve as their later persistence adapter.
