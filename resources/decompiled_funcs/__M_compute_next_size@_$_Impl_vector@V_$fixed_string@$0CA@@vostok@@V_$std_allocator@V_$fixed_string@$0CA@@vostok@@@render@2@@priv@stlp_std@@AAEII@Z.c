unsigned int __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-4h] BYREF

  __size = (unsigned int)this;
  v3 = (a2[1] - *a2) / 44;
  __size = v3;
  if ( __n > 97612893 - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( __n >= v3 )
    p_size = &__n;
  result = v3 + *p_size;
  if ( result > 0x5D1745D || result < v3 )
    return 97612893;
  return result;
}
