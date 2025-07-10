void __thiscall survarium::weapon_core_base_state::weapon_core_base_state(
        survarium::weapon_core_base_state *this,
        survarium::weapon_core *weapon,
        bool serialize_animation_state)
{
  vostok::ai::fsm_state::fsm_state(this);
  vostok::resources::unmanaged_resource::unmanaged_resource(&this->vostok::resources::unmanaged_resource, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_animation_playback_state);
  this->vostok::ai::fsm_state::__vftable = (survarium::weapon_core_base_state_vtbl *)&survarium::weapon_core_base_state::`vftable'{for `vostok::ai::fsm_state'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_base_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->m_animation_playback_state.interval_id = 0;
  this->m_animation_playback_state.interval_time = *(float *)&FLOAT_0_0;
  this->m_weapon = weapon;
  this->m_is_firing_ptr = 0;
  this->m_body_part_mask_for_user = body_part_whole_body;
  this->m_is_ready_to_be_deactivated = 0;
  this->m_animation_has_been_ended = 0;
  this->m_serialize_animation_state = serialize_animation_state;
}
