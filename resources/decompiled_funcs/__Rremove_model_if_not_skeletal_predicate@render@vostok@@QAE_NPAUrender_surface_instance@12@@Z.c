BOOL __usercall vostok::render::remove_model_if_not_skeletal_predicate::operator()@<eax>(
        vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::remove_model_if_not_skeletal_predicate *this)
{
  vostok::render::render_surface *m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // ecx
  vostok::render::enum_vertex_input_type m_vertex_input_type; // eax
  BOOL result; // eax

  m_render_surface = in_model->m_render_surface;
  m_object = m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
  else
    p_m_material_effects = &m_object->m_material_effects;
  result = 1;
  if ( !p_m_material_effects->has_translucency )
  {
    m_vertex_input_type = m_render_surface->m_vertex_input_type;
    if ( m_vertex_input_type == skeletal_4_bones_mesh_vertex_input_type
      || m_vertex_input_type == skeletal_3_bones_mesh_vertex_input_type
      || m_vertex_input_type == skeletal_2_bones_mesh_vertex_input_type
      || m_vertex_input_type == skeletal_1_bones_mesh_vertex_input_type )
    {
      return 0;
    }
  }
  return result;
}
