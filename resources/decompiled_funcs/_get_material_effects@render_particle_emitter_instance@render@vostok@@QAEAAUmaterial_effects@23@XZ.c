vostok::render::material_effects *__thiscall vostok::render::render_particle_emitter_instance::get_material_effects(
        vostok::render::render_particle_emitter_instance *this)
{
  vostok::render::material_effects_instance *m_object; // eax
  vostok::render::material_effects *result; // eax

  m_object = this->m_material_effects_ptr.m_object;
  if ( m_object )
    return &m_object->m_material_effects;
  switch ( this->m_vertex_type )
  {
    case particle_vertex_type_billboard:
      result = (vostok::render::material_effects *)unk_4BB07E8;
      break;
    case particle_vertex_type_billboard_subuv:
      result = (vostok::render::material_effects *)unk_4BB07EC;
      break;
    case particle_vertex_type_trail:
    case particle_vertex_type_beam:
      result = (vostok::render::material_effects *)unk_4BB07F0;
      break;
    default:
      result = s_nomaterial_material_effects[0];
      break;
  }
  return result;
}
