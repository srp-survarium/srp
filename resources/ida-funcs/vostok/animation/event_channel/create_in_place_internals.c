void __userpurge vostok::animation::event_channel::create_in_place_internals(
        const vostok::animation::bi_spline_event_channel_baked *channel@<esi>,
        vostok::animation::event_channel *this,
        char *memory_buff)
{
  unsigned int m_knots_count; // edi
  vostok::animation::time_channel<vostok::animation::event_channel::domain_data> *p_m_time_channel; // eax
  double v6; // st7
  int v7; // ebx
  unsigned int v8; // edi
  unsigned int i; // ecx
  unsigned int v10; // [esp+10h] [ebp+8h]

  m_knots_count = channel->m_knots_count;
  vostok::strings::copy<32>(
    (char (*)[32])this,
    (char *)&channel->m_knots.pointer[m_knots_count] + channel->m_domains_count);
  v10 = 0;
  this->m_type = channel->m_type;
  p_m_time_channel = &this->m_time_channel;
  p_m_time_channel->m_internal_memory_position = memory_buff - (char *)p_m_time_channel;
  for ( p_m_time_channel->m_knots_count = m_knots_count;
        v10 < m_knots_count;
        *(float *)((char *)&p_m_time_channel->m_knots_count + v7) = v6 )
  {
    v6 = channel->m_knots.pointer[v10];
    v7 = 4 * v10++ + p_m_time_channel->m_knots_count + p_m_time_channel->m_internal_memory_position;
  }
  v8 = p_m_time_channel->m_knots_count;
  for ( i = 0; i < v8; ++i )
    *((_BYTE *)&p_m_time_channel->m_knots_count + p_m_time_channel->m_internal_memory_position + i) = *((_BYTE *)&channel->m_knots.pointer[channel->m_knots_count] + i);
}
