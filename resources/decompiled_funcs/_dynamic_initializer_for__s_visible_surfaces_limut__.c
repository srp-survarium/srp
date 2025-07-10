int dynamic_initializer_for__s_visible_surfaces_limut__()
{
  s_visible_surfaces_limut.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_visible_surfaces_limut;
  vostok::console_commands::s_console_command_root = &s_visible_surfaces_limut;
  s_visible_surfaces_limut.m_value = (unsigned int *)&blend_alpha.z;
  s_visible_surfaces_limut.m_min = 0;
  s_visible_surfaces_limut.m_max = (unsigned int)&loc_186A0;
  s_visible_surfaces_limut.m_need_args = 1;
  s_visible_surfaces_limut.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_visible_surfaces_limut__);
}
