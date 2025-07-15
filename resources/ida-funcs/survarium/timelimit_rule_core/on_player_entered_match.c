void __thiscall survarium::timelimit_rule_core::on_player_entered_match(
        survarium::timelimit_rule_core *this,
        survarium::timelimit_rule_core *player,
        unsigned int current_time_in_ms)
{
  survarium::timelimit_rule_core *v4; // ecx

  v4 = player;
  LOBYTE(v4) = player->m_countdown_time;
  this->m_players_mask |= 1 << (char)v4;
  survarium::timelimit_rule_core::logic_tick(v4, (int)this, current_time_in_ms);
}
