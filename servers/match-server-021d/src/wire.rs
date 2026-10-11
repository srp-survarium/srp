// SPDX-License-Identifier: GPL-3.0-or-later
//! v0.21d framing, separate from the older SRP and v0.26 protocols.
//!
//! Header: fill_packet_header VA 0x28b887 / process_incoming_packet 0x28797d.
//! Message metadata: get_sending_message_info 0x1a144c and
//! get_received_message_info 0x1a14b4. PDB udp_match_packet owns 520 raw bytes.
//! This is a storage bound, not a claim that retail emits 520-byte datagrams.

use std::fmt;

pub const MAX_DATAGRAM: usize = 520;
pub const HEADER_BYTES: usize = 12;
const NEWEST_ACK: u64 = 1 << 63;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Direction {
    ClientToServer,
    ServerToClient,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Error {
    Truncated,
    TooLarge,
    EmptyMessage,
    UnknownOpcode(u8),
    InvalidOrdering,
    InvalidFragment,
    InvalidAcknowledgement,
    InvalidBundle,
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "v0.21d wire error: {self:?}")
    }
}
impl std::error::Error for Error {}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Delivery {
    pub reliable: bool,
    pub ordered: bool,
    pub channel: u8,
    pub resend_ms: u16,
    pub resend_deviation_ms: u8,
}

