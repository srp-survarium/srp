int __thiscall dynamic_initializer_for__bullet_tracers_max_count_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&bullet_tracers_max_count_cc,
    "bullet_tracers_max_count",
    1,
    command_type_engine_internal,
    execution_filter_general);
  bullet_tracers_max_count_cc.m_value = &s_max_tracers_count;
  bullet_tracers_max_count_cc.m_min = 2;
  bullet_tracers_max_count_cc.m_max = 128;
  bullet_tracers_max_count_cc.m_need_args = 1;
  bullet_tracers_max_count_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__bullet_tracers_max_count_cc__);
}
