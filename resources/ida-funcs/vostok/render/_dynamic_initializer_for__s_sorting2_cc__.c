int __thiscall vostok::render::_dynamic_initializer_for__s_sorting2_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_sorting2_cc,
    "r_use_sorting_by_distance",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_sorting2_cc.m_value = &s_sorting2_value;
  s_sorting2_cc.m_min = 0;
  s_sorting2_cc.m_max = 1;
  s_sorting2_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_sorting2_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_sorting2_cc__);
}
