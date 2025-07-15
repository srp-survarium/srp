void __usercall vostok::console_commands::show_help(vostok::console_commands::console_command *command@<eax>)
{
  vostok::strings::detail::tuples *v2; // ecx
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-254h]
  char v9[16]; // [esp+0h] [ebp-250h] BYREF
  char p2[512]; // [esp+10h] [ebp-240h] BYREF
  vostok::strings::detail::tuples v11; // [esp+210h] [ebp-40h] BYREF
  int v12; // [esp+24Ch] [ebp-4h]

  v12 = 0;
  command->info(command, (char (*)[512])p2);
  vostok::strings::detail::tuples::tuples(v2, &v11, command->m_name, ":", p2);
  v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&v11));
  vostok::strings::detail::tuples::concat(v5, (int)&v11, v9);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)4),
        v6 = v8,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v6,
      &v11.m_strings[2].first);
    v12 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v11.m_strings[2],
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\console_command_processor.cpp",
      0x1Au,
      "void __cdecl vostok::console_commands::show_help(class vostok::console_commands::console_command *)",
      (char *)&stru_802D94,
      info,
      v9);
  }
  if ( (v12 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
      (int *)&v11.m_strings[2]);
}


void __cdecl vostok::console_commands::show_help(char *str)
{
  vostok::console_commands::console_command *v1; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  bool has_passed_filters; // al
  vostok::console_commands::console_command *i; // esi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-34h]
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v7 = 0;
  if ( str )
  {
    v1 = vostok::console_commands::find(str);
    v2 = v5;
    if ( v1 )
    {
      vostok::console_commands::show_help(v1);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&stru_802D94,
                                   (const char *)2),
            v2 = v6,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v2,
          &log_callback);
        v7 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\console_command_processor.cpp",
          0x8Cu,
          "void __cdecl vostok::console_commands::show_help(const char *)",
          (char *)&stru_802D94,
          error,
          "unknown command [%s]",
          str);
      }
      if ( (v7 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
          (int *)&log_callback);
    }
  }
  else
  {
    for ( i = vostok::console_commands::s_console_command_root; i; i = i->m_prev )
      vostok::console_commands::show_help(i);
  }
}
