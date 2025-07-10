unsigned int __thiscall vostok::particle::particle_beam_emitter_instance::calc_num_new_particles(
        vostok::particle::particle_beam_emitter_instance *this,
        float time_delta,
        bool __formal)
{
  double v4; // st7
  vostok::particle::enum_particle_event event_type; // [esp+34h] [ebp-10h] BYREF
  vostok::particle::particle_action *modifier; // [esp+38h] [ebp-Ch]
  vostok::particle::base_particle *new_particle; // [esp+3Ch] [ebp-8h]
  unsigned int i; // [esp+40h] [ebp-4h]

  if ( this->m_beam_particles_allocated )
  {
    this->m_num_particles_to_create = 0;
    return this->m_num_particles_to_create;
  }
  else
  {
    this->m_beam_particles_allocated = 1;
    this->m_num_particles_to_create = this->m_max_num_particles;
    for ( i = 0; i < this->m_num_particles_to_create && this->m_num_live_particles + 1 <= this->m_max_num_particles; ++i )
    {
      new_particle = vostok::particle::particle_world::allocate_particle(this->m_particle_world);
      if ( new_particle )
      {
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
          &this->m_particle_list,
          new_particle,
          0);
        v4 = vostok::particle::curve_line_ranged_base::evaluate(
               &this->m_emitter->m_particle_lifetime_curve.m_line,
               this->m_emitter_time,
               1.0,
               this->m_emitter->m_particle_lifetime_curve.m_evaluate_type,
               linear_time_type,
               (boost::_bi::list1<vostok::network_core::packet_reader &> *)new_particle->m_seed);
        new_particle->duration = v4;
        for ( modifier = this->m_emitter->m_actions.pointer; modifier; modifier = modifier->m_next.pointer )
        {
          if ( modifier->m_visibility )
            ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_beam_emitter_instance *, vostok::particle::base_particle *, _DWORD))modifier->init)(
              modifier,
              this,
              new_particle,
              LODWORD(time_delta));
        }
        event_type = event_on_birth;
        vostok::particle::particle_emitter_instance::process_event(this, &event_type, &new_particle->position);
        ++this->m_num_live_particles;
        ++this->m_num_created_particles;
      }
    }
    this->m_num_particles_to_create = 0;
    vostok::particle::particle_beam_emitter_instance::set_particles_positions(this, 1);
    return this->m_num_live_particles;
  }
}
