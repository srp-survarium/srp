void __userpurge survarium::shared_statistics::finish_match(
        survarium::shared_statistics *this@<ecx>,
        int a2@<eax>,
        survarium::shared_statistics *winner_team,
        unsigned int active_players_mask)
{
  bool v5; // zf
  survarium::player_shared_statistics *v6; // esi
  int v7; // ebx
  unsigned __int8 v8; // [esp+Eh] [ebp-2h]
  unsigned __int8 v9; // [esp+Fh] [ebp-1h]

  v5 = *(_BYTE *)(a2 + 6152) == 0;
  *(_DWORD *)(a2 + 6136) = active_players_mask;
  *(_DWORD *)(a2 + 6148) = winner_team;
  v8 = winner_team->m_team_points[a2];
  v9 = 0;
  if ( !v5 )
  {
    do
    {
      v6 = (survarium::player_shared_statistics *)(a2 + 212 * v9);
      if ( ((1 << v9) & active_players_mask) != 0 )
        survarium::shared_statistics::on_event(
          (survarium::shared_statistics *)a2,
          (survarium::player_shared_statistics *)(a2 + 212 * v9),
          1u,
          match_stats_event_participating);
      this = winner_team;
      if ( *(survarium::shared_statistics **)(1488 * v9 + *(_DWORD *)(a2 + 6140) + 440) == winner_team )
      {
        survarium::shared_statistics::on_event((survarium::shared_statistics *)a2, v6, 1u, match_stats_event_won);
        if ( v8 )
        {
          v7 = v8;
          do
          {
            survarium::shared_statistics::on_event(
              (survarium::shared_statistics *)a2,
              v6,
              1u,
              match_stats_event_winning_team_victory_item_bonus);
            --v7;
          }
          while ( v7 );
        }
      }
      ++v9;
    }
    while ( v9 < *(_BYTE *)(a2 + 6152) );
  }
  *(_DWORD *)(a2 + 5072) = 0;
  if ( *(_DWORD *)(a2 + 6096) )
    survarium::victory_item_event_manager::clear((survarium::victory_item_event_manager *)this, (_DWORD *)(a2 + 5080));
}
