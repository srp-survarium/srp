survarium::game_event_history_item *__thiscall survarium::game_world_core::insert_impl(
        survarium::game_world_core *this,
        survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *player_id,
        survarium::game_event_history_item::events_enum event,
        const unsigned int time_in_ms,
        unsigned int is_player_aware_of,
        const bool is_server_aware_of,
        char a7)
{
  bool has_passed_filters; // al
  survarium::game_event_history_item *v10; // eax
  survarium::game_world_core *v11; // ecx
  survarium::game_event_history_item *v12; // edi
  survarium::game_event_history_item::sync_info *v13; // eax
  survarium::game_event_history_item *m_first; // esi
  survarium::game_event_history_item *v15; // ecx
  vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> *v16; // eax
  survarium::game_world_core *v17; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v18; // [esp+10h] [ebp-28h] BYREF
  survarium::game_event_history_item *v19; // [esp+34h] [ebp-4h]
  char v20; // [esp+40h] [ebp+8h]
  char v21; // [esp+43h] [ebp+Bh]

  v20 = 0;
  if ( !player_id[492].m_items.m_first
    || survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less>(
         (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)this,
         (int)&player_id[492],
         is_player_aware_of) )
  {
    v10 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater_equal>(
            &this->m_game_events_history,
            (int)player_id,
            is_player_aware_of);
    v19 = v10;
    if ( v10 && is_player_aware_of == v10->time_in_ms )
    {
      v21 = 1;
    }
    else
    {
      v21 = 0;
      survarium::game_world_core::new_game_event_history_item(v11, (int)player_id);
    }
    v12 = v10;
    v13 = &v10->sync_infos.elems[(unsigned __int8)event];
    v13->my_events_mask |= 1 << time_in_ms;
    if ( is_server_aware_of )
      v13->clients_events_i_am_aware_of_masks.elems[time_in_ms] |= 1 << event;
    if ( a7 )
      v12->sync_infos.elems[20].clients_events_i_am_aware_of_masks.elems[time_in_ms] |= 1 << event;
    v12->players_events_masks.elems[time_in_ms] |= 1 << event;
    v12->time_in_ms = is_player_aware_of;
    if ( !v21 )
    {
      m_first = v19;
      if ( v19 == v12 )
        m_first = player_id->m_items.m_first;
      survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::insert(
        player_id,
        m_first,
        v12);
    }
    v15 = player_id[2559].m_items.m_first;
    if ( (v12->time_in_ms - (int)v15) % 0x32 )
      player_id[2560].m_items.m_size = v12->time_in_ms
                                     + (player_id[2560].m_items.m_size < v12->time_in_ms
                                      ? player_id[2560].m_items.m_size - v12->time_in_ms
                                      : 0);
    v16 = (vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> *)((char *)v15 + 50 * (((unsigned int)v15 < v12->time_in_ms ? v12->time_in_ms - (unsigned int)v15 - 1 : 0) / 0x32));
    player_id[2559].m_allocator = (vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> *)((char *)v16 + (player_id[2559].m_allocator < v16 ? (char *)player_id[2559].m_allocator - (char *)v16 : 0));
    return v12;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"net_events",
                                 (const char *)3),
          this = v17,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v18);
      v20 = 1;
      vostok::logging::append(
        &v18,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x1B4u,
        "class survarium::game_event_history_item *__thiscall survarium::game_world_core::insert_impl(const unsigned char"
        ",const enum survarium::game_event_history_item::events_enum,const unsigned int,const bool,const bool)",
        "net_events",
        warning,
        "SKIPPING input %d.%03d (oldest is %d.%03d)",
        is_player_aware_of / 0x3E8,
        is_player_aware_of % 0x3E8,
        *(_DWORD *)((char *)&loc_B9937 + (unsigned int)player_id[492].m_items.m_first + 1) / 0x3E8u,
        *(_DWORD *)((char *)&loc_B9937 + (unsigned int)player_id[492].m_items.m_first + 1) % 0x3E8u);
    }
    if ( (v20 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v18);
    return 0;
  }
}
