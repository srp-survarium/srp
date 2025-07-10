void __thiscall vostok::particle::particle_emitter_instance::remove_overflowing_particles(
        vostok::particle::particle_emitter_instance *this)
{
  unsigned int num_need; // [esp+4h] [ebp-4h]

  num_need = this->m_num_particles_to_create + this->m_num_live_particles;
  if ( num_need > this->m_current_max_num_particles )
    vostok::particle::particle_emitter_instance::remove_particles(
      this,
      num_need - this->m_current_max_num_particles + 1);
}
