int survarium::_dynamic_initializer_for__cc_cam_fov__()
{
  cc_cam_fov.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_cam_fov;
  cc_cam_fov.m_min = 60.0;
  vostok::console_commands::s_console_command_root = &cc_cam_fov;
  cc_cam_fov.m_value = &survarium::default_vertical_fov;
  cc_cam_fov.m_max = 70.0;
  cc_cam_fov.m_need_args = 1;
  cc_cam_fov.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_cam_fov__);
}
