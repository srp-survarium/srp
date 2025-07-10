void __cdecl vostok::memory::free_helper<vostok::memory::base_allocator,char const>(
        vostok::memory::base_allocator *allocator,
        const char **pointer)
{
  if ( *pointer )
  {
    vostok::memory::base_allocator::free_impl(allocator, (void *)*pointer);
    *pointer = 0;
  }
}
