void __userpurge survarium::game_world_core::tick_events(
        survarium::game_state_history_item *game_state@<eax>,
        survarium::game_world_core *this,
        survarium::game_event_history_item *game_event,
        survarium::base_player *time_in_ms)
{
  survarium::game_world_core *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ecx
  char *v7; // eax
  survarium::base_player *v8; // ebx
  survarium::game_state_history_item *v9; // eax
  survarium::game_state_history_item *item; // [esp+10h] [ebp-4h]

  do
  {
    v4 = this;
    if ( !*(_DWORD *)&game_state->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1] )
      this->m_valid_time_in_ms = -1;
    v5 = this->m_start_fixed_time_in_ms
       + 50 * ((this->m_current_time_in_ms - this->m_start_fixed_time_in_ms) / 0x32 + 1);
    if ( game_event )
      v6 = game_event->time_in_ms;
    else
      v6 = -1;
    v7 = (char *)time_in_ms + ((v6 - (_DWORD)time_in_ms) & ((v6 - (unsigned __int64)(unsigned int)time_in_ms) >> 32));
    v8 = (survarium::base_player *)&v7[v5 < (unsigned int)v7 ? v5 - (_DWORD)v7 : 0];
    if ( (survarium::base_player *)v6 == v8 )
    {
      survarium::game_world_core::process_events(game_event, this);
      v4 = this;
      game_event = game_event->next;
    }
    if ( v8 != (survarium::base_player *)v4->m_current_time_in_ms )
    {
      survarium::game_world_core::atomic_tick(
        (survarium::game_world_core *)v6,
        (int)v4,
        v8,
        (unsigned int)v8 - v4->m_current_time_in_ms);
      v4 = this;
    }
    if ( v8 == (survarium::base_player *)v5 )
    {
      v9 = *(survarium::game_state_history_item **)&game_state->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1];
      if ( !v9 )
        survarium::game_world_core::new_game_state_history_item((survarium::game_world_core *)v6, (int)v4);
      item = v9;
      survarium::game_world_core::serialize((survarium::game_world_core *)v6, (int)v4, v9);
      if ( !*(_DWORD *)&game_state->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1] )
        survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::insert(
          &v4->m_game_states_history,
          item);
      game_state = item;
    }
  }
  while ( v8 != time_in_ms );
}
