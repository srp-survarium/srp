int __thiscall dynamic_initializer_for__s_draw_lights__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_lights,
    "draw_lights",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_draw_lights.m_value = &s_draw_lights_value;
  s_draw_lights.m_min = 0;
  s_draw_lights.m_max = 1;
  s_draw_lights.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_draw_lights.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_draw_lights__);
}
