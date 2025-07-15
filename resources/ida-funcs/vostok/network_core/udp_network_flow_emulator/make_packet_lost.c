void __thiscall vostok::network_core::udp_network_flow_emulator::make_packet_lost(
        vostok::network_core::udp_network_flow_emulator *this,
        unsigned __int8 *buffer,
        unsigned int buffer_size,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint)
{
  vostok::network_core::base_packet packet; // [esp+4h] [ebp-Ch] BYREF

  packet.m_buffer = buffer;
  packet.m_buffer_size = buffer_size;
  vostok::network_core::udp_match_connection::is_low_level_packet(&packet);
}
