int dynamic_initializer_for__s_clouds_time__()
{
  s_clouds_time.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_clouds_time;
  s_clouds_time.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &s_clouds_time;
  s_clouds_time.m_value = &s_clouds_time_value;
  LODWORD(s_clouds_time.m_max) = clear_value;
  s_clouds_time.m_need_args = 1;
  s_clouds_time.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__s_clouds_time__);
}
