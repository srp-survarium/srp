void __thiscall survarium::weapon_core_throw_grenade_state::register_animations(
        survarium::weapon_core_throw_grenade_state *this,
        survarium::animations_registry *registry)
{
  vostok::ai::fsm_state *i; // esi

  for ( i = this->m_logic.m_states.m_first; i; i = i->next )
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::animations_registry *))i->__vftable[1].~vostok::ai::fsm_state)(
      i,
      registry);
}
