vostok::network_core::udp_match_packet *__cdecl vostok::network_core::new_udp_match_packet(
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *allocator)
{
  vostok::network_core::udp_match_packet *v2; // [esp+10h] [ebp-24h]
  vostok::network_core::udp_match_packet *result; // [esp+30h] [ebp-4h]

  result = (vostok::network_core::udp_match_packet *)vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::allocate(allocator);
  v2 = (vostok::network_core::udp_match_packet *)operator new(0x12Cu, result);
  if ( v2 )
    vostok::network_core::udp_match_packet::udp_match_packet(v2);
  return result;
}
