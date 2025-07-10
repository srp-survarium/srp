int vostok::render::_dynamic_initializer_for__s_debug_ssao_techh__()
{
  s_debug_ssao_techh.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_debug_ssao_techh;
  vostok::console_commands::s_console_command_root = &s_debug_ssao_techh;
  s_debug_ssao_techh.m_value = &debug_ssao_tech;
  s_debug_ssao_techh.m_min = 0;
  s_debug_ssao_techh.m_max = 1;
  s_debug_ssao_techh.m_need_args = 1;
  s_debug_ssao_techh.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_debug_ssao_techh__);
}
