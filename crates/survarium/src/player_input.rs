#![allow(non_camel_case_types)]

use vostok::math::{float2, float3};

use crate::player_profile::raw::profile_slot_enum;

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct player_input {
    pub angular_velocity: float2,
    pub angualr_acceleration: float2,
    pub action_mask: u32,
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct player_state {
    pub translation_w: float3,
    pub euler_angle_y: f32,
    pub look_pitch: f32,
}

#[derive(Clone, Debug, PartialEq)]
pub struct player {
    pub position: float3,
    pub orientation: f32,
    pub look_pitch: f32,
    pub is_alive: bool,
    pub server_current_active_slot: profile_slot_enum, // sets this->m_current_active_object
    pub server_target_active_slot: profile_slot_enum,  // sets this->m_target_active_object
    pub player_stamina: player_stamina,
    pub player_inventory: Vec<player_inventory_slot>, // max 12
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub enum player_inventory_slot {
    weapon_slot(weapon_core),
    item_amount(u16),
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, Copy, Clone, Debug, PartialEq)]
pub struct player_stamina {
    pub value: f32,
    pub last_spending_time_in_ms: u32,
    pub last_tick_time_in_ms: u32,
    pub lower_threshold_was_reached: bool,
}

//
//
//

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct weapon_state {
    pub slot_id: u8,
    pub ammo_slot_id: u8,
    pub state: u8,
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct weapon_core {
    pub inventory_item: u16,
    pub random_seed: u32, // firgure out where it is set
    pub normal_random_seed: u32,
    pub weapon_target: weapon_targets,
    pub old_actions_mask: u32,
    pub ammo_in_magazine: u16,
    pub bullets_in_queue: u16,
    pub fire_queue_type: u8,
    pub ammo_slot: profile_slot_enum,
    pub is_there_chamber_a_round_state: Option<bool>,
    pub weapon_core_state: Option<weapon_core_state>,
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct weapon_core_state {
    pub is_shown: bool,
    pub active_hands: u8, // 0 - None, 1 - left, 2 - right, 3 - left & right
    pub start_transition_time_in_ms_lhs: u32,
    pub start_transition_time_in_ms_rhs: u32,

    // (target_state_id, (interval_id, interval_time)
    pub weapon_sound_target_state: (u8, Option<(u32, f32)>),
    pub logic_sprint_target_state: (u8, Option<(u32, f32)>),
}

#[repr(u8)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub enum weapon_targets {
    idle     = 0x0,
    fire     = 0x1,
    aim      = 0x2,
    aim_fire = 0x3,
    reload   = 0x4,
    inactive = 0x5,
    count    = 0x6,
}

// survarium::weapon_core
//  => survarium::inventory_item
//  => survarium::interactive_object
//  => vostok::resources::unmanaged_resource
//  => vostok::resources::resource_base
//  => vostok::resources::resource_quality
//  => vostok::resources::resource_children
//  => vostok::resources::resource_flags     + vostok::resources::resource_reconstruction_info
//  => vostok::vfs::vfs_association
//
// survarium::weapon_ammunition
//  => survarium::inventory_item
//
//

// 00000000 const struct __cppobj survarium::weapon_core : survarium::inventory_item // sizeof=0x498
//      const survarium::weapon::`vftable'
// .rdata:0097292C ; const survarium::weapon::`vftable'
//  | survarium::weapon_core::deserialize
// .rdata:009757A4 ; const survarium::weapon_core::`vftable'
//  | survarium::weapon_core::deserialize
//
//
// 00000000 struct __cppobj survarium::weapon_ammunition : survarium::inventory_item // sizeof=0x148
//      const survarium::weapon_ammunition::`vftable'
// .rdata:009788AC ; const survarium::weapon_ammunition::`vftable'
//  | r<u16>(amount)
//
//
// 00000000 struct __cppobj survarium::artefact_base : survarium::inventory_item // sizeof=0x118
//      const survarium::artefact_lifebone_core::`vftable'{for `survarium::artefact_base'}
//      const survarium::artefact_base::`vftable'
// .rdata:009787A4 ; const survarium::artefact_lifebone_core::`vftable'{for `survarium::artefact_base'}
//  | NOTE: MISSING
// .rdata:00978724 ; const survarium::artefact_base::`vftable'
//  | r<u16>(amount)
//
//
// 00000000 struct __cppobj survarium::booby_trap_set_core : survarium::inventory_item // sizeof=0x148
//      const survarium::booby_trap_set_core::`vftable'
// .rdata:0096F744 ; const survarium::booby_trap_set::`vftable'
//  | r<u16>(amount)
// .rdata:00975EAC ; const survarium::booby_trap_set_core::`vftable'
//  | r<u16>(amount)
//
// 00000000 struct __cppobj __declspec(align(8)) survarium::medkit : survarium::inventory_item // sizeof=0x150
//      const survarium::medkit::`vftable'
// .rdata:00978514 ; const survarium::medkit::`vftable'
//  | r<u16>(amount)
//
//
// 00000000 struct __cppobj __declspec(align(4)) survarium::oxygen_tank : survarium::inventory_item // sizeof=0x130
//      const survarium::oxygen_tank::`vftable'
// .rdata:0097868C ; const survarium::oxygen_tank::`vftable'
//  | r<u16>(amount)
//
//
// TODO: There are already serialize functions.
// Try to call them manually

//
//
//

#[repr(u32)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub enum affect_event_type_enum {
  applying  = 0x0,
  recalling = 0x1,
  canceling = 0x2,
}

#[repr(u32)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub enum hit_affects_type_enum {
  death              = 0x0,
  bleeding           = 0x1,
  concussion         = 0x2,
  hand_damage        = 0x3,
  leg_damage         = 0x4,
  critical_poisoning = 0x5,
  poisoning          = 0x6,
  radiation_sickness = 0x7,
  blindness          = 0x8,
  count              = 0x9,
}
