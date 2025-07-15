void __thiscall survarium::match_client::send_queued_packets(
        survarium::match_client *this,
        unsigned int current_time_in_ms)
{
  this->m_last_send_queed_packets_time_in_ms = current_time_in_ms;
  this->m_are_there_any_packets_to_send = 0;
  vostok::network::match_client::send_queued_packets(
    &this->m_client,
    &this->m_client.m_order_packets_allocator.m_object,
    current_time_in_ms);
}
