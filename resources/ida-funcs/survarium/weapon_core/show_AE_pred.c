BOOL __thiscall survarium::weapon_core::show_AE_pred(survarium::weapon_core *this)
{
  return !survarium::weapon_core::inactive_pred(this) && *(&this->m_logic->m_current_state[12].transitions.gap4 + 1);
}
