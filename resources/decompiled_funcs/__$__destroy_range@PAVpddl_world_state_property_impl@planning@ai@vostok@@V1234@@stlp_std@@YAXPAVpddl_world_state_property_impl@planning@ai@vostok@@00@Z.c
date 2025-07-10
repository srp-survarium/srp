void __cdecl stlp_std::__destroy_range<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl>(
        vostok::ai::planning::pddl_world_state_property_impl *__first,
        vostok::ai::planning::pddl_world_state_property_impl *__last)
{
  while ( __first != __last )
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(0, __first++);
}
