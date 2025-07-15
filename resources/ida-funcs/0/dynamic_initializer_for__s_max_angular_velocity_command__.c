int __thiscall dynamic_initializer_for__s_max_angular_velocity_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_max_angular_velocity_command,
    "max_angular_velocity",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_max_angular_velocity_command.m_engine = 0;
  s_max_angular_velocity_command.m_min = FLOAT_360_0;
  s_max_angular_velocity_command.m_max = FLOAT_3600_0;
  s_max_angular_velocity_command.vostok::console_commands::cc_float::vostok::console_commands::cc_value<float>::m_value = &s_max_angular_velocity_command.m_value;
  s_max_angular_velocity_command.m_need_args = 1;
  s_max_angular_velocity_command.__vftable = (survarium::max_angular_velocity_command_vtbl *)&survarium::max_angular_velocity_command::`vftable';
  s_max_angular_velocity_command.m_value = FLOAT_720_0;
  return atexit(dynamic_atexit_destructor_for__s_max_angular_velocity_command__);
}
