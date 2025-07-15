void __thiscall vostok::particle::particle_emitter_instance::remove_overflowing_particles(
        vostok::particle::particle_emitter_instance *this)
{
  unsigned int v1; // eax
  unsigned int m_current_max_num_particles; // edx

  v1 = this->m_num_live_particles + this->m_num_particles_to_create;
  m_current_max_num_particles = this->m_current_max_num_particles;
  if ( v1 > m_current_max_num_particles )
    vostok::particle::particle_emitter_instance::remove_particles(this, (int)this, v1 - m_current_max_num_particles + 1);
}
