// SPDX-License-Identifier: GPL-3.0-or-later
//! v0.21d per-peer transport. No sockets, simulation, or wall clock hidden here.
//!
//! Ordered channel starts at zero (retail channel constructor VA 0x28b268).
//! Retries use fresh datagram sequences and retain message order/fragment IDs;
//! udp_match_packet::sequence_ids retains eight attempts in the original.
//! Unordered reliable messages have no identity on the wire: applications must
//! handle duplicate inputs/events by their simulation timestamp, not by payload
//! equality alone. Queue sizes, heartbeat interval and timeout are SRP policy.

use crate::wire::{self, Direction, Frame, Header};
use std::{
    collections::{BTreeMap, VecDeque},
    fmt,
};

pub const MAX_MESSAGE: usize = 32 * 1024;
const MAX_BUFFERED_BYTES: usize = 256 * 1024;
const MAX_ORDER_AHEAD: u16 = 64;
const MAX_PENDING: usize = 2048;
const TIMEOUT_MS: u64 = 10_000;
const HEARTBEAT_MS: u64 = 100;
const ACK_DELAY_MS: u64 = 10;
// Conservative sender size, no larger than the captured server's datagrams.
const SEND_BYTES: usize = 508;
const FRAGMENT_BYTES: usize = 480;
const NEWEST: u64 = 1 << 63;

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Error {
    Wire(wire::Error),
    QueueFull,
    MessageTooLarge,
    ConflictingMessage,
    InvalidFragment,
    OrderTooFar,
    TimedOut,
}
impl From<wire::Error> for Error {
    fn from(error: wire::Error) -> Self {
        Self::Wire(error)
    }
}
impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "v0.21d transport: {self:?}")
    }
}
impl std::error::Error for Error {}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Message {
    pub opcode: u8,
    pub body: Vec<u8>,
}

#[derive(Debug, Default, Clone)]
pub struct ReceiveWindow {
    newest: Option<u16>,
    mask: u64,
}
impl ReceiveWindow {
    /// Returns false for duplicates or datagrams outside the retained window.
    pub fn insert(&mut self, sequence: u16) -> bool {
        let Some(newest) = self.newest else {
            self.newest = Some(sequence);
            self.mask = NEWEST;
            return true;
        };
        let ahead = sequence.wrapping_sub(newest);
        if ahead != 0 && ahead < 0x8000 {
            self.mask = if ahead < 64 { self.mask >> ahead } else { 0 } | NEWEST;
            self.newest = Some(sequence);
            return true;
        }
        let age = newest.wrapping_sub(sequence);
        if age >= 64 {
            return false;
        }
        let bit = NEWEST >> age;
        let fresh = self.mask & bit == 0;
        self.mask |= bit;
        fresh
    }

    pub fn header(&self, sequence: u16, multiple: bool) -> Header {
        Header {
            sequence,
            ack_sequence: self.newest.unwrap_or(0xffff),
            ack_mask: self.mask | NEWEST,
            multiple,
        }
    }
}

#[derive(Debug)]
enum Contents {
    Whole(Vec<u8>),
    Parts {
        count: Option<u8>,
        parts: BTreeMap<u8, Vec<u8>>,
    },
}
#[derive(Debug)]
struct Buffered {
    opcode: u8,
    since: u64,
    bytes: usize,
    contents: Contents,
}
impl Buffered {
    fn complete(&self) -> bool {
        match &self.contents {
            Contents::Whole(_) => true,
            Contents::Parts {
                count: Some(count),
                parts,
            } => parts.len() == usize::from(*count),
            _ => false,
        }
    }
    fn into_message(self) -> Message {
        let body = match self.contents {
            Contents::Whole(body) => body,
            Contents::Parts { parts, .. } => parts.into_values().flatten().collect(),
        };
        Message {
            opcode: self.opcode,
            body,
        }
    }
}

