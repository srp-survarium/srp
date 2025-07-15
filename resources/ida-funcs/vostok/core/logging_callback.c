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
  vostok::logging::log_file *v8; // ecx
  void *v9; // esp
  bool v10; // zf
  vostok::logging::log_file *v11; // ecx
  vostok::logging::log_file *v12; // ecx
  vostok::logging::log_file *v13; // ecx
  char v14; // al
  bool v15; // al
  char v16; // bl
  unsigned __int8 v17[12]; // [esp+0h] [ebp-Ch] BYREF

  if ( vostok::debug::is_debugger_present() )
  {
    v9 = alloca(log_string_length + 2);
    memcpy(v17, (unsigned __int8 *)log_string, log_string_length);
    v10 = !vostok::debug::g_disable_output_to_debugger;
    v17[log_string_length] = 10;
    v17[log_string_length + 1] = 0;
    if ( v10 )
      OutputDebugStringA((LPCSTR)v17);
  }
  if ( vostok::core::g_log_file && vostok::core::g_log_file->m_file )
  {
    vostok::logging::log_file::start_transaction(v8, (int)vostok::core::g_log_file);
    vostok::logging::log_file::append(v11, (int)vostok::core::g_log_file, log_string, log_string_length);
    vostok::logging::log_file::append(v12, (int)vostok::core::g_log_file, "\r\n", 2u);
    vostok::logging::log_file::end_transaction(v13, (int)vostok::core::g_log_file);
  }
  LOBYTE(v8) = (unsigned __int8)user_data & 1;
  if ( vostok::core::g_log_filter_tree )
  {
    if ( (_S5_13 & 1) == 0 )
    {
      _S5_13 |= 1u;
      if ( vostok::command_line::key::is_set((vostok::command_line::key *)v8, (int)&s_use_console)
        || (v15 = vostok::testing::run_tests_command_line((vostok::command_line::key *)v8), byte_47F2774 = 0, v15) )
      {
        byte_47F2774 = 1;
      }
    }
    v14 = byte_47F2774;
    LOBYTE(v8) = (unsigned __int8)user_data & 1;
  }
  else
  {
    v14 = 0;
  }
  if ( first_time && ((_BYTE)v8 || v14) )
    first_time = 0;
  v16 = 0;
  if ( (_BYTE)v8 || v14 )
  {
    if ( !s_tried_to_initialize_console_0 )
    {
      s_initialized_console = vostok::core::initialize_console();
      s_tried_to_initialize_console_0 = 1;
    }
    if ( s_initialized_console )
    {
      vostok::core::write_to_stdstream(stdstream_out, "%s\r\n", log_string);
      v16 = 1;
    }
  }
  if ( vostok::core::g_log_filter_tree )
  {
    if ( ((unsigned __int8)user_data & 2) != 0 )
      vostok::core::write_to_stdstream(stdstream_error, "%s\r\n", log_string);
    if ( vostok::core::g_log_filter_tree
      && vostok::command_line::key::is_set((vostok::command_line::key *)v8, (int)&s_log_to_stdout)
      && !v16 )
    {
      vostok::core::write_to_stdstream(stdstream_out, "%s\r\n", log_string);
    }
  }
}
