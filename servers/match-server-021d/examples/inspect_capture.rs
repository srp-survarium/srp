// SPDX-License-Identifier: GPL-3.0-or-later
//! Read-only verification against the original local SLL2/IPv4 capture.
//! cargo run -p match-server-021d --example inspect_capture -- CAPTURE.pcap

use match_server_021d::snapshot::Assembler;
use match_server_021d::transport::Endpoint;
use match_server_021d::wire::{self, Direction};
use std::{collections::BTreeMap, error::Error, fs::File, io::Read};

fn main() -> Result<(), Box<dyn Error>> {
    let path = std::env::args_os()
        .nth(1)
        .ok_or("provide a classic SLL2 pcap path")?;
    let mut input = File::open(path)?;
    let mut global = [0; 24];
    input.read_exact(&mut global)?;
    if global[..4] != [0xd4, 0xc3, 0xb2, 0xa1]
        || u32::from_le_bytes(global[20..24].try_into()?) != 276
    {
        return Err("expected little-endian microsecond pcap with SLL2 link type 276".into());
    }
    let mut datagrams = 0usize;
    let mut counts = BTreeMap::new();
    let mut delivered = BTreeMap::new();
    let mut client = Endpoint::new(Direction::ClientToServer);
    let mut server = Endpoint::new(Direction::ServerToClient);
    let mut first_time = None;
    let mut uploads = Assembler::default();
    let mut snapshot_crcs = Vec::new();
    let mut reported_crcs = BTreeMap::new();
    let mut upload_bytes = 0;
    let mut validated_states = 0;
    loop {
        let mut record = [0; 16];
        if input.read(&mut record[..1])? == 0 {
            break;
        }
        input.read_exact(&mut record[1..])?;
        let time = u64::from(u32::from_le_bytes(record[..4].try_into()?)) * 1000
            + u64::from(u32::from_le_bytes(record[4..8].try_into()?)) / 1000;
        let now = time.saturating_sub(*first_time.get_or_insert(time));
        let size = u32::from_le_bytes(record[8..12].try_into()?) as usize;
        if size > 65535 + 20 {
            return Err("oversized capture record".into());
        }
        let mut packet = vec![0; size];
        input.read_exact(&mut packet)?;
        if packet.len() < 40 || packet[..2] != [8, 0] {
            continue;
        }
        let ip = &packet[20..];
        if ip[0] >> 4 != 4 || ip[9] != 17 {
            continue;
        }
        let ihl = usize::from(ip[0] & 15) * 4;
        let ip_size = usize::from(u16::from_be_bytes(ip[2..4].try_into()?));
        if ihl < 20 || ip_size < ihl + 8 || ip_size > ip.len() {
            return Err("truncated IPv4 packet".into());
        }
        if u16::from_be_bytes(ip[6..8].try_into()?) & 0x3fff != 0 {
            return Err("IPv4 fragments require reassembly before this inspector".into());
        }
        let udp = &ip[ihl..ip_size];
        let source = u16::from_be_bytes(udp[..2].try_into()?);
        let dest = u16::from_be_bytes(udp[2..4].try_into()?);
        if source != 1236 && dest != 1236 {
            continue;
        }
        let size = usize::from(u16::from_be_bytes(udp[4..6].try_into()?));
        if size < 8 || size > udp.len() {
            return Err("truncated UDP datagram".into());
        }
        let data = &udp[8..size];
        let direction = if source == 1236 {
            Direction::ServerToClient
        } else {
            Direction::ClientToServer
        };
        let (header, frames) = wire::decode(direction, data)?;
        if wire::encode(direction, header, &frames)? != data {
            return Err(format!("wire round-trip mismatch at match datagram {datagrams}").into());
        }
        for frame in frames {
            *counts
                .entry((source == 1236, frame.opcode()))
                .or_insert(0usize) += 1;
        }
        let receiver = if source == 1236 {
            &mut client
        } else {
            &mut server
        };
        for message in receiver.receive(data, now).map_err(|error| {
            format!("transport at match datagram {datagrams}, time {now}: {error}")
        })? {
            if source != 1236 {
                match message.opcode {
                    0x46 => {
                        if message.body.len() != 8 {
                            return Err("invalid CRC notification length".into());
                        }
                        let time = u32::from_le_bytes(message.body[..4].try_into()?);
                        let crc = u32::from_le_bytes(message.body[4..].try_into()?);
                        reported_crcs.entry(time).or_insert_with(Vec::new).push(crc);
                    }
                    0x47 => {
                        if !uploads.expire(now).is_empty() {
                            return Err("incomplete captured upload expired".into());
                        }
                        if let Some(snapshot) = uploads.push(&message.body, now)? {
                            match_server_021d::state::inspect(&snapshot.body, 20)?;
                            validated_states += 1;
                            upload_bytes += snapshot.body.len();
                            snapshot_crcs.push((snapshot.time, snapshot.crc32()));
                        }
                    }
                    _ => {}
                }
            } else if message.opcode == 0x53 {
                match_server_021d::state::inspect(
                    message.body.get(4..).ok_or("missing state timestamp")?,
                    20,
                )?;
                validated_states += 1;
            }
            *delivered
                .entry((source == 1236, message.opcode))
                .or_insert(0usize) += 1;
        }
        datagrams += 1;
    }
    println!("Decoded and byte-verified {datagrams} match UDP datagrams");
    println!("Validated {validated_states} serialized world layouts exactly to end");
    let mut matched = 0;
    for (time, crc) in &snapshot_crcs {
        if let Some(reported) = reported_crcs.get(time) {
            if !reported.contains(crc) {
                return Err(format!("snapshot CRC mismatch at {time}").into());
            }
            matched += 1;
        }
    }
    println!(
        "Reassembled {} client snapshots ({upload_bytes} bytes); {matched} have matching captured CRC notifications",
        snapshot_crcs.len()
    );
    for ((from_server, opcode), count) in counts {
        println!(
            "{} 0x{opcode:02x}: {count} frames, {} delivered messages",
            if from_server { "server" } else { "client" },
            delivered.get(&(from_server, opcode)).copied().unwrap_or(0)
        );
    }
    Ok(())
}
