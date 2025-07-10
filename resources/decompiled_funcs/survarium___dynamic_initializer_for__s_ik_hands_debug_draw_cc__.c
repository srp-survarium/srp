int survarium::_dynamic_initializer_for__s_ik_hands_debug_draw_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_ik_hands_debug_draw_cc,
    "ik_hands_debug_draw",
    &s_ik_hands_debug_draw_value,
    0,
    command_type_user_specific,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_ik_hands_debug_draw_cc__);
}
