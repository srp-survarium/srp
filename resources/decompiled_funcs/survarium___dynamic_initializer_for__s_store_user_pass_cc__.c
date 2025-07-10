int survarium::_dynamic_initializer_for__s_store_user_pass_cc__()
{
  s_store_user_pass_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_store_user_pass_cc;
  vostok::console_commands::s_console_command_root = &s_store_user_pass_cc;
  s_store_user_pass_cc.m_value = &survarium::s_store_user_pass;
  s_store_user_pass_cc.m_min = 0;
  s_store_user_pass_cc.m_max = 1;
  s_store_user_pass_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)stru_95AF78.m_key_bindings[45].m_keyboard;
  s_store_user_pass_cc.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_store_user_pass_cc__);
}
