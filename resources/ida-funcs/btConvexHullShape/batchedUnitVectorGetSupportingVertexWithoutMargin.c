void __thiscall btConvexHullShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btConvexHullShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int *v4; // eax
  int v5; // edx
  btVector3 *v6; // eax
  int v7; // edi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  int *v11; // edx
  float *v12; // eax
  unsigned int v13; // esi
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float *v18; // esi
  float *v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // [esp+3Ch] [ebp-18h]
  int v23; // [esp+40h] [ebp-14h]
  __int64 v24; // [esp+44h] [ebp-10h]
  __int64 v25; // [esp+4Ch] [ebp-8h]

  if ( numVectors > 0 )
  {
    v4 = &supportVerticesOut->mVec128.m128_i32[3];
    v5 = numVectors;
    do
    {
      *v4 = -581039253;
      v4 += 4;
      --v5;
    }
    while ( v5 );
  }
  v23 = 0;
  if ( this->m_unscaledPoints.m_size > 0 )
  {
    HIDWORD(v25) = 0;
    v22 = 0;
    do
    {
      v6 = &this->m_unscaledPoints.m_data[v22];
      v7 = 0;
      v8 = v6->mVec128.m128_f32[0] * this->m_localScaling.mVec128.m128_f32[0];
      v9 = v6->mVec128.m128_f32[1] * this->m_localScaling.mVec128.m128_f32[1];
      v10 = v6->mVec128.m128_f32[2] * this->m_localScaling.mVec128.m128_f32[2];
      *(float *)&v24 = v8;
      *((float *)&v24 + 1) = v9;
      *(float *)&v25 = v10;
      if ( numVectors >= 4 )
      {
        v11 = &supportVerticesOut->mVec128.m128_i32[3];
        v12 = &vectors[1].mVec128.m128_f32[2];
        v13 = ((unsigned int)(numVectors - 4) >> 2) + 1;
        v7 = 4 * v13;
        do
        {
          v14 = (float)((float)(*(v12 - 6) * v8) + (float)(*(v12 - 5) * v9)) + (float)(*(v12 - 4) * v10);
          if ( v14 > *(float *)v11 )
          {
            *(_QWORD *)(v11 - 3) = v24;
            *(_QWORD *)(v11 - 1) = v25;
            *(float *)v11 = v14;
          }
          v15 = (float)((float)(*(v12 - 2) * v8) + (float)(*(v12 - 1) * v9)) + (float)(v10 * *v12);
          if ( v15 > *((float *)v11 + 4) )
          {
            *(_QWORD *)(v11 + 1) = v24;
            *(_QWORD *)(v11 + 3) = v25;
            *((float *)v11 + 4) = v15;
          }
          v16 = (float)((float)(v12[2] * v8) + (float)(v12[3] * v9)) + (float)(v12[4] * v10);
          if ( v16 > *((float *)v11 + 8) )
          {
            *(_QWORD *)(v11 + 5) = v24;
            *(_QWORD *)(v11 + 7) = v25;
            *((float *)v11 + 8) = v16;
          }
          v17 = (float)((float)(v12[6] * v8) + (float)(v12[7] * v9)) + (float)(v12[8] * v10);
          if ( v17 > *((float *)v11 + 12) )
          {
            *(_QWORD *)(v11 + 9) = v24;
            *(_QWORD *)(v11 + 11) = v25;
            *((float *)v11 + 12) = v17;
          }
          v12 += 16;
          v11 += 16;
          --v13;
        }
        while ( v13 );
      }
      if ( v7 < numVectors )
      {
        v18 = &supportVerticesOut[v7].mVec128.m128_f32[3];
        v19 = &vectors[v7].mVec128.m128_f32[2];
        v20 = numVectors - v7;
        do
        {
          v21 = (float)((float)(*(v19 - 2) * v8) + (float)(*(v19 - 1) * v9)) + (float)(v10 * *v19);
          if ( v21 > *v18 )
          {
            *(_QWORD *)(v18 - 3) = v24;
            *(_QWORD *)(v18 - 1) = v25;
            *v18 = v21;
          }
          v19 += 4;
          v18 += 4;
          --v20;
        }
        while ( v20 );
      }
      ++v22;
      ++v23;
    }
    while ( v23 < this->m_unscaledPoints.m_size );
  }
}
