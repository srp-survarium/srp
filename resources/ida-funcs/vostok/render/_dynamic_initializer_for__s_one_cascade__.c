int __thiscall vostok::render::_dynamic_initializer_for__s_one_cascade__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_one_cascade,
    "one_cascade_value",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_one_cascade.m_value = &s_one_cascade_value;
  s_one_cascade.m_min = 0;
  s_one_cascade.m_max = 1;
  s_one_cascade.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_one_cascade.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_one_cascade__);
}
