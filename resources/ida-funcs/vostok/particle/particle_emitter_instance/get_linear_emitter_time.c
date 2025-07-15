double __thiscall vostok::particle::particle_emitter_instance::get_linear_emitter_time(
        vostok::particle::particle_emitter_instance *this)
{
  if ( this->m_emitter->m_duration <= 0.001 )
    return this->m_emitter_time;
  else
    return this->m_emitter_time / this->m_emitter->m_duration;
}
