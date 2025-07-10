int dynamic_initializer_for__draw_match_stats_cc__()
{
  draw_match_stats_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &draw_match_stats_cc;
  vostok::console_commands::s_console_command_root = &draw_match_stats_cc;
  draw_match_stats_cc.m_value = &s_draw_game_match_stats;
  draw_match_stats_cc.m_min = 0;
  draw_match_stats_cc.m_max = 1;
  draw_match_stats_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  draw_match_stats_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__draw_match_stats_cc__);
}
