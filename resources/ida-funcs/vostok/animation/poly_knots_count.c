unsigned int __fastcall vostok::animation::poly_knots_count(
        int a1,
        const vostok::animation::bi_spline_channel_animation_baked *cv)
{
  unsigned int m_knots_count; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edi
  int v5; // ebx
  unsigned int v6; // esi
  float v7; // xmm0_4
  unsigned int v8; // esi

  m_knots_count = cv->m_knots_count;
  v3 = 3;
  v4 = cv->m_knots_count - 1;
  v5 = 0;
  if ( v4 > 3 )
  {
    do
    {
      v6 = v3;
      if ( v3 >= m_knots_count )
        v6 = cv->m_knots_count - 1;
      v7 = *(float *)&cv[2 * v6 + 1].m_knots_count;
      v8 = ++v3;
      if ( v3 >= m_knots_count )
        v8 = cv->m_knots_count - 1;
      if ( (float)(*(float *)&cv[2 * v8 + 1].m_knots_count - v7) >= 0.0000001 )
        ++v5;
    }
    while ( v3 < v4 );
  }
  return v5 + 1;
}
