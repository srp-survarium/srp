void __thiscall survarium::timelimit_rule_core::on_match_ready(
        survarium::timelimit_rule_core *this,
        unsigned int current_time_in_ms)
{
  this->m_current_state = game_status_waiting_for_players;
  this->m_state_start_time_ms = current_time_in_ms;
  this->m_current_time_in_ms = current_time_in_ms;
}
