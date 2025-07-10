void __usercall survarium::lobby_client::ping_server(survarium::lobby_client *this@<ecx>, int a2@<esi>)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v2; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  unsigned __int8 buffer[4]; // [esp+8h] [ebp-1Ch] BYREF
  unsigned int m_buffer_size; // [esp+Ch] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+10h] [ebp-14h] BYREF

  if ( *(_BYTE *)(a2 + 404) )
  {
    vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
    buffer[0] = 40;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v2, (int)&packet, buffer, 1u);
    v3 = *(vostok::network_core::packet<vostok::network_core::tcp_packet> **)(a2 + 32);
    m_buffer_size = v3[126].m_buffer_size;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      v3,
      (int)&packet,
      (unsigned __int8 *)&m_buffer_size,
      4u);
    vostok::network::tcp_packet_client::send((vostok::network::tcp_packet_client *)(a2 + 168), &packet);
    if ( packet.m_buffer )
    {
      if ( packet.m_buffer != (unsigned __int8 *)3 )
        packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
    }
  }
}
