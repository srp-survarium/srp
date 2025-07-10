void __userpurge stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::culling::aab_rect,vostok::render::std_allocator<vostok::render::culling::aab_rect> > *this@<ecx>,
        vostok::render::culling::aab_rect **a2@<edi>,
        unsigned int __n)
{
  vostok::render::culling::aab_rect *v3; // eax
  int v5; // ebx
  vostok::render::culling::aab_rect *v6; // esi
  vostok::render::culling::aab_rect *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *v9; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v10; // [esp+0h] [ebp-10h]
  int *v11; // [esp+4h] [ebp-Ch]
  vostok::render::culling::aab_rect *__first; // [esp+Ch] [ebp-4h]
  vostok::render::culling::aab_rect *__tmp; // [esp+14h] [ebp+4h]
  vostok::render::culling::aab_rect *__tmpa; // [esp+14h] [ebp+4h]

  v3 = *a2;
  __first = *a2;
  if ( a2[2] - *a2 < __n )
  {
    if ( __n > 0xFFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    __tmp = a2[1];
    v5 = __tmp - v3;
    if ( v3 )
    {
      v6 = (vostok::render::culling::aab_rect *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate(
                                                  v9,
                                                  __n);
      stlp_std::priv::__ucopy<vostok::render::culling::aab_rect *,vostok::render::culling::aab_rect *,int>(
        __first,
        __tmp,
        v6,
        v10,
        v11);
      v7 = *a2;
      __tmpa = v6;
      if ( *a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v7);
        v6 = __tmpa;
      }
    }
    else
    {
      v6 = (vostok::render::culling::aab_rect *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate(
                                                  v9,
                                                  __n);
    }
    *a2 = v6;
    a2[1] = &v6[v5];
    a2[2] = &v6[__n];
  }
}
