int dynamic_initializer_for__s_debug_profile_dip_cc__()
{
  s_debug_profile_dip_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_debug_profile_dip_cc;
  vostok::console_commands::s_console_command_root = &s_debug_profile_dip_cc;
  s_debug_profile_dip_cc.m_value = (bool *)&s_debug_profile_dip;
  s_debug_profile_dip_cc.m_min = 0;
  s_debug_profile_dip_cc.m_max = 1;
  s_debug_profile_dip_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_debug_profile_dip_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_debug_profile_dip_cc__);
}
