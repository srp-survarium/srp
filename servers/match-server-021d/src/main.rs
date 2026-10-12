// SPDX-License-Identifier: GPL-3.0-or-later
//! Loopback v0.21d test server. See docs/v021d/SERVER-PLAN.txt for gates.
mod supervision;
mod test_control;
use match_server_021d::{
    coordinator::{Coordinator, Delivery, InputDecision},
    protocol::{self, Extension, Protocol},
    setup,
    snapshot::Assembler,
    transport::{Endpoint, Message},
    wire::{self, Direction},
};
use std::{
    collections::HashMap,
    error::Error,
    net::{SocketAddr, UdpSocket},
    time::{Duration, Instant, SystemTime, UNIX_EPOCH},
};

struct Peer {
    slot: u8,
    session: u32,
    endpoint: Endpoint,
    uploads: Assembler,
    prepared: bool,
    last_seen: u64,
    connected_at: u64,
    last_actions: Option<u32>,
    blackout_until: u64,
    dropped_packets: usize,
    state_blackout: Option<u64>,
}
struct Server {
    protocol: Protocol,
    peers: HashMap<SocketAddr, Peer>,
    coordinator: Coordinator,
    roster: u8,
    accounts: Vec<u32>,
    starting: u8,
    port: u16,
    match_seconds: u16,
    instance: u128,
    generation: u64,
    participants: u32,
    trace_clock: bool,
    completed: Option<(u64, u32, Vec<Option<Vec<u8>>>)>,
}
fn u32_at(bytes: &[u8], offset: usize) -> Option<u32> {
    Some(u32::from_le_bytes(
        bytes.get(offset..offset + 4)?.try_into().ok()?,
    ))
}
impl Server {
    fn message(
        &mut self,
        addr: SocketAddr,
        message: Message,
        now: u64,
    ) -> Result<bool, Box<dyn Error>> {
        let peer = self.peers.get_mut(&addr).ok_or("unknown peer")?;
        let b = &message.body;
        let mut deliveries = Vec::new();
        match message.opcode {
            0 if b.is_empty() => {
                peer.endpoint.send(1, &[], now)?;
                return Ok(true);
            }
            1 | 2 if b.is_empty() => {}
            0x40 if b.len() == 5 && b[4] == 0 && u32_at(b, 0) == Some(peer.session) => {
                if !peer.prepared && peer.endpoint.pending_count() == 0 {
                    peer.endpoint.send(
                        0x50,
                        &[self.port.to_le_bytes(), self.port.to_le_bytes()].concat(),
                        now,
                    )?;
                }
            }
            0x41 if b.len() == 4 && u32_at(b, 0) == Some(peer.session) => {
                if !peer.prepared {
                    peer.endpoint.send(
                        0x51,
                        &setup::with_accounts(&self.accounts, peer.slot, self.match_seconds)?,
                        now,
                    )?;
                    self.coordinator.prepared(peer.slot)?;
                    peer.prepared = true;
                    println!("static setup sent: slot={}", peer.slot);
                }
            }
            0x42 if b.is_empty() => {
                self.coordinator.ready(peer.slot)?;
                println!("resources ready: slot={}", peer.slot);
            }
            0x43 => deliveries = self.coordinator.clock_reply(peer.slot, b)?,
            0x44 => {
                let rtt = if peer.endpoint.has_pending(&[0x52, 0x53, 0x55]) {
                    None
                } else {
                    peer.endpoint.round_trip_ms(now)
                };
                if self.trace_clock {
                    println!(
                        "clock observation: slot={}, wall_ms={now}, shared_ms={:?}, reported_ms={:?}, rtt_ms={rtt:?}",
                        peer.slot,
                        self.coordinator.game_time(now).ok(),
                        u32_at(b, 0)
                    );
                }
                deliveries = self.coordinator.clock_observation(peer.slot, b, now, rtt)?;
                if let Some(slew) = deliveries.first() {
                    println!(
                        "clock slew: slot={}, offset_ms={}, rtt_ms={}",
                        peer.slot,
                        i16::from_le_bytes(slew.body[..2].try_into().unwrap()),
                        rtt.unwrap()
                    );
                }
            }
            0x45 => {
                let (decision, output) = self.coordinator.input(peer.slot, b, now)?;
                deliveries = output;
                let actions = u32_at(b, 8);
                if matches!(decision, InputDecision::Accepted | InputDecision::Revision)
                    && peer.last_actions != actions
                {
                    println!(
                        "input: slot={}, time={}, actions={:08x}, decision={decision:?}",
                        peer.slot,
                        u32_at(b, 12).unwrap(),
                        actions.unwrap()
                    );
                    peer.last_actions = actions;
                }
                if decision == InputDecision::Capacity {
                    return Err("input history capacity reached".into());
                }
            }
            0x46 if b.len() == 8 => {
                for comparison in self.coordinator.hash(peer.slot, b, now)? {
                    if comparison.crcs[0] != comparison.crcs[1] {
                        println!(
                            "historical CRC disagreement: time={}, slots={:?}, crcs={:08x?}",
                            comparison.time, comparison.slots, comparison.crcs
                        );
                    }
                }
            }
            0x47 | 0x48 => {
                let fragment = match self.protocol.extension(message.opcode, b)? {
                    Extension::Leave => return Ok(true),
                    Extension::Upload(fragment) => fragment,
                };
                if let Some(snapshot) = peer.uploads.push(fragment, now)? {
                    println!(
                        "snapshot received: slot={}, time={}, bytes={}, mask={:x}, crc={:08x}",
                        peer.slot,
                        snapshot.time,
                        snapshot.body.len(),
                        u32_at(&snapshot.body, 0).unwrap_or(u32::MAX),
                        snapshot.crc32()
                    );
                    if let Some(decision) = self.coordinator.uploaded(peer.slot, snapshot, now)? {
                        println!(
                            "reference upload: slot={}, decision={decision:?}, corroborated_time={:?}",
                            peer.slot,
                            self.coordinator.reference_state().map(|(_, s)| s.time)
                        );
                    }
                }
            }
            _ => {
                return Err(format!(
                    "invalid application message {:02x}, bytes={}",
                    message.opcode,
                    b.len()
                )
                .into());
            }
        }
        self.deliver(deliveries, now);
        Ok(false)
    }

