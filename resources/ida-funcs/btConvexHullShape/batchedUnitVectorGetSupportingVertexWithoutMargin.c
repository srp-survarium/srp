void __thiscall btConvexHullShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btConvexHullShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int v4; // edx
  float *v5; // eax
  btVector3 *v6; // eax
  int v7; // ebx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  int *v11; // edx
  float *v12; // eax
  float v13; // xmm0_4
  int v14; // [esp+18h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-14h]

  v4 = numVectors;
  if ( numVectors > 0 )
  {
    v5 = &supportVerticesOut->mVec128.m128_f32[3];
    do
    {
      *v5 = FLOAT_N9_9999998e17;
      v5 += 4;
      --v4;
    }
    while ( v4 );
  }
  v15 = 0;
  if ( this->m_unscaledPoints.m_size > 0 )
  {
    v14 = 0;
    do
    {
      v6 = &this->m_unscaledPoints.m_data[v14];
      v7 = numVectors;
      v8 = v6->mVec128.m128_f32[0] * this->m_localScaling.mVec128.m128_f32[0];
      v9 = v6->mVec128.m128_f32[1] * this->m_localScaling.mVec128.m128_f32[1];
      v10 = v6->mVec128.m128_f32[2] * this->m_localScaling.mVec128.m128_f32[2];
      if ( numVectors > 0 )
      {
        v11 = &supportVerticesOut->mVec128.m128_i32[3];
        v12 = &vectors->mVec128.m128_f32[2];
        do
        {
          v13 = (float)((float)(*(v12 - 2) * v8) + (float)(*(v12 - 1) * v9)) + (float)(v10 * *v12);
          if ( v13 > *(float *)v11 )
          {
            *((float *)v11 - 3) = v8;
            *((float *)v11 - 2) = v9;
            *((float *)v11 - 1) = v10;
            *v11 = 0;
            *(float *)v11 = v13;
          }
          v12 += 4;
          v11 += 4;
          --v7;
        }
        while ( v7 );
      }
      ++v15;
      ++v14;
    }
    while ( v15 < this->m_unscaledPoints.m_size );
  }
}
