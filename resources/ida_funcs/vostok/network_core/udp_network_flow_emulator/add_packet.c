void __thiscall vostok::network_core::udp_network_flow_emulator::add_packet(
        vostok::network_core::udp_network_flow_emulator *this,
        unsigned __int8 *buffer,
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *buffer_size,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint,
        unsigned int time_in_ms,
        unsigned int unacknowledged_packets_count)
{
  vostok::network_core::packet_reader *v6; // ecx
  vostok::network_core::packet_reader *v7; // ecx
  unsigned int v8; // eax
  _BYTE v10[28]; // [esp+2Ch] [ebp-94h] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *p_second; // [esp+48h] [ebp-78h]
  _BYTE *v12; // [esp+4Ch] [ebp-74h]
  int v13; // [esp+58h] [ebp-68h]
  unsigned int m_max_ping_time_in_ms; // [esp+5Ch] [ebp-64h]
  unsigned int m_min_ping_time_in_ms; // [esp+60h] [ebp-60h]
  stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > v16; // [esp+80h] [ebp-40h] BYREF
  _DWORD v17[2]; // [esp+A4h] [ebp-1Ch] BYREF
  vostok::network_core::udp_match_packet *packet; // [esp+ACh] [ebp-14h]
  unsigned __int16 received_local_sequence_id; // [esp+B0h] [ebp-10h]
  vostok::network_core::packet_reader reader; // [esp+B4h] [ebp-Ch] BYREF
  unsigned __int16 remote_sequence_id; // [esp+BCh] [ebp-4h]

  v17[0] = buffer;
  v17[1] = buffer_size;
  reader.m_packet = (const vostok::network_core::base_packet *)v17;
  reader.m_pointer = (const unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                buffer_size,
                                                (int)v17);
  remote_sequence_id = vostok::network_core::packet_reader::r<unsigned short>(v6, (int)&reader);
  received_local_sequence_id = vostok::network_core::packet_reader::r<unsigned short>(v7, (int)&reader);
  packet = vostok::network_core::new_udp_match_packet(this->m_packets_allocator);
  m_max_ping_time_in_ms = this->m_max_ping_time_in_ms;
  m_min_ping_time_in_ms = this->m_min_ping_time_in_ms;
  v8 = vostok::math::random32::random(&this->m_ping_random, m_max_ping_time_in_ms - m_min_ping_time_in_ms);
  packet->last_send_time_in_ms = time_in_ms + m_min_ping_time_in_ms + v8;
  v13 = this->m_delayed_packets._M_impl._M_finish - this->m_delayed_packets._M_impl._M_start;
  if ( v13 + unacknowledged_packets_count >= ((300 * this->m_packets_allocator->m_max_count) >> 2) - 1 )
    packet->last_send_time_in_ms = time_in_ms;
  vostok::memory::copy(packet->m_buffer.elems, 6u, buffer, 6u);
  vostok::network_core::packet<vostok::network_core::udp_match_packet>::append(
    (unsigned int)&buffer_size[-1]._M_impl._M_finish + 2,
    packet,
    buffer + 6);
  v12 = v10;
  qmemcpy(v10, endpoint, sizeof(v10));
  v16.first = packet;
  p_second = &v16.second;
  qmemcpy(&v16.second, v10, sizeof(v16.second));
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>,vostok::vectora_allocator<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>>>::push_back(
    &this->m_delayed_packets._M_impl,
    &v16);
}
