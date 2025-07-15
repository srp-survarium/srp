int __thiscall vostok::render::_dynamic_initializer_for__s_r_resolution_cc__(
        vostok::console_commands::console_command *this)
{
  char *m_begin; // esi

  m_begin = s_r_resolution_value.m_begin;
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_r_resolution_cc,
    "r_resolution",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_r_resolution_cc.__vftable = (vostok::console_commands::cc_string_vtbl *)&vostok::console_commands::cc_string::`vftable';
  s_r_resolution_cc.m_value = m_begin;
  s_r_resolution_cc.m_size = 16;
  s_r_resolution_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_r_resolution_cc__);
}
