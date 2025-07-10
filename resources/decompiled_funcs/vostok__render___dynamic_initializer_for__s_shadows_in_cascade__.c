int vostok::render::_dynamic_initializer_for__s_shadows_in_cascade__()
{
  s_shadows_in_cascade.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_shadows_in_cascade;
  vostok::console_commands::s_console_command_root = &s_shadows_in_cascade;
  s_shadows_in_cascade.m_value = &s_shadows_in_cascade_value;
  s_shadows_in_cascade.m_min = 0;
  s_shadows_in_cascade.m_max = 5;
  s_shadows_in_cascade.m_need_args = 1;
  s_shadows_in_cascade.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_shadows_in_cascade__);
}
