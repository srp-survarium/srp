// SPDX-License-Identifier: GPL-3.0-or-later
//! Private, generation-bound admission changes, not client game messages.
use std::collections::HashMap;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Change {
    pub grant: bool,
    pub revision: u64,
    pub instance: u128,
    pub generation: u64,
    pub slot: u8,
    pub account: u32,
    pub session: u32,
}

pub struct Admissions {
    pub sessions: HashMap<u32, u8>,
    last: HashMap<u8, (Change, &'static str)>,
}

impl Admissions {
    pub fn new(sessions: HashMap<u32, u8>) -> Self {
        Self {
            sessions,
            last: HashMap::new(),
        }
    }

    /// Return status and whether an existing transport must be disconnected.
    /// Keep one revision per immutable slot: delayed revocations cannot affect
    /// a newer admission, and a lost reply never repeats a successful removal.
    pub fn change(
        &mut self,
        change: Change,
        instance: u128,
        generation: u64,
        accounts: &[u32],
        phase: &str,
        occupied: u32,
    ) -> (&'static str, bool) {
        if change.instance != instance
            || accounts.get(usize::from(change.slot)) != Some(&change.account)
            || change.session == 0
            || change.revision == 0
        {
            return ("invalid", false);
        }
        if let Some((previous, status)) = self.last.get(&change.slot) {
            if change == *previous {
                return (status, false);
            }
            if change.revision <= previous.revision {
                return ("stale", false);
            }
        }
        if change.generation != generation {
            return ("stale", false);
        }
        let bound = self
            .sessions
            .iter()
            .find_map(|(&token, &slot)| (slot == change.slot).then_some(token));
        let status = if self
            .sessions
            .get(&change.session)
            .is_some_and(|&slot| slot != change.slot)
            || bound.is_some_and(|token| token != change.session)
        {
            "conflict"
        } else if change.grant && phase != "running" {
            "unavailable"
        } else if change.grant && occupied & (1 << change.slot) != 0 {
            "occupied"
        } else {
            "ok"
        };
        self.last.insert(change.slot, (change, status));
        if status != "ok" {
            return (status, false);
        }
        if change.grant {
            self.sessions.insert(change.session, change.slot);
            (status, false)
        } else {
            self.sessions.remove(&change.session);
            (status, occupied & (1 << change.slot) != 0)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn change(revision: u64, grant: bool) -> Change {
        Change {
            grant,
            revision,
            instance: 123,
            generation: 1,
            slot: 1,
            account: 3,
            session: 303,
        }
    }
    #[test]
    fn lost_grant_reply_is_idempotent_even_after_transport_arrives() {
        let mut a = Admissions::new(HashMap::from([(101, 0)]));
        assert_eq!(
            a.change(change(1, true), 123, 1, &[1, 3], "running", 1),
            ("ok", false)
        );
        assert_eq!(
            a.change(change(1, true), 123, 1, &[1, 3], "running", 3),
            ("ok", false)
        );
        assert_eq!(a.sessions.get(&303), Some(&1));
        assert_eq!(
            a.change(change(2, true), 123, 1, &[1, 3], "running", 3),
            ("occupied", false)
        );
    }
    #[test]
    fn old_revoke_cannot_remove_reconnected_account_and_reply_retry_cannot_disconnect_twice() {
        let mut a = Admissions::new(HashMap::from([(303, 1)]));
        assert_eq!(
            a.change(change(1, false), 123, 1, &[1, 3], "running", 3),
            ("ok", true)
        );
        assert_eq!(
            a.change(change(1, false), 123, 1, &[1, 3], "running", 3),
            ("ok", false)
        );
        assert!(!a.sessions.contains_key(&303));
        assert_eq!(
            a.change(change(2, true), 123, 1, &[1, 3], "running", 1),
            ("ok", false)
        );
        assert_eq!(
            a.change(change(1, false), 123, 1, &[1, 3], "running", 3),
            ("stale", false)
        );
        assert_eq!(a.sessions.get(&303), Some(&1));
    }
    #[test]
    fn account_generation_instance_and_session_conflicts_cannot_authorize_reserved_slots() {
        let mut a = Admissions::new(HashMap::from([(303, 0)]));
        assert_eq!(
            a.change(change(1, true), 123, 1, &[1, 3], "running", 1).0,
            "conflict"
        );
        a.sessions.clear();
        assert_eq!(
            a.change(change(2, true), 124, 1, &[1, 3], "running", 1).0,
            "invalid"
        );
        assert_eq!(
            a.change(change(2, true), 123, 2, &[1, 3], "running", 1).0,
            "stale"
        );
        assert_eq!(
            a.change(change(2, true), 123, 1, &[1, 4], "running", 1).0,
            "invalid"
        );
        assert!(a.sessions.is_empty());
    }
    #[test]
    fn no_admission_before_activation_or_after_finish() {
        for phase in ["waiting", "starting", "finished"] {
            let mut a = Admissions::new(HashMap::new());
            assert_eq!(
                a.change(change(1, true), 123, 1, &[1, 3], phase, 0).0,
                "unavailable"
            );
            assert!(a.sessions.is_empty());
        }
    }
}
