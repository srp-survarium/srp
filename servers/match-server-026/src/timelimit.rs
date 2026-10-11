// SPDX-License-Identifier: GPL-3.0-or-later
//! Native timelimit rule prefix (0x317f30/0x317fd0) and predicate (0x318360).
//! The pinned map configs listed here put rule 93 first in the rules stream.
use crate::state;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Limits {
    pub match_ms: u32,
    pub waiting_ms: u32,
}

impl Limits {
    pub fn for_map(map: u8) -> Option<Self> {
        include_str!("../fixtures/026g-mode-timers.tsv")
            .lines()
            .filter(|line| !line.starts_with('#'))
            .find_map(|line| {
                let mut fields = line.split('\t');
                if fields.next()?.parse::<u8>().ok()? != map {
                    return None;
                }
                Some(Self {
                    match_ms: fields.next()?.parse::<u32>().ok()?.checked_mul(1000)?,
                    waiting_ms: fields.next()?.parse::<u32>().ok()?.checked_mul(60_000)?,
                })
            })
    }

    /// Evaluate a CRC-verified checkpoint, never extrapolate from a stale state.
    /// Layout validation is separate from CRC, provenance and membership checks.
    pub fn completed(self, bytes: &[u8], time: u32, roster: u8) -> Result<bool, &'static str> {
        let layout = state::inspect(bytes, roster)?;
        let rules = &bytes[layout.blocks[4].clone()];
        let prefix = rules.get(..13).ok_or("missing time-limit rule prefix")?;
        let start = u32::from_le_bytes(prefix[..4].try_into().unwrap());
        let current = u32::from_le_bytes(prefix[4..8].try_into().unwrap());
        let mask = u32::from_le_bytes(prefix[8..12].try_into().unwrap());
        if current != time || mask != layout.mask || start > current {
            return Err("time-limit rule disagrees with checkpoint identity");
        }
        match prefix[12] {
            1 => Ok(current - start >= self.waiting_ms),
            3 => Ok(current - start >= self.match_ms),
            0 | 2 => Ok(false),
            _ => Err("unknown time-limit rule state"),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn checkpoint(start: u32, current: u32, status: u8) -> Vec<u8> {
        // No players, four empty world blocks, 13-byte timer, empty effects.
        let mut bytes = vec![0; 12];
        bytes.extend(13u16.to_le_bytes());
        bytes.extend(start.to_le_bytes());
        bytes.extend(current.to_le_bytes());
        bytes.extend(0u32.to_le_bytes());
        bytes.push(status);
        bytes.extend(0u16.to_le_bytes());
        bytes
    }

    #[test]
    fn matches_native_completion_predicate() {
        let mut count = 0;
        for line in include_str!("../fixtures/026g-timelimit.tsv")
            .lines()
            .filter(|line| !line.starts_with('#') && !line.is_empty())
        {
            let fields: Vec<u32> = line
                .split('\t')
                .map(|field| field.parse().unwrap())
                .collect();
            let limits = Limits {
                match_ms: fields[3],
                waiting_ms: fields[4],
            };
            let bytes = checkpoint(fields[0], fields[1], fields[2] as u8);
            assert_eq!(limits.completed(&bytes, fields[1], 2), Ok(fields[5] != 0));
            count += 1;
        }
        assert_eq!(count, 84);
    }

    #[test]
    fn native_states_deadlines_and_checkpoint_identity() {
        let limits = Limits::for_map(71).unwrap();
        assert_eq!(
            limits,
            Limits {
                match_ms: 900_000,
                waiting_ms: 300_000
            }
        );
        for (status, duration) in [(1, 300_000), (3, 900_000)] {
            let start = 20500;
            for delta in [duration - 1, duration, duration + 1] {
                assert_eq!(
                    limits.completed(&checkpoint(start, start + delta, status), start + delta, 2),
                    Ok(delta >= duration)
                );
            }
        }
        for status in [0, 2] {
            assert_eq!(
                limits.completed(&checkpoint(50, 1_000_000, status), 1_000_000, 2),
                Ok(false)
            );
        }
        assert!(limits.completed(&checkpoint(50, 100, 4), 100, 2).is_err());
        assert!(limits.completed(&checkpoint(50, 100, 3), 150, 2).is_err());
        assert!(limits.completed(&checkpoint(150, 100, 3), 100, 2).is_err());
        let mut bytes = checkpoint(50, 100, 3);
        bytes[22] = 1; // timer membership disagrees with empty historical state
        assert!(limits.completed(&bytes, 100, 2).is_err());
        assert_eq!(Limits::for_map(115).unwrap().match_ms, 90_000);
        assert!(Limits::for_map(141).is_none());
        assert!(Limits::for_map(151).is_none());
    }
}
