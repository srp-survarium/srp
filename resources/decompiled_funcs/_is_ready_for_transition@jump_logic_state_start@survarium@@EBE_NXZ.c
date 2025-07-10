bool __thiscall survarium::jump_logic_state_start::is_ready_for_transition(survarium::jump_logic_state_start *this)
{
  return this->m_jump_interval_ended;
}
