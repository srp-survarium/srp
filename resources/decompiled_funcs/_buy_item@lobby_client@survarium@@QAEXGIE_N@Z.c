void __thiscall survarium::lobby_client::buy_item(
        survarium::lobby_client *this,
        survarium::lobby_client *item_dict_id,
        vostok::network_core::packet<vostok::network_core::tcp_packet> *count,
        vostok::network_core::packet<vostok::network_core::tcp_packet> *faction_id,
        unsigned __int8 use_premium_money)
{
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v6; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v7; // ecx
  unsigned __int8 buffer; // [esp+4h] [ebp-18h] BYREF
  vostok::network_core::tcp_packet packet; // [esp+8h] [ebp-14h] BYREF

  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  buffer = 36;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v5, (int)&packet, &buffer, 1u);
  buffer = 0;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&buffer,
    (int)&packet,
    &buffer,
    1u);
  count = (vostok::network_core::packet<vostok::network_core::tcp_packet> *)(unsigned __int16)count;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v6,
    (int)&packet,
    (unsigned __int8 *)&count,
    2u);
  count = faction_id;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    faction_id,
    (int)&packet,
    (unsigned __int8 *)&count,
    4u);
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&use_premium_money,
    (int)&packet,
    &use_premium_money,
    1u);
  use_premium_money = 0;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v7, (int)&packet, &use_premium_money, 1u);
  vostok::network::tcp_packet_client::send(&item_dict_id->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
