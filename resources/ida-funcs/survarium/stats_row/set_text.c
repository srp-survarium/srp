void __userpurge survarium::stats_row::set_text(
        survarium::stats_graph *current_time_in_ms@<ecx>,
        const vostok::network_core::udp_match_stream_stats *previous_stats@<eax>,
        survarium::stats_row *this,
        const vostok::network_core::udp_match_stream_stats *new_stats)
{
  survarium::stats_graph *v6; // ecx
  unsigned int m_count; // eax
  float m_cumulative_value; // xmm0_4
  float time; // [esp+0h] [ebp-124h]
  float time_4; // [esp+4h] [ebp-120h]
  char text[256]; // [esp+20h] [ebp-104h] BYREF

  survarium::stats_stream::set_text(&previous_stats->packets, &this->packets, current_time_in_ms, &new_stats->packets);
  survarium::stats_stream::set_text(
    &previous_stats->messages,
    &this->messages,
    current_time_in_ms,
    &new_stats->messages);
  time_4 = (float)(new_stats->data_bytes - previous_stats->data_bytes);
  time = (double)(unsigned int)current_time_in_ms * 0.001;
  survarium::stats_graph::add_value(v6, (float *)this->data_bytes_per_second_graph, time, time_4);
  survarium::sprintf_big_number(new_stats->data_bytes, 0x400u, "b", (char (*)[256])text, "bytes");
  survarium::flash_text::set_text(&this->data_bytes, text);
  if ( (float)(this->data_bytes_per_second_graph->m_newest_value->time
             - this->data_bytes_per_second_graph->m_newest_value->next->time) > 0.0 )
  {
    vostok::sprintf<256>(
      (char (*)[256])text,
      "%4.1f Kbits",
      (float)((float)(this->data_bytes_per_second_graph->m_cumulative_value
                    / (float)(this->data_bytes_per_second_graph->m_newest_value->time
                            - this->data_bytes_per_second_graph->m_newest_value->next->time))
            * 0.0078125));
    survarium::flash_text::set_text(&this->data_bits_per_second, text);
  }
  m_count = this->messages.graph->m_count;
  if ( m_count )
  {
    vostok::sprintf<256>(
      (char (*)[256])text,
      "%5.1f bytes",
      this->data_bytes_per_second_graph->m_cumulative_value / (double)m_count);
    survarium::flash_text::set_text(&this->data_bits_per_message, text);
  }
  m_cumulative_value = this->packets.graph->m_cumulative_value;
  if ( m_cumulative_value > 0.0 )
  {
    vostok::sprintf<256>(
      (char (*)[256])text,
      "%5.2f mpp",
      (float)(this->messages.graph->m_cumulative_value / m_cumulative_value));
    survarium::flash_text::set_text(&this->messages_per_second, text);
  }
}
