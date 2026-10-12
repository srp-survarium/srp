// SPDX-License-Identifier: GPL-3.0-or-later
//! Bounded reference-state acquisition and historical CRC observations.
//! These are SRP policies, not reconstructed community-server arbitration.
//! Reference trust and disagreement thresholds are explicit local-test policy.
use crate::{snapshot::Snapshot, state};
use std::collections::{BTreeMap, VecDeque};

pub const WINDOW_MS: u32 = 10_000;
const REQUEST_INTERVAL_MS: u64 = 5_000;
const REQUEST_TIMEOUT_MS: u64 = 5_000;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Comparison {
    pub time: u32,
    pub slots: [u8; 2],
    pub crcs: [u32; 2],
}
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum SnapshotDecision {
    Cached,
    Unsolicited,
    OutsideWindow,
    MembershipMismatch,
    HashMismatch,
}
#[derive(Clone, Copy)]
struct Report {
    crc: u32,
    revised: bool,
}
struct Request {
    slot: u8,
    wall: u64,
}
struct Candidate {
    slot: u8,
    state: Snapshot,
}

pub struct Recovery {
    roster: u8,
    oldest: u32,
    initial_mask: u32,
    events: VecDeque<(u32, u8, bool)>,
    hashes: BTreeMap<(u32, u8), Report>,
    reference: Option<u8>,
    request: Option<Request>,
    next_request: u64,
    candidate: Option<Candidate>,
}
impl Recovery {
    pub fn new(roster: u8) -> Self {
        assert!((1..=20).contains(&roster));
        Self {
            roster,
            oldest: 0,
            initial_mask: 0,
            events: VecDeque::new(),
            hashes: BTreeMap::new(),
            reference: None,
            request: None,
            next_request: 0,
            candidate: None,
        }
    }

