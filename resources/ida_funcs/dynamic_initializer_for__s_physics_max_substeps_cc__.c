int dynamic_initializer_for__s_physics_max_substeps_cc__()
{
  s_physics_max_substeps_cc.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_physics_max_substeps_cc;
  vostok::console_commands::s_console_command_root = &s_physics_max_substeps_cc;
  s_physics_max_substeps_cc.m_value = &s_physics_max_substeps_value;
  s_physics_max_substeps_cc.m_min = 0;
  s_physics_max_substeps_cc.m_max = 100;
  s_physics_max_substeps_cc.m_need_args = 1;
  s_physics_max_substeps_cc.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_physics_max_substeps_cc__);
}
