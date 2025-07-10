bool __usercall vostok::render::remove_model_if_not_forward_predicate::operator()@<al>(
        const vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::remove_model_if_not_forward_predicate *this)
{
  vostok::render::render_surface *m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx

  m_render_surface = in_model->m_render_surface;
  m_object = m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    return s_nomaterial_material_effects[m_render_surface->m_vertex_input_type]->m_effects[17].m_object == 0;
  else
    return m_object->m_material_effects.m_effects[17].m_object == 0;
}
