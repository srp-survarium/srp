int survarium::_dynamic_initializer_for__s_recoil_use_pseudo_random_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_recoil_use_pseudo_random_cc,
    "recoil_use_pseudo_random",
    &s_recoil_use_pseudo_random_value,
    0,
    command_type_engine_internal,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_recoil_use_pseudo_random_cc__);
}
