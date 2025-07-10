void __cdecl stlp_std::_Param_Construct<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::planning::pddl_world_state_property_impl>(
        vostok::ai::planning::pddl_world_state_property_impl *__p,
        const vostok::ai::planning::pddl_world_state_property_impl *__val)
{
  vostok::ai::planning::pddl_world_state_property_impl *v2; // [esp+20h] [ebp-8h]

  v2 = (vostok::ai::planning::pddl_world_state_property_impl *)operator new(0x20u, __p);
  if ( v2 )
    vostok::ai::planning::pddl_world_state_property_impl::pddl_world_state_property_impl(v2, __val);
}
