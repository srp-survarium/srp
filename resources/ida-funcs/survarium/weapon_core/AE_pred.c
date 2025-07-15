bool __thiscall survarium::weapon_core::AE_pred(survarium::weapon_core *this)
{
  return *(&this->m_logic->m_current_state[12].transitions.gap4 + 1);
}
