void __userpurge survarium::lobby_client::set_player_skills(
        vostok::vectora<survarium::player_skill> *skills@<eax>,
        survarium::lobby_client *this,
        vostok::vectora<unsigned char> *perks)
{
  vostok::vectora<unsigned char> *v3; // ebx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v5; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v6; // ecx
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v7; // ecx
  survarium::player_skill *M_start; // eax
  survarium::player_skill *M_finish; // esi
  vostok::network_core::packet<vostok::network_core::tcp_packet> *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // ebx
  vostok::network_core::tcp_packet packet; // [esp+10h] [ebp-14h] BYREF

  v3 = perks;
  vostok::network_core::tcp_packet::tcp_packet(&packet, &vostok::memory::g_mt_allocator);
  LOBYTE(perks) = 37;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v5,
    (int)&packet,
    (unsigned __int8 *)&perks,
    1u);
  LOBYTE(perks) = 0;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    (vostok::network_core::packet<vostok::network_core::tcp_packet> *)&perks,
    (int)&packet,
    (unsigned __int8 *)&perks,
    1u);
  LOBYTE(perks) = skills->_M_impl._M_finish - skills->_M_impl._M_start;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v6,
    (int)&packet,
    (unsigned __int8 *)&perks,
    1u);
  M_start = skills->_M_impl._M_start;
  M_finish = skills->_M_impl._M_finish;
  if ( M_start != M_finish )
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
      v7,
      (int)&packet,
      &M_start->skill_id,
      2 * (M_finish - M_start));
  LOBYTE(perks) = LOBYTE(v3->_M_impl._M_finish) - LOBYTE(v3->_M_impl._M_start);
  LOBYTE(v7) = (_BYTE)perks;
  vostok::network_core::packet<vostok::network_core::tcp_packet>::append(
    v7,
    (int)&packet,
    (unsigned __int8 *)&perks,
    1u);
  v11 = v3->_M_impl._M_start;
  v12 = v3->_M_impl._M_finish;
  if ( v11 != v12 )
    vostok::network_core::packet<vostok::network_core::tcp_packet>::append(v10, (int)&packet, v11, v12 - v11);
  vostok::network::tcp_packet_client::send(&this->m_packet_client, &packet);
  if ( packet.m_buffer )
  {
    if ( packet.m_buffer != (unsigned __int8 *)3 )
      packet.m_allocator->call_free(packet.m_allocator, packet.m_buffer - 3);
  }
}
