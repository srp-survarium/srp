BOOL __thiscall survarium::weapon_core::idle_AE_not_fire_pred(survarium::weapon_core *this)
{
  return *(&this->m_logic->m_current_state[12].transitions.gap4 + 1) && !survarium::weapon_core::fire_pred(this);
}
