int dynamic_initializer_for__draw_respawn_debug_cc__()
{
  draw_respawn_debug_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &draw_respawn_debug_cc;
  vostok::console_commands::s_console_command_root = &draw_respawn_debug_cc;
  draw_respawn_debug_cc.m_value = (bool *)&survarium::g_allocator.l_.a2_.t_ + 3;
  draw_respawn_debug_cc.m_min = 0;
  draw_respawn_debug_cc.m_max = 1;
  draw_respawn_debug_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  draw_respawn_debug_cc.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__draw_respawn_debug_cc__);
}
