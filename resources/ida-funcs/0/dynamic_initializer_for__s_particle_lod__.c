int dynamic_initializer_for__s_particle_lod__()
{
  s_particle_lod.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_particle_lod;
  vostok::console_commands::s_console_command_root = &s_particle_lod;
  s_particle_lod.m_value = (unsigned int *)&survarium::g_allocator.l_;
  s_particle_lod.m_min = 0;
  s_particle_lod.m_max = 10;
  s_particle_lod.m_need_args = 1;
  s_particle_lod.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(dynamic_atexit_destructor_for__s_particle_lod__);
}
