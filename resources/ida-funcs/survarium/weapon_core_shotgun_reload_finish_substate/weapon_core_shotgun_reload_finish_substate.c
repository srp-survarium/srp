void __thiscall survarium::weapon_core_shotgun_reload_finish_substate::weapon_core_shotgun_reload_finish_substate(
        survarium::weapon_core_shotgun_reload_finish_substate *this,
        survarium::weapon_core *weapon,
        float animation_time_scale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  survarium::weapon_core_shotgun_reload_base_substate::weapon_core_shotgun_reload_base_substate(
    this,
    weapon,
    animation_time_scale,
    animations,
    animations_count,
    play_once_and_freeze_at_end,
    5u,
    "shotgun-finish_reload",
    "reload_finish(stand)",
    "reload_finish(crouch)",
    "reload_finish(jump)");
  this->survarium::weapon_core_shotgun_reload_base_substate::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_shotgun_reload_finish_substate_vtbl *)&survarium::weapon_core_shotgun_reload_finish_substate::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_shotgun_reload_base_substate::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_shotgun_reload_finish_substate::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->m_owner_ready_for_transition = 0;
}
