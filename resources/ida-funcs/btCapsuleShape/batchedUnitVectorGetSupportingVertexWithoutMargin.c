void __thiscall btCapsuleShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btCapsuleShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  float *v6; // edi
  int m_upAxis; // eax
  double v8; // st7
  btCapsuleShape_vtbl *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  unsigned int v14; // xmm4_4
  float v15; // xmm0_4
  unsigned int v16; // xmm2_4
  float v17; // xmm0_4
  int v18; // eax
  btCapsuleShape_vtbl *v19; // edx
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  unsigned int v24; // xmm1_4
  float v25; // xmm4_4
  unsigned int v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // [esp+11Ch] [ebp-50h]
  float v29; // [esp+120h] [ebp-4Ch]
  int v30; // [esp+124h] [ebp-48h]
  float v31; // [esp+128h] [ebp-44h]
  float v32; // [esp+128h] [ebp-44h]
  float v33; // [esp+12Ch] [ebp-40h]
  float v34; // [esp+130h] [ebp-3Ch]
  float v35; // [esp+134h] [ebp-38h]
  float v36; // [esp+13Ch] [ebp-30h]
  float v37; // [esp+140h] [ebp-2Ch]
  float v38; // [esp+144h] [ebp-28h]
  unsigned __int64 v39; // [esp+14Ch] [ebp-20h]
  unsigned __int64 v40; // [esp+154h] [ebp-18h]
  unsigned __int64 v41; // [esp+15Ch] [ebp-10h]
  unsigned __int64 v42; // [esp+164h] [ebp-8h]

  v28 = this->m_implicitShapeDimensions.mVec128.m128_f32[(this->m_upAxis + 2) % 3];
  if ( numVectors > 0 )
  {
    HIDWORD(v40) = 0;
    HIDWORD(v42) = 0;
    v6 = &vectors->mVec128.m128_f32[2];
    v30 = numVectors;
    do
    {
      m_upAxis = this->m_upAxis;
      v8 = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis];
      v9 = this->__vftable;
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      *(&v33 + m_upAxis) = v8;
      v29 = -9.9999998e17;
      v31 = v9->getMargin(this);
      v10 = *(v6 - 2);
      v11 = this->m_localScaling.mVec128.m128_f32[1] * *(v6 - 1);
      v12 = *(v6 - 1) * v31;
      v13 = *v6 * v31;
      *(float *)&v14 = (float)((float)((float)(v10 * this->m_localScaling.mVec128.m128_f32[0]) * v28) + v33)
                     - (float)(v10 * v31);
      v15 = *v6 * (float)((float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v6) * v28) + v35) - v13);
      *(float *)&v40 = (float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v6) * v28) + v35) - v13;
      *(float *)&v16 = (float)((float)(v11 * v28) + v34) - v12;
      v17 = (float)(v15 + (float)(*(v6 - 1) * *(float *)&v16)) + (float)(v10 * *(float *)&v14);
      v39 = __PAIR64__(v16, v14);
      if ( v17 > -9.9999998e17 )
      {
        v29 = v17;
        supportVerticesOut->mVec128.m128_u64[0] = v39;
        supportVerticesOut->mVec128.m128_u64[1] = v40;
      }
      v18 = this->m_upAxis;
      v19 = this->__vftable;
      v36 = 0.0;
      v37 = 0.0;
      v38 = 0.0;
      *(&v36 + v18) = -this->m_implicitShapeDimensions.mVec128.m128_f32[v18];
      v32 = v19->getMargin(this);
      v20 = *(v6 - 2);
      v21 = this->m_localScaling.mVec128.m128_f32[1] * *(v6 - 1);
      v22 = *(v6 - 1) * v32;
      v23 = *v6 * v32;
      *(float *)&v24 = (float)((float)((float)(v20 * this->m_localScaling.mVec128.m128_f32[0]) * v28) + v36)
                     - (float)(v20 * v32);
      v25 = *v6 * (float)((float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v6) * v28) + v38) - v23);
      *(float *)&v42 = (float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v6) * v28) + v38) - v23;
      *(float *)&v26 = (float)((float)(v21 * v28) + v37) - v22;
      v27 = (float)(v25 + (float)(*(v6 - 1) * *(float *)&v26)) + (float)(v20 * *(float *)&v24);
      v41 = __PAIR64__(v26, v24);
      if ( v27 > v29 )
      {
        supportVerticesOut->mVec128.m128_u64[0] = v41;
        supportVerticesOut->mVec128.m128_u64[1] = v42;
      }
      v6 += 4;
      ++supportVerticesOut;
      --v30;
    }
    while ( v30 );
  }
}
