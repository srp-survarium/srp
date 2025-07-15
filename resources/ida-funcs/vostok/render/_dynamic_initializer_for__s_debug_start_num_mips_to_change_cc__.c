int __thiscall vostok::render::_dynamic_initializer_for__s_debug_start_num_mips_to_change_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_debug_start_num_mips_to_change_cc,
    "r_debug_start_num_mips_to_change",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_debug_start_num_mips_to_change_cc.m_min = 0;
  s_debug_start_num_mips_to_change_cc.m_value = &s_debug_start_num_mips_to_change;
  s_debug_start_num_mips_to_change_cc.m_max = 14;
  s_debug_start_num_mips_to_change_cc.m_need_args = 1;
  s_debug_start_num_mips_to_change_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_debug_start_num_mips_to_change_cc__);
}
