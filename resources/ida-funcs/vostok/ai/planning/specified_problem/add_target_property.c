void __thiscall vostok::ai::planning::specified_problem::add_target_property(
        vostok::ai::planning::specified_problem *this,
        const vostok::ai::planning::pddl_world_state_property_impl *property_to_be_added)
{
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::push_back(
    &this->m_target_world_state._M_impl,
    property_to_be_added);
}