#[derive(Debug, Default)]
pub struct OrderedReceiver {
    expected: u16,
    pending: BTreeMap<u16, Buffered>,
    bytes: usize,
}
impl OrderedReceiver {
    /// A failure is terminal for the peer. Never silently expire already-acked
    /// fragments: doing so loses data the sender is entitled to stop retrying.
    pub fn check_timeout(&self, now: u64) -> Result<(), Error> {
        if self
            .pending
            .values()
            .any(|p| now.saturating_sub(p.since) >= TIMEOUT_MS)
        {
            return Err(Error::TimedOut);
        }
        Ok(())
    }

    pub fn push(&mut self, frame: Frame<'_>, now: u64) -> Result<Vec<Message>, Error> {
        self.check_timeout(now)?;
        let (opcode, order, body) = match frame {
            Frame::Control { opcode, body }
            | Frame::Message {
                opcode,
                order: None,
                body,
            } => {
                if body.len() > MAX_MESSAGE {
                    return Err(Error::MessageTooLarge);
                }
                return Ok(vec![Message {
                    opcode,
                    body: body.to_vec(),
                }]);
            }
            Frame::Message {
                opcode,
                order: Some(order),
                body,
            }
            | Frame::Fragment {
                opcode,
                order,
                body,
                ..
            } => (opcode, order, body),
        };
        let ahead = order.wrapping_sub(self.expected);
        if ahead >= 0x8000 {
            return Ok(Vec::new());
        }
        if ahead >= MAX_ORDER_AHEAD {
            return Err(Error::OrderTooFar);
        }
        if body.len() > MAX_MESSAGE {
            return Err(Error::MessageTooLarge);
        }
        let newly_inserted = !self.pending.contains_key(&order);
        if newly_inserted {
            let contents = match frame {
                Frame::Fragment { .. } => Contents::Parts {
                    count: None,
                    parts: BTreeMap::new(),
                },
                _ => Contents::Whole(Vec::new()),
            };
            self.pending.insert(
                order,
                Buffered {
                    opcode,
                    since: now,
                    bytes: 0,
                    contents,
                },
            );
        }
        let entry = self.pending.get_mut(&order).unwrap();
        if entry.opcode != opcode {
            return Err(Error::ConflictingMessage);
        }
        let additional = match (&mut entry.contents, frame) {
            (Contents::Whole(previous), Frame::Message { .. }) => {
                // Empty bodies are valid but still immutable once received.
                if !newly_inserted && previous.as_slice() != body {
                    return Err(Error::ConflictingMessage);
                }
                if previous.as_slice() == body {
                    0
                } else {
                    if self.bytes + body.len() > MAX_BUFFERED_BYTES {
                        return Err(Error::QueueFull);
                    }
                    *previous = body.to_vec();
                    body.len()
                }
            }
            (
                Contents::Parts { count, parts },
                Frame::Fragment {
                    index,
                    count: incoming,
                    ..
                },
            ) => {
                if body.is_empty() || (index == 0) != incoming.is_some() || incoming == Some(0) {
                    return Err(Error::InvalidFragment);
                }
                if let Some(total) = incoming {
                    if count.is_some_and(|c| c != total) || parts.keys().any(|i| *i >= total) {
                        return Err(Error::ConflictingMessage);
                    }
                    *count = Some(total);
                }
                if count.is_some_and(|total| index >= total) {
                    return Err(Error::InvalidFragment);
                }
                if let Some(previous) = parts.get(&index) {
                    if previous.as_slice() != body {
                        return Err(Error::ConflictingMessage);
                    }
                    0
                } else {
                    if entry.bytes + body.len() > MAX_MESSAGE {
                        return Err(Error::MessageTooLarge);
                    }
                    if self.bytes + body.len() > MAX_BUFFERED_BYTES {
                        return Err(Error::QueueFull);
                    }
                    parts.insert(index, body.to_vec());
                    body.len()
                }
            }
            _ => return Err(Error::ConflictingMessage),
        };
        entry.bytes += additional;
        self.bytes += additional;
        let mut ready = Vec::new();
        while self
            .pending
            .get(&self.expected)
            .is_some_and(Buffered::complete)
        {
            let entry = self.pending.remove(&self.expected).unwrap();
            self.bytes -= entry.bytes;
            ready.push(entry.into_message());
            self.expected = self.expected.wrapping_add(1);
        }
        Ok(ready)
    }
}

