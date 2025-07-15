int survarium::_dynamic_initializer_for__s_recoil_enable_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_recoil_enable_cc,
    "recoil_enable",
    &s_recoil_enable_value,
    1,
    command_type_user_specific,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_recoil_enable_cc__);
}
