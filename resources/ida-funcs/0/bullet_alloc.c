void *__cdecl bullet_alloc(unsigned int size)
{
  return vostok::physics::g_allocator->call_malloc(
           vostok::physics::g_allocator,
           size,
           "bullet",
           "bullet_alloc",
           ".\\bullet_physics_world.cpp",
           42);
}
