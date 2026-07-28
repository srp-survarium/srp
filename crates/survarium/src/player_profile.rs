use bytemuck::Zeroable;
use raw::*;
use vostok::network_packet::Packet;

pub const DEMO_AMMO_AMOUNT: u16 = 10_000;

// Every item currently exposed by the 0.100b lobby's price, compatibility,
// restriction, and quick-item tables.
pub const DEMO_WEAPON_DICT_IDS: [u16; 11] = [12, 13, 14, 15, 16, 17, 18, 19, 55, 56, 64];
pub const DEMO_AMMO_DICT_IDS: [u16; 11] = [7, 20, 22, 50, 51, 52, 53, 70, 71, 72, 73];
pub const DEMO_GEAR_DICT_IDS: [u16; 25] = [
    24, 35, 36, 37, 38, 39, // boots
    25, 40, 41, 42, // gloves
    28, 44, 45, 46, 47, // legs
    27, // helmet
    43, // mask
    29, 31, 32, 33, 34, 48, // torso
    9, 49, // backpacks
];
pub const DEMO_QUICK_ITEM_DICT_IDS: [u16; 6] = [65, 66, 67, 68, 54, 57];
pub const DEMO_SCOPE_DICT_IDS: [u16; 1] = [69];

pub mod raw {
    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct player_profile {
        pub account_id: u32,
        pub profile_id: u32,
        pub profile_name: [u8; 32],
        pub boosters: [skill_booster; 11],
        pub slots: [inventory_item_instance; 19],
        pub team: game_team_id,
        pub padding_1: [u8; 3],
        pub is_local: bool,
        pub padding_2: [u8; 3],
    }
    const _: () = assert!(std::mem::size_of::<player_profile>() == 0x1B8);

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum game_team_id {
        team_1 = 0x0,
        team_2 = 0x1,
        team_neutral = 0x2,
        team_undefined = 0x3,
        team_invalid = 0xFF,
    }

    #[repr(C)]
    #[derive(bytemuck::Pod, bytemuck::Zeroable, Copy, Clone, Debug, PartialEq, Default)]
    pub struct skill_booster {
        pub id: u8,
        pub padding: [u8; 3],
        pub value: f32,
    }
    const _: () = assert!(std::mem::size_of::<skill_booster>() == 8);

