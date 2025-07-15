int __thiscall dynamic_initializer_for__s_particle_simulation_speed__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_particle_simulation_speed,
    "particle_time_scale",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_particle_simulation_speed.m_min = epsilon_3_4;
  s_particle_simulation_speed.m_value = &s_particle_simulation_speed_value;
  s_particle_simulation_speed.m_max = FLOAT_5_0;
  s_particle_simulation_speed.m_need_args = 1;
  s_particle_simulation_speed.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(dynamic_atexit_destructor_for__s_particle_simulation_speed__);
}
