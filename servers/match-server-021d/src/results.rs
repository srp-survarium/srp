// SPDX-License-Identifier: GPL-3.0-or-later
//! Read-only v0.21d shared-statistics decoding. See docs/v021d/RESULTS.txt.
//! This does not award currency, infer kills from CRCs, or rewrite world state.
use crate::state;

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct PlayerStats {
    /// PDB match_stats_events_dict_enum, indices 0..24 (24 is the count).
    pub events: [u16; 24],
    /// Current streak, NOT the maximum streak over the whole match.
    pub current_killstreak: u16,
}
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Stats {
    pub players: Vec<PlayerStats>,
    pub team_points: [u8; 2],
}
struct Reader<'a>(&'a [u8]);
impl Reader<'_> {
    fn take(&mut self, n: usize) -> Result<&[u8], &'static str> {
        let (head, tail) = self
            .0
            .split_at_checked(n)
            .ok_or("truncated match statistics")?;
        self.0 = tail;
        Ok(head)
    }
    fn byte(&mut self) -> Result<u8, &'static str> {
        Ok(self.take(1)?[0])
    }
    fn short(&mut self) -> Result<u16, &'static str> {
        Ok(u16::from_le_bytes(self.take(2)?.try_into().unwrap()))
    }
    fn word(&mut self) -> Result<u32, &'static str> {
        Ok(u32::from_le_bytes(self.take(4)?.try_into().unwrap()))
    }
    fn float(&mut self) -> Result<f32, &'static str> {
        let value = f32::from_bits(self.word()?);
        if !value.is_finite() {
            return Err("nonfinite statistics value");
        }
        Ok(value)
    }
}
impl Stats {
    /// Fixed gather-all-items rule, not an arbitrary score threshold.
    /// Native on_event 0x1fb8a9 completes when either container owns every
    /// spawned item; shared_statistics 0x1dded5 mirrors deposit/theft counts.
    /// Reject impossible totals rather than allowing byte overflow or two
    /// simultaneous winners to end a match. Zero items cannot award a win.
    pub fn objective_winner(&self, victory_items: u8) -> Option<u8> {
        if victory_items == 0
            || u16::from(self.team_points[0]) + u16::from(self.team_points[1])
                > u16::from(victory_items)
        {
            return None;
        }
        self.team_points
            .iter()
            .position(|&n| n == victory_items)
            .map(|n| n as u8)
    }

    pub fn from_world(body: &[u8], roster: u8, victory_items: u8) -> Result<Self, &'static str> {
        let layout = state::inspect(body, roster)?;
        Self::decode(&body[layout.blocks[1].clone()], roster, victory_items)
    }
    /// Counts come from the static match options, never the untrusted stream.
    /// Includes inactive roster slots; the world membership mask is unrelated.
    pub fn decode(body: &[u8], roster: u8, victory_items: u8) -> Result<Self, &'static str> {
        if !(1..=20).contains(&roster) || victory_items > 10 {
            return Err("invalid statistics roster or victory item count");
        }
        let mut r = Reader(body);
        let mut players = Vec::new();
        for _ in 0..roster {
            let mut events = [0; 24];
            for event in &mut events {
                *event = r.short()?;
            }
            // intermediate_shared_statistics: two sparse 20-slot arrays.
            for is_damage in [true, false] {
                let count = r.byte()?;
                if count > 20 {
                    return Err("too many statistics sparse entries");
                }
                let mut seen = 0u32;
                for _ in 0..count {
                    let slot = r.byte()?;
                    if slot >= roster || seen & (1u32 << slot) != 0 {
                        return Err("invalid or duplicate statistics slot");
                    }
                    seen |= 1u32 << slot;
                    if is_damage {
                        if r.float()? < 0.0 {
                            return Err("negative received damage");
                        }
                    } else {
                        r.word()?;
                    }
                }
            }
            r.word()?; // relative last-killed time (0 is the absent sentinel)
            let last_hit = r.byte()?;
            if last_hit != 255 && last_hit >= roster {
                return Err("invalid last-hit slot");
            }
            let current_killstreak = r.short()?;
            r.float()?; // action coefficient, not itself the scoreboard score
            r.take(7)?; // killed faction representatives
            players.push(PlayerStats {
                events,
                current_killstreak,
            });
        }
        // One curing_event_status per static roster slot: relative time,u16,bool.
        r.take(usize::from(roster) * 7)?;
        // victory_item_event_manager: per-item sparse player contributions,
        // carried/stolen distances, team and in-container flag.
        for _ in 0..victory_items {
            let mask = r.word()?;
            if mask >> roster != 0 {
                return Err("victory contribution mask exceeds roster");
            }
            for _ in 0..mask.count_ones() {
                r.float()?;
            }
            r.float()?;
            r.float()?;
            let team = r.byte()?;
            if ![0, 1, 2, 3, 255].contains(&team) {
                return Err("invalid victory item team");
            }
            r.byte()?; // native bool accepts any nonzero byte
        }
        let team_points = [r.byte()?, r.byte()?];
        if !r.0.is_empty() {
            return Err("trailing match statistics");
        }
        Ok(Self {
            players,
            team_points,
        })
    }
}

