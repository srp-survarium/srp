int dynamic_initializer_for__bullet_tracers_max_count_cc__()
{
  bullet_tracers_max_count_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &bullet_tracers_max_count_cc;
  vostok::console_commands::s_console_command_root = &bullet_tracers_max_count_cc;
  bullet_tracers_max_count_cc.m_value = &s_max_tracers_count;
  bullet_tracers_max_count_cc.m_min = 2;
  bullet_tracers_max_count_cc.m_max = 128;
  bullet_tracers_max_count_cc.m_need_args = 1;
  bullet_tracers_max_count_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__bullet_tracers_max_count_cc__);
}
