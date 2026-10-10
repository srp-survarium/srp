// SPDX-License-Identifier: GPL-3.0-or-later
// Multi-client match server: a dumb relay.
//
// SRP is a mock — this does NOT simulate the game. It owns one UDP socket,
// demultiplexes datagrams to a per-peer `Transport` (reliable-UDP), and:
//   * runs each client through the connect/startup/join handshake, reflecting the
//     per-match live roster (one `PlayerProfile`/`SpawnPlayer` per connected
//     peer), and
//   * relays each client's `ClientPlayerUpdate` to every OTHER peer as a
//     `ServerPlayerInput`, so players see each other move.
//   * validates the identity/roster fields of a synthetic client hit report and
//     rebroadcasts it as the stock server `HitPlayer` message.
//
// Movement and damage remain client-reported demo data; there is no geometry,
// health simulation, or reconciliation. Roster handling is best-effort (see
// WORK.md) — the clean case is clients connecting before either readies up;
// late joins may render imperfectly and need in-game iteration.

use std::collections::HashMap;
use std::io;
use std::net::{SocketAddr, UdpSocket};
use std::sync::Arc;
use std::time::{Duration, Instant};

use session::SessionStore;
use survarium::player_input::weapon_state;
use survarium::player_profile::raw::game_team_id;

use crate::game;
use crate::message::server_message::raw::game_status;
use crate::message::{ClientGameMessageKind, PlayerHit, ServerGameMessageKind};
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

struct Peer {
    transport: Transport,
    /// `false` until the peer's `ConnectionRequest` assigns it a player id.
    registered: bool,
    match_id: u32,
    player_id: u8,
    team: game_team_id,
    name: String,
    /// `true` once the peer has sent `JoinMatch` (is in the match).
    joined: bool,
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
            joined: false,
            last_seen: Instant::now(),
        }
    }
}

pub struct MatchServer {
    socket: UdpSocket,
    store: Arc<SessionStore>,
    peers: HashMap<SocketAddr, Peer>,
}

impl MatchServer {
    pub fn bind(addr: &str, store: Arc<SessionStore>) -> io::Result<Self> {
        let socket = UdpSocket::bind(addr)?;
        socket.set_nonblocking(true)?;
        Ok(Self {
            socket,
            store,
            peers: HashMap::new(),
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
                let mut roster: Vec<(u8, game_team_id, String, bool)> = self
                    .peers
                    .iter()
                    .filter(|(_, peer)| peer.registered && peer.match_id == match_id)
                    .map(|(addr, peer)| {
                        (peer.player_id, peer.team, peer.name.clone(), *addr == from)
                    })
                    .collect();
                roster.sort_by_key(|(player_id, ..)| *player_id);

                self.send_to(from, game::match_options(roster.len() as u8));
                for (player_id, team, name, is_local) in roster {
                    self.send_to(
                        from,
                        ServerGameMessageKind::PlayerProfile {
                            player_profile: Box::new(game::player_profile(
                                player_id, team, &name, is_local,
                            )),
                        },
                    );
                }
            }

            ClientGameMessageKind::JoinMatch => {
                let Some(peer) = self.peers.get_mut(&from) else {
                    return;
                };
                peer.joined = true;
                let player_id = peer.player_id;

                // Spawn the joining player for itself and start the match.
                self.send_to(
                    from,
                    ServerGameMessageKind::GameStatusChanged {
                        game_status: game_status::inprocess,
                    },
                );
                self.send_to(from, self.spawn_message(player_id));

                // Let everyone already in the match see the newcomer.
                self.broadcast_to_others(from, self.spawn_message(player_id));
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
                    self.send_to(from, self.spawn_message(player_id));
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
                // Dumb relay: forward this player's movement to everyone else. The
                // client message carries no weapon_state, so we send a default one.
                // @NOTE: best-effort — see ServerPlayerInput serialization note.
                self.broadcast_to_others(
                    from,
                    ServerGameMessageKind::ServerPlayerInput {
                        player_id,
                        player_input,
                        player_state,
                        weapon_state: weapon_state {
                            slot_id: 0,
                            ammo_slot_id: 0,
                            state: 0,
                        },
                    },
                );
            }

            ClientGameMessageKind::ClientPlayerHit(hit) => {
                let Some((match_id, hit)) = self.validate_player_hit(from, hit) else {
                    return;
                };
                self.broadcast_to_match(match_id, ServerGameMessageKind::HitPlayer(hit));
            }
        }
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

        let name = self
            .store
            .account_for_session(session_id)
            .map(|account| account.lock().unwrap().name.clone())
            .unwrap_or_else(|| format!("player_{player_id}"));

        if let Some(peer) = self.peers.get_mut(&addr) {
            peer.registered = true;
            peer.match_id = match_id;
            peer.player_id = player_id;
            peer.team = team;
            peer.name = name;
        }

        log::info!(
            "session {session_id:#x} is player {player_id} in match {match_id:#x} \
             (team {team:?}) at {addr}",
        );
    }

    /// A `SpawnPlayer` for `player_id` at its canned spawn point.
    fn spawn_message(&self, player_id: u8) -> ServerGameMessageKind {
        ServerGameMessageKind::SpawnPlayer {
            player_id,
            player: game::spawn_content(player_id as usize),
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
}
