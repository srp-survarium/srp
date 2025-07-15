int __thiscall dynamic_initializer_for__s_no_other__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_no_other,
    "no_other",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_no_other.m_value = &s_no_other_value;
  s_no_other.m_min = 0;
  s_no_other.m_max = 1;
  s_no_other.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_no_other.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_no_other__);
}
