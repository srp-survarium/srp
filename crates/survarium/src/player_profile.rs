use bytemuck::Zeroable;
use raw::*;
use vostok::network_packet::Packet;

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
            .iter()
            .position(|&c| c == 0)
            .map(|end| &profile_name[..end])
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
        let item = |id, dict_id, condition_or_stack, amount_in_inventory| {
            inventory_item_instance {
                condition_or_stack,
                amount_in_inventory,
                id,
                dict_id,
                padding: Default::default(),
            }
        };
        let equipment = |id, dict_id| item(id, dict_id, 100, 1);

        let mut slots = [inventory_item_instance::default(); 19];

        // A database that has no imported items cannot be handed imported
        // dictionary IDs: the client dereferences the missing resource and dies
        // with an access violation while the lobby is still sending the
        // profile. Set SRP_STOCK_PROFILE_ONLY for such a database -- the SoC
        // map release is one -- and the profile keeps only retail items.
        let stock_only = std::env::var_os("SRP_STOCK_PROFILE_ONLY").is_some();

        #[rustfmt::skip]
        {
            use profile_slot_enum::*;

            // Use the real lobby inventory instance IDs, not dictionary IDs.
            // The five imported Duty pieces deliberately leave mask/back empty.
            if !stock_only {
                slots[helmet_slot] = equipment(53, 79);
                slots[torso_slot]  = equipment(51, 77);
                slots[pants_slot]  = equipment(52, 78);
                slots[gloves_slot] = equipment(54, 80);
                slots[boots_slot]  = equipment(55, 81);
            }

            slots[weapon1_slot]       = equipment(21, 13); // stock AKS-74U
            slots[ammo1_weapon1_slot] = item(56, 7, 200, 200); // 5.45x39 FMJ
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
