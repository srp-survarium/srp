int dynamic_initializer_for__cc_player_name_max_font_size__()
{
  cc_player_name_max_font_size.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_player_name_max_font_size;
  LODWORD(cc_player_name_max_font_size.m_min) = clear_value;
  vostok::console_commands::s_console_command_root = &cc_player_name_max_font_size;
  cc_player_name_max_font_size.m_value = &s_player_name_max_font_size;
  cc_player_name_max_font_size.m_max = 100.0;
  cc_player_name_max_font_size.m_need_args = 1;
  cc_player_name_max_font_size.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__cc_player_name_max_font_size__);
}
