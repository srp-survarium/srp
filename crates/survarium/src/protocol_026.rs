// SPDX-License-Identifier: GPL-3.0-or-later
//! Match and lobby framing for retail 0.26g0, recovered from VAs 0x279670,
//! 0x26e390 and 0x3fa240. Acknowledgements: `vostok::network_packet::udp_026`.

use std::fmt;

pub mod compression;
pub mod lobby;
pub mod match_options;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Direction {
    LobbyClient,
    LobbyServer,
    Client,
    /// SRP client with the opt-in E2 snapshot-upload extension.
    ClientSnapshots,
    Server,
    /// SRP server with the opt-in F7 historical snapshot request.
    ServerSnapshots,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Fragment {
    pub index: u8,
    /// Present only in fragment zero. This counts fragments, not bytes.
    pub count: Option<u8>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Frame<'a> {
    pub id: u8,
    /// Wire delivery byte: unique ID, or order index for ordered lobby messages.
    pub unique_id: Option<u8>,
    pub fragment: Option<Fragment>,
    pub body: &'a [u8],
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Error {
    UnknownMessage(u8),
    WrongDirection(u8),
    Truncated,
    InvalidLength,
    InvalidFragment,
    InvalidUniqueId,
    InvalidPlayerMask,
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{self:?}")
    }
}
impl std::error::Error for Error {}

fn has_unique_id(id: u8) -> bool {
    matches!(id, 0x2e..=0x50 | 0x80..=0x85 | 0x87..=0x9e | 0xa0..=0xa6 | 0xa8..=0xaa | 0xe4..=0xe8 | 0xf6)
}

fn validate_id(id: u8, direction: Direction) -> Result<(), Error> {
    match id {
        0x2e..=0x50 if direction == Direction::LobbyClient => Ok(()),
        0x80..=0x85 | 0x87..=0xa6 | 0xa8..=0xaa if direction == Direction::LobbyServer => Ok(()),
        0xd8..=0xe1 if matches!(direction, Direction::Client | Direction::ClientSnapshots) => {
            Ok(())
        }
        0xe2 if direction == Direction::ClientSnapshots => Ok(()),
        0xe3..=0xf6 if matches!(direction, Direction::Server | Direction::ServerSnapshots) => {
            Ok(())
        }
        0xf7 | 0xf8 if direction == Direction::ServerSnapshots => Ok(()),
        0xfa..=0xfe => Ok(()),
        0x2e..=0x50 | 0x80..=0x85 | 0x87..=0xa6 | 0xa8..=0xaa | 0xd8..=0xe1 | 0xe3..=0xf6 => {
            Err(Error::WrongDirection(id))
        }
        _ => Err(Error::UnknownMessage(id)),
    }
}

/// `None` means explicitly length-prefixed in bundles, remainder of packet otherwise.
fn body_length(id: u8, body: &[u8], players: u8) -> Result<Option<usize>, Error> {
    Ok(Some(match id {
        0x2e..=0x50 | 0x80..=0x85 | 0x87..=0xa6 | 0xa8..=0xaa => return Ok(None),
        0xd8 | 0xdf => 5,
        0xd9 | 0xe3 | 0xe6 | 0xf0 | 0xf7 => 4,
        0xda | 0xe0 | 0xe1 | 0xfa..=0xfe => 0,
        0xdb => 6,
        0xdc => 9,
        0xdd | 0xeb => 10,
        0xde | 0xe7 | 0xe9 | 0xea | 0xef | 0xf2 | 0xf4 => 2,
        0xe5 => 7,
        0xec => 11,
        0xf1 | 0xf5 => 1,
        0xf3 => 3,
        0xe2 | 0xe4 | 0xe8 | 0xf6 | 0xf8 => return Ok(None),
        0xed | 0xee => {
            if !(1..=20).contains(&players) {
                return Err(Error::InvalidPlayerMask);
            }
            let time_bytes = if id == 0xed { 1 } else { 2 };
            let mask_bytes = usize::from(players).div_ceil(8);
            let mask = body
                .get(time_bytes..time_bytes + mask_bytes)
                .ok_or(Error::Truncated)?;
            if players % 8 != 0 && mask[mask_bytes - 1] >> (players % 8) != 0 {
                return Err(Error::InvalidPlayerMask);
            }
            time_bytes
                + mask_bytes
                + mask.iter().map(|b| b.count_ones() as usize).sum::<usize>() * 8
        }
        _ => return Err(Error::UnknownMessage(id)),
    }))
}

fn byte(input: &mut &[u8]) -> Result<u8, Error> {
    let (&first, rest) = input.split_first().ok_or(Error::Truncated)?;
    *input = rest;
    Ok(first)
}

fn variable_minimum(id: u8, fragment: Option<Fragment>) -> usize {
    if id == 0xe2 {
        9
    } else if id == 0xe8 && fragment.is_none_or(|f| f.index == 0) {
        3
    } else {
        1
    }
}

/// Parse a payload after removing the UDP envelope and acknowledgement tail.
/// Fragment bodies remain fragmented; reassembly and duplicate suppression are
/// the connection's responsibility. `players` is needed only for ED/EE batches.
pub fn decode_frames(
    mut input: &[u8],
    single: bool,
    direction: Direction,
    players: u8,
) -> Result<Vec<Frame<'_>>, Error> {
    if input.is_empty() {
        return Err(Error::Truncated);
    }
    let mut frames = Vec::new();
    while !input.is_empty() {
        let first = byte(&mut input)?;
        let fragmented = first == 0xff;
        let id = if fragmented { byte(&mut input)? } else { first };
        validate_id(id, direction)?;
        if id >= 0xfa && (fragmented || !input.is_empty()) {
            return Err(Error::InvalidLength);
        }
        let unique_id = if has_unique_id(id) {
            Some(byte(&mut input)?)
        } else {
            None
        };
        let fragment = if fragmented {
            let index = byte(&mut input)?;
            let count = if index == 0 {
                Some(byte(&mut input)?)
            } else {
                None
            };
            if count == Some(0) || index == 255 {
                return Err(Error::InvalidFragment);
            }
            Some(Fragment { index, count })
        } else {
            None
        };
        let known = body_length(id, input, players)?;
        let length = match known {
            Some(length) => length,
            None if single => input.len(),
            None => {
                let length = byte(&mut input)?;
                if length != 255 {
                    usize::from(length)
                } else {
                    let length = u16::from_le_bytes([byte(&mut input)?, byte(&mut input)?]);
                    if length < 255 {
                        return Err(Error::InvalidLength);
                    }
                    usize::from(length)
                }
            }
        };
        if known.is_none() && length < variable_minimum(id, fragment) {
            return Err(Error::InvalidLength);
        }
        if single && length != input.len() {
            return Err(Error::InvalidLength);
        }
        let body = input.get(..length).ok_or(Error::Truncated)?;
        frames.push(Frame {
            id,
            unique_id,
            fragment,
            body,
        });
        input = &input[length..];
    }
    Ok(frames)
}

