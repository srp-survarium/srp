void __thiscall vostok::command_line::check_keys(
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *ecx0)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v1; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-28h] BYREF
  vostok::command_line::checker predicate[4]; // [esp+2Ch] [ebp-4h]

  if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      ecx0,
      &log_callback);
    vostok::logging::append(
      &log_callback,
      (void *const)1,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\command_line.cpp",
      0x158u,
      "void __cdecl vostok::command_line::check_keys(void)",
      "core:",
      info,
      (char *)&stru_7F9BE8.allocator,
      vostok::command_line::s_command_line_error.m_begin);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v1,
      (int *)&log_callback);
    if ( vostok::debug::is_debugger_present() )
      __debugbreak();
    if ( HIDWORD(s_command_line_keys_creation.m_mutex[1]) )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(s_command_line_keys_creation.m_mutex[1]) + 64))(
        HIDWORD(s_command_line_keys_creation.m_mutex[1]),
        0);
  }
  predicate[0] = 0;
  vostok::command_line::iterate_keys<vostok::command_line::checker>();
}
