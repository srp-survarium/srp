int __thiscall dynamic_initializer_for__s_net_client_account_password_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_net_client_account_password_cc,
    "account_password",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_net_client_account_password_cc.__vftable = (vostok::console_commands::cc_string_vtbl *)&vostok::console_commands::cc_string::`vftable';
  s_net_client_account_password_cc.m_value = s_net_client_account_password;
  s_net_client_account_password_cc.m_size = 128;
  s_net_client_account_password_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_net_client_account_password_cc__);
}
