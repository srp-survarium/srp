// SPDX-License-Identifier: GPL-3.0-or-later
//! Explicit snapshot dialects. Never infer a dialect from incoming traffic.

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub enum Protocol {
    #[default]
    Community,
    Srp1,
}

pub enum Extension<'a> {
    Upload(&'a [u8]),
    Leave,
}

impl Protocol {
    pub fn name(self) -> &'static str {
        match self {
            Self::Community => "community",
            Self::Srp1 => "srp1",
        }
    }

    pub fn snapshot_request(self) -> &'static [u8] {
        match self {
            Self::Community => b"",
            Self::Srp1 => b"SRP1\x01",
        }
    }

    pub fn extension(self, opcode: u8, body: &[u8]) -> Result<Extension<'_>, &'static str> {
        match (self, opcode) {
            (Self::Community, 0x47) => Ok(Extension::Upload(body)),
            (Self::Srp1, 0x47) if body.len() == 4 => Ok(Extension::Leave),
            (Self::Srp1, 0x48) if body.starts_with(b"SRP1") => Ok(Extension::Upload(&body[4..])),
            _ => Err("message does not match configured snapshot protocol"),
        }
    }
}

/// Preserve the existing positional launch contract; the explicit option may
/// occur before or after it, including without an optional control socket.
pub fn arguments(
    args: impl IntoIterator<Item = String>,
) -> Result<(Protocol, Vec<String>), &'static str> {
    let mut args = args.into_iter();
    let mut protocol = None;
    let mut positional = Vec::new();
    while let Some(arg) = args.next() {
        if arg == "--protocol" {
            if protocol.is_some() {
                return Err("duplicate --protocol");
            }
            protocol = Some(match args.next().as_deref() {
                Some("community") => Protocol::Community,
                Some("srp1") => Protocol::Srp1,
                _ => return Err("--protocol requires community or srp1"),
            });
        } else if arg.starts_with("--") {
            return Err("unknown option");
        } else {
            positional.push(arg);
        }
    }
    Ok((protocol.unwrap_or_default(), positional))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn extension_dialects_do_not_alias_upload_and_leave() {
        let fragment = [50, 0, 0, 0, 0, 0, 1, 0, 0];
        assert!(
            matches!(Protocol::Community.extension(0x47, &fragment), Ok(Extension::Upload(b)) if b == fragment)
        );
        assert!(Protocol::Community.extension(0x48, b"SRP1payload").is_err());
        assert!(Protocol::Srp1.extension(0x47, &fragment).is_err());
        assert!(matches!(
            Protocol::Srp1.extension(0x47, &[50, 0, 0, 0]),
            Ok(Extension::Leave)
        ));
        assert!(Protocol::Srp1.extension(0x48, &fragment).is_err());
        assert!(Protocol::Srp1.extension(0x48, b"SRP2payload").is_err());
        assert!(
            matches!(Protocol::Srp1.extension(0x48, b"SRP1payload"), Ok(Extension::Upload(b)) if b == b"payload")
        );
        assert_eq!(Protocol::Community.snapshot_request(), b"");
        assert_eq!(Protocol::Srp1.snapshot_request(), b"SRP1\x01");
    }

    #[test]
    fn protocol_selection_preserves_positional_defaults_and_rejects_ambiguity() {
        let parse = |args: &[&str]| arguments(args.iter().map(|s| s.to_string()));
        assert_eq!(
            parse(&["sessions", "12023"]).unwrap(),
            (Protocol::Community, vec!["sessions".into(), "12023".into()])
        );
        assert_eq!(
            parse(&["sessions", "--protocol", "srp1", "12023"]).unwrap(),
            (Protocol::Srp1, vec!["sessions".into(), "12023".into()])
        );
        for args in [
            vec!["--protocol"],
            vec!["--protocol", "auto"],
            vec!["--protocol", "srp1", "--protocol", "community"],
            vec!["--unknown"],
        ] {
            assert!(parse(&args).is_err());
        }
    }
}
