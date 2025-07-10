void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::log_file>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::log_file **pointer)
{
  vostok::logging::log_file *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::log_file::~log_file(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
