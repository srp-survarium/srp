int vostok::render::_dynamic_initializer_for__s_r_resolution_cc__()
{
  char *m_begin; // ecx

  m_begin = s_r_resolution_value.m_begin;
  s_r_resolution_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_r_resolution_cc;
  vostok::console_commands::s_console_command_root = &s_r_resolution_cc;
  s_r_resolution_cc.__vftable = (vostok::console_commands::cc_string_vtbl *)&stru_95AF78.m_key_bindings[42].m_keyboard[1];
  s_r_resolution_cc.m_value = m_begin;
  s_r_resolution_cc.m_size = 16;
  s_r_resolution_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_r_resolution_cc__);
}
