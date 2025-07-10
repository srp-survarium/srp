void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::http_client>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::http_client **pointer)
{
  vostok::network_core::http_client *v2; // [esp+40h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::http_client::~http_client(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
