void __userpurge survarium::messaging_client::find_players_by_name(
        char *player_name@<esi>,
        survarium::messaging_client *this)
{
  survarium::messaging_client *v2; // ebp
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v3; // ecx
  unsigned __int8 v4; // bl
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v6; // ecx
  vostok::network_core::tcp_packet packet; // [esp+10h] [ebp-10h] BYREF

  v2 = this;
  if ( this->m_connection_state == client_connected )
  {
    vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
    LOBYTE(this) = -60;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      v3,
      (int)&packet,
      (unsigned __int8 *)&this,
      1u);
    LOBYTE(this) = 4;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&this,
      (int)&packet,
      (unsigned __int8 *)&this,
      1u);
    v4 = strlen(player_name);
    LOBYTE(this) = v4;
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      v5,
      (int)&packet,
      (unsigned __int8 *)&this,
      1u);
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      v6,
      (int)&packet,
      (unsigned __int8 *)player_name,
      v4);
    vostok::network::tcp_packet_client::send(&v2->m_network_client, &packet);
    if ( packet.m_buffer )
    {
      if ( packet.m_buffer != (unsigned __int8 *)3 )
        packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
    }
  }
}
