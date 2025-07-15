void __thiscall survarium::lobby_client::query_profile_contents(
        survarium::lobby_client *this,
        survarium::lobby_client *profile_id,
        unsigned int profile_ida)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v4; // ecx
  unsigned __int8 buffer; // [esp+4h] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+8h] [ebp-14h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer = 33;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v3, (int)&packet, &buffer, 1u);
  buffer = 2;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
    (int)&packet,
    &buffer,
    1u);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v4,
    (int)&packet,
    (unsigned __int8 *)&profile_ida,
    4u);
  vostok::network::tcp_packet_client::send(&profile_id->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
