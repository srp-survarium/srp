void __thiscall survarium::weapon_core_melee_state::~weapon_core_melee_state(survarium::weapon_core_melee_state *this)
{
  vostok::resources::unmanaged_resource *v1; // esi

  v1 = &this->vostok::resources::unmanaged_resource;
  this->survarium::weapon_core_melee_state_base::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::weapon_core_melee_state_vtbl *)&survarium::weapon_core_melee_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_melee_state_base::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::weapon_core_melee_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  `vector destructor iterator'(
    (char *)this->m_animations,
    4u,
    2,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource(v1);
}
