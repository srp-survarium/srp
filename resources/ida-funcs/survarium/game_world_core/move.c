void __userpurge survarium::game_world_core::move(
        survarium::game_world_core *this@<ecx>,
        survarium::game_world_core *a2@<eax>,
        unsigned int time_in_ms)
{
  survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *v4; // ecx
  unsigned int m_valid_time_in_ms; // eax
  vostok::timing::timer *v6; // ecx
  void *v7; // esp
  survarium::game_state_history_item *v8; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  survarium::game_state_history_item *v10; // esi
  bool v11; // al
  unsigned int v12; // eax
  unsigned int v13; // edx
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v14; // ecx
  survarium::game_event_history_item *v15; // eax
  vostok::timing::timer *v16; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  unsigned int elapsed_msec; // edi
  bool v19; // al
  bool v20; // zf
  bool v21; // al
  unsigned int v22; // eax
  bool v23; // al
  unsigned int v24; // edx
  unsigned int v25; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // ecx
  bool has_passed_filters; // al
  unsigned int v28; // eax
  unsigned int v29; // edx
  bool v30; // al
  unsigned int v31; // eax
  unsigned int v32; // edx
  unsigned int *v33; // esi
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v34; // ecx
  unsigned int v35; // esi
  survarium::game_event_history_item *v36; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp-1Ch] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp-1Ch] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v39; // [esp-1Ch] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v40; // [esp-1Ch] [ebp-68h]
  LARGE_INTEGER v41[2]; // [esp-18h] [ebp-64h] BYREF
  unsigned int v42; // [esp-8h] [ebp-54h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v43; // [esp-4h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+10h] [ebp-3Ch] BYREF
  unsigned int v45; // [esp+34h] [ebp-18h]
  unsigned int v46; // [esp+38h] [ebp-14h]
  unsigned int v47; // [esp+3Ch] [ebp-10h]
  survarium::game_state_history_item *m_first; // [esp+40h] [ebp-Ch]
  int v49; // [esp+44h] [ebp-8h]

  v49 = 0;
  if ( !a2->m_is_first_time && (a2->m_current_time_in_ms != time_in_ms || a2->m_valid_time_in_ms < time_in_ms) )
  {
    survarium::game_world_core::snap_inputs(this, (int)a2, time_in_ms);
    m_valid_time_in_ms = a2->m_valid_time_in_ms;
    if ( a2->m_current_time_in_ms <= m_valid_time_in_ms || m_valid_time_in_ms >= time_in_ms )
    {
      m_first = survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less_equal>(
                  v4,
                  (int)&a2->m_game_states_history,
                  time_in_ms);
      if ( !m_first )
      {
        if ( a2->m_game_states_history.m_items.m_first )
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       (vostok::logging::filter_tree *)"game_core",
                                       (const char *)2),
                v26 = v43,
                has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v26,
              &v44);
            v28 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) / 0x3E8u;
            v29 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) % 0x3E8u;
            v49 = 16;
            vostok::logging::append(
              &v44,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\game_world_core.cpp",
              0x57Eu,
              "void __thiscall survarium::game_world_core::move(const unsigned int)",
              "game_core",
              error,
              "cannot find older item for time %d.%03d : the oldest is %d.%03d",
              time_in_ms / 0x3E8,
              time_in_ms % 0x3E8,
              v28,
              v29);
          }
          if ( (v49 & 0x10) != 0 )
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v26,
              (int *)&v44);
          m_first = a2->m_game_states_history.m_items.m_first;
        }
        else
        {
          if ( !vostok::core::g_log_filter_tree
            || (v30 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_core", (const char *)2),
                v26 = v43,
                v30) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
              v26,
              &v44);
            v31 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) / 0x3E8u;
            v32 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) % 0x3E8u;
            v49 = 32;
            v43 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v32;
            v42 = v31;
            vostok::logging::append(
              &v44,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\game_world_core.cpp",
              0x582u,
              "void __thiscall survarium::game_world_core::move(const unsigned int)",
              "game_core",
              error,
              "cannot find older item for time %d.%03d, game states history is empty!",
              time_in_ms / 0x3E8,
              time_in_ms % 0x3E8);
          }
          if ( (v49 & 0x20) != 0 )
            boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
              (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v26,
              (int *)&v44);
        }
      }
      v33 = (unsigned int *)((char *)m_first + (_DWORD)&loc_B9937 + 1);
      v34 = *(survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > **)&m_first->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1];
      if ( v34 != (survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *)a2->m_current_time_in_ms )
        survarium::game_world_core::deserialize(a2, m_first);
      v35 = *v33;
      if ( v35 < time_in_ms )
      {
        v36 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater>(
                v34,
                (int)a2,
                v35);
        survarium::game_world_core::tick_events(m_first, a2, v36, (survarium::base_player *)time_in_ms);
      }
    }
    else
    {
      v6 = (vostok::timing::timer *)(m_valid_time_in_ms + a2->m_event_horizon_interval_in_ms);
      m_first = 0;
      if ( time_in_ms >= (unsigned int)v6 )
      {
        v7 = alloca(24);
        if ( v41 )
        {
          vostok::timing::timer::timer(v6, v41);
          m_first = v8;
        }
        else
        {
          m_first = 0;
        }
        vostok::timing::timer::start(v6, (LARGE_INTEGER *)m_first);
      }
      v10 = survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::less_equal>(
              (survarium::history<survarium::game_state_history_item,vostok::memory::single_size_buffer_allocator<760148,vostok::threading::single_threading_policy> > *)v6,
              (int)&a2->m_game_states_history,
              a2->m_valid_time_in_ms);
      if ( v10 )
        goto LABEL_19;
      if ( a2->m_game_states_history.m_items.m_first )
      {
        if ( !vostok::core::g_log_filter_tree
          || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_core", (const char *)2),
              v9 = v37,
              v11) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v9,
            &v44);
          v12 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) / 0x3E8u;
          v13 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) % 0x3E8u;
          v49 = 1;
          v47 = v12;
          vostok::logging::append(
            &v44,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x554u,
            "void __thiscall survarium::game_world_core::move(const unsigned int)",
            "game_core",
            error,
            "cannot find older item for time %d.%03d : the oldest is %d.%03d",
            time_in_ms / 0x3E8,
            time_in_ms % 0x3E8,
            v12,
            v13);
        }
        if ( (v49 & 1) != 0 )
        {
          v49 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
            (int *)&v44);
        }
        v10 = a2->m_game_states_history.m_items.m_first;
        a2->m_valid_time_in_ms = *(_DWORD *)&v10->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937
                                                                                                 + 1];
