int __thiscall dynamic_initializer_for__s_lights_cull__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_lights_cull,
    "lights_cull",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_lights_cull.m_value = &s_lights_cull_value;
  s_lights_cull.m_min = 0;
  s_lights_cull.m_max = 1;
  s_lights_cull.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_lights_cull.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_lights_cull__);
}
