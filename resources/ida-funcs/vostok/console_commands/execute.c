void __cdecl vostok::console_commands::execute(
        char *command_to_execute,
        vostok::console_commands::execution_filter filter,
        unsigned int command_types_to_execute)
{
  char *v3; // ebx
  int v4; // eax
  int v5; // edi
  void *v6; // esp
  const char *v7; // esi
  vostok::console_commands::console_command *v8; // ecx
  bool has_passed_filters; // al
  bool v10; // zf
  bool v11; // al
  vostok::console_commands::console_command *v12; // [esp-4h] [ebp-240h]
  vostok::console_commands::console_command *v13; // [esp-4h] [ebp-240h]
  char v14[16]; // [esp+0h] [ebp-23Ch] BYREF
  char format[512]; // [esp+10h] [ebp-22Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+210h] [ebp-2Ch] BYREF
  char *destination; // [esp+230h] [ebp-Ch]
  int v18; // [esp+234h] [ebp-8h]

  v18 = 0;
  v3 = command_to_execute;
  strchr(command_to_execute, 0x20u);
  v5 = v4;
  if ( v4 )
  {
    v6 = alloca(v4 - (_DWORD)command_to_execute + 1);
    destination = v14;
    vostok::strings::copy_n(
      v14,
      v4 - (_DWORD)command_to_execute + 1,
      command_to_execute,
      v4 - (_DWORD)command_to_execute);
    v3 = destination;
  }
  v7 = v5 != 0 ? (const char *)(v5 + 1) : 0;
  v8 = vostok::console_commands::find(v3);
  if ( !v8 )
  {
    if ( filter == execution_filter_early )
      return;
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)3),
          v8 = v12,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
        &log_callback);
      v18 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\console_command_processor.cpp",
        0x71u,
        "void __cdecl vostok::console_commands::execute(const char *,enum vostok::console_commands::execution_filter,unsigned int)",
        (char *)&stru_802D94,
        warning,
        "unknown command [%s]",
        v3);
    }
    v10 = (v18 & 1) == 0;
LABEL_19:
    if ( !v10 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
        (int *)&log_callback);
    return;
  }
  if ( (filter == execution_filter_all || v8->m_execution_type == filter)
    && (command_types_to_execute & v8->m_command_type) != 0 )
  {
    if ( v7 && strlen(v7) || !v8->m_need_args )
    {
      v8->execute(v8, v7);
      return;
    }
    v8->status(v8, (char (*)[512])format);
    if ( !vostok::core::g_log_filter_tree
      || (v11 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)&stru_802D94, (const char *)4),
          v8 = v13,
          v11) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8,
        &log_callback);
      v18 = 2;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\console_command_processor.cpp",
        0x7Fu,
        "void __cdecl vostok::console_commands::execute(const char *,enum vostok::console_commands::execution_filter,unsigned int)",
        (char *)&stru_802D94,
        info,
        format);
    }
    v10 = (v18 & 2) == 0;
    goto LABEL_19;
  }
}
