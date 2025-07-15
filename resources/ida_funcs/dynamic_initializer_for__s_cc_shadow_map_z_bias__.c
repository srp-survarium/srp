int dynamic_initializer_for__s_cc_shadow_map_z_bias__()
{
  s_cc_shadow_map_z_bias.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_cc_shadow_map_z_bias;
  s_cc_shadow_map_z_bias.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &s_cc_shadow_map_z_bias;
  s_cc_shadow_map_z_bias.m_value = &s_shadow_map_z_bias;
  s_cc_shadow_map_z_bias.m_max = FLOAT_4_0;
  s_cc_shadow_map_z_bias.m_need_args = 1;
  s_cc_shadow_map_z_bias.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__s_cc_shadow_map_z_bias__);
}
