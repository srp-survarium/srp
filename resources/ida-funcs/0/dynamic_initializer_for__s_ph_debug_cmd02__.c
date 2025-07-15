int dynamic_initializer_for__s_ph_debug_cmd02__()
{
  s_ph_debug_cmd02.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_ph_debug_cmd02;
  vostok::console_commands::s_console_command_root = &s_ph_debug_cmd02;
  s_ph_debug_cmd02.m_value = &s_debug_draw_hittable;
  s_ph_debug_cmd02.m_min = 0;
  s_ph_debug_cmd02.m_max = 1;
  s_ph_debug_cmd02.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_ph_debug_cmd02.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_ph_debug_cmd02__);
}
