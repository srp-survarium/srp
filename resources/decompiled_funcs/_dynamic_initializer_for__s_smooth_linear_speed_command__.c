int dynamic_initializer_for__s_smooth_linear_speed_command__()
{
  s_smooth_linear_speed_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_smooth_linear_speed_command;
  s_smooth_linear_speed_command.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &s_smooth_linear_speed_command;
  s_smooth_linear_speed_command.m_value = &s_smooth_linear_speed;
  s_smooth_linear_speed_command.m_max = FLOAT_10_0;
  s_smooth_linear_speed_command.m_need_args = 1;
  s_smooth_linear_speed_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__s_smooth_linear_speed_command__);
}
