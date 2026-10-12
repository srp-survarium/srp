// SPDX-License-Identifier: GPL-3.0-or-later
//! 0.26g0 shared statistics: 0x2f5ac0, 0x335750, 0x3353c0, 0x334dc0.
//! Counts come from match setup and the map's victory-item rule, not this stream.
use crate::state;

const BYTE_EVENTS: [usize; 22] = [
    0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 19, 20, 21, 24, 25, 27,
];
const WORD_EVENTS: [usize; 6] = [6, 17, 18, 22, 23, 26];

#[derive(Debug, PartialEq, Eq)]
pub struct Player {
    /// Event dictionary index, then equipment preset. Includes inactive slots.
    pub events: [[u16; 3]; 28],
    pub longest_killstreak: u16,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Statistics {
    pub players: Vec<Player>,
    pub team_points: [u16; 2],
    pub team_victory_items: [u8; 2],
    /// Raw native team enum; no inference about completion is made here.
    pub winner_team: u8,
    /// All players active during the match; can differ from current membership.
    pub active_in_match_mask: u32,
}

struct Reader<'a> {
    bytes: &'a [u8],
    cursor: usize,
}
impl Reader<'_> {
    fn take(&mut self, count: usize) -> Result<&[u8], &'static str> {
        let end = self
            .cursor
            .checked_add(count)
            .ok_or("statistics overflow")?;
        let value = self
            .bytes
            .get(self.cursor..end)
            .ok_or("truncated statistics")?;
        self.cursor = end;
        Ok(value)
    }
    fn byte(&mut self) -> Result<u8, &'static str> {
        Ok(self.take(1)?[0])
    }
    fn word(&mut self) -> Result<u16, &'static str> {
        Ok(u16::from_le_bytes(self.take(2)?.try_into().unwrap()))
    }
    fn mask(&mut self, bits: u8) -> Result<u32, &'static str> {
        let value = u32::from_le_bytes(self.take(4)?.try_into().unwrap());
        if value >> bits != 0 {
            return Err("statistics mask exceeds its domain");
        }
        Ok(value)
    }
    fn sparse_words(&mut self, bits: u8) -> Result<(), &'static str> {
        let mask = self.mask(bits)?;
        self.take(mask.count_ones() as usize * 4)?;
        Ok(())
    }
}

pub fn inspect(
    checkpoint: &[u8],
    roster: u8,
    victory_items: u8,
) -> Result<Statistics, &'static str> {
    let layout = state::inspect(checkpoint, roster)?;
    // Item masks in the corresponding rule use u16. Reject impossible counts.
    if victory_items > 16 {
        return Err("too many victory items");
    }
    read_block(&checkpoint[layout.blocks[1].clone()], roster, victory_items)
}

fn read_block(bytes: &[u8], roster: u8, victory_items: u8) -> Result<Statistics, &'static str> {
    let mut reader = Reader { bytes, cursor: 0 };
    let mut players = Vec::new();
    for _ in 0..roster {
        let mut events = [[0; 3]; 28];
        for preset in 0..3 {
            let mask = reader.mask(28)?;
            for event in BYTE_EVENTS {
                if mask & (1 << event) != 0 {
                    events[event][preset] = u16::from(reader.byte()?);
                }
            }
            for event in WORD_EVENTS {
                if mask & (1 << event) != 0 {
                    events[event][preset] = reader.word()?;
                }
            }
        }
        // Damage per inflictor/preset, then last-hit timestamps per receiver.
        // Native storage has 20 slots even for a smaller negotiated roster.
        for _ in 0..4 {
            reader.sparse_words(20)?;
        }
        reader.take(10)?; // last kill time, last enemy, killstreak, action coef
        players.push(Player {
            events,
            longest_killstreak: reader.word()?,
        });
    }
    for _ in 0..victory_items {
        for _ in 0..3 {
            reader.sparse_words(roster)?; // carried distances per preset
        }
        reader.take(10)?; // two nearest positions, owner team, first finder
    }
    let result = Statistics {
        players,
        team_points: [reader.word()?, reader.word()?],
        team_victory_items: [reader.byte()?, reader.byte()?],
        winner_team: reader.byte()?,
        active_in_match_mask: reader.mask(roster)?,
    };
    if reader.cursor != bytes.len() {
        return Err("trailing statistics bytes or incorrect victory-item count");
    }
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn unhex(hex: &str) -> Vec<u8> {
        let compact: String = hex.chars().filter(|c| !c.is_whitespace()).collect();
        (0..compact.len())
            .step_by(2)
            .map(|i| u8::from_str_radix(&compact[i..i + 2], 16).unwrap())
            .collect()
    }

    #[test]
    fn captured_nonzero_byte_and_word_events() {
        for (hex, roster, event, value) in [
            (include_str!("../fixtures/026g-event-byte.hex"), 2, 19, 1),
            (include_str!("../fixtures/026g-event-word.hex"), 1, 22, 2),
        ] {
            let bytes = unhex(hex);
            let stats = inspect(&bytes, roster, 10).unwrap();
            assert_eq!(stats.players[0].events[event], [value, 0, 0]);
            assert_eq!(stats.winner_team, 3);
            // Roster is static match setup, not the count of active players.
            assert!(inspect(&bytes, 3 - roster, 10).is_err());
            let layout = state::inspect(&bytes, roster).unwrap();
            let mut malformed = bytes.clone();
            malformed[layout.blocks[1].start + 3] |= 0x80;
            assert!(inspect(&malformed, roster, 10).is_err());
        }
    }

    #[test]
    fn captured_school_statistics_and_truncation() {
        for hex in [
            include_str!("../fixtures/026g-school-initial.hex"),
            include_str!("../fixtures/026g-school-live.hex"),
        ] {
            let bytes = unhex(hex);
            let stats = inspect(&bytes, 2, 10).unwrap();
            assert_eq!(stats.players.len(), 2);
            assert_eq!(stats.team_points, [0, 0]);
            assert_eq!(stats.team_victory_items, [0, 0]);
            assert!(inspect(&bytes, 2, 9).is_err());
            assert!(inspect(&bytes, 2, 11).is_err());
            let layout = state::inspect(&bytes, 2).unwrap();
            let block = &bytes[layout.blocks[1].clone()];
            for end in 0..block.len() {
                assert!(read_block(&block[..end], 2, 10).is_err());
            }
        }
    }
}
