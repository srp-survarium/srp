unsigned int __thiscall vostok::particle::particle_emitter_instance::calc_num_new_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta,
        bool allow_to_create_new)
{
  unsigned int v4; // ecx
  vostok::particle::particle_emitter *m_emitter; // eax
  float m_emitter_time; // xmm1_4
  vostok::particle::burst_entry *pointer; // eax
  float v8; // xmm0_4
  unsigned int result; // eax
  float v10; // [esp+18h] [ebp+Ch]
  float v11; // [esp+18h] [ebp+Ch]

  v4 = 0;
  this->m_num_particles_to_create = 0;
  if ( !allow_to_create_new )
    return 0;
  if ( this->m_delayed )
    return 0;
  if ( this->m_num_live_particles >= this->m_max_num_particles )
    return 0;
  m_emitter = this->m_emitter;
  if ( m_emitter->m_num_loops )
  {
    if ( this->m_waiting_for_end )
      return 0;
  }
  if ( m_emitter->m_num_burst_entries )
  {
    m_emitter_time = this->m_emitter_time;
    pointer = m_emitter->m_burst_entries.pointer;
    while ( pointer->time < m_emitter_time || (float)(m_emitter_time + time_delta) <= pointer->time )
    {
      ++v4;
      ++pointer;
      if ( v4 >= this->m_emitter->m_num_burst_entries )
        goto LABEL_16;
    }
    v10 = vostok::particle::random_float(
            (float)(pointer->count - pointer->count_variance),
            (float)(pointer->count + pointer->count_variance));
    if ( v10 <= 0.0 )
      v8 = 0.0;
    else
      v8 = v10;
    this->m_num_particles_to_create = (unsigned __int64)v8;
  }
LABEL_16:
  v11 = this->m_current_create_rate * time_delta + this->m_time_to_create_new_one;
  result = vostok::math::floor(v11);
  this->m_num_particles_to_create += result;
  this->m_time_to_create_new_one = v11 - (double)result;
  return result;
}
