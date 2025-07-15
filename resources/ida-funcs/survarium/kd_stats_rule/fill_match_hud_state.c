void __thiscall survarium::kd_stats_rule::fill_match_hud_state(
        survarium::kd_stats_rule *this,
        survarium::match_hud_state *state,
        const unsigned int __formal)
{
  unsigned __int8 i; // dl
  int v4; // eax
  bool online; // bl

  for ( i = 0; i < this->m_players_count; state->player_kd_stats[v4].online = online )
  {
    v4 = i;
    state->player_kd_stats[i].kills = this->m_kd_stats[i].kills;
    state->player_kd_stats[i].deaths = this->m_kd_stats[i].deaths;
    online = this->m_kd_stats[i++].online;
  }
}
