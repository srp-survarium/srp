int __thiscall dynamic_initializer_for__s_net_client_account_name_cc__(vostok::console_commands::cc_string *this)
{
  vostok::console_commands::cc_string::cc_string(
    this,
    (int)&s_net_client_account_name_cc,
    "account_name",
    s_net_client_account_name,
    0x80u,
    1,
    command_type_user_specific,
    execution_filter_general);
  return atexit(dynamic_atexit_destructor_for__s_net_client_account_name_cc__);
}
