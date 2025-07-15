int __thiscall vostok::render::_dynamic_initializer_for__s_hiz_8__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_hiz_8,
    "hiz_8",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_hiz_8.m_value = &s_hiz_8_value;
  s_hiz_8.m_min = 0;
  s_hiz_8.m_max = 1;
  s_hiz_8.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_hiz_8.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_hiz_8__);
}
