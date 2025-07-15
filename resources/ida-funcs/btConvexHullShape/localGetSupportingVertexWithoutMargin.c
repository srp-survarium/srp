btVector3 *__thiscall btConvexHullShape::localGetSupportingVertexWithoutMargin(
        btConvexHullShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  btVector3 *v3; // eax
  int m_size; // edx
  float v5; // xmm1_4
  int v6; // esi
  btVector3 *m_data; // esi
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float *v11; // edi
  float *v12; // esi
  unsigned int v13; // edx
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  btVector3 *v17; // edx
  int v18; // ecx
  float v19; // [esp+24h] [ebp-24h]
  float v20; // [esp+24h] [ebp-24h]
  float v21; // [esp+28h] [ebp-20h]
  __int64 v22; // [esp+28h] [ebp-20h]
  float v23; // [esp+2Ch] [ebp-1Ch]
  int v24; // [esp+30h] [ebp-18h]
  int v25; // [esp+34h] [ebp-14h]
  btVector3 v26; // [esp+38h] [ebp-10h]
  unsigned __int64 v27; // [esp+38h] [ebp-10h]
  unsigned __int64 v28; // [esp+40h] [ebp-8h]

  v3 = result;
  m_size = this->m_unscaledPoints.m_size;
  v5 = -9.9999998e17;
  v6 = 0;
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  v24 = m_size;
  if ( m_size >= 4 )
  {
    m_data = this->m_unscaledPoints.m_data;
    v8 = this->m_localScaling.mVec128.m128_f32[0];
    v9 = this->m_localScaling.mVec128.m128_f32[1];
    v10 = this->m_localScaling.mVec128.m128_f32[2];
    v26.mVec128.m128_i32[3] = 0;
    v11 = &m_data->mVec128.m128_f32[2];
    v12 = &m_data[1].mVec128.m128_f32[2];
    v21 = vec->mVec128.m128_f32[1];
    v13 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v23 = vec->mVec128.m128_f32[2];
    v25 = 4 * v13;
    v3 = result;
    v19 = vec->mVec128.m128_f32[0];
    do
    {
      v26.mVec128.m128_f32[0] = *(v11 - 2) * v8;
      v26.mVec128.m128_f32[2] = *v11 * v10;
      if ( (float)((float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * (float)(*(v11 - 1) * v9)))
                 + (float)(v23 * v26.mVec128.m128_f32[2])) > v5 )
      {
        v26.mVec128.m128_f32[1] = *(v11 - 1) * v9;
        v5 = (float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * v26.mVec128.m128_f32[1]))
           + (float)(v23 * (float)(*v11 * v10));
        *result = (btVector3)v26.mVec128;
      }
      v26.mVec128.m128_f32[0] = v11[2] * v8;
      v26.mVec128.m128_f32[2] = *v12 * v10;
      if ( (float)((float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * (float)(*(v12 - 1) * v9)))
                 + (float)(v23 * v26.mVec128.m128_f32[2])) > v5 )
      {
        v26.mVec128.m128_f32[1] = *(v12 - 1) * v9;
        v5 = (float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * v26.mVec128.m128_f32[1]))
           + (float)(v23 * (float)(*v12 * v10));
        *result = (btVector3)v26.mVec128;
      }
      v26.mVec128.m128_f32[0] = v11[6] * v8;
      v26.mVec128.m128_f32[2] = v12[4] * v10;
      if ( (float)((float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * (float)(v12[3] * v9)))
                 + (float)(v23 * v26.mVec128.m128_f32[2])) > v5 )
      {
        v26.mVec128.m128_f32[1] = v12[3] * v9;
        v5 = (float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * v26.mVec128.m128_f32[1]))
           + (float)(v23 * (float)(v12[4] * v10));
        *result = (btVector3)v26.mVec128;
      }
      v26.mVec128.m128_f32[0] = v11[10] * v8;
      v26.mVec128.m128_f32[2] = v12[8] * v10;
      if ( (float)((float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * (float)(v12[7] * v9)))
                 + (float)(v23 * v26.mVec128.m128_f32[2])) > v5 )
      {
        v26.mVec128.m128_f32[1] = v12[7] * v9;
        v5 = (float)((float)(v19 * v26.mVec128.m128_f32[0]) + (float)(v21 * v26.mVec128.m128_f32[1]))
           + (float)(v23 * (float)(v12[8] * v10));
        *result = (btVector3)v26.mVec128;
      }
      v11 += 16;
      v12 += 16;
      --v13;
    }
    while ( v13 );
    v6 = v25;
    m_size = v24;
  }
  if ( v6 < m_size )
  {
    v14 = this->m_localScaling.mVec128.m128_f32[0];
    v15 = this->m_localScaling.mVec128.m128_f32[1];
    v16 = this->m_localScaling.mVec128.m128_f32[2];
    HIDWORD(v28) = 0;
    v17 = &this->m_unscaledPoints.m_data[v6];
    v22 = *(__int64 *)((char *)vec->mVec128.m128_i64 + 4);
    v20 = vec->mVec128.m128_f32[0];
    v18 = v24 - v6;
    do
    {
      *(float *)&v27 = v17->mVec128.m128_f32[0] * v14;
      *(float *)&v28 = v17->mVec128.m128_f32[2] * v16;
      if ( (float)((float)((float)(v20 * *(float *)&v27)
                         + (float)(*(float *)&v22 * (float)(v17->mVec128.m128_f32[1] * v15)))
                 + (float)(*((float *)&v22 + 1) * *(float *)&v28)) > v5 )
      {
        *((float *)&v27 + 1) = v17->mVec128.m128_f32[1] * v15;
        v5 = (float)((float)(v20 * *(float *)&v27) + (float)(*(float *)&v22 * *((float *)&v27 + 1)))
           + (float)(*((float *)&v22 + 1) * (float)(v17->mVec128.m128_f32[2] * v16));
        v3->mVec128.m128_u64[0] = v27;
        v3->mVec128.m128_u64[1] = v28;
      }
      ++v17;
      --v18;
    }
    while ( v18 );
  }
  return v3;
}
