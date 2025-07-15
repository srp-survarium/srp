int __thiscall dynamic_initializer_for__s_max_ping_time_in_ms_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_max_ping_time_in_ms_cc,
    "max_ping_time_in_ms",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_max_ping_time_in_ms_cc.m_value = &s_max_ping_time_in_ms;
  s_max_ping_time_in_ms_cc.m_min = 250;
  s_max_ping_time_in_ms_cc.m_max = 1000;
  s_max_ping_time_in_ms_cc.m_need_args = 1;
  s_max_ping_time_in_ms_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_max_ping_time_in_ms_cc__);
}
