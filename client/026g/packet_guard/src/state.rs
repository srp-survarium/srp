// SPDX-License-Identifier: GPL-3.0-or-later

use crate::{
    Error, MAX_STATE, Players, Result,
    reader::{Bits, Reader},
};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
#[repr(u32)]
pub enum Part {
    Player = 1,
    AnimationTree,
    Bullets,
    Statistics,
    Objects,
    Physics,
    Rules,
    Effects,
    AnimationValues,
}
/// Pure validation only. Validate every nested count, index and destination
/// capacity in the complete slice. Missing schemas must return Unsupported.
pub trait Schema {
    fn check(
        &self,
        part: Part,
        bytes: &[u8],
        meaningful_bits: usize,
        slot: Option<u8>,
    ) -> Result<()>;
}
pub struct Reject;
impl Schema for Reject {
    fn check(&self, _: Part, _: &[u8], _: usize, _: Option<u8>) -> Result<()> {
        Err(Error::Unsupported)
    }
}
fn width(n: u32) -> u32 {
    (32 - n.leading_zeros()).max(1)
}
fn indices(bits: &mut Bits<'_>, count: u32, unique: u32) -> Result<()> {
    if unique == 0 || unique > count {
        return Err(Error::Invalid);
    }
    for _ in 0..count {
        if bits.read(width(unique))? >= unique {
            return Err(Error::Invalid);
        }
    }
    Ok(())
}
fn animation(r: &mut Reader<'_>, schema: Option<&dyn Schema>, slot: u8) -> Result<()> {
    let bytes = r.remaining();
    let mut b = Bits::new(bytes);
    let tree_bits = b.read(16)? as usize;
    b.skip(tree_bits)?;
    if let Some(schema) = schema {
        schema.check(
            Part::AnimationTree,
            &bytes[2..2 + tree_bits.div_ceil(8)],
            tree_bits,
            Some(slot),
        )?;
    }
    let count = b.read(10)?;
    if count != 0 {
        let dictionary = b.read(1)? != 0;
        b.skip(32)?;
        if count > 1 {
            let element_width = b.read(5)?;
            if dictionary {
                let unique = b.read(width(count))?;
                if unique == 0 || unique > count {
                    return Err(Error::Invalid);
                }
                b.skip(((unique - 1) * element_width) as usize)?;
                indices(&mut b, count, unique)?;
            } else {
                b.skip((count * element_width) as usize)?;
            }
        }
    }
    let dictionary = b.read(1)? != 0;
    let count = b.read(10)?;
    let unique = if dictionary {
        b.read(width(count))?
    } else {
        count
    };
    if dictionary && ((unique == 0 && count != 0) || unique > count) {
        return Err(Error::Invalid);
    }
    for _ in 0..unique {
        if !f32::from_bits(b.read(32)?).is_finite() {
            return Err(Error::Invalid);
        }
    }
    if dictionary && count != 0 {
        indices(&mut b, count, unique)?;
    }
    let bit_count = b.position();
    let data = r.take(bit_count.div_ceil(8))?;
    if let Some(schema) = schema {
        schema.check(Part::AnimationValues, data, bit_count, Some(slot))?;
    }
    Ok(())
}
fn block(
    r: &mut Reader<'_>,
    schema: Option<&dyn Schema>,
    part: Part,
    slot: Option<u8>,
) -> Result<()> {
    let n = usize::from(r.u16()?);
    let bytes = r.take(n)?;
    if let Some(schema) = schema {
        schema.check(part, bytes, n * 8, slot)?;
    }
    Ok(())
}
fn verify(bytes: &[u8], players: Players, schema: Option<&dyn Schema>) -> Result<()> {
    if bytes.len() > MAX_STATE {
        return Err(Error::Limit);
    }
    let mut r = Reader::new(bytes);
    r.u32()?; // Native timestamp precedes the mask.
    let mask = r.u32()?;
    players.validate_mask(mask)?;
    for slot in 0..players.get() {
        if mask & (1 << slot) == 0 {
            continue;
        }
        block(&mut r, schema, Part::Player, Some(slot))?;
        if r.byte()? != 0 {
            animation(&mut r, schema, slot)?;
        }
    }
    for part in [
        Part::Bullets,
        Part::Statistics,
        Part::Objects,
        Part::Physics,
        Part::Rules,
        Part::Effects,
    ] {
        block(&mut r, schema, part, None)?;
    }
    r.finish()
}
/// Boundaries only. This MUST NOT authorize a native consumer.
pub fn envelope(bytes: &[u8], players: Players) -> Result<()> {
    verify(bytes, players, None)
}
/// Deep verification requires a schema for EVERY opaque block and animation.
pub fn deep(bytes: &[u8], players: Players, schema: &dyn Schema) -> Result<()> {
    verify(bytes, players, Some(schema))
}
