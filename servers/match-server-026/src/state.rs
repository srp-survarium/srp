// SPDX-License-Identifier: GPL-3.0-or-later
//! 0.26g0 build 2777 historical-state boundaries; opaque bytes are never rewritten.
//! Layout: 0x324be0 / 0x324d80; players: 0x33fde0 / 0x33fee0.
//! Animation envelope: 0x3a9900, times: 0x3a9580, floats: 0x3a9720.
//! This validates boundaries, not animation-tree semantics or game rules.
//! Adapted from the 0.21d investigation's boundary reader, with the 0.26 layout.
const MAX_MESSAGE: usize = 32768;
use std::ops::Range;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Player {
    pub slot: u8,
    pub state: Range<usize>,
    pub animation: Option<Range<usize>>,
}
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Layout {
    pub mask: u32,
    pub players: Vec<Player>,
    /// Bullets, statistics, objects, physics, rules, effects, in wire order.
    pub blocks: [Range<usize>; 6],
}

/// `roster` comes from this match's static setup, never from the uploaded mask.
/// Timestamp, membership, provenance and generation are coordinator checks.
pub fn inspect(body: &[u8], roster: u8) -> Result<Layout, &'static str> {
    if !(1..=20).contains(&roster) || body.len() > MAX_MESSAGE - 4 {
        return Err("invalid state size or roster");
    }
    let mask = u32::from_le_bytes(
        body.get(..4)
            .ok_or("missing state mask")?
            .try_into()
            .unwrap(),
    );
    if mask >> roster != 0 {
        return Err("state mask exceeds static roster");
    }
    let mut cursor = 4;
    let mut players = Vec::new();
    for slot in 0..roster {
        if mask & (1 << slot) == 0 {
            continue;
        }
        let state = block(body, &mut cursor)?;
        let flag = *body.get(cursor).ok_or("missing animation flag")?;
        cursor += 1;
        // The engine treats any nonzero byte as true (0xff is captured).
        let animation = if flag != 0 {
            let start = cursor;
            cursor = animation_end(body, cursor)?;
            Some(start..cursor)
        } else {
            None
        };
        players.push(Player {
            slot,
            state,
            animation,
        });
    }
    let mut blocks = std::array::from_fn(|_| 0..0);
    for range in &mut blocks {
        *range = block(body, &mut cursor)?;
    }
    if cursor != body.len() {
        return Err("trailing serialized state data");
    }
    Ok(Layout {
        mask,
        players,
        blocks,
    })
}

fn block(body: &[u8], cursor: &mut usize) -> Result<Range<usize>, &'static str> {
    let size = body
        .get(*cursor..*cursor + 2)
        .ok_or("missing state block size")?;
    let size = usize::from(u16::from_le_bytes(size.try_into().unwrap()));
    *cursor += 2;
    let start = *cursor;
    *cursor += size;
    if *cursor > body.len() {
        return Err("truncated state block");
    }
    Ok(start..*cursor)
}

