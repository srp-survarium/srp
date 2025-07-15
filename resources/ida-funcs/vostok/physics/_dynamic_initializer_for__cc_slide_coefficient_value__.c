int __thiscall vostok::physics::_dynamic_initializer_for__cc_slide_coefficient_value__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_slide_coefficient_value,
    "cc_slide_coefficient",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_slide_coefficient_value.m_min = 0.0;
  cc_slide_coefficient_value.m_value = &s_cc_slide_coefficient_value;
  cc_slide_coefficient_value.m_max = FLOAT_1000_0;
  cc_slide_coefficient_value.m_need_args = 1;
  cc_slide_coefficient_value.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__cc_slide_coefficient_value__);
}
