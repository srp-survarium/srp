int __thiscall dynamic_initializer_for__s_use_poral_culling_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_use_poral_culling_cc,
    "r_use_portal_culling",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_use_poral_culling_cc.m_value = &s_use_poral_culling_value;
  s_use_poral_culling_cc.m_min = 0;
  s_use_poral_culling_cc.m_max = 1;
  s_use_poral_culling_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_use_poral_culling_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_use_poral_culling_cc__);
}
