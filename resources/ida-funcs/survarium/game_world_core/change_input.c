int __thiscall survarium::game_world_core::change_input(
        survarium::game_world_core *this,
        survarium::game_world_core *update,
        unsigned __int8 *is_server_aware_of,
        char a4)
{
  unsigned int v4; // edx
  bool has_passed_filters; // al
  char *v6; // eax
  unsigned int m_event_horizon_interval_in_ms; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *m_max_current_time_in_ms; // ecx
  bool v10; // al
  char *v11; // eax
  bool v12; // al
  char *v13; // eax
  int v14; // ecx
  unsigned int v15; // eax
  survarium::fixed_history<survarium::player_input_history_item,27> *v16; // esi
  survarium::player_input_history_item *i; // edx
  vostok::memory::single_size_buffer_allocator<24,vostok::threading::single_threading_policy>::node *v18; // eax
  survarium::game_world_core *v19; // ecx
  survarium::game_world_core *v20; // ecx
  survarium::player_input_history_item *v21; // esi
  const survarium::player_input *p_m_last; // edx
  survarium::fixed_history<survarium::player_input_history_item,27> *v23; // eax
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *m_first; // ecx
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v25; // edi
  vostok::memory::single_size_buffer_allocator<24,vostok::threading::single_threading_policy>::node *v26; // eax
  survarium::game_world_core *v27; // ecx
  unsigned int v28; // [esp-10h] [ebp-48h]
  unsigned int v29; // [esp-10h] [ebp-48h]
  unsigned int v30; // [esp-10h] [ebp-48h]
  unsigned int v31; // [esp-Ch] [ebp-44h]
  unsigned int v32; // [esp-Ch] [ebp-44h]
  unsigned int v33; // [esp-Ch] [ebp-44h]
  unsigned int v34; // [esp-8h] [ebp-40h]
  unsigned int v35; // [esp-8h] [ebp-40h]
  unsigned int v36; // [esp-8h] [ebp-40h]
  survarium::game_world_core *v37; // [esp-4h] [ebp-3Ch]
  unsigned int v38; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v40; // [esp-4h] [ebp-3Ch]
  unsigned int v41; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v42; // [esp-4h] [ebp-3Ch]
  unsigned int v43; // [esp-4h] [ebp-3Ch]
  bool v44; // [esp+0h] [ebp-38h]
  char insert_before; // [esp+10h] [ebp-28h]
  survarium::player_input_history_item *insert_beforea; // [esp+10h] [ebp-28h]
  survarium::player_input_history_item *insert_beforeb; // [esp+10h] [ebp-28h]
  survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *v48; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v49; // [esp+18h] [ebp-20h] BYREF

  v4 = *((_DWORD *)is_server_aware_of + 4);
  insert_before = 0;
  if ( v4 <= update->m_last_resync_time_in_ms )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"net_sync",
                                 (const char *)3),
          this = v37,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v49);
      insert_before = 1;
      v38 = update->m_last_resync_time_in_ms % 0x3E8;
      v34 = update->m_last_resync_time_in_ms / 0x3E8;
      v31 = *((_DWORD *)is_server_aware_of + 4) % 0x3E8u;
      v28 = *((_DWORD *)is_server_aware_of + 4) / 0x3E8u;
      v6 = survarium::game_world_core::profile_name(update, *is_server_aware_of);
      vostok::logging::append(
        &v49,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x216u,
        "enum survarium::input_action_enum __thiscall survarium::game_world_core::change_input(const struct survarium::pl"
        "ayer_update &,const bool)",
        "net_sync",
        warning,
        "change input (client %s) request REJECTED, reason: older than last resync %d.%03d, but %d.%03d",
        v6,
        v28,
        v31,
        v34,
        v38);
    }
    if ( (insert_before & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v49);
    return 4;
  }
  if ( update->m_is_server )
    m_event_horizon_interval_in_ms = 0;
  else
    m_event_horizon_interval_in_ms = update->m_event_horizon_interval_in_ms;
  m_max_current_time_in_ms = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)update->m_max_current_time_in_ms;
  if ( v4 + m_event_horizon_interval_in_ms <= (unsigned int)m_max_current_time_in_ms )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v10 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
          m_max_current_time_in_ms = v40,
          v10) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_max_current_time_in_ms,
        &v49);
      insert_before = 2;
      v41 = update->m_max_current_time_in_ms % 0x3E8;
      v35 = update->m_max_current_time_in_ms / 0x3E8;
      v32 = *((_DWORD *)is_server_aware_of + 4) % 0x3E8u;
      v29 = *((_DWORD *)is_server_aware_of + 4) / 0x3E8u;
      v11 = survarium::game_world_core::profile_name(update, *is_server_aware_of);
      vostok::logging::append(
        &v49,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x221u,
        "enum survarium::input_action_enum __thiscall survarium::game_world_core::change_input(const struct survarium::pl"
        "ayer_update &,const bool)",
        "net_sync",
        warning,
        "change input (client %s) request REJECTED, reason: too old %d.%03d, but %d.%03d",
        v11,
        v29,
        v32,
        v35,
        v41);
    }
    if ( (insert_before & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_max_current_time_in_ms,
        (int *)&v49);
    return 2;
  }
  if ( a4 )
  {
    if ( update->m_game_states_history.m_items.m_first
      && v4 > (unsigned int)m_max_current_time_in_ms + 5 * update->m_event_horizon_interval_in_ms )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
            m_max_current_time_in_ms = v42,
            v12) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          m_max_current_time_in_ms,
          &v49);
        insert_before = 4;
        v43 = update->m_max_current_time_in_ms % 0x3E8;
        v36 = update->m_max_current_time_in_ms / 0x3E8;
        v33 = *((_DWORD *)is_server_aware_of + 4) % 0x3E8u;
        v30 = *((_DWORD *)is_server_aware_of + 4) / 0x3E8u;
        v13 = survarium::game_world_core::profile_name(update, *is_server_aware_of);
        vostok::logging::append(
          &v49,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x22Cu,
          "enum survarium::input_action_enum __thiscall survarium::game_world_core::change_input(const struct survarium::"
          "player_update &,const bool)",
          "net_sync",
          warning,
          "change input (client %s) request REJECTED, reason: too new %d.%03d, but %d.%03d",
          v13,
          v30,
          v33,
          v36,
          v43);
      }
      if ( (insert_before & 4) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_max_current_time_in_ms,
          (int *)&v49);
      return 3;
    }
    v23 = &update->m_players_inputs_history.m_begin[*is_server_aware_of];
    m_first = (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)v23->m_items.m_first;
    v48 = v23;
    while ( 1 )
    {
      if ( !m_first )
      {
        insert_beforeb = 0;
        v25 = 0;
        goto LABEL_51;
      }
      if ( m_first[1].m_items.m_size >= v4 )
        break;
      m_first = (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)m_first->m_items.m_size;
    }
    v25 = m_first;
    insert_beforeb = (survarium::player_input_history_item *)m_first;
