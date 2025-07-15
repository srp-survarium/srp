int __thiscall dynamic_initializer_for__s_particle_lod__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_particle_lod,
    "particle_lod",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_particle_lod.m_min = 0;
  s_particle_lod.m_value = &s_particle_lod_value;
  s_particle_lod.m_max = 10;
  s_particle_lod.m_need_args = 1;
  s_particle_lod.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_particle_lod__);
}
