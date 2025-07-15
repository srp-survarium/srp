int dynamic_initializer_for__s_ui_enabled_console_command__()
{
  s_ui_enabled_console_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_ui_enabled_console_command;
  vostok::console_commands::s_console_command_root = &s_ui_enabled_console_command;
  s_ui_enabled_console_command.m_value = &s_ui_enabled;
  s_ui_enabled_console_command.m_min = 0;
  s_ui_enabled_console_command.m_max = 1;
  s_ui_enabled_console_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_ui_enabled_console_command.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_ui_enabled_console_command__);
}
