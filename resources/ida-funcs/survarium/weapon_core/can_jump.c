BOOL __thiscall survarium::weapon_core::can_jump(survarium::weapon_core *this)
{
  unsigned int m_size; // eax

  m_size = this->m_logic->m_current_state[12].transitions.m_size;
  return m_size == 3 || m_size == 4;
}
