int __thiscall dynamic_initializer_for__show_detailed_statistics__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&show_detailed_statistics,
    "r_show_detailed_statistics",
    1,
    command_type_user_specific,
    execution_filter_general);
  show_detailed_statistics.m_value = &s_show_detailed_statistics_value;
  show_detailed_statistics.m_min = 0;
  show_detailed_statistics.m_max = 1;
  show_detailed_statistics.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  show_detailed_statistics.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__show_detailed_statistics__);
}
