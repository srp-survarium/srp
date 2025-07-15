void __thiscall btBoxShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btBoxShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  btVector3 *v4; // esi
  int v5; // ebp
  float *v6; // edx
  float *v7; // eax
  unsigned int v8; // edi
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float *v21; // eax
  int v22; // esi
  float *v23; // edx
  int v24; // edi
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm1_4

  v4 = supportVerticesOut;
  v5 = 0;
  if ( numVectors >= 4 )
  {
    v6 = &vectors[1].mVec128.m128_f32[1];
    v7 = &supportVerticesOut[1].mVec128.m128_f32[3];
    v8 = ((unsigned int)(numVectors - 4) >> 2) + 1;
    v5 = 4 * v8;
    do
    {
      v9 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      if ( *(v6 - 3) < 0.0 )
        v9 = -v9;
      v10 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
      if ( *(v6 - 4) < 0.0 )
        v10 = -v10;
      v11 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      if ( *(v6 - 5) < 0.0 )
        v11 = -v11;
      *(v7 - 7) = v11;
      *(v7 - 6) = v10;
      *(v7 - 5) = v9;
      *(v7 - 4) = 0.0;
      v12 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      if ( v6[1] < 0.0 )
        v12 = -v12;
      v13 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
      if ( *v6 < 0.0 )
        v13 = -v13;
      v14 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      if ( *(v6 - 1) < 0.0 )
        v14 = -v14;
      *(v7 - 3) = v14;
      *(float *)((char *)v6 + (char *)supportVerticesOut - (char *)vectors) = v13;
      *(v7 - 1) = v12;
      *v7 = 0.0;
      v15 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      if ( v6[5] < 0.0 )
        v15 = -v15;
      v16 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
      if ( v6[4] < 0.0 )
        v16 = -v16;
      v17 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      if ( v6[3] < 0.0 )
        v17 = -v17;
      v7[1] = v17;
      v7[2] = v16;
      v7[3] = v15;
      v7[4] = 0.0;
      v18 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      if ( v6[9] < 0.0 )
        v18 = -v18;
      v19 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
      if ( v6[8] < 0.0 )
        v19 = -v19;
      v20 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      if ( v6[7] < 0.0 )
        v20 = -v20;
      v7[5] = v20;
      v7[6] = v19;
      v7[7] = v18;
      v7[8] = 0.0;
      v6 += 16;
      v7 += 16;
      --v8;
    }
    while ( v8 );
    v4 = supportVerticesOut;
  }
  if ( v5 < numVectors )
  {
    v21 = &v4[v5].mVec128.m128_f32[3];
    v22 = (char *)v4 - (char *)vectors;
    v23 = &vectors[v5].mVec128.m128_f32[1];
    v24 = numVectors - v5;
    do
    {
      v25 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      if ( v23[1] < 0.0 )
        v25 = -v25;
      v26 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
      if ( *v23 < 0.0 )
        v26 = -v26;
      v27 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      if ( *(v23 - 1) < 0.0 )
        v27 = -v27;
      *(v21 - 3) = v27;
      *(float *)((char *)v23 + v22) = v26;
      *(v21 - 1) = v25;
      *v21 = 0.0;
      v23 += 4;
      v21 += 4;
      --v24;
    }
    while ( v24 );
  }
}
