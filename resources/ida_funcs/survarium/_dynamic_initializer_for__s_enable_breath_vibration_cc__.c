int survarium::_dynamic_initializer_for__s_enable_breath_vibration_cc__()
{
  vostok::console_commands::cc_bool::cc_bool(
    &s_enable_breath_vibration_cc,
    (const char *)&stru_977EF0.m_current_quality_level,
    &s_enable_breath_vibration_value,
    1,
    command_type_engine_internal,
    execution_filter_general);
  return atexit(survarium::_dynamic_atexit_destructor_for__s_enable_breath_vibration_cc__);
}
