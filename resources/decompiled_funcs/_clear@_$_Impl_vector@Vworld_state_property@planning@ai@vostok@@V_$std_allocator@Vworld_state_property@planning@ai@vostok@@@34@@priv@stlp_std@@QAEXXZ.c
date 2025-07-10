void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this)
{
  stlp_std::__false_type __formal; // [esp+1Fh] [ebp-9h] BYREF
  vostok::ai::planning::world_state_property *__first; // [esp+20h] [ebp-8h]
  vostok::ai::planning::world_state_property *__last; // [esp+24h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}
