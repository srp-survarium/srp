char __userpurge survarium::game_world_core::erase_impl@<al>(
        survarium::game_world_core *this@<ecx>,
        _DWORD *a2@<eax>,
        const unsigned __int8 player_id,
        unsigned int event,
        char time_in_ms,
        const bool can_server_be_aware_of)
{
  survarium::game_event_history_item *v7; // esi
  survarium::game_event_history_item::sync_info *v8; // eax
  int v9; // edx
  boost::array<unsigned int,3> *p_players_events_masks; // ebx
  survarium::game_state_history_item *v11; // eax
  unsigned int i; // eax
  survarium::game_event_history_item *prev; // ecx
  survarium::game_event_history_item *next; // eax
  int v16; // edi

  v7 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater_equal>(
         &this->m_game_events_history,
         (int)a2,
         event);
  v8 = &v7->sync_infos.elems[player_id];
  v8->my_events_mask &= ~1u;
  v9 = ~(1 << player_id);
  v8->clients_events_i_am_aware_of_masks.elems[0] &= v9;
  if ( time_in_ms )
    v7->sync_infos.elems[20].clients_events_i_am_aware_of_masks.elems[0] &= v9;
  p_players_events_masks = &v7->players_events_masks;
  v7->players_events_masks.elems[0] &= v9;
  v11 = survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less>(
          (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)player_id,
          (int)(a2 + 2460),
          v7->time_in_ms);
  if ( v11 )
    a2[12799] = *(_DWORD *)&v11->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]
              + (a2[12799] < *(_DWORD *)&v11->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]
               ? a2[12799] - *(_DWORD *)&v11->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]
               : 0);
  for ( i = 0; i < 3; ++i )
  {
    if ( p_players_events_masks->elems[0] )
      return 0;
    p_players_events_masks = (boost::array<unsigned int,3> *)((char *)p_players_events_masks + 4);
  }
  if ( a2[1] )
  {
    prev = v7->prev;
    next = v7->next;
    v7->prev = 0;
    v7->next = 0;
    if ( prev )
      prev->next = next;
    else
      a2[1] = next;
    if ( next )
      next->prev = prev;
    else
      a2[2] = prev;
    v7->prev = 0;
    v7->next = 0;
    --*a2;
  }
  v16 = a2[4];
  v7->sync_infos.elems[0].my_events_mask = *(_DWORD *)(v16 + 32);
  *(_DWORD *)(v16 + 32) = v7;
  --*(_DWORD *)(v16 + 36);
  return 1;
}
