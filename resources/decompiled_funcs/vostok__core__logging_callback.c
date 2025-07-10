void __cdecl vostok::core::logging_callback(
        void *const user_data,
        const char *const file,
        const unsigned int line,
        const char *const function_signature,
        const char *const initiator,
        const vostok::logging::verbosity verbosity,
        char *log_string,
        unsigned int log_string_length)
{
  vostok::command_line::key *v8; // ecx
  void *v9; // esp
  bool v10; // al
  unsigned __int8 v11[19]; // [esp+0h] [ebp-14h] BYREF
  char v12; // [esp+13h] [ebp-1h]
  char v13; // [esp+1Fh] [ebp+Bh]

  if ( vostok::debug::is_debugger_present() )
  {
    v9 = alloca(log_string_length + 2);
    memcpy(v11, (unsigned __int8 *)log_string, log_string_length);
    v11[log_string_length] = 10;
    v11[log_string_length + 1] = 0;
    vostok::debug::output((const char *)v11);
  }
  if ( vostok::core::g_log_file && vostok::core::g_log_file->m_file )
  {
    vostok::logging::log_file::append(vostok::core::g_log_file, log_string, log_string_length);
    vostok::logging::log_file::append(vostok::core::g_log_file, "\r\n", 2u);
  }
  v13 = (unsigned __int8)user_data & 1;
  v10 = vostok::core::use_console_for_logging(v8);
  if ( first_time && (v13 || v10) )
    first_time = 0;
  v12 = 0;
  if ( v13 || v10 )
  {
    if ( !s_tried_to_initialize_console_0 )
    {
      s_initialized_console = vostok::core::initialize_console();
      s_tried_to_initialize_console_0 = 1;
    }
    if ( s_initialized_console )
    {
      vostok::core::write_to_stdstream(stdstream_out, "%s\r\n", log_string);
      v12 = 1;
    }
  }
  if ( vostok::core::g_log_filter_tree )
  {
    if ( ((unsigned __int8)user_data & 2) != 0 )
      vostok::core::write_to_stdstream(stdstream_error, "%s\r\n", log_string);
    if ( vostok::core::g_log_filter_tree )
    {
      if ( s_log_to_stdout.m_type == type_unset )
      {
        v11[15] = 0;
        s_log_to_stdout.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_log_to_stdout.m_type != type_recursive && !v12 )
        vostok::core::write_to_stdstream(stdstream_out, "%s\r\n", log_string);
    }
  }
}
