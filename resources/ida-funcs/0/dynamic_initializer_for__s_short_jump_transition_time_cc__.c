int __thiscall dynamic_initializer_for__s_short_jump_transition_time_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_short_jump_transition_time_cc,
    "short_jump_transition_time",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_short_jump_transition_time_cc.m_min = FLOAT_0_0099999998;
  s_short_jump_transition_time_cc.m_value = &g_short_jump_transition_time;
  s_short_jump_transition_time_cc.m_max = s_aim_transition_time;
  s_short_jump_transition_time_cc.m_need_args = 1;
  s_short_jump_transition_time_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_short_jump_transition_time_cc__);
}
