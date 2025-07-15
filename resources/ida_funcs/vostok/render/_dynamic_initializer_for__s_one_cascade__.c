int vostok::render::_dynamic_initializer_for__s_one_cascade__()
{
  s_one_cascade.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_one_cascade;
  vostok::console_commands::s_console_command_root = &s_one_cascade;
  s_one_cascade.m_value = &s_one_cascade_value;
  s_one_cascade.m_min = 0;
  s_one_cascade.m_max = 1;
  s_one_cascade.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_one_cascade.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_one_cascade__);
}
