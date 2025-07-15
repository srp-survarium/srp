unsigned int __thiscall vostok::particle::particle_emitter_instance::calc_num_new_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta,
        bool allow_to_create_new)
{
  unsigned int result; // eax
  float v4; // [esp+24h] [ebp-30h]
  vostok::particle::burst_entry *one_burst; // [esp+44h] [ebp-10h]
  unsigned int i; // [esp+48h] [ebp-Ch]
  float f_num_new; // [esp+4Ch] [ebp-8h]

  this->m_num_particles_to_create = 0;
  if ( !allow_to_create_new || this->m_delayed || this->m_num_live_particles >= this->m_max_num_particles )
    return 0;
  if ( this->m_emitter->m_num_loops && this->m_waiting_for_end )
    return 0;
  for ( i = 0; i < this->m_emitter->m_num_burst_entries; ++i )
  {
    one_burst = &this->m_emitter->m_burst_entries.pointer[i];
    if ( one_burst->time >= this->m_emitter_time && (float)(this->m_emitter_time + time_delta) > one_burst->time )
    {
      v4 = vostok::particle::random_float(
             (float)(one_burst->count - one_burst->count_variance),
             (float)(one_burst->count_variance + one_burst->count));
      vostok::math::max();
      this->m_num_particles_to_create = (__int64)v4;
      break;
    }
  }
  f_num_new = (float)(time_delta * this->m_current_create_rate) + this->m_time_to_create_new_one;
  result = vostok::math::floor(f_num_new);
  this->m_time_to_create_new_one = f_num_new - (double)result;
  this->m_num_particles_to_create += result;
  return result;
}
