void __userpurge vostok::render::render_particle_emitter_instance::render_beams(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        vostok::render::render_particle_emitter_instance *a2@<esi>,
        const vostok::math::float3 *view_location,
        unsigned int num_particles)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  vostok::render::render_particle_emitter_instance *v6; // ebp
  vostok::particle::base_particle *m_first; // eax
  vostok::render::render_particle_emitter_instance *i; // ecx

  v4 = 0;
  v5 = num_particles / a2->m_beamtrail_parameters->num_beams;
  v6 = 0;
  do
  {
    m_first = a2->m_particle_list->m_first;
    for ( i = 0; m_first; i = (vostok::render::render_particle_emitter_instance *)((char *)i + 1) )
    {
      if ( i == v6 )
        break;
      m_first = m_first->next;
    }
    vostok::render::render_particle_emitter_instance::render_trails(i, a2, view_location, m_first, v5);
    ++v4;
    v6 = (vostok::render::render_particle_emitter_instance *)((char *)v6 + v5);
  }
  while ( v4 < a2->m_beamtrail_parameters->num_beams );
}
