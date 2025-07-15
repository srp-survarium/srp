int __thiscall survarium::_dynamic_initializer_for__cc_icon_name_min_alpha__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_icon_name_min_alpha,
    "icon_name_min_alpha",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_icon_name_min_alpha.m_min = 0;
  cc_icon_name_min_alpha.m_value = &survarium::g_icon_name_min_alpha;
  cc_icon_name_min_alpha.m_max = 255;
  cc_icon_name_min_alpha.m_need_args = 1;
  cc_icon_name_min_alpha.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_icon_name_min_alpha__);
}
