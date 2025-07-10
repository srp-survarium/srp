void *__fastcall vostok::memory::malloc_helper<vostok::memory::base_allocator>(
        vostok::memory::base_allocator *allocator,
        unsigned int size)
{
  return allocator->call_malloc(allocator, size);
}
