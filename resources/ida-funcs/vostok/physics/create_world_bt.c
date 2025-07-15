void __cdecl vostok::physics::create_world_bt(vostok::physics::engine *allocator)
{
  char *v1; // eax
  vostok::memory::base_allocator *v2; // eax
  vostok::physics::bullet_physics_world *v3; // ecx

  v1 = type_info::raw_name(&vostok::physics::bullet_physics_world `RTTI Type Descriptor');
  v2 = (vostok::memory::base_allocator *)vostok::memory::g_mt_allocator.call_malloc(
                                           &vostok::memory::g_mt_allocator,
                                           92,
                                           v1,
                                           "vostok::physics::create_world_bt",
                                           ".\\physics_entry_point.cpp",
                                           24);
  if ( v2 )
    vostok::physics::bullet_physics_world::bullet_physics_world(v3, v2, allocator);
}
