// SPDX-License-Identifier: GPL-3.0-or-later
//! Bounded relay history for state replacement. Policy limits are SRP choices.
use std::collections::BTreeMap;

const RETAIN_MS: u32 = 6000; // Less than half of the 8-bit / 50 ms time range.
const MAX_INPUTS: usize = 16_384;

/// Retail 0x318620/0x318690: tick byte, optionally followed by milliseconds
/// within that tick. The two-byte form is not a little-endian integer.
pub fn input_time(body: &[u8], variable: bool, reference: u32) -> Option<u32> {
    let tick = *body.first()?;
    let remainder = if variable { *body.get(1)? } else { 0 };
    if remainder >= 50 {
        return None;
    }
    let reference_tick = reference / 50;
    let delta = tick.wrapping_sub(reference_tick as u8) as i8;
    u32::try_from((i64::from(reference_tick) + i64::from(delta)) * 50 + i64::from(remainder)).ok()
}

#[derive(Clone)]
pub struct Input {
    pub time: u32,
    pub slot: u8,
    pub opcode: u8,
    pub body: Vec<u8>,
}

#[derive(Default)]
pub struct History {
    inputs: BTreeMap<(u32, u8), Input>,
    floor: u32,
}

impl History {
    pub fn accepts(&mut self, time: u32, now: u32) -> bool {
        self.prune(now);
        time > self.floor && time <= now.saturating_add(500)
    }

    pub fn record(&mut self, input: Input, now: u32) -> bool {
        if !self.accepts(input.time, now) {
            return false;
        }
        if self
            .inputs
            .get(&(input.time, input.slot))
            .is_some_and(|old| old.opcode == input.opcode && old.body == input.body)
        {
            return false;
        }
        self.inputs.insert((input.time, input.slot), input);
        while self.inputs.len() > MAX_INPUTS {
            let ((time, _), _) = self.inputs.pop_first().unwrap();
            self.floor = self.floor.max(time);
        }
        true
    }

    fn prune(&mut self, now: u32) {
        self.floor = self.floor.max(now.saturating_sub(RETAIN_MS));
        self.inputs.retain(|(time, _), _| *time > self.floor);
    }

    pub fn after(&mut self, snapshot_time: u32, now: u32) -> Option<Vec<Input>> {
        self.prune(now);
        if snapshot_time < self.floor {
            return None;
        }
        Some(
            self.inputs
                .values()
                .filter(|input| input.time > snapshot_time)
                .cloned()
                .collect(),
        )
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn expands_native_tick_and_subtick_through_wrap() {
        assert_eq!(input_time(&[114, 8], true, 5700), Some(5708));
        assert_eq!(input_time(&[0], false, 12799), Some(12800));
        assert_eq!(input_time(&[255, 49], true, 12800), Some(12799));
        assert_eq!(input_time(&[255], false, 0), None);
        assert_eq!(input_time(&[1, 50], true, 50), None);
    }

    #[test]
    fn replay_keeps_latest_revision_and_refuses_incomplete_history() {
        let mut history = History::default();
        for (time, value) in [(100, 1), (200, 2), (200, 3), (150, 4)] {
            history.record(
                Input {
                    time,
                    slot: 0,
                    opcode: 0xeb,
                    body: vec![value],
                },
                200,
            );
        }
        let replay = history.after(100, 200).unwrap();
        assert_eq!(
            replay
                .iter()
                .map(|i| (i.time, i.body[0]))
                .collect::<Vec<_>>(),
            [(150, 4), (200, 3)]
        );
        assert!(history.after(100, 6201).is_none());
        assert!(history.after(201, 6201).unwrap().is_empty());
    }
}
