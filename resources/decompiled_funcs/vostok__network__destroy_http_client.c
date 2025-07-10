void __cdecl vostok::network::destroy_http_client(vostok::network_core::http_client *client_to_destroy)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::http_client>(
    vostok::network::g_allocator,
    &client_to_destroy);
}
