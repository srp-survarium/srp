char __usercall vostok::render::stage_lights::has_models_for_shadow_pass@<al>(
        const vostok::buffer_vector<vostok::render::render_surface_instance *> *dynamic_visuals@<eax>,
        vostok::render::render_surface *a2@<ecx>)
{
  vostok::render::render_surface_instance **m_begin; // ebx
  int v3; // esi
  int m_render_surface; // edi
  vostok::render::material_effects *material_effects; // eax
  vostok::render::render_surface_instance **m_end; // [esp+Ch] [ebp-4h]

  m_begin = dynamic_visuals->m_begin;
  m_end = dynamic_visuals->m_end;
  if ( dynamic_visuals->m_begin == m_end )
    return 0;
  while ( 1 )
  {
    v3 = (int)*m_begin;
    m_render_surface = (int)(*m_begin)->m_render_surface;
    material_effects = vostok::render::render_surface::get_material_effects(a2, m_render_surface);
    if ( material_effects->is_cast_shadow
      && *(_DWORD *)(m_render_surface + 4)
      && material_effects->m_effects[1].m_object
      && !vostok::render::render_surface_instance::is_occluded((vostok::render::render_surface_instance *)a2, v3) )
    {
      break;
    }
    if ( ++m_begin == m_end )
      return 0;
  }
  return 1;
}
