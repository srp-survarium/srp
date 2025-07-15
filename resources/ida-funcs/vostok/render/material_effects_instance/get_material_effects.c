vostok::render::material_effects *__thiscall vostok::render::material_effects_instance::get_material_effects(
        vostok::render::material_effects_instance *this,
        vostok::render::enum_vertex_input_type vtype)
{
  unsigned int m_num_material_effects; // esi
  int v3; // eax
  vostok::render::material_effects *m_material_effects; // edi
  vostok::render::enum_vertex_input_type *i; // edx

  m_num_material_effects = this->m_num_material_effects;
  v3 = 0;
  if ( !m_num_material_effects )
    return this->m_material_effects;
  m_material_effects = this->m_material_effects;
  for ( i = &m_material_effects->m_vertex_input_type; *i != vtype; i += 38 )
  {
    if ( ++v3 >= m_num_material_effects )
      return this->m_material_effects;
  }
  return &m_material_effects[v3];
}
