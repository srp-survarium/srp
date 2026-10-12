// SPDX-License-Identifier: GPL-3.0-or-later

use crate::{
    Error, FRAGMENT_TIMEOUT_MS, MAX_DATAGRAM, MAX_FRAMES, MAX_MESSAGE, MAX_PARTS, Players, Result,
    reader::Reader,
};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Channel {
    Lobby,
    Match,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Opcode(u8);
impl Opcode {
    pub fn new(value: u8, channel: Channel) -> Result<Self> {
        let allowed = matches!(value, 0xfa..=0xfd)
            || match channel {
                Channel::Lobby => matches!(value, 0x80..=0x85 | 0x87..=0xa6 | 0xa8..=0xaa),
                Channel::Match => matches!(value, 0xe3..=0xf6),
            };
        if allowed {
            Ok(Self(value))
        } else {
            Err(Error::Unsupported)
        }
    }
    pub const fn get(self) -> u8 {
        self.0
    }
    pub fn has_delivery(self, channel: Channel) -> bool {
        self.0 < 0xfa
            && match channel {
                Channel::Lobby => self.0 != 0x9f,
                Channel::Match => matches!(self.0, 0xe4..=0xe8 | 0xf6),
            }
    }
}

#[derive(Clone, Copy, Debug)]
pub struct Header<'a> {
    pub sequence: u8,
    pub acknowledgement: u8,
    pub single: bool,
    pub payload: &'a [u8],
}
pub fn header(bytes: &[u8]) -> Result<Header<'_>> {
    if bytes.len() > MAX_DATAGRAM {
        return Err(Error::Limit);
    }
    if bytes.len() < 4 {
        return Err(Error::Truncated);
    }
    let mut end = bytes.len();
    let mut bits = 1;
    let mut control = bytes[2];
    while control & 128 != 0 {
        if bits > 120 {
            return Err(Error::Limit);
        }
        bits += 7;
        if end <= 3 {
            return Err(Error::Truncated);
        }
        end -= 1;
        control = bytes[end];
    }
    if bits > 122 && control >> 1 != 0 {
        return Err(Error::Invalid);
    }
    if end == 3 {
        return Err(Error::Truncated);
    }
    Ok(Header {
        sequence: bytes[0],
        acknowledgement: bytes[1],
        single: control & 1 == 0,
        payload: &bytes[3..end],
    })
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Fragment {
    pub index: u8,
    pub count: Option<u8>,
}
#[derive(Clone, Copy, Debug)]
pub struct Frame<'a> {
    pub opcode: Opcode,
    pub delivery: Option<u8>,
    pub fragment: Option<Fragment>,
    pub body: &'a [u8],
}
pub(crate) fn fixed_length(op: Opcode, channel: Channel) -> Option<usize> {
    if op.0 >= 0xfa {
        return Some(0);
    }
    if channel == Channel::Lobby {
        return None;
    }
    match op.0 {
        0xe3 | 0xe6 | 0xf0 => Some(4),
        0xe5 => Some(7),
        0xe7 | 0xe9 | 0xea | 0xef | 0xf2 | 0xf4 => Some(2),
        0xeb => Some(10),
        0xec => Some(11),
        0xf1 | 0xf5 => Some(1),
        0xf3 => Some(3),
        _ => None,
    }
}
fn batch_length(op: Opcode, bytes: &[u8], players: Option<Players>) -> Result<usize> {
    let players = players.ok_or(Error::Invalid)?;
    let mut r = Reader::new(bytes);
    let time = if op.0 == 0xed { 1 } else { 2 };
    r.take(time)?;
    let mask_bytes = usize::from(players.get()).div_ceil(8);
    let mut mask = 0;
    for i in 0..mask_bytes {
        mask |= u32::from(r.byte()?) << (8 * i);
    }
    players.validate_mask(mask)?;
    // The native batch handler reads the first two inputs unconditionally.
    if mask.count_ones() < 2 {
        return Err(Error::Invalid);
    }
    Ok(time + mask_bytes + 8 * mask.count_ones() as usize)
}
pub fn fixed_body(op: Opcode, bytes: &[u8], players: Option<Players>) -> Result<()> {
    let length = if matches!(op.0, 0xed | 0xee) {
        batch_length(op, bytes, players)?
    } else {
        fixed_length(op, Channel::Match).ok_or(Error::Unsupported)?
    };
    if length == bytes.len() {
        Ok(())
    } else {
        Err(Error::Invalid)
    }
}
fn one<'a>(
    r: &mut Reader<'a>,
    single: bool,
    channel: Channel,
    players: Option<Players>,
) -> Result<Frame<'a>> {
    let first = r.byte()?;
    let fragmented = first == 255;
    let op = Opcode::new(if fragmented { r.byte()? } else { first }, channel)?;
    if op.0 >= 0xfa && (fragmented || !r.remaining().is_empty()) {
        return Err(Error::Invalid);
    }
    let delivery = if op.has_delivery(channel) {
        Some(r.byte()?)
    } else {
        None
    };
    let fixed = fixed_length(op, channel);
    let fragment = if fragmented {
        if fixed.is_some() || delivery.is_none() || matches!(op.0, 0xed | 0xee) {
            return Err(Error::Invalid);
        }
        let index = r.byte()?;
        let count = if index == 0 { Some(r.byte()?) } else { None };
        if index == 255 || count == Some(0) {
            return Err(Error::Invalid);
        }
        Some(Fragment { index, count })
    } else {
        None
    };
    let length = if matches!(op.0, 0xed | 0xee) {
        batch_length(op, r.remaining(), players)?
    } else if let Some(n) = fixed {
        n
    } else if single {
        r.remaining().len()
    } else {
        let n = r.byte()?;
        if n == 255 {
            let n = usize::from(r.u16()?);
            if n < 255 {
                return Err(Error::Invalid);
            }
            n
        } else {
            usize::from(n)
        }
    };
    if fixed.is_none() && length == 0 {
        return Err(Error::Invalid);
    }
    if single && length != r.remaining().len() {
        return Err(Error::Invalid);
    }
    Ok(Frame {
        opcode: op,
        delivery,
        fragment,
        body: r.take(length)?,
    })
}

