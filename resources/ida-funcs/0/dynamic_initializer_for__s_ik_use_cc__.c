int __thiscall dynamic_initializer_for__s_ik_use_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_ik_use_cc,
    "ik_on_hands",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_ik_use_cc.m_value = &s_ik_enable_on_hands_value;
  s_ik_use_cc.m_min = 0;
  s_ik_use_cc.m_max = 1;
  s_ik_use_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_ik_use_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_ik_use_cc__);
}
