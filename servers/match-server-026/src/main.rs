// SPDX-License-Identifier: GPL-3.0-or-later
mod clock;
mod history;
mod recovery;
mod replay;
mod server;
use match_server_026::snapshot;

use server::Server;
use std::{
    fs::File,
    io::Write,
    net::UdpSocket,
    time::{Duration, Instant},
};

fn record(
    log: &mut Option<File>,
    now: u64,
    direction: &str,
    peer: std::net::SocketAddr,
    data: &[u8],
) -> std::io::Result<()> {
    if let Some(log) = log {
        write!(log, "{now}\t{direction}\t{peer}\t")?;
        for byte in data {
            write!(log, "{byte:02x}")?;
        }
        writeln!(log)?;
    }
    Ok(())
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut bind = "127.0.0.1:2236".to_string();
    let mut players = 2;
    let mut start_players = None;
    let mut map = 61;
    let mut packet_log = None;
    let mut snapshots = false;
    let mut checkpoints = false;
    let mut restore_once_after_ms = None;
    let mut recover = false;
    let mut clock_sync = false;
    let mut clock_fault = None;
    let mut drop_relay = None;
    let mut finish_after_ms = None;
    let mut finish_timed = false;
    let mut finish_objective = false;
    let mut results = false;
    let mut score_weights = None;
    let mut roster = None;
    let mut args = std::env::args().skip(1);
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--roster" => {
                let path = args.next().ok_or("--roster needs a file")?;
                roster = Some(match_server_026::roster::parse(&std::fs::read_to_string(
                    path,
                )?)?);
            }
            "--score-weights" => {
                let path = args.next().ok_or("--score-weights needs a file")?;
                score_weights = Some(match_server_026::scoring::parse(&std::fs::read_to_string(
                    path,
                )?)?);
            }
            "--results" => results = true,
            "--finish-timed" => finish_timed = true,
            "--finish-objective" => finish_objective = true,
            "--finish-after-ms" => {
                let time: u32 = args
                    .next()
                    .ok_or("--finish-after-ms needs a game timestamp")?
                    .parse()?;
                if time == 0 {
                    return Err("finish timestamp must be nonzero".into());
                }
                finish_after_ms = Some(time);
            }
            "--snapshots" => snapshots = true,
            "--checkpoints" => checkpoints = true,
            "--recover" => recover = true,
            "--clock-sync" => clock_sync = true,
            "--clock-fault" => {
                let spec = args
                    .next()
                    .ok_or("--clock-fault needs SLOT:GAME_MS:OFFSET_MS")?;
                let parts: Vec<_> = spec.split(':').collect();
                if parts.len() != 3 {
                    return Err("--clock-fault needs SLOT:GAME_MS:OFFSET_MS".into());
                }
                let slot: u8 = parts[0].parse()?;
                let at: u32 = parts[1].parse()?;
                let offset: i16 = parts[2].parse()?;
                if offset == 0 || offset.unsigned_abs() > 1000 {
                    return Err("clock fault offset must be nonzero and within +/-1000 ms".into());
                }
                clock_fault = Some((slot, at, offset));
            }
            "--drop-relay" => {
                let spec = args.next().ok_or("--drop-relay needs SLOT:FROM_MS:TO_MS")?;
                let parts: Vec<_> = spec
                    .split(':')
                    .map(str::parse::<u32>)
                    .collect::<Result<_, _>>()?;
                if parts.len() != 3 || parts[0] >= 20 || parts[1] >= parts[2] {
                    return Err("--drop-relay needs SLOT:FROM_MS:TO_MS with FROM < TO".into());
                }
                drop_relay = Some((parts[0] as u8, parts[1], parts[2]));
            }
            "--restore-once-after-ms" => {
                restore_once_after_ms = Some(
                    args.next()
                        .ok_or("--restore-once-after-ms needs a game timestamp")?
                        .parse()?,
                )
            }
            "--bind" => bind = args.next().ok_or("--bind needs an address")?,
            "--players" => players = args.next().ok_or("--players needs a count")?.parse()?,
            "--start-players" => {
                start_players = Some(
                    args.next()
                        .ok_or("--start-players needs a count")?
                        .parse::<u8>()?,
                )
            }
            "--map" => map = args.next().ok_or("--map needs a dictionary ID")?.parse()?,
            "--packet-log" => {
                packet_log = Some(File::create(
                    args.next().ok_or("--packet-log needs a path")?,
                )?)
            }
            "--help" => {
                println!(
                    "  --roster FILE: fixed local identities; rows SESSION_HEX TEAM SQUAD NAME, one per player"
                );
                println!(
                    "  --score-weights FILE: 28 finite event weights; whitespace and # comments allowed (default: development preset)"
                );
                println!(
                    "  --finish-objective: confirm battery victory across verified checkpoints; requires --checkpoints"
                );
                println!(
                    "  --results: F8 native results for battery maps; requires --checkpoints, a finish policy and the results-capable client"
                );
                println!(
                    "  --finish-timed: evaluate the native timer from verified checkpoints (requires --checkpoints)"
                );
                println!(
                    "match-server-026 [--bind 127.0.0.1:2236] [--players 2] [--start-players COUNT] [--map 61] [--packet-log path] [--snapshots] [--checkpoints] [--recover] [--clock-sync] [--clock-fault SLOT:GAME_MS:OFFSET_MS] [--restore-once-after-ms game_time] [--drop-relay SLOT:FROM_MS:TO_MS]"
                );
                println!(
                    "  --finish-after-ms TIME: diagnostic forced finish; does not evaluate victory rules"
                );
                return Ok(());
            }
            _ => return Err(format!("unknown argument {arg}").into()),
        }
    }
    if checkpoints && !snapshots {
        return Err("--checkpoints requires --snapshots and the F7-capable client patch".into());
    }
    if results
        && (!checkpoints
            || (!finish_timed && !finish_objective && finish_after_ms.is_none())
            || match_server_026::results::victory_items(map).is_none())
    {
        return Err(
            "--results requires checkpoints, a finish policy and a supported battery map".into(),
        );
    }
    if finish_objective
        && (!checkpoints
            || finish_after_ms.is_some()
            || match_server_026::results::victory_items(map).is_none()
            || match_server_026::timelimit::Limits::for_map(map).is_none())
    {
        return Err("--finish-objective requires checkpoints and a supported battery map; cannot combine with --finish-after-ms".into());
    }
    if finish_timed
        && (!checkpoints
            || finish_after_ms.is_some()
            || match_server_026::timelimit::Limits::for_map(map).is_none())
    {
        return Err("--finish-timed requires --checkpoints and a known native map timer; cannot combine with --finish-after-ms".into());
    }
    if restore_once_after_ms.is_some() && !checkpoints {
        return Err("--restore-once-after-ms requires --checkpoints".into());
    }
    if recover && !checkpoints {
        return Err("--recover requires --checkpoints".into());
    }
    if drop_relay.is_some_and(|(slot, _, _)| slot >= players) {
        return Err("--drop-relay slot is outside the roster".into());
    }
    let start_players = start_players.unwrap_or(players);
    if start_players == 0 || start_players > players || (start_players < players && !checkpoints) {
        return Err(
            "--start-players must be 1..=players; a partial roster requires --checkpoints".into(),
        );
    }
    if clock_fault.is_some_and(|(slot, _, _)| slot >= players)
        || (clock_fault.is_some() && !clock_sync)
    {
        return Err("--clock-fault requires --clock-sync and a roster slot".into());
    }
    if roster
        .as_ref()
        .is_some_and(|members| members.len() != usize::from(players))
    {
        return Err("roster member count must equal --players".into());
    }
    let socket = UdpSocket::bind(&bind)?;
    socket.set_read_timeout(Some(Duration::from_millis(10)))?;
    let mut server = Server::new(socket.local_addr()?.port(), players, map)?;
    if let Some(members) = roster {
        server.set_roster(&members)?;
    }
    if let Some(weights) = score_weights {
        server.set_score_weights(weights)?;
    }
    server.start_players = start_players;
    server.snapshots = snapshots;
    server.checkpoints = checkpoints;
    server.restore_once_after_ms = restore_once_after_ms;
    server.recover = recover;
    server.clock_sync = clock_sync;
    server.clock_fault = clock_fault;
    server.drop_relay = drop_relay;
    server.finish_after_ms = finish_after_ms;
    server.finish_timed = finish_timed;
    server.finish_objective = finish_objective;
    server.results = results;
    eprintln!(
        "0.26g0 match endpoint: {} ({players} players, map {map})",
        socket.local_addr()?
    );
    eprintln!(
        "Development endpoint: fixed roster; account authentication and persistence are not implemented."
    );
    let start = Instant::now();
    let mut packet = [0; 513];
    loop {
        match socket.recv_from(&mut packet) {
            Ok((n, peer)) => {
                // Timestamp receipt after the blocking read, not before it.
                let now = start.elapsed().as_millis() as u64;
                record(&mut packet_log, now, "in", peer, &packet[..n])?;
                match server.receive(peer, &packet[..n], now) {
                    Ok(outbound) => {
                        for (destination, data) in outbound {
                            socket.send_to(&data, destination)?;
                            record(&mut packet_log, now, "out", destination, &data)?;
                        }
                    }
                    Err(error) => eprintln!("Rejected packet from {peer}: {error}"),
                }
            }
            Err(error)
                if matches!(
                    error.kind(),
                    std::io::ErrorKind::WouldBlock | std::io::ErrorKind::TimedOut
                ) => {}
            Err(error) => return Err(error.into()),
        }
        for (destination, data) in server.poll(start.elapsed().as_millis() as u64)? {
            socket.send_to(&data, destination)?;
            record(
                &mut packet_log,
                start.elapsed().as_millis() as u64,
                "out",
                destination,
                &data,
            )?;
        }
    }
}
