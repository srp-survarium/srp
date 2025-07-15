void __thiscall vostok::ai::planning::specified_problem::reset(vostok::ai::planning::specified_problem *this)
{
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::clear(&this->m_target_world_state._M_impl);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>::clear(&this->m_objects._M_t);
}
