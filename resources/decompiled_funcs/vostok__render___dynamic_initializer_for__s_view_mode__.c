int vostok::render::_dynamic_initializer_for__s_view_mode__()
{
  s_view_mode.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_view_mode;
  vostok::console_commands::s_console_command_root = &s_view_mode;
  s_view_mode.m_value = (unsigned int *)&s_view_mode_value;
  s_view_mode.m_min = 0;
  s_view_mode.m_max = 26;
  s_view_mode.m_need_args = 1;
  s_view_mode.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_view_mode__);
}
