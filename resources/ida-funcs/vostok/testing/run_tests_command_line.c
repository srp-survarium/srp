bool __thiscall vostok::testing::run_tests_command_line(vostok::command_line::key *this)
{
  unsigned int v1; // eax
  bool result; // al

  v1 = s_out_result;
  if ( s_out_result == -1 )
  {
    if ( s_command_line_initialized )
    {
      if ( vostok::testing::g_run_tests.m_type == type_unset )
      {
        vostok::testing::g_run_tests.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( vostok::testing::g_run_tests.m_type == type_recursive
        && !vostok::command_line::key::operator bool(this, (int)&vostok::testing::g_run_tests_and_exit) )
      {
        result = 0;
        s_out_result = 0;
        return result;
      }
    }
    else if ( !vostok::command_line::key_is_set(s_run_tests_key_name)
           && !vostok::command_line::key_is_set(s_run_tests_and_exit_key_name) )
    {
      result = 0;
      s_out_result = 0;
      return result;
    }
    v1 = 1;
    s_out_result = 1;
  }
  return v1 != 0;
}
