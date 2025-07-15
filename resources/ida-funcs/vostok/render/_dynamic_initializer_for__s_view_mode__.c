int __thiscall vostok::render::_dynamic_initializer_for__s_view_mode__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_view_mode,
    "r_view_mode",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_view_mode.m_min = 0;
  s_view_mode.m_value = &s_view_mode_value;
  s_view_mode.m_max = 26;
  s_view_mode.m_need_args = 1;
  s_view_mode.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_view_mode__);
}
