void __thiscall vostok::render::material::finalize_nomaterial_material(vostok::render::material_effects *this)
{
  unsigned int i; // edi
  vostok::render::material_effects *v2; // esi
  vostok::render::grass_render_model *m_object; // ebp
  char *v4; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  for ( i = 0; i < 15; ++i )
  {
    v2 = s_nomaterial_material_effects[i];
    m_object = vostok::render::g_allocator.m_object;
    if ( v2 )
    {
      vostok::render::material_effects::~material_effects(this, (int)s_nomaterial_material_effects[i]);
      v4 = (char *)v2;
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
      s_nomaterial_material_effects[i] = 0;
    }
    s_nomaterial_material_effects[i] = 0;
  }
}
