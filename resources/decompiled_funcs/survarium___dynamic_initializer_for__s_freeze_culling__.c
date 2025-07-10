int survarium::_dynamic_initializer_for__s_freeze_culling__()
{
  s_freeze_culling.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_freeze_culling;
  vostok::console_commands::s_console_command_root = &s_freeze_culling;
  s_freeze_culling.m_value = &s_freeze_culling_value;
  s_freeze_culling.m_min = 0;
  s_freeze_culling.m_max = 1;
  s_freeze_culling.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_freeze_culling.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_freeze_culling__);
}
