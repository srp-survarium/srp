int __thiscall dynamic_initializer_for__s_grenades_sensor_radius_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_grenades_sensor_radius_command,
    "grenades_sensor_radius",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_grenades_sensor_radius_command.m_min = 0.0;
  s_grenades_sensor_radius_command.m_value = &s_grenades_sensor_radius;
  s_grenades_sensor_radius_command.m_max = FLOAT_50_0;
  s_grenades_sensor_radius_command.m_need_args = 1;
  s_grenades_sensor_radius_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_grenades_sensor_radius_command__);
}
