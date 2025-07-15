void __cdecl vostok::core::debug_log_callback(
        char *initiator,
        bool is_error_verbosity,
        bool log_only_user_string,
        const char *message)
{
  vostok::command_line::key *v4; // ecx
  vostok::strings::detail::tuples *v5; // ecx
  vostok::strings::detail::tuples *v6; // ecx
  void *v7; // esp
  vostok::strings::detail::tuples *v8; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  BOOL v10; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  char v12[8]; // [esp+0h] [ebp-40h] BYREF
  vostok::strings::detail::tuples v13; // [esp+8h] [ebp-38h] BYREF
  int user_data; // [esp+3Ch] [ebp-4h] BYREF

  user_data = vostok::command_line::key::is_set(v4, (int)&s_write_errors_to_stderr) ? 2 : 0;
  vostok::strings::detail::tuples::tuples(v5, &v13, initiator, ":");
  v7 = alloca(vostok::strings::detail::tuples::size(v6, (unsigned int *)&v13));
  vostok::strings::detail::tuples::concat(v8, (int)&v13, v12);
  boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
    v9,
    &v13.m_strings[2].second);
  v10 = !is_error_verbosity;
  if ( log_only_user_string )
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v13.m_strings[2].second,
      &user_data,
      (vostok::logging::log_format *)&vostok::logging::format_message,
      ".\\logging_extensions.cpp",
      0xC8u,
      "void __cdecl vostok::core::debug_log_callback(const char *,bool,bool,const char *)",
      v12,
      (vostok::logging::verbosity)(2 * v10 + 2),
      (char *)&stru_7F9BE8.allocator,
      message);
  else
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v13.m_strings[2].second,
      &user_data,
      &vostok::core::g_log_format,
      ".\\logging_extensions.cpp",
      0xCCu,
      "void __cdecl vostok::core::debug_log_callback(const char *,bool,bool,const char *)",
      v12,
      (vostok::logging::verbosity)(2 * v10 + 2),
      (char *)&stru_7F9BE8.allocator,
      message);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&v13.m_strings[2].second);
  if ( vostok::core::g_log_file )
    vostok::logging::log_file::flush(0);
}
