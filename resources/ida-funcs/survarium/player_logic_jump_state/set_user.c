void __thiscall survarium::player_logic_jump_state::set_user(
        survarium::player_logic_jump_state *this,
        survarium::base_player *user)
{
  vostok::ai::fsm_state *m_first; // esi

  this->m_user = user;
  m_first = this->m_logic.m_logic.m_states.m_first;
  this->m_logic.m_user = user;
  while ( m_first )
  {
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::base_player *))m_first->__vftable[1].~vostok::ai::fsm_state)(
      m_first,
      user);
    m_first = m_first->next;
  }
}
