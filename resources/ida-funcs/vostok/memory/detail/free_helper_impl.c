void __cdecl vostok::memory::detail::free_helper_impl<vostok::memory::base_allocator,vostok::resources::resource_base>(
        vostok::memory::base_allocator *allocator,
        vostok::resources::resource_base **pointer,
        void *const top_pointer)
{
  vostok::memory::base_allocator::free_impl(allocator, top_pointer);
  *pointer = 0;
}
