// SPDX-License-Identifier: GPL-3.0-or-later
//! Stable identities for the local development endpoint. These session values
//! are local admission tokens, not authenticated retail accounts.
use std::collections::{BTreeMap, BTreeSet};

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Member {
    pub session: u32,
    pub team: u8,
    pub squad: u8,
    pub name: String,
}

pub fn validate(members: &[Member]) -> Result<(), String> {
    if !(1..=20).contains(&members.len()) {
        return Err("roster needs 1..=20 members".into());
    }
    let mut sessions = BTreeSet::new();
    let mut names = BTreeSet::new();
    let mut squads = BTreeMap::new();
    for member in members {
        if member.session == 0 || !sessions.insert(member.session) {
            return Err("roster sessions must be nonzero and unique".into());
        }
        if member.team > 1 {
            return Err("roster teams must be 0 or 1".into());
        }
        if member.name.is_empty()
            || member.name.len() > 63
            || member.name.chars().any(char::is_control)
            || !names.insert(member.name.to_lowercase())
        {
            return Err("roster names must be unique, nonempty and at most 63 UTF-8 bytes, without control characters".into());
        }
        if member.squad != 0 {
            let (team, count) = squads.entry(member.squad).or_insert((member.team, 0));
            *count += 1;
            if *team != member.team || *count > 3 {
                return Err("a squad must contain at most three players on the same team".into());
            }
        }
    }
    Ok(())
}

/// One member per line: eight hexadecimal session digits, team, squad, name.
/// Blank lines and whole-line # comments are ignored. Line order fixes slots.
pub fn parse(text: &str) -> Result<Vec<Member>, String> {
    let mut members = Vec::new();
    for (line, text) in text.lines().enumerate() {
        let text = text.trim();
        if text.is_empty() || text.starts_with('#') {
            continue;
        }
        let mut fields = text.split_whitespace();
        let error = || format!("roster line {} needs SESSION_HEX TEAM SQUAD NAME", line + 1);
        let token = fields.next().ok_or_else(error)?;
        if token.len() != 8 || !token.bytes().all(|c| c.is_ascii_hexdigit()) {
            return Err(error());
        }
        let session = u32::from_str_radix(token, 16).map_err(|_| error())?;
        let team = fields
            .next()
            .ok_or_else(error)?
            .parse()
            .map_err(|_| error())?;
        let squad = fields
            .next()
            .ok_or_else(error)?
            .parse()
            .map_err(|_| error())?;
        let name = fields.collect::<Vec<_>>().join(" ");
        members.push(Member {
            session,
            team,
            squad,
            name,
        });
    }
    validate(&members)?;
    Ok(members)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn stable_slots_and_squads_are_validated_before_admission() {
        let roster = parse("# session team squad name\n000000a1 0 1 Alice\n000000b2 0 1 Bob Smith\n000000c3 1 0 Carol\n").unwrap();
        assert_eq!(
            roster[1],
            Member {
                session: 0xb2,
                team: 0,
                squad: 1,
                name: "Bob Smith".into()
            }
        );
        for invalid in [
            "",
            "00000000 0 0 Alice",
            "a1 0 0 Alice",
            "000000a1 2 0 Alice",
            "000000a1 0 256 Alice",
            "000000a1 0 0",
            "000000a1 0 1 Alice\n000000b2 1 1 Bob",
            "000000a1 0 0 Alice\n000000a1 1 0 Bob",
            "000000a1 0 0 Alice\n000000b2 1 0 alice",
            "000000a1 0 1 A\n000000b2 0 1 B\n000000c3 0 1 C\n000000d4 0 1 D",
        ] {
            assert!(parse(invalid).is_err(), "{invalid:?}");
        }
    }
}
