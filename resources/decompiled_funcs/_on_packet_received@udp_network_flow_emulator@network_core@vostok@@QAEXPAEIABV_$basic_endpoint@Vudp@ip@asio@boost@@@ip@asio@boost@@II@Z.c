void __thiscall vostok::network_core::udp_network_flow_emulator::on_packet_received(
        vostok::network_core::udp_network_flow_emulator *this,
        unsigned __int8 *buffer,
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *buffer_size,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *endpoint,
        unsigned int time_in_ms,
        unsigned int unacknowledged_packets_count)
{
  if ( vostok::math::random32::random_f(&this->m_lost_packets_random, 1.0) <= this->m_lost_packet_probability )
    vostok::network_core::udp_network_flow_emulator::make_packet_lost(this, buffer, (unsigned int)buffer_size, endpoint);
  else
    vostok::network_core::udp_network_flow_emulator::add_packet(
      this,
      buffer,
      buffer_size,
      endpoint,
      time_in_ms,
      unacknowledged_packets_count);
}
