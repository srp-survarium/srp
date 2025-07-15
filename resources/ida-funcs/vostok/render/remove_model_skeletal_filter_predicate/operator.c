bool __userpurge vostok::render::remove_model_skeletal_filter_predicate::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::render_surface *a2@<ecx>,
        vostok::render::remove_model_skeletal_filter_predicate *this)
{
  vostok::render::render_surface *m_render_surface; // esi
  bool result; // al
  vostok::render::enum_vertex_input_type m_vertex_input_type; // esi

  m_render_surface = in_model->m_render_surface;
  if ( !vostok::render::render_surface::get_material_effects(a2, (int)m_render_surface)->m_effects[1].m_object )
    return 1;
  m_vertex_input_type = m_render_surface->m_vertex_input_type;
  result = m_vertex_input_type == skeletal_4_bones_mesh_vertex_input_type
        || m_vertex_input_type == skeletal_3_bones_mesh_vertex_input_type
        || m_vertex_input_type == skeletal_2_bones_mesh_vertex_input_type
        || m_vertex_input_type == skeletal_1_bones_mesh_vertex_input_type;
  if ( this->m_inverse_flag )
    return result == 0;
  return result;
}
