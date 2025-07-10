void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  vostok::render::batched_vertex_source *v3; // esi
  int v4; // ebx
  vostok::render::batched_vertex_source *v5; // ebp
  vostok::render::batched_vertex_source *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *v8; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v9; // [esp+0h] [ebp-10h]
  int *v10; // [esp+4h] [ebp-Ch]
  vostok::render::batched_vertex_source *__last; // [esp+Ch] [ebp-4h]

  v3 = *(vostok::render::batched_vertex_source **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 36 < __n )
  {
    if ( __n > 0x71C71C7 )
      stlp_std::__stl_throw_length_error("vector");
    __last = *(vostok::render::batched_vertex_source **)(a2 + 4);
    v4 = __last - v3;
    v5 = stlp_std::priv::_STLP_alloc_proxy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::allocate(
           v8,
           __n);
    if ( v3 )
    {
      stlp_std::priv::__ucopy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source *,int>(
        v3,
        __last,
        v5,
        v9,
        v10);
      v6 = *(vostok::render::batched_vertex_source **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v6);
      }
    }
    *(_DWORD *)a2 = v5;
    *(_DWORD *)(a2 + 4) = &v5[v4];
    *(_DWORD *)(a2 + 8) = &v5[__n];
  }
}
