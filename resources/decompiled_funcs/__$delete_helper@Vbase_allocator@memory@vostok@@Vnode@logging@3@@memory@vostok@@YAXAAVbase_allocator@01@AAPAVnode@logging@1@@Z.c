void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::logging::node>(
        vostok::memory::base_allocator *allocator,
        vostok::logging::node **pointer)
{
  vostok::logging::node *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::logging::node::~node(*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
