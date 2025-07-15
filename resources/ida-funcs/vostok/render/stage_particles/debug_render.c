void __thiscall vostok::render::stage_particles::debug_render(vostok::render::stage_particles *this)
{
  vostok::render::system_renderer *v1; // ecx
  vostok::particle::render_particle_emitter_instance **m_begin; // esi
  vostok::particle::render_particle_emitter_instance **m_end; // edi
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> v4; // [esp+0h] [ebp-1010h] BYREF
  int v5; // [esp+100Ch] [ebp-4h] BYREF

  if ( draw )
  {
    vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>(
      &v4,
      (const vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *)&this->m_context->m_scene_view.m_object[202].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
    m_begin = v4.m_begin;
    m_end = v4.m_end;
    if ( v4.m_begin != v4.m_end )
    {
      v5 = -16711681;
      do
        vostok::render::system_renderer::draw_aabb(
          v1,
          vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          (const vostok::math::color *)&(*m_begin++)[40],
          &v5);
      while ( m_begin != m_end );
    }
  }
}
