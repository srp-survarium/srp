vostok::render::light_data *__usercall stlp_std::priv::__copy<vostok::render::light_data *,vostok::render::light_data *,int>@<eax>(
        vostok::render::light_data *__last@<edx>,
        vostok::render::light_data *__first,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *v3; // ebx
  int v5; // edx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v7; // eax
  vostok::render::light *v8; // edi
  vostok::render::grass_render_model *v10; // esi
  int __n; // [esp+1Ch] [ebp+8h]

  v3 = __first;
  v5 = __last - __first;
  for ( __n = v5; v5 > 0; __n = v5 )
  {
    m_object = v3->light.m_object;
    v7 = 0;
    if ( v3->light.m_object )
    {
      v7 = v3->light.m_object;
      ++m_object->m_reference_count;
    }
    v8 = __result->light.m_object;
    __result->light.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 )
      {
        v10 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(m_object);
        BYTE2(v10->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v10->m_reconstruction_info_actuality_tick), v8);
        v5 = __n;
      }
    }
    --v5;
    __result->id = v3->id;
    ++v3;
    ++__result;
  }
  return __result;
}
