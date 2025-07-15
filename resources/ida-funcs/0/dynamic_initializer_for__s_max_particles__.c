int __thiscall dynamic_initializer_for__s_max_particles__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_max_particles,
    "max_particles",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_max_particles.m_min = 0;
  s_max_particles.m_value = &s_max_particles_value;
  s_max_particles.m_max = 1000;
  s_max_particles.m_need_args = 1;
  s_max_particles.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_max_particles__);
}
