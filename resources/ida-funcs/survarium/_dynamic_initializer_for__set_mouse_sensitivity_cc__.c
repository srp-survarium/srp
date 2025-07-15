int survarium::_dynamic_initializer_for__set_mouse_sensitivity_cc__()
{
  set_mouse_sensitivity_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &set_mouse_sensitivity_cc;
  set_mouse_sensitivity_cc.m_min = 0.0099999998;
  vostok::console_commands::s_console_command_root = &set_mouse_sensitivity_cc;
  set_mouse_sensitivity_cc.m_value = &survarium::g_mouse_sensitivity;
  set_mouse_sensitivity_cc.m_max = FLOAT_10_0;
  set_mouse_sensitivity_cc.m_need_args = 1;
  set_mouse_sensitivity_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(survarium::_dynamic_atexit_destructor_for__set_mouse_sensitivity_cc__);
}