/// Application metadata, as viewed in the client binary, plus the explicit
/// SRP1 DLL upload opcode 0x48 (same delivery policy as 0x47). Low-level controls
/// have separate handling and are deliberately excluded from this table.
pub fn delivery(direction: Direction, opcode: u8) -> Result<Delivery, Error> {
    let (flags, resend_ms, resend_deviation_ms) = match (direction, opcode) {
        (Direction::ClientToServer, 0x40..=0x43 | 0x47 | 0x48)
        | (Direction::ServerToClient, 0x50) => (0x7f, 500, 200),
        (Direction::ClientToServer, 0x44 | 0x46) => (0x3f, u16::MAX, 255),
        (Direction::ClientToServer, 0x45) | (Direction::ServerToClient, 0x54 | 0x56..=0x58) => {
            (0x7f, 200, 0)
        }
        (Direction::ServerToClient, 0x51..=0x53 | 0x55 | 0x59) => (0xc0, 500, 200),
        _ => return Err(Error::UnknownOpcode(opcode)),
    };
    Ok(Delivery {
        reliable: flags & 0x40 != 0,
        ordered: flags & 0x80 != 0,
        channel: flags & 0x3f,
        resend_ms,
        resend_deviation_ms,
    })
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Header {
    pub sequence: u16,
    pub ack_sequence: u16,
    /// Bit 63 acknowledges ack_sequence; bit 62 its predecessor, etc.
    /// Bit 63 is implicit on the wire. Before any receive, the original
    /// protocol uses ack_sequence = 0xffff; it has no explicit absent-ack bit.
    pub ack_mask: u64,
    pub multiple: bool,
}

impl Header {
    pub fn decode(data: &[u8]) -> Result<(Self, &[u8]), Error> {
        if data.len() > MAX_DATAGRAM {
            return Err(Error::TooLarge);
        }
        let mut reader = Reader(data);
        let sequence = reader.u16()?;
        let ack_sequence = reader.u16()?;
        let word = u64::from_le_bytes(reader.take(8)?.try_into().unwrap());
        Ok((
            Self {
                sequence,
                ack_sequence,
                ack_mask: (word >> 1) | NEWEST_ACK,
                multiple: word & 1 != 0,
            },
            reader.0,
        ))
    }

    pub fn acknowledges(self, sequence: u16) -> bool {
        let age = self.ack_sequence.wrapping_sub(sequence);
        age < 64 && self.ack_mask & (NEWEST_ACK >> age) != 0
    }

    pub fn encode(self, payload: &[u8]) -> Result<Vec<u8>, Error> {
        if self.ack_mask & NEWEST_ACK == 0 {
            return Err(Error::InvalidAcknowledgement);
        }
        if payload.is_empty() {
            return Err(Error::EmptyMessage);
        }
        if payload.len() > MAX_DATAGRAM - HEADER_BYTES {
            return Err(Error::TooLarge);
        }
        let mut data = Vec::with_capacity(HEADER_BYTES + payload.len());
        data.extend(self.sequence.to_le_bytes());
        data.extend(self.ack_sequence.to_le_bytes());
        data.extend(((self.ack_mask << 1) | u64::from(self.multiple)).to_le_bytes());
        data.extend_from_slice(payload);
        Ok(data)
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Frame<'a> {
    Control {
        opcode: u8,
        body: &'a [u8],
    },
    Message {
        opcode: u8,
        order: Option<u16>,
        body: &'a [u8],
    },
    /// Transport fragmentation, distinct from client 0x47 snapshot chunks.
    Fragment {
        opcode: u8,
        order: u16,
        index: u8,
        /// Present only in fragment zero; includes fragment zero itself.
        count: Option<u8>,
        body: &'a [u8],
    },
}

impl<'a> Frame<'a> {
    pub fn opcode(self) -> u8 {
        match self {
            Self::Control { opcode, .. }
            | Self::Message { opcode, .. }
            | Self::Fragment { opcode, .. } => opcode,
        }
    }

    pub fn decode(direction: Direction, data: &'a [u8]) -> Result<Self, Error> {
        let mut reader = Reader(data);
        let opcode = reader.u8()?;
        if opcode <= 2 {
            if !reader.0.is_empty() {
                return Err(Error::InvalidBundle);
            }
            return Ok(Self::Control {
                opcode,
                body: reader.0,
            });
        }
        if opcode == 0xff {
            let opcode = reader.u8()?;
            if !delivery(direction, opcode)?.ordered {
                return Err(Error::InvalidFragment);
            }
            let order = reader.u16()?;
            let index = reader.u8()?;
            let count = if index == 0 {
                let count = reader.u8()?;
                if count == 0 {
                    return Err(Error::InvalidFragment);
                }
                Some(count)
            } else {
                None
            };
            if reader.0.is_empty() {
                return Err(Error::InvalidFragment);
            }
            return Ok(Self::Fragment {
                opcode,
                order,
                index,
                count,
                body: reader.0,
            });
        }
        let order = if delivery(direction, opcode)?.ordered {
            Some(reader.u16()?)
        } else {
            None
        };
        Ok(Self::Message {
            opcode,
            order,
            body: reader.0,
        })
    }

    pub fn encode(self, direction: Direction) -> Result<Vec<u8>, Error> {
        let (overhead, body_len) = match self {
            Self::Control { body, .. } => (1, body.len()),
            Self::Message { order, body, .. } => (1 + 2 * usize::from(order.is_some()), body.len()),
            Self::Fragment { count, body, .. } => (5 + usize::from(count.is_some()), body.len()),
        };
        if body_len > MAX_DATAGRAM - HEADER_BYTES - overhead {
            return Err(Error::TooLarge);
        }
        let mut data = Vec::new();
        match self {
            Self::Control { opcode, body } => {
                if opcode > 2 {
                    return Err(Error::UnknownOpcode(opcode));
                }
                if !body.is_empty() {
                    return Err(Error::InvalidBundle);
                }
                data.push(opcode);
                data.extend_from_slice(body);
            }
            Self::Message {
                opcode,
                order,
                body,
            } => {
                if delivery(direction, opcode)?.ordered != order.is_some() {
                    return Err(Error::InvalidOrdering);
                }
                data.push(opcode);
                if let Some(order) = order {
                    data.extend(order.to_le_bytes());
                }
                data.extend_from_slice(body);
            }
            Self::Fragment {
                opcode,
                order,
                index,
                count,
                body,
            } => {
                if !delivery(direction, opcode)?.ordered
                    || body.is_empty()
                    || (index == 0) != count.is_some()
                    || count == Some(0)
                {
                    return Err(Error::InvalidFragment);
                }
                data.extend([0xff, opcode]);
                data.extend(order.to_le_bytes());
                data.push(index);
                if let Some(count) = count {
                    data.push(count);
                }
                data.extend_from_slice(body);
            }
        }
        if data.len() > MAX_DATAGRAM - HEADER_BYTES {
            return Err(Error::TooLarge);
        }
        Ok(data)
    }
}

pub fn decode(direction: Direction, data: &[u8]) -> Result<(Header, Vec<Frame<'_>>), Error> {
    let (header, payload) = Header::decode(data)?;
    if payload.is_empty() {
        return Err(Error::EmptyMessage);
    }
    if !header.multiple {
        let frames = vec![Frame::decode(direction, payload)?];
        validate_framing(header, &frames)?;
        return Ok((header, frames));
    }
    let mut reader = Reader(payload);
    let mut frames = Vec::new();
    while !reader.0.is_empty() {
        let short_length = reader.u8()?;
        let length = if short_length == 0 {
            reader.u16()? as usize
        } else {
            short_length as usize
        };
        if length == 0 {
            return Err(Error::EmptyMessage);
        }
        frames.push(Frame::decode(direction, reader.take(length)?)?);
    }
    validate_framing(header, &frames)?;
    Ok((header, frames))
}

// VA 0x287c7e..0x287ca4: exactly one length-prefixed frame dispatches to
// process_low_level_message. Ordinary application frames use the other path.
fn validate_framing(header: Header, frames: &[Frame<'_>]) -> Result<(), Error> {
    if frames.is_empty() || (!header.multiple && frames.len() != 1) {
        return Err(Error::InvalidBundle);
    }
    let control = frames.iter().any(|f| matches!(f, Frame::Control { .. }));
    if control != (header.multiple && frames.len() == 1) {
        return Err(Error::InvalidBundle);
    }
    Ok(())
}

/// A single length-prefixed frame is reserved for low-level controls. Ordinary
/// messages are unbundled singles or bundles containing at least two frames.
pub fn encode(
    direction: Direction,
    header: Header,
    frames: &[Frame<'_>],
) -> Result<Vec<u8>, Error> {
    validate_framing(header, frames)?;
    let mut payload = Vec::new();
    for frame in frames {
        let message = frame.encode(direction)?;
        if header.multiple {
            if message.len() < 256 {
                payload.push(message.len() as u8);
            } else {
                payload.push(0);
                payload.extend((message.len() as u16).to_le_bytes());
            }
        }
        if payload.len() + message.len() > MAX_DATAGRAM - HEADER_BYTES {
            return Err(Error::TooLarge);
        }
        payload.extend(message);
    }
    header.encode(&payload)
}

pub(crate) struct Reader<'a>(pub(crate) &'a [u8]);
impl<'a> Reader<'a> {
    pub(crate) fn take(&mut self, size: usize) -> Result<&'a [u8], Error> {
        if self.0.len() < size {
            return Err(Error::Truncated);
        }
        let (value, rest) = self.0.split_at(size);
        self.0 = rest;
        Ok(value)
    }
    pub(crate) fn u8(&mut self) -> Result<u8, Error> {
        Ok(self.take(1)?[0])
    }
    pub(crate) fn u16(&mut self) -> Result<u16, Error> {
        Ok(u16::from_le_bytes(self.take(2)?.try_into().unwrap()))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn header(multiple: bool) -> Header {
        Header {
            sequence: 0,
            ack_sequence: 0xffff,
            ack_mask: NEWEST_ACK,
            multiple,
        }
    }

    #[test]
    fn captured_input_datagram() {
        // First unbundled outgoing 0x45 in the 2026-10-11 capture. Contains
        // only input/time and transport counters, no profile or session data.
        let bytes = [
            0x7f, 0, 0x16, 1, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x45, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 0, 0, 0, 0xa8, 0x2f, 0, 0,
        ];
        let (h, frames) = decode(Direction::ClientToServer, &bytes).unwrap();
        assert_eq!(h.sequence, 127);
        assert_eq!(h.ack_sequence, 278);
        assert_eq!(h.ack_mask, u64::MAX);
        assert!(!h.multiple);
        assert_eq!(
            frames,
            [Frame::Message {
                opcode: 0x45,
                order: None,
                body: &bytes[13..]
            }]
        );
        assert_eq!(
            encode(Direction::ClientToServer, h, &frames).unwrap(),
            bytes
        );
    }

    #[test]
    fn ack_bit_positions_and_sequence_wrap() {
        // Byte mapping follows the retail writer's 64-bit shift, independently
        // of encode/decode round trips: previous receive occupies wire bit 63.
        let h = Header {
            ack_sequence: 0,
            ack_mask: NEWEST_ACK | (NEWEST_ACK >> 1) | 1,
            ..header(false)
        };
        let bytes = h.encode(&[2]).unwrap();
        assert_eq!(&bytes[4..12], &[2, 0, 0, 0, 0, 0, 0, 0x80]);
        assert!(h.acknowledges(0));
        assert!(h.acknowledges(65535));
        assert!(h.acknowledges(65536u32.wrapping_sub(63) as u16));
        assert!(!h.acknowledges(65534));
        assert!(!h.acknowledges(65536u32.wrapping_sub(64) as u16));
        assert!(!h.acknowledges(1));
    }

    #[test]
    fn ordered_messages_share_channel_zero_but_inputs_do_not() {
        for opcode in [0x51, 0x52, 0x53, 0x55, 0x59] {
            let d = delivery(Direction::ServerToClient, opcode).unwrap();
            assert!(d.reliable && d.ordered);
            assert_eq!(d.channel, 0);
        }
        for opcode in [0x54, 0x56, 0x57, 0x58] {
            let d = delivery(Direction::ServerToClient, opcode).unwrap();
            assert!(d.reliable && !d.ordered);
            assert_eq!(d.resend_ms, 200);
        }
        for opcode in [0x44, 0x46] {
            assert!(
                !delivery(Direction::ClientToServer, opcode)
                    .unwrap()
                    .reliable
            );
        }
        assert_eq!(
            delivery(Direction::ServerToClient, 0x89),
            Err(Error::UnknownOpcode(0x89))
        );
    }

    #[test]
    fn fragment_inside_bundle_and_extended_length() {
        let body = [0x33; 260];
        let frames = [
            Frame::Message {
                opcode: 0x59,
                order: Some(8),
                body: &[],
            },
            Frame::Fragment {
                opcode: 0x53,
                order: 7,
                index: 0,
                count: Some(2),
                body: &body,
            },
        ];
        let packet = encode(Direction::ServerToClient, header(true), &frames).unwrap();
        assert_eq!(&packet[12..19], &[3, 0x59, 8, 0, 0, 10, 1]); // length 266 encoded as u16
        assert_eq!(
            decode(Direction::ServerToClient, &packet).unwrap().1,
            frames
        );
    }

    #[test]
    fn low_level_dispatch_requires_a_single_length_prefixed_control() {
        let control = Frame::Control {
            opcode: 2,
            body: &[],
        };
        let application = Frame::Message {
            opcode: 0x59,
            order: Some(0),
            body: &[],
        };
        let d = Direction::ServerToClient;
        let bytes = encode(d, header(true), &[control]).unwrap();
        assert_eq!(&bytes[12..], &[1, 2]); // captured heartbeat framing
        assert_eq!(decode(d, &bytes).unwrap().1, [control]);
        assert_eq!(
            encode(d, header(false), &[control]),
            Err(Error::InvalidBundle)
        );
        assert_eq!(
            encode(d, header(true), &[application]),
            Err(Error::InvalidBundle)
        );
        assert_eq!(
            encode(d, header(true), &[control, application]),
            Err(Error::InvalidBundle)
        );
        assert_eq!(
            decode(d, &header(false).encode(&[2]).unwrap()),
            Err(Error::InvalidBundle)
        );
    }

    #[test]
    fn malformed_frames_are_errors() {
        for size in 0..HEADER_BYTES {
            assert_eq!(Header::decode(&vec![0; size]), Err(Error::Truncated));
        }
        assert_eq!(Header::decode(&[0; MAX_DATAGRAM + 1]), Err(Error::TooLarge));
        let d = Direction::ServerToClient;
        for bad in [
            &[0x53][..],
            &[0xff, 0x53, 0, 0, 0],
            &[0xff, 0x53, 0, 0, 0, 0, 1],
            &[0xff, 0x54, 0, 0, 0, 1, 1],
        ] {
            assert!(Frame::decode(d, bad).is_err());
        }
        for bad in [&[0][..], &[0, 0], &[0, 0, 0], &[5, 2]] {
            let bytes = header(true).encode(bad).unwrap();
            assert!(decode(d, &bytes).is_err());
        }
        assert_eq!(
            Frame::Message {
                opcode: 0x53,
                order: None,
                body: &[0]
            }
            .encode(d),
            Err(Error::InvalidOrdering)
        );
    }
}
