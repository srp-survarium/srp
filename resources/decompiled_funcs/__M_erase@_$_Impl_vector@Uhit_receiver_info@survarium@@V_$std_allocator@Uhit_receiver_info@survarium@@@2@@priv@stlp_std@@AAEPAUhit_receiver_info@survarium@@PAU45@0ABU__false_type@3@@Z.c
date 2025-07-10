vostok::ai::planning::world_state_property *__thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *this,
        vostok::ai::planning::world_state_property *__first,
        vostok::ai::planning::world_state_property *__last,
        const stlp_std::__false_type *__formal)
{
  this->_M_finish = (vostok::ai::planning::world_state_property *)stlp_std::priv::__copy_trivial(
                                                                    (unsigned __int8 *)__last,
                                                                    (unsigned __int8 *)this->_M_finish,
                                                                    (unsigned __int8 *)__first);
  return __first;
}
