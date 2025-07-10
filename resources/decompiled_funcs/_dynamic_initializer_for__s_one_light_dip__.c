int dynamic_initializer_for__s_one_light_dip__()
{
  s_one_light_dip.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_one_light_dip;
  vostok::console_commands::s_console_command_root = &s_one_light_dip;
  s_one_light_dip.m_value = &s_one_light_dip_value;
  s_one_light_dip.m_min = 0;
  s_one_light_dip.m_max = 1;
  s_one_light_dip.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_one_light_dip.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_one_light_dip__);
}
