void __thiscall stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float>>::reserve(
        stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float> > *this,
        unsigned int __n,
        unsigned int __na)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // edi
  int v6; // ebp
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ebp
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v12; // [esp+0h] [ebp-10h]
  unsigned int __old_size; // [esp+14h] [ebp+4h]

  v4 = *(unsigned __int8 **)__n;
  if ( (*(_DWORD *)(__n + 8) - *(_DWORD *)__n) >> 2 < __na )
  {
    if ( __na > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v5 = *(unsigned __int8 **)(__n + 4);
    v6 = (v5 - v4) >> 2;
    __old_size = v6;
    v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                              __na,
                              v12);
    if ( v4 )
    {
      v8 = v7;
      if ( v5 != v4 )
        memcpy(v7, v4, v5 - v4);
      v9 = *(unsigned __int8 **)__n;
      v10 = v8;
      if ( *(_DWORD *)__n )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
      }
      v6 = __old_size;
    }
    else
    {
      v10 = v7;
    }
    *(_DWORD *)__n = v10;
    *(_DWORD *)(__n + 4) = &v10[4 * v6];
    *(_DWORD *)(__n + 8) = &v10[4 * __na];
  }
}
