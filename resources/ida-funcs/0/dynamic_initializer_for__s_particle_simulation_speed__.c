int dynamic_initializer_for__s_particle_simulation_speed__()
{
  vostok::console_commands::cc_u32::cc_u32(
    &s_particle_simulation_speed,
    command_type_engine_internal,
    execution_filter_general,
    "particle_simulation_speed",
    &s_particle_simulation_speed_value,
    0,
    0x64u,
    1);
  return atexit(dynamic_atexit_destructor_for__s_particle_simulation_speed__);
}