LABEL_19:
        v47 = a2->m_valid_time_in_ms;
        survarium::game_world_core::deserialize(a2, v10);
        v15 = survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::nearest_item<stlp_std::greater>(
                v14,
                (int)a2,
                *(_DWORD *)&v10->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9937 + 1]);
        survarium::game_world_core::tick_events(v10, a2, v15, (survarium::base_player *)time_in_ms);
        if ( !m_first )
          return;
        elapsed_msec = vostok::timing::timer::get_elapsed_msec(v16, (int)m_first);
        if ( !vostok::core::g_log_filter_tree
          || (v19 = vostok::logging::has_passed_filters(
                      (vostok::logging::filter_tree *)"game_world_core",
                      (const char *)3),
              v17 = v38,
              v19) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v17,
            &v44);
          v49 |= 8u;
          v46 = time_in_ms / 0x3E8;
          v45 = time_in_ms % 0x3E8;
          m_first = (survarium::game_state_history_item *)(v47 / 0x3E8);
          vostok::logging::append(
            &v44,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x573u,
            "void __thiscall survarium::game_world_core::move(const unsigned int)",
            "game_world_core",
            warning,
            "large move( %d.%03d ): %d.%03d => %d.%03d took %d.%03ds",
            (time_in_ms - v47) / 0x3E8,
            (time_in_ms - v47) % 0x3E8,
            v47 / 0x3E8,
            v47 % 0x3E8,
            time_in_ms / 0x3E8,
            time_in_ms % 0x3E8,
            elapsed_msec / 0x3E8,
            elapsed_msec % 0x3E8);
        }
        v20 = (v49 & 8) == 0;
        goto LABEL_24;
      }
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game_core", (const char *)2),
            v9 = v39,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v9,
          &v44);
        v22 = *(_DWORD *)((char *)&loc_B9937 + (unsigned int)a2->m_game_states_history.m_items.m_first + 1) / 0x3E8u;
        v49 = 2;
        v46 = v22;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\game_world_core.cpp",
          0x55Bu,
          "void __thiscall survarium::game_world_core::move(const unsigned int)",
          "game_core",
          error,
          "cannot find older item for time %d.%03d, game states history is empty!",
          time_in_ms / 0x3E8,
          time_in_ms % 0x3E8);
      }
      if ( (v49 & 2) != 0 )
      {
        v49 &= ~2u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
          (int *)&v44);
      }
      if ( m_first )
      {
        v46 = vostok::timing::timer::get_elapsed_msec((vostok::timing::timer *)v9, (int)m_first);
        if ( !vostok::core::g_log_filter_tree
          || (v23 = vostok::logging::has_passed_filters(
                      (vostok::logging::filter_tree *)"game_world_core",
                      (const char *)3),
              v17 = v40,
              v23) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v17,
            &v44);
          v24 = v46 % 0x3E8;
          v25 = a2->m_valid_time_in_ms;
          v49 |= 4u;
          v46 /= 0x3E8u;
          m_first = (survarium::game_state_history_item *)(time_in_ms / 0x3E8);
          v47 = time_in_ms % 0x3E8;
          v45 = v25 / 0x3E8;
          vostok::logging::append(
            &v44,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_world_core.cpp",
            0x55Eu,
            "void __thiscall survarium::game_world_core::move(const unsigned int)",
            "game_world_core",
            warning,
            "large move( %d.%03d ): %d.%03d => %d.%03d took %d.%03ds",
            (time_in_ms - v25) / 0x3E8,
            (time_in_ms - v25) % 0x3E8,
            v25 / 0x3E8,
            v25 % 0x3E8,
            time_in_ms / 0x3E8,
            time_in_ms % 0x3E8,
            v46,
            v24);
        }
        v20 = (v49 & 4) == 0;
LABEL_24:
        if ( !v20 )
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v17,
            (int *)&v44);
      }
    }
  }
}
