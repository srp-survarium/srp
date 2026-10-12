// SPDX-License-Identifier: GPL-3.0-or-later
//! Arrival cursors preserve input revisions received during a late-join transfer.
use std::collections::BTreeMap;

#[derive(Clone, Debug)]
pub struct Event {
    pub time: u32,
    pub slot: u8,
    pub opcode: u8,
    pub body: Vec<u8>,
}

#[derive(Default)]
pub struct Journal {
    events: BTreeMap<(u32, u8, u8), (u64, Event)>,
    cursor: u64,
    floor: u32,
}
impl Journal {
    pub fn cursor(&self) -> u64 {
        self.cursor
    }
    pub fn record(&mut self, event: Event, now: u32) {
        self.prune(now);
        self.cursor += 1;
        // EB/EC are two encodings of the same input, not separate changes.
        let kind = if event.opcode >= 0xeb {
            0xeb
        } else {
            event.opcode
        };
        self.events
            .insert((event.time, event.slot, kind), (self.cursor, event));
        while self.events.len() > 16_384 {
            let ((time, _, _), _) = self.events.pop_first().unwrap();
            self.floor = self.floor.max(time);
        }
    }
    fn prune(&mut self, now: u32) {
        self.floor = self.floor.max(now.saturating_sub(6000));
        self.events.retain(|(time, _, _), _| *time > self.floor);
    }
    pub fn valid(&mut self, baseline: u32, selected: u64, now: u32) -> bool {
        self.prune(now);
        baseline >= self.floor
            && !self
                .events
                .values()
                .any(|(seq, event)| *seq > selected && event.time <= baseline)
    }
    pub fn after(&self, baseline: u32, cursor: u64) -> Vec<Event> {
        self.events
            .values()
            .filter(|(seq, event)| *seq > cursor && event.time > baseline)
            .map(|(_, event)| event.clone())
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn input(time: u32, value: u8) -> Event {
        Event {
            time,
            slot: 0,
            opcode: 0xeb,
            body: vec![value],
        }
    }
    #[test]
    fn cursor_replays_revisions_and_membership_and_detects_invalid_baseline() {
        let mut journal = Journal::default();
        journal.record(input(100, 1), 200);
        let selected = journal.cursor();
        journal.record(input(250, 2), 300);
        let batch = journal.cursor();
        assert_eq!(journal.after(200, 0)[0].body, [2]);
        journal.record(input(250, 3), 300);
        journal.record(
            Event {
                time: 350,
                slot: 1,
                opcode: 0xea,
                body: vec![7, 1],
            },
            300,
        );
        let events = journal.after(200, batch);
        assert_eq!(events.len(), 2);
        assert_eq!(events[0].body, [3]);
        assert_eq!(events[1].opcode, 0xea);
        assert!(journal.valid(200, selected, 300));
        journal.record(input(150, 4), 300);
        assert!(!journal.valid(200, selected, 300));
        assert!(!journal.valid(200, journal.cursor(), 6201));
    }
}
