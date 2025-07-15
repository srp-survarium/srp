int __thiscall dynamic_initializer_for__s_show_profiler_command__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_show_profiler_command,
    "show_profiler",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_show_profiler_command.m_value = &s_show_profiler;
  s_show_profiler_command.m_min = 0;
  s_show_profiler_command.m_max = 1;
  s_show_profiler_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_show_profiler_command.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_show_profiler_command__);
}
