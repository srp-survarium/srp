int __thiscall dynamic_initializer_for__s_shadow_z_near__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_shadow_z_near,
    "shadow_z_near",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_shadow_z_near.m_min = FLOAT_0_0099999998;
  s_shadow_z_near.m_value = &s_shadow_z_near_value;
  s_shadow_z_near.m_max = s_bm_current_air_resistance;
  s_shadow_z_near.m_need_args = 1;
  s_shadow_z_near.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_shadow_z_near__);
}
