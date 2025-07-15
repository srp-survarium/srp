// attributes: thunk
void __thiscall survarium::single_player_respawn_rule::on_player_entered_match(
        survarium::single_player_respawn_rule *this,
        survarium::base_player *player,
        unsigned int current_time_in_ms)
{
  survarium::single_player_respawn_rule::spawn_player(this, player, current_time_in_ms);
}
