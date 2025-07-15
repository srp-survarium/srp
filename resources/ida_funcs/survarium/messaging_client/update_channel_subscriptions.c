void __usercall survarium::messaging_client::update_channel_subscriptions(
        survarium::messaging_client *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  unsigned __int8 buffer[4]; // [esp+8h] [ebp-3Ch] BYREF
  vostok::network_core::tcp_packet packet; // [esp+Ch] [ebp-38h] BYREF
  unsigned int channel_subscriptions[9]; // [esp+1Ch] [ebp-28h] BYREF

  if ( *(_DWORD *)(a2 + 136) == 3 )
  {
    v2 = *(_DWORD *)(a2 + 312);
    channel_subscriptions[0] = 0;
    channel_subscriptions[3] = 0;
    channel_subscriptions[1] = -1;
    channel_subscriptions[2] = -1;
    memset(&channel_subscriptions[6], 0, 12);
    channel_subscriptions[4] = 1;
    channel_subscriptions[5] = v2 != -1 ? v2 : 0;
    vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
    buffer[0] = -59;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v3, (int)&packet, buffer, 1u);
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      (vostok::network_core::packet<vostok::network_core::tcp_packet> *)channel_subscriptions,
      (int)&packet,
      (unsigned __int8 *)channel_subscriptions,
      0x24u);
    vostok::network::tcp_packet_client::send((vostok::network::tcp_packet_client *)(a2 + 144), &packet);
    if ( packet.m_buffer )
    {
      if ( packet.m_buffer != (unsigned __int8 *)3 )
        packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
    }
  }
}
