bool __thiscall vostok::core::suppress_debug_window_on_crash(vostok::command_line::key *this)
{
  unsigned int v1; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *command_line; // eax

  v1 = s_out_result_0;
  if ( s_out_result_0 == -1 )
  {
    if ( s_command_line_initialized )
    {
      LOBYTE(v1) = vostok::command_line::key::is_set(this, (int)&s_suppress_debug_window_on_crash);
    }
    else
    {
      command_line = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)vostok::core::get_command_line();
      LOBYTE(v1) = vostok::command_line::key_is_set_impl(command_line, "suppress_debug_window_on_crash");
    }
    v1 = (unsigned __int8)v1;
    s_out_result_0 = (unsigned __int8)v1;
  }
  return v1 != 0;
}
