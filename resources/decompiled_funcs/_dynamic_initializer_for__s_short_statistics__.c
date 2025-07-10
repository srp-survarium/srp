int dynamic_initializer_for__s_short_statistics__()
{
  s_short_statistics.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_short_statistics;
  vostok::console_commands::s_console_command_root = &s_short_statistics;
  s_short_statistics.m_value = &s_short_statistics_value;
  s_short_statistics.m_min = 0;
  s_short_statistics.m_max = 1;
  s_short_statistics.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_short_statistics.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_short_statistics__);
}
