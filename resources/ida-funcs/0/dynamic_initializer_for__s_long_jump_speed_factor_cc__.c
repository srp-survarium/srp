int __thiscall dynamic_initializer_for__s_long_jump_speed_factor_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_long_jump_speed_factor_cc,
    "long_jump_speed_factor",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_long_jump_speed_factor_cc.m_min = 0.0;
  s_long_jump_speed_factor_cc.m_value = &s_long_jump_speed_factor_value;
  s_long_jump_speed_factor_cc.m_max = s_bm_current_air_resistance;
  s_long_jump_speed_factor_cc.m_need_args = 1;
  s_long_jump_speed_factor_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_long_jump_speed_factor_cc__);
}
