int __thiscall survarium::_dynamic_initializer_for__bullet_tracer_exposition__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&bullet_tracer_exposition,
    "bullet_tracer_exposition",
    1,
    command_type_engine_internal,
    execution_filter_general);
  bullet_tracer_exposition.m_min = FLOAT_0_0099999998;
  bullet_tracer_exposition.m_value = &g_bullet_tracer_exposition;
  bullet_tracer_exposition.m_max = FLOAT_5_0;
  bullet_tracer_exposition.m_need_args = 1;
  bullet_tracer_exposition.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__bullet_tracer_exposition__);
}
