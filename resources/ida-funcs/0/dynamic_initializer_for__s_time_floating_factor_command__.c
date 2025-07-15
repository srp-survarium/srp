int __thiscall dynamic_initializer_for__s_time_floating_factor_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_time_floating_factor_command,
    "time_floating_factor",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_time_floating_factor_command.m_min = epsilon_3_4;
  s_time_floating_factor_command.m_value = &s_time_floating_factor;
  s_time_floating_factor_command.m_max = c_anim_center;
  s_time_floating_factor_command.m_need_args = 1;
  s_time_floating_factor_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_time_floating_factor_command__);
}
