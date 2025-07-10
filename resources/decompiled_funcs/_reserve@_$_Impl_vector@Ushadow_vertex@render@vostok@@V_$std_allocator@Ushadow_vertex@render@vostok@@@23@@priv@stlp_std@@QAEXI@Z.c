void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex> > *this@<ecx>,
        vostok::render::shadow_vertex **a2@<edi>,
        unsigned int __n)
{
  vostok::render::shadow_vertex *v3; // eax
  int v5; // ebx
  vostok::render::shadow_vertex *v6; // esi
  vostok::render::shadow_vertex *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex> > *v9; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v10; // [esp+0h] [ebp-10h]
  int *v11; // [esp+4h] [ebp-Ch]
  vostok::render::shadow_vertex *__last; // [esp+Ch] [ebp-4h]
  vostok::render::shadow_vertex *__tmp; // [esp+14h] [ebp+4h]
  vostok::render::shadow_vertex *__tmpa; // [esp+14h] [ebp+4h]

  v3 = *a2;
  __tmp = *a2;
  if ( a2[2] - *a2 < __n )
  {
    if ( __n > 0x7FFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    __last = a2[1];
    v5 = __last - v3;
    if ( v3 )
    {
      v6 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::allocate(
             __n,
             v9);
      stlp_std::priv::__ucopy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex *,int>(
        __tmp,
        __last,
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
      v6 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::allocate(
             __n,
             v9);
    }
    *a2 = v6;
    a2[1] = &v6[v5];
    a2[2] = &v6[__n];
  }
}
