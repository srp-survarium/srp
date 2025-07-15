void __userpurge vostok::animation::event_channel::create_in_place_internals(
        const vostok::animation::bi_spline_event_channel_baked *channel@<esi>,
        vostok::animation::event_channel *this,
        _BYTE *memory_buff)
{
  signed int m_knots_count; // edi
  vostok::animation::time_channel<vostok::animation::event_channel::domain_data> *p_m_time_channel; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  double v8; // st7
  unsigned int v9; // ebx
  double v10; // st7
  unsigned int v11; // ebx
  double v12; // st7
  unsigned int v13; // ebp
  unsigned int v14; // edi
  unsigned int i; // ecx
  char *memory_buffa; // [esp+14h] [ebp+8h]

  m_knots_count = channel->m_knots_count;
  memory_buffa = (char *)m_knots_count;
  vostok::strings::copy<32>(
    (char (*)[32])this,
    (const char *)&channel->m_knots.pointer[m_knots_count] + channel->m_domains_count);
  p_m_time_channel = &this->m_time_channel;
  this->m_type = channel->m_type;
  v6 = 0;
  this->m_time_channel.m_internal_memory_position = memory_buff - (_BYTE *)&this->m_time_channel;
  this->m_time_channel.m_knots_count = m_knots_count;
  if ( m_knots_count >= 4 )
  {
    do
    {
      v7 = v6;
      v8 = channel->m_knots.pointer[v6];
      v9 = this->m_time_channel.m_internal_memory_position + 4 * v6 + this->m_time_channel.m_knots_count;
      v6 += 4;
      *(float *)((char *)&p_m_time_channel->m_knots_count + v9) = v8;
      v10 = channel->m_knots.pointer[v7 + 1];
      v11 = this->m_time_channel.m_internal_memory_position + v7 * 4 + this->m_time_channel.m_knots_count;
      v7 += 3;
      *(float *)((char *)&p_m_time_channel->m_internal_memory_position + v11) = v10;
      *(float *)&this->m_name[this->m_time_channel.m_knots_count
                            + 28
                            + v7 * 4
                            + this->m_time_channel.m_internal_memory_position] = channel->m_knots.pointer[v7 - 1];
      m_knots_count = (signed int)memory_buffa;
      *(float *)((char *)&this->m_time_channel.m_knots_count
               + this->m_time_channel.m_knots_count
               + v7 * 4
               + this->m_time_channel.m_internal_memory_position) = channel->m_knots.pointer[v7];
    }
    while ( v6 < (unsigned int)(memory_buffa - 3) );
  }
  for ( ; v6 < m_knots_count; *(float *)((char *)&p_m_time_channel->m_knots_count + v13) = v12 )
  {
    v12 = channel->m_knots.pointer[v6];
    v13 = this->m_time_channel.m_knots_count + 4 * v6++ + this->m_time_channel.m_internal_memory_position;
  }
  v14 = p_m_time_channel->m_knots_count;
  for ( i = 0; i < v14; ++i )
    *((_BYTE *)&this->m_time_channel.m_knots_count + this->m_time_channel.m_internal_memory_position + i) = *((_BYTE *)&channel->m_knots.pointer[channel->m_knots_count] + i);
}
