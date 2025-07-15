int __thiscall vostok::render::_dynamic_initializer_for__s_max_triagles_per_dip__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_max_triagles_per_dip,
    "max_triagles_per_dip",
    0,
    command_type_user_specific,
    execution_filter_general);
  s_max_triagles_per_dip.m_min = 0;
  s_max_triagles_per_dip.m_value = &s_max_triagles_per_dip_value;
  s_max_triagles_per_dip.m_max = (unsigned int)&loc_1869F + 1;
  s_max_triagles_per_dip.m_need_args = 1;
  s_max_triagles_per_dip.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_max_triagles_per_dip__);
}