    pub fn membership(&mut self, time: u32, slot: u8, entered: bool) -> Result<(), &'static str> {
        if slot >= self.roster || time < self.oldest || time % 50 != 0 {
            return Err("invalid recovery membership event");
        }
        if self.events.contains(&(time, slot, entered)) {
            return Ok(());
        }
        if self.events.len() >= 1024 {
            return Err("recovery membership capacity reached");
        }
        let index = self
            .events
            .iter()
            .position(|e| e.0 > time)
            .unwrap_or(self.events.len());
        self.events.insert(index, (time, slot, entered));
        Ok(())
    }

    pub fn mask_at(&self, time: u32) -> Option<u32> {
        if time < self.oldest {
            return None;
        }
        let mut mask = self.initial_mask;
        for &(event_time, slot, entered) in &self.events {
            if event_time > time {
                break;
            }
            apply(&mut mask, slot, entered);
        }
        Some(mask)
    }

    /// Returns a donor for one bodyless 0x59 request. Lowest connected playing
    /// slot is the explicit test reference; departure selects the next slot.
    pub fn tick(&mut self, wall: u64, game: u32, playing: &[u8]) -> Option<u8> {
        self.prune(game);
        let reference = playing.iter().copied().min();
        if reference != self.reference {
            self.reference = reference;
            self.request = None;
            self.candidate = None;
            self.next_request = wall;
        }
        if self
            .request
            .as_ref()
            .is_some_and(|r| wall.saturating_sub(r.wall) >= REQUEST_TIMEOUT_MS)
        {
            self.request = None;
        }
        let slot = reference?;
        if self.request.is_some()
            || wall < self.next_request
            || self.mask_at(game)? & (1 << slot) == 0
        {
            return None;
        }
        self.request = Some(Request { slot, wall });
        self.next_request = wall.saturating_add(REQUEST_INTERVAL_MS);
        Some(slot)
    }

    /// Snapshot time is supplied by the donor's event horizon, not the request.
    /// A request has no identity on the wire: all replies still need validation.
    pub fn snapshot(
        &mut self,
        slot: u8,
        snapshot: Snapshot,
        game: u32,
    ) -> Result<SnapshotDecision, &'static str> {
        self.prune(game);
        if self.request.as_ref().is_none_or(|r| r.slot != slot) {
            return Ok(SnapshotDecision::Unsolicited);
        }
        if snapshot.time == 0
            || snapshot.time % 50 != 0
            || snapshot.time < self.oldest
            || snapshot.time > game
        {
            return Ok(SnapshotDecision::OutsideWindow);
        }
        let layout = state::inspect(&snapshot.body, self.roster)?;
        if layout.mask == 0
            || self.mask_at(snapshot.time) != Some(layout.mask)
            || layout.mask & (1 << slot) == 0
        {
            return Ok(SnapshotDecision::MembershipMismatch);
        }
        if self
            .hashes
            .get(&(snapshot.time, slot))
            .is_some_and(|h| h.revised || h.crc != snapshot.crc32())
        {
            return Ok(SnapshotDecision::HashMismatch);
        }
        // Retain one immutable body, not unlimited periodic full states.
        if let Some(old) = &self.candidate {
            if snapshot.time < old.state.time {
                return Ok(SnapshotDecision::OutsideWindow);
            }
            if snapshot.time == old.state.time && snapshot != old.state {
                return Err("reference snapshot changed at the same timestamp");
            }
        }
        self.candidate = Some(Candidate {
            slot,
            state: snapshot,
        });
        self.request = None;
        Ok(SnapshotDecision::Cached)
    }

    /// Unreliable duplicate reports do not inflate comparisons. Revisions make
    /// that slot/time ambiguous for this retention window, withdrawing consent
    /// to use it as a baseline even if the old CRC later reappears.
    pub fn hash(
        &mut self,
        slot: u8,
        time: u32,
        crc: u32,
        game: u32,
    ) -> Result<Vec<Comparison>, &'static str> {
        if slot >= self.roster {
            return Err("invalid CRC source slot");
        }
        self.prune(game);
        if time == 0 || time % 50 != 0 || time < self.oldest || time > game {
            return Ok(vec![]);
        }
        let mask = self.mask_at(time).unwrap_or(0);
        if mask & (1 << slot) == 0 {
            return Ok(vec![]);
        }
        if let Some(old) = self.hashes.get_mut(&(time, slot)) {
            if old.crc != crc {
                old.revised = true;
                old.crc = crc;
            }
            return Ok(vec![]);
        }
        let out = self
            .hashes
            .range((time, 0)..=(time, self.roster - 1))
            .filter(|((_, peer), h)| !h.revised && mask & (1 << peer) != 0)
            .map(|((_, peer), h)| Comparison {
                time,
                slots: [*peer, slot],
                crcs: [h.crc, crc],
            })
            .collect();
        self.hashes.insert(
            (time, slot),
            Report {
                crc,
                revised: false,
            },
        );
        Ok(out)
    }

    /// Late accepted input can change an already observed historical state.
    /// Require fresh hash reports rather than retaining evidence it invalidates.
    pub fn input_changed(&mut self, time: u32) {
        self.hashes.retain(|(t, _), _| *t < time);
        if self
            .candidate
            .as_ref()
            .is_some_and(|c| c.state.time >= time)
        {
            self.candidate = None;
        }
    }

    /// Same-time CRC corroboration and membership are necessary, not sufficient:
    /// callers must also preserve a complete post-baseline input/event backlog.
    pub fn corroborated(&self) -> Option<(u8, &Snapshot)> {
        let c = self.candidate.as_ref()?;
        let h = self.hashes.get(&(c.state.time, c.slot))?;
        (!h.revised && h.crc == c.state.crc32()).then_some((c.slot, &c.state))
    }

    pub fn reference(&self) -> Option<u8> {
        self.reference
    }

    pub fn departed(&mut self, slot: u8) {
        if self.reference == Some(slot) {
            self.reference = None;
            self.request = None;
            self.candidate = None;
        }
    }

    pub fn forget_hashes(&mut self, slot: u8) {
        self.hashes.retain(|(_, s), _| *s != slot);
    }

    /// Three or more distinct disagreements spanning >=500 ms, all at least
    /// one second old, ending within two seconds of game time. A newer equal
    /// sample cancels the run even before that sample has matured. Missing or
    /// revised samples never count. This trusts the explicit reference, not a
    /// majority or independently simulated server truth.
    pub fn suspects(&self, game: u32, playing: &[u8]) -> Vec<(u8, u32)> {
        let Some(reference) = self.reference else {
            return vec![];
        };
        let mut out = Vec::new();
        for &slot in playing {
            if slot == reference {
                continue;
            }
            let mut count = 0;
            let mut newest = None;
            for (&(time, source), report) in self.hashes.iter().rev() {
                if source != slot || report.revised {
                    continue;
                }
                let Some(other) = self.hashes.get(&(time, reference)).filter(|h| !h.revised) else {
                    continue;
                };
                if self.mask_at(time).unwrap_or(0) & ((1 << slot) | (1 << reference))
                    != ((1 << slot) | (1 << reference))
                {
                    continue;
                }
                if report.crc == other.crc {
                    break;
                }
                if time > game.saturating_sub(1000) {
                    continue;
                }
                if newest.is_none() {
                    if time < game.saturating_sub(2000) {
                        break;
                    }
                    newest = Some(time);
                }
                if newest.unwrap() - time > 1000 {
                    break;
                }
                count += 1;
                if count >= 3 && newest.unwrap() - time >= 500 {
                    out.push((slot, newest.unwrap()));
                    break;
                }
            }
        }
        out
    }

    /// Positive post-restore evidence uses the same reference and distinct
    /// mature samples. A single matching hash cannot clear a failed-attempt budget.
    pub fn agrees(&self, slot: u8, after: u32, game: u32) -> bool {
        let Some(reference) = self.reference.filter(|r| *r != slot) else {
            return false;
        };
        let mut count = 0;
        let mut newest = None;
        for (&(time, source), report) in self.hashes.iter().rev() {
            if source != slot || report.revised || time <= after {
                continue;
            }
            let Some(other) = self.hashes.get(&(time, reference)).filter(|h| !h.revised) else {
                continue;
            };
            if report.crc != other.crc {
                return false;
            }
            if time > game.saturating_sub(1000) {
                continue;
            }
            if newest.is_none() {
                if time < game.saturating_sub(2000) {
                    return false;
                }
                newest = Some(time);
            }
            if newest.unwrap() - time > 1000 {
                break;
            }
            count += 1;
            if count >= 3 && newest.unwrap() - time >= 500 {
                return true;
            }
        }
        false
    }

    fn prune(&mut self, game: u32) {
        self.oldest = self.oldest.max(game.saturating_sub(WINDOW_MS));
        while self.events.front().is_some_and(|e| e.0 < self.oldest) {
            let (_, slot, entered) = self.events.pop_front().unwrap();
            apply(&mut self.initial_mask, slot, entered);
        }
        self.hashes.retain(|(time, _), _| *time >= self.oldest);
        if self
            .candidate
            .as_ref()
            .is_some_and(|c| c.state.time < self.oldest)
        {
            self.candidate = None;
        }
    }
}
fn apply(mask: &mut u32, slot: u8, entered: bool) {
    if entered {
        *mask |= 1 << slot;
    } else {
        *mask &= !(1 << slot);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn populated(time: u32, mask: u32) -> Snapshot {
        let mut body = mask.to_le_bytes().to_vec();
        for slot in 0..2 {
            if mask & (1 << slot) != 0 {
                body.extend([1, 0, slot, 0]);
            }
        }
        body.extend([0; 8]);
        Snapshot { time, body }
    }
    fn running() -> Recovery {
        let mut r = Recovery::new(2);
        r.membership(600, 0, true).unwrap();
        r.membership(600, 1, true).unwrap();
        r
    }
    #[test]
    fn request_validation_corroboration_and_revision_withdrawal() {
        let mut r = running();
        let s = populated(1000, 3);
        let crc = s.crc32();
        assert_eq!(
            r.snapshot(0, s.clone(), 1500).unwrap(),
            SnapshotDecision::Unsolicited
        );
        assert_eq!(r.tick(0, 1500, &[1, 0]), Some(0));
        assert_eq!(r.tick(1, 1501, &[0, 1]), None);
        assert_eq!(
            r.snapshot(1, s.clone(), 1500).unwrap(),
            SnapshotDecision::Unsolicited
        );
        assert_eq!(
            r.snapshot(0, populated(1000, 1), 1500).unwrap(),
            SnapshotDecision::MembershipMismatch
        );
        assert_eq!(
            r.snapshot(0, s.clone(), 1500).unwrap(),
            SnapshotDecision::Cached
        );
        assert!(r.corroborated().is_none());
        r.hash(0, 1000, crc, 1500).unwrap();
        assert_eq!(r.corroborated(), Some((0, &s)));
        let c = r.hash(1, 1000, crc, 1500).unwrap();
        assert_eq!(
            c,
            vec![Comparison {
                time: 1000,
                slots: [0, 1],
                crcs: [crc, crc]
            }]
        );
        assert!(r.hash(1, 1000, crc, 1500).unwrap().is_empty());
        r.hash(0, 1000, crc ^ 1, 1500).unwrap();
        assert!(r.corroborated().is_none());
        r.hash(0, 1000, crc, 1500).unwrap();
        assert!(r.corroborated().is_none());
    }
    #[test]
    fn departure_changes_reference_and_historical_membership_is_preserved() {
        let mut r = running();
        assert_eq!(r.tick(0, 1000, &[0, 1]), Some(0));
        r.membership(1200, 0, false).unwrap();
        r.departed(0);
        assert_eq!(r.reference(), None);
        assert!(r.corroborated().is_none());
        assert_eq!(r.tick(1, 1050, &[1]), Some(1));
        assert_eq!(r.mask_at(1150), Some(3));
        assert_eq!(r.mask_at(1200), Some(2));
        assert_eq!(
            r.snapshot(0, populated(1000, 3), 1250).unwrap(),
            SnapshotDecision::Unsolicited
        );
        assert_eq!(
            r.snapshot(1, populated(1250, 3), 1250).unwrap(),
            SnapshotDecision::MembershipMismatch
        );
        assert_eq!(
            r.snapshot(1, populated(1250, 2), 1250).unwrap(),
            SnapshotDecision::Cached
        );
        r.tick(20000, 20000, &[1]);
        assert_eq!(r.mask_at(10000), Some(2));
        assert_eq!(r.mask_at(9999), None);
        assert!(r.events.is_empty());
        assert!(r.corroborated().is_none());
    }
    #[test]
    fn requests_are_bounded_and_old_input_invalidates_cached_evidence() {
        let mut r = running();
        let s = populated(1000, 3);
        let crc = s.crc32();
        assert_eq!(r.tick(0, 1500, &[0]), Some(0));
        assert_eq!(r.tick(4999, 1500, &[0]), None);
        assert_eq!(r.tick(5000, 1500, &[0]), Some(0));
        r.hash(0, 1000, crc, 1500).unwrap();
        r.snapshot(0, s, 1500).unwrap();
        r.input_changed(1050);
        assert!(r.corroborated().is_some());
        r.input_changed(1000);
        assert!(r.corroborated().is_none());
        assert!(r.hashes.is_empty());
        for time in (50..=30000).step_by(50) {
            r.hash(0, time, 0, time).unwrap();
        }
        assert_eq!(r.hashes.len(), 201);
        assert_eq!(
            r.snapshot(0, populated(500, 3), 30000).unwrap(),
            SnapshotDecision::Unsolicited
        );
    }

    #[test]
    fn wrong_hash_future_time_and_malformed_state_cannot_become_a_reference() {
        let mut r = running();
        let s = populated(1000, 3);
        r.tick(0, 1500, &[0, 1]);
        r.hash(0, 1000, s.crc32() ^ 1, 1500).unwrap();
        assert_eq!(
            r.snapshot(0, s, 1500).unwrap(),
            SnapshotDecision::HashMismatch
        );
        assert_eq!(
            r.snapshot(0, populated(2000, 3), 1500).unwrap(),
            SnapshotDecision::OutsideWindow
        );
        let mut malformed = populated(1050, 3);
        malformed.body.push(0);
        assert!(r.snapshot(0, malformed, 1500).is_err());
        assert!(r.corroborated().is_none());
        // A different timestamp is a missing comparison, not disagreement.
        assert!(r.hash(1, 1050, 123, 1500).unwrap().is_empty());
        assert!(r.hash(1, 550, 123, 1500).unwrap().is_empty());
    }

    #[test]
    fn recovery_requires_sustained_mature_disagreement_not_missing_or_revised_samples() {
        let mut r = running();
        r.tick(0, 1000, &[0, 1]);
        for time in [1000, 1250, 1500] {
            r.hash(0, time, 1, 1600).unwrap();
            r.hash(1, time, 2, 1600).unwrap();
        }
        assert!(r.suspects(2499, &[0, 1]).is_empty());
        assert_eq!(r.suspects(2500, &[0, 1]), vec![(1, 1500)]);
        assert!(r.suspects(3501, &[0, 1]).is_empty()); // Stale evidence.
        r.hash(0, 2000, 3, 2500).unwrap();
        assert_eq!(r.suspects(2500, &[0, 1]), vec![(1, 1500)]); // Missing counterpart.
        r.hash(1, 2000, 3, 2500).unwrap();
        assert!(r.suspects(2500, &[0, 1]).is_empty()); // New equality cancels.
        r.forget_hashes(1);
        assert!(r.suspects(2500, &[0, 1]).is_empty());
        for time in [1000, 1250, 1500] {
            r.hash(1, time, 2, 1600).unwrap();
            r.hash(1, time, 4, 1600).unwrap();
        }
        assert!(r.suspects(2500, &[0, 1]).is_empty());
    }
}
