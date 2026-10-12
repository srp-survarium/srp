// SPDX-License-Identifier: GPL-3.0-or-later

use crate::{Error, Result, reader::Reader};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Stage {
    Name,
    Password,
}

pub fn verify(stage: Stage, bytes: &[u8]) -> Result<()> {
    let mut r = Reader::new(bytes);
    let op = r.byte()?;
    match stage {
        Stage::Name if matches!(op, 0x0a | 0x0b | 0x0c | 0x14) => {}
        Stage::Password => match op {
            8 => {
                let session = r.u32()?;
                let address = r.u32()?;
                let port = r.u16()?;
                if session == 0 || address == 0 || address == u32::MAX || port == 0 {
                    return Err(Error::Invalid);
                }
            }
            0x25 => {
                r.take(13)?;
            }
            0x0a..=0x14 => {}
            _ => return Err(Error::Unsupported),
        },
        _ => return Err(Error::Unsupported),
    }
    r.finish()
}

/// Bounded per-connection TCP plaintext accumulator. Never feed TLS records.
#[derive(Default)]
pub struct Accumulator {
    data: [u8; 14],
    used: usize,
}
pub struct Progress<'a> {
    pub consumed: usize,
    pub response: Option<&'a [u8]>,
}
impl Accumulator {
    pub const fn new() -> Self {
        Self {
            data: [0; 14],
            used: 0,
        }
    }
    pub fn reset(&mut self) {
        self.used = 0;
    }
    /// Return at most one complete response. Apply the stage transition before
    /// feeding the unconsumed suffix. On errors, close/reset the connection.
    pub fn feed(&mut self, stage: Stage, bytes: &[u8]) -> Result<Progress<'_>> {
        let mut consumed = 0;
        if self.used == 0 {
            let Some(&op) = bytes.first() else {
                return Ok(Progress {
                    consumed,
                    response: None,
                });
            };
            self.data[0] = op;
            self.used = 1;
            consumed = 1;
        }
        let need = match (stage, self.data[0]) {
            (Stage::Password, 8) => 11,
            (Stage::Password, 0x25) => 14,
            _ => 1,
        };
        if self.used > need {
            return Err(Error::Invalid);
        }
        let take = (need - self.used).min(bytes.len() - consumed);
        self.data[self.used..self.used + take].copy_from_slice(&bytes[consumed..consumed + take]);
        self.used += take;
        consumed += take;
        if self.used != need {
            return Ok(Progress {
                consumed,
                response: None,
            });
        }
        verify(stage, &self.data[..need])?;
        self.used = 0;
        Ok(Progress {
            consumed,
            response: Some(&self.data[..need]),
        })
    }
}
