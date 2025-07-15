int __thiscall dynamic_initializer_for__s_light1_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_light1_cc,
    "light1",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_light1_cc.m_value = &s_light1;
  s_light1_cc.m_min = 0;
  s_light1_cc.m_max = 1;
  s_light1_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_light1_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_light1_cc__);
}
