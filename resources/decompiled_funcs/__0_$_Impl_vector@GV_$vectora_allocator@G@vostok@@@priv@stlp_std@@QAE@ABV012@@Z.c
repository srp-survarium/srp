void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __x)
{
  const stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *v3; // ebx
  vostok::memory::base_allocator *v4; // eax
  int v5; // edi
  int *p_x; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // [esp+8h] [ebp-4h] BYREF

  v3 = (const stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *)__x;
  v4 = *(vostok::memory::base_allocator **)(__x + 8);
  v5 = (*(_DWORD *)(__x + 4) - *(_DWORD *)__x) >> 1;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = (unsigned __int8 *)v4;
  a2[3] = 0;
  v12 = v5;
  __x = 1;
  p_x = &__x;
  if ( v5 )
    p_x = &v12;
  v7 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            2 * *p_x);
  *a2 = v7;
  a2[1] = v7;
  a2[3] = &v7[2 * v5];
  M_finish = (unsigned __int8 *)v3->_M_finish;
  M_start = (unsigned __int8 *)v3->_M_start;
  if ( M_finish != M_start )
  {
    v10 = M_finish - M_start;
    memcpy(v7, M_start, v10);
    v7 = (unsigned __int8 *)(v10 + v11);
  }
  a2[1] = v7;
}
