// Multi-client match server: a dumb relay.
//
// SRP is a mock — this does NOT simulate the game. It owns one UDP socket,
// demultiplexes datagrams to a per-peer `Transport` (reliable-UDP), and:
//   * runs each client through the connect/startup/join handshake, reflecting the
//     per-match live roster (one `PlayerProfile`/`SpawnPlayer` per connected
//     peer), and
//   * relays each client's `ClientPlayerUpdate` to every OTHER peer as a
//     `ServerPlayerInput`, so players see each other move.
//   * validates the identity/roster fields of a synthetic client hit report,
//     applies a deliberately simplified health model, and emits stock
//     `HitPlayer`/`KillPlayer` messages.
//
// Movement and damage remain client-reported demo data; there is no geometry,
// armor, healing, respawn, or reconciliation. Roster handling is best-effort
// (see WORK.md) — the clean case is clients connecting before either readies
// up; late joins may render imperfectly and need in-game iteration.

use std::collections::HashMap;
use std::io;
use std::net::{SocketAddr, UdpSocket};
use std::sync::Arc;
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};

use session::SessionStore;
use survarium::player_input::weapon_state;
use survarium::player_profile::raw::{
    game_team_id, player_profile as raw_player_profile, profile_slot_enum,
};

use crate::game;
use crate::message::server_message::raw::game_status;
use crate::message::{ClientGameMessageKind, PlayerHit, PlayerKill, ServerGameMessageKind};
use crate::transport::Transport;

const FRAMES_PER_SECOND: u64 = 120;
const FRAME_DURATION: Duration = Duration::from_millis(1000 / FRAMES_PER_SECOND);
/// Client tracks `m_net_players[20]`, so at most 20 player ids.
const MAX_PLAYERS: u8 = 20;
/// Standalone clients without a lobby assignment share the historic match.
const DEFAULT_MATCH_ID: u32 = 0x123;
/// Drop a peer we haven't heard from for this long (the client sends keepalives
/// and updates far more often), so dead clients don't linger in the roster.
const IDLE_TIMEOUT: Duration = Duration::from_secs(5);
/// Cap on total peer entries (registered + still-connecting), to bound the work
/// a flood of unknown source addresses can create.
const PEER_LIMIT: usize = 64;
/// Demo health model. The client-reported hit amount is deducted directly.
const PLAYER_MAX_HEALTH: f32 = 100.0;

struct Peer {
    transport: Transport,
    /// `false` until the peer's `ConnectionRequest` assigns it a player id.
    registered: bool,
    match_id: u32,
    player_id: u8,
    team: game_team_id,
    name: String,
    /// Exact lobby-selected equipment for this match connection.
    profile: raw_player_profile,
    /// `true` once the peer has sent `JoinMatch` (is in the match).
    joined: bool,
    health: f32,
    alive: bool,
    /// Index into `game::SPAWN_POSITIONS`, assigned when this peer joins.
    spawn_index: usize,
    /// When we last received a datagram from this peer (for the idle timeout).
    last_seen: Instant,
}

impl Peer {
    fn new() -> Self {
        Self {
            transport: Transport::new(),
            registered: false,
            match_id: DEFAULT_MATCH_ID,
            player_id: 0,
            team: game_team_id::team_1,
            name: String::new(),
            profile: raw_player_profile::new_dummy(0, 0, "demo_player"),
            joined: false,
            health: PLAYER_MAX_HEALTH,
            alive: true,
            spawn_index: 0,
            last_seen: Instant::now(),
        }
    }
}

pub struct MatchServer {
    socket: UdpSocket,
    store: Arc<SessionStore>,
    peers: HashMap<SocketAddr, Peer>,
    spawn_rng: SpawnRng,
}

/// Tiny dependency-free PRNG used only to vary demo spawn selection. This is
/// deliberately not suitable for security or authoritative game simulation.
struct SpawnRng(u64);

impl SpawnRng {
    fn new(seed: u64) -> Self {
        Self(seed.max(1))
    }

