int dynamic_initializer_for__s_draw_snd_stats__()
{
  s_draw_snd_stats.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_draw_snd_stats;
  vostok::console_commands::s_console_command_root = &s_draw_snd_stats;
  s_draw_snd_stats.m_value = (bool *)&survarium::g_allocator.f_.f_ + 4;
  s_draw_snd_stats.m_min = 0;
  s_draw_snd_stats.m_max = 1;
  s_draw_snd_stats.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_draw_snd_stats.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_draw_snd_stats__);
}
