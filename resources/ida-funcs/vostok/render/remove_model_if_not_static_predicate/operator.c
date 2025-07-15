BOOL __usercall vostok::render::remove_model_if_not_static_predicate::operator()@<eax>(
        vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::remove_model_if_not_static_predicate *this)
{
  vostok::render::render_surface *m_render_surface; // ecx
  vostok::render::enum_vertex_input_type m_vertex_input_type; // eax
  bool v4; // dl
  vostok::render::material_effects_instance *m_object; // eax
  vostok::render::material_effects *p_m_material_effects; // eax

  m_render_surface = in_model->m_render_surface;
  m_vertex_input_type = in_model->m_render_surface->m_vertex_input_type;
  v4 = m_vertex_input_type == wires_vertex_input_type
    || m_vertex_input_type == static_mesh_vertex_input_type
    || m_vertex_input_type == static_mesh_vertex_colored_input_type;
  m_object = m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
  else
    p_m_material_effects = &m_object->m_material_effects;
  return p_m_material_effects->has_translucency || !v4;
}
