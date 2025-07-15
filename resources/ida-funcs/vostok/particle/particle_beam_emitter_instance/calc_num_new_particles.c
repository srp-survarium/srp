unsigned int __userpurge vostok::particle::particle_beam_emitter_instance::calc_num_new_particles@<eax>(
        vostok::particle::particle_beam_emitter_instance *this@<ecx>,
        vostok::particle::base_particle *particle@<edi>,
        vostok::particle::particle_action *i@<esi>,
        float a4@<xmm0>,
        float time_delta,
        bool __formal)
{
  unsigned int m_max_num_particles; // eax
  vostok::particle::particle_emitter_instance *v9; // ecx
  unsigned int v10; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h] BYREF

  if ( this->m_beam_particles_allocated )
  {
    this->m_num_particles_to_create = 0;
    return 0;
  }
  else
  {
    v10 = 0;
    this->m_beam_particles_allocated = 1;
    m_max_num_particles = this->m_max_num_particles;
    this->m_num_particles_to_create = m_max_num_particles;
    if ( m_max_num_particles )
    {
      do
      {
        if ( this->m_num_live_particles + 1 > this->m_max_num_particles )
          break;
        particle = vostok::particle::particle_world::allocate_particle(
                     (vostok::particle::particle_world *)this,
                     &this->m_particle_world->vostok::particle::particle_emitter_instance::__vftable);
        if ( particle )
        {
          vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
            &this->m_particle_list,
            particle,
            (vostok::threading::mutex *)this);
          vostok::math::curve_line_ranged_base::evaluate(
            &this->m_emitter->m_particle_lifetime_curve.m_line,
            particle->m_seed,
            this->m_emitter_time,
            1.0,
            this->m_emitter->m_particle_lifetime_curve.m_evaluate_type,
            linear_time_type);
          particle->duration = a4;
          for ( i = this->m_emitter->m_actions.pointer; i; i = i->m_next.pointer )
          {
            if ( i->m_visibility )
              ((void (__thiscall *)(vostok::particle::particle_action *, vostok::particle::particle_beam_emitter_instance *, vostok::particle::base_particle *, _DWORD))i->init)(
                i,
                this,
                particle,
                LODWORD(time_delta));
          }
          particle = (vostok::particle::base_particle *)((char *)particle + 44);
          v11 = 3;
          vostok::particle::particle_emitter_instance::process_event(
            v9,
            (vostok::particle::particle_event *)this,
            (vostok::math::float4x4 *)&v11,
            (const vostok::math::float3 *)particle);
          ++this->m_num_live_particles;
          ++this->m_num_created_particles;
        }
        ++v10;
      }
      while ( v10 < this->m_num_particles_to_create );
    }
    this->m_num_particles_to_create = 0;
    vostok::particle::particle_beam_emitter_instance::set_particles_positions(
      this,
      particle,
      (unsigned int)i,
      (unsigned int)this,
      1);
    return this->m_num_live_particles;
  }
}
