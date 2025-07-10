unsigned int __usercall vostok::animation::poly_knots_count@<eax>(
        const vostok::animation::bi_spline_channel_animation_baked *cv@<edi>)
{
  unsigned int m_knots_count; // esi
  unsigned int v2; // eax
  unsigned int v3; // ebp
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // eax
  float v7; // xmm1_4
  unsigned int v8; // eax
  unsigned int v9; // ecx
  float v10; // xmm1_4
  unsigned int v11; // eax
  unsigned int v12; // eax
  float v13; // xmm1_4
  unsigned int v14; // eax
  unsigned int v15; // ecx
  float v16; // xmm1_4
  unsigned int v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // eax
  float v20; // xmm1_4
  unsigned int v21; // eax
  unsigned int knots_cnt; // [esp+Ch] [ebp-4h]

  m_knots_count = cv->m_knots_count;
  v2 = 0;
  v3 = 3;
  v4 = cv->m_knots_count - 1;
  knots_cnt = 0;
  if ( v4 > 3 )
  {
    if ( (signed int)(cv->m_knots_count - 4) >= 4 )
    {
      v5 = 5;
      do
      {
        v6 = v3;
        if ( v3 >= m_knots_count )
          v6 = cv->m_knots_count - 1;
        v7 = *(float *)&cv[2 * v6 + 1].m_knots_count;
        v8 = v5 - 1;
        v9 = v5 - 1;
        if ( v5 - 1 >= m_knots_count )
          v9 = cv->m_knots_count - 1;
        if ( (float)(*(float *)&cv[2 * v9 + 1].m_knots_count - v7) >= 0.0000001 )
          ++knots_cnt;
        if ( v8 >= m_knots_count )
          v8 = cv->m_knots_count - 1;
        v10 = *(float *)&cv[2 * v8 + 1].m_knots_count;
        v11 = v5;
        if ( v5 >= m_knots_count )
          v11 = cv->m_knots_count - 1;
        if ( (float)(*(float *)&cv[2 * v11 + 1].m_knots_count - v10) >= 0.0000001 )
          ++knots_cnt;
        v12 = v5;
        if ( v5 >= m_knots_count )
          v12 = cv->m_knots_count - 1;
        v13 = *(float *)&cv[2 * v12 + 1].m_knots_count;
        v14 = v5 + 1;
        v15 = v5 + 1;
        if ( v5 + 1 >= m_knots_count )
          v15 = cv->m_knots_count - 1;
        if ( (float)(*(float *)&cv[2 * v15 + 1].m_knots_count - v13) >= 0.0000001 )
          ++knots_cnt;
        if ( v14 >= m_knots_count )
          v14 = cv->m_knots_count - 1;
        v16 = *(float *)&cv[2 * v14 + 1].m_knots_count;
        v17 = v5 + 2;
        if ( v5 + 2 >= m_knots_count )
          v17 = cv->m_knots_count - 1;
        if ( (float)(*(float *)&cv[2 * v17 + 1].m_knots_count - v16) >= 0.0000001 )
          ++knots_cnt;
        v3 += 4;
        v5 += 4;
      }
      while ( v3 < cv->m_knots_count - 4 );
      v2 = knots_cnt;
    }
    if ( v3 < v4 )
    {
      v18 = v3 + 1;
      do
      {
        v19 = v3;
        if ( v3 >= m_knots_count )
          v19 = cv->m_knots_count - 1;
        v20 = *(float *)&cv[2 * v19 + 1].m_knots_count;
        v21 = v18;
        if ( v18 >= m_knots_count )
          v21 = cv->m_knots_count - 1;
        if ( (float)(*(float *)&cv[2 * v21 + 1].m_knots_count - v20) >= 0.0000001 )
          ++knots_cnt;
        ++v3;
        ++v18;
      }
      while ( v3 < v4 );
      v2 = knots_cnt;
    }
  }
  return v2 + 1;
}
