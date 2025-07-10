bool __thiscall survarium::game_world::ray_query(
        survarium::game_world *this,
        const vostok::ai::collision_object *const object_to_pick,
        const vostok::ai::collision_object *const object_to_ignore,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float transparency_threshold,
        float *visibility_value)
{
  vostok::memory::base_allocator *m_allocator; // ecx
  vostok::vectora<vostok::physics::closest_ray_result> game_objects; // [esp+18h] [ebp-10h] BYREF

  m_allocator = this[-1].m_victory_items._M_impl._M_end_of_storage.m_allocator;
  game_objects._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  game_objects._M_impl._M_start = 0;
  game_objects._M_impl._M_finish = 0;
  game_objects._M_impl._M_end_of_storage._M_data = 0;
  ((void (__thiscall *)(vostok::memory::base_allocator *, const vostok::math::float3 *, const vostok::math::float3 *, _DWORD, vostok::vectora<vostok::physics::closest_ray_result> *, int, int))m_allocator->__vftable[1].call_free)(
    m_allocator,
    origin,
    direction,
    LODWORD(max_distance),
    &game_objects,
    0xFFFF,
    64);
  if ( game_objects._M_impl._M_start )
    game_objects._M_impl._M_end_of_storage.m_allocator->call_free(
      game_objects._M_impl._M_end_of_storage.m_allocator,
      game_objects._M_impl._M_start);
  return 0;
}
