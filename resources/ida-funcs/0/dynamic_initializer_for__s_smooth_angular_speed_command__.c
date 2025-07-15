int __thiscall dynamic_initializer_for__s_smooth_angular_speed_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_smooth_angular_speed_command,
    "smooth_angular_speed",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_smooth_angular_speed_command.m_min = 0.0;
  s_smooth_angular_speed_command.m_value = &s_smooth_angular_speed;
  s_smooth_angular_speed_command.m_max = FLOAT_720_0;
  s_smooth_angular_speed_command.m_need_args = 1;
  s_smooth_angular_speed_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_smooth_angular_speed_command__);
}
