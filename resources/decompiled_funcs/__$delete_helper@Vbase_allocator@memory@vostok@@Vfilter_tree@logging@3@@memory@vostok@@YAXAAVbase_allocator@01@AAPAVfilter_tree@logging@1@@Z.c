void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::filter_tree>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::filter_tree **pointer)
{
  vostok::logging::filter_tree *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::filter_tree::~filter_tree(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
