void __thiscall survarium::single_player_respawn_rule::tick(
        survarium::single_player_respawn_rule *this,
        const unsigned int time_delta_in_ms,
        unsigned int current_time_in_ms)
{
  boost::array<unsigned int,20> *p_m_player_death_times; // esi
  survarium::base_player *v5; // edi
  survarium::single_player_respawn_rule *v6; // ecx
  unsigned __int8 v7; // [esp+Ch] [ebp-4h]

  v7 = 0;
  p_m_player_death_times = &this->m_player_death_times;
  do
  {
    if ( p_m_player_death_times->elems[0] != -1 && p_m_player_death_times->elems[0] + 5000 <= current_time_in_ms )
    {
      v5 = survarium::game_world_core::player(this->m_game_world_core, v7);
      v5->remove(v5, 1);
      survarium::single_player_respawn_rule::spawn_player(v6, v5, current_time_in_ms);
      p_m_player_death_times->elems[0] = -1;
    }
    ++v7;
    p_m_player_death_times = (boost::array<unsigned int,20> *)((char *)p_m_player_death_times + 4);
  }
  while ( v7 < 0x14u );
}
