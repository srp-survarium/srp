void __thiscall survarium::weapon_core_shotgun_reload_state::weapon_core_shotgun_reload_state(
        survarium::weapon_core_shotgun_reload_state *this,
        survarium::weapon_core *weapon,
        survarium::weapon_core_shotgun_reload_base_substate *reload_start,
        survarium::weapon_core_shotgun_reload_base_substate *reload_one_round,
        survarium::weapon_core_shotgun_reload_base_substate *reload_finish)
{
  survarium::weapon_core_base_state::weapon_core_base_state(this, weapon, 1);
  this->survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_shotgun_reload_state_vtbl *)&survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_shotgun_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->m_logic = 0;
  this->m_delete_substates_on_destruction = 1;
  this->m_body_part_mask_for_user = body_part_whole_body_but_hands;
  survarium::weapon_core_shotgun_reload_state::initialize_logic(this, reload_start, reload_one_round, reload_finish);
}
