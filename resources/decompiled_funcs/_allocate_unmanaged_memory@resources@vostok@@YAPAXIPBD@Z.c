void *__cdecl vostok::resources::allocate_unmanaged_memory(unsigned int size)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_unmanaged_allocator, size);
}
