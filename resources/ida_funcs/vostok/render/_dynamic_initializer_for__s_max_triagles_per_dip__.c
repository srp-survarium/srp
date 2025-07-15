int vostok::render::_dynamic_initializer_for__s_max_triagles_per_dip__()
{
  s_max_triagles_per_dip.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_max_triagles_per_dip;
  vostok::console_commands::s_console_command_root = &s_max_triagles_per_dip;
  s_max_triagles_per_dip.m_value = &s_max_triagles_per_dip_value;
  s_max_triagles_per_dip.m_min = 0;
  s_max_triagles_per_dip.m_max = (unsigned int)&loc_186A0;
  s_max_triagles_per_dip.m_need_args = 1;
  s_max_triagles_per_dip.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_max_triagles_per_dip__);
}
