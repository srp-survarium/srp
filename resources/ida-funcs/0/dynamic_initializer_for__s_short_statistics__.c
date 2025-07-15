int __thiscall dynamic_initializer_for__s_short_statistics__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_short_statistics,
    "r_short_statistics",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_short_statistics.m_value = &s_short_statistics_value;
  s_short_statistics.m_min = 0;
  s_short_statistics.m_max = 1;
  s_short_statistics.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_short_statistics.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_short_statistics__);
}