/// Serialize one frame. For bundles, concatenate encodings with `single=false`.
pub fn encode_frame(
    frame: Frame<'_>,
    single: bool,
    direction: Direction,
    players: u8,
) -> Result<Vec<u8>, Error> {
    validate_id(frame.id, direction)?;
    if has_unique_id(frame.id) != frame.unique_id.is_some() {
        return Err(Error::InvalidUniqueId);
    }
    if frame.id >= 0xfa && frame.fragment.is_some() {
        return Err(Error::InvalidFragment);
    }
    let known = body_length(frame.id, frame.body, players)?;
    // Retail's ED/EE length getter first requires room for at least two
    // inputs, even before counting mask bits. Use EB/EC for one input.
    if matches!(frame.id, 0xed | 0xee) {
        let time_bytes = if frame.id == 0xed { 1 } else { 2 };
        if frame.body.len() < time_bytes + usize::from(players).div_ceil(8) + 16 {
            return Err(Error::InvalidLength);
        }
    }
    if let Some(length) = known {
        if frame.body.len() != length {
            return Err(Error::InvalidLength);
        }
    } else if frame.body.len() < variable_minimum(frame.id, frame.fragment)
        || frame.body.len() > 65535
    {
        return Err(Error::InvalidLength);
    }
    let mut result = Vec::new();
    if frame.fragment.is_some() {
        result.push(0xff);
    }
    result.push(frame.id);
    if let Some(unique) = frame.unique_id {
        result.push(unique);
    }
    if let Some(fragment) = frame.fragment {
        if (fragment.index == 0) != fragment.count.is_some()
            || fragment.count == Some(0)
            || fragment.index == 255
        {
            return Err(Error::InvalidFragment);
        }
        result.push(fragment.index);
        if let Some(count) = fragment.count {
            result.push(count);
        }
    }
    if known.is_none() && !single {
        if frame.body.len() < 255 {
            result.push(frame.body.len() as u8);
        } else {
            result.push(255);
            result.extend_from_slice(&(frame.body.len() as u16).to_le_bytes());
        }
    }
    result.extend_from_slice(frame.body);
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn historical_snapshot_request_is_a_fixed_opt_in_server_message() {
        let frame = Frame {
            id: 0xf7,
            unique_id: None,
            fragment: None,
            body: &[50, 0, 0, 0],
        };
        assert!(encode_frame(frame, true, Direction::Server, 2).is_err());
        let bytes = encode_frame(frame, false, Direction::ServerSnapshots, 2).unwrap();
        assert_eq!(bytes, [0xf7, 50, 0, 0, 0]);
        assert_eq!(
            decode_frames(&bytes, false, Direction::ServerSnapshots, 2).unwrap(),
            [frame]
        );
        assert!(decode_frames(&bytes, true, Direction::ClientSnapshots, 2).is_err());
        assert!(decode_frames(&bytes[..4], true, Direction::ServerSnapshots, 2).is_err());
    }

    #[test]
    fn retail_machine_code_frames() {
        check_retail_frames(include_str!("fixtures/026g-frames.tsv"), false);
    }

    #[test]
    fn retail_machine_code_lobby_frames() {
        check_retail_frames(include_str!("fixtures/026g-lobby-frames.tsv"), true);
        for id in [0x86, 0xa7] {
            assert_eq!(
                decode_frames(&[id, 0, 1], true, Direction::LobbyServer, 0),
                Err(Error::UnknownMessage(id))
            );
        }
        assert!(decode_frames(&[0x4a, 0, 4], true, Direction::LobbyServer, 0).is_err());
        assert!(decode_frames(&[0xa1, 0, 0, 0, 0, 0], true, Direction::Server, 0).is_err());
        assert!(decode_frames(&[0x2e, 0, 0], false, Direction::LobbyClient, 0).is_err());
    }

    fn check_retail_frames(fixture: &str, lobby: bool) {
        for line in fixture.lines() {
            if line.starts_with('#') {
                continue;
            }
            let c: Vec<_> = line.split('\t').collect();
            let packet: Vec<u8> = (0..c[0].len())
                .step_by(2)
                .map(|i| u8::from_str_radix(&c[0][i..i + 2], 16).unwrap())
                .collect();
            let single = c[1] == "1";
            let direction = match (lobby, c[2] == "1") {
                (true, true) => Direction::LobbyServer,
                (true, false) => Direction::LobbyClient,
                (false, true) => Direction::Server,
                (false, false) => Direction::Client,
            };
            let players = c[3].parse().unwrap();
            let frames = decode_frames(&packet, single, direction, players).unwrap();
            assert_eq!(frames.len(), 1);
            let frame = frames[0];
            let flags = c[9].parse::<u8>().unwrap();
            // Retail stores the opcode itself in the buffer of low-level
            // messages. Our Frame consistently excludes the opcode from body.
            assert_eq!(
                frame.body.len() + usize::from(flags & 1),
                c[4].parse::<usize>().unwrap()
            );
            assert_eq!(frame.id, c[5].parse::<u8>().unwrap());
            let metadata = c[10].parse::<u8>().unwrap();
            assert_eq!(
                frame.unique_id,
                if metadata & 0x20 != 0 {
                    Some(c[6].parse().unwrap())
                } else {
                    None
                }
            );
            assert_eq!(
                frame.fragment,
                if flags & 2 != 0 {
                    let index = c[7].parse().unwrap();
                    Some(Fragment {
                        index,
                        count: if index == 0 {
                            Some(c[8].parse().unwrap())
                        } else {
                            None
                        },
                    })
                } else {
                    None
                }
            );
            assert_eq!(
                encode_frame(frame, single, direction, players).unwrap(),
                packet
            );
        }
    }

    #[test]
    fn snapshot_extension_is_opt_in_and_length_prefixed_in_bundles() {
        let mut payload = vec![0; 488];
        payload[..4].copy_from_slice(&50u32.to_le_bytes());
        payload[6..8].copy_from_slice(&480u16.to_le_bytes());
        let frame = Frame {
            id: 0xe2,
            unique_id: None,
            fragment: None,
            body: &payload,
        };
        assert_eq!(
            encode_frame(frame, true, Direction::Client, 1),
            Err(Error::UnknownMessage(0xe2))
        );
        let mut bundle = encode_frame(frame, false, Direction::ClientSnapshots, 1).unwrap();
        assert_eq!(&bundle[..4], &[0xe2, 0xff, 0xe8, 1]);
        bundle.push(0xda);
        let decoded = decode_frames(&bundle, false, Direction::ClientSnapshots, 1).unwrap();
        assert_eq!(decoded[0], frame);
        assert_eq!(decoded[1].id, 0xda);
        assert!(decode_frames(&[0xe2, 0], true, Direction::ClientSnapshots, 1).is_err());
    }

    #[test]
    fn fixed_client_messages_have_no_bundle_lengths() {
        let bytes = [0xda, 0xdf, 20, 0x78, 0x56, 0x34, 0x12, 0xe0];
        let frames = decode_frames(&bytes, false, Direction::Client, 0).unwrap();
        assert_eq!(
            frames
                .iter()
                .map(|f| (f.id, f.body.len()))
                .collect::<Vec<_>>(),
            [(0xda, 0), (0xdf, 5), (0xe0, 0)]
        );
        let encoded: Vec<_> = frames
            .into_iter()
            .flat_map(|f| encode_frame(f, false, Direction::Client, 0).unwrap())
            .collect();
        assert_eq!(encoded, bytes);
        assert_eq!(
            decode_frames(&bytes, true, Direction::Client, 0),
            Err(Error::InvalidLength)
        );
        assert_eq!(
            decode_frames(&[0xe2], true, Direction::Client, 0),
            Err(Error::UnknownMessage(0xe2))
        );
    }

    #[test]
    fn unique_fragment_metadata_precedes_variable_length() {
        let first = [0xff, 0xe4, 73, 0, 2, 3, 1, 2, 3, 0xf5, 8];
        let frames = decode_frames(&first, false, Direction::Server, 20).unwrap();
        assert_eq!(
            frames[0],
            Frame {
                id: 0xe4,
                unique_id: Some(73),
                fragment: Some(Fragment {
                    index: 0,
                    count: Some(2)
                }),
                body: &[1, 2, 3]
            }
        );
        assert_eq!(frames[1].body, [8]);
        let second = [0xff, 0xe4, 73, 1, 4, 5, 6];
        let frames = decode_frames(&second, true, Direction::Server, 20).unwrap();
        assert_eq!(
            frames[0].fragment,
            Some(Fragment {
                index: 1,
                count: None
            })
        );
        assert_eq!(frames[0].body, [4, 5, 6]);
        assert_eq!(
            encode_frame(frames[0], true, Direction::Server, 20).unwrap(),
            second
        );
    }

    #[test]
    fn extended_lengths_and_negotiated_input_batches() {
        let body = [42; 255];
        let bytes = encode_frame(
            Frame {
                id: 0xf6,
                unique_id: Some(1),
                fragment: None,
                body: &body,
            },
            false,
            Direction::Server,
            20,
        )
        .unwrap();
        assert_eq!(&bytes[..5], [0xf6, 1, 255, 255, 0]);
        assert_eq!(
            decode_frames(&bytes, false, Direction::Server, 20).unwrap()[0].body,
            body
        );
        for id in [0xed, 0xee] {
            let mut batch = vec![id, 12];
            if id == 0xee {
                batch.push(49);
            }
            batch.extend_from_slice(&[1, 0, 8]); // players 0 and 19
            batch.extend_from_slice(&[0; 16]);
            batch.extend_from_slice(&[0xf5, 2]);
            let frames = decode_frames(&batch, false, Direction::Server, 20).unwrap();
            assert_eq!(frames.len(), 2);
            assert_eq!(frames[1].id, 0xf5);
            assert_eq!(
                decode_frames(&batch, false, Direction::Server, 19),
                Err(Error::InvalidPlayerMask)
            );
        }
        let one_input = [12, 1, 0, 0, 0, 0, 0, 0, 0, 0];
        assert_eq!(
            encode_frame(
                Frame {
                    id: 0xed,
                    unique_id: None,
                    fragment: None,
                    body: &one_input
                },
                true,
                Direction::Server,
                8
            ),
            Err(Error::InvalidLength)
        );
    }

    #[test]
    fn rejects_truncated_or_ambiguous_frames() {
        for bytes in [&[][..], &[0xff], &[0xe4], &[0xff, 0xe4, 0, 0], &[0xdc, 0]] {
            assert!(decode_frames(bytes, true, Direction::Server, 20).is_err());
        }
        assert_eq!(
            decode_frames(&[0xfa, 0], false, Direction::Server, 20),
            Err(Error::InvalidLength)
        );
        assert_eq!(
            decode_frames(&[0xe4, 0, 255, 1, 0, 42], false, Direction::Server, 20),
            Err(Error::InvalidLength)
        );
    }
}
