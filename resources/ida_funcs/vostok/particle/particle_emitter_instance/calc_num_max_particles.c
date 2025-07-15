unsigned int __thiscall vostok::particle::particle_emitter_instance::calc_num_max_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta)
{
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  float value_4; // [esp+10h] [ebp-4Ch]
  unsigned int i; // [esp+54h] [ebp-8h]
  unsigned int num_max_particles_by_burst_list; // [esp+58h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(v2);
  this->m_create_rate = vostok::particle::curve_line_ranged_base::evaluate(
                          &this->m_emitter->m_particle_spawn_rate_curve.m_line,
                          this->m_emitter_time,
                          1.0,
                          this->m_emitter->m_particle_spawn_rate_curve.m_evaluate_type,
                          range_time_type,
                          (boost::_bi::list1<vostok::network_core::packet_reader &> *)this);
  num_max_particles_by_burst_list = 0;
  for ( i = 0; i < this->m_emitter->m_num_burst_entries; ++i )
    num_max_particles_by_burst_list += vostok::math::abs(this->m_emitter->m_burst_entries.pointer[i].count);
  value_4 = vostok::particle::particle_emitter_instance::get_max_particle_lifetime(this) * this->m_create_rate;
  this->m_current_calc_num_max_particles = num_max_particles_by_burst_list + vostok::math::floor(value_4) + 2;
  return this->m_current_calc_num_max_particles;
}
