bool __userpurge vostok::render::sort_by_texture_predicate::operator()@<al>(
        vostok::render::sort_by_texture_predicate *this@<ecx>,
        const vostok::render::render_surface_instance *left@<eax>,
        const vostok::render::render_surface_instance *right)
{
  vostok::render::render_surface *m_render_surface; // eax
  vostok::render::material_effects_instance *m_object; // ecx
  vostok::render::material_effects *p_m_material_effects; // esi
  vostok::render::material_effects_instance *v7; // ecx
  vostok::render::material_effects *v8; // edx

  m_render_surface = left->m_render_surface;
  m_object = m_render_surface->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
  else
    p_m_material_effects = &m_object->m_material_effects;
  v7 = right->m_render_surface->m_materail_effects_instance.m_object;
  if ( !v7 || s_use_one_material_value )
    v8 = s_nomaterial_material_effects[right->m_render_surface->m_vertex_input_type];
  else
    v8 = &v7->m_material_effects;
  return vostok::render::res_texture_list::compare(
           p_m_material_effects->m_effects[this->m_stage_type].m_object->m_techniques._M_impl._M_start[this->m_tech_index].m_object->m_passes._M_impl._M_start->m_object->m_ps.m_object->m_textures.m_object,
           v8->m_effects[this->m_stage_type].m_object->m_techniques._M_impl._M_start[this->m_tech_index].m_object->m_passes._M_impl._M_start->m_object->m_ps.m_object->m_textures.m_object) < 0;
}
