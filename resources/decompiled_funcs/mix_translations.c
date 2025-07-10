vostok::math::float3 *__usercall mix_translations@<eax>(
        const vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *transforms@<edx>,
        vostok::math::float3 *result@<eax>)
{
  stlp_std::pair<vostok::math::float3,float> *m_begin; // ecx
  __int128 v3; // xmm4
  stlp_std::pair<vostok::math::float3,float> *m_end; // edx
  float v5; // xmm5_4
  float v6; // xmm6_4
  float second; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  __int128 v11; // xmm0

  m_begin = transforms->m_begin;
  v3 = 0;
  m_end = transforms->m_end;
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  if ( m_begin != m_end )
  {
    v5 = 0.0;
    v6 = 0.0;
    do
    {
      second = m_begin->second;
      v8 = m_begin->first.y * second;
      v9 = m_begin->first.z * second;
      v10 = m_begin->first.x * second;
      v11 = v3;
      ++m_begin;
      *(float *)&v11 = *(float *)&v3 + v10;
      v3 = v11;
      v5 = v5 + v8;
      v6 = v6 + v9;
    }
    while ( m_begin != m_end );
    LODWORD(result->x) = v11;
    result->y = v5;
    result->z = v6;
  }
  return result;
}
