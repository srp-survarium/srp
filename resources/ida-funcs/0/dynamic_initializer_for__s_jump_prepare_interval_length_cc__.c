int __thiscall dynamic_initializer_for__s_jump_prepare_interval_length_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_jump_prepare_interval_length_cc,
    "jump_prepare_interval_length",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_jump_prepare_interval_length_cc.m_min = FLOAT_0_0099999998;
  s_jump_prepare_interval_length_cc.m_value = &g_jump_prepare_interval_length;
  s_jump_prepare_interval_length_cc.m_max = s_aim_transition_time;
  s_jump_prepare_interval_length_cc.m_need_args = 1;
  s_jump_prepare_interval_length_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_jump_prepare_interval_length_cc__);
}
