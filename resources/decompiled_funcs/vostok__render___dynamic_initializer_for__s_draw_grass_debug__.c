int vostok::render::_dynamic_initializer_for__s_draw_grass_debug__()
{
  s_draw_grass_debug.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_draw_grass_debug;
  vostok::console_commands::s_console_command_root = &s_draw_grass_debug;
  s_draw_grass_debug.m_value = &s_draw_grass_debug_value;
  s_draw_grass_debug.m_min = 0;
  s_draw_grass_debug.m_max = 1;
  s_draw_grass_debug.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_draw_grass_debug.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_draw_grass_debug__);
}
