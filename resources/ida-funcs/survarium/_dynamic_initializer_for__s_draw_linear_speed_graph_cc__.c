int survarium::_dynamic_initializer_for__s_draw_linear_speed_graph_cc__()
{
  s_draw_linear_speed_graph_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_draw_linear_speed_graph_cc;
  vostok::console_commands::s_console_command_root = &s_draw_linear_speed_graph_cc;
  s_draw_linear_speed_graph_cc.m_value = (bool *)&survarium::g_allocator.l_.a2_.t_ + 2;
  s_draw_linear_speed_graph_cc.m_min = 0;
  s_draw_linear_speed_graph_cc.m_max = 1;
  s_draw_linear_speed_graph_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_draw_linear_speed_graph_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_draw_linear_speed_graph_cc__);
}
