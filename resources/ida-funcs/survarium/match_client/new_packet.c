vostok::network_core::udp_match_packet *__thiscall survarium::match_client::new_packet(
        survarium::match_client *this,
        int message_type)
{
  return vostok::network::match_client::new_packet(
           (vostok::network::match_client *)this,
           (int)&this->m_client,
           message_type);
}
