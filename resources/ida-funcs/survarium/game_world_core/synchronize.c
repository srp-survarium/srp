unsigned __int8 __thiscall survarium::game_world_core::synchronize<survarium::packet_sender>(
        survarium::game_world_core *this,
        _DWORD *client_id,
        unsigned int oldest_aware_event_time_in_ms,
        unsigned int current_time_in_ms,
        survarium::packet_sender *predicate)
{
  _DWORD *v5; // esi
  survarium::game_event_history_item *v7; // eax
  int v8; // edi
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v9; // ecx
  survarium::game_event_history_item *v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // edi
  int v13; // edx
  vostok::render::stage_screen_space_reflections *v14; // ecx
  int v15; // eax
  int v16; // edi
  unsigned int time_in_ms; // eax
  int v18; // eax
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v19; // [esp-4h] [ebp-34h]
  survarium::player_update v20; // [esp+10h] [ebp-20h] BYREF
  unsigned int v21; // [esp+24h] [ebp-Ch]
  int v22; // [esp+28h] [ebp-8h]
  unsigned int v23; // [esp+2Ch] [ebp-4h]
  char time_in_ms_3; // [esp+3Fh] [ebp+Fh]

  v5 = client_id;
  if ( !client_id[1] )
    return 0;
  survarium::game_world_core::snap_inputs(this, (int)client_id, current_time_in_ms);
  v7 = (survarium::game_event_history_item *)client_id[1];
  v8 = client_id[12795];
  v9 = (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)client_id[12798];
  if ( v8 + v7->time_in_ms <= (unsigned int)v9 )
    v7 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater>(
           v9,
           (int)client_id,
           oldest_aware_event_time_in_ms);
  if ( v7 && v8 + v7->time_in_ms < *(_DWORD *)((char *)&loc_B9937 + client_id[2461] + 1) )
    v7 = 0;
  time_in_ms_3 = 0;
  v10 = v7;
  if ( !v7 )
    return time_in_ms_3;
  while ( (v10->time_in_ms - v5[12796]) % 0x32 )
  {
LABEL_24:
    v10 = v10->next;
    if ( !v10 )
      return time_in_ms_3;
  }
  if ( v10->time_in_ms > current_time_in_ms )
    return time_in_ms_3;
  v11 = 0;
  v23 = 0;
  while ( 1 )
  {
    v12 = v10->players_events_masks.elems[v11];
    v13 = v10->sync_infos.elems[20].clients_events_i_am_aware_of_masks.elems[v11] ^ v12;
    v21 = v12;
    v22 = v13;
    if ( v13 )
      break;
LABEL_23:
    v10->sync_infos.elems[20].clients_events_i_am_aware_of_masks.elems[v11++] = v12;
    v23 = v11;
    if ( v11 >= 3 )
      goto LABEL_24;
  }
  while ( 1 )
  {
    v14 = (vostok::render::stage_screen_space_reflections *)(((v13 & ~(v13 - 1) & 0xAAAAAAAA) != 0)
                                                           | (2
                                                            * (((v13 & ~(v13 - 1) & 0xCCCCCCCC) != 0)
                                                             | (2
                                                              * (((v13 & ~(v13 - 1) & 0xF0F0F0F0) != 0)
                                                               | (2
                                                                * (((v13 & ~(v13 - 1) & 0xFF00FF00) != 0)
                                                                 | (2 * ((v13 & ~(v13 - 1) & 0xFFFF0000) != 0)))))))));
    if ( v23 )
      break;
    v15 = *(_DWORD *)(720 * (unsigned __int8)v14 + v5[2465] + 8);
    if ( v15 )
    {
      while ( *(_DWORD *)(v15 + 20) > v10->time_in_ms )
      {
        v15 = *(_DWORD *)(v15 + 4);
        if ( !v15 )
          goto LABEL_17;
      }
      v16 = v15;
    }
    else
    {
LABEL_17:
      v16 = 0;
    }
    if ( v16 )
    {
      time_in_ms = v10->time_in_ms;
      if ( *(_DWORD *)(v16 + 20) == time_in_ms )
      {
        v20.player_id = ((v13 & ~(v13 - 1) & 0xAAAAAAAA) != 0)
                      | (2
                       * (((v13 & ~(v13 - 1) & 0xCCCCCCCC) != 0)
                        | (2
                         * (((v13 & ~(v13 - 1) & 0xF0F0F0F0) != 0)
                          | (2 * (((v13 & ~(v13 - 1) & 0xFF00FF00) != 0) | (2 * ((v13 & ~(v13 - 1) & 0xFFFF0000) != 0))))))));
        v20.input = *(survarium::player_input *)(v16 + 8);
        v20.time_in_ms = time_in_ms;
        survarium::packet_sender::on_player_input_changed(predicate, &v20);
        v5 = client_id;
        v13 = v22;
        time_in_ms_3 = 1;
      }
    }
    v13 &= v13 - 1;
    v22 = v13;
    if ( !v13 )
    {
      v12 = v21;
      v11 = v23;
      goto LABEL_23;
    }
  }
  v19 = (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)v10->time_in_ms;
  vostok::memory::process_allocator::finalize_impl(v14);
  return (unsigned __int8)survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater>(
                            v19,
                            v18,
                            (unsigned int)client_id);
}