#[derive(Debug)]
struct Pending {
    encoded: Vec<u8>,
    reliable: bool,
    retry_ms: u64,
    created: u64,
    due: u64,
    attempts: VecDeque<u64>,
}

#[derive(Debug)]
pub struct Endpoint {
    outgoing: Direction,
    receive: ReceiveWindow,
    ordered: OrderedReceiver,
    next_sequence: u64,
    next_order: u16,
    pending: VecDeque<Pending>,
    pending_bytes: usize,
    last_sent: u64,
    ack_needed: bool,
    sent_times: VecDeque<(u64, u64)>,
    rtt_samples: VecDeque<(u64, u64)>,
}
impl Endpoint {
    pub fn new(outgoing: Direction) -> Self {
        Self {
            outgoing,
            receive: ReceiveWindow::default(),
            ordered: OrderedReceiver::default(),
            next_sequence: 0,
            next_order: 0,
            pending: VecDeque::new(),
            pending_bytes: 0,
            last_sent: 0,
            ack_needed: false,
            sent_times: VecDeque::new(),
            rtt_samples: VecDeque::new(),
        }
    }

    pub fn pending_count(&self) -> usize {
        self.pending.len()
    }

    /// Recent minimum ACK RTT. Includes the receiver's ACK scheduling delay;
    /// it is not an exact propagation delay. Samples expire after five seconds.
    pub fn round_trip_ms(&self, now: u64) -> Option<u64> {
        self.rtt_samples
            .iter()
            .filter(|(received, _)| now.saturating_sub(*received) <= 5_000)
            .map(|(_, rtt)| *rtt)
            .min()
    }

    fn record_sent(&mut self, now: u64) {
        self.sent_times.push_back((self.next_sequence, now));
        if self.sent_times.len() > 256 {
            self.sent_times.pop_front();
        }
    }

    /// Match the application opcode, also behind the 0xff fragment marker.
    pub fn has_pending(&self, opcodes: &[u8]) -> bool {
        self.pending.iter().any(|p| {
            let opcode = p.encoded[usize::from(p.encoded[0] == 0xff)];
            opcodes.contains(&opcode)
        })
    }

    /// Enqueue atomically: insufficient capacity never leaves half a message
    /// queued, and never consumes an ordered ID without the corresponding data.
    pub fn send(&mut self, opcode: u8, body: &[u8], now: u64) -> Result<(), Error> {
        if body.len() > MAX_MESSAGE {
            return Err(Error::MessageTooLarge);
        }
        let meta = if opcode <= 2 {
            None
        } else {
            Some(wire::delivery(self.outgoing, opcode)?)
        };
        let order = meta.filter(|m| m.ordered).map(|_| self.next_order);
        let mut encoded = Vec::new();
        if body.len() + 1 + usize::from(order.is_some()) * 2 <= SEND_BYTES - wire::HEADER_BYTES {
            let frame = if opcode <= 2 {
                Frame::Control { opcode, body }
            } else {
                Frame::Message {
                    opcode,
                    order,
                    body,
                }
            };
            encoded.push(frame.encode(self.outgoing)?);
        } else {
            let order = order.ok_or(Error::MessageTooLarge)?;
            let count = body.len().div_ceil(FRAGMENT_BYTES) as u8;
            for (index, part) in body.chunks(FRAGMENT_BYTES).enumerate() {
                encoded.push(
                    Frame::Fragment {
                        opcode,
                        order,
                        index: index as u8,
                        count: (index == 0).then_some(count),
                        body: part,
                    }
                    .encode(self.outgoing)?,
                );
            }
        }
        let bytes = encoded.iter().map(Vec::len).sum::<usize>();
        if self.pending.len() + encoded.len() > MAX_PENDING
            || self.pending_bytes + bytes > MAX_BUFFERED_BYTES
        {
            return Err(Error::QueueFull);
        }
        if order.is_some() {
            self.next_order = self.next_order.wrapping_add(1);
        }
        self.pending_bytes += bytes;
        for encoded in encoded {
            self.pending.push_back(Pending {
                encoded,
                reliable: meta.is_some_and(|m| m.reliable),
                retry_ms: meta.map_or(0, |m| u64::from(m.resend_ms)),
                created: now,
                due: now,
                attempts: VecDeque::new(),
            });
        }
        Ok(())
    }

