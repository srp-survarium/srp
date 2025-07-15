bool __thiscall survarium::timelimit_rule_core::rule_completed(
        survarium::timelimit_rule_core *this,
        const unsigned int current_time_in_ms)
{
  unsigned int v2; // edx
  bool result; // al
  bool v4; // cf

  v2 = current_time_in_ms - this->m_state_start_time_ms;
  result = 0;
  if ( this->m_current_state == game_status_waiting_for_players )
  {
    v4 = v2 < this->m_wait_players_time;
  }
  else
  {
    if ( this->m_current_state != game_status_inprocess )
      return result;
    v4 = v2 < this->m_match_length_ms;
  }
  return 1 - v4;
}