    fn next_index(&mut self, upper_bound: usize) -> usize {
        debug_assert!(upper_bound > 0);
        let mut value = self.0;
        value ^= value << 13;
        value ^= value >> 7;
        value ^= value << 17;
        self.0 = value;
        value as usize % upper_bound
    }
}

impl MatchServer {
    pub fn bind(addr: &str, store: Arc<SessionStore>) -> io::Result<Self> {
        let socket = UdpSocket::bind(addr)?;
        socket.set_nonblocking(true)?;
        let seed = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap_or_default()
            .as_nanos() as u64
            ^ u64::from(socket.local_addr()?.port());
        Ok(Self {
            socket,
            store,
            peers: HashMap::new(),
            spawn_rng: SpawnRng::new(seed),
        })
    }

    /// The address the relay is bound to (used by tests to find the ephemeral port).
    #[cfg(test)]
    pub fn local_addr(&self) -> io::Result<SocketAddr> {
        self.socket.local_addr()
    }

    /// Run the relay loop forever (never returns; panics are contained by the
    /// caller's supervisor).
    pub fn run(mut self) -> ! {
        let mut buf = [0u8; 2048];
        loop {
            let frame_start = Instant::now();

            // Drain everything available this frame.
            loop {
                match self.socket.recv_from(&mut buf) {
                    Ok((len, addr)) => self.handle_datagram(addr, buf[..len].to_vec()),
                    Err(error) if error.kind() == io::ErrorKind::WouldBlock => break,
                    Err(error) => {
                        log::error!("recv_from failed: {error}");
                        break;
                    }
                }
            }

            self.reap_peers();

            // Keepalives.
            let socket = &self.socket;
            for (addr, peer) in self.peers.iter_mut() {
                peer.transport.maintain(socket, *addr);
            }

            if let Some(remaining) = FRAME_DURATION.checked_sub(frame_start.elapsed()) {
                std::thread::sleep(remaining);
            }
        }
    }

    fn handle_datagram(&mut self, addr: SocketAddr, datagram: Vec<u8>) {
        if !self.peers.contains_key(&addr) && self.peers.len() >= PEER_LIMIT {
            log::warn!("peer limit ({PEER_LIMIT}) reached; dropping datagram from {addr}");
            return;
        }

        let peer = self.peers.entry(addr).or_insert_with(Peer::new);
        peer.last_seen = Instant::now();
        let messages = peer
            .transport
            .handle_datagram(&datagram, &self.socket, addr);
        for message in messages {
            self.handle_game_message(addr, message);
        }
    }

