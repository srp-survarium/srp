void __userpurge survarium::timelimit_rule_core::logic_tick(
        survarium::timelimit_rule_core *this@<ecx>,
        int a2@<edi>,
        unsigned int current_time_in_ms)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool v7; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // esi
  unsigned int v9; // eax
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp+0h] [ebp-54h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp+0h] [ebp-54h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp+0h] [ebp-54h]
  char v14; // [esp+10h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v15; // [esp+14h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+34h] [ebp-20h] BYREF

  v3 = (*(_DWORD *)(a2 + 288) & 0x55555555) + ((*(_DWORD *)(a2 + 288) >> 1) & 0x55555555);
  v14 = 0;
  v4 = (((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333)) & 0xF0F0F0F)
     + ((((v3 & 0x33333333) + ((v3 >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F);
  v5 = (unsigned __int16)(((unsigned int)&s_ui_commands_allocator.m_buffer[1970079] & v4)
                        + ((unsigned int)&s_ui_commands_allocator.m_buffer[1970079] & (v4 >> 8)))
     + ((((unsigned int)&s_ui_commands_allocator.m_buffer[1970079] & v4)
       + ((unsigned int)&s_ui_commands_allocator.m_buffer[1970079] & (v4 >> 8))) >> 16);
  if ( *(_DWORD *)(a2 + 276) == 1 )
  {
    if ( *(_DWORD *)(a2 + 288) )
    {
      v9 = vostok::math::floor((float)*(unsigned __int8 *)(a2 + 308) * *(float *)(a2 + 296));
      v6 = v12;
      if ( v5 >= v9 )
      {
        *(_DWORD *)(a2 + 276) = 2;
        *(_DWORD *)(a2 + 280) = current_time_in_ms;
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"rule",
                                     (const char *)4),
              v6 = v13,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v6,
            &v16);
          v14 = 1;
          vostok::logging::append(
            &v16,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\timelimit_rule_core.cpp",
            0x5Eu,
            "void __thiscall survarium::timelimit_rule_core::logic_tick(const unsigned int)",
            "rule",
            info,
            "Countdown: [%d]Match begins in %d seconds",
            current_time_in_ms,
            *(_DWORD *)(a2 + 304) / 0x3E8u);
        }
        if ( (v14 & 1) != 0 )
        {
          v8 = &v16;
          goto LABEL_16;
        }
      }
    }
  }
  else if ( *(_DWORD *)(a2 + 276) == 2 )
  {
    v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(*(_DWORD *)(a2 + 280) + *(_DWORD *)(a2 + 304));
    if ( (unsigned int)v6 <= current_time_in_ms )
    {
      *(_DWORD *)(a2 + 276) = 3;
      *(_DWORD *)(a2 + 280) = v6;
      if ( !vostok::core::g_log_filter_tree
        || (v7 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"rule", (const char *)4),
            v6 = v11,
            v7) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v6,
          &v15);
        v14 = 2;
        vostok::logging::append(
          &v15,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\timelimit_rule_core.cpp",
          0x67u,
          "void __thiscall survarium::timelimit_rule_core::logic_tick(const unsigned int)",
          "rule",
          info,
          "Match started [%d]",
          current_time_in_ms);
      }
      if ( (v14 & 2) != 0 )
      {
        v8 = &v15;
LABEL_16:
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
          (int *)v8);
      }
    }
  }
}
