int __thiscall vostok::render::_dynamic_initializer_for__s_do_stages_profiling_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_do_stages_profiling_cc,
    "r_show_stage_stats",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_do_stages_profiling_cc.m_value = &s_do_stages_profiling;
  s_do_stages_profiling_cc.m_min = 0;
  s_do_stages_profiling_cc.m_max = 1;
  s_do_stages_profiling_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_do_stages_profiling_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_do_stages_profiling_cc__);
}
