void __thiscall stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert(
        stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *this,
        survarium::zone_group::zone_wrapper *__pos,
        unsigned int __n,
        const survarium::zone_group::zone_wrapper *__x)
{
  stlp_std::__true_type v4; // [esp+6h] [ebp-2h] BYREF
  stlp_std::__false_type __formal; // [esp+7h] [ebp-1h] BYREF

  if ( __n )
  {
    if ( this->_M_end_of_storage._M_data - this->_M_finish < __n )
    {
      v4 = 0;
      stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_insert_overflow(
        this,
        __pos,
        __x,
        &v4,
        __n,
        0);
    }
    else
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert_aux(
        this,
        __pos,
        __n,
        __x,
        &__formal);
    }
  }
}
