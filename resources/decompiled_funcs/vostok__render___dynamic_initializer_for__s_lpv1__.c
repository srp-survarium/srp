int vostok::render::_dynamic_initializer_for__s_lpv1__()
{
  s_lpv1.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_lpv1;
  vostok::console_commands::s_console_command_root = &s_lpv1;
  s_lpv1.m_value = &s_lpv1_value;
  s_lpv1.m_min = 0;
  s_lpv1.m_max = 1;
  s_lpv1.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_lpv1.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_lpv1__);
}
