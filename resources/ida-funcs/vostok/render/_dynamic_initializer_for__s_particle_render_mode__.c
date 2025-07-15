int __thiscall vostok::render::_dynamic_initializer_for__s_particle_render_mode__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_particle_render_mode,
    "particle_render_mode",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_particle_render_mode.m_min = 0;
  s_particle_render_mode.m_value = &s_particle_render_mode_value;
  s_particle_render_mode.m_max = 100;
  s_particle_render_mode.m_need_args = 1;
  s_particle_render_mode.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_particle_render_mode__);
}
