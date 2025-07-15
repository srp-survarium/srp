BOOL __thiscall survarium::weapon_core::chamber_a_round_AE_pred(survarium::weapon_core *this)
{
  return survarium::weapon_core::chamber_a_round_pred(this)
      && *(&this->m_logic->m_current_state[12].transitions.gap4 + 1);
}
