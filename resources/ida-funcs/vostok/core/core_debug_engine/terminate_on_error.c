BOOL __thiscall vostok::core::core_debug_engine::terminate_on_error(vostok::core::core_debug_engine *this)
{
  int v1; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *command_line; // eax
  vostok::command_line::key *v3; // ecx

  v1 = dword_8B8AF0;
  if ( dword_8B8AF0 == -1 )
  {
    if ( s_command_line_initialized )
    {
      LOBYTE(v1) = vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_print_build_id);
    }
    else
    {
      command_line = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)vostok::core::get_command_line();
      LOBYTE(v1) = vostok::command_line::key_is_set_impl(command_line, MEMORY[0x888F1C]);
    }
    v1 = (unsigned __int8)v1;
    dword_8B8AF0 = (unsigned __int8)v1;
  }
  return v1
      || vostok::testing::run_tests_command_line((vostok::command_line::key *)this)
      || vostok::core::suppress_debug_window_on_crash(v3);
}
