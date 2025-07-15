void __cdecl destroy_client(vostok::network::login_client_impl *client_to_destroy)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network::login_client_impl>(
    vostok::network::g_allocator,
    &client_to_destroy);
}
