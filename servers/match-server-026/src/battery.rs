// SPDX-License-Identifier: GPL-3.0-or-later
//! Conservative completion from verified battery checkpoints. The native
//! event-time deadline is not serialized; wait three seconds from observation.
use crate::{results, state, statistics, timelimit};

fn winner(points: [u16; 2], total: u8, native_winner: u8) -> Option<u8> {
    (0..2).find(|&team| {
        native_winner == team
            && points[usize::from(team)] == u16::from(total)
            && points[usize::from(1 - team)] < u16::from(total)
    })
}

pub fn winning_team(
    bytes: &[u8],
    time: u32,
    roster: u8,
    map: u8,
) -> Result<Option<u8>, &'static str> {
    let total = results::victory_items(map).ok_or("unsupported battery map")?;
    let layout = state::inspect(bytes, roster)?;
    timelimit::Limits::for_map(map)
        .ok_or("missing timer identity")?
        .completed(bytes, time, roster)?;
    // Waiting/countdown states cannot satisfy the active match objective.
    if bytes[layout.blocks[4].start + 12] != 3 {
        return Ok(None);
    }
    let stats = statistics::inspect(bytes, roster, total)?;
    Ok(winner(stats.team_points, total, stats.winner_team))
}

#[derive(Clone, Copy, Debug)]
struct Candidate {
    team: u8,
    first: u32,
    last: u32,
    crc: u32,
}

#[derive(Default, Debug)]
pub struct Completion {
    candidate: Option<Candidate>,
}
impl Completion {
    pub fn pending(&self) -> bool {
        self.candidate.is_some()
    }
    pub fn invalidate(&mut self) {
        self.candidate = None;
    }

    /// Caller establishes CRC provenance, freshness, membership and identity.
    /// Repeated polling of one checkpoint never advances the confirmation clock.
    pub fn observe(&mut self, time: u32, crc: u32, team: Option<u8>) -> bool {
        let Some(team) = team else {
            self.invalidate();
            return false;
        };
        let first = self
            .candidate
            .filter(|old| {
                old.team == team
                    && time >= old.last
                    && time - old.last <= 6000
                    && (time != old.last || crc == old.crc)
            })
            .map_or(time, |old| old.first);
        self.candidate = Some(Candidate {
            team,
            first,
            last: time,
            crc,
        });
        time - first >= 3000
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn threshold_matches_native_battery_events() {
        let mut count = 0;
        for line in include_str!("../fixtures/026g-battery.tsv")
            .lines()
            .filter(|line| !line.starts_with('#') && !line.is_empty())
        {
            let f: Vec<u32> = line.split('\t').map(|x| x.parse().unwrap()).collect();
            if f[6] != u32::MAX {
                continue;
            }
            let team = winner([f[10] as u16, f[11] as u16], f[5] as u8, f[12] as u8);
            assert_eq!(team.is_some(), f[13] != u32::MAX);
            if team.is_some() {
                assert_eq!(f[13], f[4] + 3000);
            }
            count += 1;
        }
        assert_eq!(count, 72);
    }

    #[test]
    fn confirmation_requires_new_consistent_history() {
        for team in [0, 1] {
            let mut completion = Completion::default();
            assert!(!completion.observe(10000, 1, Some(team)));
            for _ in 0..10 {
                assert!(!completion.observe(10000, 1, Some(team)));
            }
            assert!(!completion.observe(12999, 2, Some(team)));
            assert!(completion.observe(13000, 3, Some(team)));
            completion.invalidate();
            assert!(!completion.pending());
            assert!(!completion.observe(14000, 4, Some(team)));
            assert!(!completion.observe(14000, 5, Some(team))); // revised same-time state
            assert!(!completion.observe(13000, 6, Some(team))); // backwards history
            assert!(!completion.observe(19001, 7, Some(team))); // evidence gap
            assert!(!completion.observe(22001, 8, Some(1 - team))); // different winner
            assert!(!completion.observe(23000, 9, None)); // objective lost or invalid
            assert!(!completion.observe(26000, 10, Some(team)));
        }
    }
}
