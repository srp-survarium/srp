void __thiscall vostok::ai::fsm::tick(vostok::ai::fsm *this)
{
  vostok::ai::fsm_state_transition *i; // [esp+134h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_current_state->is_ready_for_transition(this->m_current_state) )
  {
    for ( i = this->m_current_state->transitions.m_first; i; i = i->next )
    {
      if ( (unsigned __int8)boost::function0<bool>::operator()(&i->predicate) )
      {
        this->m_current_state->finalize(this->m_current_state);
        this->m_current_state = i->target_state;
        this->m_current_state->initialize(this->m_current_state);
        break;
      }
    }
  }
  this->m_current_state->execute(this->m_current_state);
}
