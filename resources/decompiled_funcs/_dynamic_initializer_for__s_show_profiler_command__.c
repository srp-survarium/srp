int dynamic_initializer_for__s_show_profiler_command__()
{
  s_show_profiler_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_show_profiler_command;
  vostok::console_commands::s_console_command_root = &s_show_profiler_command;
  s_show_profiler_command.m_value = (bool *)&survarium::g_allocator.f_.f_ + 6;
  s_show_profiler_command.m_min = 0;
  s_show_profiler_command.m_max = 1;
  s_show_profiler_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_show_profiler_command.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_show_profiler_command__);
}
