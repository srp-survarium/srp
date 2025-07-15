char __thiscall delayed_packets_predicate::operator()(
        delayed_packets_predicate *this,
        const stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp> > *message)
{
  if ( this->m_time_in_ms < message->first->last_send_time_in_ms )
    return 0;
  vostok::buffer_vector<stlp_std::pair<vostok::network_core::udp_match_packet *,boost::asio::ip::basic_endpoint<boost::asio::ip::udp>>>::push_back(
    this->m_packets,
    message);
  return 1;
}
