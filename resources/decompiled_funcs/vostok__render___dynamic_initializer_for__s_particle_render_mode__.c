int vostok::render::_dynamic_initializer_for__s_particle_render_mode__()
{
  s_particle_render_mode.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_particle_render_mode;
  vostok::console_commands::s_console_command_root = &s_particle_render_mode;
  s_particle_render_mode.m_value = &s_particle_render_mode_value;
  s_particle_render_mode.m_min = 0;
  s_particle_render_mode.m_max = 100;
  s_particle_render_mode.m_need_args = 1;
  s_particle_render_mode.__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_particle_render_mode__);
}