    /// Errors require discarding this endpoint; callers must not continue with
    /// partial ordered state after a conflicting fragment or capacity failure.
    pub fn receive(&mut self, data: &[u8], now: u64) -> Result<Vec<Message>, Error> {
        let direction = match self.outgoing {
            Direction::ClientToServer => Direction::ServerToClient,
            Direction::ServerToClient => Direction::ClientToServer,
        };
        let (header, frames) = wire::decode(direction, data)?;
        self.acknowledge(header, now);
        self.ack_needed = true;
        if !self.receive.insert(header.sequence) {
            return Ok(Vec::new());
        }
        let mut messages = Vec::new();
        for frame in frames {
            messages.extend(self.ordered.push(frame, now)?);
        }
        Ok(messages)
    }

    fn acknowledge(&mut self, header: Header, now: u64) {
        let Some(last_sent) = self.next_sequence.checked_sub(1) else {
            return;
        };
        let age = (last_sent as u16).wrapping_sub(header.ack_sequence);
        if age >= 0x8000 {
            return;
        } // future/ambiguous acknowledgment
        let Some(absolute_ack) = last_sent.checked_sub(u64::from(age)) else {
            return;
        };
        // A retry has its own datagram sequence. Measure the particular newly
        // acknowledged attempt, not the first send of its reliable message.
        let mut sample = None;
        self.sent_times.retain(|(sequence, sent)| {
            let acknowledged = absolute_ack
                .checked_sub(*sequence)
                .is_some_and(|age| age < 64 && header.ack_mask & (NEWEST >> age) != 0);
            if acknowledged {
                if let Some(elapsed) = now.checked_sub(*sent) {
                    sample = Some(elapsed); // Newest acknowledged send in this batch.
                }
            }
            !acknowledged && now.saturating_sub(*sent) <= TIMEOUT_MS
        });
        if let Some(sample) = sample {
            self.rtt_samples.push_back((now, sample));
            if self.rtt_samples.len() > 64 {
                self.rtt_samples.pop_front();
            }
        }
        self.pending.retain(|pending| {
            !pending.attempts.iter().any(|sent| {
                absolute_ack
                    .checked_sub(*sent)
                    .is_some_and(|age| age < 64 && header.ack_mask & (NEWEST >> age) != 0)
            })
        });
        self.pending_bytes = self.pending.iter().map(|p| p.encoded.len()).sum();
    }

    /// At most 64 datagrams per call. The socket adapter should poll regularly
    /// using elapsed monotonic milliseconds, and send returned datagrams in order.
    pub fn poll(&mut self, now: u64) -> Result<Vec<Vec<u8>>, Error> {
        self.ordered.check_timeout(now)?;
        if self
            .pending
            .iter()
            .any(|p| now.saturating_sub(p.created) >= TIMEOUT_MS)
        {
            return Err(Error::TimedOut);
        }
        let mut output = Vec::new();
        for _ in 0..64 {
            let mut indices = Vec::new();
            let mut size = 0;
            for (index, pending) in self.pending.iter().enumerate() {
                if pending.due > now {
                    continue;
                }
                let bytes = pending.encoded.len();
                let prefix = if bytes < 256 { 1 } else { 3 };
                // Controls must be alone in a one-frame bundle; that framing
                // selects the client's low-level dispatcher (VA 0x287c99).
                if pending.encoded[0] <= 2 && !indices.is_empty() {
                    break;
                }
                if !indices.is_empty() && size + prefix + bytes > SEND_BYTES - wire::HEADER_BYTES {
                    break;
                }
                indices.push(index);
                size += bytes + prefix;
                if pending.encoded[0] <= 2 {
                    break;
                }
            }
            if indices.is_empty() {
                break;
            }
            let multiple = indices.len() > 1 || self.pending[indices[0]].encoded[0] <= 2;
            let mut payload = Vec::new();
            for index in indices {
                let pending = &mut self.pending[index];
                if multiple {
                    if pending.encoded.len() < 256 {
                        payload.push(pending.encoded.len() as u8);
                    } else {
                        payload.push(0);
                        payload.extend((pending.encoded.len() as u16).to_le_bytes());
                    }
                }
                payload.extend_from_slice(&pending.encoded);
                pending.attempts.push_back(self.next_sequence);
                if pending.attempts.len() > 8 {
                    pending.attempts.pop_front();
                }
                pending.due = now.saturating_add(pending.retry_ms);
            }
            output.push(
                self.receive
                    .header(self.next_sequence as u16, multiple)
                    .encode(&payload)?,
            );
            self.record_sent(now);
            self.next_sequence += 1;
            self.pending.retain(|p| p.reliable || p.attempts.is_empty());
            self.pending_bytes = self.pending.iter().map(|p| p.encoded.len()).sum();
            self.last_sent = now;
            self.ack_needed = false;
        }
        if output.is_empty()
            && (now.saturating_sub(self.last_sent) >= HEARTBEAT_MS
                || (self.ack_needed && now.saturating_sub(self.last_sent) >= ACK_DELAY_MS))
        {
            output.push(
                self.receive
                    .header(self.next_sequence as u16, true)
                    .encode(&[1, 2])?,
            );
            self.record_sent(now);
            self.next_sequence += 1;
            self.last_sent = now;
            self.ack_needed = false;
        }
        Ok(output)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn ordered(order: u16, body: &[u8]) -> Frame<'_> {
        Frame::Message {
            opcode: 0x52,
            order: Some(order),
            body,
        }
    }

