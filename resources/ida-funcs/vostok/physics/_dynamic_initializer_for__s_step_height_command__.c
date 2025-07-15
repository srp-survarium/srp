int vostok::physics::_dynamic_initializer_for__s_step_height_command__()
{
  s_step_height_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_step_height_command;
  s_step_height_command.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &s_step_height_command;
  s_step_height_command.m_value = &s_step_height;
  s_step_height_command.m_max = retry_to_increase_quality_period_sec;
  s_step_height_command.m_need_args = 1;
  s_step_height_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_step_height_command__);
}
