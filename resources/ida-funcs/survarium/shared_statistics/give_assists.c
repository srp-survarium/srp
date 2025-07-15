void __userpurge survarium::shared_statistics::give_assists(
        survarium::shared_statistics *this@<ecx>,
        survarium::shared_statistics *a2@<eax>,
        const survarium::player_shared_statistics *killer_stats,
        const survarium::player_shared_statistics *victim_stats)
{
  survarium::game_team_id v5; // eax
  unsigned __int8 m_players_count; // bl
  float v7; // xmm0_4
  survarium::intermediate_shared_statistics *p_intermediate; // esi
  survarium::player_shared_statistics *v9; // esi
  float v10; // [esp+Ch] [ebp-14h]
  survarium::game_team_id v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  survarium::shared_statistics *v13; // [esp+18h] [ebp-8h]
  unsigned __int8 v14; // [esp+1Fh] [ebp-1h]

  v5 = survarium::shared_statistics::team(a2, killer_stats);
  m_players_count = a2->m_players_count;
  v7 = 0.0;
  v11 = v5;
  v10 = 0.0;
  if ( m_players_count )
  {
    v13 = a2;
    p_intermediate = &victim_stats->intermediate;
    v12 = m_players_count;
    do
    {
      if ( survarium::shared_statistics::team(a2, v13->m_player_stats.elems) == v11 )
        v7 = p_intermediate->received_damage.elems[0] + v7;
      v13 = (survarium::shared_statistics *)((char *)v13 + 212);
      p_intermediate = (survarium::intermediate_shared_statistics *)((char *)p_intermediate + 4);
      --v12;
    }
    while ( v12 );
    v10 = v7;
  }
  if ( COERCE_FLOAT(LODWORD(v7) & 0x7FFFFFFF) >= 0.000001 )
  {
    v14 = 0;
    if ( m_players_count )
    {
      do
      {
        v9 = &a2->m_player_stats.elems[v14];
        if ( v9 != killer_stats
          && survarium::shared_statistics::team(a2, &a2->m_player_stats.elems[v14]) == v11
          && (float)(victim_stats->intermediate.received_damage.elems[v14] / v10) >= 0.1 )
        {
          survarium::shared_statistics::on_event(a2, v9, 1u, match_stats_event_assist);
        }
        ++v14;
      }
      while ( v14 != a2->m_players_count );
    }
  }
}
