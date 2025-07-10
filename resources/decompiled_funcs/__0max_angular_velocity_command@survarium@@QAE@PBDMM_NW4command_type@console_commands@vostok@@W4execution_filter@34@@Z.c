void __thiscall survarium::max_angular_velocity_command::max_angular_velocity_command(
        survarium::max_angular_velocity_command *this)
{
  vostok::console_commands::cc_value<float>::cc_value<float>(
    (int)&s_max_angular_velocity_command,
    1135869952,
    "max_angular_velocity",
    &s_max_angular_velocity_command.m_value,
    3600.0,
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_max_angular_velocity_command.__vftable = (survarium::max_angular_velocity_command_vtbl *)&survarium::max_angular_velocity_command::`vftable';
  s_max_angular_velocity_command.m_engine = 0;
  s_max_angular_velocity_command.m_value = 720.0;
}
