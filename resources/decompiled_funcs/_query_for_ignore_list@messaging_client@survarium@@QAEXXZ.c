void __usercall survarium::messaging_client::query_for_ignore_list(
        survarium::messaging_client *this@<ecx>,
        int a2@<esi>)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v2; // ecx
  unsigned __int8 buffer; // [esp+4h] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+8h] [ebp-14h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
    buffer = -60;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v2, (int)&packet, &buffer, 1u);
    buffer = 6;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
      (int)&packet,
      &buffer,
      1u);
    vostok::network::tcp_packet_client::send((vostok::network::tcp_packet_client *)(a2 + 144), &packet);
    if ( packet.m_buffer )
    {
      if ( packet.m_buffer != (unsigned __int8 *)3 )
        packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
    }
  }
}
