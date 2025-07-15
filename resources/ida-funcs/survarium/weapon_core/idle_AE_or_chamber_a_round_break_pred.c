int __thiscall survarium::weapon_core::idle_AE_or_chamber_a_round_break_pred(survarium::weapon_core *this)
{
  int result; // eax

  result = 0;
  if ( *(&this->m_logic->m_current_state[12].transitions.gap4 + 1) || !this->m_user->m_is_alive )
    return 1;
  return result;
}
