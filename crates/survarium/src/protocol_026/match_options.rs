// SPDX-License-Identifier: GPL-3.0-or-later
//! Static match setup for 0.26g0. Layout validated by executing the original
//! match-options, profile, inventory and dictionary readers. `key`/`tag` and
//! inventory `field_*` names deliberately retain unknown field semantics.

use super::compression;

pub const MAX_PLAYERS: usize = 20;
pub const MAX_PROFILES: usize = 3;
pub const MAX_INVENTORY: usize = 69;
pub const SLOT_COUNT: usize = 23;
pub const MODIFIER_COUNT: usize = 68;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Slot {
    pub inventory_index: u16,
    pub amount: u16,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Profile {
    pub tag: u8,
    pub key: u32,
    pub name: String,
    pub slots: [Option<Slot>; SLOT_COUNT],
    pub modifiers: [f32; MODIFIER_COUNT],
}

impl Default for Profile {
    fn default() -> Self {
        Self {
            tag: 0,
            key: 0,
            name: String::new(),
            slots: [None; SLOT_COUNT],
            modifiers: [0.; MODIFIER_COUNT],
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ItemValue {
    Stack(u32),
    NonStackable {
        value: u32,
        field_0c: u32,
        field_10: u32,
    },
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ItemAttribute {
    pub first: u32,
    pub second: u32,
    pub value: u64,
    pub flag: u8,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct InventoryItem {
    pub id: u32,
    /// This build's dictionary ID. `value` must agree with its is_stack flag.
    pub dictionary_id: u16,
    pub value: ItemValue,
    pub switches: Vec<(u32, bool)>,
    pub attributes: Vec<ItemAttribute>,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Player {
    pub team: u8,
    pub name: String,
    pub clan_tag: String,
    pub key: u32,
    pub profiles: Vec<Profile>,
    pub inventory: Vec<InventoryItem>,
}

#[derive(Debug, Clone, PartialEq)]
pub struct MatchOptions {
    /// Active players, in network player-ID order. Remaining slots are padded.
    pub players: Vec<Player>,
    pub map_id: u8,
    pub match_id: u32,
    pub match_level: u16,
    /// Name inferred from the corresponding 0.21d PDB field; 0.26 has 28 entries.
    pub event_scores: [f32; 28],
    /// Zero means no squad; equal nonzero IDs identify squadmates. Native HUD
    /// 0x23989f and scoreboard 0x2352a3 use these values directly.
    pub squads: [u8; MAX_PLAYERS],
}

#[derive(Debug)]
pub enum Error {
    Invalid(&'static str),
    Compression(compression::Error),
}
impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "0.26 setup: {self:?}")
    }
}
impl std::error::Error for Error {}

fn string(out: &mut Vec<u8>, value: &str, max: usize) -> Result<(), Error> {
    if value.len() > max || value.contains('\0') {
        return Err(Error::Invalid(
            "string exceeds client field or contains NUL",
        ));
    }
    out.push(value.len() as u8);
    out.extend_from_slice(value.as_bytes());
    Ok(())
}

impl MatchOptions {
    pub fn serialize(&self) -> Result<Vec<u8>, Error> {
        if self.players.is_empty() || self.players.len() > MAX_PLAYERS {
            return Err(Error::Invalid("player count must be 1..=20"));
        }
        let mut out = Vec::new();
        for player in &self.players {
            if player.team > 3 {
                return Err(Error::Invalid("invalid player team"));
            }
            if player.profiles.is_empty() || player.profiles.len() > MAX_PROFILES {
                return Err(Error::Invalid("profile count must be 1..=3"));
            }
            if player.inventory.len() > MAX_INVENTORY {
                return Err(Error::Invalid("too many inventory items"));
            }
            out.push(player.team);
            string(&mut out, &player.name, 63)?;
            string(&mut out, &player.clan_tag, 14)?;
            out.extend_from_slice(&player.key.to_le_bytes());
            out.extend([player.profiles.len() as u8, player.inventory.len() as u8]);
            for profile in &player.profiles {
                out.push(profile.tag);
                out.extend_from_slice(&profile.key.to_le_bytes());
                string(&mut out, &profile.name, 63)?;
                let mask = profile
                    .slots
                    .iter()
                    .enumerate()
                    .fold(0u32, |mask, (i, slot)| {
                        mask | (u32::from(slot.is_some()) << i)
                    });
                out.extend_from_slice(&mask.to_le_bytes());
                for slot in profile.slots.iter().flatten() {
                    if usize::from(slot.inventory_index) >= player.inventory.len() {
                        return Err(Error::Invalid("equipment references absent inventory item"));
                    }
                    out.extend_from_slice(&slot.inventory_index.to_le_bytes());
                    out.extend_from_slice(&slot.amount.to_le_bytes());
                }
                if profile.modifiers.iter().any(|f| !f.is_finite()) {
                    return Err(Error::Invalid("non-finite modifier"));
                }
                let mask = profile
                    .modifiers
                    .iter()
                    .enumerate()
                    .fold(0u128, |mask, (i, value)| {
                        mask | (u128::from(*value != 0.) << i)
                    });
                // The engine's uint128 stores the high u64 before the low u64.
                out.extend_from_slice(&((mask >> 64) as u64).to_le_bytes());
                out.extend_from_slice(&(mask as u64).to_le_bytes());
                for value in profile.modifiers.iter().filter(|v| **v != 0.) {
                    out.extend_from_slice(&value.to_le_bytes());
                }
            }
            for item in &player.inventory {
                if item.dictionary_id == 0 {
                    return Err(Error::Invalid("zero dictionary ID"));
                }
                if item.switches.len() > 8 || item.attributes.len() > 3 {
                    return Err(Error::Invalid(
                        "inventory extension exceeds client capacity",
                    ));
                }
                out.extend_from_slice(&item.id.to_le_bytes());
                out.extend_from_slice(&item.dictionary_id.to_le_bytes());
                match item.value {
                    ItemValue::Stack(value) => out.extend_from_slice(&value.to_le_bytes()),
                    ItemValue::NonStackable {
                        value,
                        field_0c,
                        field_10,
                    } => {
                        for word in [value, field_0c, field_10] {
                            out.extend_from_slice(&word.to_le_bytes());
                        }
                    }
                }
                out.push(item.switches.len() as u8);
                for (value, enabled) in &item.switches {
                    out.extend_from_slice(&value.to_le_bytes());
                    out.push(u8::from(*enabled));
                }
                out.push(item.attributes.len() as u8);
                for attribute in &item.attributes {
                    out.extend_from_slice(&attribute.first.to_le_bytes());
                    out.extend_from_slice(&attribute.second.to_le_bytes());
                    out.extend_from_slice(&attribute.value.to_le_bytes());
                    out.push(attribute.flag);
                }
            }
        }
        for _ in self.players.len()..MAX_PLAYERS {
            out.extend_from_slice(&[255, 0, 0, 0, 0, 0, 0, 0, 0]);
        }
        out.extend([self.map_id, self.players.len() as u8]);
        out.extend_from_slice(&self.match_id.to_le_bytes());
        out.extend_from_slice(&self.match_level.to_le_bytes());
        if self.event_scores.iter().any(|f| !f.is_finite()) {
            return Err(Error::Invalid("non-finite event score"));
        }
        for score in self.event_scores {
            out.extend_from_slice(&score.to_le_bytes());
        }
        out.extend_from_slice(&self.squads);
        if out.len() > compression::MAX_EXPANDED_SIZE {
            return Err(Error::Invalid("setup exceeds client buffer"));
        }
        Ok(out)
    }

    /// E4 application body, before unique-ID/fragment and transport framing.
    pub fn static_info(&self, local_player: u8) -> Result<Vec<u8>, Error> {
        if usize::from(local_player) >= self.players.len() {
            return Err(Error::Invalid("local player is absent from roster"));
        }
        let encoded = compression::compress(&self.serialize()?).map_err(Error::Compression)?;
        let mut out = Vec::with_capacity(1 + encoded.len());
        out.push(local_player);
        out.extend_from_slice(&encoded);
        Ok(out)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn sample() -> MatchOptions {
        let mut profile = Profile {
            tag: 2,
            key: 777,
            name: "Loadout".into(),
            ..Profile::default()
        };
        profile.slots[7] = Some(Slot {
            inventory_index: 0,
            amount: 1,
        });
        profile.slots[8] = Some(Slot {
            inventory_index: 1,
            amount: 120,
        });
        for (i, value) in [(0, 1.25), (63, 2.5), (67, 3.75)] {
            profile.modifiers[i] = value;
        }
        MatchOptions {
            players: vec![Player {
                team: 1,
                name: "Tester".into(),
                clan_tag: "SRP".into(),
                key: 123456,
                profiles: vec![profile],
                inventory: vec![
                    InventoryItem {
                        id: 1001,
                        dictionary_id: 3,
                        value: ItemValue::NonStackable {
                            value: 10000,
                            field_0c: 17,
                            field_10: 19,
                        },
                        switches: vec![(33, true)],
                        attributes: vec![ItemAttribute {
                            first: 44,
                            second: 55,
                            value: 0x123456789abc,
                            flag: 3,
                        }],
                    },
                    InventoryItem {
                        id: 1002,
                        dictionary_id: 7,
                        value: ItemValue::Stack(120),
                        switches: vec![],
                        attributes: vec![],
                    },
                ],
            }],
            map_id: 61,
            match_id: 1234,
            match_level: 10,
            event_scores: std::array::from_fn(|i| i as f32 + 0.5),
            squads: std::array::from_fn(|i| i as u8),
        }
    }

    #[test]
    fn setup_verified_by_retail_object_reader() {
        let hex = include_str!("../fixtures/026g-options.hex")
            .lines()
            .find(|s| !s.starts_with('#'))
            .unwrap();
        let expected: Vec<u8> = (0..hex.len())
            .step_by(2)
            .map(|i| u8::from_str_radix(&hex[i..i + 2], 16).unwrap())
            .collect();
        let options = sample();
        assert_eq!(options.serialize().unwrap(), expected);
        let info = options.static_info(0).unwrap();
        assert_eq!(info[0], 0);
        assert_eq!(
            compression::decompress(&info[1..], compression::MAX_EXPANDED_SIZE).unwrap(),
            expected
        );
    }

    #[test]
    fn rejects_values_that_overrun_or_misindex_client_objects() {
        let mut options = sample();
        assert!(options.static_info(1).is_err());
        options.players[0].profiles[0].slots[0] = Some(Slot {
            inventory_index: 2,
            amount: 1,
        });
        assert!(options.serialize().is_err());
        options.players[0].profiles[0].slots[0] = None;
        options.players[0].clan_tag = "012345678901234".into();
        assert!(options.serialize().is_err());
        options.players[0].clan_tag.clear();
        options.players[0].profiles.resize(4, Profile::default());
        assert!(options.serialize().is_err());
    }
}
