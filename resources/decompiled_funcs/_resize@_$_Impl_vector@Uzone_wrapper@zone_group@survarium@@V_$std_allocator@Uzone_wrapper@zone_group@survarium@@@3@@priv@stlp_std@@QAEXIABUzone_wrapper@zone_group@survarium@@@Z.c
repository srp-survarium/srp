void __thiscall stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::resize(
        stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *this,
        unsigned int __new_size,
        const survarium::zone_group::zone_wrapper *__x)
{
  stlp_std::__false_type __formal; // [esp+2Bh] [ebp-9h] BYREF
  survarium::zone_group::zone_wrapper *M_start; // [esp+2Ch] [ebp-8h]
  vostok::ai::planning::world_state_property *__last; // [esp+30h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = (vostok::ai::planning::world_state_property *)this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != (survarium::zone_group::zone_wrapper *)__last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        (stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)this,
        (vostok::ai::planning::world_state_property *)&M_start[__new_size],
        __last,
        &__formal);
    }
  }
}
