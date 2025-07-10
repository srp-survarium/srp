void __thiscall survarium::lobby_client::move_item(
        survarium::lobby_client *this,
        survarium::lobby_client *items,
        survarium::vector<survarium::relocate_item_descr> *itemsa)
{
  survarium::vector<survarium::relocate_item_descr> *v3; // ebx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v4; // ecx
  survarium::relocate_item_descr *i; // esi
  vostok::network_core::tcp_packet packet; // [esp+10h] [ebp-14h] BYREF

  v3 = itemsa;
  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  LOBYTE(itemsa) = 35;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v4,
    (int)&packet,
    (unsigned __int8 *)&itemsa,
    1u);
  LOBYTE(itemsa) = 0;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&itemsa,
    (int)&packet,
    (unsigned __int8 *)&itemsa,
    1u);
  LOBYTE(itemsa) = v3->_M_impl._M_finish - v3->_M_impl._M_start;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&itemsa,
    (int)&packet,
    (unsigned __int8 *)&itemsa,
    1u);
  for ( i = v3->_M_impl._M_start; i != v3->_M_impl._M_finish; ++i )
    survarium::relocate_item_descr::serialize(i, &packet);
  vostok::network::tcp_packet_client::send(&items->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
