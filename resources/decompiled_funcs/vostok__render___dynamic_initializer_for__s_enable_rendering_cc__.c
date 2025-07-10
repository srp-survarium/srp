int vostok::render::_dynamic_initializer_for__s_enable_rendering_cc__()
{
  s_enable_rendering_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_enable_rendering_cc;
  vostok::console_commands::s_console_command_root = &s_enable_rendering_cc;
  s_enable_rendering_cc.m_value = &s_enable_rendering;
  s_enable_rendering_cc.m_min = 0;
  s_enable_rendering_cc.m_max = 1;
  s_enable_rendering_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_enable_rendering_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_enable_rendering_cc__);
}
