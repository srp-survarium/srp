int dynamic_initializer_for__s_lights_cull__()
{
  s_lights_cull.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_lights_cull;
  vostok::console_commands::s_console_command_root = &s_lights_cull;
  s_lights_cull.m_value = &s_lights_cull_value;
  s_lights_cull.m_min = 0;
  s_lights_cull.m_max = 1;
  s_lights_cull.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_lights_cull.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_lights_cull__);
}
