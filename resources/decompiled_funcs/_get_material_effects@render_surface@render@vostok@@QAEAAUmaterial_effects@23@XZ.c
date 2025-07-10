vostok::render::material_effects *__thiscall vostok::render::render_surface::get_material_effects(
        vostok::render::render_surface *this)
{
  vostok::render::material_effects_instance *m_object; // eax

  m_object = this->m_materail_effects_instance.m_object;
  if ( !m_object || s_use_one_material_value )
    return s_nomaterial_material_effects[this->m_vertex_input_type];
  else
    return &m_object->m_material_effects;
}
