void __thiscall btCylinderShapeX::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btCylinderShapeX *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int v4; // ebx
  float *v6; // esi
  long double v7; // st7
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  unsigned __int64 v11; // [esp+14h] [ebp-20h]
  btCylinderShapeX *v12; // [esp+1Ch] [ebp-18h]
  float v13; // [esp+20h] [ebp-14h]
  unsigned __int64 v14; // [esp+24h] [ebp-10h]
  unsigned __int64 v15; // [esp+2Ch] [ebp-8h]

  v4 = numVectors;
  v12 = this;
  if ( numVectors > 0 )
  {
    v6 = &vectors->mVec128.m128_f32[2];
    while ( 1 )
    {
      v11 = this->m_implicitShapeDimensions.mVec128.m128_u64[0];
      v7 = sqrtf((float)(*v6 * *v6) + (float)(*(v6 - 1) * *(v6 - 1)));
      v13 = v7;
      if ( v7 == 0.0 )
      {
        v9 = 0.0;
        HIDWORD(v14) = HIDWORD(v11);
        v10 = *(float *)&v11;
        if ( *(v6 - 2) < 0.0 )
          v10 = -*(float *)&v11;
        *(float *)&v14 = v10;
      }
      else
      {
        *((float *)&v14 + 1) = *(v6 - 1) * (float)(*((float *)&v11 + 1) / v13);
        v8 = *(float *)&v11;
        if ( *(v6 - 2) < 0.0 )
          v8 = -*(float *)&v11;
        *(float *)&v14 = v8;
        v9 = *v6 * (float)(*((float *)&v11 + 1) / v13);
      }
      supportVerticesOut->mVec128.m128_u64[0] = v14;
      *(float *)&v15 = v9;
      supportVerticesOut->mVec128.m128_u64[1] = v15;
      v6 += 4;
      ++supportVerticesOut;
      if ( !--v4 )
        break;
      this = v12;
    }
  }
}
