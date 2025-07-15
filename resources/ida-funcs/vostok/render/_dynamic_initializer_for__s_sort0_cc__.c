int __thiscall vostok::render::_dynamic_initializer_for__s_sort0_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_sort0_cc,
    "r_sort0",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_sort0_cc.m_value = &s_sort0;
  s_sort0_cc.m_min = 0;
  s_sort0_cc.m_max = 1;
  s_sort0_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_sort0_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_sort0_cc__);
}
