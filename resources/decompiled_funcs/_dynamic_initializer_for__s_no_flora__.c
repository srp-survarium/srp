int dynamic_initializer_for__s_no_flora__()
{
  s_no_flora.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_no_flora;
  vostok::console_commands::s_console_command_root = &s_no_flora;
  s_no_flora.m_value = (bool *)&blend_alpha.elements[1] + 2;
  s_no_flora.m_min = 0;
  s_no_flora.m_max = 1;
  s_no_flora.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_no_flora.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_no_flora__);
}
