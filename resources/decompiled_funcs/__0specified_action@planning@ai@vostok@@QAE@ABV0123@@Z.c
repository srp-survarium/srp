void __thiscall vostok::ai::planning::specified_action::specified_action(
        vostok::ai::planning::specified_action *this,
        const vostok::ai::planning::specified_action *__that)
{
  unsigned int *end; // [esp+20h] [ebp-44h] BYREF
  unsigned int *m_buffer; // [esp+24h] [ebp-40h]
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl> > *p_M_impl; // [esp+28h] [ebp-3Ch]

  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
    &this->m_preconditions._M_impl,
    &__that->m_preconditions._M_impl);
  p_M_impl = &this->m_effects._M_impl;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(
    &this->m_effects._M_impl,
    &__that->m_effects._M_impl);
  m_buffer = (unsigned int *)this->m_parameters_instances.m_buffer;
  this->m_parameters_instances.m_begin = (unsigned int *)this->m_parameters_instances.m_buffer;
  this->m_parameters_instances.m_end = m_buffer;
  end = __that->m_parameters_instances.m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    &this->m_parameters_instances,
    __that->m_parameters_instances.m_begin,
    (const unsigned int *const *)&end);
  this->m_prototype = __that->m_prototype;
}
