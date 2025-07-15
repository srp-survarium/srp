vostok::render::material_effects *__thiscall vostok::render::material_effects_instance::get_material_effects_or_new(
        vostok::render::material_effects_instance *this,
        vostok::render::enum_vertex_input_type vtype)
{
  unsigned int m_num_material_effects; // edx
  unsigned int v3; // eax
  vostok::render::enum_vertex_input_type *p_m_vertex_input_type; // esi
  vostok::render::material_effects *result; // eax
  int v6; // eax
  vostok::render::material_effects *m_material_effects; // ecx
  vostok::render::enum_vertex_input_type *i; // esi

  m_num_material_effects = this->m_num_material_effects;
  v3 = 0;
  if ( !m_num_material_effects )
    goto LABEL_7;
  p_m_vertex_input_type = &this->m_material_effects->m_vertex_input_type;
  while ( *p_m_vertex_input_type != vtype )
  {
    ++v3;
    p_m_vertex_input_type += 38;
    if ( v3 >= m_num_material_effects )
      goto LABEL_7;
  }
  result = &this->m_material_effects[v3];
  if ( !result )
  {
LABEL_7:
    v6 = 0;
    if ( m_num_material_effects )
    {
      m_material_effects = this->m_material_effects;
      for ( i = &m_material_effects->m_vertex_input_type; *i != unknown_vertex_input_type; i += 38 )
      {
        if ( ++v6 >= m_num_material_effects )
          return 0;
      }
      return &m_material_effects[v6];
    }
    else
    {
      return 0;
    }
  }
  return result;
}
