int vostok::render::_dynamic_initializer_for__s_debug_minus_mip_cc__()
{
  s_debug_minus_mip_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_debug_minus_mip_cc;
  vostok::console_commands::s_console_command_root = &s_debug_minus_mip_cc;
  s_debug_minus_mip_cc.m_value = &s_debug_minus_mip;
  s_debug_minus_mip_cc.m_min = 0;
  s_debug_minus_mip_cc.m_max = 14;
  s_debug_minus_mip_cc.m_need_args = 1;
  s_debug_minus_mip_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_debug_minus_mip_cc__);
}
