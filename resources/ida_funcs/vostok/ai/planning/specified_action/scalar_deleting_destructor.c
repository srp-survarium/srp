vostok::ai::planning::specified_action *__thiscall vostok::ai::planning::specified_action::`scalar deleting destructor'(
        vostok::ai::planning::specified_action *this,
        char a2)
{
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
    (vostok::buffer_vector<vostok::resources::request> *)this,
    &this->m_parameters_instances.m_begin);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_effects._M_impl);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_preconditions._M_impl);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
