bool __thiscall survarium::weapon_core::is_ready_to_be_deactivated(survarium::weapon_core *this)
{
  return LOBYTE(this->m_logic->m_current_state[12].transitions.m_last)
      && survarium::weapon_user_animations_selector::is_ready_to_be_deactivated(&this->m_user_animations_selector);
}
