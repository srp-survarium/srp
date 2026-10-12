// SPDX-License-Identifier: GPL-3.0-or-later
//! Inspect complete E2 snapshot bodies saved by inspect_capture.
use match_server_026::statistics;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut args = std::env::args().skip(1);
    let usage = "usage: inspect_statistics ROSTER VICTORY_ITEMS SNAPSHOT.bin ...";
    let roster: u8 = args.next().ok_or(usage)?.parse()?;
    let items: u8 = args.next().ok_or(usage)?.parse()?;
    let mut count = 0;
    for path in args {
        let bytes = std::fs::read(&path)?;
        let stats = statistics::inspect(&bytes, roster, items)
            .map_err(|error| format!("{path}: {error}"))?;
        println!(
            "{path}: points {:?}, batteries {:?}, native winner {}, active-in-match {:08x}",
            stats.team_points,
            stats.team_victory_items,
            stats.winner_team,
            stats.active_in_match_mask
        );
        for (slot, player) in stats.players.iter().enumerate() {
            let events: Vec<_> = player
                .events
                .iter()
                .enumerate()
                .filter(|(_, values)| **values != [0; 3])
                .collect();
            if !events.is_empty() || player.longest_killstreak != 0 {
                println!(
                    "  slot {slot}: events {events:?}, longest killstreak {}",
                    player.longest_killstreak
                );
            }
        }
        count += 1;
    }
    if count == 0 {
        return Err(usage.into());
    }
    println!("Validated {count} complete statistics blocks.");
    Ok(())
}
