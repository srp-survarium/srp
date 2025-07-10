vostok::render::light_data *__cdecl stlp_std::priv::__copy_backward<vostok::render::light_data *,vostok::render::light_data *,int>(
        vostok::render::light_data *__first,
        vostok::render::light_data *__last,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *v3; // edx
  int i; // ebx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v7; // eax
  vostok::render::light *v8; // edi
  vostok::render::grass_render_model *v10; // esi
  vostok::render::light_data *__lasta; // [esp+18h] [ebp+8h]

  v3 = __last;
  for ( i = __last - __first; i > 0; __result->id = v3->id )
  {
    m_object = v3[-1].light.m_object;
    --v3;
    --__result;
    v7 = 0;
    __lasta = v3;
    if ( m_object )
    {
      v7 = m_object;
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
        v3 = __lasta;
      }
    }
    --i;
  }
  return __result;
}
