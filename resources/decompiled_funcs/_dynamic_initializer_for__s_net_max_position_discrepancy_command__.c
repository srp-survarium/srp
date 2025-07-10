int dynamic_initializer_for__s_net_max_position_discrepancy_command__()
{
  s_net_max_position_discrepancy_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_net_max_position_discrepancy_command;
  s_net_max_position_discrepancy_command.m_min = bi_spline_knots_resolution_eps;
  vostok::console_commands::s_console_command_root = &s_net_max_position_discrepancy_command;
  s_net_max_position_discrepancy_command.m_value = &s_net_max_position_discrepancy;
  s_net_max_position_discrepancy_command.m_max = FLOAT_0_1;
  s_net_max_position_discrepancy_command.m_need_args = 1;
  s_net_max_position_discrepancy_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(dynamic_atexit_destructor_for__s_net_max_position_discrepancy_command__);
}
