int __thiscall vostok::render::_dynamic_initializer_for__s_debug_ssao_techh__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_debug_ssao_techh,
    "r_debug_ssao_tech",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_debug_ssao_techh.m_min = 0;
  s_debug_ssao_techh.m_value = &debug_ssao_tech;
  s_debug_ssao_techh.m_max = 1;
  s_debug_ssao_techh.m_need_args = 1;
  s_debug_ssao_techh.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_debug_ssao_techh__);
}
