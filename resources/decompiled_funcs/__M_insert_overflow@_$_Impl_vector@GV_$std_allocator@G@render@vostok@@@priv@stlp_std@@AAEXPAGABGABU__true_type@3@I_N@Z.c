void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this@<ecx>,
        int a2@<edi>,
        unsigned __int16 *__pos,
        const unsigned __int16 *__x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // edx
  char *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short> > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  unsigned __int16 *__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_compute_next_size(
           this,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short>>::allocate(
                            v19,
                            __xa);
  v10 = (char *)__pos - *(_DWORD *)a2;
  __new_start = (unsigned __int16 *)v9;
  if ( __pos == *(unsigned __int16 **)a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *(unsigned __int8 **)a2, (unsigned int)v10);
    v9 = (unsigned __int8 *)__new_start;
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = __formal; i; v12 += 2 )
  {
    *(_WORD *)v12 = *__x;
    --i;
  }
  v14 = v12;
  if ( !__fill_len )
  {
    v15 = *(_DWORD *)(a2 + 4) - (_DWORD)__pos;
    if ( v15 )
    {
      memmove(v12, (unsigned __int8 *)__pos, v15);
      v9 = (unsigned __int8 *)__new_start;
      v14 = (unsigned __int8 *)(v15 + v16);
    }
  }
  v17 = *(unsigned __int8 **)a2;
  if ( *(_DWORD *)a2 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v17);
    v9 = (unsigned __int8 *)__new_start;
  }
  *(_DWORD *)(a2 + 4) = v14;
  *(_DWORD *)a2 = v9;
  *(_DWORD *)(a2 + 8) = &v9[2 * __xa];
}
