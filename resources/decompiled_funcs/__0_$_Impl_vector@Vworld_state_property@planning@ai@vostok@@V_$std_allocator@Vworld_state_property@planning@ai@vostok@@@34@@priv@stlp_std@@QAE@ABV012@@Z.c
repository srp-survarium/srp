void __thiscall stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        const stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *__x)
{
  vostok::ai::std_allocator<vostok::ai::planning::world_state_property> __a; // [esp+2Bh] [ebp-1h] BYREF

  stlp_std::priv::_Vector_base<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Vector_base<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  this->_M_finish = (vostok::ai::planning::world_state_property *)stlp_std::priv::__ucopy_trivial(
                                                                    (unsigned __int8 *)__x->_M_start,
                                                                    (unsigned __int8 *)__x->_M_finish,
                                                                    (unsigned __int8 *)this->_M_start);
}
