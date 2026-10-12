use crate::{
    Error, MAX_MESSAGE, MAX_OPTIONS, MAX_PLAYERS, MAX_STATE, Players, Result,
    reader::Reader,
    state,
    transport::{self, Channel, Opcode},
};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ItemKind {
    Stackable,
    NonStackable,
}
/// Metadata comes from trusted local build-2777 data, never from the peer.
pub trait Metadata {
    fn item_kind(&self, dictionary_id: u16) -> Option<ItemKind>;
    fn map_exists(&self, map_id: u8) -> bool;
}
pub fn options(bytes: &[u8], metadata: &dyn Metadata) -> Result<Players> {
    if bytes.len() > MAX_OPTIONS {
        return Err(Error::Limit);
    }
    let mut r = Reader::new(bytes);
    let mut present = 0;
    for player in 0..MAX_PLAYERS {
        let team = r.byte()?;
        if team != 255 && team > 3 {
            return Err(Error::Invalid);
        }
        if team != 255 {
            if present != player {
                return Err(Error::Invalid);
            }
            present += 1;
        }
        r.string(64, team != 255)?;
        r.string(15, false)?;
        r.u32()?;
        let profiles = r.byte()?;
        let inventory = r.byte()?;
        if profiles > 3 || inventory > 69 {
            return Err(Error::Limit);
        }
        if (team == 255 && (profiles != 0 || inventory != 0)) || (team != 255 && profiles == 0) {
            return Err(Error::Invalid);
        }
        for _ in 0..profiles {
            r.byte()?;
            r.u32()?;
            r.string(64, false)?;
            let mask = r.u32()?;
            if mask >> 23 != 0 {
                return Err(Error::Invalid);
            }
            for slot in 0..23 {
                if mask & (1 << slot) != 0 {
                    if r.u16()? >= u16::from(inventory) {
                        return Err(Error::Invalid);
                    }
                    r.u16()?;
                }
            }
            let high = r.u32()?;
            if high >> 4 != 0 || r.u32()? != 0 {
                return Err(Error::Invalid);
            }
            let count = high.count_ones() + r.u32()?.count_ones() + r.u32()?.count_ones();
            for _ in 0..count {
                r.finite_float()?;
            }
        }
        let mut ids = [0u32; 69];
        for index in 0..usize::from(inventory) {
            let id = r.u32()?;
            if id == 0 || ids[..index].contains(&id) {
                return Err(Error::Invalid);
            }
            ids[index] = id;
            let dictionary_id = r.u16()?;
            if dictionary_id == 0 {
                return Err(Error::Unsupported);
            }
            match metadata
                .item_kind(dictionary_id)
                .ok_or(Error::Unsupported)?
            {
                ItemKind::Stackable => {
                    r.take(4)?;
                }
                ItemKind::NonStackable => {
                    r.take(12)?;
                }
            }
            let switches = r.byte()?;
            if switches > 8 {
                return Err(Error::Limit);
            }
            for _ in 0..switches {
                r.u32()?;
                r.boolean()?;
            }
            let attributes = r.byte()?;
            if attributes > 3 {
                return Err(Error::Limit);
            }
            // Attribute flag is an unrestricted byte; captured value 3 is valid.
            for _ in 0..attributes {
                r.take(17)?;
            }
        }
    }
    let map = r.byte()?;
    let roster = Players::new(r.byte()?)?;
    if roster.get() != present {
        return Err(Error::Invalid);
    }
    if !metadata.map_exists(map) {
        return Err(Error::Unsupported);
    }
    r.u32()?;
    r.u16()?;
    for _ in 0..28 {
        r.finite_float()?;
    }
    r.take(20)?;
    r.finish()?;
    Ok(roster)
}

/// Callbacks are pure validators. Unsupported is the default, never a bypass.
pub trait MessageSchema {
    fn lobby(&self, _op: Opcode, _bytes: &[u8]) -> Result<()> {
        Err(Error::Unsupported)
    }
    fn match_action(&self, _op: Opcode, _bytes: &[u8]) -> Result<()> {
        Err(Error::Unsupported)
    }
}
pub struct Reject;
impl MessageSchema for Reject {}

