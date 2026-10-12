// SPDX-License-Identifier: GPL-3.0-or-later
//! Reassembly of the community patch's client 0x47 uploads, not UDP fragments.
//! This preserves opaque engine state; completion and CRC do not prove that
//! a snapshot is eligible for a match, roster, timestamp, or recovery generation.

use std::{collections::BTreeMap, fmt};

pub const MAX_BYTES: usize = 32 * 1024;
const MAX_TRANSFERS: usize = 4;
const RETAIN_MS: u64 = 10_000;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Error {
    InvalidFragment,
    Conflict,
    Capacity,
}
impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "v0.21d snapshot: {self:?}")
    }
}
impl std::error::Error for Error {}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Snapshot {
    pub time: u32,
    pub body: Vec<u8>,
}
impl Snapshot {
    pub fn crc32(&self) -> u32 {
        crc32(&self.body)
    }
}

#[derive(Debug)]
struct Transfer {
    started: u64,
    body: Vec<u8>,
    present: Vec<bool>,
    received: usize,
}

/// One assembler per peer and match generation. Completed transfers remain
/// immutable for the retry interval, so retransmissions cannot emit them twice.
/// Expiry is observable; the coordinator must request a new snapshot if needed.
/// Retention and capacity are SRP policy, not recovered community-server rules.
#[derive(Debug, Default)]
pub struct Assembler {
    transfers: BTreeMap<u32, Transfer>,
}
impl Assembler {
    /// Returns expired incomplete timestamps. Fully received transfers expire
    /// silently. A caller must reject stale timestamps when selecting a state.
    pub fn expire(&mut self, now: u64) -> Vec<u32> {
        let mut incomplete = Vec::new();
        self.transfers.retain(|time, transfer| {
            let keep = now.saturating_sub(transfer.started) < RETAIN_MS;
            if !keep && transfer.received != transfer.body.len() {
                incomplete.push(*time);
            }
            keep
        });
        incomplete
    }

    /// Accepts the complete 0x47 application body, excluding its opcode.
    /// Call expire explicitly so timeout decisions cannot go unnoticed.
    pub fn push(&mut self, message: &[u8], now: u64) -> Result<Option<Snapshot>, Error> {
        if message.len() <= 8 || message.len() > 488 {
            return Err(Error::InvalidFragment);
        }
        let time = u32::from_le_bytes(message[..4].try_into().unwrap());
        let offset = usize::from(u16::from_le_bytes(message[4..6].try_into().unwrap()));
        let total = usize::from(u16::from_le_bytes(message[6..8].try_into().unwrap()));
        let data = &message[8..];
        if total == 0 || total > MAX_BYTES || offset + data.len() > total {
            return Err(Error::InvalidFragment);
        }
        if !self.transfers.contains_key(&time) {
            if self.transfers.len() >= MAX_TRANSFERS {
                return Err(Error::Capacity);
            }
            self.transfers.insert(
                time,
                Transfer {
                    started: now,
                    body: vec![0; total],
                    present: vec![false; total],
                    received: 0,
                },
            );
        }
        let transfer = self.transfers.get_mut(&time).unwrap();
        if transfer.body.len() != total {
            return Err(Error::Conflict);
        }
        for (index, byte) in data.iter().enumerate() {
            let index = offset + index;
            if transfer.present[index] && transfer.body[index] != *byte {
                return Err(Error::Conflict);
            }
        }
        if transfer.received == total {
            return Ok(None);
        }
        for (index, byte) in data.iter().enumerate() {
            let index = offset + index;
            if !transfer.present[index] {
                transfer.present[index] = true;
                transfer.body[index] = *byte;
                transfer.received += 1;
            }
        }
        Ok((transfer.received == total).then(|| Snapshot {
            time,
            body: transfer.body.clone(),
        }))
    }
}

/// CRC-32/ISO-HDLC, verified against captured client 0x46 values. The timestamp
/// is excluded; every byte of the serialized world body is included.
pub fn crc32(bytes: &[u8]) -> u32 {
    let mut crc = !0u32;
    for byte in bytes {
        crc ^= u32::from(*byte);
        for _ in 0..8 {
            crc = (crc >> 1) ^ (0xedb88320 & 0u32.wrapping_sub(crc & 1));
        }
    }
    !crc
}

#[cfg(test)]
mod tests {
    use super::*;
    fn fragment(time: u32, offset: u16, total: u16, data: &[u8]) -> Vec<u8> {
        [
            time.to_le_bytes().as_slice(),
            &offset.to_le_bytes(),
            &total.to_le_bytes(),
            data,
        ]
        .concat()
    }

    #[test]
    fn reordered_overlapping_and_duplicate_uploads_complete_once() {
        let mut a = Assembler::default();
        assert_eq!(a.push(&fragment(50, 3, 6, b"def"), 0), Ok(None));
        assert_eq!(a.push(&fragment(50, 2, 6, b"cde"), 1), Ok(None));
        let first = fragment(50, 0, 6, b"abc");
        assert_eq!(
            a.push(&first, 2),
            Ok(Some(Snapshot {
                time: 50,
                body: b"abcdef".to_vec()
            }))
        );
        assert_eq!(a.push(&first, 3), Ok(None));
        assert_eq!(a.push(&fragment(50, 1, 6, b"X"), 4), Err(Error::Conflict));
    }

    #[test]
    fn invalid_bounds_conflicts_capacity_and_expiry_are_explicit() {
        let mut a = Assembler::default();
        assert_eq!(
            a.push(&fragment(0, 65535, 4, b"a"), 0),
            Err(Error::InvalidFragment)
        );
        assert_eq!(
            a.push(&fragment(0, 0, 65535, b"a"), 0),
            Err(Error::InvalidFragment)
        );
        for time in 0..4 {
            a.push(&fragment(time, 0, 2, b"a"), 0).unwrap();
        }
        assert_eq!(a.push(&fragment(0, 1, 3, b"a"), 1), Err(Error::Conflict));
        assert_eq!(a.push(&fragment(4, 0, 2, b"a"), 1), Err(Error::Capacity));
        assert_eq!(a.expire(RETAIN_MS), vec![0, 1, 2, 3]);
        assert!(
            a.push(&fragment(4, 0, 2, b"ab"), RETAIN_MS)
                .unwrap()
                .is_some()
        );
        assert!(a.expire(RETAIN_MS * 2).is_empty());
    }

    #[test]
    fn standard_crc_vector() {
        assert_eq!(crc32(b"123456789"), 0xcbf43926);
        assert_eq!(crc32(b""), 0);
    }
}
