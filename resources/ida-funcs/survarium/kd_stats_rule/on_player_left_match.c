void __thiscall survarium::kd_stats_rule::on_player_left_match(
        survarium::kd_stats_rule *this,
        survarium::base_player *player,
        const unsigned int __formal)
{
  this->m_kd_stats[player->id].online = 0;
}
