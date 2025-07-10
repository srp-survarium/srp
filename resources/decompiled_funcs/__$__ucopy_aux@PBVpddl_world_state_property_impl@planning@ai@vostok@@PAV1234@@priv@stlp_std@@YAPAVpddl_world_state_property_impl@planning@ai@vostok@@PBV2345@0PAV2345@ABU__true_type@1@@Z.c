vostok::ai::planning::pddl_world_state_property_impl *__cdecl stlp_std::priv::__ucopy_aux<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
        vostok::ai::planning::pddl_world_state_property_impl *__first,
        const vostok::ai::planning::pddl_world_state_property_impl *__last,
        vostok::ai::planning::pddl_world_state_property_impl *__result)
{
  vostok::ai::planning::pddl_world_state_property_impl *__val; // [esp+0h] [ebp-38h]
  int i; // [esp+28h] [ebp-10h]

  __val = __first;
  for ( i = __last - __first; i > 0; --i )
    stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
      __result++,
      __val++);
  return __result;
}
