bool __userpurge vostok::render::remove_model_if_not_lod_predicate::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::remove_model_if_not_lod_predicate *this)
{
  vostok::render::render_surface *m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // ecx
  bool result; // al

  result = 1;
  if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
     || !in_model->m_occluded)
    && in_model->m_shader_lod_index == this->m_shader_lod_index )
  {
    m_render_surface = in_model->m_render_surface;
    m_object = m_render_surface->m_materail_effects_instance.m_object;
    if ( !m_object || s_use_one_material_value )
      p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
    else
      p_m_material_effects = &m_object->m_material_effects;
    if ( p_m_material_effects->m_effects[0].m_object && m_render_surface->m_render_geometry.geom.m_object )
      return 0;
  }
  return result;
}
