// SPDX-License-Identifier: GPL-3.0-or-later
use std::{
    collections::{BTreeMap, VecDeque},
    net::SocketAddr,
};
use survarium::protocol_026::{
    self as protocol, Direction, Fragment, Frame,
    match_options::{InventoryItem, ItemValue, MatchOptions, Player, Profile, Slot},
};
use vostok::network_packet::udp_026::Header;

type Error = Box<dyn std::error::Error>;
type Outbound = Vec<(SocketAddr, Vec<u8>)>;
const NEWEST: u128 = 1 << 127;

#[derive(Default)]
struct History {
    newest: Option<u8>,
    mask: u128,
}
impl History {
    fn receive(&mut self, sequence: u8) -> bool {
        let Some(newest) = self.newest else {
            self.newest = Some(sequence);
            self.mask = NEWEST;
            return true;
        };
        let forward = sequence.wrapping_sub(newest);
        if forward != 0 && forward < 128 {
            self.mask = (self.mask >> forward) | NEWEST;
            self.newest = Some(sequence);
            return true;
        }
        let age = newest.wrapping_sub(sequence);
        if age >= 127 {
            return false;
        }
        let bit = NEWEST >> age;
        let fresh = self.mask & bit == 0;
        self.mask |= bit;
        fresh
    }
}

struct Pending {
    frame: Vec<u8>,
    attempts: VecDeque<u64>,
    last_send: Option<u64>,
    created: u64,
    retry_ms: u64,
    lifetime_ms: Option<u64>,
}
struct Join {
    baseline: u32,
    selected_cursor: u64,
    sent_cursor: u64,
    began: u64,
    state: Option<Vec<u8>>,
}

struct Restoration {
    time: u32,
    cursor: u64,
    began: u64,
    deadline: u64,
    invalidated: bool,
}

struct Peer {
    late: bool,
    active_at: Option<u32>,
    join: Option<Join>,
    session: u32,
    slot: u8,
    history: History,
    generation: u64,
    unique: u8,
    pending: Vec<Pending>,
    startup_sent: bool,
    ready: bool,
    last_seen: u64,
    last_send: u64,
    ack_dirty: bool,
    snapshot: Option<crate::snapshot::Upload>,
    clock_confirmed: bool,
    clock: crate::clock::Clock,
    state_sent: bool,
    resync_sequence: u8,
    restoring: Option<Restoration>,
}
impl Peer {
    fn packet(&mut self, payload: &[u8], now: u64) -> Result<Vec<u8>, Error> {
        let header = Header {
            sequence: self.generation as u8,
            ack_sequence: self.history.newest.unwrap_or(0),
            ack_mask: self.history.mask,
            ack_bits: 127,
            single_message: true,
        };
        let bytes = header.encode(payload)?;
        self.generation += 1;
        self.last_send = now;
        self.ack_dirty = false;
        Ok(bytes)
    }

    fn acknowledge(&mut self, header: Header) {
        if self.generation == 0 {
            return;
        }
        let age = ((self.generation - 1) as u8).wrapping_sub(header.ack_sequence);
        if age >= 128 || u64::from(age) >= self.generation {
            return;
        }
        let acknowledged_generation = self.generation - 1 - u64::from(age);
        self.pending.retain(|pending| {
            !pending.attempts.iter().any(|generation| {
                *generation <= acknowledged_generation
                    && acknowledged_generation - generation < u64::from(header.ack_bits)
                    && header.acknowledges(*generation as u8)
            })
        });
    }

    fn enqueue(&mut self, id: u8, body: &[u8], players: u8, now: u64) -> Result<(), Error> {
        // E3/E4 and E9..EC use the timings in the retail delivery getter
        // (0x279b10). E5 is deliberately retried until acked for initial setup;
        // the retail metadata instead leaves its repetition to the application.
        let (retry_ms, lifetime_ms) = match id {
            0xe3 | 0xe4 | 0xe8 => (500, None),
            0xe5 => (200, None),
            0xe6 => (2000, Some(1500)), // One timing probe, never a stale retry.
            0xe7 => (50, Some(250)),
            0xf7 => (500, Some(2000)),
            0xf8 => (250, None),
            0xe9..=0xec => (50, Some(250)),
            _ => return Err("unsupported outbound delivery policy".into()),
        };
        let unique = if matches!(id, 0xe4..=0xe8 | 0xf6) {
            let value = self.unique;
            self.unique = self.unique.wrapping_add(1);
            Some(value)
        } else {
            None
        };
        let parts = body.len().div_ceil(480).max(1);
        if parts > 255 {
            return Err("message exceeds fragment count limit".into());
        }
        if self.pending.len() + parts > 1024 {
            return Err("outbound queue is full".into());
        }
        for index in 0..parts {
            let start = index * 480;
            let end = (start + 480).min(body.len());
            let fragment = (parts > 1).then_some(Fragment {
                index: index as u8,
                count: (index == 0).then_some(parts as u8),
            });
            let frame = protocol::encode_frame(
                Frame {
                    id,
                    unique_id: unique,
                    fragment,
                    body: &body[start..end],
                },
                true,
                if matches!(id, 0xf7 | 0xf8) {
                    Direction::ServerSnapshots
                } else {
                    Direction::Server
                },
                players,
            )?;
            self.pending.push(Pending {
                frame,
                attempts: VecDeque::new(),
                last_send: None,
                created: now,
                retry_ms,
                lifetime_ms,
            });
        }
        Ok(())
    }

    fn flush(&mut self, now: u64) -> Result<Vec<Vec<u8>>, Error> {
        self.pending.retain(|pending| {
            pending
                .lifetime_ms
                .is_none_or(|lifetime| now.saturating_sub(pending.created) < lifetime)
        });
        let mut out = Vec::new();
        // Keep an entire flush below the half-range of the 8-bit sequence space.
        for index in 0..self.pending.len() {
            if out.len() == 64 {
                break;
            }
            if self.pending[index]
                .last_send
                .is_some_and(|last| now.saturating_sub(last) < self.pending[index].retry_ms)
            {
                continue;
            }
            let frame = self.pending[index].frame.clone();
            let generation = self.generation;
            out.push(self.packet(&frame, now)?);
            let pending = &mut self.pending[index];
            pending.last_send = Some(now);
            pending.attempts.push_back(generation);
            while pending.attempts.len() > 9 {
                pending.attempts.pop_front();
            }
        }
        if now.saturating_sub(self.last_send) >= if self.ack_dirty { 25 } else { 500 } {
            out.push(self.packet(&[0xfc], now)?);
        }
        Ok(out)
    }
}

pub struct Server {
    sessions: BTreeMap<u32, u8>,
    pub results: bool,
    pub finish_timed: bool,
    pub finish_objective: bool,
    battery_completion: match_server_026::battery::Completion,
    /// Diagnostic only: exercise native finish/UI at a chosen game timestamp.
    pub finish_after_ms: Option<u32>,
    finishing: Option<(u32, u64)>,
    pub snapshots: bool,
    pub clock_sync: bool,
    pub clock_fault: Option<(u8, u32, i16)>,
    clock_fault_sent: bool,
    pub start_players: u8,
    journal: crate::replay::Journal,
    membership: BTreeMap<u32, u32>,
    /// First scheduled entry per roster slot, retained beyond replay history.
    first_entry: BTreeMap<u8, u32>,
    initial_time: u32,
    initial_state: Option<Vec<u8>>,
    membership_sent: bool,
    port: u16,
    options: MatchOptions,
    peers: BTreeMap<SocketAddr, Peer>,
    started: Option<u64>,
    monitor: crate::recovery::Monitor,
    pub recover: bool,
    recovery_targets: BTreeMap<u8, u32>,
    next_recovery_at: u64,
    /// Diagnostic fault: withhold live relay to (slot, from_game_ms, to_game_ms).
    pub drop_relay: Option<(u8, u32, u32)>,
    dropped_relays: u32,
    fault_reported: bool,
    pub checkpoints: bool,
    checkpoint_request: Option<(SocketAddr, crate::snapshot::Request)>,
    last_checkpoint_attempt: u64,
    latest_checkpoint: Option<crate::snapshot::Checkpoint>,
    history: crate::history::History,
    /// Explicit local validation: restore once from a checkpoint at/after this time.
    pub restore_once_after_ms: Option<u32>,
    restored_once: bool,
}
impl Server {
    pub fn new(port: u16, players: u8, map_id: u8) -> Result<Self, Error> {
        if !(1..=20).contains(&players) {
            return Err("players must be 1..=20".into());
        }
        let roster = (0..players)
            .map(|slot| {
                let mut profile = Profile {
                    name: "Default".into(),
                    key: 1,
                    ..Profile::default()
                };
                profile.slots[7] = Some(Slot {
                    inventory_index: 0,
                    amount: 1,
                });
                profile.slots[8] = Some(Slot {
                    inventory_index: 1,
                    amount: 120,
                });
                Player {
                    team: slot % 2,
                    name: format!("Player{}", slot + 1),
                    clan_tag: String::new(),
                    key: u32::from(slot) + 1,
                    profiles: vec![profile],
                    inventory: vec![
                        InventoryItem {
                            id: 1,
                            dictionary_id: 3,
                            value: ItemValue::NonStackable {
                                value: 10000,
                                field_0c: 0,
                                field_10: 0,
                            },
                            switches: vec![],
                            attributes: vec![],
                        },
                        InventoryItem {
                            id: 2,
                            // 0.26g0 compatibility_47 pairs AK-74M (3) with
                            // 5.45x39 7N10 (217); low-tier ammo 7 is incompatible.
                            dictionary_id: 217,
                            value: ItemValue::Stack(120),
                            switches: vec![],
                            attributes: vec![],
                        },
                    ],
                }
            })
            .collect();
        let options = MatchOptions {
            players: roster,
            map_id,
            match_id: 1,
            match_level: 10,
            event_scores: match_server_026::scoring::development(),
            squads: [0; 20],
        };
        options.serialize()?;
        Ok(Self {
            sessions: BTreeMap::new(),
            results: false,
            finish_timed: false,
            finish_objective: false,
            battery_completion: Default::default(),
            finish_after_ms: None,
            finishing: None,
            snapshots: false,
            clock_sync: false,
            clock_fault: None,
            clock_fault_sent: false,
            start_players: players,
            journal: crate::replay::Journal::default(),
            membership: BTreeMap::from([(0, 0)]),
            first_entry: BTreeMap::new(),
            initial_time: 0,
            initial_state: None,
            membership_sent: false,
            port,
            options,
            peers: BTreeMap::new(),
            started: None,
            monitor: crate::recovery::Monitor::default(),
            recover: false,
            recovery_targets: BTreeMap::new(),
            next_recovery_at: 0,
            drop_relay: None,
            dropped_relays: 0,
            fault_reported: false,
            checkpoints: false,
            checkpoint_request: None,
            last_checkpoint_attempt: 0,
            latest_checkpoint: None,
            history: crate::history::History::default(),
            restore_once_after_ms: None,
            restored_once: false,
        })
    }

    /// Freeze local player identity, team and squad before publishing setup.
    pub fn set_roster(
        &mut self,
        members: &[match_server_026::roster::Member],
    ) -> Result<(), Error> {
        if !self.peers.is_empty() || self.started.is_some() {
            return Err("cannot change roster after admitting players".into());
        }
        match_server_026::roster::validate(members)?;
        if members.len() != self.options.players.len() {
            return Err("roster member count must equal --players".into());
        }
        self.sessions.clear();
        self.options.squads = [0; 20];
        for (slot, member) in members.iter().enumerate() {
            self.sessions.insert(member.session, slot as u8);
            self.options.players[slot].name.clone_from(&member.name);
            self.options.players[slot].team = member.team;
            self.options.squads[slot] = member.squad;
        }
        Ok(())
    }

    /// Setup and final results must use the same policy for the whole match.
    pub fn set_score_weights(&mut self, weights: [f32; 28]) -> Result<(), Error> {
        if !self.peers.is_empty() || self.started.is_some() {
            return Err("cannot change score weights after admitting players".into());
        }
        if weights.iter().any(|weight| !weight.is_finite()) {
            return Err("event weights must be finite".into());
        }
        self.options.event_scores = weights;
        Ok(())
    }

