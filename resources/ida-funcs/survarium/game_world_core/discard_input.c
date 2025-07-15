void __thiscall survarium::game_world_core::discard_input(
        survarium::game_world_core *this,
        _DWORD *player_id,
        unsigned __int8 time_in_ms,
        unsigned int time_in_msa)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  bool v6; // zf
  _DWORD *v7; // edi
  boost::detail::function::vtable_base **i; // ebx
  bool v9; // al
  bool v10; // al
  bool v11; // al
  boost::detail::function::vtable_base *v12; // eax
  int v13; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v15; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v16; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // [esp-4h] [ebp-34h]
  bool v18; // [esp+0h] [ebp-30h]
  char v19; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+10h] [ebp-20h] BYREF

  v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)time_in_msa;
  v19 = 0;
  if ( time_in_msa <= player_id[12801] )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game_world_core",
                                 (const char *)3),
          v4 = v14,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v20);
      v19 = 1;
      vostok::logging::append(
        &v20,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x298u,
        "void __thiscall survarium::game_world_core::discard_input(const unsigned char,const unsigned int)",
        "game_world_core",
        warning,
        "cannot discard local player input: older than last resync(%d.%03d, but %d.%03d)",
        time_in_msa / 0x3E8,
        time_in_msa % 0x3E8,
        player_id[12801] / 0x3E8u,
        player_id[12801] % 0x3E8u);
    }
    v6 = (v19 & 1) == 0;
LABEL_6:
    if ( !v6 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
        (int *)&v20);
    return;
  }
  v7 = (_DWORD *)(player_id[2465] + 720 * time_in_ms);
  for ( i = (boost::detail::function::vtable_base **)v7[1]; i; i = (boost::detail::function::vtable_base **)*i )
  {
    if ( (unsigned int)i[5] >= time_in_msa )
      goto LABEL_13;
  }
  i = 0;
LABEL_13:
  if ( !i )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v9 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_world_core", (const char *)3),
          v4 = v15,
          v9) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v20);
      v19 = 2;
      vostok::logging::append(
        &v20,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x29Fu,
        "void __thiscall survarium::game_world_core::discard_input(const unsigned char,const unsigned int)",
        "game_world_core",
        warning,
        "cannot discard local player input: too old(%d.%03d, but %d.%03d)",
        time_in_msa / 0x3E8,
        time_in_msa % 0x3E8,
        player_id[12798] / 0x3E8u,
        player_id[12798] % 0x3E8u);
    }
    v6 = (v19 & 2) == 0;
    goto LABEL_6;
  }
  if ( i[5] != (boost::detail::function::vtable_base *)time_in_msa )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v10 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_world_core", (const char *)3),
          v4 = v16,
          v10) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v20);
      v19 = 4;
      vostok::logging::append(
        &v20,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x2A3u,
        "void __thiscall survarium::game_world_core::discard_input(const unsigned char,const unsigned int)",
        "game_world_core",
        warning,
        "cannot discard local player input: cannot find player input(%d.%03d, but %d.%03d)",
        time_in_msa / 0x3E8,
        time_in_msa % 0x3E8,
        (unsigned int)i[5] / 0x3E8,
        (unsigned int)i[5] % 0x3E8);
    }
    v6 = (v19 & 4) == 0;
    goto LABEL_6;
  }
  if ( !survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less>(
          (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)time_in_msa,
          (int)(player_id + 2460),
          time_in_msa) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_world_core", (const char *)3),
          v4 = v17,
          v11) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v4,
        &v20);
      v19 = 8;
      vostok::logging::append(
        &v20,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_world_core.cpp",
        0x2A8u,
        "void __thiscall survarium::game_world_core::discard_input(const unsigned char,const unsigned int)",
        "game_world_core",
        warning,
        "cannot discard local player input: cannot find game state(%d.%03d, but %d.%03d)",
        time_in_msa / 0x3E8,
        time_in_msa % 0x3E8,
        player_id[12798] / 0x3E8u,
        player_id[12798] % 0x3E8u);
    }
    v6 = (v19 & 8) == 0;
    goto LABEL_6;
  }
  if ( v7[1] )
  {
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)i[1];
    v12 = *i;
    i[1] = 0;
    *i = 0;
    if ( v4 )
      v4->vtable = v12;
    else
      v7[1] = v12;
    if ( v12 )
      v12[1].manager = (void (__cdecl *)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type))v4;
    else
      v7[2] = v4;
    i[1] = 0;
    *i = 0;
    --*v7;
  }
  v13 = v7[4];
  *i = *(boost::detail::function::vtable_base **)(v13 + 32);
  *(_DWORD *)(v13 + 32) = i;
  --*(_DWORD *)(v13 + 36);
  survarium::game_world_core::erase_impl((survarium::game_world_core *)v4, player_id, time_in_ms, time_in_msa, 1, v18);
}