    fn handle_game_message(&mut self, from: SocketAddr, message: ClientGameMessageKind) {
        let is_connection_request =
            matches!(&message, ClientGameMessageKind::ConnectionRequest { .. });
        if !is_connection_request && !self.peers.get(&from).is_some_and(|peer| peer.registered) {
            log::warn!("ignoring pre-registration match message from {from}");
            return;
        }

        match message {
            ClientGameMessageKind::ConnectionRequest { session_id } => {
                self.register_peer(from, session_id);
            }

            ClientGameMessageKind::GetStartupInfo => {
                // Tell this client about the whole current roster: how many players
                // to expect, then a profile per player (its own marked is_local).
                let match_id = self.peers[&from].match_id;
                let mut roster: Vec<(u8, game_team_id, String, raw_player_profile, bool)> = self
                    .peers
                    .iter()
                    .filter(|(_, peer)| peer.registered && peer.match_id == match_id)
                    .map(|(addr, peer)| {
                        (
                            peer.player_id,
                            peer.team,
                            peer.name.clone(),
                            peer.profile,
                            *addr == from,
                        )
                    })
                    .collect();
                roster.sort_by_key(|(player_id, ..)| *player_id);

                self.send_to(from, game::match_options(roster.len() as u8));
                for (player_id, team, name, profile, is_local) in roster {
                    self.send_to(
                        from,
                        ServerGameMessageKind::PlayerProfile {
                            player_profile: Box::new(game::player_profile(
                                profile, player_id, team, &name, is_local,
                            )),
                        },
                    );
                }
            }

            ClientGameMessageKind::JoinMatch => {
                let match_id = self.peers[&from].match_id;
                let spawn_index = self.select_spawn_index(match_id);
                let Some(peer) = self.peers.get_mut(&from) else {
                    return;
                };
                peer.joined = true;
                peer.health = PLAYER_MAX_HEALTH;
                peer.alive = true;
                peer.spawn_index = spawn_index;
                let player_id = peer.player_id;

                // Spawn the joining player for itself and start the match.
                self.send_to(
                    from,
                    ServerGameMessageKind::GameStatusChanged {
                        game_status: game_status::inprocess,
                    },
                );
                self.send_to(from, self.spawn_message(match_id, player_id));

                // Let everyone already in the match see the newcomer.
                self.broadcast_to_others(from, self.spawn_message(match_id, player_id));
            }

            ClientGameMessageKind::TeamBasesInitializeInfo => {
                // Spawn every other already-joined player for this client, then
                // tell it who is connected.
                let match_id = self.peers[&from].match_id;
                let others: Vec<u8> = self
                    .peers
                    .iter()
                    .filter(|(addr, peer)| {
                        **addr != from && peer.joined && peer.match_id == match_id
                    })
                    .map(|(_, peer)| peer.player_id)
                    .collect();
                for player_id in others {
                    self.send_to(from, self.spawn_message(match_id, player_id));
                }
                self.send_to(
                    from,
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: self.connected_bitmask(match_id),
                    },
                );
            }

            ClientGameMessageKind::ClientPlayerUpdate {
                player_input,
                player_state,
                time_in_ms: _,
            } => {
                let Some(peer) = self.peers.get(&from) else {
                    return;
                };
                let player_id = peer.player_id;
                let active_slot = game::active_weapon_slot(&peer.profile)
                    .unwrap_or(profile_slot_enum::weapon1_slot);
                // Dumb relay: forward this player's movement to everyone else. The
                // client message carries no weapon_state, so use the active slot
                // from the selected loadout.
                self.broadcast_to_others(
                    from,
                    ServerGameMessageKind::ServerPlayerInput {
                        player_id,
                        player_input,
                        player_state,
                        weapon_state: weapon_state {
                            slot_id: active_slot as u8,
                            ammo_slot_id: 0,
                            state: 0,
                        },
                    },
                );
            }

            ClientGameMessageKind::ClientPlayerHit(hit) => {
                let Some((match_id, hit, kill)) = self.apply_player_hit(from, hit) else {
                    return;
                };
                self.broadcast_to_match(match_id, ServerGameMessageKind::HitPlayer(hit));
                if let Some(kill) = kill {
                    self.broadcast_to_match(match_id, ServerGameMessageKind::KillPlayer(kill));
                }
            }
        }
    }

    fn apply_player_hit(
        &mut self,
        from: SocketAddr,
        hit: PlayerHit,
    ) -> Option<(u32, PlayerHit, Option<PlayerKill>)> {
        let (match_id, hit) = self.validate_player_hit(from, hit)?;
        let item_dict_id = self
            .peers
            .get(&from)
            .and_then(|peer| game::active_weapon_dict_id(&peer.profile))
            .map(u32::from)
            .unwrap_or_default();
        let target = self.peers.values_mut().find(|peer| {
            peer.registered
                && peer.joined
                && peer.match_id == match_id
                && peer.player_id == hit.being_hit
        })?;

        // This demo intentionally treats the reported amount as final damage.
        // Armor, body-part multipliers, and damage-model affects belong to the
        // future authoritative engine implementation.
        if !target.alive {
            return None;
        }
        target.health = (target.health - hit.amount).max(0.0);
        let kill = if target.health == 0.0 {
            target.alive = false;
            Some(PlayerKill {
                victim_id: hit.being_hit,
                killer_id: hit.hit_initiator,
                is_headshot: hit.body_part.eq_ignore_ascii_case("head"),
                item_dict_id,
            })
        } else {
            None
        };
        Some((match_id, hit, kill))
    }

    fn validate_player_hit(
        &self,
        from: SocketAddr,
        mut hit: PlayerHit,
    ) -> Option<(u32, PlayerHit)> {
        let source = self
            .peers
            .get(&from)
            .filter(|peer| peer.registered && peer.joined)?;

        // Never trust the attacker ID supplied in the synthetic payload. The
        // UDP peer's registered identity is the authority for this demo.
        hit.hit_initiator = source.player_id;

        // The stock 0.100b HitPlayer deserializer reads these two IDs as bools,
        // so its wire format can address only players 0 and 1. Keep the demo
        // explicit instead of silently aliasing every nonzero player to ID 1.
        if hit.hit_initiator > 1 || hit.being_hit > 1 {
            log::warn!(
                "dropping hit with stock-incompatible players {} -> {}",
                hit.hit_initiator,
                hit.being_hit
            );
            return None;
        }

        let target_is_present = self.peers.values().any(|peer| {
            peer.registered
                && peer.joined
                && peer.match_id == source.match_id
                && peer.player_id == hit.being_hit
        });
        target_is_present.then_some((source.match_id, hit))
    }

    fn register_peer(&mut self, addr: SocketAddr, session_id: u32) {
        if self.peers.get(&addr).is_some_and(|peer| peer.registered) {
            log::debug!("ignoring duplicate registration from {addr}");
            return;
        }

        let assignment = self.store.match_assignment(session_id);
        let match_id = assignment
            .map(|assignment| assignment.match_id)
            .unwrap_or(DEFAULT_MATCH_ID);
        let team = match assignment {
            Some(a) if a.team_id == 2 => game_team_id::team_2,
            _ => game_team_id::team_1,
        };

        let player_id = (0..MAX_PLAYERS).find(|candidate| {
            !self.peers.values().any(|peer| {
                peer.registered && peer.match_id == match_id && peer.player_id == *candidate
            })
        });
        let Some(player_id) = player_id else {
            log::warn!(
                "match {match_id:#x} full ({MAX_PLAYERS} players); rejecting session {session_id:#x}"
            );
            // The transport has already acknowledged the connection request.
            // Remove it now so it cannot continue with the default player ID.
            self.peers.remove(&addr);
            return;
        };

        let account = self.store.account_for_session(session_id);
        let name = account
            .as_ref()
            .map(|account| account.lock().unwrap().name.clone())
            .unwrap_or_else(|| format!("player_{player_id}"));
        let profile = self
            .store
            .selected_profile(session_id)
            .or_else(|| {
                account
                    .as_ref()
                    .and_then(|account| account.lock().unwrap().profile_contents.first().copied())
            })
            .unwrap_or_else(|| {
                raw_player_profile::new_dummy(u32::from(player_id), 0, "demo_player")
            });

        if let Some(peer) = self.peers.get_mut(&addr) {
            peer.registered = true;
            peer.match_id = match_id;
            peer.player_id = player_id;
            peer.team = team;
            peer.name = name;
            peer.profile = profile;
        }

        log::info!(
            "session {session_id:#x} is player {player_id} in match {match_id:#x} \
             (team {team:?}) at {addr}",
        );
    }

    fn select_spawn_index(&mut self, match_id: u32) -> usize {
        let spawn_count = game::spawn_position_count();
        let available: Vec<usize> = (0..spawn_count)
            .filter(|candidate| {
                !self.peers.values().any(|peer| {
                    peer.joined && peer.match_id == match_id && peer.spawn_index == *candidate
                })
            })
            .collect();

        if available.is_empty() {
            self.spawn_rng.next_index(spawn_count)
        } else {
            available[self.spawn_rng.next_index(available.len())]
        }
    }

    /// A `SpawnPlayer` for `player_id` at its assigned demo spawn point.
    fn spawn_message(&self, match_id: u32, player_id: u8) -> ServerGameMessageKind {
        let peer = self.peers.values().find(|peer| {
            peer.registered && peer.match_id == match_id && peer.player_id == player_id
        });
        let spawn_index = peer.map_or(player_id as usize, |peer| peer.spawn_index);
        let profile = peer.map_or_else(
            || raw_player_profile::new_dummy(u32::from(player_id), 0, "demo_player"),
            |peer| peer.profile,
        );
        ServerGameMessageKind::SpawnPlayer {
            player_id,
            player: game::spawn_content(spawn_index, &profile),
        }
    }

    /// Bitmask of registered (connected) players, one bit per player id.
    fn connected_bitmask(&self, match_id: u32) -> u32 {
        self.peers
            .values()
            .filter(|peer| peer.registered && peer.match_id == match_id)
            .fold(0, |mask, peer| mask | (1 << peer.player_id))
    }

    fn send_to(&mut self, addr: SocketAddr, message: ServerGameMessageKind) {
        if let Some(peer) = self.peers.get_mut(&addr) {
            peer.transport
                .send_game_message(&self.socket, addr, message);
        }
    }

    fn broadcast_to_others(&mut self, except: SocketAddr, message: ServerGameMessageKind) {
        let Some(match_id) = self.peers.get(&except).map(|peer| peer.match_id) else {
            return;
        };
        let socket = &self.socket;
        for (addr, peer) in self.peers.iter_mut() {
            if *addr != except && peer.joined && peer.match_id == match_id {
                peer.transport
                    .send_game_message(socket, *addr, message.clone());
            }
        }
    }

    fn broadcast_to_match(&mut self, match_id: u32, message: ServerGameMessageKind) {
        let socket = &self.socket;
        for (addr, peer) in self.peers.iter_mut() {
            if peer.joined && peer.match_id == match_id {
                peer.transport
                    .send_game_message(socket, *addr, message.clone());
            }
        }
    }

    /// Drop peers that have disconnected or gone silent, and tell the rest who is
    /// left.
    fn reap_peers(&mut self) {
        let now = Instant::now();
        let gone: Vec<SocketAddr> = self
            .peers
            .iter()
            .filter(|(_, peer)| {
                peer.transport.is_disconnected()
                    || now.duration_since(peer.last_seen) > IDLE_TIMEOUT
            })
            .map(|(addr, _)| *addr)
            .collect();

        if gone.is_empty() {
            return;
        }

        for addr in gone {
            if let Some(peer) = self.peers.remove(&addr) {
                log::info!("player {} ({addr}) disconnected", peer.player_id);
            }
        }

        // Best-effort leave signal: refresh each match's connected bitmask.
        let bitmasks: HashMap<u32, u32> = self.peers.values().filter(|peer| peer.registered).fold(
            HashMap::new(),
            |mut bitmasks, peer| {
                *bitmasks.entry(peer.match_id).or_default() |= 1 << peer.player_id;
                bitmasks
            },
        );
        let socket = &self.socket;
        for (addr, peer) in self.peers.iter_mut() {
            if peer.joined {
                peer.transport.send_game_message(
                    socket,
                    *addr,
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: bitmasks
                            .get(&peer.match_id)
                            .copied()
                            .unwrap_or_default(),
                    },
                );
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::Duration;

    fn peer_addr(port: u16) -> SocketAddr {
        SocketAddr::from(([127, 0, 0, 1], port))
    }

    fn joined_peer(match_id: u32, player_id: u8) -> Peer {
        Peer {
            registered: true,
            match_id,
            player_id,
            joined: true,
            ..Peer::new()
        }
    }

    fn player_hit(hit_initiator: u8, being_hit: u8) -> PlayerHit {
        PlayerHit {
            hit_initiator,
            being_hit,
            body_part: "head".to_owned(),
            damage_type: "injury".to_owned(),
            amount: 50.0,
            armor_piercing: 0.25,
        }
    }

    /// A minimal, valid client "connection" datagram: local_seq 0, remote_seq
    /// 0xFFFF, ack word 0 (→ remote_ack_bits 0x8000, single packet), then a
    /// `connection_request` (0x40) with order_id 0 and the session id.
    fn connection_packet(session_id: u32) -> Vec<u8> {
        let mut packet = vec![0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x40, 0x00, 0x00];
        packet.extend(session_id.to_le_bytes());
        packet
    }

    #[test]
    fn responds_to_a_connection_request() {
        let store = Arc::new(SessionStore::new());
        let server = MatchServer::bind("127.0.0.1:0", store).unwrap();
        let server_addr = server.local_addr().unwrap();
        std::thread::spawn(move || server.run());

        let client = UdpSocket::bind("127.0.0.1:0").unwrap();
        client
            .set_read_timeout(Some(Duration::from_secs(2)))
            .unwrap();
        client
            .send_to(&connection_packet(0xDD00), server_addr)
            .unwrap();

        let mut buf = [0u8; 2048];
        let (len, _) = client
            .recv_from(&mut buf)
            .expect("relay should answer a connection request");

        // Server packet: 6-byte header, then the first message's type byte.
        // 0x80 = match_server_connection_successful.
        assert!(len >= 7, "response too short: {len} bytes");
        assert_eq!(
            buf[6], 0x80,
            "expected ConnectionSuccessful, got {:#x}",
            buf[6]
        );
    }

    #[test]
    fn assigns_player_ids_per_match() {
        let store = Arc::new(SessionStore::new());
        for session_id in 0..=20 {
            store.join_match(session_id);
        }
        let mut server = MatchServer::bind("127.0.0.1:0", store).unwrap();

        for session_id in 0..=20 {
            let addr = peer_addr(10_000 + session_id as u16);
            server.peers.insert(addr, Peer::new());
            server.register_peer(addr, session_id);
        }

        let first = &server.peers[&peer_addr(10_000)];
        let twenty_first = &server.peers[&peer_addr(10_020)];
        assert_ne!(first.match_id, twenty_first.match_id);
        assert_eq!(first.player_id, 0);
        assert_eq!(twenty_first.player_id, 0);
    }

    #[test]
    fn reuses_a_vacated_player_id() {
        let store = Arc::new(SessionStore::new());
        for session_id in 1..=3 {
            store.join_match(session_id);
        }
        let mut server = MatchServer::bind("127.0.0.1:0", store).unwrap();

        for session_id in 1..=2 {
            let addr = peer_addr(11_000 + session_id as u16);
            server.peers.insert(addr, Peer::new());
            server.register_peer(addr, session_id);
        }
        server.peers.remove(&peer_addr(11_001));

        let replacement = peer_addr(11_003);
        server.peers.insert(replacement, Peer::new());
        server.register_peer(replacement, 3);
        assert_eq!(server.peers[&replacement].player_id, 0);
    }

    #[test]
    fn removes_an_over_capacity_unassigned_peer() {
        let store = Arc::new(SessionStore::new());
        let mut server = MatchServer::bind("127.0.0.1:0", store).unwrap();

        for session_id in 0..=20 {
            let addr = peer_addr(12_000 + session_id as u16);
            server.peers.insert(addr, Peer::new());
            server.register_peer(addr, session_id);
        }

        assert!(!server.peers.contains_key(&peer_addr(12_020)));
    }

    #[test]
    fn registration_uses_the_profile_selected_in_the_lobby() {
        let store = Arc::new(SessionStore::new());
        let mut selected = raw_player_profile::new_dummy(1, 400_000, "selected");
        selected.slots[profile_slot_enum::weapon1_slot].dict_id = 55;
        store.ready_for_match(0xDD00, selected, &[selected]);

        let mut server = MatchServer::bind("127.0.0.1:0", Arc::clone(&store)).unwrap();
        let addr = peer_addr(12_100);
        server.peers.insert(addr, Peer::new());
        server.register_peer(addr, 0xDD00);

        assert_eq!(server.peers[&addr].profile.profile_id, 400_000);
        assert_eq!(
            server.peers[&addr].profile.slots[profile_slot_enum::weapon1_slot].dict_id,
            55
        );
    }

    #[test]
    fn authenticates_hit_attacker_from_the_sending_peer() {
        let mut server = MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        let attacker = peer_addr(13_000);
        server
            .peers
            .insert(attacker, joined_peer(DEFAULT_MATCH_ID, 0));
        server
            .peers
            .insert(peer_addr(13_001), joined_peer(DEFAULT_MATCH_ID, 1));

        let (match_id, hit) = server
            .validate_player_hit(attacker, player_hit(99, 1))
            .unwrap();
        assert_eq!(match_id, DEFAULT_MATCH_ID);
        assert_eq!(hit.hit_initiator, 0);
        assert_eq!(hit.being_hit, 1);
    }

    #[test]
    fn rejects_hit_for_an_absent_or_unrepresentable_target() {
        let mut server = MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        let attacker = peer_addr(14_000);
        server
            .peers
            .insert(attacker, joined_peer(DEFAULT_MATCH_ID, 0));
        server
            .peers
            .insert(peer_addr(14_001), joined_peer(DEFAULT_MATCH_ID + 1, 1));

        assert!(
            server
                .validate_player_hit(attacker, player_hit(0, 1))
                .is_none()
        );
        assert!(
            server
                .validate_player_hit(attacker, player_hit(0, 2))
                .is_none()
        );
    }

    #[test]
    fn kills_a_player_when_simplified_health_reaches_zero() {
        let mut server = MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        let attacker = peer_addr(15_000);
        let victim = peer_addr(15_001);
        server
            .peers
            .insert(attacker, joined_peer(DEFAULT_MATCH_ID, 0));
        server
            .peers
            .insert(victim, joined_peer(DEFAULT_MATCH_ID, 1));

        let (_, _, first_kill) = server.apply_player_hit(attacker, player_hit(0, 1)).unwrap();
        assert_eq!(first_kill, None);
        assert_eq!(server.peers[&victim].health, 50.0);

        let (_, _, second_kill) = server.apply_player_hit(attacker, player_hit(0, 1)).unwrap();
        assert_eq!(
            second_kill,
            Some(PlayerKill {
                victim_id: 1,
                killer_id: 0,
                is_headshot: true,
                item_dict_id: 13,
            })
        );
        assert_eq!(server.peers[&victim].health, 0.0);
        assert!(!server.peers[&victim].alive);

        assert!(
            server
                .apply_player_hit(attacker, player_hit(0, 1))
                .is_none(),
            "a dead player must not emit duplicate hits or kills"
        );
    }

    #[test]
    fn assigns_unused_spawn_points_within_a_match() {
        let mut server = MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        server.spawn_rng = SpawnRng::new(123);

        let first = peer_addr(16_000);
        let second = peer_addr(16_001);
        let first_spawn = server.select_spawn_index(DEFAULT_MATCH_ID);
        let mut first_peer = joined_peer(DEFAULT_MATCH_ID, 0);
        first_peer.spawn_index = first_spawn;
        server.peers.insert(first, first_peer);

        let second_spawn = server.select_spawn_index(DEFAULT_MATCH_ID);
        let mut second_peer = joined_peer(DEFAULT_MATCH_ID, 1);
        second_peer.spawn_index = second_spawn;
        server.peers.insert(second, second_peer);

        assert!(first_spawn < game::spawn_position_count());
        assert!(second_spawn < game::spawn_position_count());
        assert_ne!(first_spawn, second_spawn);
    }

    #[test]
    fn spawn_selection_is_isolated_per_match() {
        let mut server = MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        server.spawn_rng = SpawnRng::new(7);
        let occupied = peer_addr(17_000);
        server
            .peers
            .insert(occupied, joined_peer(DEFAULT_MATCH_ID, 0));
        server.peers.get_mut(&occupied).unwrap().spawn_index = 0;

        let selection = server.select_spawn_index(DEFAULT_MATCH_ID + 1);

        let mut empty_server =
            MatchServer::bind("127.0.0.1:0", Arc::new(SessionStore::new())).unwrap();
        empty_server.spawn_rng = SpawnRng::new(7);
        assert_eq!(
            selection,
            empty_server.select_spawn_index(DEFAULT_MATCH_ID + 1),
            "an occupied point in another match must not affect this match"
        );
    }
}
