int __thiscall dynamic_initializer_for__cc_grenade_icon_size__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_grenade_icon_size,
    "grenade_icon_size",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_grenade_icon_size.m_min = FLOAT_0_1;
  cc_grenade_icon_size.m_value = &s_grenade_icon_size;
  cc_grenade_icon_size.m_max = s_spot_max_distance;
  cc_grenade_icon_size.m_need_args = 1;
  cc_grenade_icon_size.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__cc_grenade_icon_size__);
}
