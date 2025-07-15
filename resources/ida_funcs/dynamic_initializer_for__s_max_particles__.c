int dynamic_initializer_for__s_max_particles__()
{
  s_max_particles.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_max_particles;
  vostok::console_commands::s_console_command_root = &s_max_particles;
  s_max_particles.m_value = &s_max_particles_value;
  s_max_particles.m_min = 0;
  s_max_particles.m_max = 1000;
  s_max_particles.m_need_args = 1;
  s_max_particles.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_max_particles__);
}
