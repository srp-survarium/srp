int dynamic_initializer_for__show_detailed_statistics__()
{
  show_detailed_statistics.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &show_detailed_statistics;
  vostok::console_commands::s_console_command_root = &show_detailed_statistics;
  show_detailed_statistics.m_value = (bool *)&survarium::g_allocator.f_.f_ + 7;
  show_detailed_statistics.m_min = 0;
  show_detailed_statistics.m_max = 1;
  show_detailed_statistics.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  show_detailed_statistics.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__show_detailed_statistics__);
}
