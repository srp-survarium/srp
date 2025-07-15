void __userpurge vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1>>::create_in_place_internals(
        vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *this@<esi>,
        const vostok::animation::bi_spline_channel_animation_baked *cv@<eax>,
        _BYTE *memory_buff)
{
  unsigned int v4; // eax
  unsigned int m_knots_count; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  int v8; // ebp
  unsigned int v9; // ebx
  unsigned int v10; // xmm0_4
  unsigned int v11; // ebx
  int v12; // eax
  vostok::animation::poly_curve_order3_domain<float,1> domain; // [esp+10h] [ebp-10h] BYREF
  char *memory_buffa; // [esp+24h] [ebp+4h]

  v4 = vostok::animation::poly_knots_count(cv);
  this->m_time_channel.m_internal_memory_position = memory_buff - (_BYTE *)this;
  this->m_time_channel.m_knots_count = v4;
  m_knots_count = cv->m_knots_count;
  v6 = 3;
  v7 = cv->m_knots_count - 1;
  v8 = 0;
  if ( v7 > 3 )
  {
    memory_buffa = 0;
    do
    {
      v9 = v6;
      if ( v6 >= m_knots_count )
        v9 = v7;
      v10 = cv[2 * v9 + 1].m_knots_count;
      v11 = v6 + 1;
      if ( v6 + 1 < m_knots_count )
        v7 = v6 + 1;
      if ( (float)(*(float *)&cv[2 * v7 + 1].m_knots_count - *(float *)&v10) >= 0.0000001 )
      {
        vostok::animation::get_spline_params<vostok::animation::bi_spline_channel_animation_baked,float,1>(
          cv,
          v6,
          domain.m_coeff);
        *(vostok::animation::poly_curve_order3_domain<float,1> *)&memory_buffa[this->m_time_channel.m_internal_memory_position
                                                                             + (_DWORD)this] = domain;
        v12 = v8 + 4 * this->m_time_channel.m_knots_count;
        ++v8;
        *(unsigned int *)((char *)&this->m_time_channel.m_knots_count
                        + 4 * v12
                        + this->m_time_channel.m_internal_memory_position) = v10;
        memory_buffa += 16;
      }
      m_knots_count = cv->m_knots_count;
      v6 = v11;
      v7 = cv->m_knots_count - 1;
    }
    while ( v11 < v7 );
  }
  *(unsigned int *)((char *)&this[2 * this->m_time_channel.m_knots_count].m_time_channel.m_knots_count
                  + 4 * v8
                  + this->m_time_channel.m_internal_memory_position) = cv[2 * cv->m_knots_count - 1].m_knots_count;
}
