unsigned int __usercall stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<unsigned char,vostok::vectora_allocator<unsigned char> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = a2[1] - *a2;
  __na = 1;
  __size = v2;
  if ( v2 == -1 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result < v2 )
    return -1;
  return result;
}
