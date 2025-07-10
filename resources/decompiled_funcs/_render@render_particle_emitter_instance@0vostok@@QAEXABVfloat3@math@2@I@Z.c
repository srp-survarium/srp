void __fastcall vostok::render::render_particle_emitter_instance::render(
        vostok::render::render_particle_emitter_instance *num_particles,
        const vostok::math::float3 *view_location,
        vostok::render::render_particle_emitter_instance *this)
{
  switch ( this->m_vertex_type )
  {
    case particle_vertex_type_billboard:
      vostok::render::render_particle_emitter_instance::render_sprites(num_particles, this);
      break;
    case particle_vertex_type_billboard_subuv:
      vostok::render::render_particle_emitter_instance::render_subuv_sprites(num_particles, this);
      break;
    case particle_vertex_type_trail:
      vostok::render::render_particle_emitter_instance::render_trails(
        (vostok::render::render_particle_emitter_instance *)this->m_particle_list->m_first,
        this,
        view_location,
        this->m_particle_list->m_first,
        (unsigned int)num_particles);
      break;
    case particle_vertex_type_beam:
      vostok::render::render_particle_emitter_instance::render_beams(
        num_particles,
        this,
        view_location,
        (unsigned int)num_particles);
      break;
    default:
      return;
  }
}
