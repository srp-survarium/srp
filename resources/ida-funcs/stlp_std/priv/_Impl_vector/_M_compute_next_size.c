unsigned int __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_compute_next_size(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this,
        unsigned int __n)
{
  unsigned int v2; // edx
  unsigned int *p_n; // eax
  unsigned int result; // eax
  unsigned int v5; // [esp+0h] [ebp-4h] BYREF

  v2 = this->_M_finish - this->_M_start;
  v5 = v2;
  if ( __n > 0x3FFFFFFF - v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_n = &v5;
  if ( __n >= v2 )
    p_n = &__n;
  result = v2 + *p_n;
  if ( result > 0x3FFFFFFF || result < v2 )
    return 0x3FFFFFFF;
  return result;
}


unsigned int __userpurge stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int __n)
{
  unsigned int v3; // ecx
  unsigned int *p_n; // eax
  unsigned int result; // eax
  unsigned int v6; // [esp+0h] [ebp-4h] BYREF

  v3 = (a2[1] - *a2) >> 4;
  v6 = v3;
  if ( __n > 0xFFFFFFF - v3 )
    stlp_std::__stl_throw_length_error("vector");
  p_n = &v6;
  if ( __n >= v3 )
    p_n = &__n;
  result = v3 + *p_n;
  if ( result > 0xFFFFFFF || result < v3 )
    return 0xFFFFFFF;
  return result;
}
