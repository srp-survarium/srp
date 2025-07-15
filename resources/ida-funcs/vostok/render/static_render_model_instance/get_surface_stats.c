void __thiscall vostok::render::static_render_model_instance::get_surface_stats(
        vostok::render::static_render_model_instance *this,
        unsigned int surface_id,
        vostok::render::surface_stats *stats)
{
  vostok::render::render_surface_instance *v3; // eax
  vostok::render::render_surface *m_render_surface; // edx
  char *m_begin; // edx
  char *v6; // ecx

  v3 = &this->m_surface_instances[surface_id];
  stats->vcount = v3->m_render_surface->m_render_geometry.vertex_count;
  stats->tricount = v3->m_render_surface->m_render_geometry.primitive_count;
  m_render_surface = v3->m_render_surface;
  if ( m_render_surface->m_materail_effects_instance.m_object )
    m_begin = m_render_surface->m_materail_effects_instance.m_object->m_material_name.m_string.m_begin;
  else
    m_begin = "_not_assigned";
  v6 = stats->material.m_begin;
  if ( v6 != m_begin )
  {
    stats->material.m_end = v6;
    *v6 = 0;
    vostok::buffer_string::operator+=(&stats->material, m_begin);
  }
}
