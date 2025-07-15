bool __userpurge survarium::game_world_core::enter_match@<al>(
        survarium::game_world_core *this@<ecx>,
        int a2@<edi>,
        __int32 player_id,
        unsigned int time_in_ms)
{
  unsigned int v4; // edx
  bool has_passed_filters; // al
  char *v6; // eax
  bool v7; // zf
  char v9; // bl
  int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // esi
  bool v13; // al
  char *v14; // eax
  _DWORD *i; // eax
  bool v16; // al
  char *v17; // eax
  unsigned int v18; // [esp-8h] [ebp-48h]
  unsigned int v19; // [esp-8h] [ebp-48h]
  unsigned int v20; // [esp-8h] [ebp-48h]
  survarium::game_world_core *v21; // [esp-4h] [ebp-44h]
  unsigned int v22; // [esp-4h] [ebp-44h]
  survarium::game_world_core *v23; // [esp-4h] [ebp-44h]
  unsigned int v24; // [esp-4h] [ebp-44h]
  survarium::game_world_core *v25; // [esp-4h] [ebp-44h]
  unsigned int v26; // [esp-4h] [ebp-44h]
  char v27; // [esp+Ch] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v28; // [esp+20h] [ebp-20h] BYREF

  v4 = time_in_ms;
  v27 = 0;
  if ( time_in_ms <= *(_DWORD *)(a2 + 51204) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"net_sync",
                                 (const char *)3),
          this = v21,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v28);
      v27 = 1;
      v22 = *(_DWORD *)(a2 + 51204) % 0x3E8u;
      v18 = *(_DWORD *)(a2 + 51204) / 0x3E8u;
      v6 = survarium::game_world_core::profile_name((survarium::game_world_core *)a2, player_id);
      vostok::logging::append(
        &v28,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x2BAu,
        "bool __thiscall survarium::game_world_core::enter_match(const unsigned char,unsigned int)",
        "net_sync",
        warning,
        "enter match (client %s) request REJECTED, reason: older than last resync %d.%03d, but %d.%03d",
        v6,
        time_in_ms / 0x3E8,
        time_in_ms % 0x3E8,
        v18,
        v22);
    }
    v7 = (v27 & 1) == 0;
LABEL_6:
    if ( !v7 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v28);
    return 0;
  }
  v9 = *(_BYTE *)(a2 + 51213);
  if ( v9 )
    v10 = 0;
  else
    v10 = *(_DWORD *)(a2 + 51180);
  v11 = *(_DWORD *)(a2 + 51192);
  this = (survarium::game_world_core *)(time_in_ms + v10);
  if ( (unsigned int)this <= v11 )
  {
    if ( !v9 )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
            this = v25,
            v16) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
          &v28);
        v27 = 4;
        v26 = *(_DWORD *)(a2 + 51192) % 0x3E8u;
        v20 = *(_DWORD *)(a2 + 51192) / 0x3E8u;
        v17 = survarium::game_world_core::profile_name((survarium::game_world_core *)a2, player_id);
        vostok::logging::append(
          &v28,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x2D7u,
          "bool __thiscall survarium::game_world_core::enter_match(const unsigned char,unsigned int)",
          "net_sync",
          warning,
          "enter match (client %s) request REJECTED, reason: too old %d.%03d, but %d.%03d",
          v17,
          time_in_ms / 0x3E8,
          time_in_ms % 0x3E8,
          v20,
          v26);
      }
      v7 = (v27 & 4) == 0;
      goto LABEL_6;
    }
    this = *(survarium::game_world_core **)(a2 + 51184);
    v12 = (unsigned int)&this->m_game_events_history.m_allocator.m_on_out_of_memory.functor.vostok_pointer_size_alignment[4]
        + 50 * ((v11 - (unsigned int)this) / 0x32)
        + 2;
    if ( !vostok::core::g_log_filter_tree
      || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_sync", (const char *)3),
          this = v23,
          v13) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v28);
      v27 = 2;
      v24 = *(_DWORD *)(a2 + 51192) % 0x3E8u;
      v19 = *(_DWORD *)(a2 + 51192) / 0x3E8u;
      v14 = survarium::game_world_core::profile_name((survarium::game_world_core *)a2, player_id);
      vostok::logging::append(
        &v28,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x2CDu,
        "bool __thiscall survarium::game_world_core::enter_match(const unsigned char,unsigned int)",
        "net_sync",
        warning,
        "enter match (client %s) request CORRECTED from %d.%03d to %d.%03d ( %d.%03d )",
        v14,
        time_in_ms / 0x3E8,
        time_in_ms % 0x3E8,
        v12 / 0x3E8,
        v12 % 0x3E8,
        v19,
        v24);
    }
    if ( (v27 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v28);
    v4 = v12;
  }
  for ( i = *(_DWORD **)(a2 + 24276); i && i[3] < v4; i = (_DWORD *)*i )
    ;
  if ( !i || i[3] != v4 )
  {
    for ( i = *(_DWORD **)(a2 + 24280); i && i[3] >= v4; i = (_DWORD *)i[1] )
      ;
  }
  LOBYTE(this) = player_id;
  if ( ((1 << player_id) & i[2]) != 0 )
    return 0;
  return survarium::game_world_core::insert_impl(
           this,
           (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)a2,
           (survarium::game_event_history_item::events_enum)player_id,
           1u,
           v4,
           *(_BYTE *)(a2 + 51213) == 0,
           1) != 0;
}
