void __usercall survarium::match_client::enqueue(
        survarium::match_client *this@<esi>,
        vostok::network_core::udp_match_packet *packet@<eax>)
{
  vostok::network::match_client::enqueue(&this->m_client, packet);
  this->m_are_there_any_packets_to_send = 1;
}
