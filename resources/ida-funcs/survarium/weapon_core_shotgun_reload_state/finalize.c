void __thiscall survarium::weapon_core_shotgun_reload_state::finalize(
        survarium::weapon_core_shotgun_reload_state *this)
{
  vostok::ai::fsm *m_logic; // esi
  vostok::ai::fsm_state *m_current_state; // ecx

  m_logic = this->m_logic;
  m_current_state = m_logic->m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    m_logic->m_current_state = 0;
  }
}
