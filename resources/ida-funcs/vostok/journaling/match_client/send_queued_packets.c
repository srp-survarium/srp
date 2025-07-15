void __thiscall vostok::journaling::match_client::send_queued_packets(
        vostok::journaling::match_client *this,
        unsigned int current_time_in_ms)
{
  this->m_last_send_queed_packets_time_in_ms = current_time_in_ms;
  this->m_are_there_any_packets_to_send = 0;
}
