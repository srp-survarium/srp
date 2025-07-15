void __thiscall btCapsuleShape::batchedUnitVectorGetSupportingVertexWithoutMargin(
        btCapsuleShape *this,
        const btVector3 *vectors,
        btVector3 *supportVerticesOut,
        int numVectors)
{
  float *v5; // esi
  int m_upAxis; // eax
  double v7; // st7
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // xmm2_4
  float v13; // xmm0_4
  int v14; // eax
  float v15; // xmm3_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  int v19; // xmm2_4
  int v20; // xmm0_4
  float v21; // xmm4_4
  bool v22; // zf
  float v23; // [esp+18h] [ebp-58h]
  float v25; // [esp+20h] [ebp-50h]
  float v26; // [esp+20h] [ebp-50h]
  int *v27; // [esp+24h] [ebp-4Ch]
  float v28; // [esp+28h] [ebp-48h]
  int v29; // [esp+2Ch] [ebp-44h]
  float v30; // [esp+30h] [ebp-40h]
  float v31; // [esp+34h] [ebp-3Ch]
  float v32; // [esp+38h] [ebp-38h]
  float v33; // [esp+40h] [ebp-30h]
  float v34; // [esp+44h] [ebp-2Ch]
  float v35; // [esp+48h] [ebp-28h]
  int v36; // [esp+50h] [ebp-20h]
  float v37; // [esp+54h] [ebp-1Ch]
  float v38; // [esp+58h] [ebp-18h]
  int v39; // [esp+5Ch] [ebp-14h]
  int v40; // [esp+60h] [ebp-10h]
  int v41; // [esp+64h] [ebp-Ch]
  float v42; // [esp+68h] [ebp-8h]
  int v43; // [esp+6Ch] [ebp-4h]

  v23 = this->m_implicitShapeDimensions.mVec128.m128_f32[(this->m_upAxis + 2) % 3];
  if ( numVectors > 0 )
  {
    v5 = &vectors->mVec128.m128_f32[2];
    v39 = 0;
    v43 = 0;
    v27 = &vectors->mVec128.m128_i32[2];
    v29 = numVectors;
    do
    {
      m_upAxis = this->m_upAxis;
      v7 = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis];
      v30 = 0.0;
      v31 = 0.0;
      v32 = 0.0;
      *(&v30 + m_upAxis) = v7;
      v28 = FLOAT_N9_9999998e17;
      v25 = this->getMargin(this);
      v8 = *v5;
      v9 = *(v5 - 2);
      v10 = (float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v5) * v23) + v32;
      v37 = (float)((float)((float)(this->m_localScaling.mVec128.m128_f32[1] * *(v5 - 1)) * v23) + v31)
          - (float)(*(v5 - 1) * v25);
      v11 = (float)((float)(v9 * this->m_localScaling.mVec128.m128_f32[0]) * v23) + v30;
      v38 = v10 - (float)(v8 * v25);
      *(float *)&v12 = v11 - (float)(v9 * v25);
      v13 = (float)((float)(v8 * v38) + (float)(*(v5 - 1) * v37)) + (float)(v9 * *(float *)&v12);
      v36 = v12;
      if ( v13 > -9.9999998e17 )
      {
        supportVerticesOut->mVec128.m128_i32[0] = v36;
        supportVerticesOut->mVec128.m128_f32[1] = v37;
        supportVerticesOut->mVec128.m128_f32[2] = v38;
        supportVerticesOut->mVec128.m128_i32[3] = v39;
        v5 = (float *)v27;
        v28 = v13;
      }
      v14 = this->m_upAxis;
      v33 = 0.0;
      v34 = 0.0;
      v35 = 0.0;
      *((_DWORD *)&v33 + v14) = this->m_implicitShapeDimensions.mVec128.m128_i32[v14] ^ _mask__NegFloat_;
      v26 = this->getMargin(this);
      v15 = *(v5 - 2);
      v16 = *v5;
      v17 = (float)((float)(this->m_localScaling.mVec128.m128_f32[1] * *(v5 - 1)) * v23) + v34;
      v18 = *(v5 - 1) * v26;
      *(float *)&v19 = (float)((float)((float)(v15 * this->m_localScaling.mVec128.m128_f32[0]) * v23) + v33)
                     - (float)(v15 * v26);
      v42 = (float)((float)((float)(this->m_localScaling.mVec128.m128_f32[2] * *v5) * v23) + v35) - (float)(*v5 * v26);
      *(float *)&v20 = v17 - v18;
      v21 = (float)((float)(v16 * v42) + (float)(*(v5 - 1) * *(float *)&v20)) + (float)(v15 * *(float *)&v19);
      v40 = v19;
      v41 = v20;
      if ( v21 > v28 )
      {
        supportVerticesOut->mVec128.m128_i32[0] = v40;
        supportVerticesOut->mVec128.m128_i32[1] = v41;
        supportVerticesOut->mVec128.m128_f32[2] = v42;
        supportVerticesOut->mVec128.m128_i32[3] = v43;
        v5 = (float *)v27;
      }
      ++supportVerticesOut;
      v5 += 4;
      v22 = v29-- == 1;
      v27 = (int *)v5;
    }
    while ( !v22 );
  }
}
