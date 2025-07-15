int dynamic_initializer_for__s_is_ui_minimap_rotable__()
{
  s_is_ui_minimap_rotable.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_is_ui_minimap_rotable;
  vostok::console_commands::s_console_command_root = &s_is_ui_minimap_rotable;
  s_is_ui_minimap_rotable.m_value = &is_ui_minimap_rotable;
  s_is_ui_minimap_rotable.m_min = 0;
  s_is_ui_minimap_rotable.m_max = 1;
  s_is_ui_minimap_rotable.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_is_ui_minimap_rotable.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_is_ui_minimap_rotable__);
}
