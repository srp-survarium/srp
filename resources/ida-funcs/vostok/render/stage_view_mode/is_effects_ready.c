bool __thiscall vostok::render::stage_view_mode::is_effects_ready(vostok::render::stage_view_mode *this)
{
  unsigned int v1; // esi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *m_editor_texture_density_effect; // eax

  v1 = 0;
  m_editor_texture_density_effect = this->m_editor_texture_density_effect;
  do
  {
    if ( v1 != 12
      && (!m_editor_texture_density_effect[-15].m_object
       || !m_editor_texture_density_effect->m_object
       || !m_editor_texture_density_effect[15].m_object
       || !m_editor_texture_density_effect[30].m_object
       || !m_editor_texture_density_effect[45].m_object
       || !m_editor_texture_density_effect[61].m_object) )
    {
      return 0;
    }
    ++v1;
    ++m_editor_texture_density_effect;
  }
  while ( v1 < 0xF );
  return this->m_editor_apply_wireframe_shader.m_object
      && this->m_editor_show_overdraw_shader.m_object
      && this->m_editor_vertex_alpha_effect.m_object
      && this->m_editor_show_geometry_effect.m_object;
}
