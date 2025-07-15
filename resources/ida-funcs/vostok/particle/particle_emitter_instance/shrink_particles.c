void __thiscall vostok::particle::particle_emitter_instance::shrink_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta,
        float limit_over_total,
        unsigned int num_need_particles)
{
  float v4; // xmm0_4

  v4 = this->m_create_rate * limit_over_total;
  this->m_current_max_num_particles = (unsigned __int64)((double)this->m_current_calc_num_max_particles
                                                       * limit_over_total);
  this->m_current_create_rate = v4;
}
