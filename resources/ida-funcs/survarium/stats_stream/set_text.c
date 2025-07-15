void __thiscall survarium::stats_stream::set_text(
        const vostok::network_core::udp_match_items_stats *previous_stats,
        survarium::stats_stream *this,
        survarium::stats_graph *current_time_in_ms,
        const vostok::network_core::udp_match_items_stats *new_stats)
{
  unsigned int v4; // edi
  survarium::stats_graph *v5; // ecx
  unsigned int v6; // eax
  float time_4; // [esp+4h] [ebp-11Ch]
  float time_4a; // [esp+4h] [ebp-11Ch]
  float time; // [esp+18h] [ebp-108h]
  char text[256]; // [esp+20h] [ebp-100h] BYREF

  v4 = new_stats->bytes - previous_stats->bytes;
  time = (double)(unsigned int)current_time_in_ms * 0.001;
  time_4 = (float)(new_stats->count - previous_stats->count);
  survarium::stats_graph::add_value(current_time_in_ms, (float *)this->graph, time, time_4);
  time_4a = (float)v4;
  survarium::stats_graph::add_value(v5, (float *)this->bytes_per_second_graph, time, time_4a);
  survarium::sprintf_big_number(new_stats->count, 0x3E8u, (const char *)&buf, (char (*)[256])text, (const char *)&buf);
  survarium::flash_text::set_text(&this->count, text);
  survarium::sprintf_big_number(new_stats->bytes, 0x400u, "b", (char (*)[256])text, "bytes");
  survarium::flash_text::set_text(&this->bytes, text);
  if ( (float)(this->graph->m_newest_value->time - this->graph->m_newest_value->next->time) > 0.0 )
  {
    v6 = vostok::math::floor(
           this->graph->m_cumulative_value
         / (float)(this->graph->m_newest_value->time - this->graph->m_newest_value->next->time));
    survarium::sprintf_big_number(v6, (const char *)&buf, (char (*)[256])text);
    survarium::flash_text::set_text(&this->count_per_second, text);
  }
  if ( (float)(this->bytes_per_second_graph->m_newest_value->time
             - this->bytes_per_second_graph->m_newest_value->next->time) > 0.0 )
  {
    vostok::sprintf<256>(
      (char (*)[256])text,
      "%4.1f Kbits",
      (float)((float)(this->bytes_per_second_graph->m_cumulative_value
                    / (float)(this->bytes_per_second_graph->m_newest_value->time
                            - this->bytes_per_second_graph->m_newest_value->next->time))
            * 0.0078125));
    survarium::flash_text::set_text(&this->bits_per_second, text);
  }
}
