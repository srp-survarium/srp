void __thiscall survarium::weapon_core_aimed_state_base::weapon_core_aimed_state_base(
        survarium::weapon_core_aimed_state_base *this,
        survarium::weapon_core *weapon)
{
  survarium::weapon_core_base_state::weapon_core_base_state(this, weapon, 0);
  this->survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_aimed_state_base_vtbl *)&survarium::weapon_core_aimed_state_base::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_aimed_state_base::`vftable'{for `vostok::resources::unmanaged_resource'};
}
