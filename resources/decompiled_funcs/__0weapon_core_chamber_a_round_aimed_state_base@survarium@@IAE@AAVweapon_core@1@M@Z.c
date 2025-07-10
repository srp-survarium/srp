void __thiscall survarium::weapon_core_chamber_a_round_aimed_state_base::weapon_core_chamber_a_round_aimed_state_base(
        survarium::weapon_core_chamber_a_round_aimed_state_base *this,
        survarium::weapon_core *weapon,
        float animation_time_scale)
{
  survarium::weapon_core_base_state::weapon_core_base_state(this, weapon, 1);
  this->survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_chamber_a_round_aimed_state_base_vtbl *)&survarium::weapon_core_animation_end_aware_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_animation_end_aware_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_animation_to_wait_for);
  this->survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_chamber_a_round_aimed_state_base_vtbl *)&survarium::weapon_core_chamber_a_round_aimed_state_base::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_animation_end_aware_state::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_chamber_a_round_aimed_state_base::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->m_animation_timescale = animation_time_scale;
  this->m_body_part_mask_for_user = body_part_whole_body_but_hands;
}