    /// Application/queue errors affect the corresponding peer, never return
    /// through main and shut down the listening service.
    fn deliver(&mut self, deliveries: Vec<Delivery>, now: u64) {
        let mut failed = Vec::new();
        for delivery in deliveries {
            let Some((addr, peer)) = self.peers.iter_mut().find(|(_, p)| p.slot == delivery.slot)
            else {
                continue;
            };
            if delivery.opcode == 0x53 {
                if let Some(ms) = peer.state_blackout.take() {
                    peer.blackout_until = now.saturating_add(ms);
                    peer.dropped_packets = 0;
                    println!(
                        "test state blackout started: slot={}, duration_ms={ms}",
                        peer.slot
                    );
                }
            }
            // One transport boundary covers every coordinator request,
            // including recovery and final-statistics acquisition.
            let body = if delivery.opcode == 0x59 {
                self.protocol.snapshot_request()
            } else {
                &delivery.body
            };
            if let Err(e) = peer.endpoint.send(delivery.opcode, body, now) {
                eprintln!("slot={} queue error: {e}", peer.slot);
                if !failed.contains(addr) {
                    failed.push(*addr);
                }
            } else if matches!(delivery.opcode, 0x52 | 0x53 | 0x56 | 0x57 | 0x59) {
                println!(
                    "coordinator sent: to={}, opcode={:02x}, bytes={}",
                    peer.slot,
                    delivery.opcode,
                    body.len()
                );
            }
        }
        // At most 20 peers can fail; each call removes one before broadcasting.
        for addr in failed {
            self.remove(addr, now);
        }
    }

    fn reset(&mut self, reason: &str) {
        eprintln!("closing test cohort: {reason}");
        self.peers.clear();
        self.participants = 0;
        self.generation = self
            .generation
            .checked_add(1)
            .expect("match generation exhausted");
        self.coordinator =
            Coordinator::with_duration(self.roster, self.starting, self.match_seconds).unwrap();
    }

    fn remove(&mut self, addr: SocketAddr, now: u64) {
        let Some(peer) = self.peers.remove(&addr) else {
            return;
        };
        println!("peer removed: slot={}", peer.slot);
        match self.coordinator.remove(peer.slot, now) {
            Ok(deliveries) => {
                if self.peers.is_empty() {
                    self.participants = 0;
                    self.generation = self
                        .generation
                        .checked_add(1)
                        .expect("match generation exhausted");
                }
                self.deliver(deliveries, now);
            }
            Err(e) => self.reset(e),
        }
    }