/// Native lobby reply for the fixed local-test roster. Account IDs/names/teams
/// are server-owned. No economy is enabled: rewards, quests, drops and Elo are
/// zero. Maximum historical streak is unavailable in shared snapshots and is
/// left at its native default; current streak must not be mislabeled as maximum.
/// This limitation is explicit in RESULTS.txt.
impl Stats {
    pub fn lobby_packet(&self, match_id: u32, slot: u8) -> Result<Vec<u8>, &'static str> {
        let accounts: Vec<_> = (1..=self.players.len() as u32).collect();
        self.lobby_packet_with_accounts(match_id, slot, &accounts)
    }

    pub fn lobby_packet_with_accounts(
        &self,
        match_id: u32,
        slot: u8,
        accounts: &[u32],
    ) -> Result<Vec<u8>, &'static str> {
        crate::sessions::validate_accounts(accounts)?;
        if accounts.len() != self.players.len() {
            return Err("results identities differ from simulation roster");
        }
        let player = self
            .players
            .get(usize::from(slot))
            .ok_or("invalid results slot")?;
        let mut b = vec![0x36, 0x13];
        b.extend(match_id.to_le_bytes());
        let winner = match self.team_points[0].cmp(&self.team_points[1]) {
            std::cmp::Ordering::Greater => 0,
            std::cmp::Ordering::Less => 1,
            std::cmp::Ordering::Equal => 2,
        };
        b.extend([winner, self.team_points[0], self.team_points[1]]);
        // Award banners are unassigned in the local-test policy.
        b.extend([0; 3]); // best player empty name, u16 score
        b.extend([0; 4]); // gunslinger empty name, u8 accuracy, u16 shots
        b.extend([0; 5]); // support empty name, u16 healed, u16 saved
        b.extend([0; 5]); // researcher empty name, u16 artefacts, u16 items
        b.push(self.players.len() as u8);
        for (index, p) in self.players.iter().enumerate() {
            let name = format!("Local {}", accounts[index]);
            b.push(name.len() as u8);
            b.extend(name.as_bytes());
            b.extend(accounts[index].to_le_bytes());
            b.extend(p.score().to_le_bytes());
            b.extend(p.events[0].to_le_bytes());
            b.extend(p.events[2].to_le_bytes());
            b.push((index % 2) as u8);
            b.extend(0u16.to_le_bytes()); // no Elo system
        }
        b.extend(accounts[usize::from(slot)].to_le_bytes());
        for event in [1, 7, 8, 15, 14, 13, 6, 18, 5] {
            b.extend(player.events[event].to_le_bytes());
        }
        b.push(1); // fixed local profile level
        b.extend(player.events[17].to_le_bytes());
        b.extend([0; 8]); // exp, money, Elo before, Elo after
        b.push(0); // neutral reputation faction
        b.extend([0; 4]); // reputation, unrecorded maximum streak
        let shots = u32::from(player.events[22]);
        let hits = u32::from(player.events[23]);
        b.push(if shots == 0 {
            0
        } else {
            (hits * 100 / shots).min(100) as u8
        });
        b.extend(106u16.to_le_bytes()); // fixed test PPSh
        b.extend(0u16.to_le_bytes()); // no second weapon
        b.extend([0; 6]); // quest count, drop count, drop value
        Ok(b)
    }
}
impl PlayerStats {
    /// base_game_statistics_handler::recalculate_scores0x19c410 with the fixed
    /// setup coefficients; distance counters6/17/18 have a0.01 multiplier.
    pub fn score(&self) -> u16 {
        let mut total = 0.0f32;
        for (event, (&count, &coefficient)) in self
            .events
            .iter()
            .zip(crate::setup::SCORES.iter())
            .enumerate()
        {
            let scale = if [6, 17, 18].contains(&event) {
                0.01f32
            } else {
                1.0
            };
            total += f32::from(count) * coefficient * scale;
        }
        ((total + 0.5).floor() as i32) as u16
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn results_preserve_account_ids_names_and_local_recipient_for_reordered_roster() {
        let stats = Stats {
            players: vec![
                PlayerStats {
                    events: [0; 24],
                    current_killstreak: 0
                };
                2
            ],
            team_points: [5, 0],
        };
        let packet = stats.lobby_packet_with_accounts(77, 1, &[3, 16]).unwrap();
        assert_eq!(&packet[..6], &[0x36, 0x13, 77, 0, 0, 0]);
        assert_eq!(packet[26], 2);
        let mut offset = 27;
        for (id, team, name) in [(3u32, 0, "Local 3"), (16, 1, "Local 16")] {
            let length = packet[offset] as usize;
            offset += 1;
            assert_eq!(&packet[offset..offset + length], name.as_bytes());
            offset += length;
            assert_eq!(&packet[offset..offset + 4], &id.to_le_bytes());
            assert_eq!(packet[offset + 10], team);
            offset += 13;
        }
        assert_eq!(&packet[offset..offset + 4], &16u32.to_le_bytes());
        assert!(stats.lobby_packet_with_accounts(77, 1, &[3]).is_err());
        assert!(stats.lobby_packet_with_accounts(77, 1, &[3, 3]).is_err());
    }
    fn fixture() -> Vec<u8> {
        // Explicit wire layout, independent field values exercise boundaries.
        let mut b = Vec::new();
        for slot in 0..2u16 {
            for event in 0..24u16 {
                b.extend((slot * 100 + event).to_le_bytes());
            }
            b.push(1);
            b.push((1 - slot) as u8);
            b.extend(12.5f32.to_le_bytes());
            b.push(1);
            b.push((1 - slot) as u8);
            b.extend(1234u32.to_le_bytes());
            b.extend(5678u32.to_le_bytes());
            b.push(255);
            b.extend((slot + 3).to_le_bytes());
            b.extend(0.5f32.to_le_bytes());
            b.extend([0; 7]);
        }
        b.extend([0; 14]);
        b.extend(3u32.to_le_bytes());
        for v in [1.0f32, 2.0, 3.0, 4.0] {
            b.extend(v.to_le_bytes());
        }
        b.extend([1, 255, 2, 4]);
        b
    }
    #[test]
    fn decodes_events_sparse_arrays_and_team_scores_and_rejects_all_truncations() {
        let b = fixture();
        let s = Stats::decode(&b, 2, 1).unwrap();
        assert_eq!(s.players[0].events[22], 22);
        assert_eq!(s.players[1].events[2], 102);
        assert_eq!(s.players[1].current_killstreak, 4);
        assert_eq!(s.team_points, [2, 4]);
        for end in 0..b.len() {
            assert!(Stats::decode(&b[..end], 2, 1).is_err(), "prefix {end}");
        }
        let mut extra = b.clone();
        extra.push(0);
        assert!(Stats::decode(&extra, 2, 1).is_err());
        assert!(Stats::decode(&b, 1, 1).is_err());
        assert!(Stats::decode(&b, 2, 0).is_err());
    }
    #[test]
    fn rejects_bad_sparse_slot_and_nonfinite_damage() {
        let mut b = fixture();
        b[49] = 2;
        assert!(Stats::decode(&b, 2, 1).is_err());
        let mut b = fixture();
        b[50..54].copy_from_slice(&f32::NAN.to_le_bytes());
        assert!(Stats::decode(&b, 2, 1).is_err());
        let mut b = fixture();
        b[48] = 21;
        assert!(Stats::decode(&b, 2, 1).is_err());
    }
}
