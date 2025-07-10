void __cdecl destroy_client_0(vostok::network_core::tcp_packet_client *client_to_destroy)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::tcp_packet_client>(
    vostok::network::g_allocator,
    &client_to_destroy);
}
