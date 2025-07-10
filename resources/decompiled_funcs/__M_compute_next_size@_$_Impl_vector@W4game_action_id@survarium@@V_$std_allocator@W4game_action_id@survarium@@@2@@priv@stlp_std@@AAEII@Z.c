unsigned int __usercall stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size@<eax>(
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // ecx
  unsigned int *p_size; // eax
  unsigned int result; // eax
  unsigned int __size; // [esp+0h] [ebp-8h] BYREF
  unsigned int __na; // [esp+4h] [ebp-4h] BYREF

  v2 = (a2[1] - *a2) >> 2;
  __na = 1;
  __size = v2;
  if ( v2 == 0x3FFFFFFF )
    stlp_std::__stl_throw_length_error("vector");
  p_size = &__size;
  if ( v2 <= 1 )
    p_size = &__na;
  result = v2 + *p_size;
  if ( result > 0x3FFFFFFF || result < v2 )
    return 0x3FFFFFFF;
  return result;
}
