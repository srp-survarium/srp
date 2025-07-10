void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        unsigned __int8 *__pos,
        const unsigned __int16 *__x,
        unsigned int __formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int v7; // ebx
  unsigned int *p_formal; // eax
  unsigned __int8 *v9; // ebp
  char *v10; // edi
  int v11; // eax
  unsigned __int8 *v12; // eax
  unsigned int i; // ecx
  unsigned int v14; // edi
  unsigned __int8 *v15; // ebx
  int v16; // eax
  unsigned __int8 *v17; // edx
  unsigned int v18; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = __formal;
  size = stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)this,
           __formal);
  v18 = size;
  __formal = 1;
  p_formal = &__formal;
  if ( size )
    p_formal = &v18;
  v9 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, unsigned int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            2 * *p_formal);
  v10 = (char *)(__pos - *a2);
  if ( __pos == *a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *a2, __pos - *a2);
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = v7; i; v12 += 2 )
  {
    *(_WORD *)v12 = *__x;
    --i;
  }
  v14 = a2[1] - __pos;
  v15 = v12;
  if ( v14 )
  {
    memmove(v12, __pos, v14);
    v15 = (unsigned __int8 *)(v14 + v16);
  }
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v17 = &v9[2 * size];
  *a2 = v9;
  a2[1] = v15;
  a2[3] = v17;
}
