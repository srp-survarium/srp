void __thiscall survarium::single_player_respawn_rule::on_player_left_match(
        survarium::single_player_respawn_rule *this,
        survarium::base_player *player,
        const unsigned int current_time_in_ms)
{
  player->remove(player, 1);
}
