void __usercall vostok::animation::evaluate_frame(
        const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *channels@<ecx>,
        vostok::animation::frame *f@<eax>,
        float a3@<xmm4>,
        float time,
        vostok::animation::current_frame_position *frame_pos)
{
  vostok::animation::frame *v5; // edi
  int v7; // ebx
  int v8; // ebp
  unsigned int v9; // eax
  unsigned int m_internal_memory_position; // ecx
  float v11; // xmm0_4

  v5 = f;
  v7 = (char *)frame_pos - (char *)f;
  v8 = 9;
  do
  {
    v9 = vostok::animation::time_channel<vostok::animation::poly_curve_order3_domain<float,1>>::domain(
           &channels->m_time_channel,
           a3,
           (unsigned int *)((char *)v5 + v7));
    m_internal_memory_position = channels->m_time_channel.m_internal_memory_position;
    v11 = time
        - *(float *)((char *)&channels[2 * channels->m_time_channel.m_knots_count].m_time_channel.m_knots_count
                   + 4 * v9
                   + m_internal_memory_position);
    v5->translation.x = (float)((float)((float)((float)((float)(*(float *)((char *)&channels[2 * v9 + 1].m_time_channel.m_internal_memory_position
                                                                         + m_internal_memory_position)
                                                              * v11)
                                                      + *(float *)((char *)&channels[2 * v9 + 1].m_time_channel.m_knots_count
                                                                 + m_internal_memory_position))
                                              * v11)
                                      + *(float *)((char *)&channels[2 * v9].m_time_channel.m_internal_memory_position
                                                 + m_internal_memory_position))
                              * v11)
                      + *(float *)((char *)&channels[2 * v9].m_time_channel.m_knots_count + m_internal_memory_position);
    ++channels;
    v5 = (vostok::animation::frame *)((char *)v5 + 4);
    --v8;
  }
  while ( v8 );
}
