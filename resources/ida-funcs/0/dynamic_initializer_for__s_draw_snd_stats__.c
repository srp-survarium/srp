int __thiscall dynamic_initializer_for__s_draw_snd_stats__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_draw_snd_stats,
    "draw_sound_stats",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_draw_snd_stats.m_value = &s_draw_snd_stats_value;
  s_draw_snd_stats.m_min = 0;
  s_draw_snd_stats.m_max = 1;
  s_draw_snd_stats.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_draw_snd_stats.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_draw_snd_stats__);
}
