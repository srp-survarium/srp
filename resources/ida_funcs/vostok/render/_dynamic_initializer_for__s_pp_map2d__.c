int vostok::render::_dynamic_initializer_for__s_pp_map2d__()
{
  s_pp_map2d.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_pp_map2d;
  vostok::console_commands::s_console_command_root = &s_pp_map2d;
  s_pp_map2d.m_value = &s_pp_map2d_value;
  s_pp_map2d.m_min = 0;
  s_pp_map2d.m_max = 1;
  s_pp_map2d.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_pp_map2d.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_pp_map2d__);
}
