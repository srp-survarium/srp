vostok::ai::planning::pddl_world_state_property_impl *__cdecl stlp_std::uninitialized_copy<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
        const vostok::ai::planning::pddl_world_state_property_impl *__first,
        const vostok::ai::planning::pddl_world_state_property_impl *__last,
        vostok::ai::planning::pddl_world_state_property_impl *__result)
{
  stlp_std::__true_type __formal; // [esp+37h] [ebp-1h] BYREF

  __formal = 0;
  return stlp_std::priv::__ucopy_aux<vostok::ai::planning::pddl_world_state_property_impl const *,vostok::ai::planning::pddl_world_state_property_impl *>(
           __first,
           __last,
           __result,
           &__formal);
}
