void __usercall stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(
        vostok::render::light_data *__last@<eax>,
        vostok::render::light_data *__first,
        const vostok::render::light_data *__val)
{
  vostok::render::light_data *v3; // ebp
  int i; // ebx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v6; // eax
  vostok::render::light *v7; // edi
  vostok::render::grass_render_model *v9; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    m_object = __val->light.m_object;
    v6 = 0;
    if ( __val->light.m_object )
    {
      v6 = __val->light.m_object;
      ++m_object->m_reference_count;
    }
    v7 = v3->light.m_object;
    v3->light.m_object = v6;
    if ( v7 )
    {
      if ( v7->m_reference_count-- == 1 )
      {
        v9 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(m_object);
        BYTE2(v9->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v7);
      }
    }
    v3->id = __val->id;
    --i;
  }
}
