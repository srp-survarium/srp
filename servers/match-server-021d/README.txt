Local v0.21d server

This package coordinates the clients' existing simulations. It does not run
server-side game physics. The current local test uses School, Battery hunt
and fixed loadouts. All services bind loopback; arbitrary nonempty test
passwords are accepted. This is a development server, not public authentication.

Small persistent clock drift uses bounded native timer slews and measured ACK
latency. This assumes the client's default time_floating_factor=0.05. See
docs/v021d/CLOCK-CORRECTION.txt for policy and the pending real-engine drift
validation boundary; automated protocol/model tests pass.

Two client protocols are supported, selected explicitly per match process:
  community (default): the previously tested community-patched 0.21d client;
  srp1: clean-retail 0.21d with the project's SRP1-48-R1 DLL and Matches UI.
Never mix these clients in the same process. Native menu allocation always
selects srp1. See docs/v021d/START-HERE.txt for simulation/recovery evidence,
known limits and the user's already accepted combat playtest.

NATIVE MATCHES SERVICE

Run from the repository root with Rust, Python 3.11+ and OpenSSL available:
  cargo build -p match-server-021d
  mkdir -p /tmp/srp-021d-local
  umask 077
  openssl req -x509 -newkey rsa:2048 -nodes -days 3650 \
    -subj '/CN=SRP isolated local test' \
    -keyout /tmp/srp-021d-local/login.key \
    -out /tmp/srp-021d-local/login.crt

Create this certificate once, not on every restart. Before starting the private
test client, put the matching public login.crt in its
resources/ssl/survarium_login_server.crt. The repository's old test certificate
is expired and a verifying retail client rejects it. Keep the private key out
of the client installation and evidence archives.

  python3 servers/match-server-021d/tools/native_menu.py \
    --cert /tmp/srp-021d-local/login.crt \
    --key /tmp/srp-021d-local/login.key \
    --state /tmp/srp-021d-local/accounts.sqlite \
    --base-port 19121 \
    --match-server "$PWD/target/debug/match-server-021d" \
    --match-work /tmp/srp-021d-local/matches \
    --require-recovery --match-results

Pass the compiled binary directly. This allocator adds --protocol srp1 itself;
do not pass tools/srp1_server.sh, which would add the option twice. That older
wrapper remains for allocators that only supply positional arguments.

Point the client at login 127.0.0.1:19121, with
SRP_MENU_API=http://127.0.0.1:19125/v1/menu and SRP_MATCH_PROTOCOL=1. The separate
client/021d launcher can derive these from service_port=19121 in its profile.
Its DLL/movie/assets are separate client deliverables, not server dependencies.
The native menu service's Python modules are all included in this package.

Use the client package with the SrpResults waiting-screen helper (verified
package-v4, resource archive SHA256 f3ea03d7831697c33c3310f2c76405f5be40cf6e082b7d92122d30aec2c30f9d).
If statistics never arrive, it shows an explanation after 15 seconds and the
native Close button returns to Matches. Late statistics still display normally.
This UI fallback is a client-package feature; the server does not fabricate
missing results. See docs/v021d/RESULTS-FALLBACK.txt for exact scope and evidence.

In Matches, create or join a room, have each present player choose Ready, then
let the creator choose Start. The service starts one SRP1 process per room,
up to eight concurrent processes. Capacity limits the waiting room; Start uses
the present roster. Each process gets private per-match session grants and
its own UDP port. Results are retained for each returning account in memory.
Late join through this menu is currently disabled, even though the community
coordinator has independently tested late-join/recovery support.

The starting roster has 120 seconds to reach the shared bootstrap. An empty
or incomplete initial cohort then expires, releasing its process and grants.
When the last UDP player leaves, the allocator also reclaims the room without
requiring a lobby return. It retains available final results for returning
accounts before stopping the child. Running matches are not limited by this
startup deadline. Lost status replies alone do not terminate a live match.

Match/team chat follows the admitted room and its assigned teams. In the
tested default bindings, T opens chat, Tab changes channel, and Enter sends.
Match reaches both teams; Team reaches your assigned team. Returning to the
lobby ends match-chat eligibility; a new admission supplies a fresh group.
See docs/v021d/NATIVE-CHAT.txt for routing and protocol-test evidence.
In-game names/results still use fixed roster-local aliases, which can differ
from the persistent account name shown in chat when room join order changes.

RESTART AND SHUTDOWN

Keep the same --state file to retain account-to-slot identities, tokens and
monotonic native match-order IDs. A fresh native menu store has sixteen account
slots; a different-sized front-door checkpoint is rejected rather than
remapped. Do not share this store with another running service. Omitting
--state gives an ephemeral test service.

SIGTERM or Ctrl-C stops child matches and removes their grants/control sockets.
Restart drops waiting rooms, Ready state and in-memory results. Players sign
back in and create new rooms, preserving their identities. Native order IDs
are committed before allocation and never reused after a normal restart;
failed allocation can leave a harmless gap. A failed database write prevents
admission and requires restarting after resolving the storage problem.

The service does not resume active simulations or preserve completed results
across its restart. Abrupt SIGKILL/power loss is not a graceful shutdown:
child supervision and stale grant cleanup for that case remain incomplete.
Do not delete a live store's adjacent lock file or reuse old grant files.

COMMUNITY CLIENT SERVICE

tools/front_door.py remains available for the already tested fixed-roster
community path. Its required --sessions export feeds the executable's
positional SESSIONS_FILE argument. Its --state option preserves identities and
routes; tools/queue_match.py explicitly admits the next match. See
docs/v021d/NEXT-MATCH.txt and PERSISTENCE.txt for exact commands and guards.

AUTOMATED CHECKS

  cargo test -p match-server-021d
  PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover \
    -s servers/match-server-021d/tests -p 'test_*.py' -v
  PYTHONDONTWRITEBYTECODE=1 python3 \
    servers/match-server-021d/tests/run_menu_lifecycle.py \
    --front-door servers/match-server-021d/tools/front_door.py \
    --match-server target/debug/match-server-021d \
    --cert /tmp/srp-021d-local/login.crt --key /tmp/srp-021d-local/login.key \
    --work /tmp/srp-021d-new-lifecycle-test

The lifecycle test requires a new work directory and disposable loopback ports.
It performs native login, menu operations, child allocation, shutdown and
reverse-order account login after restart. It does not launch a game client.
The latest full native-client lifecycle evidence is in SRP1-INTEGRATION.txt;
menu-service persistence and source integration are recorded in MENU-SERVICE.txt.
