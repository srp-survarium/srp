bool __userpurge survarium::game_world_core::leave_match@<al>(
        survarium::game_world_core *this@<ecx>,
        survarium::game_world_core *a2@<edi>,
        __int32 player_id,
        unsigned int time_in_ms)
{
  unsigned int v4; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *m_event_horizon_interval_in_ms; // ecx
  bool has_passed_filters; // al
  char *v7; // eax
  bool v8; // zf
  bool m_is_server; // dl
  unsigned int m_max_current_time_in_ms; // eax
  bool v12; // al
  char *v13; // eax
  survarium::players_mask_history_item *i; // eax
  bool v15; // al
  char *v16; // eax
  unsigned int v17; // [esp-8h] [ebp-48h]
  unsigned int v18; // [esp-8h] [ebp-48h]
  unsigned int v19; // [esp-8h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v20; // [esp-4h] [ebp-44h]
  unsigned int v21; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v22; // [esp-4h] [ebp-44h]
  unsigned int v23; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v24; // [esp-4h] [ebp-44h]
  unsigned int v25; // [esp-4h] [ebp-44h]
  char v26; // [esp+Ch] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+20h] [ebp-20h] BYREF

  v4 = time_in_ms;
  m_event_horizon_interval_in_ms = 0;
  v26 = 0;
  if ( time_in_ms <= a2->m_last_resync_time_in_ms )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"net_sync",
                                 (const char *)3),
          m_event_horizon_interval_in_ms = v20,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_event_horizon_interval_in_ms,
        &v27);
      v26 = 1;
      v21 = a2->m_last_resync_time_in_ms % 0x3E8;
      v17 = a2->m_last_resync_time_in_ms / 0x3E8;
      v7 = survarium::game_world_core::profile_name(a2, player_id);
      vostok::logging::append(
        &v27,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x2FBu,
        "bool __thiscall survarium::game_world_core::leave_match(const unsigned char,unsigned int)",
        "net_sync",
        warning,
        "leave match (client %s) request REJECTED, reason: older than last resync %d.%03d, but %d.%03d",
        v7,
        time_in_ms / 0x3E8,
        time_in_ms % 0x3E8,
        v17,
        v21);
    }
    v8 = (v26 & 1) == 0;
LABEL_6:
    if ( !v8 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_event_horizon_interval_in_ms,
        (int *)&v27);
    return 0;
  }
  m_is_server = a2->m_is_server;
  if ( !m_is_server )
    m_event_horizon_interval_in_ms = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)a2->m_event_horizon_interval_in_ms;
  m_max_current_time_in_ms = a2->m_max_current_time_in_ms;
  m_event_horizon_interval_in_ms = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)m_event_horizon_interval_in_ms + time_in_ms);
  if ( (unsigned int)m_event_horizon_interval_in_ms <= m_max_current_time_in_ms )
  {
    if ( !m_is_server )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
            m_event_horizon_interval_in_ms = v24,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          m_event_horizon_interval_in_ms,
          &v27);
        v26 = 4;
        v25 = a2->m_max_current_time_in_ms % 0x3E8;
        v19 = a2->m_max_current_time_in_ms / 0x3E8;
        v16 = survarium::game_world_core::profile_name(a2, player_id);
        vostok::logging::append(
          &v27,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x318u,
          "bool __thiscall survarium::game_world_core::leave_match(const unsigned char,unsigned int)",
          "net_sync",
          warning,
          "leave match (client %s) request REJECTED, reason: too old %d.%03d, but %d.%03d",
          v16,
          time_in_ms / 0x3E8,
          time_in_ms % 0x3E8,
          v19,
          v25);
      }
      v8 = (v26 & 4) == 0;
      goto LABEL_6;
    }
    m_event_horizon_interval_in_ms = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)a2->m_start_fixed_time_in_ms;
    v4 = (unsigned int)&m_event_horizon_interval_in_ms[1].functor.vostok_pointer_size_alignment[2]
       + 50 * ((m_max_current_time_in_ms - (unsigned int)m_event_horizon_interval_in_ms) / 0x32)
       + 2;
    if ( !vostok::core::g_log_filter_tree
      || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
          m_event_horizon_interval_in_ms = v22,
          v12) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        m_event_horizon_interval_in_ms,
        &v27);
      v26 = 2;
      v23 = a2->m_max_current_time_in_ms % 0x3E8;
      v18 = a2->m_max_current_time_in_ms / 0x3E8;
      v13 = survarium::game_world_core::profile_name(a2, player_id);
      vostok::logging::append(
        &v27,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x30Eu,
        "bool __thiscall survarium::game_world_core::leave_match(const unsigned char,unsigned int)",
        "net_sync",
        warning,
        "leave match (client %s) request CORRECTED from %d.%03d to %d.%03d ( %d.%03d )",
        v13,
        time_in_ms / 0x3E8,
        time_in_ms % 0x3E8,
        v4 / 0x3E8,
        v4 % 0x3E8,
        v18,
        v23);
    }
    if ( (v26 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_event_horizon_interval_in_ms,
        (int *)&v27);
  }
  for ( i = a2->m_active_clients_history.m_items.m_first; i && i->time_in_ms < v4; i = i->next )
    ;
  if ( !i || i->time_in_ms != v4 )
  {
    for ( i = a2->m_active_clients_history.m_items.m_last; i && i->time_in_ms >= v4; i = i->prev )
      ;
  }
  if ( !i )
    return 0;
  LOBYTE(m_event_horizon_interval_in_ms) = player_id;
  if ( ((1 << player_id) & i->clients_mask) != 1 << player_id )
    return 0;
  return survarium::game_world_core::insert_impl(
           (survarium::game_world_core *)m_event_horizon_interval_in_ms,
           &a2->m_game_events_history,
           (survarium::game_event_history_item::events_enum)player_id,
           2u,
           v4,
           1,
           1) != 0;
}
