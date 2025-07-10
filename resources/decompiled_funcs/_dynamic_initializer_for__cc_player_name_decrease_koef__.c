int dynamic_initializer_for__cc_player_name_decrease_koef__()
{
  cc_player_name_decrease_koef.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_player_name_decrease_koef;
  cc_player_name_decrease_koef.m_min = 0.0;
  vostok::console_commands::s_console_command_root = &cc_player_name_decrease_koef;
  cc_player_name_decrease_koef.m_value = &s_player_name_decrease_koef;
  LODWORD(cc_player_name_decrease_koef.m_max) = clear_value;
  cc_player_name_decrease_koef.m_need_args = 1;
  cc_player_name_decrease_koef.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__cc_player_name_decrease_koef__);
}
