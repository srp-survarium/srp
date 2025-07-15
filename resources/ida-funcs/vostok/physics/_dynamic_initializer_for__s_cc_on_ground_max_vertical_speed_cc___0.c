int __thiscall vostok::physics::_dynamic_initializer_for__s_cc_on_ground_max_vertical_speed_cc___0(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_cc_on_ground_max_vertical_speed_cc_0,
    "old_cc_on_ground_max_vertical_speed",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_cc_on_ground_max_vertical_speed_cc_0.m_min = 0.0;
  s_cc_on_ground_max_vertical_speed_cc_0.m_value = &s_cc_on_ground_max_vertical_speed_0;
  s_cc_on_ground_max_vertical_speed_cc_0.m_max = FLOAT_10_0;
  s_cc_on_ground_max_vertical_speed_cc_0.m_need_args = 1;
  s_cc_on_ground_max_vertical_speed_cc_0.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_cc_on_ground_max_vertical_speed_cc___0);
}
