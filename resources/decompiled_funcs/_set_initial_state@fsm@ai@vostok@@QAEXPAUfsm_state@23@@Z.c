void __thiscall vostok::ai::fsm::set_initial_state(vostok::ai::fsm *this, vostok::ai::fsm_state *initial_state)
{
  if ( this->m_current_state != initial_state )
  {
    if ( this->m_current_state )
      this->m_current_state->finalize(this->m_current_state);
    this->m_current_state = initial_state;
    if ( this->m_current_state )
      this->m_current_state->initialize(this->m_current_state);
  }
}
