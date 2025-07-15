int __thiscall vostok::physics::_dynamic_initializer_for__s_step_height_command___0(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_step_height_command_0,
    "old_character_controller_step_height",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_step_height_command_0.m_min = 0.0;
  s_step_height_command_0.m_value = &s_step_height;
  s_step_height_command_0.m_max = retry_to_increase_quality_period_sec;
  s_step_height_command_0.m_need_args = 1;
  s_step_height_command_0.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_step_height_command___0);
}
