bool __thiscall vostok::particle::particle_emitter_instance::is_finished(
        vostok::particle::particle_emitter_instance *this)
{
  unsigned int m_num_loops; // eax

  m_num_loops = this->m_emitter->m_num_loops;
  if ( !m_num_loops )
    return 0;
  return this->m_current_loop == m_num_loops && !this->m_waiting_for_end;
}
