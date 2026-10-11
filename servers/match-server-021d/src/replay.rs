// SPDX-License-Identifier: GPL-3.0-or-later
//! Bounded accepted-event journal. Arrival cursors preserve changes received
//! while a joining client is restoring a snapshot or acknowledging a batch.
use std::collections::{BTreeMap, VecDeque};

const MAX_EVENTS: usize = 17_408;

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Event {
    pub time: u32,
    pub opcode: u8,
    pub body: Vec<u8>,
}

#[derive(Default)]
pub struct Journal {
    sequence: u64,
    oldest: u32,
    events: VecDeque<(u64, Event)>,
}
impl Journal {
    pub fn push(&mut self, event: Event) -> Result<(), &'static str> {
        if self.events.len() >= MAX_EVENTS {
            return Err("replay journal capacity reached");
        }
        self.sequence = self
            .sequence
            .checked_add(1)
            .ok_or("replay cursor exhausted")?;
        self.events.push_back((self.sequence, event));
        Ok(())
    }

    pub fn prune(&mut self, game: u32) {
        self.oldest = self
            .oldest
            .max(game.saturating_sub(crate::recovery::WINDOW_MS));
        self.events.retain(|(_, e)| e.time >= self.oldest);
    }

    /// The snapshot already contains effects through its own time. Never
    /// replay those: change_input rejects time <= last full synchronization.
    pub fn after(&self, cursor: u64, baseline: u32) -> Option<(u64, Vec<Event>)> {
        if baseline < self.oldest || cursor > self.sequence {
            return None;
        }
        let pending: Vec<_> = self
            .events
            .iter()
            .filter(|(seq, e)| *seq > cursor && e.time > baseline)
            .collect();
        let mut latest = BTreeMap::new();
        for &(seq, event) in &pending {
            // Only the last accepted revision for a slot/time is needed in a
            // batch. Later batches wait for ACKs, so an older batch cannot
            // arrive after its replacement on this restoring peer.
            if event.opcode == 0x54 {
                latest.insert((event.time, event.body[0]), *seq);
            }
        }
        let events = pending
            .into_iter()
            .filter(|(seq, e)| e.opcode != 0x54 || latest[&(e.time, e.body[0])] == *seq)
            .map(|(_, e)| e.clone())
            .collect();
        Some((self.sequence, events))
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn input(time: u32, value: u8) -> Event {
        Event {
            time,
            opcode: 0x54,
            body: vec![0, value],
        }
    }
    #[test]
    fn batches_preserve_late_arrivals_and_latest_revisions_but_exclude_baseline() {
        let mut j = Journal::default();
        j.push(input(1000, 1)).unwrap();
        j.push(input(1100, 2)).unwrap();
        j.push(input(1100, 3)).unwrap();
        let (cursor, events) = j.after(0, 1000).unwrap();
        assert_eq!(events, vec![input(1100, 3)]);
        j.push(input(1050, 4)).unwrap();
        j.push(input(1100, 5)).unwrap();
        assert_eq!(
            j.after(cursor, 1000).unwrap().1,
            vec![input(1050, 4), input(1100, 5)]
        );
        j.prune(11001);
        assert!(j.after(cursor, 1000).is_none());
        assert_eq!(j.after(0, 1050).unwrap().1, vec![input(1100, 5)]);
    }
}
