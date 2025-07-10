int dynamic_initializer_for__s_test_players_random_input_cc__()
{
  s_test_players_random_input_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_test_players_random_input_cc;
  vostok::console_commands::s_console_command_root = &s_test_players_random_input_cc;
  s_test_players_random_input_cc.m_value = &s_is_test_players_random_input_enabled;
  s_test_players_random_input_cc.m_min = 0;
  s_test_players_random_input_cc.m_max = 1;
  s_test_players_random_input_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_test_players_random_input_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_test_players_random_input_cc__);
}
