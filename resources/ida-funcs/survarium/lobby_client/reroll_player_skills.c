void __thiscall survarium::lobby_client::reroll_player_skills(
        survarium::lobby_client *this,
        survarium::lobby_client *thisa)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v2; // ecx
  unsigned __int8 buffer; // [esp+4h] [ebp-14h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+8h] [ebp-10h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer = 37;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v2, (int)&packet, &buffer, 1u);
  buffer = 1;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
    (int)&packet,
    &buffer,
    1u);
  vostok::network::tcp_packet_client::send(&thisa->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
