void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_range_initialize<unsigned short const *>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        int a2@<edi>,
        int __first,
        unsigned __int8 *__last,
        const stlp_std::forward_iterator_tag *__formal)
{
  unsigned __int8 *v5; // ebp
  unsigned int v6; // ebx
  int v7; // esi
  int *p_first; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v5 = (unsigned __int8 *)__first;
  v6 = (unsigned int)&__last[-__first];
  v7 = (int)&__last[-__first] >> 1;
  v11 = v7;
  __first = 1;
  p_first = &__first;
  if ( v7 )
    p_first = &v11;
  v9 = (unsigned __int8 *)(*(int (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)(a2 + 8) + 20))(
                            *(_DWORD *)(a2 + 8),
                            0,
                            2 * *p_first);
  *(_DWORD *)a2 = v9;
  *(_DWORD *)(a2 + 12) = &v9[2 * v7];
  if ( __last != v5 )
  {
    memcpy(v9, v5, v6);
    v9 = (unsigned __int8 *)(v6 + v10);
  }
  *(_DWORD *)(a2 + 4) = v9;
}
