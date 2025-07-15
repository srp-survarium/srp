void __thiscall survarium::pvp_match_core_cook::delete_resource(
        survarium::pvp_match_core_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::physics::world *m_current_satisfaction_update_tick; // ebx

  m_current_satisfaction_update_tick = (vostok::physics::world *)resource[1].m_current_satisfaction_update_tick;
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &resource,
    "survarium::pvp_match_core_cook::delete_resource",
    ".\\pvp_match_core_cook.cpp",
    0x35u);
  vostok::physics::destroy_world(m_current_satisfaction_update_tick);
}
