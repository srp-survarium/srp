int survarium::_dynamic_initializer_for__cc_death_camera_distance__()
{
  cc_death_camera_distance.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_death_camera_distance;
  cc_death_camera_distance.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &cc_death_camera_distance;
  cc_death_camera_distance.m_value = &s_death_camera_distance;
  cc_death_camera_distance.m_max = 1000.0;
  cc_death_camera_distance.m_need_args = 1;
  cc_death_camera_distance.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_death_camera_distance__);
}
