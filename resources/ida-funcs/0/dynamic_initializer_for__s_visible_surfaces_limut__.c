int __thiscall dynamic_initializer_for__s_visible_surfaces_limut__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_visible_surfaces_limut,
    "visible_surfaces_limut",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_visible_surfaces_limut.m_min = 0;
  s_visible_surfaces_limut.m_value = &s_visible_surfaces_limit_value;
  s_visible_surfaces_limut.m_max = (unsigned int)&loc_1869F + 1;
  s_visible_surfaces_limut.m_need_args = 1;
  s_visible_surfaces_limut.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_visible_surfaces_limut__);
}
