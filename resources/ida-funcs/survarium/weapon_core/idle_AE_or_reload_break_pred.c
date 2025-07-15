BOOL __thiscall survarium::weapon_core::idle_AE_or_reload_break_pred(survarium::weapon_core *this)
{
  vostok::ai::fsm_state *m_current_state; // ecx

  m_current_state = this->m_logic->m_current_state;
  return *(&m_current_state[12].transitions.gap4 + 1)
      || survarium::weapon_core::reload_break_pred((survarium::weapon_core *)m_current_state);
}
