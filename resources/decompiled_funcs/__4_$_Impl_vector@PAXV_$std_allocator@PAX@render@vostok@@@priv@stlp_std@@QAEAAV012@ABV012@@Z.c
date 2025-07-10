stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=@<eax>(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __x)
{
  const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v3; // ebp
  void **v4; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v5; // eax
  unsigned __int8 *v6; // esi
  unsigned int v7; // ebx
  void **v8; // ebp
  unsigned __int8 *v9; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v11; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // ebp
  int v16; // eax
  unsigned __int8 *M_finish; // eax
  unsigned __int8 *v18; // ecx
  void *const *v19; // [esp+0h] [ebp-Ch]

  v3 = (const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)__x;
  if ( __x == a2 )
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  v4 = *(void ***)(__x + 4);
  v5 = *(stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > **)__x;
  v6 = *(unsigned __int8 **)a2;
  v7 = ((int)v4 - *(_DWORD *)__x) >> 2;
  if ( v7 > (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) >> 2 )
  {
    __x = (*(_DWORD *)(__x + 4) - *(_DWORD *)__x) >> 2;
    v8 = stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_allocate_and_copy<void * const *>(
           v5,
           &__x,
           v19,
           v4);
    v9 = *(unsigned __int8 **)a2;
    if ( *(_DWORD *)a2 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
    }
    v11 = &v8[__x];
    *(_DWORD *)(a2 + 4) = &v8[v7];
    *(_DWORD *)a2 = v8;
    *(_DWORD *)(a2 + 8) = v11;
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  }
  v13 = (*(_DWORD *)(a2 + 4) - (int)v6) >> 2;
  if ( v13 < v7 )
  {
    if ( 4 * v13 )
      memmove(v6, (unsigned __int8 *)v5, 4 * v13);
    M_finish = (unsigned __int8 *)v3->_M_finish;
    v18 = (unsigned __int8 *)&v3->_M_start[(*(_DWORD *)(a2 + 4) - *(_DWORD *)a2) >> 2];
    if ( M_finish != v18 )
      memcpy(*(unsigned __int8 **)(a2 + 4), v18, M_finish - v18);
    *(_DWORD *)(a2 + 4) = *(_DWORD *)a2 + 4 * v7;
    return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
  }
  v14 = (char *)v4 - (char *)v5;
  v15 = v14;
  if ( v14 )
  {
    memmove(v6, (unsigned __int8 *)v5, v14);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>((void **)(v15 + v16), *(void ***)(a2 + 4));
  }
  else
  {
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>((void **)v6, *(void ***)(a2 + 4));
  }
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2 + 4 * v7;
  return (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)a2;
}
