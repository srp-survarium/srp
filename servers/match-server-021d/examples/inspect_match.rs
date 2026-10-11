// SPDX-License-Identifier: GPL-3.0-or-later
//! Read-only, multi-flow inspection of an initial-cohort test capture.
//! Usage: inspect_match CAPTURE.pcap [MATCH_PORT=12023] [--single-match] [--events]
//! --single-match is an explicit assertion that all flows belong to one match;
//! use for late join, whose clock references and initial baselines differ.
//! Supports classic LE microsecond Ethernet or Linux SLL2 IPv4/UDP captures.
//! Each flow must be captured from its connection start. No credentials printed.
use match_server_021d::{
    snapshot::{Assembler, crc32},
    transport::Endpoint,
    wire::{self, Direction},
};
use std::{
    collections::{BTreeMap, BTreeSet},
    error::Error,
    fs::File,
    io::Read,
};

struct Flow {
    client: Endpoint,
    server: Endpoint,
    slot: Option<u8>,
    resets: Vec<(u32, u32)>,
    states: Vec<(u32, u32)>,
    state_masks: BTreeMap<u32, u32>,
    crc: BTreeMap<u32, u32>,
    crc_revisions: usize,
    membership: BTreeSet<(u32, u8, bool)>,
    inputs: BTreeSet<Vec<u8>>,
    relays: BTreeSet<Vec<u8>>,
    counts: BTreeMap<(bool, u8), usize>,
    uploads: Assembler,
    uploaded_states: Vec<(u32, u32, u32, usize)>,
    stats_options: Option<(u8, u8)>,
    last_stats: Option<(u32, match_server_021d::results::Stats)>,
}
impl Flow {
    fn new() -> Self {
        Self {
            client: Endpoint::new(Direction::ClientToServer),
            server: Endpoint::new(Direction::ServerToClient),
            slot: None,
            resets: vec![],
            states: vec![],
            state_masks: BTreeMap::new(),
            crc: BTreeMap::new(),
            crc_revisions: 0,
            membership: BTreeSet::new(),
            inputs: BTreeSet::new(),
            relays: BTreeSet::new(),
            counts: BTreeMap::new(),
            uploads: Assembler::default(),
            uploaded_states: vec![],
            stats_options: None,
            last_stats: None,
        }
    }
    fn mask(&self, time: u32) -> u32 {
        let (baseline, mut mask) = self
            .state_masks
            .range(..=time)
            .next_back()
            .map(|(&t, &m)| (t, m))
            .unwrap_or((0, 0));
        for &(at, slot, entered) in &self.membership {
            if at > time {
                break;
            }
            if at <= baseline {
                continue;
            }
            if entered {
                mask |= 1u32 << slot;
            } else {
                mask &= !(1u32 << slot);
            }
        }
        mask
    }
    fn observe(
        &mut self,
        server: bool,
        opcode: u8,
        b: &[u8],
        now: u64,
    ) -> Result<(), Box<dyn Error>> {
        *self.counts.entry((server, opcode)).or_default() += 1;
        match (server, opcode) {
            (true, 0x51) => {
                self.slot = Some(*b.last().ok_or("empty static setup")?);
                let name_len = usize::from(*b.get(1).ok_or("missing map name")?);
                self.stats_options = Some((
                    *b.get(name_len + 3).ok_or("missing roster")?,
                    *b.get(name_len + 4).ok_or("missing victory items")?,
                ));
            }
            (true, 0x52) => {
                if b.len() != 8 {
                    return Err("invalid clock reset".into());
                }
                self.resets.push((u32_at(b, 0)?, u32_at(b, 4)?));
                self.crc.clear();
                self.membership.clear();
                self.state_masks.clear();
                self.inputs.clear();
                self.relays.clear();
            }
            (true, 0x53) => {
                let time = u32_at(b, 0)?;
                let body = b.get(4..).ok_or("truncated world")?;
                let layout = match_server_021d::state::inspect(body, 20)?;
                self.states.push((time, crc32(body)));
                self.state_masks.insert(time, layout.mask);
            }
            (true, 0x56 | 0x57) => {
                if b.len() != 5 || b[0] >= 20 {
                    return Err("invalid membership event".into());
                }
                self.membership
                    .insert((u32_at(b, 1)?, b[0], opcode == 0x56));
            }
            (false, 0x46) => {
                if b.len() != 8 {
                    return Err("invalid CRC notification".into());
                }
                let time = u32_at(b, 0)?;
                let crc = u32_at(b, 4)?;
                if self
                    .crc
                    .insert(time, crc)
                    .is_some_and(|previous| previous != crc)
                {
                    self.crc_revisions += 1;
                }
            }
            (false, 0x45) => {
                if b.len() != 16 {
                    return Err("invalid input".into());
                }
                self.inputs.insert(b.to_vec());
            }
            (false, 0x47) => {
                if !self.uploads.expire(now).is_empty() {
                    return Err("incomplete captured snapshot expired".into());
                }
                if let Some(s) = self.uploads.push(b, now)? {
                    let layout = match_server_021d::state::inspect(&s.body, 20)?;
                    if let Some((roster, items)) = self.stats_options {
                        self.last_stats = Some((
                            s.time,
                            match_server_021d::results::Stats::from_world(&s.body, roster, items)?,
                        ));
                    }
                    self.uploaded_states
                        .push((s.time, s.crc32(), layout.mask, s.body.len()));
                }
            }
            (true, 0x54) => {
                if b.len() != 17 || b[0] >= 20 {
                    return Err("invalid relayed input".into());
                }
                self.relays.insert(b.to_vec());
            }
            _ => {}
        }
        Ok(())
    }
}
fn u32_at(b: &[u8], offset: usize) -> Result<u32, Box<dyn Error>> {
    Ok(u32::from_le_bytes(
        b.get(offset..offset + 4)
            .ok_or("truncated scalar")?
            .try_into()?,
    ))
}
fn main() -> Result<(), Box<dyn Error>> {
    let mut args = std::env::args().skip(1);
    let path = args
        .next()
        .ok_or("usage: inspect_match CAPTURE.pcap [PORT]")?;
    let port: u16 = args.next().map_or(Ok(12023), |s| s.parse())?;
    let mut single_match = false;
    let mut events = false;
    for arg in args {
        match arg.as_str() {
            "--single-match" => single_match = true,
            "--events" => events = true,
            _ => return Err("expected --single-match or --events".into()),
        }
    }
    if single_match {
        println!("comparison scope: operator asserts this capture contains one match generation");
    }
    let mut file = File::open(path)?;
    let mut global = [0; 24];
    file.read_exact(&mut global)?;
    if global[..4] != [0xd4, 0xc3, 0xb2, 0xa1] {
        return Err("expected LE microsecond classic pcap".into());
    }
    let link = u32_at(&global, 20)?;
    if ![1, 276].contains(&link) {
        return Err("unsupported capture link type".into());
    }
    let mut flows: BTreeMap<([u8; 4], u16), Flow> = BTreeMap::new();
    let mut first = None;
    let mut datagrams = 0;
    let mut bytes = 0;
    loop {
        let mut record = [0; 16];
        if file.read(&mut record[..1])? == 0 {
            break;
        }
        file.read_exact(&mut record[1..])?;
        let captured = u32_at(&record, 8)? as usize;
        if captured > 65555 {
            return Err("oversized capture record".into());
        }
        let mut packet = vec![0; captured];
        file.read_exact(&mut packet)?;
        let timestamp =
            u64::from(u32_at(&record, 0)?) * 1000 + u64::from(u32_at(&record, 4)?) / 1000;
        let now = timestamp.saturating_sub(*first.get_or_insert(timestamp));
        let offset = if link == 1 {
            if packet.get(12..14) != Some(&[8, 0]) {
                continue;
            }
            14
        } else {
            if packet.get(..2) != Some(&[8, 0]) {
                continue;
            }
            20
        };
        let ip = packet.get(offset..).ok_or("truncated link header")?;
        if ip.len() < 20 {
            return Err("truncated IPv4 header".into());
        }
        if ip[0] >> 4 != 4 || ip[9] != 17 {
            continue;
        }
        let ihl = usize::from(ip[0] & 15) * 4;
        let size = usize::from(u16::from_be_bytes(ip[2..4].try_into()?));
        if ihl < 20 || size < ihl + 8 || size > ip.len() {
            return Err("truncated IPv4 packet".into());
        }
        if u16::from_be_bytes(ip[6..8].try_into()?) & 0x3fff != 0 {
            return Err("reassemble IP fragments first".into());
        }
        let udp = &ip[ihl..size];
        let src = u16::from_be_bytes(udp[..2].try_into()?);
        let dst = u16::from_be_bytes(udp[2..4].try_into()?);
        if src != port && dst != port {
            continue;
        }
        let size = usize::from(u16::from_be_bytes(udp[4..6].try_into()?));
        if size < 8 || size > udp.len() {
            return Err("truncated UDP payload".into());
        }
        let server = src == port;
        let key = (
            if server {
                ip[16..20].try_into()?
            } else {
                ip[12..16].try_into()?
            },
            if server { dst } else { src },
        );
        let data = &udp[8..size];
        let direction = if server {
            Direction::ServerToClient
        } else {
            Direction::ClientToServer
        };
        let (header, frames) = wire::decode(direction, data)?;
        if wire::encode(direction, header, &frames)? != data {
            return Err("datagram re-encode differs".into());
        }
        let flow = flows.entry(key).or_insert_with(Flow::new);
        let endpoint = if server {
            &mut flow.client
        } else {
            &mut flow.server
        };
        for message in endpoint.receive(data, now)? {
            flow.observe(server, message.opcode, &message.body, now)?;
            if events {
                let b = &message.body;
                let detail = match (server, message.opcode) {
                    (true, 0x52) | (false, 0x43) => Some(format!(
                        "reference={} game={}",
                        u32_at(b, 0)?,
                        u32_at(b, 4)?
                    )),
                    (true, 0x53) => Some(format!("state_time={}", u32_at(b, 0)?)),
                    (false, 0x45) => Some(format!(
                        "input_time={} actions={:08x}",
                        u32_at(b, 12)?,
                        u32_at(b, 8)?
                    )),
                    (true, 0x54) => Some(format!(
                        "source={} input_time={} actions={:08x}",
                        b[0],
                        u32_at(b, 13)?,
                        u32_at(b, 9)?
                    )),
                    (true, 0x56 | 0x57) => {
                        Some(format!("member={} event_time={}", b[0], u32_at(b, 1)?))
                    }
                    _ => None,
                };
                if let Some(detail) = detail {
                    println!(
                        "event elapsed_ms={now} port={} slot={:?} from={} opcode={:02x} {detail}",
                        key.1,
                        flow.slot,
                        if server { "server" } else { "client" },
                        message.opcode
                    );
                }
            }
        }
        datagrams += 1;
        bytes += data.len();
    }
    println!(
        "verified_datagrams={datagrams} udp_payload_bytes={bytes} flows={}",
        flows.len()
    );
    for ((_, port), flow) in &flows {
        if let Some((time, stats)) = &flow.last_stats {
            println!(
                "last_uploaded_statistics port={port} time={time} team_points={:?}",
                stats.team_points
            );
            for (slot, player) in stats.players.iter().enumerate() {
                let nonzero: Vec<_> = player
                    .events
                    .iter()
                    .enumerate()
                    .filter(|(_, n)| **n != 0)
                    .collect();
                println!(
                    "  player={slot} nonzero_events={nonzero:?} current_killstreak={}",
                    player.current_killstreak
                );
            }
        }
        println!(
            "port={port} slot={:?} resets={:?} states={:?}",
            flow.slot, flow.resets, flow.states
        );
        println!(
            "  membership={:?} crc_samples={} revised_crc_reports={} inputs={} relays={}",
            flow.membership,
            flow.crc.len(),
            flow.crc_revisions,
            flow.inputs.len(),
            flow.relays.len()
        );
        let actions: BTreeSet<_> = flow.inputs.iter().map(|b| u32_at(b, 8).unwrap()).collect();
        println!("  input_action_masks={actions:08x?}");
        for &(time, crc, mask, size) in &flow.uploaded_states {
            println!(
                "  upload time={time} crc={crc:08x} mask={mask:x} bytes={size} matches_last_same_time_report={:?}",
                flow.crc.get(&time).map(|reported| *reported == crc)
            );
        }
        for ((server, opcode), count) in &flow.counts {
            println!(
                "  {} {opcode:02x}={count}",
                if *server { "server" } else { "client" }
            );
        }
    }
    let flow_list: Vec<_> = flows.values().collect();
    for (index, &a) in flow_list.iter().enumerate() {
        for &b in &flow_list[index + 1..] {
            // --single-match allows different per-peer restore histories.
            // CRC maps contain only samples since each flow's last reset;
            // compare pre-recovery checkpoints separately. CRC is not physics validation.
            if a.resets.is_empty()
                || b.resets.is_empty()
                || (!single_match
                    && (a.resets.len() != 1
                        || b.resets.len() != 1
                        || a.resets != b.resets
                        || a.states.first() != b.states.first()))
            {
                println!("comparison skipped: different/multiple reset or baseline histories");
                continue;
            }
            let mut matches = Vec::new();
            let mut mismatches = Vec::new();
            let mut excluded = 0;
            for (&time, &crc) in &a.crc {
                let Some(other) = b.crc.get(&time) else {
                    continue;
                };
                if a.mask(time) == 0 || a.mask(time) != b.mask(time) {
                    excluded += 1;
                    continue;
                }
                if crc == *other {
                    matches.push(time);
                } else {
                    mismatches.push(time);
                }
            }
            println!(
                "compare_slots={:?},{:?} matched={} mismatched={} excluded_membership={} first_match={:?} last_match={:?}",
                a.slot,
                b.slot,
                matches.len(),
                mismatches.len(),
                excluded,
                matches.first(),
                matches.last()
            );
            println!(
                "  first_mismatch={:?} last_mismatch={:?}",
                mismatches.first(),
                mismatches.last()
            );
            for (sender, receiver) in [(a, b), (b, a)] {
                let slot = sender.slot.ok_or("missing setup/local slot")?;
                let receiver_slot = receiver.slot.ok_or("missing receiver slot")?;
                // A disconnected receiver cannot record its own leave event.
                // Use the surviving flow's copy of that shared event too.
                let departure = sender
                    .membership
                    .union(&receiver.membership)
                    .filter(|&&(_, player, entered)| player == receiver_slot && !entered)
                    .map(|&(time, _, _)| time)
                    .min();
                let mut missing = 0;
                let mut after_departure = 0;
                let mut in_baseline = 0;
                for input in &sender.inputs {
                    if receiver
                        .states
                        .last()
                        .is_some_and(|(t, _)| u32_at(input, 12).unwrap() <= *t)
                    {
                        in_baseline += 1;
                        continue;
                    }
                    if departure.is_some_and(|left| u32_at(input, 12).unwrap() >= left) {
                        after_departure += 1;
                        continue;
                    }
                    let body = [vec![slot], input.clone()].concat();
                    if !receiver.relays.contains(&body) {
                        missing += 1;
                    }
                }
                println!(
                    "  source_slot={slot} inputs_without_captured_relay={missing} excluded_after_receiver_departure={after_departure} excluded_in_baseline={in_baseline}"
                );
            }
        }
    }
    Ok(())
}
