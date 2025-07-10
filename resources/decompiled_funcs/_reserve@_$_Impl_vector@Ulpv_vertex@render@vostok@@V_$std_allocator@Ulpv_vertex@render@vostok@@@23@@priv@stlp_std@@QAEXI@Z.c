void __userpurge stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // ebp
  int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *v10; // [esp+0h] [ebp-10h]
  unsigned __int8 *v11; // [esp+Ch] [ebp-4h]

  v3 = *(unsigned __int8 **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 20 < __n )
  {
    if ( __n > 0xCCCCCCC )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(unsigned __int8 **)(a2 + 4);
    v5 = (v4 - v3) / 20;
    v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc>>::allocate(
                              __n,
                              v10);
    if ( v3 )
    {
      v11 = v6;
      if ( v4 != v3 )
      {
        memcpy(v6, v3, v4 - v3);
        v6 = v11;
      }
      v7 = v6;
      v8 = *(unsigned __int8 **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
    }
    else
    {
      v7 = v6;
    }
    *(_DWORD *)(a2 + 4) = &v7[20 * v5];
    *(_DWORD *)a2 = v7;
    *(_DWORD *)(a2 + 8) = &v7[20 * __n];
  }
}
