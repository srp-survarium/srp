int survarium::_dynamic_initializer_for__s_recoil_horizontal_eanble_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_recoil_horizontal_eanble_cc,
    "recoil_horizontal_enable",
    &s_recoil_horizontal_enable_value,
    0,
    command_type_user_specific,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_recoil_horizontal_eanble_cc__);
}
