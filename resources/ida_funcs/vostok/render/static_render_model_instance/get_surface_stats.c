void __thiscall vostok::render::static_render_model_instance::get_surface_stats(
        vostok::render::static_render_model_instance *this,
        unsigned int surface_id,
        vostok::render::surface_stats *stats)
{
  vostok::render::render_surface_instance *m_surface_instances; // eax
  vostok::render::render_surface *m_render_surface; // ecx
  vostok::render::render_surface_instance *v5; // eax
  vostok::render::material_effects_instance *m_object; // eax
  vostok::fixed_string<260> *p_material; // ecx
  const char *m_begin; // edx
  char *v9; // eax
  char *v10; // eax

  m_surface_instances = this->m_surface_instances;
  m_render_surface = m_surface_instances[surface_id].m_render_surface;
  v5 = &m_surface_instances[surface_id];
  stats->vcount = m_render_surface->m_render_geometry.vertex_count;
  stats->tricount = v5->m_render_surface->m_render_geometry.primitive_count;
  m_object = v5->m_render_surface->m_materail_effects_instance.m_object;
  p_material = &stats->material;
  if ( m_object )
  {
    m_begin = m_object->m_material_name.m_string.m_begin;
    v9 = p_material->m_begin;
    if ( p_material->m_begin != m_begin )
    {
      stats->material.m_end = v9;
      *v9 = 0;
      vostok::buffer_string::operator+=(p_material, m_begin);
    }
  }
  else
  {
    v10 = p_material->m_begin;
    if ( p_material->m_begin != "_not_assigned" )
    {
      stats->material.m_end = v10;
      *v10 = 0;
      vostok::buffer_string::operator+=(p_material, "_not_assigned");
    }
  }
}
