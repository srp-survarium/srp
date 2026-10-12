// SPDX-License-Identifier: GPL-3.0-or-later

use crate::{Error, Result};

#[derive(Clone, Copy)]
pub struct Reader<'a> {
    remaining: &'a [u8],
}
impl<'a> Reader<'a> {
    pub const fn new(bytes: &'a [u8]) -> Self {
        Self { remaining: bytes }
    }
    pub const fn remaining(self) -> &'a [u8] {
        self.remaining
    }
    pub fn take(&mut self, count: usize) -> Result<&'a [u8]> {
        let (head, tail) = self
            .remaining
            .split_at_checked(count)
            .ok_or(Error::Truncated)?;
        self.remaining = tail;
        Ok(head)
    }
    pub fn byte(&mut self) -> Result<u8> {
        Ok(self.take(1)?[0])
    }
    pub fn u16(&mut self) -> Result<u16> {
        let p = self.take(2)?;
        Ok(u16::from_le_bytes([p[0], p[1]]))
    }
    pub fn u32(&mut self) -> Result<u32> {
        let p = self.take(4)?;
        Ok(u32::from_le_bytes([p[0], p[1], p[2], p[3]]))
    }
    pub fn finite_float(&mut self) -> Result<f32> {
        let value = f32::from_bits(self.u32()?);
        if value.is_finite() {
            Ok(value)
        } else {
            Err(Error::Invalid)
        }
    }
    pub fn boolean(&mut self) -> Result<bool> {
        match self.byte()? {
            0 => Ok(false),
            1 | 255 => Ok(true),
            _ => Err(Error::Invalid),
        }
    }
    pub fn string(&mut self, capacity: usize, nonempty: bool) -> Result<&'a [u8]> {
        let len = usize::from(self.byte()?);
        if len >= capacity || (nonempty && len == 0) {
            return Err(Error::Invalid);
        }
        let value = self.take(len)?;
        if value.contains(&0) {
            return Err(Error::Invalid);
        }
        Ok(value)
    }
    pub fn finish(self) -> Result<()> {
        if self.remaining.is_empty() {
            Ok(())
        } else {
            Err(Error::Invalid)
        }
    }
}

pub(crate) struct Bits<'a> {
    bytes: &'a [u8],
    position: usize,
}
impl<'a> Bits<'a> {
    pub fn new(bytes: &'a [u8]) -> Self {
        Self { bytes, position: 0 }
    }
    pub fn position(&self) -> usize {
        self.position
    }
    pub fn skip(&mut self, size: usize) -> Result<()> {
        let end = self.position.checked_add(size).ok_or(Error::Limit)?;
        let capacity = self.bytes.len().checked_mul(8).ok_or(Error::Limit)?;
        if end > capacity {
            return Err(Error::Truncated);
        }
        self.position = end;
        Ok(())
    }
    pub fn read(&mut self, size: u32) -> Result<u32> {
        if size > 32 {
            return Err(Error::Invalid);
        }
        let start = self.position;
        self.skip(size as usize)?;
        let mut value = 0;
        for bit in start..self.position {
            value = value << 1 | u32::from((self.bytes[bit / 8] >> (7 - bit % 8)) & 1);
        }
        Ok(value)
    }
}
