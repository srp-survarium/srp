int __thiscall vostok::physics::_dynamic_initializer_for__cc_ms_max_slope_normal_dot_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_ms_max_slope_normal_dot_cc,
    "cc_max_slope_angle_cos",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_ms_max_slope_normal_dot_cc.m_min = 0.0;
  cc_ms_max_slope_normal_dot_cc.m_value = &vostok::physics::bullet_character_controller::ms_max_slope_normal_dot;
  cc_ms_max_slope_normal_dot_cc.m_max = s_bm_current_air_resistance;
  cc_ms_max_slope_normal_dot_cc.m_need_args = 1;
  cc_ms_max_slope_normal_dot_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__cc_ms_max_slope_normal_dot_cc__);
}
