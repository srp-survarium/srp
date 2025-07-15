int survarium::_dynamic_initializer_for__s_ik_use_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_ik_use_cc,
    "ik_enable_on_hands",
    &s_ik_enable_on_hands_value,
    1,
    command_type_engine_internal,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_ik_use_cc__);
}
