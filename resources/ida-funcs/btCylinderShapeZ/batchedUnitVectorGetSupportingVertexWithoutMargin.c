void __thiscall btCylinderShapeZ::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btCylinderShapeZ *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  int v4; // ebx
  float *v6; // edi
  long double v7; // st7
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // [esp+10h] [ebp-24h]
  float v12; // [esp+14h] [ebp-20h]
  btCylinderShapeZ *v13; // [esp+18h] [ebp-1Ch]
  float v14; // [esp+1Ch] [ebp-18h]
  float v15; // [esp+20h] [ebp-14h]
  unsigned __int64 v16; // [esp+24h] [ebp-10h]
  unsigned __int64 v17; // [esp+2Ch] [ebp-8h]

  v4 = numVectors;
  v13 = this;
  if ( numVectors > 0 )
  {
    v6 = &vectors->mVec128.m128_f32[2];
    while ( 1 )
    {
      v12 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
      v11 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
      v15 = *(v6 - 2);
      v7 = sqrtf((float)(v15 * v15) + (float)(*(v6 - 1) * *(v6 - 1)));
      v14 = v7;
      if ( v7 == 0.0 )
      {
        v9 = 0.0;
        *(float *)&v16 = v12;
        v10 = v11;
        if ( *v6 < 0.0 )
          v10 = -v11;
        *(float *)&v17 = v10;
      }
      else
      {
        *(float *)&v16 = v15 * (float)(v12 / v14);
        v8 = v11;
        if ( *v6 < 0.0 )
          v8 = -v11;
        *(float *)&v17 = v8;
        v9 = *(v6 - 1) * (float)(v12 / v14);
      }
      *((float *)&v16 + 1) = v9;
      supportVerticesOut->mVec128.m128_u64[0] = v16;
      supportVerticesOut->mVec128.m128_u64[1] = v17;
      v6 += 4;
      ++supportVerticesOut;
      if ( !--v4 )
        break;
      this = v13;
    }
  }
}
