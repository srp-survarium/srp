void __userpurge vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1>>::create_in_place_internals(
        _BYTE *memory_buff@<eax>,
        int a2@<ecx>,
        vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *this,
        const vostok::animation::bi_spline_channel_animation_baked *cv)
{
  const vostok::animation::bi_spline_channel_animation_baked *v5; // edi
  unsigned int v7; // eax
  unsigned int m_knots_count; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // esi
  float v12; // xmm1_4
  unsigned int v13; // xmm0_4
  float *v14; // edi
  unsigned int v15; // eax
  int v16; // ecx
  unsigned int v17; // eax
  float point_factors[4]; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v19; // [esp+1Ch] [ebp-Ch]
  unsigned int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]
  int v22; // [esp+30h] [ebp+8h]

  v5 = cv;
  v7 = vostok::animation::poly_knots_count(a2, cv);
  v22 = 0;
  this->m_time_channel.m_internal_memory_position = memory_buff - (_BYTE *)this;
  this->m_time_channel.m_knots_count = v7;
  m_knots_count = cv->m_knots_count;
  v9 = 3;
  v10 = cv->m_knots_count - 1;
  if ( v10 > 3 )
  {
    v21 = 0;
    do
    {
      v11 = v9;
      if ( v9 >= m_knots_count )
        v11 = v10;
      if ( v9 + 1 < m_knots_count )
        v10 = v9 + 1;
      v12 = *(float *)&v5[2 * v10 + 1].m_knots_count - *(float *)&v5[2 * v11 + 1].m_knots_count;
      v20 = v5[2 * v11 + 1].m_knots_count;
      v19 = v9 + 1;
      if ( v12 >= 0.0000001 )
      {
        vostok::animation::get_spline_params<vostok::animation::bi_spline_channel_animation_baked,float,1>(
          v5,
          v9,
          point_factors);
        v13 = v20;
        v14 = (float *)((char *)&this[v21 / 8].m_time_channel.m_knots_count
                      + this->m_time_channel.m_internal_memory_position);
        *v14++ = point_factors[0];
        *v14++ = point_factors[1];
        *v14 = point_factors[2];
        v14[1] = point_factors[3];
        v15 = this->m_time_channel.m_knots_count;
        v5 = cv;
        v16 = v22++;
        v21 += 16;
        *(unsigned int *)((char *)&this[2 * v15].m_time_channel.m_knots_count
                        + 4 * v16
                        + this->m_time_channel.m_internal_memory_position) = v13;
      }
      m_knots_count = v5->m_knots_count;
      v9 = v19;
      v10 = v5->m_knots_count - 1;
    }
    while ( v19 < v10 );
  }
  v17 = v5->m_knots_count - 1;
  if ( v17 >= v5->m_knots_count )
    v17 = v5->m_knots_count - 1;
  *(unsigned int *)((char *)&this[2 * this->m_time_channel.m_knots_count].m_time_channel.m_knots_count
                  + 4 * v22
                  + this->m_time_channel.m_internal_memory_position) = v5[2 * v17 + 1].m_knots_count;
}
