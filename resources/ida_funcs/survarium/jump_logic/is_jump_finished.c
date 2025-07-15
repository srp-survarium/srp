bool __thiscall survarium::jump_logic::is_jump_finished(survarium::jump_logic *this)
{
  return *(&this->m_logic->m_current_state[1].transitions.gap4 + 1);
}
