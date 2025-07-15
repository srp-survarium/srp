void __userpurge survarium::victory_item_event_manager::calculate_players_share(
        survarium::victory_item_event_manager *this@<eax>,
        const survarium::victory_item_status *item_status@<edx>,
        survarium::game_team_id winner_team@<edi>,
        boost::array<float,20> *players_share)
{
  const survarium::match_options *m_match_options; // eax
  float v5; // xmm3_4
  float v6; // xmm2_4
  unsigned int i; // ecx
  float v8; // xmm0_4
  boost::array<float,20> *v9; // ecx
  unsigned int v10; // ebx
  int v11; // edx
  float v12; // xmm0_4

  m_match_options = this->m_match_options;
  v5 = 0.0;
  v6 = 0.0;
  for ( i = 0; i < m_match_options->players_count; ++i )
  {
    v8 = item_status->carried_distances.elems[i];
    if ( m_match_options->player_profiles.elems[(unsigned __int8)i].team == winner_team )
      v5 = v8 + v5;
    else
      v6 = v8 + v6;
  }
  if ( item_status->owner_team == winner_team )
  {
    if ( s_bm_current_air_resistance <= v6 )
      v6 = s_bm_current_air_resistance;
  }
  else
  {
    v6 = s_bm_current_air_resistance;
  }
  v9 = players_share;
  v10 = 0;
  v11 = (char *)item_status - (char *)players_share;
  while ( v10 < m_match_options->players_count )
  {
    if ( m_match_options->player_profiles.elems[(unsigned __int8)v10].team == winner_team )
      v12 = (float)(*(float *)((char *)v9->elems + v11) / v5) * v6;
    else
      v12 = 0.0;
    v9->elems[0] = v12;
    ++v10;
    v9 = (boost::array<float,20> *)((char *)v9 + 4);
  }
}
