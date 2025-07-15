int __thiscall dynamic_initializer_for__s_foreground_pass_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_foreground_pass_cc,
    "r_foreground_pass",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_foreground_pass_cc.m_value = &s_foreground_pass;
  s_foreground_pass_cc.m_min = 0;
  s_foreground_pass_cc.m_max = 1;
  s_foreground_pass_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_foreground_pass_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_foreground_pass_cc__);
}
