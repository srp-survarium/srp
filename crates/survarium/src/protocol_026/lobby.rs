// SPDX-License-Identifier: GPL-3.0-or-later
//! Recovered 0.26g0 squad messages. These are application bodies; native UDP
//! framing and login/bootstrap are separate. Read squad: 0x274720; dispatch A1:
//! 0x274e80. Write actions: 0x274580, 0x2745d0, 0x274660, 0x2746d0.

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum SquadAction {
    Disband,
    Invite(String),
    Remove(u32),
    Leave,
}

impl SquadAction {
    pub fn decode(body: &[u8]) -> Result<Self, &'static str> {
        match body {
            [0x4a, 1] => Ok(Self::Disband),
            [0x4a, 2, length, name @ ..] if name.len() == usize::from(*length) => {
                let name = std::str::from_utf8(name).map_err(|_| "invalid squad invite name")?;
                validate_name(name)?;
                Ok(Self::Invite(name.into()))
            }
            [0x4a, 3, a, b, c, d] => Ok(Self::Remove(u32::from_le_bytes([*a, *b, *c, *d]))),
            [0x4a, 4] => Ok(Self::Leave),
            _ => Err("invalid or unsupported 0.26 squad action"),
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SquadMember {
    pub account_id: u32,
    pub profile_id: u32,
    pub profile_revision: u32,
    pub name: String,
    pub online: bool,
    pub ready: bool,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SquadStatus {
    pub squad_id: u32,
    pub commander: u8,
    pub members: Vec<SquadMember>,
    pub local_is_commander: bool,
    pub revision: u32,
}

fn validate_name(name: &str) -> Result<(), &'static str> {
    if name.is_empty() || name.len() > 63 || name.chars().any(char::is_control) {
        return Err("squad name must fit the native 64-byte terminated buffer");
    }
    Ok(())
}

impl SquadStatus {
    pub fn encode(&self) -> Result<Vec<u8>, &'static str> {
        let mut out = vec![0xa1];
        out.extend(self.squad_id.to_le_bytes());
        if self.squad_id == 0 {
            if !self.members.is_empty() || self.local_is_commander {
                return Err("an absent squad cannot have members or a local commander");
            }
            return Ok(out);
        }
        if self.members.is_empty()
            || self.members.len() > 3
            || usize::from(self.commander) >= self.members.len()
        {
            return Err("native squad needs 1..=3 members and a valid commander index");
        }
        let mut accounts = std::collections::BTreeSet::new();
        out.extend([self.members.len() as u8, self.commander]);
        for member in &self.members {
            validate_name(&member.name)?;
            if member.account_id == 0 || !accounts.insert(member.account_id) {
                return Err("squad account IDs must be nonzero and unique");
            }
            out.extend(member.account_id.to_le_bytes());
            out.extend(member.profile_id.to_le_bytes());
            out.extend(member.profile_revision.to_le_bytes());
            out.push(member.name.len() as u8);
            out.extend(member.name.as_bytes());
            out.extend([u8::from(member.online), u8::from(member.ready)]);
        }
        out.push(u8::from(self.local_is_commander));
        out.extend(self.revision.to_le_bytes());
        Ok(out)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn squad_actions_reject_truncation_trailing_data_and_bad_names() {
        let invite = b"\x4a\x02\x05Alice";
        assert_eq!(
            SquadAction::decode(invite),
            Ok(SquadAction::Invite("Alice".into()))
        );
        for n in 0..invite.len() {
            assert!(SquadAction::decode(&invite[..n]).is_err());
        }
        for invalid in [
            &b"\x4a\x02\x00"[..],
            &b"\x4a\x02\x01\0"[..],
            &b"\x4a\x02\x01\xff"[..],
            &b"\x4a\x04\0"[..],
            &b"\x4a\x00"[..],
        ] {
            assert!(SquadAction::decode(invalid).is_err());
        }
        assert_eq!(
            SquadAction::decode(b"\x4a\x03\x04\x03\x02\x01"),
            Ok(SquadAction::Remove(0x01020304))
        );
    }

    #[test]
    fn status_bounds_protect_native_fixed_member_and_name_storage() {
        let mut status = SquadStatus {
            squad_id: 0,
            commander: 0,
            members: vec![],
            local_is_commander: false,
            revision: 0,
        };
        assert_eq!(status.encode().unwrap(), [0xa1, 0, 0, 0, 0]);
        status.squad_id = 1;
        assert!(status.encode().is_err());
        let member = SquadMember {
            account_id: 7,
            profile_id: 8,
            profile_revision: 9,
            name: "Alice".into(),
            online: true,
            ready: false,
        };
        status.members.push(member.clone());
        status.local_is_commander = true;
        status.revision = 10;
        assert_eq!(
            status.encode().unwrap(),
            [
                0xa1, 1, 0, 0, 0, 1, 0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 5, b'A', b'l', b'i',
                b'c', b'e', 1, 0, 1, 10, 0, 0, 0
            ]
        );
        status.commander = 1;
        assert!(status.encode().is_err());
        status.commander = 0;
        status.members.push(member.clone());
        assert!(status.encode().is_err());
        status.members = (1..=4)
            .map(|account_id| SquadMember {
                account_id,
                ..member.clone()
            })
            .collect();
        assert!(status.encode().is_err());
        status.members.truncate(3);
        assert!(status.encode().is_ok());
        status.members[0].name = "x".repeat(64);
        assert!(status.encode().is_err());
    }
}
