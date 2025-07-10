void __usercall survarium::lobby_client::discard_playing_order(survarium::lobby_client *this@<ecx>, int a2@<esi>)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v2; // ecx
  unsigned __int8 buffer[4]; // [esp+8h] [ebp-1Ch] BYREF
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v4; // [esp+Ch] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+10h] [ebp-14h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer[0] = 39;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v2, (int)&packet, buffer, 1u);
  v4 = *(vostok::network_core::packet<vostok::network_core::tcp_packet> **)(a2 + 412);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v4, (int)&packet, (unsigned __int8 *)&v4, 4u);
  vostok::network::tcp_packet_client::send((vostok::network::tcp_packet_client *)(a2 + 168), &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
