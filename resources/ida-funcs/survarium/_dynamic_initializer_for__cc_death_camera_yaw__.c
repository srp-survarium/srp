int survarium::_dynamic_initializer_for__cc_death_camera_yaw__()
{
  cc_death_camera_yaw.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_death_camera_yaw;
  cc_death_camera_yaw.m_min = -3.1415927;
  vostok::console_commands::s_console_command_root = &cc_death_camera_yaw;
  cc_death_camera_yaw.m_value = &s_death_camera_yaw;
  cc_death_camera_yaw.m_max = pi_16;
  cc_death_camera_yaw.m_need_args = 1;
  cc_death_camera_yaw.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_death_camera_yaw__);
}
