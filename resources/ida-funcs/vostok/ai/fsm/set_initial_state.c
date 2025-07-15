void __userpurge vostok::ai::fsm::set_initial_state(
        vostok::ai::fsm *this@<esi>,
        vostok::ai::fsm_state *initial_state@<edi>,
        const vostok::ai::fsm::current_state_action_enum action)
{
  vostok::ai::fsm_state *m_current_state; // ecx

  m_current_state = this->m_current_state;
  if ( m_current_state != initial_state || action == ignore_current_state )
  {
    if ( m_current_state && action == finalize_current_state )
      m_current_state->finalize(m_current_state);
    this->m_current_state = initial_state;
    if ( initial_state )
      initial_state->initialize(initial_state);
  }
}
