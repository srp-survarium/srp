void __thiscall survarium::lobby_client::set_status_ready_for_match(
        survarium::lobby_client *this,
        survarium::lobby_client *profile_id,
        unsigned int profile_ida)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  unsigned __int8 buffer[4]; // [esp+4h] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+8h] [ebp-14h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer[0] = 32;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v3, (int)&packet, buffer, 1u);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)profile_ida,
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
