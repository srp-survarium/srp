int __thiscall survarium::_dynamic_initializer_for__cc_death_camera_yaw__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_death_camera_yaw,
    "death_camera_yaw",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_death_camera_yaw.m_min = FLOAT_N3_1415927;
  cc_death_camera_yaw.m_value = &s_death_camera_yaw;
  cc_death_camera_yaw.m_max = pi_23;
  cc_death_camera_yaw.m_need_args = 1;
  cc_death_camera_yaw.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_death_camera_yaw__);
}
