void __thiscall survarium::match_client::enqueue(
        survarium::match_client *this,
        vostok::network_core::udp_match_packet *packet)
{
  this->m_are_there_any_packets_to_send = 1;
  vostok::network::match_client::enqueue((vostok::network::match_client *)this, packet);
}
