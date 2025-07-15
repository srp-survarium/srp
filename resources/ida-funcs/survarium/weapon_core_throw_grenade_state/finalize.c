void __thiscall survarium::weapon_core_throw_grenade_state::finalize(survarium::weapon_core_throw_grenade_state *this)
{
  vostok::ai::fsm_state **p_m_current_state; // esi
  vostok::ai::fsm_state *m_current_state; // ecx
  survarium::grenade_set_core *m_object; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+8h] [ebp-4h] BYREF

  p_m_current_state = &this->m_logic.m_current_state;
  m_current_state = this->m_logic.m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    *p_m_current_state = 0;
  }
  m_object = this->m_grenade_set.m_object;
  this->m_grenade_set.m_object = 0;
  v5.m_object = (vostok::particle::particle_system_instance_impl *)m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
}