struct Bits<'a> {
    bytes: &'a [u8],
    cursor: usize,
}
impl Bits<'_> {
    fn skip(&mut self, size: usize) -> Result<(), &'static str> {
        if size > self.bytes.len() * 8 - self.cursor {
            return Err("truncated compressed animation");
        }
        self.cursor += size;
        Ok(())
    }
    fn read(&mut self, size: usize) -> Result<usize, &'static str> {
        let start = self.cursor;
        self.skip(size)?;
        let mut result = 0;
        for bit in start..self.cursor {
            result = (result << 1) | usize::from((self.bytes[bit / 8] >> (7 - bit % 8)) & 1);
        }
        Ok(result)
    }
}
fn width(count: usize) -> usize {
    (usize::BITS - count.leading_zeros()).max(1) as usize
}
fn animation_end(body: &[u8], start: usize) -> Result<usize, &'static str> {
    let mut bits = Bits {
        bytes: body,
        cursor: start * 8,
    };
    let tree_bits = bits.read(16)?;
    bits.skip(tree_bits)?;
    let count = bits.read(10)?;
    if count != 0 {
        let dictionary = bits.read(1)? != 0;
        bits.skip(32)?;
        if count > 1 {
            let element_width = bits.read(5)?;
            if dictionary {
                let unique = bits.read(width(count))?;
                if unique == 0 {
                    return Err("empty compressed time dictionary");
                }
                bits.skip((unique - 1) * element_width)?;
                bits.skip(count * width(unique))?;
            } else {
                bits.skip(count * element_width)?;
            }
        }
    }
    let dictionary = bits.read(1)? != 0;
    let count = bits.read(10)?;
    if dictionary {
        let unique = bits.read(width(count))?;
        bits.skip(unique * 32)?;
        bits.skip(count * width(unique))?;
    } else {
        bits.skip(count * 32)?;
    }
    Ok(bits.cursor.div_ceil(8))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn hex(text: &str) -> Vec<u8> {
        text.trim()
            .as_bytes()
            .chunks_exact(2)
            .map(|pair| u8::from_str_radix(std::str::from_utf8(pair).unwrap(), 16).unwrap())
            .collect()
    }

    #[test]
    fn matches_native_animation_boundaries() {
        let mut count = 0;
        for line in include_str!("../fixtures/026g-animations.tsv")
            .lines()
            .filter(|line| !line.starts_with('#') && !line.is_empty())
        {
            let fields: Vec<_> = line.split('\t').collect();
            let bytes = hex(fields[0]);
            let expected: usize = fields[1].parse().unwrap();
            assert_eq!(animation_end(&bytes, 0), Ok(expected));
            assert_eq!(expected, bytes.len());
            assert!(animation_end(&bytes[..bytes.len() - 1], 0).is_err());
            count += 1;
        }
        assert_eq!(count, 253);
    }

    #[test]
    fn real_school_snapshots_match_native_boundaries() {
        let initial = hex(include_str!("../fixtures/026g-school-initial.hex"));
        let layout = inspect(&initial, 2).unwrap();
        assert_eq!(layout.mask, 0);
        assert!(layout.players.is_empty());
        assert_eq!(
            layout.blocks,
            [6..22, 24..335, 337..570, 572..572, 574..2355, 2357..2377]
        );
        let live = hex(include_str!("../fixtures/026g-school-live.hex"));
        let layout = inspect(&live, 2).unwrap();
        assert_eq!(layout.mask, 3);
        assert_eq!(
            layout.players,
            vec![
                Player {
                    slot: 0,
                    state: 6..681,
                    animation: Some(682..854)
                },
                Player {
                    slot: 1,
                    state: 856..1531,
                    animation: Some(1532..1704)
                },
            ]
        );
        assert_eq!(
            layout.blocks,
            [
                1706..1722,
                1724..2035,
                2037..2292,
                2294..2294,
                2296..4077,
                4079..4099
            ]
        );
        assert_eq!(crc32fast::hash(&live), 0x943e6614);
        for bytes in [&initial, &live] {
            for end in 0..bytes.len() {
                assert!(inspect(&bytes[..end], 2).is_err(), "accepted prefix {end}");
            }
        }
    }

    fn state(animation: &[u8], flag: u8) -> Vec<u8> {
        // Slot 1, two opaque player bytes, then six one-byte world blocks.
        [
            vec![2, 0, 0, 0, 2, 0, 0xaa, 0xbb, flag],
            animation.to_vec(),
            vec![1, 0, 11, 1, 0, 12, 1, 0, 13, 1, 0, 14, 1, 0, 15, 1, 0, 16],
        ]
        .concat()
    }

    #[test]
    fn populated_boundaries_flags_and_every_truncated_prefix() {
        // 16 zero tree bits count, 10 zero time count, float mode 0/count 0.
        for flag in [1, 2, 255] {
            let bytes = state(&[0; 5], flag);
            let layout = inspect(&bytes, 2).unwrap();
            assert_eq!(layout.mask, 2);
            assert_eq!(
                layout.players,
                vec![Player {
                    slot: 1,
                    state: 6..8,
                    animation: Some(9..14),
                }]
            );
            assert_eq!(
                layout.blocks,
                [16..17, 19..20, 22..23, 25..26, 28..29, 31..32]
            );
            for end in 0..bytes.len() {
                assert!(inspect(&bytes[..end], 2).is_err(), "accepted prefix {end}");
            }
            let mut trailing = bytes.clone();
            trailing.push(0);
            assert!(inspect(&trailing, 2).is_err());
            assert!(inspect(&bytes, 1).is_err());
        }
        assert_eq!(
            inspect(&state(&[], 0), 2).unwrap().players[0].animation,
            None
        );
        let mut oversized = state(&[], 0);
        oversized[4..6].copy_from_slice(&u16::MAX.to_le_bytes());
        assert!(inspect(&oversized, 2).is_err());
    }

    #[test]
    fn animation_direct_and_dictionary_boundaries() {
        // Independently calculated bit lengths from the recovered format.
        // Build fields MSB-first, checking exact expected byte boundary.
        fn pack(fields: &[(usize, usize)]) -> Vec<u8> {
            let mut bits = Vec::new();
            for &(value, width) in fields {
                for shift in (0..width).rev() {
                    bits.push((value >> shift) & 1);
                }
            }
            let mut out = vec![0; bits.len().div_ceil(8)];
            for (i, bit) in bits.into_iter().enumerate() {
                out[i / 8] |= (bit as u8) << (7 - i % 8);
            }
            out
        }
        // Tree 3 bits; time count 2/direct/base/width 4/two deltas;
        // floats direct, count 1, one f32: 118 bits = 15 bytes.
        let direct = pack(&[
            (3, 16),
            (5, 3),
            (2, 10),
            (0, 1),
            (0, 32),
            (4, 5),
            (0x12, 8),
            (0, 1),
            (1, 10),
            (0x3f800000, 32),
        ]);
        assert_eq!(direct.len(), 15);
        assert_eq!(animation_end(&direct, 0), Ok(15));
        // Time count 3, two unique times (one delta), three 2-bit indices;
        // float count 3, two unique values, three 2-bit indices: 159 bits.
        let dict = pack(&[
            (0, 16),
            (3, 10),
            (1, 1),
            (0, 32),
            (4, 5),
            (2, 2),
            (1, 4),
            (0, 6),
            (1, 1),
            (3, 10),
            (2, 2),
            (0, 32),
            (0x3f800000, 32),
            (0, 6),
        ]);
        assert_eq!(dict.len(), 20);
        assert_eq!(animation_end(&dict, 0), Ok(20));
        for bytes in [&direct, &dict] {
            for end in 0..bytes.len() {
                assert!(animation_end(&bytes[..end], 0).is_err());
            }
            assert!(inspect(&state(bytes, 255), 2).is_ok());
        }
        let bad = pack(&[(0, 16), (2, 10), (1, 1), (0, 32), (4, 5), (0, 2)]);
        assert_eq!(
            animation_end(&bad, 0),
            Err("empty compressed time dictionary")
        );
    }
}
