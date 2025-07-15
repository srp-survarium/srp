void __thiscall btBoxShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btBoxShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int *v4; // eax
  float *v5; // edx
  int v6; // edi
  int v7; // xmm3_4
  int v8; // xmm1_4
  int v9; // xmm0_4

  if ( numVectors > 0 )
  {
    v4 = &supportVerticesOut->mVec128.m128_i32[3];
    v5 = &vectors->mVec128.m128_f32[1];
    v6 = numVectors;
    do
    {
      v7 = this->m_implicitShapeDimensions.mVec128.m128_i32[2];
      if ( v5[1] < 0.0 )
        v7 ^= _mask__NegFloat_;
      v8 = this->m_implicitShapeDimensions.mVec128.m128_i32[1];
      if ( *v5 < 0.0 )
        v8 ^= _mask__NegFloat_;
      v9 = this->m_implicitShapeDimensions.mVec128.m128_i32[0];
      if ( *(v5 - 1) < 0.0 )
        v9 ^= _mask__NegFloat_;
      *(v4 - 3) = v9;
      *(_DWORD *)((char *)v5 + (char *)supportVerticesOut - (char *)vectors) = v8;
      *(v4 - 1) = v7;
      *v4 = 0;
      v5 += 4;
      v4 += 4;
      --v6;
    }
    while ( v6 );
  }
}
