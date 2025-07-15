int __thiscall dynamic_initializer_for__dispersion_magic_coef_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&dispersion_magic_coef_cc,
    "dispersion_gui_scale_coef",
    1,
    command_type_engine_internal,
    execution_filter_general);
  dispersion_magic_coef_cc.m_min = 0.0;
  dispersion_magic_coef_cc.m_value = &s_dispersion_gui_scale_coef_value;
  dispersion_magic_coef_cc.m_max = FLOAT_10000_0;
  dispersion_magic_coef_cc.m_need_args = 1;
  dispersion_magic_coef_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__dispersion_magic_coef_cc__);
}
