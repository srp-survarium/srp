void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *__x)
{
  const vostok::ai::planning::pddl_world_state_property_impl *__val; // [esp+8h] [ebp-58h]
  int i; // [esp+30h] [ebp-30h]
  vostok::ai::planning::pddl_world_state_property_impl *__p; // [esp+34h] [ebp-2Ch]
  vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> __a; // [esp+5Fh] [ebp-1h] BYREF

  stlp_std::priv::_Vector_base<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Vector_base<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  __val = __x->_M_start;
  __p = this->_M_start;
  for ( i = __x->_M_finish - __x->_M_start; i > 0; --i )
    stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
      __p++,
      __val++);
  this->_M_finish = __p;
}
