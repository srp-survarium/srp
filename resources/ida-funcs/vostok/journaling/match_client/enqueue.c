void __thiscall vostok::journaling::match_client::enqueue(
        vostok::journaling::match_client *this,
        vostok::network_core::udp_match_packet *packet)
{
  this->m_are_there_any_packets_to_send = 1;
}
