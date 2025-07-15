int __thiscall vostok::render::_dynamic_initializer_for__s_draw_grass_debug_0__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_grass_debug_0,
    "r_draw_grass_debug_0",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_draw_grass_debug_0.m_value = &s_draw_grass_debug_value_0;
  s_draw_grass_debug_0.m_min = 0;
  s_draw_grass_debug_0.m_max = 1;
  s_draw_grass_debug_0.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_draw_grass_debug_0.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_draw_grass_debug_0__);
}
