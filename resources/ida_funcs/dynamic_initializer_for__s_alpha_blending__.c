int dynamic_initializer_for__s_alpha_blending__()
{
  s_alpha_blending.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_alpha_blending;
  vostok::console_commands::s_console_command_root = &s_alpha_blending;
  s_alpha_blending.m_value = &s_alpha_blending_value;
  s_alpha_blending.m_min = 0;
  s_alpha_blending.m_max = 1;
  s_alpha_blending.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_alpha_blending.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_alpha_blending__);
}