    #[test]
    fn receive_window_tracks_holes_duplicates_and_wrap() {
        let mut window = ReceiveWindow::default();
        assert!(window.insert(65534));
        assert!(window.insert(0));
        assert!(!window.header(0, false).acknowledges(65535));
        assert!(window.insert(65535));
        assert!(window.header(0, false).acknowledges(65535));
        assert!(!window.insert(65535));
        assert!(window.insert(70));
        assert!(!window.insert(0));
        assert!(!window.header(0, false).acknowledges(0));
    }

    #[test]
    fn fragments_can_arrive_before_zero_and_hold_later_orders() {
        let mut r = OrderedReceiver::default();
        assert!(r.push(ordered(1, b"next"), 0).unwrap().is_empty());
        let last = Frame::Fragment {
            opcode: 0x51,
            order: 0,
            index: 1,
            count: None,
            body: b"two",
        };
        assert!(r.push(last, 1).unwrap().is_empty());
        assert!(r.push(last, 2).unwrap().is_empty());
        let first = Frame::Fragment {
            opcode: 0x51,
            order: 0,
            index: 0,
            count: Some(2),
            body: b"one",
        };
        assert_eq!(
            r.push(first, 3).unwrap(),
            [
                Message {
                    opcode: 0x51,
                    body: b"onetwo".to_vec()
                },
                Message {
                    opcode: 0x52,
                    body: b"next".to_vec()
                }
            ]
        );
        assert!(r.push(first, 4).unwrap().is_empty());
        assert_eq!(r.bytes, 0);
    }

    #[test]
    fn conflicting_fragments_and_expired_order_gaps_fail() {
        let mut r = OrderedReceiver::default();
        let part = Frame::Fragment {
            opcode: 0x53,
            order: 0,
            index: 1,
            count: None,
            body: b"original",
        };
        r.push(part, 0).unwrap();
        assert_eq!(
            r.push(
                Frame::Fragment {
                    opcode: 0x53,
                    order: 0,
                    index: 1,
                    count: None,
                    body: b"changed"
                },
                1
            ),
            Err(Error::ConflictingMessage)
        );
        let mut r = OrderedReceiver::default();
        r.push(ordered(1, b"future"), 0).unwrap();
        assert_eq!(r.check_timeout(TIMEOUT_MS), Err(Error::TimedOut));
        // Timeout is terminal, rather than dropping acknowledged data and
        // waiting forever for a retransmission that will never be sent.
        assert_eq!(r.bytes, 6);
    }

