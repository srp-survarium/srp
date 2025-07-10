void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::clear(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this)
{
  stlp_std::__false_type __formal; // [esp+3Bh] [ebp-9h] BYREF
  vostok::ai::planning::pddl_world_state_property_impl *__first; // [esp+3Ch] [ebp-8h]
  vostok::ai::planning::pddl_world_state_property_impl *__last; // [esp+40h] [ebp-4h]

  __last = this->_M_finish;
  __first = this->_M_start;
  if ( __first != __last )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_erase(
      this,
      __first,
      __last,
      &__formal);
  }
}
