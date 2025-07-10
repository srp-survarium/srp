void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_M_clear_after_move(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this)
{
  vostok::ai::planning::pddl_world_state_property_impl *v1; // [esp-8h] [ebp-5Ch] BYREF
  void *current; // [esp-4h] [ebp-58h] BYREF
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *thisa; // [esp+0h] [ebp-54h]
  int v4; // [esp+4h] [ebp-50h]
  vostok::ai::planning::pddl_world_state_property_impl **v5; // [esp+3Ch] [ebp-18h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v6; // [esp+40h] [ebp-14h]
  void **v7; // [esp+44h] [ebp-10h]
  stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *> v8; // [esp+48h] [ebp-Ch]

  thisa = this;
  current = this;
  v7 = &current;
  v8.current = this->_M_start;
  current = v8.current;
  v1 = v8.current;
  v5 = &v1;
  v6.current = this->_M_finish;
  stlp_std::_Destroy_Range<stlp_std::reverse_iterator<vostok::ai::planning::pddl_world_state_property_impl *>>(v6, v8);
  v4 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, thisa->_M_start);
}