    fn flush_peer(
        &mut self,
        socket: &UdpSocket,
        addr: SocketAddr,
        now: u64,
    ) -> Result<(), Box<dyn Error>> {
        if let Some(peer) = self.peers.get_mut(&addr) {
            if peer.blackout_until != 0 && now >= peer.blackout_until {
                println!(
                    "test blackout ended: slot={}, dropped_packets={}",
                    peer.slot, peer.dropped_packets
                );
                peer.blackout_until = 0;
            }
            for packet in peer.endpoint.poll(now)? {
                if now < peer.blackout_until {
                    peer.dropped_packets += 1;
                } else {
                    socket.send_to(&packet, addr)?;
                }
            }
        }
        Ok(())
    }

    fn tick(&mut self, socket: &UdpSocket, now: u64) {
        let idle: Vec<_> = self
            .peers
            .values()
            .filter(|p| p.endpoint.pending_count() == 0)
            .map(|p| p.slot)
            .collect();
        let replay_idle: Vec<_> = self
            .peers
            .values()
            .filter(|p| !p.endpoint.has_pending(&[0x54, 0x56, 0x57]))
            .map(|p| p.slot)
            .collect();
        match self
            .coordinator
            .tick_with_replay_idle(now, &idle, &replay_idle)
        {
            Ok(deliveries) => {
                // Preserve departed participants, excluding unused reserved identities.
                self.participants |= self.coordinator.participant_mask();
                if self
                    .completed
                    .as_ref()
                    .is_none_or(|c| c.0 != self.generation)
                {
                    if let Some(snapshot) = self.coordinator.final_snapshot() {
                        if let Ok(stats) = match_server_021d::results::Stats::from_world(
                            &snapshot.body,
                            self.roster,
                            setup::VICTORY_ITEMS,
                        ) {
                            let packets: Result<Vec<_>, _> = (0..self.roster)
                                .map(|slot| {
                                    if self.participants & (1 << slot) == 0 {
                                        Ok(None)
                                    } else {
                                        stats
                                            .lobby_packet_for_participants(
                                                1,
                                                slot,
                                                &self.accounts,
                                                self.participants,
                                            )
                                            .map(Some)
                                    }
                                })
                                .collect();
                            if let Ok(packets) = packets {
                                println!(
                                    "final results retained: generation={}, snapshot_time={}, team_points={:?}",
                                    self.generation, snapshot.time, stats.team_points
                                );
                                self.completed = Some((self.generation, snapshot.time, packets));
                            }
                        }
                    }
                }
                self.deliver(deliveries, now);
            }
            Err(e) => {
                self.reset(e);
                return;
            }
        }
        for (slot, reason) in self.coordinator.take_failures() {
            eprintln!("restore failed: slot={slot}, reason={reason}");
            if let Some(addr) = self
                .peers
                .iter()
                .find(|(_, p)| p.slot == slot)
                .map(|(a, _)| *a)
            {
                self.remove(addr, now);
            }
        }
        for (slot, phase, time) in self.coordinator.take_notices() {
            println!("restore: slot={slot}, phase={phase}, time={time}");
        }
        let addresses: Vec<_> = self.peers.keys().copied().collect();
        for addr in addresses {
            let Some(peer) = self.peers.get_mut(&addr) else {
                continue;
            };
            for time in peer.uploads.expire(now) {
                eprintln!("expired upload: slot={}, time={time}", peer.slot);
            }
            if now.saturating_sub(peer.last_seen) > 15_000
                || (now.saturating_sub(peer.connected_at) >= 120_000
                    && !self.coordinator.entered(peer.slot))
            {
                self.remove(addr, now);
                continue;
            }
            if let Err(e) = self.flush_peer(socket, addr, now) {
                eprintln!("peer transport/send error: {e}");
                self.remove(addr, now);
            }
        }
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    let mut raw: Vec<_> = std::env::args().skip(1).collect();
    let supervised = raw.iter().filter(|a| *a == "--supervised").count();
    if supervised > 1 {
        return Err("duplicate --supervised".into());
    }
    raw.retain(|a| a != "--supervised");
    let (protocol, positional) = protocol::arguments(raw)?;
    let mut args = positional.into_iter();
    let sessions_file = args
        .next()
        .ok_or("usage: match-server-021d SESSIONS_FILE [PORT] [START_PLAYERS] [MATCH_SECONDS] [TEST_CONTROL_SOCKET] [--protocol community|srp1]")?;
    let supervisor = if supervised == 1 {
        Some(supervision::Supervisor::watch((&sessions_file).into())?)
    } else {
        None
    };
    let port: u16 = args.next().map_or(Ok(12023), |s| s.parse())?;
    let starting: u8 = args.next().map_or(Ok(1), |s| s.parse())?;
    let match_seconds: u16 = args
        .next()
        .map_or(Ok(setup::MATCH_SECONDS), |s| s.parse())?;
    let control = args
        .next()
        .map(|path| test_control::Control::bind(path.into()))
        .transpose()?;
    if args.next().is_some() {
        return Err("unexpected argument".into());
    }
    let grants =
        match_server_021d::sessions::Grants::parse(&std::fs::read_to_string(&sessions_file)?)?;
    let count = grants.accounts.len() as u8;
    let mut admissions = match_server_021d::admission::Admissions::new(grants.sessions);
    let mut server = Server {
        protocol,
        peers: HashMap::new(),
        coordinator: Coordinator::with_duration(count, starting, match_seconds)?,
        roster: count,
        accounts: grants.accounts,
        starting,
        port,
        match_seconds,
        instance: SystemTime::now().duration_since(UNIX_EPOCH)?.as_nanos(),
        generation: 1,
        participants: 0,
        trace_clock: std::env::var_os("SRP_TEST_TRACE_CLOCK").is_some(),
        completed: None,
    };
    let socket = UdpSocket::bind((std::net::Ipv4Addr::LOCALHOST, port))?;
    socket.set_read_timeout(Some(Duration::from_millis(5)))?;
    let start = Instant::now();
    let mut buffer = [0u8; 521];
    println!(
        "v0.21d test server on 127.0.0.1:{port}, roster={count}, starting={starting}, match_seconds={match_seconds}, protocol={}",
        protocol.name()
    );
    loop {
        if supervisor.as_ref().is_some_and(|parent| parent.gone()) {
            return Ok(());
        }
        match socket.recv_from(&mut buffer) {
            Ok((size, addr)) => {
                let now = start.elapsed().as_millis() as u64;
                let data = &buffer[..size];
                if !server.peers.contains_key(&addr) {
                    // A native allocation owns one generation. Retain control
                    // results for its supervisor, but never accept stale grants
                    // into an implicitly restarted world.
                    if supervised == 1 && protocol == Protocol::Srp1 && server.generation != 1 {
                        continue;
                    }
                    let Ok((_, frames)) = wire::decode(Direction::ClientToServer, data) else {
                        continue;
                    };
                    let Some(wire::Frame::Message {
                        opcode: 0x40, body, ..
                    }) = frames.first()
                    else {
                        continue;
                    };
                    if body.len() != 5 || body[4] != 0 {
                        continue;
                    }
                    let session = u32_at(body, 0).unwrap();
                    let Some(&slot) = admissions.sessions.get(&session) else {
                        continue;
                    };
                    if matches!(server.coordinator.routing_status(now), Ok(("finished", _)))
                        || server.coordinator.admit(slot).is_err()
                    {
                        continue;
                    }
                    server.peers.insert(
                        addr,
                        Peer {
                            slot,
                            session,
                            endpoint: Endpoint::new(Direction::ServerToClient),
                            uploads: Assembler::default(),
                            prepared: false,
                            last_seen: now,
                            connected_at: now,
                            last_actions: None,
                            blackout_until: 0,
                            dropped_packets: 0,
                            state_blackout: None,
                        },
                    );
                    println!("peer connected: slot={slot}");
                }
                let peer = server.peers.get_mut(&addr).unwrap();
                let messages = match peer.endpoint.receive(data, now) {
                    Ok(messages) => {
                        peer.last_seen = now;
                        messages
                    }
                    Err(e) => {
                        eprintln!("slot={} transport error: {e}", peer.slot);
                        server.remove(addr, now);
                        continue;
                    }
                };
                for message in messages {
                    match server.message(addr, message, now) {
                        Ok(false) => {}
                        Ok(true) => {
                            if let Err(e) = server.flush_peer(&socket, addr, now) {
                                eprintln!("disconnect confirmation: {e}");
                            }
                            server.remove(addr, now);
                            break;
                        }
                        Err(e) => {
                            eprintln!("peer application error: {e}");
                            server.remove(addr, now);
                            break;
                        }
                    }
                }
            }
            Err(e)
                if matches!(
                    e.kind(),
                    std::io::ErrorKind::WouldBlock | std::io::ErrorKind::TimedOut
                ) => {}
            Err(e) => return Err(e.into()),
        }
        let now = start.elapsed().as_millis() as u64;
        if let Some(control) = &control {
            for command in control.poll() {
                match command {
                    test_control::Command::Admission(change, source) => {
                        let (phase, occupied) = server.coordinator.routing_status(now)?;
                        let (status, disconnect) = admissions.change(
                            change,
                            server.instance,
                            server.generation,
                            &server.accounts,
                            phase,
                            occupied,
                        );
                        if disconnect {
                            if let Some(addr) = server.peers.iter().find_map(|(&addr, peer)| {
                                (peer.slot == change.slot).then_some(addr)
                            }) {
                                server.remove(addr, now);
                            }
                        }
                        let _ = control.reply(
                            &source,
                            &format!(
                                "v1 {} {:x} {} {} {status}",
                                change.revision, server.instance, change.generation, change.slot
                            ),
                        );
                    }
                    test_control::Command::Status(nonce, source) => {
                        let (phase, occupied) = server.coordinator.routing_status(now)?;
                        let reply = format!(
                            "v1 {nonce} {:x} {} {phase} {occupied}",
                            server.instance, server.generation
                        );
                        // An expired/unbound requester never affects the match.
                        let _ = control.reply(&source, &reply);
                    }
                    test_control::Command::Results(nonce, generation, slot, source) => {
                        if let Some((saved_generation, time, packets)) = &server.completed {
                            if *saved_generation == generation {
                                if let Some(packet) =
                                    packets.get(usize::from(slot)).and_then(Option::as_ref)
                                {
                                    use std::fmt::Write;
                                    let mut reply = format!(
                                        "v1 {nonce} {:x} {generation} {time} ",
                                        server.instance
                                    );
                                    for byte in packet {
                                        let _ = write!(reply, "{byte:02x}");
                                    }
                                    let _ = control.reply(&source, &reply);
                                    continue;
                                }
                            }
                        }
                        let _ = control.reply(
                            &source,
                            &format!("v1 {nonce} {:x} {generation} missing", server.instance),
                        );
                    }
                    test_control::Command::Recover(slot) => {
                        if let Err(e) = server.coordinator.request_recovery(slot, now) {
                            eprintln!("test recovery rejected: slot={slot}, reason={e}");
                        }
                    }
                    test_control::Command::ClockOffset(slot, ms) => {
                        if server.coordinator.clock_probe_allowed(slot) {
                            if let Some(peer) = server.peers.values_mut().find(|p| p.slot == slot) {
                                if !peer.endpoint.has_pending(&[0x52, 0x53, 0x55]) {
                                    server.trace_clock = true;
                                    match peer.endpoint.send(0x55, &ms.to_le_bytes(), now) {
                                        Ok(_) => println!(
                                            "test clock offset queued: slot={slot}, offset_ms={ms}, wall_ms={now}"
                                        ),
                                        Err(error) => eprintln!(
                                            "test clock offset not queued: slot={slot}, error={error}"
                                        ),
                                    }
                                }
                            }
                        }
                    }
                    test_control::Command::Blackout(slot, ms) => {
                        if let Some(peer) = server.peers.values_mut().find(|p| p.slot == slot) {
                            if peer.blackout_until == 0 {
                                peer.blackout_until = now.saturating_add(ms);
                                peer.dropped_packets = 0;
                                println!("test blackout started: slot={slot}, duration_ms={ms}");
                            }
                        }
                    }
                    test_control::Command::StateBlackout(slot, ms) => {
                        if let Some(peer) = server.peers.values_mut().find(|p| p.slot == slot) {
                            peer.state_blackout = Some(ms);
                            println!("test state blackout armed: slot={slot}, duration_ms={ms}");
                        }
                    }
                }
            }
        }
        server.tick(&socket, now);
    }
}
