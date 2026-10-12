// SPDX-License-Identifier: GPL-3.0-or-later
//! Native E6/DB timing feedback; bounded E7 slew is SRP policy.
//! E6: server game milliseconds (u16), advertised RTT (u16).
//! DB: echoed RTT, echoed server time plus client processing, client game time.
//! See retail 0x27b770, 0x27cbf0, 0x27b7f0 and 0x1ee9e0.
use std::collections::VecDeque;

struct Probe {
    sent: u64,
    game: u16,
    advertised_rtt: u16,
}
#[derive(Default)]
pub struct Clock {
    probe: Option<Probe>,
    last_probe: Option<u64>,
    rtt: u16,
    samples: VecDeque<i16>,
}
#[derive(Debug, PartialEq)]
pub struct Sample {
    pub rtt: u16,
    pub error: i16,
    pub correction: Option<i16>,
}
impl Clock {
    /// Probes are sent once. Retransmitting an old timestamp biases latency.
    pub fn request(&mut self, now: u64, game: u32) -> Option<[u8; 4]> {
        if self
            .last_probe
            .is_some_and(|last| now.saturating_sub(last) < 2000)
        {
            return None;
        }
        if self.probe.is_some() {
            self.samples.clear();
        }
        self.last_probe = Some(now);
        self.probe = Some(Probe {
            sent: now,
            game: game as u16,
            advertised_rtt: self.rtt,
        });
        let mut body = [0; 4];
        body[..2].copy_from_slice(&(game as u16).to_le_bytes());
        body[2..].copy_from_slice(&self.rtt.to_le_bytes());
        Some(body)
    }
    pub fn receive(&mut self, body: &[u8], now: u64, game: u32) -> Option<Sample> {
        let probe = self.probe.as_ref()?;
        let fields: Vec<_> = body
            .chunks_exact(2)
            .map(|b| u16::from_le_bytes([b[0], b[1]]))
            .collect();
        if body.len() != 6
            || now.saturating_sub(probe.sent) > 1500
            || fields[0] != probe.advertised_rtt
        {
            return None;
        }
        let processing = fields[1].wrapping_sub(probe.game);
        let elapsed = (game as u16).wrapping_sub(fields[1]) as i16;
        let rtt = elapsed.max(0) as u16;
        // Allow a small timer quantization margin but reject stale exchanges.
        if u64::from(processing) > now.saturating_sub(probe.sent) + 2
            || !(-2..=500).contains(&elapsed)
        {
            return None;
        }
        let error = fields[1].wrapping_add(rtt / 2).wrapping_sub(fields[2]) as i16;
        self.probe = None; // Duplicates never vote or produce a second correction.
        self.rtt = rtt;
        self.samples.push_back(error);
        while self.samples.len() > 3 {
            self.samples.pop_front();
        }
        let correction = if self.samples.len() == 3 {
            let mut sorted: Vec<_> = self.samples.iter().copied().collect();
            sorted.sort();
            let median = sorted[1];
            // Do not chase jitter or a single delayed/stalled frame. Require
            // three errors of one sign before applying a bounded gradual slew.
            if median.unsigned_abs() > 10 && sorted.iter().all(|v| v.signum() == median.signum()) {
                self.samples.clear();
                Some(median.clamp(-100, 100))
            } else {
                None
            }
        } else {
            None
        };
        Some(Sample {
            rtt,
            error,
            correction,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn reply(rtt: u16, echoed: u16, local: u16) -> Vec<u8> {
        [rtt.to_le_bytes(), echoed.to_le_bytes(), local.to_le_bytes()].concat()
    }
    #[test]
    fn subtracts_client_processing_handles_wrap_and_slews_in_correct_direction() {
        let mut clock = Clock::default();
        for i in 0..3u64 {
            let game = 65520 + i as u32 * 2000;
            let body = clock.request(i * 2000, game).unwrap();
            let advertised = u16::from_le_bytes(body[2..].try_into().unwrap());
            // 100ms client processing, 40ms RTT, client 60ms behind.
            let packet = reply(advertised, (game + 100) as u16, (game + 60) as u16);
            let sample = clock.receive(&packet, i * 2000 + 140, game + 140).unwrap();
            assert_eq!(sample.rtt, 40);
            assert_eq!(sample.error, 60);
            assert_eq!(sample.correction, if i == 2 { Some(60) } else { None });
            assert!(clock.receive(&packet, i * 2000 + 141, game + 141).is_none());
        }
    }
    #[test]
    fn timer_rounding_is_tolerated_and_a_missed_exchange_breaks_the_sample_streak() {
        let mut clock = Clock::default();
        clock.request(0, 1000).unwrap();
        let first = clock.receive(&reply(0, 1002, 1022), 0, 1000).unwrap();
        assert_eq!(first.rtt, 0);
        assert_eq!(first.error, -20);
        clock.request(2000, 3000).unwrap(); // No reply to this probe.
        for i in 2..=4u64 {
            let game = 1000 + i as u32 * 2000;
            let body = clock.request(i * 2000, game).unwrap();
            let advertised = u16::from_le_bytes(body[2..].try_into().unwrap());
            let sample = clock
                .receive(
                    &reply(advertised, game as u16, (game + 30) as u16),
                    i * 2000 + 20,
                    game + 20,
                )
                .unwrap();
            assert_eq!(sample.correction, if i == 4 { Some(-20) } else { None });
        }
    }

    #[test]
    fn refuses_expired_unrelated_and_impossible_replies_and_bounds_correction() {
        let mut clock = Clock::default();
        clock.request(0, 1000).unwrap();
        assert!(clock.receive(&reply(1, 1000, 1000), 10, 1010).is_none());
        assert!(clock.receive(&reply(0, 1200, 1000), 10, 1010).is_none());
        assert!(clock.receive(&reply(0, 900, 1000), 10, 1010).is_none());
        assert!(clock.receive(&reply(0, 2000, 2000), 1600, 2600).is_none());
        for i in 1..=3u64 {
            let game = i as u32 * 2000;
            let body = clock.request(i * 2000, game).unwrap();
            let advertised = u16::from_le_bytes(body[2..].try_into().unwrap());
            let sample = clock
                .receive(
                    &reply(advertised, game as u16, (game + 400) as u16),
                    i * 2000 + 20,
                    game + 20,
                )
                .unwrap();
            assert_eq!(sample.correction, if i == 3 { Some(-100) } else { None });
        }
    }
}
