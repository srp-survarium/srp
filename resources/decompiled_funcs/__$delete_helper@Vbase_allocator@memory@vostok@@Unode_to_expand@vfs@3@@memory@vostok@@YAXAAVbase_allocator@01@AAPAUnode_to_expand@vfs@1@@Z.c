void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::node_to_expand>(
        vostok::memory::base_allocator *allocator,
        vostok::vfs::node_to_expand **pointer)
{
  if ( *pointer )
  {
    vostok::memory::base_allocator::free_impl(allocator, *pointer);
    *pointer = 0;
  }
}