    #[repr(C)]
    #[derive(bytemuck::Pod, bytemuck::Zeroable, Copy, Clone, Debug, PartialEq, Default)]
    pub struct inventory_item_instance {
        pub condition_or_stack: u32,
        pub amount_in_inventory: u32,
        pub id: u32,
        pub dict_id: u16,
        pub padding: [u8; 2],
    }
    const _: () = assert!(std::mem::size_of::<inventory_item_instance>() == 0x10);

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Clone, Copy, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum profile_slot_enum {
        helmet_slot        = 0x0,
        mask_slot          = 0x1,
        torso_slot         = 0x2,
        back_slot          = 0x3,
        pants_slot         = 0x4,
        gloves_slot        = 0x5,
        boots_slot         = 0x6,
        weapon1_slot       = 0x7,
        ammo1_weapon1_slot = 0x8,
        ammo2_weapon1_slot = 0x9,
        weapon2_slot       = 0xA,
        ammo1_weapon2_slot = 0xB,
        ammo2_weapon2_slot = 0xC,
        quick_slot1        = 0xD,
        quick_slot2        = 0xE,
        quick_slot3        = 0xF,
        quick_slot4        = 0x10,
        quick_slot5        = 0x11,
        quick_slot6        = 0x12,
        max_slots_count    = 0x13,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum skill_booster_enum {
        empty                         = 0,
        st_dispersion_correction      = 1,
        st_aiming_speed_correction    = 2,
        st_health_regen_correction    = 3,
        st_stamina_regen_correction   = 4,
        st_movement_speed_correction  = 5,
        st_additional_max_weight_name = 6,
        st_pain_healt_correction      = 7,
        st_artcontainer_time_corr     = 8,
        st_anomaly_damage_corr        = 9,
        st_engineer_use_time_corr     = 10,
        st_engineer_succ_chance_corr  = 11,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum skill_id_enum {
        st_sniper_skill      = 1,
        st_physical_skill    = 2,
        st_engineering_skill = 3,
        st_medicial_skill    = 4,
        st_knowledge_skill   = 5,
    }
}

impl<T, const N: usize> std::ops::Index<profile_slot_enum> for [T; N] {
    type Output = T;

    fn index(&self, index: profile_slot_enum) -> &Self::Output {
        &self[index as usize]
    }
}

impl<T, const N: usize> std::ops::IndexMut<profile_slot_enum> for [T; N] {
    fn index_mut(&mut self, index: profile_slot_enum) -> &mut Self::Output {
        &mut self[index as usize]
    }
}

impl player_profile {
    pub fn serialize_tcp(self, packet: &mut impl Packet) {
        packet.write(self)
    }

    pub fn serialize_udp(self, packet: &mut impl Packet) {
        let player_profile {
            account_id: _,
            profile_id: _,
            profile_name,
            boosters,
            slots,
            padding_1: _,
            team,
            is_local,
            padding_2: _,
        } = self;

        packet.write(team);
        packet.write(is_local);

        let profile_name = profile_name
            .split_once(|&c| c == 0)
            .map(|(name, _)| name)
            .unwrap_or(profile_name.as_ref());
        packet.write_slice::<u8, _, _>(profile_name);

        //
        //
        //

        let mut bitmask = 0b0000_0000_0000_0000;
        let mut compact_boosters = [skill_booster::zeroed(); 11];
        let mut no = 0;
        for (i, booster) in boosters.into_iter().enumerate() {
            if booster == skill_booster::zeroed() {
                continue;
            }
            bitmask |= 1_u16 << i;
            compact_boosters[no] = booster;
            no += 1;
        }
        packet.write(bitmask);
        for booster in &compact_boosters[0..no] {
            packet.write(booster.id);
            packet.write(booster.value);
        }

        //
        //
        //

        #[rustfmt::skip]
        #[expect(non_camel_case_types)]
        #[derive(Copy, Clone)]
        enum slot_serialize_mode_enum {
            serialize_just_condition_stack_values = 0x0,
            #[expect(dead_code)]
            serialize_just_amount_values          = 0x1,
            serialize_both_values                 = 0x2,
        }
        use slot_serialize_mode_enum::*;

        const TABLE: [slot_serialize_mode_enum; 19] = [
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_just_condition_stack_values,
            serialize_both_values,
            serialize_both_values,
            serialize_just_condition_stack_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
            serialize_both_values,
        ];

        for (i, slot) in slots.into_iter().enumerate() {
            if slot == inventory_item_instance::zeroed() {
                continue;
            }

            packet.write(i as u8);
            packet.write(slot.dict_id);
            packet.write(slot.id);
            if matches!(
                TABLE[i],
                serialize_both_values | serialize_just_condition_stack_values
            ) {
                packet.write(slot.condition_or_stack as u16)
            }

            if matches!(
                TABLE[i],
                serialize_both_values | serialize_just_amount_values
            ) {
                packet.write(slot.amount_in_inventory)
            }
        }
    }
}

impl player_profile {
    pub fn new_dummy(account_id: u32, profile_id: u32, profile_name: &str) -> Self {
        let a = |id, dict_id, condition_or_stack, amount_in_inventory| inventory_item_instance {
            condition_or_stack,
            amount_in_inventory,
            id,
            dict_id,
            padding: Default::default(),
        };
        let equipment = |dict_id| a(dict_id as u32, dict_id, 100, 1);
        let ammo = |dict_id, condition_or_stack, amount_in_inventory| {
            a(
                dict_id as u32,
                dict_id,
                condition_or_stack,
                amount_in_inventory,
            )
        };

        let mut slots = [inventory_item_instance::default(); 19];

        #[rustfmt::skip]
        {
            use profile_slot_enum::*;

            slots[helmet_slot] = equipment(27);
            slots[mask_slot] = equipment(43);
            slots[torso_slot] = equipment(48);
            slots[back_slot] = equipment(9);
            slots[pants_slot] = equipment(46);
            slots[gloves_slot] = equipment(40);
            slots[boots_slot] = equipment(24);

            slots[weapon1_slot] = equipment(13); // AK-74u
            slots[ammo1_weapon1_slot] =
                ammo(7, DEMO_AMMO_AMOUNT.into(), DEMO_AMMO_AMOUNT.into());
            slots[ammo2_weapon1_slot] =
                ammo(7, DEMO_AMMO_AMOUNT.into(), DEMO_AMMO_AMOUNT.into());

            slots[weapon2_slot] = equipment(14); // Remington 700
            slots[ammo1_weapon2_slot] =
                ammo(51, DEMO_AMMO_AMOUNT.into(), DEMO_AMMO_AMOUNT.into());
            slots[ammo2_weapon2_slot] =
                ammo(52, DEMO_AMMO_AMOUNT.into(), DEMO_AMMO_AMOUNT.into());

            slots[quick_slot1] = a(65, 65, 100, 100); // painkiller
            slots[quick_slot2] = a(66, 66, 100, 100); // bandages
            slots[quick_slot3] = a(67, 67, 100, 100); // medkit
            slots[quick_slot4] = a(68, 68, 100, 100); // traps
        };

        if !(3 < profile_name.len() && profile_name.len() < 30) {
            panic!("bad name")
        }

        let profile_name = {
            let mut bytes = [b'\0'; 32];
            bytes[0..profile_name.len()].copy_from_slice(profile_name.as_bytes());
            bytes
        };

        Self {
            account_id,
            profile_id,
            profile_name,
            boosters: [skill_booster::default(); 11],
            slots,
            padding_1: Default::default(),
            team: game_team_id::team_neutral,
            is_local: true,
            padding_2: Default::default(),
        }
    }
}

pub fn demo_inventory() -> Vec<inventory_item_instance> {
    let mut items = Vec::new();
    for dict_id in DEMO_WEAPON_DICT_IDS
        .into_iter()
        .chain(DEMO_GEAR_DICT_IDS)
        .chain(DEMO_SCOPE_DICT_IDS)
    {
        items.push(inventory_item_instance {
            condition_or_stack: 100,
            amount_in_inventory: 1,
            id: 1_000_000 + u32::from(dict_id),
            dict_id,
            padding: Default::default(),
        });
    }
    for dict_id in DEMO_AMMO_DICT_IDS {
        items.push(inventory_item_instance {
            condition_or_stack: u32::from(DEMO_AMMO_AMOUNT),
            amount_in_inventory: u32::from(DEMO_AMMO_AMOUNT),
            id: 1_000_000 + u32::from(dict_id),
            dict_id,
            padding: Default::default(),
        });
    }
    for dict_id in DEMO_QUICK_ITEM_DICT_IDS {
        items.push(inventory_item_instance {
            condition_or_stack: 100,
            amount_in_inventory: 100,
            id: 1_000_000 + u32::from(dict_id),
            dict_id,
            padding: Default::default(),
        });
    }
    items
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn dummy_profile_starts_with_two_weapons_full_gear_and_large_ammo_stacks() {
        use profile_slot_enum::*;

        let profile = player_profile::new_dummy(1, 0, "demo_player");
        assert!(
            profile.slots[..=boots_slot as usize]
                .iter()
                .all(|slot| slot.id != 0)
        );
        assert_eq!(profile.slots[weapon1_slot].dict_id, 13);
        assert_eq!(profile.slots[weapon2_slot].dict_id, 14);
        for slot in [
            ammo1_weapon1_slot,
            ammo2_weapon1_slot,
            ammo1_weapon2_slot,
            ammo2_weapon2_slot,
        ] {
            assert_eq!(
                profile.slots[slot].condition_or_stack,
                u32::from(DEMO_AMMO_AMOUNT)
            );
            assert_eq!(
                profile.slots[slot].amount_in_inventory,
                u32::from(DEMO_AMMO_AMOUNT)
            );
        }
    }

    #[test]
    fn demo_inventory_contains_every_known_item_with_generous_ammo() {
        let inventory = demo_inventory();
        let dict_ids: std::collections::HashSet<u16> =
            inventory.iter().map(|item| item.dict_id).collect();
        let instance_ids: std::collections::HashSet<u32> =
            inventory.iter().map(|item| item.id).collect();
        assert_eq!(
            inventory.len(),
            dict_ids.len(),
            "catalog IDs must be unique"
        );
        assert_eq!(
            inventory.len(),
            instance_ids.len(),
            "inventory instance IDs must be unique"
        );

        for dict_id in DEMO_WEAPON_DICT_IDS
            .into_iter()
            .chain(DEMO_AMMO_DICT_IDS)
            .chain(DEMO_GEAR_DICT_IDS)
            .chain(DEMO_QUICK_ITEM_DICT_IDS)
            .chain(DEMO_SCOPE_DICT_IDS)
        {
            assert!(
                dict_ids.contains(&dict_id),
                "missing dictionary item {dict_id}"
            );
        }
        for dict_id in DEMO_AMMO_DICT_IDS {
            let ammo = inventory
                .iter()
                .find(|item| item.dict_id == dict_id)
                .unwrap();
            assert_eq!(ammo.condition_or_stack, u32::from(DEMO_AMMO_AMOUNT));
            assert_eq!(ammo.amount_in_inventory, u32::from(DEMO_AMMO_AMOUNT));
        }
    }
}
