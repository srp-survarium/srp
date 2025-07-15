int __thiscall survarium::weapon_core::player_stance(survarium::weapon_core *this)
{
  int v3; // eax
  bool m_aimed; // cl
  int v5; // eax

  if ( !this->m_user->m_is_alive )
    return 0;
  v3 = survarium::portable_interactive_object_core::player_stance(
         (survarium::portable_interactive_object_core *)this,
         (int)this->m_portable_interactive_object);
  m_aimed = this->m_aimed;
  if ( !v3 )
    return m_aimed;
  v5 = v3 - 2;
  if ( !v5 )
    return m_aimed + 2;
  if ( v5 == 2 )
    return m_aimed + 4;
  return m_aimed + 6;
}
