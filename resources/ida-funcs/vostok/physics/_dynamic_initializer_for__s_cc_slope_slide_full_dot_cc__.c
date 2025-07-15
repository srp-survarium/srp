int __thiscall vostok::physics::_dynamic_initializer_for__s_cc_slope_slide_full_dot_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_cc_slope_slide_full_dot_cc,
    "cc_slope_slide_full_dot",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_cc_slope_slide_full_dot_cc.m_min = 0.0;
  s_cc_slope_slide_full_dot_cc.m_value = &s_cc_slope_slide_full_dot;
  s_cc_slope_slide_full_dot_cc.m_max = s_bm_current_air_resistance;
  s_cc_slope_slide_full_dot_cc.m_need_args = 1;
  s_cc_slope_slide_full_dot_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_cc_slope_slide_full_dot_cc__);
}
