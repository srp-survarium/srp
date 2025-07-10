unsigned __int8 *__usercall stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned __int8 *result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) / 56;
  __na = 1;
  __size = v2;
  if ( &vostok::memory::s_CRT_arena[65492828] == (unsigned __int8 *)v2 )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = (unsigned __int8 *)(v2 + *p_size);
  if ( result > &vostok::memory::s_CRT_arena[65492828] || (unsigned int)result < v2 )
    return &vostok::memory::s_CRT_arena[65492828];
  return result;
}
