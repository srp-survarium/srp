void __thiscall vostok::physics::bullet_physics_world::bullet_physics_world(
        vostok::physics::bullet_physics_world *this,
        vostok::memory::base_allocator *allocator,
        vostok::physics::engine *engine)
{
  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::physics::bullet_physics_world::`vftable';
  LOBYTE(allocator->m_arena_start) = 0;
  BYTE1(allocator->m_arena_start) = 0;
  BYTE2(allocator->m_arena_start) = 0;
  allocator->m_arena_end = 0;
  allocator->m_arena_id = 0;
  *(_DWORD *)&allocator->m_use_memory_monitor = 0;
  allocator[1].__vftable = 0;
  LOBYTE(allocator[1].m_arena_end) = HIBYTE(allocator);
  LOBYTE(allocator->m_arena_end) = 0;
  allocator->m_arena_id = 0;
  *(_DWORD *)&allocator->m_use_memory_monitor = &allocator->m_arena_end;
  allocator[1].__vftable = (vostok::memory::base_allocator_vtbl *)&allocator->m_arena_end;
  allocator[1].m_arena_start = 0;
  allocator[3].m_arena_start = engine;
  allocator[1].m_arena_id = (const char *)&vostok::memory::g_mt_allocator;
  vostok::math::create_invalid_aabb((vostok::math::aabb *)&allocator[3].m_arena_end);
}
