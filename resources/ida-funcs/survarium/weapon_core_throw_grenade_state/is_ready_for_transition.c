BOOL __thiscall survarium::weapon_core_throw_grenade_state::is_ready_for_transition(
        survarium::weapon_core_throw_grenade_state *this)
{
  vostok::ai::fsm_state *m_current_state; // ecx

  m_current_state = this->m_logic.m_current_state;
  return m_current_state[2].transitions.gap4 && m_current_state->is_ready_for_transition(m_current_state);
}
