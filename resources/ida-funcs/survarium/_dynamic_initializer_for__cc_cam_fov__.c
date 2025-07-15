int __thiscall survarium::_dynamic_initializer_for__cc_cam_fov__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_cam_fov,
    "fov",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_cam_fov.m_min = FLOAT_60_0;
  cc_cam_fov.m_value = &survarium::default_vertical_fov;
  cc_cam_fov.m_max = FLOAT_70_0;
  cc_cam_fov.m_need_args = 1;
  cc_cam_fov.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_cam_fov__);
}
