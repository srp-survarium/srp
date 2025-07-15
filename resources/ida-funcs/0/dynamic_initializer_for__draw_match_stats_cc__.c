int __thiscall dynamic_initializer_for__draw_match_stats_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&draw_match_stats_cc,
    "draw_match_stats",
    1,
    command_type_user_specific,
    execution_filter_general);
  draw_match_stats_cc.m_value = &s_draw_game_match_stats;
  draw_match_stats_cc.m_min = 0;
  draw_match_stats_cc.m_max = 1;
  draw_match_stats_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  draw_match_stats_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__draw_match_stats_cc__);
}
