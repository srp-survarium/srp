void __thiscall survarium::player_respawn_rule::on_player_entered_match(
        survarium::player_respawn_rule *this,
        survarium::base_player *player,
        unsigned int current_time_in_ms)
{
  this->m_player_respawn_times.elems[player->id] = current_time_in_ms;
}
