int __thiscall survarium::_dynamic_initializer_for__cc_death_camera_distance__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_death_camera_distance,
    "death_camera_distance",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_death_camera_distance.m_min = 0.0;
  cc_death_camera_distance.m_value = &s_death_camera_distance;
  cc_death_camera_distance.m_max = FLOAT_1000_0;
  cc_death_camera_distance.m_need_args = 1;
  cc_death_camera_distance.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_death_camera_distance__);
}
