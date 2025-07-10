int dynamic_initializer_for__s_no_bushes__()
{
  s_no_bushes.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_no_bushes;
  vostok::console_commands::s_console_command_root = &s_no_bushes;
  s_no_bushes.m_value = &s_no_bushes_value;
  s_no_bushes.m_min = 0;
  s_no_bushes.m_max = 1;
  s_no_bushes.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_no_bushes.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_no_bushes__);
}
