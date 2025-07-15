int __thiscall vostok::render::_dynamic_initializer_for__s_shadows_in_cascade__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_shadows_in_cascade,
    "shadows_in_cascade",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_shadows_in_cascade.m_min = 0;
  s_shadows_in_cascade.m_value = &s_shadows_in_cascade_value;
  s_shadows_in_cascade.m_max = 5;
  s_shadows_in_cascade.m_need_args = 1;
  s_shadows_in_cascade.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_shadows_in_cascade__);
}
