void __thiscall vostok::particle::particle_emitter_instance::recalc_duration(
        vostok::particle::particle_emitter_instance *this)
{
  this->m_current_duration = vostok::particle::calc_duration(
                               this->m_emitter->m_duration,
                               this->m_emitter->m_duration_variance);
}
