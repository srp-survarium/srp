// SPDX-License-Identifier: GPL-3.0-or-later
//! Trusted local admission data. Account identity is independent of roster slot.
use std::collections::{HashMap, HashSet};

pub struct Grants {
    pub sessions: HashMap<u32, u8>,
    pub accounts: Vec<u32>,
}

pub fn validate_accounts(accounts: &[u32]) -> Result<(), &'static str> {
    if !(1..=20).contains(&accounts.len())
        || accounts.contains(&0)
        || accounts.iter().collect::<HashSet<_>>().len() != accounts.len()
    {
        return Err("invalid or duplicate roster account identity");
    }
    Ok(())
}

impl Grants {
    pub fn parse(text: &str) -> Result<Self, &'static str> {
        let versioned = text.lines().next() == Some("SRP-SESSIONS-2");
        let mut sessions = HashMap::new();
        let mut roster = HashMap::new();
        for line in text.lines().skip(usize::from(versioned)) {
            let values: Result<Vec<u32>, _> = line.split_whitespace().map(str::parse).collect();
            let values = values.map_err(|_| "invalid session file number")?;
            let (session, slot, account) = match values.as_slice() {
                [slot, account, session] if versioned => (*session, *slot, *account),
                [session, slot] if !versioned => (*session, *slot, slot.saturating_add(1)),
                _ => return Err("invalid session file record"),
            };
            let slot = u8::try_from(slot).map_err(|_| "invalid session slot")?;
            if slot >= 20 || roster.insert(slot, account).is_some() {
                return Err("duplicate or invalid roster slot");
            }
            if session == 0 && !versioned {
                return Err("zero legacy session");
            }
            // Versioned zero sessions reserve static identities without giving
            // their accounts permission to enter this match.
            if session != 0 && sessions.insert(session, slot).is_some() {
                return Err("duplicate session");
            }
        }
        let accounts: Option<Vec<_>> = (0..roster.len())
            .map(|slot| roster.get(&(slot as u8)).copied())
            .collect();
        let accounts = accounts.ok_or("roster slots must be contiguous from zero")?;
        validate_accounts(&accounts)?;
        Ok(Self { sessions, accounts })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn account_identity_does_not_depend_on_join_order_or_active_admission() {
        let grants = Grants::parse("SRP-SESSIONS-2\n0 3 303\n1 1 101\n2 2 0\n").unwrap();
        assert_eq!(grants.accounts, [3, 1, 2]);
        assert_eq!(grants.sessions.get(&303), Some(&0));
        assert_eq!(grants.sessions.get(&101), Some(&1));
        assert!(!grants.sessions.contains_key(&0));
        assert_eq!(grants.sessions.len(), 2);
        let legacy = Grants::parse("101 0\n202 1\n").unwrap();
        assert_eq!(legacy.accounts, [1, 2]);
        assert_eq!(legacy.sessions.get(&202), Some(&1));
    }

    #[test]
    fn ambiguous_and_incomplete_identities_cannot_start_a_match() {
        for text in [
            "",
            "0 0\n",
            "101 1\n",
            "101 0\n101 1\n",
            "SRP-SESSIONS-2\n0 0 101\n",
            "SRP-SESSIONS-2\n0 3 101\n1 3 202\n",
            "SRP-SESSIONS-2\n0 3 101\n0 4 202\n",
            "SRP-SESSIONS-2\n0 3 101\n2 4 202\n",
            "SRP-SESSIONS-2\n0 3 101\n1 4 101\n",
        ] {
            assert!(Grants::parse(text).is_err(), "{text}");
        }
    }
}
