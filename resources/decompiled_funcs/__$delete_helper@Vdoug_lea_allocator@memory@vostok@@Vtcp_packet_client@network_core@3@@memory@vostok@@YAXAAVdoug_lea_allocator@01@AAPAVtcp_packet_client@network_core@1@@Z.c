void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::tcp_packet_client>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::network_core::tcp_packet_client **pointer)
{
  vostok::network_core::tcp_packet_client *v2; // [esp+8h] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    vostok::network_core::tcp_packet_client::~tcp_packet_client(*pointer);
    vostok::memory::doug_lea_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
