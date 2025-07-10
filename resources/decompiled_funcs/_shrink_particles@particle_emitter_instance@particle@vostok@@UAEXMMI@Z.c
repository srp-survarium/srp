void __thiscall vostok::particle::particle_emitter_instance::shrink_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta,
        float limit_over_total,
        survarium::game_camera *num_need_particles)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize(num_need_particles);
  this->m_current_max_num_particles = (__int64)((double)this->m_current_calc_num_max_particles * limit_over_total);
  this->m_current_create_rate = this->m_create_rate * limit_over_total;
}
