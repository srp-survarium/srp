BOOL __thiscall survarium::weapon_core::can_sprint(survarium::weapon_core *this)
{
  unsigned int m_size; // eax
  BOOL result; // eax

  result = 0;
  if ( !this->m_aimed )
  {
    m_size = this->m_logic->m_current_state[12].transitions.m_size;
    if ( m_size == 3 || m_size == 4 || m_size == 6 )
      return 1;
  }
  return result;
}
