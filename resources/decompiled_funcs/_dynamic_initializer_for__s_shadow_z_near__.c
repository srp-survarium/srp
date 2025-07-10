int dynamic_initializer_for__s_shadow_z_near__()
{
  s_shadow_z_near.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_shadow_z_near;
  s_shadow_z_near.m_min = 0.0099999998;
  vostok::console_commands::s_console_command_root = &s_shadow_z_near;
  s_shadow_z_near.m_value = &s_shadow_z_near_value;
  LODWORD(s_shadow_z_near.m_max) = clear_value;
  s_shadow_z_near.m_need_args = 1;
  s_shadow_z_near.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__s_shadow_z_near__);
}
