int __thiscall survarium::_dynamic_initializer_for__s_store_user_pass_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_store_user_pass_cc,
    "store_user_password",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_store_user_pass_cc.m_value = &survarium::s_store_user_pass;
  s_store_user_pass_cc.m_min = 0;
  s_store_user_pass_cc.m_max = 1;
  s_store_user_pass_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_store_user_pass_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_store_user_pass_cc__);
}