LABEL_51:
    if ( v25 && v25[1].m_items.m_size == v4 )
    {
      p_m_last = (const survarium::player_input *)&v25->m_items.m_last;
      return survarium::operator==((const survarium::player_input *)(is_server_aware_of + 4), p_m_last) ? 1 : 4;
    }
    v26 = survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::new_item(
            m_first,
            (int)v23);
    *(_DWORD *)&v26->data[8] = *((_DWORD *)is_server_aware_of + 1);
    *(_DWORD *)&v26->data[12] = *((_DWORD *)is_server_aware_of + 2);
    *(_DWORD *)&v26->data[16] = *((_DWORD *)is_server_aware_of + 3);
    *(_DWORD *)&v26->data[20] = *((_DWORD *)is_server_aware_of + 4);
    survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
      v48,
      insert_beforeb,
      (survarium::player_input_history_item *)v26);
    survarium::game_world_core::insert_impl(
      v27,
      &update->m_game_events_history,
      (survarium::game_event_history_item::events_enum)*is_server_aware_of,
      0,
      *((_DWORD *)is_server_aware_of + 4),
      1,
      a4);
  }
  else
  {
    v14 = 50;
    LOBYTE(v14) = *is_server_aware_of;
    v15 = update->m_start_fixed_time_in_ms
        + 50 * ((update->m_start_fixed_time_in_ms < v4 ? v4 - update->m_start_fixed_time_in_ms - 1 : 0) / 0x32);
    v16 = &update->m_players_inputs_history.m_begin[*is_server_aware_of];
    for ( i = v16->m_items.m_first; ; i = i->next )
    {
      if ( !i )
      {
        insert_beforea = 0;
        goto LABEL_33;
      }
      if ( i->time_in_ms > v15 )
        break;
    }
    insert_beforea = i;
LABEL_33:
    if ( insert_beforea )
    {
      if ( !survarium::game_world_core::erase_impl(
              (survarium::game_world_core *)v14,
              update,
              v14,
              insert_beforea->time_in_ms,
              0,
              v44) )
        return 4;
      survarium::game_world_core::insert_impl(
        v20,
        &update->m_game_events_history,
        (survarium::game_event_history_item::events_enum)*is_server_aware_of,
        0,
        *((_DWORD *)is_server_aware_of + 4),
        1,
        0);
      v21 = v16->m_items.m_first;
      if ( v21 )
      {
        while ( v21->time_in_ms <= insert_beforea->time_in_ms )
        {
          v21 = v21->next;
          if ( !v21 )
            goto LABEL_40;
        }
      }
      else
      {
LABEL_40:
        v21 = 0;
      }
      if ( v21 && v21->time_in_ms == *((_DWORD *)is_server_aware_of + 4) )
      {
        p_m_last = &v21->input;
        return survarium::operator==((const survarium::player_input *)(is_server_aware_of + 4), p_m_last) ? 1 : 4;
      }
      insert_beforea->time_in_ms = *((_DWORD *)is_server_aware_of + 4);
      insert_beforea->input.rotation_delta.x = insert_beforea->input.rotation_delta.x
                                             + *((float *)is_server_aware_of + 1);
      insert_beforea->input.rotation_delta.y = *((float *)is_server_aware_of + 2)
                                             + insert_beforea->input.rotation_delta.y;
      insert_beforea->input.actions_mask |= *((_DWORD *)is_server_aware_of + 3);
    }
    else
    {
      v18 = survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy>>::new_item(
              (survarium::history<survarium::player_input_history_item,vostok::memory::single_size_fixed_allocator<24,27,vostok::threading::single_threading_policy> > *)v14,
              (int)v16);
      *(_DWORD *)&v18->data[8] = *((_DWORD *)is_server_aware_of + 1);
      *(_DWORD *)&v18->data[12] = *((_DWORD *)is_server_aware_of + 2);
      *(_DWORD *)&v18->data[16] = *((_DWORD *)is_server_aware_of + 3);
      *(_DWORD *)&v18->data[20] = *((_DWORD *)is_server_aware_of + 4);
      survarium::history<survarium::players_mask_history_item,vostok::memory::single_size_fixed_allocator<16,40,vostok::threading::single_threading_policy>>::insert(
        v16,
        0,
        (survarium::player_input_history_item *)v18);
      survarium::game_world_core::insert_impl(
        v19,
        &update->m_game_events_history,
        (survarium::game_event_history_item::events_enum)*is_server_aware_of,
        0,
        *((_DWORD *)is_server_aware_of + 4),
        1,
        0);
    }
  }
  return 0;
}
