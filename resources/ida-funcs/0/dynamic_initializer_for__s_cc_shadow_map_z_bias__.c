int __thiscall dynamic_initializer_for__s_cc_shadow_map_z_bias__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_cc_shadow_map_z_bias,
    "shadow_map_z_bias",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_cc_shadow_map_z_bias.m_min = 0.0;
  s_cc_shadow_map_z_bias.m_value = &s_shadow_map_z_bias;
  s_cc_shadow_map_z_bias.m_max = FLOAT_4_0;
  s_cc_shadow_map_z_bias.m_need_args = 1;
  s_cc_shadow_map_z_bias.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_cc_shadow_map_z_bias__);
}
