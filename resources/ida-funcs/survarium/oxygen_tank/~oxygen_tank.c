void __thiscall survarium::oxygen_tank::~oxygen_tank(survarium::oxygen_tank *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  char **p_m_influences; // [esp+4h] [ebp-14h]
  unsigned int i; // [esp+14h] [ebp-4h]

  this->__vftable = (survarium::oxygen_tank_vtbl *)&survarium::oxygen_tank::`vftable';
  for ( i = 0; i < this->m_influences_count; ++i )
    ((void (__thiscall *)(survarium::oxygen_tank::item_influence *, _DWORD))this->m_influences[i].protector.~survarium::damage_protector)(
      &this->m_influences[i],
      0);
  p_m_influences = (char **)&this->m_influences;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_influences);
  if ( this->m_influences )
  {
    vostok::memory::doug_lea_allocator::free_impl(v1, *p_m_influences);
    *p_m_influences = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(this);
}
