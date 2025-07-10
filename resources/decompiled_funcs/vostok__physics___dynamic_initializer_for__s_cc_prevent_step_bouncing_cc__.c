int vostok::physics::_dynamic_initializer_for__s_cc_prevent_step_bouncing_cc__()
{
  s_cc_prevent_step_bouncing_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_cc_prevent_step_bouncing_cc;
  vostok::console_commands::s_console_command_root = &s_cc_prevent_step_bouncing_cc;
  s_cc_prevent_step_bouncing_cc.m_value = &s_cc_prevent_step_bouncing_value;
  s_cc_prevent_step_bouncing_cc.m_min = 0;
  s_cc_prevent_step_bouncing_cc.m_max = 1;
  s_cc_prevent_step_bouncing_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_cc_prevent_step_bouncing_cc.m_need_args = 1;
  return atexit(vostok::physics::_dynamic_atexit_destructor_for__s_cc_prevent_step_bouncing_cc__);
}
