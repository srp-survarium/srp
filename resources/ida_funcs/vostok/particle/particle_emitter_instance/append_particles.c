void __thiscall vostok::particle::particle_emitter_instance::append_particles(
        vostok::particle::particle_emitter_instance *this,
        float time_delta)
{
  double v2; // st7
  vostok::math::float3 *v3; // eax
  vostok::particle::enum_particle_event event_type; // [esp+40h] [ebp-1Ch] BYREF
  vostok::math::float3 v6; // [esp+44h] [ebp-18h] BYREF
  vostok::particle::particle_action *modifier; // [esp+50h] [ebp-Ch]
  vostok::particle::base_particle *new_particle; // [esp+54h] [ebp-8h]
  unsigned int i; // [esp+58h] [ebp-4h]

  for ( i = 0; i < this->m_num_particles_to_create && this->m_num_live_particles + 1 <= this->m_max_num_particles; ++i )
  {
    new_particle = vostok::particle::particle_world::allocate_particle(this->m_particle_world);
    if ( new_particle )
    {
      vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        &this->m_particle_list,
        new_particle,
        0);
      new_particle->m_seed = (unsigned int)new_particle + vostok::timing::get_QPC().LowPart;
      v2 = vostok::particle::curve_line_ranged_base::evaluate(
             &this->m_emitter->m_particle_lifetime_curve.m_line,
             this->m_emitter_time,
             1.0,
             this->m_emitter->m_particle_lifetime_curve.m_evaluate_type,
             range_time_type,
             (boost::_bi::list1<vostok::network_core::packet_reader &> *)new_particle->m_seed);
      new_particle->duration = v2;
      for ( modifier = this->m_emitter->m_actions.pointer; modifier; modifier = modifier->m_next.pointer )
      {
        if ( modifier->m_visibility )
          ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_emitter_instance *, vostok::particle::base_particle *, _DWORD))modifier->init)(
            modifier,
            this,
            new_particle,
            LODWORD(time_delta));
      }
      if ( this->m_emitter->m_world_space )
      {
        v3 = vostok::math::float4x4::transform_position(&new_particle->position, &v6, &this->m_transform);
        new_particle->position = *v3;
      }
      event_type = event_on_birth;
      vostok::particle::particle_emitter_instance::process_event(this, &event_type, &new_particle->position);
      ++this->m_num_live_particles;
      ++this->m_num_created_particles;
    }
  }
}