/// Successfully parsed TRANSPORT frames. Bodies still require application checks.
pub struct Frames<'a> {
    reader: Reader<'a>,
    single: bool,
    channel: Channel,
    players: Option<Players>,
    left: usize,
}
impl Frames<'_> {
    pub fn count_remaining(&self) -> usize {
        self.left
    }
}
impl<'a> Iterator for Frames<'a> {
    type Item = Frame<'a>;
    fn next(&mut self) -> Option<Self::Item> {
        if self.left == 0 {
            return None;
        }
        // The immutable bytes and metadata were already checked by frames().
        let value = one(&mut self.reader, self.single, self.channel, self.players)
            .expect("validated immutable frame batch");
        self.left -= 1;
        Some(value)
    }
}
pub fn frames(
    bytes: &[u8],
    single: bool,
    channel: Channel,
    players: Option<Players>,
) -> Result<Frames<'_>> {
    if bytes.is_empty() {
        return Err(Error::Truncated);
    }
    if bytes.len() > MAX_DATAGRAM {
        return Err(Error::Limit);
    }
    let mut r = Reader::new(bytes);
    let mut count = 0;
    while !r.remaining().is_empty() {
        one(&mut r, single, channel, players)?;
        count += 1;
        if count > MAX_FRAMES {
            return Err(Error::Limit);
        }
    }
    Ok(Frames {
        reader: Reader::new(bytes),
        single,
        channel,
        players,
        left: count,
    })
}

/// Bounded storage, one per active delivery identity and connection generation.
/// The field representation consists solely of integers and byte arrays, and
/// all-zero bytes are a valid reset state (used by the C adapter initializer).
#[repr(C)]
pub struct Reassembly {
    started: u32,
    total: u32,
    lengths: [u16; MAX_PARTS],
    active: u8,
    opcode: u8,
    delivery: u8,
    count: u8,
    received: u8,
    data: [u8; MAX_MESSAGE],
}
impl Default for Reassembly {
    fn default() -> Self {
        Self::new()
    }
}
impl Reassembly {
    pub const fn new() -> Self {
        Self {
            started: 0,
            total: 0,
            lengths: [0; MAX_PARTS],
            active: 0,
            opcode: 0,
            delivery: 0,
            count: 0,
            received: 0,
            data: [0; MAX_MESSAGE],
        }
    }
    pub fn reset(&mut self) {
        self.active = 0;
        self.total = 0;
        self.received = 0;
        self.count = 0;
        self.lengths.fill(0);
    }
    pub fn feed<'a>(&'a mut self, frame: Frame<'_>, now: u32) -> Result<Option<Frame<'a>>> {
        let part = frame.fragment.ok_or(Error::Invalid)?;
        let delivery = frame.delivery.ok_or(Error::Invalid)?;
        let channel = if frame.opcode.get() < 0xe3 {
            Channel::Lobby
        } else {
            Channel::Match
        };
        if !frame.opcode.has_delivery(channel) || fixed_length(frame.opcode, channel).is_some() {
            return Err(Error::Invalid);
        }
        if frame.body.is_empty() || frame.body.len() > MAX_DATAGRAM || part.index == 255 {
            return Err(Error::Invalid);
        }
        if self.active != 0 && now.wrapping_sub(self.started) >= FRAGMENT_TIMEOUT_MS {
            self.reset();
            return Err(Error::Expired);
        }
        if self.active == 0 {
            if part.index != 0 {
                return Ok(None);
            }
            let count = part.count.filter(|n| *n != 0).ok_or(Error::Invalid)?;
            self.reset();
            self.active = 1;
            self.started = now;
            self.opcode = frame.opcode.0;
            self.delivery = delivery;
            self.count = count;
        }
        if frame.opcode.0 != self.opcode
            || delivery != self.delivery
            || part.index >= self.count
            || (part.index == 0 && part.count != Some(self.count))
            || (part.index != 0 && part.count.is_some())
        {
            self.reset();
            return Err(Error::FragmentConflict);
        }
        let index = usize::from(part.index);
        let start = index * MAX_DATAGRAM;
        let old = usize::from(self.lengths[index]);
        if old != 0 {
            if old != frame.body.len() || &self.data[start..start + old] != frame.body {
                self.reset();
                return Err(Error::FragmentConflict);
            }
            return Ok(None);
        }
        if frame.body.len() > MAX_MESSAGE - self.total as usize {
            self.reset();
            return Err(Error::Limit);
        }
        self.data[start..start + frame.body.len()].copy_from_slice(frame.body);
        self.lengths[index] = frame.body.len() as u16;
        self.total += frame.body.len() as u32;
        self.received += 1;
        if self.received != self.count {
            return Ok(None);
        }
        let mut dest = 0;
        for i in 0..usize::from(self.count) {
            let length = usize::from(self.lengths[i]);
            self.data
                .copy_within(i * MAX_DATAGRAM..i * MAX_DATAGRAM + length, dest);
            dest += length;
        }
        self.active = 0;
        Ok(Some(Frame {
            opcode: frame.opcode,
            delivery: Some(delivery),
            fragment: None,
            body: &self.data[..dest],
        }))
    }
}
