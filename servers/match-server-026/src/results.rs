// SPDX-License-Identifier: GPL-3.0-or-later
//! SRP F8 v1 results, derived from a coordinator-verified final checkpoint.
//! Fixed 24-byte header and 80-byte roster rows; no account rewards are granted.
use crate::{state, statistics};
use survarium::protocol_026::match_options::MatchOptions;

pub fn victory_items(map: u8) -> Option<u8> {
    include_str!("../fixtures/026g-result-modes.tsv")
        .lines()
        .filter(|line| !line.starts_with('#'))
        .find_map(|line| {
            let mut fields = line.split('\t');
            if fields.next()?.parse::<u8>().ok()? != map {
                return None;
            }
            if fields.next()? != "2" {
                return None;
            }
            fields.next()?.parse().ok()
        })
}

/// Native recalculate_scores (0x26dc30), including u16 preset-sum wrapping.
pub fn score(events: &[[u16; 3]; 28], weights: &[f32; 28]) -> Result<i16, &'static str> {
    if weights.iter().any(|weight| !weight.is_finite()) {
        return Err("non-finite event score weight");
    }
    let mut total = 0f32;
    for (event, presets) in events.iter().enumerate() {
        let count = presets.iter().copied().fold(0u16, u16::wrapping_add);
        let factor = if matches!(event, 6 | 17 | 18) {
            0.01f32
        } else {
            1.
        };
        total += f32::from(count) * weights[event] * factor;
    }
    if !total.is_finite() || total.abs() >= i32::MAX as f32 {
        return Err("score exceeds native integer range");
    }
    Ok((total + 0.5).floor() as i32 as i16)
}

pub fn encode(
    options: &MatchOptions,
    bytes: &[u8],
    time: u32,
    local_slot: u8,
    participants: u32,
) -> Result<Vec<u8>, &'static str> {
    let roster = u8::try_from(options.players.len()).map_err(|_| "invalid roster")?;
    let items = victory_items(options.map_id).ok_or("unverified result mode")?;
    let layout = state::inspect(bytes, roster)?;
    crate::timelimit::Limits::for_map(options.map_id)
        .ok_or("missing timer identity")?
        .completed(bytes, time, roster)?;
    let stats = statistics::inspect(bytes, roster, items)?;
    if participants >> roster != 0 || participants & layout.mask != layout.mask {
        return Err("invalid result participant mask");
    }
    let local = options
        .players
        .get(usize::from(local_slot))
        .ok_or("invalid local slot")?;
    if local.team > 1 || layout.mask & (1 << local_slot) == 0 {
        return Err("results require an active team player");
    }
    let winner = match stats.team_points[0].cmp(&stats.team_points[1]) {
        std::cmp::Ordering::Greater => 0,
        std::cmp::Ordering::Less => 1,
        std::cmp::Ordering::Equal => 2,
    };
    if stats.winner_team != winner && !(winner == 2 && stats.winner_team == 3) {
        return Err("battery winner disagrees with team scores");
    }
    let mut out = vec![1, (time / 50) as u8, local_slot, 2];
    out.extend(time.to_le_bytes());
    out.extend(options.match_id.to_le_bytes());
    out.extend(participants.to_le_bytes());
    for value in stats.team_points {
        out.extend(value.to_le_bytes());
    }
    out.extend([winner, roster, local.team, 0]);
    for (player, counters) in options.players.iter().zip(&stats.players) {
        if player.team > 1 || player.name.len() > 63 || player.name.contains('\0') {
            return Err("invalid result player identity");
        }
        let mut row = [0u8; 80];
        row[..4].copy_from_slice(&player.key.to_le_bytes());
        row[4] = player.team;
        // This direct-match path has no account profile. Match level is not
        // the player's rank; leave the row unranked rather than inventing one.
        for (offset, event) in [(8, 0), (10, 2)] {
            let value = counters.events[event]
                .iter()
                .copied()
                .fold(0u16, u16::wrapping_add);
            row[offset..offset + 2].copy_from_slice(&value.to_le_bytes());
        }
        row[12..14].copy_from_slice(&score(&counters.events, &options.event_scores)?.to_le_bytes());
        row[14] = player.name.len() as u8;
        row[16..16 + player.name.len()].copy_from_slice(player.name.as_bytes());
        out.extend(row);
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn recomputed_scores_match_native_oracle() {
        let mut count = 0;
        for line in include_str!("../fixtures/026g-scores.tsv")
            .lines()
            .filter(|line| !line.starts_with('#') && !line.is_empty())
        {
            let (hex, expected) = line.split_once('\t').unwrap();
            let bytes: Vec<_> = hex
                .as_bytes()
                .chunks_exact(2)
                .map(|b| u8::from_str_radix(std::str::from_utf8(b).unwrap(), 16).unwrap())
                .collect();
            let events = std::array::from_fn(|e| {
                std::array::from_fn(|p| {
                    let offset = e * 6 + p * 2;
                    u16::from_le_bytes(bytes[offset..offset + 2].try_into().unwrap())
                })
            });
            let weights = std::array::from_fn(|e| {
                f32::from_le_bytes(bytes[168 + e * 4..172 + e * 4].try_into().unwrap())
            });
            assert_eq!(score(&events, &weights), Ok(expected.parse().unwrap()));
            count += 1;
        }
        assert_eq!(count, 172);
    }
}
