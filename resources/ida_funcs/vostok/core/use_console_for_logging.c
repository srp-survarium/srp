bool __thiscall vostok::core::use_console_for_logging(vostok::command_line::key *this)
{
  bool v2; // al

  if ( !vostok::core::g_log_filter_tree )
    return 0;
  if ( (_S3_11 & 1) == 0 )
  {
    _S3_11 |= 1u;
    if ( s_use_console.m_type == type_unset )
    {
      s_use_console.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_use_console.m_type != type_recursive
      || (v2 = vostok::testing::run_tests_command_line(this), s_use_console_for_logging = 0, v2) )
    {
      s_use_console_for_logging = 1;
    }
  }
  return s_use_console_for_logging;
}
