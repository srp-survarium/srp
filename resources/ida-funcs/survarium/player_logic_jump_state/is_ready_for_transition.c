BOOL __thiscall survarium::player_logic_jump_state::is_ready_for_transition(survarium::player_logic_jump_state *this)
{
  return BYTE1(this->m_logic.m_logic.m_current_state[1].transitions.m_first)
      || this->m_user->damage_model(&this->m_user->survarium::inventory_holder)->m_object->m_broken_legs_count == 2
      || !this->m_user->m_is_alive;
}
