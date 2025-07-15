unsigned int __userpurge vostok::particle::particle_emitter_instance::calc_num_max_particles@<eax>(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        float a2@<xmm0>,
        float time_delta)
{
  unsigned int m_max_num_particles; // eax
  vostok::particle::particle_emitter *m_emitter; // edx
  unsigned int m_num_burst_entries; // ebx
  int *p_count; // eax
  float curve_value_max; // xmm2_4
  float v9; // xmm0_4
  unsigned int result; // eax
  int v11; // [esp+18h] [ebp-4h]

  vostok::math::curve_line_ranged_base::evaluate(
    &this->m_emitter->m_particle_spawn_rate_curve.m_line,
    (unsigned int)this,
    this->m_emitter_time,
    1.0,
    this->m_emitter->m_particle_spawn_rate_curve.m_evaluate_type,
    range_time_type);
  m_max_num_particles = this->m_max_num_particles;
  m_emitter = this->m_emitter;
  v11 = 0;
  this->m_create_rate = a2;
  this->m_current_calc_num_max_particles = m_max_num_particles;
  if ( m_emitter->m_num_burst_entries )
  {
    m_num_burst_entries = m_emitter->m_num_burst_entries;
    p_count = &m_emitter->m_burst_entries.pointer->count;
    do
    {
      v11 += (*p_count >> 31) ^ ((*p_count >> 31) + *p_count);
      p_count += 3;
      --m_num_burst_entries;
    }
    while ( m_num_burst_entries );
  }
  if ( m_emitter->m_particle_spawn_rate_curve.m_line.m_upper.curve_value_max <= m_emitter->m_particle_spawn_rate_curve.m_line.m_lower.curve_value_max )
    curve_value_max = m_emitter->m_particle_spawn_rate_curve.m_line.m_lower.curve_value_max;
  else
    curve_value_max = m_emitter->m_particle_spawn_rate_curve.m_line.m_upper.curve_value_max;
  v9 = m_emitter->m_particle_lifetime_curve.m_line.m_upper.curve_value_max;
  if ( v9 <= m_emitter->m_particle_lifetime_curve.m_line.m_lower.curve_value_max )
    v9 = m_emitter->m_particle_lifetime_curve.m_line.m_lower.curve_value_max;
  result = vostok::math::floor(v9 * curve_value_max) + v11 + 2;
  this->m_current_calc_num_max_particles = result;
  return result;
}
