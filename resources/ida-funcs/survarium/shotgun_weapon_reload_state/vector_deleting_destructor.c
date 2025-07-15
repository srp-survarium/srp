survarium::shotgun_weapon_reload_state *__thiscall survarium::shotgun_weapon_reload_state::`vector deleting destructor'(
        survarium::shotgun_weapon_reload_state *this,
        char a2)
{
  vostok::ai::fsm *m_logic; // eax
  survarium::weapon_core_shotgun_reload_state *v4; // ecx

  m_logic = this->m_logic;
  this->survarium::weapon_core_shotgun_reload_state::survarium::weapon_core_base_state::vostok::ai::fsm_state::__vftable = (survarium::shotgun_weapon_reload_state_vtbl *)&survarium::shotgun_weapon_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  this->survarium::weapon_core_shotgun_reload_state::survarium::weapon_core_base_state::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::shotgun_weapon_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  vostok::ai::fsm::clear_transitions((vostok::ai::fsm *)this, (int)m_logic);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_finish_substate);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_reload_one_substate);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_start_substate);
  survarium::weapon_core_shotgun_reload_state::~weapon_core_shotgun_reload_state(v4, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::shotgun_weapon_reload_state *__thiscall survarium::shotgun_weapon_reload_state::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::shotgun_weapon_reload_state::`vector deleting destructor'(
           (survarium::shotgun_weapon_reload_state *)(this - 24),
           a2);
}
