void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network::match_client_impl>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network::match_client_impl **pointer)
{
  vostok::network::match_client_impl *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network::match_client_impl::~match_client_impl(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
