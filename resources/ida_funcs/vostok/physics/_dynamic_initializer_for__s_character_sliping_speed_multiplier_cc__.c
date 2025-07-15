int vostok::physics::_dynamic_initializer_for__s_character_sliping_speed_multiplier_cc__()
{
  s_character_sliping_speed_multiplier_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_character_sliping_speed_multiplier_cc;
  s_character_sliping_speed_multiplier_cc.m_min = 0.0099999998;
  vostok::console_commands::s_console_command_root = &s_character_sliping_speed_multiplier_cc;
  s_character_sliping_speed_multiplier_cc.m_value = &s_character_sliping_speed_multiplier_value;
  s_character_sliping_speed_multiplier_cc.m_max = 100.0;
  s_character_sliping_speed_multiplier_cc.m_need_args = 1;
  s_character_sliping_speed_multiplier_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_character_sliping_speed_multiplier_cc__);
}