pub fn lobby(op: u8, bytes: &[u8], schema: &dyn MessageSchema) -> Result<()> {
    if bytes.len() > MAX_MESSAGE {
        return Err(Error::Limit);
    }
    let op = Opcode::new(op, Channel::Lobby)?;
    let mut r = Reader::new(bytes);
    if op.get() >= 0xfa {
        return r.finish();
    }
    match op.get() {
        0x80 => {
            r.take(2)?;
        }
        0xa1 => {
            if r.u32()? == 0 {
                return r.finish();
            }
            let count = r.byte()?;
            let commander = r.byte()?;
            if !(1..=3).contains(&count) || commander >= count {
                return Err(Error::Invalid);
            }
            let mut accounts = [0u32; 3];
            for index in 0..usize::from(count) {
                let account = r.u32()?;
                if account == 0 || accounts[..index].contains(&account) {
                    return Err(Error::Invalid);
                }
                accounts[index] = account;
                r.u32()?;
                r.u32()?;
                r.string(64, true)?;
                r.boolean()?;
                r.boolean()?;
            }
            r.boolean()?;
            r.u32()?;
        }
        _ => return schema.lobby(op, bytes),
    }
    r.finish()
}

pub trait Decoder {
    fn decode(&self, input: &[u8], output: &mut [u8]) -> Result<usize>;
}
#[cfg(feature = "lzma")]
pub struct Lzma2;
#[cfg(feature = "lzma")]
impl Decoder for Lzma2 {
    fn decode(&self, input: &[u8], output: &mut [u8]) -> Result<usize> {
        crate::compression::decode(input, output)
    }
}
pub struct Policy<'a> {
    pub players: Option<Players>,
    pub metadata: &'a dyn Metadata,
    pub messages: &'a dyn MessageSchema,
    pub state: &'a dyn state::Schema,
    pub decoder: &'a dyn Decoder,
}
/// `Some(roster)` is staged E4 output; commit only after the whole transaction.
pub fn match_message(
    op: u8,
    bytes: &[u8],
    policy: &Policy<'_>,
    scratch: &mut [u8],
) -> Result<Option<Players>> {
    if bytes.len() > MAX_MESSAGE {
        return Err(Error::Limit);
    }
    let op = Opcode::new(op, Channel::Match)?;
    let mut r = Reader::new(bytes);
    if op.get() >= 0xfa {
        r.finish()?;
        return Ok(None);
    }
    if op.get() == 0xe4 {
        let local = r.byte()?;
        let output = scratch.get_mut(..MAX_OPTIONS).ok_or(Error::Limit)?;
        let expanded = policy.decoder.decode(r.remaining(), output)?;
        let expanded = output.get(..expanded).ok_or(Error::Codec)?;
        let roster = options(expanded, policy.metadata)?;
        if local >= roster.get() {
            return Err(Error::Invalid);
        }
        return Ok(Some(roster));
    }
    if op.get() == 0xe8 {
        let players = policy.players.ok_or(Error::Invalid)?;
        r.byte()?;
        if r.byte()? != 0 {
            let output = scratch.get_mut(..MAX_STATE).ok_or(Error::Limit)?;
            let expanded = policy.decoder.decode(r.remaining(), output)?;
            let expanded = output.get(..expanded).ok_or(Error::Codec)?;
            state::deep(expanded, players, policy.state)?;
        } else {
            state::deep(r.remaining(), players, policy.state)?;
        }
        return Ok(None);
    }
    if op.get() != 0xe3 && policy.players.is_none() {
        return Err(Error::Invalid);
    }
    if op.get() != 0xf6 {
        transport::fixed_body(op, bytes, policy.players)?;
    }
    // Skhid F6 is NOT the retail compressed debug payload. Require a schema.
    policy.messages.match_action(op, bytes)?;
    Ok(None)
}
