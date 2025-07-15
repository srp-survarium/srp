btVector3 *__thiscall btConvexHullShape::localGetSupportingVertexWithoutMargin(
        btConvexHullShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  btVector3 *v3; // eax
  int m_size; // esi
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  btVector3 *m_data; // ecx
  int v10; // edx
  float v11; // xmm0_4
  float v12; // [esp+Ch] [ebp-1Ch]
  float v13; // [esp+10h] [ebp-18h]
  float v14; // [esp+14h] [ebp-14h]
  unsigned __int64 v15; // [esp+1Ch] [ebp-Ch]

  v3 = result;
  m_size = this->m_unscaledPoints.m_size;
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  v12 = FLOAT_N9_9999998e17;
  if ( m_size > 0 )
  {
    v5 = this->m_localScaling.mVec128.m128_f32[0];
    v6 = this->m_localScaling.mVec128.m128_f32[1];
    v7 = this->m_localScaling.mVec128.m128_f32[2];
    v8 = vec->mVec128.m128_f32[1];
    m_data = this->m_unscaledPoints.m_data;
    v14 = vec->mVec128.m128_f32[2];
    v13 = vec->mVec128.m128_f32[0];
    v10 = m_size;
    do
    {
      *(float *)&v15 = m_data->mVec128.m128_f32[1] * v6;
      v11 = (float)((float)(v13 * (float)(v5 * m_data->mVec128.m128_f32[0])) + (float)(v8 * *(float *)&v15))
          + (float)(v14 * (float)(m_data->mVec128.m128_f32[2] * v7));
      *((float *)&v15 + 1) = m_data->mVec128.m128_f32[2] * v7;
      if ( v11 > v12 )
      {
        result->mVec128.m128_f32[0] = v5 * m_data->mVec128.m128_f32[0];
        *(unsigned __int64 *)((char *)result->mVec128.m128_u64 + 4) = v15;
        v12 = v11;
        result->mVec128.m128_i32[3] = 0;
      }
      ++m_data;
      --v10;
    }
    while ( v10 );
  }
  return v3;
}
