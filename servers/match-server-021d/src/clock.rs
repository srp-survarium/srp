// SPDX-License-Identifier: GPL-3.0-or-later
//! Conservative SRP policy for retail 0x55 signed-millisecond clock slews.
//! The client defaults to a 0.05 floating factor (game ctor VA 0x15149c).
//! No simulation reset, timer jump, or claim of recovered community policy.
use std::collections::VecDeque;

const DEADBAND_MS: i64 = 75;
const MAX_OFFSET_MS: i64 = 100;
const COOLDOWN_MS: u64 = 5_000;

#[derive(Default)]
pub struct Slew {
    last_report: Option<(u32, u64)>,
    errors: VecDeque<i64>,
    next_correction: u64,
}

impl Slew {
    pub fn reset(&mut self, now: u64) {
        *self = Self {
            next_correction: now.saturating_add(COOLDOWN_MS),
            ..Self::default()
        };
    }

    /// RTT/2 is a symmetric-path estimate, not a measured one-way delay.
    /// Missing/stale RTT or an outstanding ordered transfer supplies None.
    pub fn observe(
        &mut self,
        client: u32,
        server: u32,
        now: u64,
        round_trip_ms: Option<u64>,
    ) -> Option<i16> {
        if let Some((previous, received)) = self.last_report {
            if client <= previous || now.saturating_sub(received) < 500 {
                return None; // Reordered/duplicate reports cannot add evidence.
            }
            if now.saturating_sub(received) > 2_500 {
                self.errors.clear();
            }
        }
        let Some(rtt) = round_trip_ms.filter(|rtt| *rtt <= 1_000) else {
            self.errors.clear();
            // An ordered correction may have spent seconds in retransmission.
            // Leave time for it to finish after the last blocked observation.
            self.next_correction = self.next_correction.max(now.saturating_add(COOLDOWN_MS));
            return None;
        };
        let error = i64::from(server) - i64::from(client) - (rtt / 2) as i64;
        if error.abs() > 2_000 {
            self.errors.clear();
            return None; // Do not let an implausible timestamp poison the high-water mark.
        }
        self.last_report = Some((client, now));
        if now < self.next_correction || error.abs() <= DEADBAND_MS {
            self.errors.clear();
            return None;
        }
        self.errors.push_back(error);
        if self.errors.len() > 3 {
            self.errors.pop_front();
        }
        if self.errors.len() != 3 {
            return None;
        }
        let mut errors: Vec<_> = self.errors.iter().copied().collect();
        errors.sort_unstable();
        if errors[2] - errors[0] > 50 {
            return None; // Variable transit/pauses are not stable drift evidence.
        }
        let offset = errors[1].clamp(-MAX_OFFSET_MS, MAX_OFFSET_MS) as i16;
        self.next_correction = now.saturating_add(COOLDOWN_MS);
        self.errors.clear();
        Some(offset)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn accounts_for_transit_and_requires_stable_distinct_reports() {
        let mut s = Slew::default();
        // Client 100ms behind, plus 40ms one-way transit: correct +100, not +140.
        assert_eq!(s.observe(860, 1000, 1000, Some(80)), None);
        assert_eq!(s.observe(860, 1100, 1100, Some(80)), None);
        assert_eq!(s.observe(850, 2000, 2000, Some(80)), None);
        assert_eq!(s.observe(1860, 2000, 2000, Some(80)), None);
        assert_eq!(s.observe(2860, 3000, 3000, Some(80)), Some(100));
        assert_eq!(s.observe(3860, 4000, 4000, Some(80)), None);
    }

    #[test]
    fn latency_alone_jitter_missing_latency_and_extreme_reports_do_not_slew() {
        for errors in [[40, 40, 40], [100, 300, 100], [-100, 100, -100]] {
            let mut s = Slew::default();
            for (i, error) in errors.into_iter().enumerate() {
                let time = (i as u32 + 1) * 1000;
                assert_eq!(
                    s.observe(
                        (i64::from(time) - error) as u32,
                        time,
                        u64::from(time),
                        Some(80)
                    ),
                    None
                );
            }
        }
        let mut s = Slew::default();
        for rtt in [None, Some(1001)] {
            assert_eq!(s.observe(800, 1000, 1000, rtt), None);
        }
        s = Slew::default();
        assert_eq!(s.observe(u32::MAX, 1000, 1000, Some(10)), None);
        assert_eq!(s.observe(800, 1000, 1000, Some(0)), None);
        assert_eq!(s.observe(1800, 2000, 2000, Some(0)), None);
        assert_eq!(s.observe(2800, 3000, 3000, Some(0)), Some(100));
    }

    #[test]
    fn reset_and_report_gaps_require_new_evidence() {
        let mut s = Slew::default();
        for time in [1000, 2000] {
            assert_eq!(s.observe(time + 200, time, u64::from(time), Some(0)), None);
        }
        s.reset(2000);
        for time in 3..=8 {
            assert_eq!(
                s.observe(
                    time * 1000 + 200,
                    time * 1000,
                    u64::from(time) * 1000,
                    Some(0)
                ),
                None
            );
        }
        assert_eq!(s.observe(9200, 9000, 9000, Some(0)), Some(-100));
        s = Slew::default();
        for time in [1000, 2000, 6000, 7000] {
            assert_eq!(s.observe(time + 200, time, u64::from(time), Some(0)), None);
        }
        assert_eq!(s.observe(8200, 8000, 8000, Some(0)), Some(-100));
    }

    #[test]
    fn delayed_ordered_correction_gets_time_to_finish_before_another_slew() {
        let mut s = Slew::default();
        for now in [1000u32, 2000] {
            assert_eq!(s.observe(now - 300, now, u64::from(now), Some(0)), None);
        }
        assert_eq!(s.observe(2700, 3000, 3000, Some(0)), Some(100));
        // The correction remains unacknowledged beyond its original cooldown.
        assert_eq!(s.observe(8700, 9000, 9000, None), None);
        for now in 10..=15 {
            assert_eq!(
                s.observe(now * 1000 - 300, now * 1000, u64::from(now) * 1000, Some(0)),
                None
            );
        }
        assert_eq!(s.observe(15700, 16000, 16000, Some(0)), Some(100));
    }

    #[test]
    fn bounded_slews_converge_without_time_jumps_in_retail_rate_model() {
        for initial_error in [-400.0_f64, 400.0] {
            let mut s = Slew::default();
            let mut client = 10_000.0 - initial_error;
            let mut remaining = 0.0_f64;
            let mut corrections = Vec::new();
            // Independent client model: default +/-5% until the offset is spent.
            for second in 1..=40 {
                let extra = remaining.clamp(-50.0, 50.0);
                client += 1000.0 + extra;
                remaining -= extra;
                let server = 10_000 + second * 1000;
                if let Some(offset) = s.observe(
                    client as u32 - 40,
                    server,
                    u64::from(second) * 1000,
                    Some(80),
                ) {
                    assert_eq!(
                        remaining, 0.0,
                        "do not replace an unfinished default-rate slew"
                    );
                    assert!(offset.unsigned_abs() <= 100);
                    remaining = f64::from(offset);
                    corrections.push(offset);
                }
            }
            assert_eq!(corrections.len(), 4);
            assert!((client - 50_000.0).abs() <= DEADBAND_MS as f64);
        }
    }
}