    pub fn receive(
        &mut self,
        address: SocketAddr,
        packet: &[u8],
        now: u64,
    ) -> Result<Outbound, Error> {
        let (header, body) = Header::decode(packet)?;
        let frames = protocol::decode_frames(
            body,
            header.single_message,
            if self.snapshots {
                Direction::ClientSnapshots
            } else {
                Direction::Client
            },
            self.options.players.len() as u8,
        )?;
        if frames.iter().any(|f| f.fragment.is_some()) {
            return Err("client fragments require a negotiated snapshot extension".into());
        }
        let mut out = Vec::new();
        // A restarted process may reuse its previous UDP endpoint. Treat its
        // new D8 as a replacement attempt before refreshing last_seen; otherwise
        // repeated handshakes keep the dead transport alive indefinitely.
        let same_endpoint_restart = !self.sessions.is_empty()
            && self.peers.get(&address).is_some_and(|peer| {
                peer.startup_sent
                    && frames.iter().any(|frame| {
                        frame.id == 0xd8 && frame.body[..4] == peer.session.to_le_bytes()
                    })
            });
        if !self.peers.contains_key(&address) || same_endpoint_restart {
            if self.finishing.is_some() {
                return Err("match is finishing".into());
            }
            let request = frames
                .iter()
                .find(|f| f.id == 0xd8)
                .ok_or("first message must be D8")?;
            if self.started.is_some() && (!self.membership_sent || !self.checkpoints) {
                return Err("late join requires completed bootstrap and --checkpoints".into());
            }
            let session = u32::from_le_bytes(request.body[..4].try_into()?);
            let slot = if self.sessions.is_empty() {
                if session == 0 || self.peers.values().any(|peer| peer.session == session) {
                    return Err("session must be nonzero and unique among active peers".into());
                }
                (0..self.options.players.len() as u8)
                    .find(|slot| self.peers.values().all(|p| p.slot != *slot))
                    .ok_or("roster is full")?
            } else {
                let slot = *self
                    .sessions
                    .get(&session)
                    .ok_or("session is not in the configured roster")?;
                if self.started.is_some() && self.first_entry.contains_key(&slot) && !self.recover {
                    return Err(
                        "configured player reconnect requires --recover and checkpoints".into(),
                    );
                }
                if let Some((old_address, old_peer)) =
                    self.peers.iter().find(|(_, p)| p.slot == slot)
                {
                    // A second live instance must not evict this identity. A
                    // crashed process stops heartbeats; its relaunch can use
                    // the ordinary checkpoint/replay admission after silence.
                    if now.saturating_sub(old_peer.last_seen) < 5000 {
                        return Err("configured player is still connected; retry after five seconds of silence".into());
                    }
                    if let Some(started) = self.started {
                        let game = u64::from(self.initial_time) + now.saturating_sub(started);
                        let donor = self.peers.values().any(|peer| {
                            peer.slot != slot
                                && peer.restoring.is_none()
                                && peer.active_at.is_some_and(|at| u64::from(at) <= game)
                        });
                        if !self.membership_sent || !donor {
                            return Err(
                                "active-match reconnect needs a surviving checkpoint donor".into(),
                            );
                        }
                    }
                    out.extend(self.remove_peer(*old_address, now)?);
                }
                slot
            };
            self.peers.insert(
                address,
                Peer {
                    late: self.started.is_some(),
                    active_at: None,
                    join: None,
                    session,
                    slot,
                    history: History::default(),
                    generation: 0,
                    unique: 0,
                    pending: Vec::new(),
                    startup_sent: false,
                    ready: false,
                    last_seen: now,
                    last_send: now,
                    ack_dirty: false,
                    snapshot: None,
                    clock_confirmed: false,
                    clock: crate::clock::Clock::default(),
                    state_sent: false,
                    resync_sequence: 1,
                    restoring: None,
                },
            );
            eprintln!("Peer {address} admitted to roster slot {slot}, session {session:08x}");
        }
        let game_time = self.started.map(|start| {
            self.initial_time
                .saturating_add(now.saturating_sub(start) as u32)
        });
        let joining = self.peers.values().any(|p| p.late && p.active_at.is_none());
        let retrying_restore = self.peers.values().any(|p| {
            p.restoring
                .as_ref()
                .is_some_and(|restore| restore.invalidated)
        });
        let reference_peer = self
            .peers
            .iter()
            .filter(|(_, peer)| {
                peer.restoring.is_none()
                    && peer
                        .active_at
                        .is_some_and(|at| game_time.is_some_and(|game| at <= game))
            })
            .min_by_key(|(_, peer)| (peer.active_at, peer.slot))
            .map(|(address, _)| *address);
        let peer = self.peers.get_mut(&address).unwrap();
        peer.last_seen = now;
        peer.acknowledge(header);
        peer.ack_dirty = true;
        if !peer.history.receive(header.sequence) {
            out.extend(self.poll(now)?);
            return Ok(out);
        }
        let mut relay = Vec::new();
        let mut remove = false;
        for frame in frames {
            if self.finishing.is_some() && !matches!(frame.id, 0xe0 | 0xfa | 0xfb | 0xfc | 0xfd) {
                continue;
            }
            match frame.id {
                0xd8 => {
                    if u32::from_le_bytes(frame.body[..4].try_into()?) != peer.session {
                        return Err("session changed on an existing connection".into());
                    }
                    if !peer.startup_sent
                        && !peer.pending.iter().any(|p| p.frame.first() == Some(&0xe3))
                    {
                        let ports = [self.port.to_le_bytes(), self.port.to_le_bytes()].concat();
                        peer.enqueue(0xe3, &ports, self.options.players.len() as u8, now)?;
                    }
                }
                0xd9 => {
                    if u32::from_le_bytes(frame.body.try_into()?) != peer.session {
                        return Err("startup session mismatch".into());
                    }
                    if !peer.startup_sent {
                        peer.pending.clear();
                        peer.enqueue(
                            0xe4,
                            &self.options.static_info(peer.slot)?,
                            self.options.players.len() as u8,
                            now,
                        )?;
                        peer.startup_sent = true;
                        eprintln!("Peer {address}: static match setup queued");
                    }
                }
                0xda if peer.startup_sent => {
                    if !peer.ready {
                        eprintln!("Peer {address}: resources loaded");
                    }
                    peer.ready = true;
                }
                0xe2 if self.snapshots && peer.startup_sent => {
                    if self.membership_sent && peer.active_at.is_some() {
                        if let Some((source, request)) = &mut self.checkpoint_request {
                            if *source == address && peer.restoring.is_none() {
                                match request.receive(frame.body) {
                                    Ok(Some(checkpoint)) => {
                                        eprintln!(
                                            "Verified checkpoint from slot {}: {} bytes at {} ms, CRC {:08x}",
                                            peer.slot,
                                            checkpoint.bytes.len(),
                                            checkpoint.time,
                                            checkpoint.crc
                                        );
                                        self.latest_checkpoint = Some(checkpoint);
                                        self.checkpoint_request = None;
                                        peer.pending.retain(|p| p.frame.first() != Some(&0xf7));
                                    }
                                    Ok(None) => {}
                                    Err(error) => {
                                        eprintln!(
                                            "Rejected checkpoint from slot {}: {error}",
                                            peer.slot
                                        );
                                        self.checkpoint_request = None;
                                        peer.pending.retain(|p| p.frame.first() != Some(&0xf7));
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    let was_complete = peer
                        .snapshot
                        .as_ref()
                        .is_some_and(|upload| upload.complete());
                    if crate::snapshot::Upload::receive(&mut peer.snapshot, frame.body)?
                        && !was_complete
                    {
                        let upload = peer.snapshot.as_ref().unwrap();
                        eprintln!(
                            "Peer {address}: initial snapshot {} bytes at {} ms",
                            upload.bytes.len(),
                            upload.time
                        );
                    }
                }
                0xdc | 0xdd if peer.active_at.is_some() && self.started.is_some() => {
                    let time_bytes = if frame.id == 0xdc { 1 } else { 2 };
                    let mut input = frame.body[..time_bytes].to_vec();
                    input.push(peer.slot);
                    input.extend_from_slice(&frame.body[time_bytes..]);
                    let opcode = if frame.id == 0xdc { 0xeb } else { 0xec };
                    let game_time = u32::try_from(
                        u64::from(self.initial_time) + now.saturating_sub(self.started.unwrap()),
                    )?;
                    if let Some(time) =
                        crate::history::input_time(frame.body, frame.id == 0xdd, game_time)
                    {
                        if time < peer.active_at.unwrap() || !self.history.accepts(time, game_time)
                        {
                            continue;
                        }
                        let changed = self.history.record(
                            crate::history::Input {
                                time,
                                slot: peer.slot,
                                opcode,
                                body: input.clone(),
                            },
                            game_time,
                        );
                        if changed {
                            self.journal.record(
                                crate::replay::Event {
                                    time,
                                    slot: peer.slot,
                                    opcode,
                                    body: input.clone(),
                                },
                                game_time,
                            );
                            self.monitor.input_changed(time);
                            if self
                                .latest_checkpoint
                                .as_ref()
                                .is_some_and(|s| s.time >= time)
                            {
                                self.latest_checkpoint = None;
                                self.battery_completion.invalidate();
                            }
                            if self
                                .checkpoint_request
                                .as_ref()
                                .is_some_and(|(_, r)| r.time >= time)
                            {
                                self.checkpoint_request = None;
                            }
                        }
                    } else {
                        continue;
                    }
                    relay.push((opcode, input));
                }
                0xdf if peer.active_at.is_some() => {
                    let crc = u32::from_le_bytes(frame.body[1..].try_into()?);
                    if let Some(started) = self.started {
                        let game = u32::try_from(
                            u64::from(self.initial_time) + now.saturating_sub(started),
                        )?;
                        if let Some(time) = crate::history::input_time(frame.body, false, game) {
                            if peer.restoring.is_none() {
                                self.monitor.observe(peer.slot, time, crc, game);
                            }
                        }
                    }
                    if self.checkpoints
                        && self.membership_sent
                        && reference_peer == Some(address)
                        && self.checkpoint_request.is_none()
                        && now.saturating_sub(self.last_checkpoint_attempt)
                            >= if self.recovery_targets.is_empty()
                                && !joining
                                && !retrying_restore
                                && !self.battery_completion.pending()
                            {
                                5000
                            } else {
                                1000
                            }
                    {
                        let game = u64::from(self.initial_time)
                            + now.saturating_sub(self.started.unwrap());
                        let reference = game / 50;
                        let delta = frame.body[0].wrapping_sub(reference as u8) as i8;
                        let tick = reference as i64 + i64::from(delta);
                        if let Ok(time) = u32::try_from(tick * 50) {
                            if time > self.initial_time && u64::from(time) <= game + 100 {
                                peer.enqueue(
                                    0xf7,
                                    &time.to_le_bytes(),
                                    self.options.players.len() as u8,
                                    now,
                                )?;
                                self.checkpoint_request = Some((
                                    address,
                                    crate::snapshot::Request {
                                        time,
                                        crc,
                                        requested_at: now,
                                        upload: None,
                                    },
                                ));
                                self.last_checkpoint_attempt = now;
                                eprintln!(
                                    "Requesting checkpoint from slot {} at {time} ms",
                                    peer.slot
                                );
                            }
                        }
                    }
                }
                0xfa => {
                    out.push((address, peer.packet(&[0xfb], now)?));
                    remove = true;
                }
                0xe0 | 0xfb | 0xfd => {
                    remove = true;
                }
                0xdb if peer.ready && self.started.is_some() => {
                    if self.clock_sync && peer.active_at.is_some() && peer.clock_confirmed {
                        if let Some(sample) =
                            peer.clock.receive(frame.body, now, game_time.unwrap())
                        {
                            eprintln!(
                                "Clock slot {}: RTT {} ms, error {} ms, correction {:?}",
                                peer.slot, sample.rtt, sample.error, sample.correction
                            );
                            if let Some(correction) = sample.correction {
                                peer.enqueue(
                                    0xe7,
                                    &correction.to_le_bytes(),
                                    self.options.players.len() as u8,
                                    now,
                                )?;
                            }
                        }
                    }
                    peer.clock_confirmed = true;
                    peer.pending
                        .retain(|pending| pending.frame.first() != Some(&0xe5));
                }
                0xde | 0xe1 | 0xfc => {}
                _ => {}
            }
        }
        if remove {
            relay.clear();
            out.extend(self.remove_peer(address, now)?);
        }
        if self.started.is_none()
            && self.peers.len() >= usize::from(self.start_players)
            && self.peers.values().all(|p| p.ready)
            && (!self.snapshots
                || self
                    .peers
                    .values()
                    .all(|p| p.snapshot.as_ref().is_some_and(|s| s.complete())))
        {
            let mut initial_time = 0u32;
            let mut initial_state = None;
            if self.snapshots {
                let reference = self
                    .peers
                    .values()
                    .min_by_key(|p| p.slot)
                    .unwrap()
                    .snapshot
                    .as_ref()
                    .unwrap();
                // Fresh-match bootstrap only: no players are active in this state.
                if reference.bytes[..4] != [0, 0, 0, 0] {
                    return Err("initial snapshot contains active players".into());
                }
                initial_time = reference.time;
                let expanded = [initial_time.to_le_bytes().as_slice(), &reference.bytes].concat();
                let mut body = vec![1, 1]; // resync sequence and compressed flag
                body.extend(protocol::compression::compress(&expanded)?);
                initial_state = Some(body);
            }
            self.started = Some(now);
            self.initial_time = initial_time;
            self.initial_state = initial_state;
            eprintln!(
                "All {} peers ready; initial clock and membership queued",
                self.peers.len()
            );
            let slots: Vec<_> = self.peers.values().map(|p| p.slot).collect();
            for peer in self.peers.values_mut() {
                let mut clock = vec![1];
                clock.extend_from_slice(&(now as u16).to_le_bytes());
                clock.extend_from_slice(&initial_time.to_le_bytes());
                peer.enqueue(0xe5, &clock, self.options.players.len() as u8, now)?;
                if !self.snapshots {
                    peer.active_at = Some(initial_time + 50);
                    for &slot in &slots {
                        // Retail enter_match rejects times <= the last resync.
                        // E5 initializes that boundary to zero; E9 encodes 50 ms ticks.
                        peer.enqueue(
                            0xe9,
                            &[(initial_time / 50 + 1) as u8, slot],
                            self.options.players.len() as u8,
                            now,
                        )?;
                    }
                }
            }
            if !self.snapshots {
                for slot in slots {
                    self.record_membership(initial_time + 50, slot, true);
                }
                self.membership_sent = true;
            }
        }
        for (destination, peer) in &mut self.peers {
            if *destination == address || peer.active_at.is_none() {
                continue;
            }
            if let (Some(started), Some((slot, from, until))) = (self.started, self.drop_relay) {
                let game = u64::from(self.initial_time) + now.saturating_sub(started);
                if peer.slot == slot && game >= u64::from(from) && game < u64::from(until) {
                    self.dropped_relays += relay.len() as u32;
                    continue;
                }
            }
            for (id, body) in &relay {
                peer.enqueue(*id, body, self.options.players.len() as u8, now)?;
            }
        }
        out.extend(self.poll(now)?);
        Ok(out)
    }

    fn record_membership(&mut self, time: u32, slot: u8, enter: bool) {
        if enter {
            self.first_entry
                .entry(slot)
                .and_modify(|first| *first = (*first).min(time))
                .or_insert(time);
        }
        let mask = self
            .membership
            .range(..=time)
            .next_back()
            .map_or(0, |(_, mask)| *mask);
        let mask = if enter {
            mask | (1 << slot)
        } else {
            mask & !(1 << slot)
        };
        self.membership.insert(time, mask);
        // Preserve the last mask before the journal's retention window.
        let floor = time.saturating_sub(6500);
        if let Some((&keep, _)) = self.membership.range(..=floor).next_back() {
            self.membership.retain(|time, _| *time >= keep);
        }
        self.journal.record(
            crate::replay::Event {
                time,
                slot,
                opcode: if enter { 0xe9 } else { 0xea },
                body: vec![(time / 50) as u8, slot],
            },
            time.saturating_sub(300),
        );
    }

    fn poll_joins(&mut self, now: u64) -> Result<Outbound, Error> {
        let Some(started) = self.started else {
            return Ok(Vec::new());
        };
        if !self.membership_sent {
            return Ok(Vec::new());
        }
        let game = u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
        let players = self.options.players.len() as u8;
        let mut failed = Vec::new();
        let mut activate = None;
        for (address, peer) in &mut self.peers {
            if !peer.late
                || peer.active_at.is_some()
                || !peer.ready
                || !peer.snapshot.as_ref().is_some_and(|s| s.complete())
            {
                continue;
            }
            if peer.join.is_none() {
                let Some(state) = &self.latest_checkpoint else {
                    continue;
                };
                let mask = u32::from_le_bytes(state.bytes[..4].try_into()?);
                let expected = self
                    .membership
                    .range(..=state.time)
                    .next_back()
                    .map_or(0, |(_, mask)| *mask);
                if state.time > game
                    || game - state.time > 1000
                    || mask != expected
                    || mask & (1 << peer.slot) != 0
                {
                    continue;
                }
                let expanded = [state.time.to_le_bytes().as_slice(), &state.bytes].concat();
                let mut body = vec![peer.resync_sequence, 1];
                body.extend(protocol::compression::compress(&expanded)?);
                peer.join = Some(Join {
                    baseline: state.time,
                    selected_cursor: self.journal.cursor(),
                    sent_cursor: 0,
                    began: now,
                    state: Some(body),
                });
                let mut clock = vec![peer.resync_sequence];
                clock.extend_from_slice(&(now as u16).to_le_bytes());
                clock.extend_from_slice(&game.to_le_bytes());
                peer.clock_confirmed = false;
                peer.enqueue(0xe5, &clock, players, now)?;
                eprintln!(
                    "Late join slot {}: selected checkpoint {} ms, mask {mask:x}; shared clock {game}",
                    peer.slot, state.time
                );
                continue;
            }
            let join = peer.join.as_ref().unwrap();
            if now.saturating_sub(join.began) >= 5000
                || !self
                    .journal
                    .valid(join.baseline, join.selected_cursor, game)
            {
                eprintln!(
                    "Late join slot {} failed: expired transfer or invalidated baseline",
                    peer.slot
                );
                failed.push(*address);
                continue;
            }
            if !peer.clock_confirmed {
                continue;
            }
            if let Some(state) = peer.join.as_mut().unwrap().state.take() {
                peer.enqueue(0xe8, &state, players, now)?;
                peer.state_sent = true;
                continue;
            }
            // Replay and state must be ACKed, never merely aged out of the queue.
            if peer.pending.iter().any(|p| {
                p.frame.first().is_some_and(|id| (0xe8..=0xec).contains(id))
                    || p.frame.get(..2) == Some(&[0xff, 0xe8])
            }) {
                continue;
            }
            let join = peer.join.as_ref().unwrap();
            let events = self.journal.after(join.baseline, join.sent_cursor);
            if !events.is_empty() {
                if events.len() + peer.pending.len() > 1024 {
                    failed.push(*address);
                    continue;
                }
                let first = peer.pending.len();
                for event in &events {
                    peer.enqueue(event.opcode, &event.body, players, now)?;
                }
                for pending in &mut peer.pending[first..] {
                    pending.lifetime_ms = None;
                }
                peer.join.as_mut().unwrap().sent_cursor = self.journal.cursor();
                eprintln!(
                    "Late join slot {}: replay batch of {} changes queued",
                    peer.slot,
                    events.len()
                );
                continue;
            }
            // Activate only one join per poll, so subsequent joiners replay its entry.
            activate = Some(*address);
            break;
        }
        let mut out = Vec::new();
        for address in failed {
            if let Some(peer) = self.peers.get_mut(&address) {
                out.push((address, peer.packet(&[0xfd], now)?));
            }
            out.extend(self.remove_peer(address, now)?);
        }
        if let Some(address) = activate {
            let time = (game + 300).div_ceil(50) * 50;
            let peer = self.peers.get_mut(&address).unwrap();
            let baseline = peer.join.take().unwrap().baseline;
            let slot = peer.slot;
            peer.active_at = Some(time);
            self.record_membership(time, slot, true);
            for peer in self.peers.values_mut().filter(|p| p.active_at.is_some()) {
                peer.enqueue(0xe9, &[(time / 50) as u8, slot], players, now)?;
            }
            self.monitor.reset(time.saturating_add(500));
            self.recovery_targets.clear();
            self.latest_checkpoint = None;
            self.battery_completion.invalidate();
            self.checkpoint_request = None;
            eprintln!(
                "Late join slot {slot}: snapshot {baseline} and replay acknowledged; entry at {time} ms"
            );
        }
        Ok(out)
    }

    fn reset_match(&mut self) {
        // Native connect_to_match ignores a request for its current match ID.
        // Give each new cohort a distinct ID, excluding native unset sentinels.
        self.options.match_id = match self.options.match_id.checked_add(1) {
            Some(id) if id != u32::MAX => id,
            _ => 1,
        };
        self.finishing = None;
        self.journal = crate::replay::Journal::default();
        self.membership = BTreeMap::from([(0, 0)]);
        self.first_entry.clear();
        self.clock_fault_sent = false;
        self.started = None;
        self.initial_time = 0;
        self.initial_state = None;
        self.membership_sent = false;
        self.monitor = crate::recovery::Monitor::default();
        self.recovery_targets.clear();
        self.next_recovery_at = 0;
        self.dropped_relays = 0;
        self.fault_reported = false;
        self.checkpoint_request = None;
        self.latest_checkpoint = None;
        self.battery_completion.invalidate();
        self.last_checkpoint_attempt = 0;
        self.history = crate::history::History::default();
        self.restored_once = false;
    }

    fn remove_peer(&mut self, address: SocketAddr, now: u64) -> Result<Outbound, Error> {
        let Some(departed) = self.peers.remove(&address) else {
            return Ok(Vec::new());
        };
        if self
            .checkpoint_request
            .as_ref()
            .is_some_and(|(source, _)| *source == address)
        {
            self.checkpoint_request = None;
        }
        let mut out = Vec::new();
        if let Some(started) = self.started {
            if self.finishing.is_some() {
                // Every active client already received its own finish event.
            } else if self.membership_sent && departed.active_at.is_some() {
                let game =
                    u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
                // Clear reference evidence across every roster change. Joining
                // peers replay the departure through their separate journal.
                self.monitor.reset(game.saturating_add(500));
                self.recovery_targets.clear();
                self.latest_checkpoint = None;
                self.battery_completion.invalidate();
                self.checkpoint_request = None;
                // Retail EA (0x27c690): the same 50 ms tick and roster slot
                // encoding as E9. Schedule departure on every remaining peer.
                let time = (game + 300).div_ceil(50) * 50;
                let tick = (time / 50) as u8;
                self.record_membership(time, departed.slot, false);
                for peer in self.peers.values_mut().filter(|p| p.active_at.is_some()) {
                    peer.enqueue(
                        0xea,
                        &[tick, departed.slot],
                        self.options.players.len() as u8,
                        now,
                    )?;
                }
                eprintln!(
                    "Roster slot {} left; departure queued at {time} ms (tick {tick})",
                    departed.slot
                );
            } else if !self.membership_sent {
                // A partially delivered initial state cannot admit a replacement.
                // Close the incomplete cohort and allow a clean subsequent match.
                for (destination, peer) in &mut self.peers {
                    out.push((*destination, peer.packet(&[0xfd], now)?));
                }
                self.peers.clear();
                eprintln!("Startup cancelled after roster slot {} left", departed.slot);
            }
        }
        if self.peers.is_empty() {
            self.reset_match();
        }
        Ok(out)
    }

    pub fn poll(&mut self, now: u64) -> Result<Outbound, Error> {
        let mut out = Vec::new();
        if self.finishing.is_none() && self.membership_sent {
            if self.finish_objective {
                if let (Some(started), Some(checkpoint)) = (self.started, &self.latest_checkpoint) {
                    let game =
                        u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
                    let expected_mask = self
                        .membership
                        .range(..=checkpoint.time)
                        .next_back()
                        .map_or(0, |(_, mask)| *mask);
                    let mask = checkpoint
                        .bytes
                        .get(..4)
                        .map(|b| u32::from_le_bytes(b.try_into().unwrap()));
                    let winner = if checkpoint.time <= game
                        && game - checkpoint.time <= 6000
                        && mask == Some(expected_mask)
                    {
                        match_server_026::battery::winning_team(
                            &checkpoint.bytes,
                            checkpoint.time,
                            self.options.players.len() as u8,
                            self.options.map_id,
                        )
                        .ok()
                        .flatten()
                    } else {
                        None
                    };
                    if self
                        .battery_completion
                        .observe(checkpoint.time, checkpoint.crc, winner)
                    {
                        eprintln!(
                            "Battery objective confirmed across verified checkpoints at {} ms",
                            checkpoint.time
                        );
                        out.extend(self.finish_match(game, now)?);
                    }
                } else {
                    self.battery_completion.invalidate();
                }
            }
            if self.finish_timed {
                if let (Some(started), Some(checkpoint), Some(limits)) = (
                    self.started,
                    self.latest_checkpoint.as_ref(),
                    match_server_026::timelimit::Limits::for_map(self.options.map_id),
                ) {
                    let game =
                        u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
                    let expected_mask = self
                        .membership
                        .range(..=checkpoint.time)
                        .next_back()
                        .map(|(_, mask)| *mask)
                        .unwrap_or(0);
                    let mask = checkpoint
                        .bytes
                        .get(..4)
                        .map(|bytes| u32::from_le_bytes(bytes.try_into().unwrap()));
                    if checkpoint.time <= game
                        && game - checkpoint.time <= 6000
                        && mask == Some(expected_mask)
                        && limits.completed(
                            &checkpoint.bytes,
                            checkpoint.time,
                            self.options.players.len() as u8,
                        ) == Ok(true)
                    {
                        eprintln!(
                            "Native time-limit completed in verified checkpoint at {} ms",
                            checkpoint.time
                        );
                        out.extend(self.finish_match(game, now)?);
                    }
                }
            }
            if let (Some(started), Some(deadline)) = (self.started, self.finish_after_ms) {
                let game =
                    u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
                if game >= deadline {
                    out.extend(self.finish_match(game, now)?);
                }
            }
        }
        if let Some((_, began)) = self.finishing {
            // Bound the terminal generation even if an idle results client keeps pinging.
            let expired: Vec<_> = self
                .peers
                .iter()
                .filter(|(_, peer)| {
                    now.saturating_sub(began) >= 30_000
                        || now.saturating_sub(peer.last_seen) >= 120_000
                })
                .map(|(address, _)| *address)
                .collect();
            for address in expired {
                out.push((
                    address,
                    self.peers.get_mut(&address).unwrap().packet(&[0xfd], now)?,
                ));
                out.extend(self.remove_peer(address, now)?);
            }
            for (address, peer) in &mut self.peers {
                out.extend(
                    peer.flush(now)?
                        .into_iter()
                        .map(|packet| (*address, packet)),
                );
            }
            return Ok(out);
        }
        if self
            .checkpoint_request
            .as_ref()
            .is_some_and(|(_, request)| now.saturating_sub(request.requested_at) >= 2000)
        {
            eprintln!(
                "Checkpoint request expired; retained history was unavailable or transfer timed out"
            );
            self.checkpoint_request = None;
        }
        let expired: Vec<_> = self
            .peers
            .iter()
            .filter(|(_, peer)| now.saturating_sub(peer.last_seen) >= 120_000)
            .map(|(address, _)| *address)
            .collect();
        for address in expired {
            out.extend(self.remove_peer(address, now)?);
        }
        out.extend(self.poll_joins(now)?);
        out.extend(self.poll_restoration(now)?);
        if let Some(state) = &self.initial_state {
            for peer in self.peers.values_mut() {
                if !peer.late && peer.clock_confirmed && !peer.state_sent {
                    peer.enqueue(0xe8, state, self.options.players.len() as u8, now)?;
                    peer.state_sent = true;
                }
            }
            if !self.membership_sent
                && self.peers.len() >= usize::from(self.start_players)
                && self.peers.values().all(|peer| {
                    peer.state_sent
                        && !peer.pending.iter().any(|pending| {
                            pending.frame.first() == Some(&0xe8)
                                || pending.frame.get(..2) == Some(&[0xff, 0xe8])
                        })
                })
            {
                // Allow delivery time after all state fragments are acknowledged.
                // This 300 ms lead is SRP scheduling policy, not retail metadata.
                let elapsed = now.saturating_sub(self.started.unwrap());
                let entry_tick = (u64::from(self.initial_time) + elapsed + 300).div_ceil(50) as u8;
                let slots: Vec<_> = self.peers.values().map(|p| p.slot).collect();
                let entry_time =
                    ((u64::from(self.initial_time) + elapsed + 300).div_ceil(50) * 50) as u32;
                for peer in self.peers.values_mut() {
                    peer.active_at = Some(entry_time);
                    for &slot in &slots {
                        peer.enqueue(
                            0xe9,
                            &[entry_tick, slot],
                            self.options.players.len() as u8,
                            now,
                        )?;
                    }
                }
                for slot in slots {
                    self.record_membership(entry_time, slot, true);
                }
                self.membership_sent = true;
                let game = u32::try_from(u64::from(self.initial_time) + elapsed)?;
                self.monitor.reset(game.saturating_add(300));
                eprintln!(
                    "All startup states acknowledged; player entry queued at tick {entry_tick}"
                );
            }
        }
        if let (Some(started), Some((slot, at, offset))) = (self.started, self.clock_fault) {
            let game = u64::from(self.initial_time) + now.saturating_sub(started);
            if !self.clock_fault_sent && game >= u64::from(at) {
                if let Some(peer) = self
                    .peers
                    .values_mut()
                    .find(|p| p.slot == slot && p.active_at.is_some())
                {
                    peer.enqueue(
                        0xe7,
                        &offset.to_le_bytes(),
                        self.options.players.len() as u8,
                        now,
                    )?;
                    self.clock_fault_sent = true;
                    eprintln!("Diagnostic clock fault: slot {slot}, slew {offset} ms at {game} ms");
                }
            }
        }
        for (address, peer) in &mut self.peers {
            if self.clock_sync && peer.clock_confirmed && peer.restoring.is_none() {
                if let Some(started) = self.started {
                    let game =
                        u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
                    if peer
                        .active_at
                        .is_some_and(|at| game >= at.saturating_add(1000))
                    {
                        if let Some(body) = peer.clock.request(now, game) {
                            peer.enqueue(0xe6, &body, self.options.players.len() as u8, now)?;
                        }
                    }
                }
            }
            out.extend(
                peer.flush(now)?
                    .into_iter()
                    .map(|packet| (*address, packet)),
            );
        }
        Ok(out)
    }

    fn finish_match(&mut self, game: u32, now: u64) -> Result<Outbound, Error> {
        if self.finishing.is_some() {
            return Ok(Vec::new());
        }
        // Assemble every recipient's payload before committing the terminal
        // generation. Results have one explicit historical cutoff; no extrapolation.
        let mut results = BTreeMap::new();
        if self.results {
            let Some(checkpoint) = &self.latest_checkpoint else {
                return Ok(Vec::new());
            };
            let expected_mask = self
                .membership
                .range(..=checkpoint.time)
                .next_back()
                .map(|(_, mask)| *mask)
                .unwrap_or(0);
            let Ok(layout) = match_server_026::state::inspect(
                &checkpoint.bytes,
                self.options.players.len() as u8,
            ) else {
                return Ok(Vec::new());
            };
            if checkpoint.time > game
                || game - checkpoint.time > 6000
                || layout.mask != expected_mask
            {
                return Ok(Vec::new());
            }
            let participants = self
                .first_entry
                .iter()
                .filter(|(_, time)| **time <= checkpoint.time)
                .fold(layout.mask, |mask, (slot, _)| mask | (1 << slot));
            for (address, peer) in &self.peers {
                if peer.active_at.is_some() {
                    let Ok(body) = match_server_026::results::encode(
                        &self.options,
                        &checkpoint.bytes,
                        checkpoint.time,
                        peer.slot,
                        participants,
                    ) else {
                        return Ok(Vec::new());
                    };
                    results.insert(*address, body);
                }
            }
            eprintln!(
                "Final results use verified checkpoint {} ms, CRC {:08x}",
                checkpoint.time, checkpoint.crc
            );
        }
        self.finishing = Some((game, now));
        self.checkpoint_request = None;
        self.recovery_targets.clear();
        let mut out = Vec::new();
        let mut loading = Vec::new();
        for (address, peer) in &mut self.peers {
            peer.pending.clear();
            peer.join = None;
            peer.restoring = None;
            if peer.active_at.is_some() {
                if let Some(body) = results.remove(address) {
                    peer.enqueue(0xf8, &body, self.options.players.len() as u8, now)?;
                    continue;
                }
                // Own-slot EA closes immediately, regardless of its timestamp.
                // Send only when finishing, never schedule it ahead of the deadline.
                peer.enqueue(
                    0xea,
                    &[(game / 50) as u8, peer.slot],
                    self.options.players.len() as u8,
                    now,
                )?;
                let event = peer.pending.last_mut().unwrap();
                event.lifetime_ms = None;
                event.retry_ms = 250;
            } else {
                out.push((*address, peer.packet(&[0xfd], now)?));
                loading.push(*address);
            }
        }
        for address in loading {
            out.extend(self.remove_peer(address, now)?);
        }
        eprintln!(
            "Match finish queued at {game} ms; terminal delivery retained until ACK/disconnect"
        );
        Ok(out)
    }

    fn poll_restoration(&mut self, now: u64) -> Result<Outbound, Error> {
        let Some(started) = self.started else {
            return Ok(Vec::new());
        };
        let game_time = u32::try_from(u64::from(self.initial_time) + now.saturating_sub(started))?;
        let players = self.options.players.len() as u8;
        let failed: Vec<_> = self
            .peers
            .iter()
            .filter_map(|(address, peer)| {
                let restore = peer.restoring.as_ref()?;
                (now >= restore.deadline
                    || (!restore.invalidated && now.saturating_sub(restore.began) >= 2000))
                    .then_some(*address)
            })
            .collect();
        let mut out = Vec::new();
        for address in failed {
            out.push((
                address,
                self.peers.get_mut(&address).unwrap().packet(&[0xfd], now)?,
            ));
            eprintln!(
                "Restoration failed for slot {}; closing the transport",
                self.peers[&address].slot
            );
            out.extend(self.remove_peer(address, now)?);
        }
        if self.started.is_none() {
            return Ok(out);
        }
        for peer in self.peers.values_mut() {
            let Some(restore) = &mut peer.restoring else {
                continue;
            };
            // An E8 may already have reached the client when its baseline is
            // revised. Never replay only the newer inputs against that state;
            // retain the retry until a new donor checkpoint can replace it.
            if !restore.invalidated
                && (!self.journal.valid(restore.time, restore.cursor, game_time)
                    || self.history.after(restore.time, game_time).is_none()
                    || self
                        .membership
                        .range(restore.time.saturating_add(1)..)
                        .next()
                        .is_some())
            {
                restore.invalidated = true;
                peer.pending.retain(|pending| {
                    pending.frame.first() != Some(&0xe8)
                        && pending.frame.get(..2) != Some(&[0xff, 0xe8])
                });
                eprintln!(
                    "Restoration baseline invalidated for slot {}; waiting for a fresh checkpoint",
                    peer.slot
                );
            }
        }
        let mask = self
            .peers
            .values()
            .filter(|peer| peer.active_at.is_some_and(|at| at <= game_time))
            .fold(0u32, |mask, peer| mask | (1 << peer.slot));
        if self.recover && self.membership_sent {
            // A returning lower-numbered slot must not replace the surviving
            // world as the source of truth before its catch-up is verified.
            let reference = self
                .peers
                .values()
                .filter(|peer| {
                    peer.restoring.is_none() && peer.active_at.is_some_and(|at| at <= game_time)
                })
                .min_by_key(|peer| (peer.active_at, peer.slot))
                .map(|peer| peer.slot);
            let suspects = reference.map_or_else(BTreeMap::new, |reference| {
                self.monitor.suspects(game_time, mask, reference)
            });
            for (slot, time) in &suspects {
                if !self.recovery_targets.contains_key(slot) {
                    eprintln!("Sustained hash disagreement in slot {slot}, since {time} ms");
                }
            }
            self.recovery_targets = suspects;
        }
        if let Some((slot, from, until)) = self.drop_relay {
            if game_time >= until && !self.fault_reported {
                eprintln!(
                    "Diagnostic fault withheld {} live relay messages from slot {slot} during {from}..{until} ms",
                    self.dropped_relays
                );
                self.fault_reported = true;
            }
        }
        let manual = !self.restored_once
            && self.restore_once_after_ms.is_some_and(|after| {
                self.latest_checkpoint
                    .as_ref()
                    .is_some_and(|state| state.time >= after)
            });
        let automatic =
            self.recover && !self.recovery_targets.is_empty() && now >= self.next_recovery_at;
        let retry_after = self
            .peers
            .values()
            .filter_map(|peer| {
                peer.restoring
                    .as_ref()
                    .filter(|r| r.invalidated)
                    .map(|r| r.time)
            })
            .max();
        if self.membership_sent && (manual || automatic || retry_after.is_some()) {
            if let Some(checkpoint) = &self.latest_checkpoint {
                let after = if let Some(after) = retry_after {
                    after
                } else if manual {
                    self.restore_once_after_ms.unwrap()
                } else {
                    *self.recovery_targets.values().min().unwrap()
                };
                let snapshot_mask = u32::from_le_bytes(checkpoint.bytes[..4].try_into()?);
                // Active-client recovery currently replays inputs only. Require
                // a checkpoint after every scheduled membership change.
                if checkpoint.time >= after
                    && retry_after.is_none_or(|baseline| checkpoint.time > baseline)
                    && checkpoint.time <= game_time
                    && snapshot_mask == mask
                    && self
                        .membership
                        .range(checkpoint.time.saturating_add(1)..)
                        .next()
                        .is_none()
                    && self.history.after(checkpoint.time, game_time).is_some()
                    && self.peers.values().all(|p| {
                        p.pending.len() < 512 && p.restoring.as_ref().is_none_or(|r| r.invalidated)
                    })
                {
                    let expanded =
                        [checkpoint.time.to_le_bytes().as_slice(), &checkpoint.bytes].concat();
                    let compressed = protocol::compression::compress(&expanded)?;
                    self.battery_completion.invalidate();
                    for peer in self.peers.values_mut().filter(|p| p.active_at.is_some()) {
                        let retry = peer.restoring.as_ref().is_some_and(|r| r.invalidated);
                        if !retry
                            && !manual
                            && !(automatic && self.recovery_targets.contains_key(&peer.slot))
                        {
                            continue;
                        }
                        peer.resync_sequence = peer.resync_sequence.wrapping_add(1);
                        let body = [vec![peer.resync_sequence, 1], compressed.clone()].concat();
                        peer.enqueue(0xe8, &body, players, now)?;
                        let deadline = peer
                            .restoring
                            .as_ref()
                            .map_or(now.saturating_add(5000), |r| r.deadline);
                        peer.restoring = Some(Restoration {
                            time: checkpoint.time,
                            cursor: self.journal.cursor(),
                            began: now,
                            deadline,
                            invalidated: false,
                        });
                        eprintln!(
                            "Restoring slot {} from {} ms, resync sequence {}",
                            peer.slot, checkpoint.time, peer.resync_sequence
                        );
                    }
                    if manual {
                        self.restored_once = true;
                    }
                    self.next_recovery_at = now.saturating_add(10_000);
                    self.monitor.reset(game_time.saturating_add(500));
                    self.recovery_targets.clear();
                }
            }
        }
        for peer in self.peers.values_mut() {
            let Some(restore) = &peer.restoring else {
                continue;
            };
            if restore.invalidated {
                continue;
            }
            let time = restore.time;
            let is_state = |pending: &Pending| {
                pending.frame.first() == Some(&0xe8)
                    || pending.frame.get(..2) == Some(&[0xff, 0xe8])
            };
            if peer.pending.iter().any(is_state) {
                continue;
            }
            let Some(mut inputs) = self.history.after(time, game_time) else {
                peer.restoring.as_mut().unwrap().invalidated = true;
                eprintln!(
                    "Restoration history expired for slot {}; waiting for a fresh checkpoint",
                    peer.slot
                );
                continue;
            };
            // Mode-1 E8 preserves local input history. Echoing a client's own
            // inputs through the remote-input path can retime them after resync.
            // Replay follows the same recipient rule as the live relay.
            inputs.retain(|input| input.slot != peer.slot);
            if peer.pending.len() + inputs.len() > 1024 {
                continue;
            }
            for input in &inputs {
                peer.enqueue(input.opcode, &input.body, players, now)?;
            }
            peer.restoring = None;
            eprintln!(
                "Restoration state acknowledged by slot {}; replayed {} later inputs",
                peer.slot,
                inputs.len()
            );
        }
        Ok(out)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn configured_restart_can_reuse_endpoint_without_refreshing_old_transport() {
        let mut server = Server::new(2239, 2, 71).unwrap();
        server
            .set_roster(
                &match_server_026::roster::parse("000000a1 0 1 Alice\n000000b2 0 1 Bob").unwrap(),
            )
            .unwrap();
        let first: SocketAddr = "127.0.0.1:40001".parse().unwrap();
        let second: SocketAddr = "127.0.0.1:40002".parse().unwrap();
        for (address, token) in [(first, 0xa1), (second, 0xb2)] {
            server
                .receive(address, &request(0, 0, 0xd8, &[token, 0, 0, 0, 0]), 0)
                .unwrap();
            let peer = server.peers.get_mut(&address).unwrap();
            peer.pending.clear();
            peer.startup_sent = true;
            peer.active_at = Some(100);
        }
        server.snapshots = true;
        server.checkpoints = true;
        server.recover = true;
        server.started = Some(0);
        server.membership_sent = true;
        server.record_membership(100, 0, true);
        server.record_membership(100, 1, true);
        for now in [1000, 2000, 4999] {
            assert!(
                server
                    .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), now)
                    .is_err()
            );
            assert_eq!(server.peers[&first].last_seen, 0);
        }
        server.recover = false;
        assert!(
            server
                .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 5000)
                .is_err()
        );
        server.recover = true;
        for active_at in [None, Some(6000)] {
            server.peers.get_mut(&second).unwrap().active_at = active_at;
            assert!(
                server
                    .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 5000)
                    .is_err()
            );
            assert_eq!(server.peers[&first].last_seen, 0);
        }
        server.peers.get_mut(&second).unwrap().active_at = Some(100);
        server.peers.get_mut(&second).unwrap().restoring = Some(Restoration {
            time: 100,
            cursor: 0,
            began: 5000,
            deadline: 10000,
            invalidated: false,
        });
        assert!(
            server
                .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 5000)
                .is_err()
        );
        server.peers.get_mut(&second).unwrap().restoring = None;
        let out = server
            .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 5001)
            .unwrap();
        assert!(
            out.iter().any(|(address, packet)| *address == first
                && Header::decode(packet).unwrap().1[0] == 0xe3)
        );
        assert!(!server.peers[&first].startup_sent);
        assert!(server.peers[&first].late);
        assert_eq!(server.peers[&first].active_at, None);
        assert_eq!(server.peers[&second].active_at, Some(100));
        assert_eq!(server.started, Some(0));
        assert_eq!(server.options.match_id, 1);
        // Fresh D9 uses the new transport's sequence history.
        server
            .receive(first, &request(1, 0, 0xd9, &[0xa1, 0, 0, 0]), 5002)
            .unwrap();
        assert!(server.peers[&first].startup_sent);

        // Reusing the endpoint must not bypass the surviving-donor guard.
        server.peers.remove(&second);
        assert!(
            server
                .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 10003)
                .is_err()
        );
        assert_eq!(server.peers[&first].last_seen, 5002);
    }

    fn active_recovery_fixture() -> (Server, SocketAddr, SocketAddr) {
        let (mut server, first, second) = late_join_fixture();
        server.peers.get_mut(&second).unwrap().active_at = Some(1500);
        server.membership.insert(1500, 3);
        server.latest_checkpoint.as_mut().unwrap().bytes[..4].copy_from_slice(&3u32.to_le_bytes());
        server.recover = true;
        for time in [1600, 1700, 1800] {
            server.monitor.observe(0, time, 7, time);
            server.monitor.observe(1, time, 8, time);
        }
        server.poll(2800).unwrap();
        assert!(server.peers[&first].restoring.is_none());
        assert_eq!(server.peers[&second].restoring.as_ref().unwrap().time, 1950);
        (server, first, second)
    }

    #[test]
    fn revised_recovery_baseline_waits_for_fresh_donor_and_replays_newer_inputs() {
        for revised_time in [1900u32, 1950] {
            let (mut server, first, second) = active_recovery_fixture();
            let old = server.latest_checkpoint.as_ref().unwrap();
            let old = crate::snapshot::Checkpoint {
                time: old.time,
                crc: old.crc,
                bytes: old.bytes.clone(),
            };
            let input = [vec![(revised_time / 50) as u8], vec![1; 8]].concat();
            server
                .receive(first, &request(6, 0, 0xdc, &input), 2850)
                .unwrap();
            assert!(server.latest_checkpoint.is_none());
            assert!(
                server.peers[&second]
                    .restoring
                    .as_ref()
                    .unwrap()
                    .invalidated
            );
            assert!(
                server.peers[&second]
                    .pending
                    .iter()
                    .all(|p| p.frame.first() != Some(&0xe8)
                        && p.frame.get(..2) != Some(&[0xff, 0xe8]))
            );
            // ACKing every old packet cannot finish a known-invalid restore.
            let ack = Header {
                sequence: 4,
                ack_sequence: (server.peers[&second].generation - 1) as u8,
                ack_mask: u128::MAX,
                ack_bits: 127,
                single_message: true,
            }
            .encode(&[0xfc])
            .unwrap();
            // A cached copy of the old snapshot is not a retry candidate.
            server.latest_checkpoint = Some(old);
            server.receive(second, &ack, 2860).unwrap();
            assert!(
                server.peers[&second]
                    .restoring
                    .as_ref()
                    .unwrap()
                    .invalidated
            );
            assert!(
                server.peers[&second]
                    .pending
                    .iter()
                    .all(|p| p.frame.first() != Some(&0xe8)
                        && p.frame.get(..2) != Some(&[0xff, 0xe8]))
            );
            server.latest_checkpoint = None;
            // Suspect reports do not request a checkpoint or supply recovery votes.
            server
                .receive(second, &request(5, 0, 0xdf, &[57, 1, 0, 0, 0]), 2870)
                .unwrap();
            assert!(server.checkpoint_request.is_none());

            let bytes = 3u32.to_le_bytes().to_vec();
            let crc = crc32fast::hash(&bytes);
            server
                .receive(
                    first,
                    &request(7, 0, 0xdf, &[vec![57], crc.to_le_bytes().to_vec()].concat()),
                    2880,
                )
                .unwrap();
            assert_eq!(server.checkpoint_request.as_ref().unwrap().0, first);
            let upload = [2850u32.to_le_bytes().as_slice(), &[0, 0, 4, 0], &bytes].concat();
            server
                .receive(first, &request(8, 0, 0xe2, &upload), 2890)
                .unwrap();
            let restore = server.peers[&second].restoring.as_ref().unwrap();
            assert_eq!(restore.time, 2850);
            assert_eq!(restore.deadline, 7800);
            assert!(!restore.invalidated);
            // Revise a newer input while the replacement E8 is in flight.
            for (sequence, value) in [(9, 2), (10, 3)] {
                server
                    .receive(
                        first,
                        &request(sequence, 0, 0xdc, &[vec![58], vec![value; 8]].concat()),
                        2900,
                    )
                    .unwrap();
            }
            let ack = Header {
                sequence: 6,
                ack_sequence: (server.peers[&second].generation - 1) as u8,
                ack_mask: u128::MAX,
                ack_bits: 127,
                single_message: true,
            }
            .encode(&[0xfc])
            .unwrap();
            let out = server.receive(second, &ack, 2910).unwrap();
            let replay = [vec![0xeb, 58, 0], vec![3; 8]].concat();
            assert!(
                out.iter()
                    .any(|(a, p)| *a == second && Header::decode(p).unwrap().1 == replay)
            );
            assert!(server.peers[&second].restoring.is_none());
            assert!(server.peers[&first].restoring.is_none());
        }
    }

    #[test]
    fn invalidated_recovery_has_bounded_failure_and_preserves_survivor() {
        let (mut server, first, second) = active_recovery_fixture();
        server
            .receive(
                first,
                &request(6, 0, 0xdc, &[vec![38], vec![1; 8]].concat()),
                2850,
            )
            .unwrap();
        server.poll(7799).unwrap();
        assert!(server.peers.contains_key(&second));
        let out = server.poll(7800).unwrap();
        assert!(!server.peers.contains_key(&second));
        assert!(server.peers.contains_key(&first));
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1 == [0xfd])
        );
        assert_eq!(server.started, Some(50));
    }

    #[test]
    fn configured_identity_keeps_slot_and_squad_across_endpoint_replacement() {
        let mut server = Server::new(2239, 2, 71).unwrap();
        assert_eq!(server.options.squads, [0; 20]);
        let roster =
            match_server_026::roster::parse("000000a1 0 1 Alice\n000000b2 0 1 Bob").unwrap();
        server.set_roster(&roster).unwrap();
        let first: SocketAddr = "127.0.0.1:40001".parse().unwrap();
        let second: SocketAddr = "127.0.0.1:40002".parse().unwrap();
        let replacement: SocketAddr = "127.0.0.1:40003".parse().unwrap();
        // Arrival order must not determine identity, team or squad.
        server
            .receive(second, &request(0, 0, 0xd8, &[0xb2, 0, 0, 0, 0]), 0)
            .unwrap();
        server
            .receive(first, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 1)
            .unwrap();
        assert_eq!(server.peers[&first].slot, 0);
        assert_eq!(server.peers[&second].slot, 1);
        assert!(server.set_roster(&roster).is_err());
        server.snapshots = true;
        server.checkpoints = true;
        server.recover = true;
        server.started = Some(0);
        server.membership_sent = true;
        server.record_membership(100, 0, true);
        server.record_membership(100, 1, true);
        for peer in server.peers.values_mut() {
            peer.active_at = Some(100);
        }
        assert!(
            server
                .receive(replacement, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 4999)
                .is_err()
        );
        assert!(
            server
                .receive(replacement, &request(0, 0, 0xd8, &[0xc3, 0, 0, 0, 0]), 6000)
                .is_err()
        );
        assert_eq!(server.peers.len(), 2);
        server.recover = false;
        assert!(
            server
                .receive(replacement, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 6000)
                .is_err()
        );
        assert!(server.peers.contains_key(&first));
        server.recover = true;
        let out = server
            .receive(replacement, &request(0, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 6000)
            .unwrap();
        assert!(!server.peers.contains_key(&first));
        assert_eq!(server.peers[&replacement].slot, 0);
        assert!(server.peers[&replacement].late);
        assert_eq!(server.peers[&replacement].active_at, None);
        assert_eq!(server.started, Some(0));
        assert_eq!(server.options.match_id, 1);
        assert_eq!(server.first_entry[&0], 100);
        assert_eq!(server.membership[&6300], 2);
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1 == [0xea, 126, 0])
        );
        assert_eq!(server.options.players[0].name, "Alice");
        assert_eq!(server.options.players[1].team, 0);
        assert_eq!(&server.options.squads[..2], &[1, 1]);
        // Delayed traffic from the old transport cannot immediately replace it.
        assert!(
            server
                .receive(first, &request(1, 0, 0xd8, &[0xa1, 0, 0, 0, 0]), 6001)
                .is_err()
        );
        assert!(server.peers.contains_key(&replacement));
        // Frozen configuration survives a completed match reset.
        server.peers.clear();
        server.reset_match();
        server
            .receive(replacement, &request(0, 0, 0xd8, &[0xb2, 0, 0, 0, 0]), 7000)
            .unwrap();
        assert_eq!(server.peers[&replacement].slot, 1);
        assert_eq!(server.options.match_id, 2);
    }

    #[test]
    fn scoring_policy_is_fixed_before_admission() {
        let mut server = Server::new(2238, 2, 71).unwrap();
        assert!(server.set_score_weights([f32::NAN; 28]).is_err());
        assert_eq!(
            server.options.event_scores,
            match_server_026::scoring::development()
        );
        let weights = [2.5; 28];
        server.set_score_weights(weights).unwrap();
        assert_eq!(server.options.event_scores, weights);
        let peer = "127.0.0.1:30001".parse().unwrap();
        server
            .receive(peer, &request(0, 0, 0xd8, &[1, 0, 0, 0, 0]), 0)
            .unwrap();
        assert!(server.set_score_weights([1.; 28]).is_err());
        assert_eq!(server.options.event_scores, weights);
    }

    fn battery_checkpoint(time: u32, points: u16) -> crate::snapshot::Checkpoint {
        // Policy fixture only: edit timer/statistics in a real serialized state.
        // This is not evidence that the native engine executed these deposits.
        let mut bytes: Vec<u8> = include_str!("../fixtures/026g-school-live.hex")
            .trim()
            .as_bytes()
            .chunks_exact(2)
            .map(|b| u8::from_str_radix(std::str::from_utf8(b).unwrap(), 16).unwrap())
            .collect();
        let layout = match_server_026::state::inspect(&bytes, 2).unwrap();
        let rules = layout.blocks[4].start;
        bytes[rules + 4..rules + 8].copy_from_slice(&time.to_le_bytes());
        let footer = layout.blocks[1].end - 11;
        bytes[footer..footer + 2].copy_from_slice(&points.to_le_bytes());
        bytes[footer + 6] = if points == 0 { 2 } else { 0 };
        crate::snapshot::Checkpoint {
            time,
            crc: crc32fast::hash(&bytes),
            bytes,
        }
    }

    #[test]
    fn battery_finish_requires_confirmed_current_winning_checkpoints() {
        for case in [
            "complete",
            "repeat",
            "short",
            "lost",
            "stale",
            "future",
            "mask",
            "identity",
            "waiting",
            "disabled",
            "missing",
            "revised",
            "departure",
            "reset",
        ] {
            let (mut server, first, second) = late_join_fixture();
            server.finish_objective = case != "disabled";
            server.results = true;
            server.peers.get_mut(&second).unwrap().active_at = Some(2000);
            server.membership.insert(2000, 3);
            server.latest_checkpoint = Some(battery_checkpoint(100000, 10));
            for peer in server.peers.values_mut() {
                peer.last_seen = 100000;
            }
            server.poll(100000).unwrap();
            assert!(server.finishing.is_none());
            assert_eq!(server.battery_completion.pending(), case != "disabled");
            if case == "revised" {
                let input = [vec![(100000u32 / 50) as u8], vec![1; 8]].concat();
                server
                    .receive(first, &request(6, 0, 0xdc, &input), 100050)
                    .unwrap();
                assert!(server.latest_checkpoint.is_none());
                assert!(!server.battery_completion.pending());
            }
            if case == "departure" {
                server.remove_peer(second, 100050).unwrap();
                assert!(!server.battery_completion.pending());
                continue;
            }
            if case == "reset" {
                server.reset_match();
                assert!(!server.battery_completion.pending());
                continue;
            }
            let time = match case {
                "repeat" => 100000,
                "short" => 102999,
                _ => 103000,
            };
            let mut checkpoint = battery_checkpoint(time, if case == "lost" { 9 } else { 10 });
            if matches!(case, "identity" | "waiting") {
                let layout = match_server_026::state::inspect(&checkpoint.bytes, 2).unwrap();
                let rules = layout.blocks[4].start;
                if case == "identity" {
                    checkpoint.bytes[rules + 4] ^= 1;
                } else {
                    checkpoint.bytes[rules + 12] = 1;
                }
                checkpoint.crc = crc32fast::hash(&checkpoint.bytes);
            }
            server.latest_checkpoint = if case == "missing" {
                None
            } else {
                Some(checkpoint)
            };
            if case == "mask" {
                server.membership.insert(2000, 1);
            }
            let now = match case {
                "stale" => 109001,
                "future" => 102999,
                _ => 103000,
            };
            server.poll(now).unwrap();
            assert_eq!(server.finishing.is_some(), case == "complete", "{case}");
            if case == "complete" {
                for peer in server.peers.values() {
                    assert!(peer.pending.iter().any(|p| p.frame.first() == Some(&0xf8)));
                }
            }
        }
    }

    #[test]
    fn result_finish_is_fragmented_retried_and_bound_to_verified_cutoff() {
        let (mut server, first, second) = late_join_fixture();
        server.results = true;
        server.peers.get_mut(&second).unwrap().active_at = Some(2000);
        server.membership.insert(2000, 3);
        let template = server.options.players[0].clone();
        server.options.players = (0..20)
            .map(|slot| {
                let mut player = template.clone();
                player.key = slot + 1;
                player.name = format!("Player{}", slot + 1);
                player.team = (slot % 2) as u8;
                player
            })
            .collect();
        // Slot 2 played and departed before the retained membership window.
        // Slot 3 is scheduled after the final checkpoint and must stay absent.
        server.first_entry.insert(2, 1000);
        server.first_entry.insert(3, 99000);
        let mut bytes: Vec<u8> = include_str!("../fixtures/026g-school-live.hex")
            .trim()
            .as_bytes()
            .chunks_exact(2)
            .map(|p| u8::from_str_radix(std::str::from_utf8(p).unwrap(), 16).unwrap())
            .collect();
        let layout = match_server_026::state::inspect(&bytes, 2).unwrap();
        let block = layout.blocks[1].clone();
        // Expand only statistics roster storage to exercise F8 fragmentation.
        bytes[block.start - 2..block.start]
            .copy_from_slice(&((block.len() + 18 * 40) as u16).to_le_bytes());
        bytes.splice(block.start + 80..block.start + 80, vec![0; 18 * 40]);
        server.latest_checkpoint = Some(crate::snapshot::Checkpoint {
            time: 98750,
            crc: crc32fast::hash(&bytes),
            bytes,
        });
        assert!(server.finish_match(105000, 105000).unwrap().is_empty());
        assert!(
            server.finishing.is_none(),
            "stale state cannot become final results"
        );
        server.finish_match(98800, 98800).unwrap();
        assert!(server.finishing.is_some());
        for (address, slot) in [(first, 0), (second, 1)] {
            let peer = server.peers.get_mut(&address).unwrap();
            assert_eq!(peer.pending.len(), 4);
            let mut body = Vec::new();
            for pending in &peer.pending {
                let frame =
                    protocol::decode_frames(&pending.frame, true, Direction::ServerSnapshots, 20)
                        .unwrap();
                assert_eq!(frame[0].id, 0xf8);
                body.extend(frame[0].body);
            }
            assert_eq!(&body[..4], &[1, (98750u32 / 50) as u8, slot, 2]);
            assert_eq!(u32::from_le_bytes(body[4..8].try_into().unwrap()), 98750);
            assert_eq!(u32::from_le_bytes(body[12..16].try_into().unwrap()), 7);
            assert_eq!(&body[30..32], &[0, 0], "match level is not an account rank");
            assert_eq!(&body[40..47], b"Player1");
            let initial = peer.flush(98800).unwrap();
            assert_eq!(initial.len(), 4);
            assert_eq!(peer.flush(99100).unwrap().len(), 4);
            let last = Header::decode(initial.last().unwrap()).unwrap().0.sequence;
            peer.acknowledge(Header {
                sequence: 0,
                ack_sequence: last,
                ack_mask: u128::MAX,
                ack_bits: 4,
                single_message: true,
            });
            assert!(peer.pending.is_empty());
        }
        server.reset_match();
        assert!(server.first_entry.is_empty());
    }

    #[test]
    fn timed_finish_requires_current_consistent_completed_checkpoint() {
        for case in [
            "complete", "disabled", "before", "stale", "future", "mask", "identity",
        ] {
            let (mut server, first, second) = late_join_fixture();
            server.finish_timed = case != "disabled";
            server.peers.get_mut(&second).unwrap().active_at = Some(2000);
            server.membership.insert(2000, 3);
            let mut bytes: Vec<u8> = include_str!("../fixtures/026g-school-live.hex")
                .trim()
                .as_bytes()
                .chunks_exact(2)
                .map(|pair| u8::from_str_radix(std::str::from_utf8(pair).unwrap(), 16).unwrap())
                .collect();
            let time: u32 = if case == "before" { 920_450 } else { 920_500 };
            let now = match case {
                "stale" => u64::from(time) + 6001,
                "future" => u64::from(time) - 1,
                _ => u64::from(time),
            };
            let layout = match_server_026::state::inspect(&bytes, 2).unwrap();
            let rules = layout.blocks[4].start;
            bytes[rules + 4..rules + 8].copy_from_slice(&time.to_le_bytes());
            if case == "mask" {
                server.membership.insert(2000, 1);
            }
            if case == "identity" {
                bytes[rules + 4] ^= 1;
            }
            server.latest_checkpoint = Some(crate::snapshot::Checkpoint {
                time,
                crc: crc32fast::hash(&bytes),
                bytes,
            });
            for peer in server.peers.values_mut() {
                peer.last_seen = now;
            }
            server.poll(now).unwrap();
            assert_eq!(server.finishing.is_some(), case == "complete", "{case}");
            assert!(server.peers.contains_key(&first));
        }
    }

    #[test]
    fn finish_retries_own_slot_freezes_match_and_resets_after_disconnect() {
        let (mut server, first, second) = late_join_fixture();
        server.peers.get_mut(&second).unwrap().active_at = Some(5000);
        server.finish_after_ms = Some(5000);
        let started = server.started.unwrap();
        let deadline = started + 5000 - u64::from(server.initial_time);
        server.poll(deadline - 1).unwrap();
        assert!(server.finishing.is_none());
        let finishes = server.poll(deadline).unwrap();
        assert_eq!(server.finishing, Some((5000, deadline)));
        for (address, slot) in [(first, 0), (second, 1)] {
            let events: Vec<_> = finishes
                .iter()
                .filter(|(peer, _)| *peer == address)
                .map(|(_, bytes)| Header::decode(bytes).unwrap().1)
                .filter(|body| body[0] == 0xea)
                .collect();
            assert_eq!(events, vec![&[0xea, 100, slot][..]]);
        }
        // Drop the original packets: retries persist beyond ordinary EA's 250ms lifetime.
        let retry = server.poll(deadline + 1000).unwrap();
        assert_eq!(
            retry
                .iter()
                .filter(|(_, bytes)| Header::decode(bytes).unwrap().1[0] == 0xea)
                .count(),
            2
        );
        let first_ack = retry
            .iter()
            .find(|(peer, bytes)| *peer == first && Header::decode(bytes).unwrap().1[0] == 0xea)
            .map(|(_, bytes)| Header::decode(bytes).unwrap().0.sequence)
            .unwrap();
        server
            .receive(first, &request(60, first_ack, 0xfc, &[]), deadline + 1010)
            .unwrap();
        assert!(server.peers[&first].pending.is_empty());
        let newcomer = "127.0.0.1:40003".parse().unwrap();
        assert!(
            server
                .receive(
                    newcomer,
                    &request(0, 0, 0xd8, &[3, 0, 0, 0, 0]),
                    deadline + 1020
                )
                .is_err()
        );
        let before = server.journal.cursor();
        let input = server
            .receive(
                first,
                &request(61, first_ack, 0xdc, &[40, 1, 0, 0, 0, 0, 0, 0, 0]),
                deadline + 1030,
            )
            .unwrap();
        assert_eq!(server.journal.cursor(), before);
        assert!(
            input
                .iter()
                .all(|(_, bytes)| !matches!(Header::decode(bytes).unwrap().1[0], 0xeb | 0xec))
        );
        server
            .receive(first, &request(62, first_ack, 0xfa, &[]), deadline + 1040)
            .unwrap();
        assert_eq!(server.peers[&second].pending.len(), 1); // no remote leave added
        assert_eq!(server.options.match_id, 1);
        server
            .receive(second, &request(60, 0, 0xfa, &[]), deadline + 1050)
            .unwrap();
        assert!(server.peers.is_empty());
        assert!(server.finishing.is_none());
        assert!(server.started.is_none());
        assert_eq!(server.options.match_id, 2);
        server
            .receive(
                newcomer,
                &request(0, 0, 0xd8, &[3, 0, 0, 0, 0]),
                deadline + 1060,
            )
            .unwrap();
        assert_eq!(server.peers[&newcomer].slot, 0);
        assert_eq!(server.options.match_id, 2);
    }

    #[test]
    fn finish_cancels_loading_join_and_bounds_results_transport_lifetime() {
        let (mut server, first, second) = late_join_fixture();
        let packets = server.finish_match(3000, 3000).unwrap();
        assert!(
            packets
                .iter()
                .any(|(peer, bytes)| *peer == second && Header::decode(bytes).unwrap().1 == [0xfd])
        );
        assert!(!server.peers.contains_key(&second));
        server.peers.get_mut(&first).unwrap().last_seen = 32_999;
        assert!(!server.poll(32_999).unwrap().is_empty());
        assert!(server.finishing.is_some());
        server.poll(33_000).unwrap();
        assert!(server.peers.is_empty());
        assert!(server.started.is_none());
    }

    fn late_join_fixture() -> (Server, SocketAddr, SocketAddr) {
        let mut server = Server::new(2236, 2, 61).unwrap();
        server.snapshots = true;
        server.checkpoints = true;
        server.start_players = 1;
        let first: SocketAddr = "127.0.0.1:40001".parse().unwrap();
        let second: SocketAddr = "127.0.0.1:40002".parse().unwrap();
        server
            .receive(first, &request(0, 0, 0xd8, &[1, 0, 0, 0, 0]), 0)
            .unwrap();
        server
            .receive(first, &request(1, 0, 0xd9, &[1, 0, 0, 0]), 10)
            .unwrap();
        let body = [50u32.to_le_bytes().as_slice(), &[0, 0, 4, 0, 0, 0, 0, 0]].concat();
        server
            .receive(first, &request(2, 1, 0xe2, &body), 20)
            .unwrap();
        server
            .receive(first, &request(3, 1, 0xda, &[]), 50)
            .unwrap();
        assert_eq!(server.started, Some(50)); // Capacity 2, bootstrap threshold 1.
        let out = server
            .receive(first, &request(4, 2, 0xdb, &[0; 6]), 60)
            .unwrap();
        let state = out
            .iter()
            .find(|(_, p)| Header::decode(p).unwrap().1[0] == 0xe8)
            .unwrap();
        let sequence = Header::decode(&state.1).unwrap().0.sequence;
        let out = server
            .receive(first, &request(5, sequence, 0xfc, &[]), 70)
            .unwrap();
        assert!(server.membership_sent);
        assert_eq!(server.peers[&first].active_at, Some(400));
        let entries: Vec<_> = out
            .iter()
            .filter(|(_, p)| Header::decode(p).unwrap().1[0] == 0xe9)
            .collect();
        assert_eq!(entries.len(), 1);
        assert_eq!(Header::decode(&entries[0].1).unwrap().1, [0xe9, 8, 0]);
        server
            .receive(second, &request(0, 0, 0xd8, &[2, 0, 0, 0, 0]), 2000)
            .unwrap();
        server
            .receive(second, &request(1, 0, 0xd9, &[2, 0, 0, 0]), 2001)
            .unwrap();
        server
            .receive(second, &request(2, 1, 0xe2, &body), 2002)
            .unwrap();
        server
            .receive(second, &request(3, 1, 0xda, &[]), 2003)
            .unwrap();
        let mut bytes = 1u32.to_le_bytes().to_vec();
        let mut seed = 17u32;
        for _ in 0..2048 {
            seed ^= seed << 13;
            seed ^= seed >> 17;
            seed ^= seed << 5;
            bytes.push(seed as u8);
        }
        server.latest_checkpoint = Some(crate::snapshot::Checkpoint {
            time: 1950,
            crc: crc32fast::hash(&bytes),
            bytes,
        });
        (server, first, second)
    }

    fn ack_all(server: &mut Server, address: SocketAddr, sequence: u8, now: u64) -> Outbound {
        let packet = Header {
            sequence,
            ack_sequence: (server.peers[&address].generation - 1) as u8,
            ack_mask: u128::MAX,
            ack_bits: 127,
            single_message: true,
        }
        .encode(&[0xfc])
        .unwrap();
        server.receive(address, &packet, now).unwrap()
    }

    #[test]
    fn late_join_waits_for_state_and_revised_replay_ack_before_entry() {
        let (mut server, first, second) = late_join_fixture();
        let out = server.poll(2010).unwrap();
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1[0] == 0xe5)
        );
        assert!(
            !out.iter()
                .any(|(a, p)| *a == second
                    && Header::decode(p).unwrap().1.starts_with(&[0xff, 0xe8]))
        );
        let out = server
            .receive(second, &request(4, 2, 0xdb, &[0; 6]), 2020)
            .unwrap();
        let fragments: Vec<_> = out
            .iter()
            .filter(|(a, p)| {
                *a == second && Header::decode(p).unwrap().1.starts_with(&[0xff, 0xe8])
            })
            .collect();
        assert!(fragments.len() > 1);
        let seq = Header::decode(&fragments[0].1).unwrap().0.sequence;
        server
            .receive(second, &request(5, seq, 0xfc, &[]), 2030)
            .unwrap();
        let input = [vec![41], vec![1; 8]].concat();
        let out = server
            .receive(first, &request(6, 0, 0xdc, &input), 2050)
            .unwrap();
        assert!(
            !out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1[0] == 0xeb)
        );
        // A missing state fragment is retried; no entry occurs while it is missing.
        let out = server.poll(2530).unwrap();
        assert!(
            out.iter()
                .any(|(a, p)| *a == second
                    && Header::decode(p).unwrap().1.starts_with(&[0xff, 0xe8]))
        );
        assert!(server.peers[&second].active_at.is_none());
        let out = ack_all(&mut server, second, 6, 2540);
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1[0] == 0xeb)
        );
        // Revision arrives while the first replay batch is still unacknowledged.
        let revised = [vec![41], vec![2; 8]].concat();
        server
            .receive(first, &request(7, 0, 0xdc, &revised), 2550)
            .unwrap();
        server.poll(2800).unwrap(); // Replay may not disappear via its usual 250ms lifetime.
        assert!(server.peers[&second].active_at.is_none());
        let out = ack_all(&mut server, second, 7, 2810);
        assert!(out.iter().any(|(a, p)| *a == second
            && Header::decode(p).unwrap().1 == [vec![0xeb, 41, 0], vec![2; 8]].concat()));
        assert!(server.peers[&second].active_at.is_none());
        let out = ack_all(&mut server, second, 8, 2820);
        assert_eq!(server.peers[&second].active_at, Some(3150));
        assert_eq!(server.started, Some(50));
        assert_eq!(server.peers[&first].resync_sequence, 1);
        assert_eq!(
            out.iter()
                .filter(|(_, p)| Header::decode(p).unwrap().1 == [0xe9, 63, 1])
                .count(),
            2
        );
    }

    #[test]
    fn invalidated_or_stalled_join_fails_without_removing_active_player() {
        for invalidate in [false, true] {
            let (mut server, first, second) = late_join_fixture();
            server.poll(2010).unwrap();
            if invalidate {
                let input = [vec![38], vec![1; 8]].concat(); // Before selected 1950ms baseline.
                server
                    .receive(first, &request(6, 0, 0xdc, &input), 2050)
                    .unwrap();
            } else {
                server.poll(7010).unwrap();
            }
            assert!(!server.peers.contains_key(&second));
            assert!(server.peers.contains_key(&first));
            assert_eq!(server.started, Some(50));
            assert_eq!(*server.membership.last_key_value().unwrap().1, 1);
            assert!(
                server
                    .journal
                    .after(1950, 0)
                    .iter()
                    .all(|e| e.opcode != 0xea)
            );
        }
    }

    #[test]
    fn clock_feedback_corrects_without_resetting_the_world_or_reusing_replies() {
        let (mut server, first, _) = late_join_fixture();
        server.clock_sync = true;
        server.latest_checkpoint = None;
        let mut rtt = 0u16;
        for index in 0..3u8 {
            let now = 2010 + u64::from(index) * 2000;
            let out = server.poll(now).unwrap();
            let probe = out
                .iter()
                .find(|(a, p)| *a == first && Header::decode(p).unwrap().1[0] == 0xe6)
                .unwrap();
            let (header, bytes) = Header::decode(&probe.1).unwrap();
            let frame = protocol::decode_frames(bytes, true, Direction::Server, 2).unwrap()[0];
            assert_eq!(
                frame.body,
                [(now as u16).to_le_bytes(), rtt.to_le_bytes()].concat()
            );
            let body = [
                rtt.to_le_bytes(),
                (now as u16).to_le_bytes(),
                (now as u16 + 60).to_le_bytes(),
            ]
            .concat();
            let out = server
                .receive(
                    first,
                    &request(6 + index, header.sequence, 0xdb, &body),
                    now + 20,
                )
                .unwrap();
            assert!(out.iter().all(
                |(a, p)| *a != first || !matches!(Header::decode(p).unwrap().1[0], 0xe5 | 0xe8)
            ));
            let adjustments: Vec<_> = out
                .iter()
                .filter(|(a, p)| *a == first && Header::decode(p).unwrap().1[0] == 0xe7)
                .collect();
            assert_eq!(adjustments.len(), usize::from(index == 2));
            if let Some((_, packet)) = adjustments.first() {
                let body = Header::decode(packet).unwrap().1;
                assert_eq!(i16::from_le_bytes(body[2..4].try_into().unwrap()), -50);
            }
            rtt = 20;
        }
        assert_eq!(server.peers[&first].resync_sequence, 1);
        assert_eq!(server.started, Some(50));
    }

    #[test]
    fn inputs_outside_activation_or_retained_time_window_are_not_relayed() {
        let (mut server, first, second) = late_join_fixture();
        server.peers.get_mut(&second).unwrap().active_at = Some(400);
        for (sequence, id, body) in [
            (6, 0xdc, [vec![7], vec![1; 8]].concat()), // 350, before activation.
            (7, 0xdd, [vec![40, 50], vec![1; 8]].concat()), // Invalid subtick.
            (8, 0xdc, [vec![60], vec![1; 8]].concat()), // Too far in the future.
        ] {
            let out = server
                .receive(first, &request(sequence, 0, id, &body), 2050)
                .unwrap();
            assert!(
                out.iter()
                    .all(|(_, p)| !matches!(Header::decode(p).unwrap().1[0], 0xeb | 0xec))
            );
        }
        assert!(server.history.after(400, 2050).unwrap().is_empty());
        assert!(server.journal.after(400, 0).is_empty());
        let input = [vec![41], vec![1; 8]].concat();
        let out = server
            .receive(first, &request(9, 0, 0xdc, &input), 2050)
            .unwrap();
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1[0] == 0xeb)
        );
        assert_eq!(server.history.after(400, 2050).unwrap().len(), 1);
        assert_eq!(server.journal.after(400, 0).len(), 1);
    }

    #[test]
    fn late_join_replays_reference_departure_before_its_own_entry() {
        let (mut server, first, second) = late_join_fixture();
        server.poll(2010).unwrap();
        server
            .receive(second, &request(4, 2, 0xdb, &[0; 6]), 2020)
            .unwrap();
        server
            .receive(first, &request(6, 0, 0xfa, &[]), 2050)
            .unwrap();
        let out = ack_all(&mut server, second, 5, 2060);
        assert!(
            out.iter()
                .any(|(a, p)| *a == second && Header::decode(p).unwrap().1 == [0xea, 47, 0])
        );
        assert!(server.peers[&second].active_at.is_none());
        ack_all(&mut server, second, 6, 2070);
        assert_eq!(server.peers[&second].active_at, Some(2400));
        assert_eq!(*server.membership.last_key_value().unwrap().1, 2);
    }

    #[test]
    fn automatic_recovery_targets_only_the_disagreeing_peer_and_obeys_cooldown() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        let addresses: [SocketAddr; 2] = [
            "127.0.0.1:40001".parse().unwrap(),
            "127.0.0.1:40002".parse().unwrap(),
        ];
        for (slot, address) in addresses.iter().enumerate() {
            server
                .receive(
                    *address,
                    &request(0, 0, 0xd8, &[slot as u8 + 1, 0, 0, 0, 0]),
                    0,
                )
                .unwrap();
            let peer = server.peers.get_mut(address).unwrap();
            peer.pending.clear();
            peer.ready = true;
            peer.startup_sent = true;
            peer.state_sent = true;
            peer.active_at = Some(0);
        }
        server.started = Some(0);
        server.membership_sent = true;
        server.recover = true;
        server.restore_once_after_ms = Some(50000); // Future diagnostic must not block recovery.
        server.drop_relay = Some((1, 1000, 1100));
        let input = [vec![20], vec![0; 8]].concat();
        let out = server
            .receive(addresses[0], &request(1, 0, 0xdc, &input), 1000)
            .unwrap();
        assert!(
            out.iter()
                .all(|(_, packet)| Header::decode(packet).unwrap().1[0] != 0xeb)
        );
        assert_eq!(server.dropped_relays, 1);
        assert_eq!(server.history.after(900, 1000).unwrap().len(), 1);
        for time in [1000, 1100, 1200] {
            server.monitor.observe(0, time, 7, time);
            server.monitor.observe(1, time, 8, time);
        }
        let checkpoint = |time| crate::snapshot::Checkpoint {
            time,
            bytes: 3u32.to_le_bytes().to_vec(),
            crc: crc32fast::hash(&3u32.to_le_bytes()),
        };
        server.latest_checkpoint = Some(checkpoint(1500));
        let out = server.poll(2200).unwrap();
        assert_eq!(server.peers[&addresses[0]].resync_sequence, 1);
        assert_eq!(server.peers[&addresses[1]].resync_sequence, 2);
        assert!(!server.restored_once);
        let state = out
            .iter()
            .find(|(peer, packet)| {
                *peer == addresses[1] && Header::decode(packet).unwrap().1[0] == 0xe8
            })
            .unwrap();
        let sequence = Header::decode(&state.1).unwrap().0.sequence;
        server
            .receive(addresses[1], &request(1, sequence, 0xfc, &[]), 2210)
            .unwrap();
        assert!(server.peers[&addresses[1]].restoring.is_none());
        for time in [10600, 10700, 10800] {
            server.monitor.observe(0, time, 7, time);
            server.monitor.observe(1, time, 8, time);
        }
        server.latest_checkpoint = Some(checkpoint(11000));
        server.poll(12000).unwrap();
        assert_eq!(server.peers[&addresses[1]].resync_sequence, 2);
        server.poll(12200).unwrap();
        assert_eq!(server.peers[&addresses[1]].resync_sequence, 3);
        assert_eq!(server.peers[&addresses[0]].resync_sequence, 1);
    }

    #[test]
    fn admission_rejects_zero_and_duplicate_sessions_without_occupying_a_slot() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        let first: SocketAddr = "127.0.0.1:40001".parse().unwrap();
        let second: SocketAddr = "127.0.0.1:40002".parse().unwrap();
        assert!(
            server
                .receive(first, &request(0, 0, 0xd8, &[0; 5]), 0)
                .is_err()
        );
        assert!(server.peers.is_empty());
        server
            .receive(first, &request(0, 0, 0xd8, &[7, 0, 0, 0, 0]), 0)
            .unwrap();
        // Repeated handshake from the same endpoint remains valid.
        server
            .receive(first, &request(1, 0, 0xd8, &[7, 0, 0, 0, 0]), 1)
            .unwrap();
        assert!(
            server
                .receive(second, &request(0, 0, 0xd8, &[7, 0, 0, 0, 0]), 2)
                .is_err()
        );
        assert_eq!(server.peers.len(), 1);
        server
            .receive(second, &request(0, 0, 0xd8, &[8, 0, 0, 0, 0]), 3)
            .unwrap();
        assert_eq!(server.peers[&second].slot, 1);
        server.receive(first, &request(2, 0, 0xfa, &[]), 4).unwrap();
        server
            .receive(first, &request(0, 0, 0xd8, &[7, 0, 0, 0, 0]), 5)
            .unwrap();
        assert_eq!(server.peers[&first].slot, 0);
    }

    #[test]
    fn restoration_replays_after_all_state_fragments_are_acknowledged() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        let addresses: [SocketAddr; 2] = [
            "127.0.0.1:40001".parse().unwrap(),
            "127.0.0.1:40002".parse().unwrap(),
        ];
        for address in addresses {
            server
                .receive(
                    address,
                    &request(
                        0,
                        0,
                        0xd8,
                        &[address.port().to_le_bytes().as_slice(), &[0, 0, 0]].concat(),
                    ),
                    0,
                )
                .unwrap();
            let peer = server.peers.get_mut(&address).unwrap();
            peer.pending.clear();
            peer.startup_sent = true;
            peer.ready = true;
            peer.state_sent = true;
            peer.active_at = Some(0);
        }
        server.started = Some(0);
        server.membership_sent = true;
        server.restore_once_after_ms = Some(1000);
        // Incompressible opaque bytes exercise fragmentation, not engine validity.
        let mut bytes = 3u32.to_le_bytes().to_vec();
        let mut seed = 17u32;
        for _ in 0..2048 {
            seed ^= seed << 13;
            seed ^= seed >> 17;
            seed ^= seed << 5;
            bytes.push(seed as u8);
        }
        server.latest_checkpoint = Some(crate::snapshot::Checkpoint {
            time: 1000,
            crc: crc32fast::hash(&bytes),
            bytes,
        });
        let input = vec![22, 1, 0, 0, 0, 0, 1, 0, 0, 0];
        server.history.record(
            crate::history::Input {
                time: 1100,
                slot: 1,
                opcode: 0xeb,
                body: input.clone(),
            },
            1100,
        );
        let mut own_input = input.clone();
        own_input[1] = 0;
        server.history.record(
            crate::history::Input {
                time: 1100,
                slot: 0,
                opcode: 0xeb,
                body: own_input.clone(),
            },
            1100,
        );
        let output = server.poll(1100).unwrap();
        let state_packets: Vec<_> = output
            .iter()
            .filter(|(peer, packet)| {
                *peer == addresses[0]
                    && Header::decode(packet).unwrap().1.starts_with(&[0xff, 0xe8])
            })
            .collect();
        assert!(state_packets.len() > 1);
        let (first_header, first_body) = Header::decode(&state_packets[0].1).unwrap();
        let first = protocol::decode_frames(first_body, true, Direction::Server, 2).unwrap()[0];
        assert_eq!(&first.body[..2], &[2, 1]); // New application resync sequence, compressed.
        let output = server
            .receive(
                addresses[0],
                &request(1, first_header.sequence, 0xfc, &[]),
                1110,
            )
            .unwrap();
        assert!(
            output
                .iter()
                .all(|(_, packet)| Header::decode(packet).unwrap().1[0] != 0xeb)
        );
        assert!(server.peers[&addresses[0]].restoring.is_some());
        let last = Header::decode(&state_packets.last().unwrap().1)
            .unwrap()
            .0
            .sequence;
        let ack = Header {
            sequence: 2,
            ack_sequence: last,
            ack_mask: u128::MAX,
            ack_bits: 127,
            single_message: true,
        }
        .encode(&[0xfc])
        .unwrap();
        let output = server.receive(addresses[0], &ack, 1200).unwrap();
        let expected = [vec![0xeb], input].concat();
        assert!(
            output.iter().any(|(peer, packet)| *peer == addresses[0]
                && Header::decode(packet).unwrap().1 == expected)
        );
        let own_echo = [vec![0xeb], own_input].concat();
        assert!(
            output.iter().all(|(peer, packet)| *peer != addresses[0]
                || Header::decode(packet).unwrap().1 != own_echo)
        );
        assert!(server.peers[&addresses[0]].restoring.is_none());
        assert!(server.peers[&addresses[1]].restoring.is_some());
        let output = server.poll(3100).unwrap();
        assert!(!server.peers.contains_key(&addresses[1]));
        assert!(server.peers.contains_key(&addresses[0]));
        assert!(
            output
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1 == [0xfd])
        );
    }

    fn request(sequence: u8, ack: u8, id: u8, body: &[u8]) -> Vec<u8> {
        let frame = protocol::encode_frame(
            Frame {
                id,
                unique_id: None,
                fragment: None,
                body,
            },
            true,
            Direction::ClientSnapshots,
            2,
        )
        .unwrap();
        Header {
            sequence,
            ack_sequence: ack,
            ack_mask: NEWEST,
            ack_bits: 7,
            single_message: true,
        }
        .encode(&frame)
        .unwrap()
    }
    #[test]
    fn snapshot_startup_and_checkpoints_require_the_expected_peers() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        server.snapshots = true;
        let addresses: [SocketAddr; 2] = [
            "127.0.0.1:40001".parse().unwrap(),
            "127.0.0.1:40002".parse().unwrap(),
        ];
        for (slot, address) in addresses.iter().enumerate() {
            server
                .receive(
                    *address,
                    &request(
                        0,
                        0,
                        0xd8,
                        &[address.port().to_le_bytes().as_slice(), &[0, 0, 0]].concat(),
                    ),
                    0,
                )
                .unwrap();
            server
                .receive(
                    *address,
                    &request(1, 0, 0xd9, &u32::from(address.port()).to_le_bytes()),
                    10,
                )
                .unwrap();
            // Opaque bytes sufficient to exercise scheduling, not an engine fixture.
            let body = [50u32.to_le_bytes().as_slice(), &[0, 0, 4, 0, 0, 0, 0, 0]].concat();
            crate::snapshot::Upload::receive(
                &mut server.peers.get_mut(address).unwrap().snapshot,
                &body,
            )
            .unwrap();
            server
                .receive(*address, &request(2, 1, 0xda, &[]), 20 + slot as u64)
                .unwrap();
        }
        assert!(server.started.is_some());
        assert!(
            server
                .poll(30)
                .unwrap()
                .iter()
                .all(|(_, bytes)| Header::decode(bytes).unwrap().1.first() != Some(&0xe8))
        );
        let mut states = Vec::new();
        for address in addresses {
            let clock_sequence = (server.peers[&address].generation - 1) as u8;
            let replies = server
                .receive(address, &request(3, clock_sequence, 0xdb, &[0; 6]), 40)
                .unwrap();
            let (_, state) = replies
                .iter()
                .find(|(peer, bytes)| {
                    *peer == address && Header::decode(bytes).unwrap().1.first() == Some(&0xe8)
                })
                .unwrap();
            states.push(Header::decode(state).unwrap().0.sequence);
            assert!(!server.membership_sent);
            assert!(
                !server.peers[&address]
                    .pending
                    .iter()
                    .any(|p| p.frame[0] == 0xe5)
            );
        }
        server
            .receive(addresses[0], &request(4, states[0], 0xfc, &[]), 50)
            .unwrap();
        assert!(!server.membership_sent);
        let replies = server
            .receive(addresses[1], &request(4, states[1], 0xfc, &[]), 60)
            .unwrap();
        assert!(server.membership_sent);
        assert_eq!(
            replies
                .iter()
                .filter(|(_, bytes)| Header::decode(bytes).unwrap().1.first() == Some(&0xe9))
                .count(),
            4
        );
        server.checkpoints = true;
        let mut hash = vec![120]; // 6000 ms near this match's wall-clock epoch.
        hash.extend_from_slice(&0xcbf43926u32.to_le_bytes());
        let replies = server
            .receive(addresses[0], &request(5, states[0], 0xdf, &hash), 6000)
            .unwrap();
        assert!(
            replies
                .iter()
                .any(|(address, packet)| *address == addresses[0]
                    && Header::decode(packet).unwrap().1 == [0xf7, 0x70, 0x17, 0, 0])
        );
        let body = [
            6000u32.to_le_bytes().as_slice(),
            &[0, 0, 9, 0],
            b"123456789",
        ]
        .concat();
        server
            .receive(addresses[1], &request(5, states[1], 0xe2, &body), 6001)
            .unwrap();
        assert!(server.latest_checkpoint.is_none()); // Only the selected reference may supply it.
        server
            .receive(addresses[0], &request(6, states[0], 0xe2, &body), 6002)
            .unwrap();
        assert!(server.checkpoint_request.is_none());
        assert_eq!(server.latest_checkpoint.as_ref().unwrap().time, 6000);
        assert_eq!(server.latest_checkpoint.as_ref().unwrap().crc, 0xcbf43926);
        hash[0] = 220; // Next eligible checkpoint, at 11000 ms.
        server
            .receive(addresses[0], &request(7, states[0], 0xdf, &hash), 11000)
            .unwrap();
        assert_eq!(server.checkpoint_request.as_ref().unwrap().1.time, 11000);
        server
            .receive(addresses[0], &request(8, states[0], 0xe2, &body), 11001)
            .unwrap();
        assert_eq!(server.latest_checkpoint.as_ref().unwrap().time, 6000);
        assert!(server.checkpoint_request.is_some()); // Old chunks did not satisfy the new request.
        server.poll(13000).unwrap();
        assert!(server.checkpoint_request.is_none());
        assert!(
            !server.peers[&addresses[0]]
                .pending
                .iter()
                .any(|p| p.frame[0] == 0xf7)
        );
    }

    #[test]
    fn setup_retries_then_starts_and_relays_two_clients() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        let addresses: [SocketAddr; 2] = [
            "127.0.0.1:40001".parse().unwrap(),
            "127.0.0.1:40002".parse().unwrap(),
        ];
        for (slot, address) in addresses.iter().enumerate() {
            let base = slot as u64 * 1000;
            let replies = server
                .receive(
                    *address,
                    &request(
                        0,
                        0,
                        0xd8,
                        &[address.port().to_le_bytes().as_slice(), &[0, 0, 0]].concat(),
                    ),
                    base,
                )
                .unwrap();
            let reply = replies.iter().find(|(peer, _)| peer == address).unwrap();
            assert_eq!(
                Header::decode(&reply.1).unwrap().1,
                [0xe3, 0xbc, 8, 0xbc, 8]
            );
            let replies = server
                .receive(
                    *address,
                    &request(1, 0, 0xd9, &u32::from(address.port()).to_le_bytes()),
                    base + 10,
                )
                .unwrap();
            let reply = replies.iter().find(|(peer, _)| peer == address).unwrap();
            let (header, body) = Header::decode(&reply.1).unwrap();
            let frame = protocol::decode_frames(body, true, Direction::Server, 2).unwrap()[0];
            assert_eq!(frame.id, 0xe4);
            assert_eq!(frame.body[0], slot as u8);
            assert!(
                survarium::protocol_026::compression::decompress(&frame.body[1..], 0x578a0)
                    .unwrap()
                    .len()
                    > 320
            );
            let retry = server.poll(base + 510).unwrap();
            assert!(retry.iter().any(|(peer, _)| peer == address));
            // Ack the first transmission, even though a newer retry was sent.
            server
                .receive(
                    *address,
                    &request(2, header.sequence, 0xda, &[]),
                    base + 520,
                )
                .unwrap();
            assert!(
                !server.peers[address]
                    .pending
                    .iter()
                    .any(|p| p.frame[0] == 0xe4)
            );
        }
        assert!(server.started.is_some());
        for peer in server.peers.values() {
            let entries: Vec<_> = peer
                .pending
                .iter()
                .filter(|pending| pending.frame.first() == Some(&0xe9))
                .map(|pending| pending.frame.as_slice())
                .collect();
            assert_eq!(entries, [&[0xe9, 1, 0][..], &[0xe9, 1, 1][..]]);
        }
        let replies = server
            .receive(
                addresses[0],
                &request(3, 2, 0xdc, &[1, 2, 3, 4, 5, 6, 7, 8, 9]),
                1600,
            )
            .unwrap();
        assert!(
            replies
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1 == [0xeb, 1, 0, 2, 3, 4, 5, 6, 7, 8, 9])
        );
        let retries = server.poll(1650).unwrap();
        assert!(
            retries
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1.first() == Some(&0xeb))
        );
        let expired = server.poll(1850).unwrap();
        assert!(
            !expired
                .iter()
                .any(|(_, packet)| Header::decode(packet).unwrap().1.first() == Some(&0xeb))
        );
        assert!(
            !server.peers[&addresses[1]]
                .pending
                .iter()
                .any(|p| p.frame[0] == 0xeb)
        );
        let closed = server
            .receive(addresses[0], &request(4, 2, 0xfa, &[]), 1900)
            .unwrap();
        assert!(
            closed
                .iter()
                .any(|(address, packet)| *address == addresses[0]
                    && Header::decode(packet).unwrap().1 == [0xfb])
        );
        assert!(!server.peers.contains_key(&addresses[0]));
        // Started at 1520 ms: ceil((1900 - 1520 + 300) / 50) = 14.
        assert!(
            closed
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1 == [0xea, 14, 0])
        );
        let retried = server.poll(1950).unwrap();
        assert!(
            retried
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1 == [0xea, 14, 0])
        );
        // The final peer times out, freeing this endpoint for a fresh cohort.
        server.poll(121_520).unwrap();
        assert!(server.peers.is_empty());
        assert!(server.started.is_none());
        assert!(!server.membership_sent);
        let reopened = server
            .receive(
                addresses[0],
                &request(0, 0, 0xd8, &[2, 0, 0, 0, 0]),
                121_530,
            )
            .unwrap();
        assert!(
            reopened
                .iter()
                .any(|(address, packet)| *address == addresses[0]
                    && Header::decode(packet).unwrap().1[0] == 0xe3)
        );
        assert_eq!(server.peers[&addresses[0]].slot, 0);
    }

    #[test]
    fn losing_a_peer_during_state_transfer_cancels_the_incomplete_cohort() {
        let mut server = Server::new(2236, 2, 61).unwrap();
        server.snapshots = true;
        let addresses: [SocketAddr; 2] = [
            "127.0.0.1:40001".parse().unwrap(),
            "127.0.0.1:40002".parse().unwrap(),
        ];
        for address in addresses {
            server
                .receive(
                    address,
                    &request(
                        0,
                        0,
                        0xd8,
                        &[address.port().to_le_bytes().as_slice(), &[0, 0, 0]].concat(),
                    ),
                    0,
                )
                .unwrap();
            server
                .receive(
                    address,
                    &request(1, 0, 0xd9, &u32::from(address.port()).to_le_bytes()),
                    10,
                )
                .unwrap();
            let body = [50u32.to_le_bytes().as_slice(), &[0, 0, 4, 0, 0, 0, 0, 0]].concat();
            crate::snapshot::Upload::receive(
                &mut server.peers.get_mut(&address).unwrap().snapshot,
                &body,
            )
            .unwrap();
            server
                .receive(address, &request(2, 1, 0xda, &[]), 20)
                .unwrap();
        }
        assert!(server.started.is_some());
        assert!(!server.membership_sent);
        let replies = server
            .receive(addresses[0], &request(3, 2, 0xfa, &[]), 30)
            .unwrap();
        assert!(
            replies
                .iter()
                .any(|(address, packet)| *address == addresses[1]
                    && Header::decode(packet).unwrap().1 == [0xfd])
        );
        assert!(server.peers.is_empty());
        assert!(server.started.is_none());
        assert!(server.initial_state.is_none());
        assert!(server.poll(1000).unwrap().is_empty());
    }

    #[test]
    fn sequence_window_wrap_and_duplicate_filtering() {
        let mut history = History::default();
        assert!(history.receive(254));
        assert!(history.receive(0));
        assert!(history.receive(255));
        assert!(!history.receive(254));
        assert!(!history.receive(128));
        assert!(history.receive(1));
        assert_eq!(history.mask >> 124, 15);
    }
}
