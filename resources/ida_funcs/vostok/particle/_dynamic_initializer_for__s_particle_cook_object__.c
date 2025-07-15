void vostok::particle::_dynamic_initializer_for__s_particle_cook_object__()
{
  vostok::particle::s_particle_cook_object.m_variable = (vostok::particle::particle_system_instance_cook *)&vostok::particle::s_particle_cook_object;
  vostok::particle::s_particle_cook_object.m_initialized = 0;
  vostok::particle::s_particle_cook_object.m_construction_started = 0;
}
