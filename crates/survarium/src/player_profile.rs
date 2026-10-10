// SPDX-License-Identifier: GPL-3.0-or-later
use bytemuck::Zeroable;
use raw::*;
use vostok::network_packet::Packet;

#[repr(C)]
#[derive(Clone, Debug, PartialEq)]
pub struct PlayerProfile {
    pub profile_id: u32,
    pub profile_name: String, // 64

    pub slots: [inventory_item_instance; profile_slot_enum::max_slots_count as usize],
    pub team_id: game_team_id,
    pub is_local: bool,
    pub revision: u32,
}

pub mod raw {

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
        ammo_slot_5        = 0x13,
        ammo_slot_6        = 0x14,
        ammo_slot_7        = 0x15,
        ammo_slot_8        = 0x16,
        max_slots_count    = 0x17,
        carried_item       = 0x18,
        // invalid_slot       = 0x17,
        inventory_slot_id  = 0x64,
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

const SLOT_SERIALIZE_TABLE: [slot_serialize_mode_enum; 23] = [
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
    serialize_both_values, // ??
    serialize_both_values,
    serialize_both_values,
    serialize_both_values,
];

impl PlayerProfile {
    pub fn serialize(self, packet: &mut impl Packet) {
        let PlayerProfile {
            profile_id,
            profile_name,
            slots,
            team_id,
            is_local,
            revision,
        } = self;

        packet.write(profile_id);

        packet.write(team_id);
        packet.write(is_local);
        packet.write_str(profile_name.as_str());

        let mut bitmask: u32 = 0b0000_0000_0000_0000;
        for (i, slot) in slots.iter().enumerate() {
            if *slot == inventory_item_instance::zeroed() {
                continue;
            }
            bitmask |= 1 << i
        }

        packet.write(bitmask);
        for (i, slot) in slots.into_iter().enumerate() {
            if slot == inventory_item_instance::zeroed() {
                continue;
            }

            packet.write(slot.dict_id);
            packet.write(slot.id);
            if matches!(
                SLOT_SERIALIZE_TABLE[i],
                serialize_both_values | serialize_just_condition_stack_values
            ) {
                packet.write(slot.condition_or_stack as u16)
            }

            if matches!(
                SLOT_SERIALIZE_TABLE[i],
                serialize_both_values | serialize_just_amount_values
            ) {
                packet.write(slot.amount_in_inventory)
            }
        }

        packet.write(0_u32); // static_modifiers_mask

        packet.write(revision);
    }
}

//
//
//

impl PlayerProfile {
    pub fn new_dummy(profile_id: u32, profile_name: &str) -> Self {
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

        let mut slots =
            [inventory_item_instance::default(); profile_slot_enum::max_slots_count as usize];

        #[rustfmt::skip]
        {
            use profile_slot_enum::*;
            // slots[boots_slot]   = equipment(85); // "gameplay/items/armour/boots/edge_boots_1.options"
            // slots[gloves_slot]  = equipment(41); // "gameplay/items/armour/gloves/scavenger_gloves_1.options"
            // slots[pants_slot]   = equipment(84); // "gameplay/items/armour/legs/edge_legs_1.options"
            // slots[helmet_slot]  = equipment(86); // "gameplay/items/armour/helmet/edge_helmet_1.options"

            // slots[mask_slot]    = i(4, 27, 40);

            // slots[torso_slot]   = equipment(83); // "gameplay/items/armour/torso/edge_torso_1.options"
            // slots[back_slot]    = equipment(87); // "gameplay/items/armour/back/edge_back_1.options"
            // slots[weapon1_slot] = equipment(109);

            // slots[weapon2_slot] = i(12, 55, 130);

            slots[ammo1_weapon1_slot] = ammo(81, 20, 30); // "gameplay/items/weapons/ammo/ammo_7.62x39.options"

            // slots[ammo2_weapon1_slot] = i(33, 53, 500);
            // slots[ammo2_weapon1_slot] = i(...);
            // slots[ammo1_weapon2_slot] = i(...);
            // slots[ammo2_weapon2_slot] = i(...);
        };

        Self {
            profile_id,
            profile_name: profile_name.to_string(),

            slots,
            team_id: game_team_id::team_neutral,

            is_local: true,
            revision: 0,
        }
    }
}
