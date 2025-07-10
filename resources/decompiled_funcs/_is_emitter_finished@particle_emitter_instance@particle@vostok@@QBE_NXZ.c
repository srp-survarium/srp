bool __thiscall vostok::particle::particle_emitter_instance::is_emitter_finished(
        vostok::particle::particle_emitter_instance *this)
{
  return this->m_emitter->m_duration > 0.001 && this->m_emitter_time > this->m_current_duration;
}
