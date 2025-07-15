int __thiscall survarium::_dynamic_initializer_for__s_freeze_culling__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_freeze_culling,
    "freeze_culling",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_freeze_culling.m_value = &s_freeze_culling_value;
  s_freeze_culling.m_min = 0;
  s_freeze_culling.m_max = 1;
  s_freeze_culling.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_freeze_culling.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_freeze_culling__);
}
