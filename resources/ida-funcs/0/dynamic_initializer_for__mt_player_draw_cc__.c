int __thiscall dynamic_initializer_for__mt_player_draw_cc__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&mt_player_draw_cc,
    "mt_player_draw",
    1,
    command_type_engine_internal,
    execution_filter_general);
  mt_player_draw_cc.m_value = &s_mt_player_draw;
  mt_player_draw_cc.m_min = 0;
  mt_player_draw_cc.m_max = 1;
  mt_player_draw_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  mt_player_draw_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__mt_player_draw_cc__);
}
