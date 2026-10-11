// SPDX-License-Identifier: GPL-3.0-or-later
//! Conservative historical hash comparison. Thresholds are local SRP policy.
use std::collections::BTreeMap;

#[derive(Clone, Copy)]
struct Report {
    crc: u32,
    revised: bool,
}

#[derive(Default)]
pub struct Monitor {
    floor: u32,
    evaluated: u32,
    reports: BTreeMap<(u32, u8), Report>,
    streaks: BTreeMap<u8, (u32, u32, u32)>, // first time, last time, count
}

impl Monitor {
    /// Membership changes and state replacements start a new comparison epoch.
    pub fn reset(&mut self, floor: u32) {
        *self = Self {
            floor,
            evaluated: floor,
            ..Self::default()
        };
    }

    pub fn observe(&mut self, slot: u8, time: u32, crc: u32, game: u32) {
        self.floor = self.floor.max(game.saturating_sub(6000));
        self.reports.retain(|(t, _), _| *t > self.floor);
        if slot >= 20 || time <= self.floor || time > game.saturating_add(100) {
            return;
        }
        let mut changed = false;
        self.reports
            .entry((time, slot))
            .and_modify(|old| {
                changed = old.crc != crc;
                old.revised |= changed;
                old.crc = crc;
            })
            .or_insert(Report {
                crc,
                revised: false,
            });
        if changed {
            // Also withdraw votes already evaluated before the revision arrived.
            // A reference revision can invalidate every overlapping streak.
            self.streaks
                .retain(|_, (first, last, _)| time < *first || time > *last);
        }
    }

    /// A newly accepted input may revise already observed history.
    pub fn input_changed(&mut self, time: u32) {
        self.reports.retain(|(t, _), _| *t < time);
        self.streaks.retain(|_, (_, last, _)| *last < time);
    }

    /// The server selects the longest-active peer as the local reference.
    /// Compare only equal
    /// timestamps, at least one second old; duplicates/revisions cannot vote.
    pub fn suspects(&mut self, game: u32, mask: u32, reference: u8) -> BTreeMap<u8, u32> {
        if mask.count_ones() < 2 || reference >= 20 || mask & (1 << reference) == 0 {
            return BTreeMap::new();
        }
        let settled = game.saturating_sub(1000);
        let mut times: Vec<_> = self
            .reports
            .keys()
            .filter(|(t, slot)| *slot == reference && *t > self.evaluated && *t <= settled)
            .map(|(t, _)| *t)
            .collect();
        times.sort_unstable();
        for time in times {
            self.evaluated = time;
            let donor = self.reports[&(time, reference)];
            if donor.revised {
                continue;
            }
            for slot in 0..20 {
                if slot == reference || mask & (1 << slot) == 0 {
                    continue;
                }
                let Some(report) = self.reports.get(&(time, slot)) else {
                    continue;
                };
                if report.revised {
                    continue;
                }
                if report.crc == donor.crc {
                    self.streaks.remove(&slot);
                } else {
                    let streak = self.streaks.entry(slot).or_insert((time, time, 0));
                    if time.saturating_sub(streak.1) > 1000 {
                        *streak = (time, time, 0);
                    }
                    streak.1 = time;
                    streak.2 += 1;
                }
            }
        }
        self.streaks
            .iter()
            .filter(|(slot, (first, last, count))| {
                mask & (1 << **slot) != 0
                    && *count >= 3
                    && last.saturating_sub(*first) >= 200
                    && game.saturating_sub(*last) <= 2500
            })
            .map(|(slot, (first, _, _))| (*slot, *first))
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn pair(m: &mut Monitor, time: u32, same: bool) {
        m.observe(0, time, 7, time);
        m.observe(1, time, if same { 7 } else { 8 }, time);
    }
    #[test]
    fn a_returning_lower_slot_does_not_become_the_reference() {
        let mut m = Monitor::default();
        for time in [1000, 1100, 1200] {
            pair(&mut m, time, false);
        }
        assert!(m.suspects(2200, 3, 2).is_empty());
        assert_eq!(m.suspects(2200, 3, 1), BTreeMap::from([(0, 1000)]));
    }
    #[test]
    fn requires_settled_distinct_sustained_disagreement_and_clears_on_agreement() {
        let mut m = Monitor::default();
        for _ in 0..20 {
            pair(&mut m, 1000, false);
        }
        assert!(m.suspects(2100, 3, 0).is_empty());
        pair(&mut m, 1100, false);
        pair(&mut m, 1200, false);
        assert!(m.suspects(2199, 3, 0).is_empty());
        assert_eq!(m.suspects(2200, 3, 0), BTreeMap::from([(1, 1000)]));
        pair(&mut m, 1300, true);
        assert!(m.suspects(2300, 3, 0).is_empty());
    }
    #[test]
    fn revisions_late_inputs_and_epoch_changes_cannot_reuse_old_evidence() {
        let mut m = Monitor::default();
        for t in [1000, 1100, 1200] {
            pair(&mut m, t, false);
        }
        m.observe(1, 1100, 9, 1200);
        assert!(m.suspects(2200, 3, 0).is_empty());
        pair(&mut m, 1300, false);
        assert!(!m.suspects(2300, 3, 0).is_empty());
        m.input_changed(1100);
        assert!(m.suspects(2400, 3, 0).is_empty());
        m.reset(3000);
        for t in [1000, 1100, 1200] {
            pair(&mut m, t, false);
        }
        assert!(m.suspects(4000, 3, 0).is_empty());
    }

    #[test]
    fn a_revision_after_comparison_withdraws_the_previous_votes() {
        let mut m = Monitor::default();
        for t in [1000, 1100, 1200] {
            pair(&mut m, t, false);
        }
        assert!(!m.suspects(2200, 3, 0).is_empty());
        m.observe(0, 1100, 9, 2200);
        assert!(m.suspects(2200, 3, 0).is_empty());
        // Repeating the old report cannot make the revised sample trustworthy.
        m.observe(0, 1100, 7, 2200);
        assert!(m.suspects(2200, 3, 0).is_empty());
    }
}
