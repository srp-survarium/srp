vostok::render::material_effects *__thiscall vostok::render::speedtree_tree_component::get_material_effects(
        vostok::render::speedtree_tree_component *this)
{
  vostok::render::material_effects_instance *m_object; // eax

  m_object = this->m_materail_effects_instance.m_object;
  if ( m_object )
    return &m_object->m_material_effects;
  else
    return s_nomaterial_material_effects[this->get_vertex_input_type(this)];
}
