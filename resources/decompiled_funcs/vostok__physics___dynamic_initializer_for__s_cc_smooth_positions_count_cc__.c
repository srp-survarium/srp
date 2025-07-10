int vostok::physics::_dynamic_initializer_for__s_cc_smooth_positions_count_cc__()
{
  s_cc_smooth_positions_count_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_cc_smooth_positions_count_cc;
  vostok::console_commands::s_console_command_root = &s_cc_smooth_positions_count_cc;
  s_cc_smooth_positions_count_cc.m_value = &s_cc_smooth_positions_count_value;
  s_cc_smooth_positions_count_cc.m_min = 1;
  s_cc_smooth_positions_count_cc.m_max = 100;
  s_cc_smooth_positions_count_cc.m_need_args = 1;
  s_cc_smooth_positions_count_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_cc_smooth_positions_count_cc__);
}
