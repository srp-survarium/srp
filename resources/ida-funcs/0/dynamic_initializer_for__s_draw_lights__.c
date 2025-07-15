int dynamic_initializer_for__s_draw_lights__()
{
  s_draw_lights.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_draw_lights;
  vostok::console_commands::s_console_command_root = &s_draw_lights;
  s_draw_lights.m_value = &s_draw_lights_value;
  s_draw_lights.m_min = 0;
  s_draw_lights.m_max = 1;
  s_draw_lights.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_draw_lights.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_draw_lights__);
}
