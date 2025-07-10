int dynamic_initializer_for__s_localization__()
{
  s_localization.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_localization;
  vostok::console_commands::s_console_command_root = &s_localization;
  s_localization.__vftable = (vostok::console_commands::cc_string_vtbl *)&stru_95AF78.m_key_bindings[42].m_keyboard[1];
  s_localization.m_value = s_localization_str;
  s_localization.m_size = 16;
  s_localization.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_localization__);
}
