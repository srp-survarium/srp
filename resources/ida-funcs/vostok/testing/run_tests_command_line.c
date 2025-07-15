BOOL __thiscall vostok::testing::run_tests_command_line(vostok::command_line::key *this)
{
  vostok::command_line::key *v1; // ecx
  bool is_set; // al
  char *command_line; // eax
  char *v4; // eax

  if ( s_out_result == -1 )
  {
    if ( s_command_line_initialized )
    {
      if ( vostok::command_line::key::is_set(this, (int)&vostok::testing::g_run_tests) )
        goto LABEL_9;
      is_set = vostok::command_line::key::is_set(v1, (int)&vostok::testing::g_run_tests_and_exit);
    }
    else
    {
      command_line = vostok::core::get_command_line();
      if ( vostok::command_line::key_is_set_impl(
             (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)command_line,
             (char *)&vostok::console_commands::bool_values_str._M_impl._M_end_of_storage._M_data) )
      {
        goto LABEL_9;
      }
      v4 = vostok::core::get_command_line();
      is_set = vostok::command_line::key_is_set_impl(
                 (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4,
                 s_run_tests_and_exit_key_name);
    }
    if ( !is_set )
    {
      s_out_result = 0;
      return s_out_result != 0;
    }
LABEL_9:
    s_out_result = 1;
  }
  return s_out_result != 0;
}
