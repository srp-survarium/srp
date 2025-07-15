BOOL __thiscall survarium::weapon_core::can_aim(survarium::weapon_core *this)
{
  unsigned int m_size; // eax

  m_size = this->m_logic->m_current_state[12].transitions.m_size;
  return m_size == 3 || m_size == 5 || m_size == 6 && this->m_chamber_a_round_while_aiming;
}
