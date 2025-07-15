vostok::network_core::udp_match_packet *__userpurge vostok::network::match_client::new_packet@<eax>(
        vostok::network::match_client *this@<ecx>,
        int a2@<edi>,
        int message_type)
{
  vostok::network_core::udp_match_packet *matched; // esi
  vostok::network_core::buffer_writer *v4; // ecx

  matched = (vostok::network_core::udp_match_packet *)vostok::network_core::new_udp_match_packet(*(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)a2);
  vostok::network_core::udp_match_connection::construct_packet(
    matched,
    v4,
    *(vostok::network_core::udp_match_packets_orderer **)(a2 + 232),
    message_type);
  return matched;
}
