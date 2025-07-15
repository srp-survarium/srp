void vostok::particle::_dynamic_initializer_for__s_particle_system_cook__()
{
  vostok::particle::s_particle_system_cook.m_variable = (vostok::particle::particle_system_cook *)&vostok::particle::s_particle_system_cook;
  vostok::particle::s_particle_system_cook.m_initialized = 0;
  vostok::particle::s_particle_system_cook.m_construction_started = 0;
}
