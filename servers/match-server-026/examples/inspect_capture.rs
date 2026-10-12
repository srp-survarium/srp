// SPDX-License-Identifier: GPL-3.0-or-later
//! Inspect one match's --packet-log capture using the production wire codecs.
//! Eight-bit hash times are expanded to the nearest tick of the initial E5
//! wall/game clock anchor. This assumes reports arrive within 6.4 seconds of
//! their state time; it is evidence for local testing, not recovery policy.
use match_server_026::snapshot::Upload;
use std::{
    collections::{BTreeMap, BTreeSet},
    env, fs,
    net::SocketAddr,
};
use survarium::protocol_026::{Direction, decode_frames};
use vostok::network_packet::udp_026::Header;

type Error = Box<dyn std::error::Error>;

fn main() -> Result<(), Error> {
    let mut args = env::args().skip(1);
    let path = args
        .next()
        .ok_or("usage: inspect_capture PACKETS.tsv [PLAYERS] [SNAPSHOT_DIR]")?;
    let players = args.next().unwrap_or_else(|| "2".into()).parse()?;
    let snapshot_dir = args.next().map(std::path::PathBuf::from);
    if let Some(dir) = &snapshot_dir {
        fs::create_dir_all(dir)?;
    }
    let input = fs::read_to_string(path)?;
    let mut anchors = BTreeMap::<SocketAddr, (u8, u64, u32)>::new();
    let mut counts = BTreeMap::<SocketAddr, BTreeMap<u8, usize>>::new();
    let mut hashes = BTreeMap::<i64, BTreeMap<SocketAddr, u32>>::new();
    let mut membership = BTreeSet::new();
    let mut packets = 0usize;
    let mut uploads = BTreeMap::<(SocketAddr, u32), Option<Upload>>::new();
    let mut last_hash = BTreeMap::<SocketAddr, (u8, u32)>::new();
    let mut requested_hashes = BTreeMap::<(SocketAddr, u32), u32>::new();
    let mut result_parts = BTreeMap::<SocketAddr, (Option<u8>, BTreeMap<u8, Vec<u8>>)>::new();
    for (line_number, line) in input.lines().enumerate() {
        let fields: Vec<_> = line.split('\t').collect();
        if fields.len() != 4 || fields[3].len() % 2 != 0 {
            return Err(format!("invalid capture row {}", line_number + 1).into());
        }
        let now: u64 = fields[0].parse()?;
        let peer: SocketAddr = fields[2].parse()?;
        let direction = match fields[1] {
            "in" => Direction::ClientSnapshots,
            "out" => Direction::ServerSnapshots,
            _ => return Err("invalid capture direction".into()),
        };
        let bytes: Vec<u8> = fields[3]
            .as_bytes()
            .chunks_exact(2)
            .map(|pair| u8::from_str_radix(std::str::from_utf8(pair)?, 16).map_err(Error::from))
            .collect::<Result<_, Error>>()?;
        let (header, payload) = Header::decode(&bytes)?;
        let frames = decode_frames(payload, header.single_message, direction, players)?;
        packets += 1;
        for frame in frames {
            if matches!(frame.id, 0xdb | 0xe6 | 0xe7) {
                let fields: Vec<_> = frame
                    .body
                    .chunks_exact(2)
                    .map(|b| u16::from_le_bytes([b[0], b[1]]))
                    .collect();
                let game = anchors
                    .get(&peer)
                    .map(|(_, wall, game)| u64::from(*game) + now.saturating_sub(*wall));
                println!(
                    "Timing wall {now}, game {game:?}, {peer}, {:02x}: {fields:?}",
                    frame.id
                );
            }
            if direction == Direction::ServerSnapshots {
                if frame.id == 0xf8 {
                    let (count, parts) = result_parts.entry(peer).or_default();
                    let (index, incoming_count) =
                        frame.fragment.map_or((0, Some(1)), |f| (f.index, f.count));
                    if index >= 4 || incoming_count.is_some_and(|n| n == 0 || n > 4) {
                        return Err("invalid F8 fragment count".into());
                    }
                    if let Some(n) = incoming_count {
                        if count.is_some_and(|old| old != n) {
                            return Err("conflicting F8 fragment count".into());
                        }
                        *count = Some(n);
                    }
                    if parts.get(&index).is_some_and(|old| old != frame.body) {
                        return Err("conflicting F8 fragment body".into());
                    }
                    parts.insert(index, frame.body.to_vec());
                }
                if frame.id == 0xf7 {
                    let time = u32::from_le_bytes(frame.body.try_into()?);
                    if let Some((tick, crc)) = last_hash.get(&peer) {
                        if *tick == (time / 50) as u8 {
                            requested_hashes.entry((peer, time)).or_insert(*crc);
                        }
                    }
                }
                if frame.id == 0xe5 {
                    let game = u32::from_le_bytes(frame.body[3..7].try_into()?);
                    let initial = anchors.entry(peer).or_insert((frame.body[0], now, game));
                    if initial.0 != frame.body[0] || initial.2 != game {
                        return Err(
                            "capture contains another clock reset; inspect matches separately"
                                .into(),
                        );
                    }
                }
                if matches!(frame.id, 0xe9 | 0xea) {
                    if let Some((_, wall, game)) = anchors.get(&peer) {
                        let reference = (u64::from(*game) + now.saturating_sub(*wall)) / 50;
                        let delta = frame.body[0].wrapping_sub(reference as u8) as i8;
                        let time = (i64::try_from(reference)? + i64::from(delta)) * 50;
                        membership.insert((time, peer, frame.id, frame.body[1]));
                    }
                }
                continue;
            }
            *counts.entry(peer).or_default().entry(frame.id).or_default() += 1;
            if frame.id == 0xe2 {
                let time = u32::from_le_bytes(frame.body[..4].try_into()?);
                if uploads.len() >= 1024 && !uploads.contains_key(&(peer, time)) {
                    return Err("capture exceeds 1024 snapshot transfers".into());
                }
                Upload::receive(uploads.entry((peer, time)).or_default(), frame.body)?;
            }
            if frame.id != 0xdf {
                continue;
            }
            let (_, wall, game) = anchors.get(&peer).ok_or("hash before initial clock")?;
            let reference = (u64::from(*game) + now.saturating_sub(*wall)) / 50;
            let delta = frame.body[0].wrapping_sub(reference as u8) as i8;
            let tick = i64::try_from(reference)? + i64::from(delta);
            let crc = u32::from_le_bytes(frame.body[1..].try_into()?);
            last_hash.insert(peer, (frame.body[0], crc));
            // Late inputs can revise history; retain the latest observation.
            hashes.entry(tick).or_default().insert(peer, crc);
        }
    }
    println!("Decoded {packets} datagrams using the 0.26 codecs.");
    for (peer, (count, parts)) in result_parts {
        let count = count.ok_or("F8 missing fragment zero")?;
        if parts.len() != usize::from(count) {
            return Err("incomplete F8 results".into());
        }
        let mut body = Vec::new();
        for index in 0..count {
            body.extend(parts.get(&index).ok_or("missing F8 fragment")?);
        }
        if body.len() < 24
            || body[0] != 1
            || body[21] == 0
            || body[21] > 20
            || body.len() != 24 + usize::from(body[21]) * 80
        {
            return Err("invalid F8 result layout".into());
        }
        let time = u32::from_le_bytes(body[4..8].try_into()?);
        let mask = u32::from_le_bytes(body[12..16].try_into()?);
        println!(
            "{peer}: F8 results at {time} ms, local slot {}, participants {mask:08x}, scores {}:{}, winner {}",
            body[2],
            u16::from_le_bytes(body[16..18].try_into()?),
            u16::from_le_bytes(body[18..20].try_into()?),
            body[20]
        );
        for (slot, row) in body[24..].chunks_exact(80).enumerate() {
            if mask & (1 << slot) == 0 {
                continue;
            }
            let len = usize::from(row[14]);
            if len > 63 || row[16 + len] != 0 {
                return Err("invalid F8 name".into());
            }
            println!(
                "  slot {slot}: {}, team {}, rank {}, kills {}, deaths {}, score {}",
                std::str::from_utf8(&row[16..16 + len])?,
                row[4],
                u16::from_le_bytes(row[6..8].try_into()?),
                u16::from_le_bytes(row[8..10].try_into()?),
                u16::from_le_bytes(row[10..12].try_into()?),
                i16::from_le_bytes(row[12..14].try_into()?)
            );
        }
        if let Some(dir) = &snapshot_dir {
            fs::write(
                dir.join(format!("results-{}.f8", peer.to_string().replace(':', "_"))),
                body,
            )?;
        }
    }
    for (peer, count) in counts {
        println!(
            "{peer}: {} hashes, {} inputs, {} snapshot chunks",
            count.get(&0xdf).unwrap_or(&0),
            count.get(&0xdc).unwrap_or(&0) + count.get(&0xdd).unwrap_or(&0),
            count.get(&0xe2).unwrap_or(&0)
        );
    }
    for (time, peer, opcode, slot) in membership {
        println!(
            "{peer}: {} slot {slot} at {time} ms",
            if opcode == 0xe9 { "enter" } else { "leave" }
        );
    }
    let mut pairs = BTreeMap::<(SocketAddr, SocketAddr), (usize, usize, i64, i64)>::new();
    let (mut matched, mut mismatched) = (0, 0);
    for (tick, observations) in hashes.iter().filter(|(_, peers)| peers.len() >= 2) {
        let peers: Vec<_> = observations.iter().collect();
        for (index, (first, first_crc)) in peers.iter().enumerate() {
            for (second, second_crc) in &peers[index + 1..] {
                let stats =
                    pairs
                        .entry((**first, **second))
                        .or_insert((0, 0, tick * 50, tick * 50));
                if first_crc == second_crc {
                    stats.0 += 1;
                } else {
                    stats.1 += 1;
                }
                stats.3 = tick * 50;
            }
        }
        let same = observations
            .values()
            .all(|crc| Some(crc) == observations.values().next());
        if same {
            matched += 1;
        } else {
            mismatched += 1;
        }
        println!(
            "tick {tick}: {} {observations:x?}",
            if same { "match" } else { "MISMATCH" }
        );
    }
    println!("Shared historical ticks: {matched} matching, {mismatched} mismatching.");
    for ((first, second), (matched, mismatched, start, end)) in pairs {
        println!(
            "Pair {first}/{second}: {matched} matching, {mismatched} mismatching, {start}..{end} ms."
        );
    }
    for ((peer, time), upload) in uploads {
        let upload = upload.unwrap();
        if !upload.complete() {
            println!("{peer} snapshot at {time} ms: incomplete");
            continue;
        }
        let crc = crc32fast::hash(&upload.bytes);
        let expected = requested_hashes.get(&(peer, time));
        println!(
            "{peer} snapshot at {time} ms: {} bytes, active mask {:08x}, CRC {crc:08x}, {}",
            upload.bytes.len(),
            u32::from_le_bytes(upload.bytes[..4].try_into()?),
            match expected {
                Some(value) if *value == crc => "matches requested historical hash",
                Some(_) => "HASH MISMATCH",
                None => "no requested hash",
            }
        );
        let layout = match_server_026::state::inspect(&upload.bytes, players)?;
        println!(
            "  world block lengths {:?}; rules prefix {:02x?}",
            layout.blocks.each_ref().map(|range| range.len()),
            &upload.bytes[layout.blocks[4].clone()][..layout.blocks[4].len().min(32)]
        );
        if let Some(dir) = &snapshot_dir {
            fs::write(
                dir.join(format!("{}-{time}.bin", peer.to_string().replace(':', "_"))),
                &upload.bytes,
            )?;
        }
    }
    println!(
        "Assumption: hash reports are within 6.4 seconds of the initial E5 clock. Sparse overlap does not verify continuous synchronization."
    );
    Ok(())
}
