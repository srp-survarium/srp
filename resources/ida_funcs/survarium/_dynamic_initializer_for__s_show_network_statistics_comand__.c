int survarium::_dynamic_initializer_for__s_show_network_statistics_comand__()
{
  s_show_network_statistics_comand.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_show_network_statistics_comand;
  vostok::console_commands::s_console_command_root = &s_show_network_statistics_comand;
  s_show_network_statistics_comand.m_value = &s_show_network_statistics;
  s_show_network_statistics_comand.m_min = 0;
  s_show_network_statistics_comand.m_max = 1;
  s_show_network_statistics_comand.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_show_network_statistics_comand.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_show_network_statistics_comand__);
}