    #[test]
    fn ordered_ids_wrap_and_far_future_is_bounded() {
        let mut r = OrderedReceiver {
            expected: 65535,
            ..Default::default()
        };
        r.push(ordered(0, b"new"), 0).unwrap();
        assert_eq!(r.push(ordered(65535, b"old"), 1).unwrap().len(), 2);
        assert_eq!(r.expected, 1);
        assert_eq!(r.push(ordered(65, b"too far"), 2), Err(Error::OrderTooFar));
    }

    #[test]
    fn empty_ordered_message_cannot_change_while_waiting_for_gap() {
        let mut r = OrderedReceiver::default();
        r.push(ordered(1, b""), 0).unwrap();
        assert_eq!(
            r.push(ordered(1, b"changed"), 1),
            Err(Error::ConflictingMessage)
        );
    }

    #[test]
    fn lost_fragment_retries_with_new_sequence_and_same_identity() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let mut client = Endpoint::new(Direction::ClientToServer);
        let body: Vec<u8> = (0..1500).map(|i| (i % 251) as u8).collect();
        server.send(0x53, &body, 0).unwrap();
        server.send(0x59, &[], 0).unwrap();
        let packets = server.poll(0).unwrap();
        assert_eq!(packets.len(), 4);
        // Lose the first fragment, deliver everything else backwards twice.
        for packet in packets[1..].iter().rev() {
            assert!(client.receive(packet, 10).unwrap().is_empty());
            assert!(client.receive(packet, 10).unwrap().is_empty());
        }
        for ack in client.poll(20).unwrap() {
            server.receive(&ack, 20).unwrap();
        }
        assert_eq!(server.pending_count(), 1);
        let retry = server.poll(500).unwrap();
        assert_eq!(retry.len(), 1);
        assert_ne!(
            Header::decode(&retry[0]).unwrap().0.sequence,
            Header::decode(&packets[0]).unwrap().0.sequence
        );
        assert_eq!(&retry[0][12..], &packets[0][12..]);
        let delivered = client.receive(&retry[0], 510).unwrap();
        assert_eq!(
            delivered,
            [
                Message { opcode: 0x53, body },
                Message {
                    opcode: 0x59,
                    body: vec![]
                }
            ]
        );
        for ack in client.poll(520).unwrap() {
            server.receive(&ack, 520).unwrap();
        }
        assert_eq!(server.pending_count(), 0);
    }

    #[test]
    fn replay_pending_status_is_independent_of_unacknowledged_state_fragments() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let mut client = Endpoint::new(Direction::ClientToServer);
        server.send(0x53, &[0; 1500], 0).unwrap();
        server.poll(0).unwrap(); // Lose every state fragment.
        assert!(server.has_pending(&[0x53]));
        assert!(!server.has_pending(&[0x54, 0x56, 0x57]));
        server.send(0x54, &[0; 17], 1).unwrap();
        assert!(server.has_pending(&[0x54, 0x56, 0x57]));
        for packet in server.poll(1).unwrap() {
            assert_eq!(client.receive(&packet, 2).unwrap()[0].opcode, 0x54);
        }
        for ack in client.poll(20).unwrap() {
            server.receive(&ack, 21).unwrap();
        }
        assert!(!server.has_pending(&[0x54, 0x56, 0x57]));
        assert!(server.has_pending(&[0x53]));
        assert!(server.pending_count() > 0);
    }

    #[test]
    fn rtt_tracks_retry_attempts_without_refreshing_on_duplicate_acks() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let mut client = Endpoint::new(Direction::ClientToServer);
        server.send(0x54, &[0; 17], 0).unwrap();
        server.poll(0).unwrap(); // Lost first attempt.
        let retry = server.poll(200).unwrap();
        client.receive(&retry[0], 220).unwrap();
        let ack = client.poll(230).unwrap();
        server.receive(&ack[0], 240).unwrap();
        assert_eq!(server.round_trip_ms(240), Some(40));
        assert_eq!(server.pending_count(), 0);
        server.receive(&ack[0], 1000).unwrap();
        assert_eq!(server.round_trip_ms(5241), None);
    }

    #[test]
    fn rtt_handles_sequence_wrap_future_ack_and_bounded_history() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        server.next_sequence = 65535;
        server.poll(100).unwrap();
        server.poll(200).unwrap(); // Sequence 0 after wrap.
        let mut header = Header {
            sequence: 0,
            ack_sequence: 1,
            ack_mask: NEWEST,
            multiple: true,
        };
        server
            .receive(&header.encode(&[1, 2]).unwrap(), 220)
            .unwrap();
        assert_eq!(server.round_trip_ms(220), None); // Unsent future sequence.
        header.sequence = 1;
        header.ack_sequence = 0;
        server
            .receive(&header.encode(&[1, 2]).unwrap(), 250)
            .unwrap();
        assert_eq!(server.round_trip_ms(250), Some(50));
        for now in (300..40_000).step_by(100) {
            server.poll(now).unwrap();
        }
        assert!(server.sent_times.len() <= 256);
    }

    #[test]
    fn ack_of_an_earlier_attempt_stops_retries() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let mut client = Endpoint::new(Direction::ClientToServer);
        server.send(0x54, &[3; 17], 0).unwrap();
        let first = server.poll(0).unwrap();
        client.receive(&first[0], 10).unwrap();
        let delayed_ack = client.poll(20).unwrap();
        let retry = server.poll(200).unwrap();
        assert_eq!(retry.len(), 1);
        server.receive(&delayed_ack[0], 210).unwrap();
        assert_eq!(server.pending_count(), 0);
    }

    #[test]
    fn unreliable_notifications_are_not_retried() {
        let mut client = Endpoint::new(Direction::ClientToServer);
        client.send(0x46, &[0; 8], 0).unwrap();
        client.poll(0).unwrap();
        assert_eq!(client.pending_count(), 0);
        let heartbeat = client.poll(200).unwrap();
        assert_eq!(&heartbeat[0][12..], &[1, 2]);
    }

    #[test]
    fn queued_controls_are_isolated_from_application_messages() {
        let mut endpoint = Endpoint::new(Direction::ServerToClient);
        endpoint.send(0x59, &[], 0).unwrap();
        endpoint.send(1, &[], 0).unwrap();
        endpoint.send(0x59, &[], 0).unwrap();
        let packets = endpoint.poll(0).unwrap();
        assert_eq!(packets.len(), 3);
        for (index, packet) in packets.iter().enumerate() {
            let (header, frames) = wire::decode(Direction::ServerToClient, packet).unwrap();
            assert_eq!(header.multiple, index == 1);
            assert_eq!(frames.len(), 1);
            assert_eq!(frames[0].opcode(), if index == 1 { 1 } else { 0x59 });
        }
    }

    #[test]
    fn bidirectional_ack_retirement_survives_a_full_sequence_cycle() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let mut client = Endpoint::new(Direction::ClientToServer);
        for index in 0u32..65_540 {
            let now = u64::from(index) * 20;
            let body = index.to_le_bytes();
            server.send(0x52, &body, now).unwrap();
            let packets = server.poll(now).unwrap();
            assert_eq!(packets.len(), 1);
            assert_eq!(
                client.receive(&packets[0], now).unwrap(),
                [Message {
                    opcode: 0x52,
                    body: body.to_vec()
                }]
            );
            let acks = client.poll(now + 10).unwrap();
            assert_eq!(acks.len(), 1);
            server.receive(&acks[0], now + 10).unwrap();
            assert_eq!(server.pending_count(), 0);
        }
        assert_eq!(server.next_sequence, 65_540);
        assert_eq!(server.next_order, 4);
        assert_eq!(client.ordered.expected, 4);
    }

    #[test]
    fn send_capacity_failure_is_atomic() {
        let mut server = Endpoint::new(Direction::ServerToClient);
        let body = vec![3; MAX_MESSAGE];
        while server.send(0x53, &body, 0).is_ok() {}
        let before = (
            server.pending_count(),
            server.pending_bytes,
            server.next_order,
        );
        assert_eq!(server.send(0x53, &body, 0), Err(Error::QueueFull));
        assert_eq!(
            (
                server.pending_count(),
                server.pending_bytes,
                server.next_order
            ),
            before
        );
        assert_eq!(server.poll(TIMEOUT_MS), Err(Error::TimedOut));
    }
}
