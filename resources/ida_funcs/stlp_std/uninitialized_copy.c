vostok::ai::planning::world_state_property *__cdecl stlp_std::uninitialized_copy<void * *,void * *>(
        vostok::ai::planning::world_state_property *__first,
        vostok::ai::planning::world_state_property *__last,
        vostok::ai::planning::world_state_property *__result)
{
  return (vostok::ai::planning::world_state_property *)stlp_std::priv::__ucopy_trivial(
                                                         (unsigned __int8 *)__first,
                                                         (unsigned __int8 *)__last,
                                                         (unsigned __int8 *)__result);
}


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
