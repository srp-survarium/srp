unsigned __int8 *__userpurge stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 60;
  __size = v3;
  if ( __n > (unsigned int)&vostok::memory::s_CRT_arena[-v3 + 60379772] )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = (unsigned __int8 *)(v3 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[60379772] || (unsigned int)result < v3 )
    return &vostok::memory::s_CRT_arena[60379772];
  return result;
}
