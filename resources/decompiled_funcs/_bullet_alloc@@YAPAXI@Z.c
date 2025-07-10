void *__cdecl bullet_alloc(unsigned int size)
{
  return vostok::physics::g_ph_allocator->call_malloc(vostok::physics::g_ph_allocator, size);
}
