int __thiscall dynamic_initializer_for__s_general_volume_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_general_volume_cc,
    "s_general_volume",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_general_volume_cc.m_min = 0.0;
  s_general_volume_cc.m_value = &s_general_vol;
  s_general_volume_cc.m_max = s_spot_max_distance;
  s_general_volume_cc.m_need_args = 1;
  s_general_volume_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_general_volume_cc__);
}
