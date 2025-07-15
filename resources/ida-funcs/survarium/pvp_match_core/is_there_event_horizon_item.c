bool __usercall survarium::pvp_match_core::is_there_event_horizon_item@<al>(
        survarium::pvp_match_core *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax
  survarium::game_world_core *v3; // ecx
  int v5; // esi
  unsigned int v6; // edi
  survarium::game_state_history_item *v7; // eax

  v2 = *(_DWORD *)(a2 + 312);
  v3 = *(survarium::game_world_core **)(v2 + 9844);
  if ( !v3 )
    return 0;
  if ( *(_BYTE *)(v2 + 51213) )
    return 1;
  v5 = *(_DWORD *)(v2 + 51180);
  v6 = *(_DWORD *)(v2 + 51192);
  if ( v5 + *(unsigned int *)((char *)&v3->m_game_events_history.m_items.m_size + (_DWORD)&loc_B9937 + 1) <= v6 )
    v7 = survarium::game_world_core::event_horizon_history_item(v3, v2);
  else
    v7 = *(survarium::game_state_history_item **)(v2 + 9844);
  return !v7->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B993F + 2]
      && v5 + *(_DWORD *)&v7->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1] <= v6;
}
