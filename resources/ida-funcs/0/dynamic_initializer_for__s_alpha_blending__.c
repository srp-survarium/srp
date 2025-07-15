int __thiscall dynamic_initializer_for__s_alpha_blending__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_alpha_blending,
    "alpha_blending",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_alpha_blending.m_value = &s_alpha_blending_value;
  s_alpha_blending.m_min = 0;
  s_alpha_blending.m_max = 1;
  s_alpha_blending.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_alpha_blending.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_alpha_blending__);
}
