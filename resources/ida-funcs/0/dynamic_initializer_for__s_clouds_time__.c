int __thiscall dynamic_initializer_for__s_clouds_time__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_clouds_time,
    "clouds_time",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_clouds_time.m_min = 0.0;
  s_clouds_time.m_value = &s_clouds_time_value;
  s_clouds_time.m_max = s_bm_current_air_resistance;
  s_clouds_time.m_need_args = 1;
  s_clouds_time.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_clouds_time__);
}
