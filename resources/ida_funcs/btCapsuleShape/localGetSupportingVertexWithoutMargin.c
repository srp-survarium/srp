btVector3 *__thiscall btCapsuleShape::localGetSupportingVertexWithoutMargin(
        btCapsuleShape *this,
        btVector3 *result,
        const btVector3 *vec0)
{
  float _X; // xmm1_4
  long double v5; // st7
  int m_upAxis; // ecx
  double v7; // st7
  btCapsuleShape_vtbl *v8; // eax
  double v9; // st7
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  unsigned int v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm0_4
  double v18; // st7
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  unsigned int v22; // xmm2_4
  btVector3 *v23; // eax
  float v24; // [esp+12Ch] [ebp-38h]
  float v25; // [esp+130h] [ebp-34h]
  btVector3 v26; // [esp+134h] [ebp-30h]
  btVector3 v27; // [esp+144h] [ebp-20h] BYREF
  float v28; // [esp+154h] [ebp-10h]
  float v29; // [esp+158h] [ebp-Ch]
  float v30; // [esp+15Ch] [ebp-8h]

  v25 = -9.9999998e17;
  v26.mVec128 = vec0->mVec128;
  _X = (float)((float)(v26.mVec128.m128_f32[2] * v26.mVec128.m128_f32[2])
             + (float)(v26.mVec128.m128_f32[1] * v26.mVec128.m128_f32[1]))
     + (float)(vec0->mVec128.m128_f32[0] * vec0->mVec128.m128_f32[0]);
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  if ( _X >= 0.000099999997 )
  {
    v5 = 1.0 / sqrtf(_X);
    v26.mVec128.m128_f32[0] = v26.mVec128.m128_f32[0] * v5;
    v26.mVec128.m128_f32[1] = v26.mVec128.m128_f32[1] * v5;
    v26.mVec128.m128_f32[2] = v5 * v26.mVec128.m128_f32[2];
  }
  else
  {
    v26.mVec128.m128_u64[0] = (unsigned int)clear_value;
    v26.mVec128.m128_i32[2] = 0;
  }
  m_upAxis = this->m_upAxis;
  v7 = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis];
  v8 = this->__vftable;
  memset(&v27, 0, 12);
  v27.mVec128.m128_f32[m_upAxis] = v7;
  v24 = this->m_implicitShapeDimensions.mVec128.m128_f32[(m_upAxis + 2) % 3];
  v9 = ((double (__thiscall *)(btCapsuleShape *))v8->getMargin)(this);
  v10 = this->m_localScaling.mVec128.m128_f32[0];
  v28 = v26.mVec128.m128_f32[0] * v9;
  v11 = this->m_localScaling.mVec128.m128_f32[2];
  v12 = this->m_localScaling.mVec128.m128_f32[1];
  v29 = v26.mVec128.m128_f32[1] * v9;
  v30 = v9 * v26.mVec128.m128_f32[2];
  v13 = (float)((float)((float)(v10 * v26.mVec128.m128_f32[0]) * v24) + v27.mVec128.m128_f32[0]) - v28;
  *(float *)&v14 = (float)((float)((float)(v11 * v26.mVec128.m128_f32[2]) * v24) + v27.mVec128.m128_f32[2]) - v30;
  v27.mVec128.m128_u64[1] = v14;
  v27.mVec128.m128_f32[1] = (float)((float)((float)(v12 * v26.mVec128.m128_f32[1]) * v24) + v27.mVec128.m128_f32[1])
                          - v29;
  v27.mVec128.m128_f32[0] = v13;
  v15 = (float)((float)(*(float *)&v14 * v26.mVec128.m128_f32[2])
              + (float)(v27.mVec128.m128_f32[1] * v26.mVec128.m128_f32[1]))
      + (float)(v13 * v26.mVec128.m128_f32[0]);
  if ( v15 > -9.9999998e17 )
  {
    v25 = v15;
    *result = (btVector3)v27.mVec128;
  }
  v16 = this->m_upAxis;
  v17 = -this->m_implicitShapeDimensions.mVec128.m128_f32[v16];
  memset(&v27, 0, 12);
  v27.mVec128.m128_f32[v16] = v17;
  v18 = ((double (__thiscall *)(btCapsuleShape *))this->getMargin)(this);
  v19 = this->m_localScaling.mVec128.m128_f32[0];
  v28 = v26.mVec128.m128_f32[0] * v18;
  v20 = this->m_localScaling.mVec128.m128_f32[2];
  v21 = this->m_localScaling.mVec128.m128_f32[1];
  v29 = v26.mVec128.m128_f32[1] * v18;
  v30 = v18 * v26.mVec128.m128_f32[2];
  *(float *)&v22 = (float)((float)((float)(v20 * v26.mVec128.m128_f32[2]) * v24) + v27.mVec128.m128_f32[2]) - v30;
  v27.mVec128.m128_u64[1] = v22;
  v27.mVec128.m128_f32[1] = (float)((float)((float)(v21 * v26.mVec128.m128_f32[1]) * v24) + v27.mVec128.m128_f32[1])
                          - v29;
  v27.mVec128.m128_f32[0] = (float)((float)((float)(v19 * v26.mVec128.m128_f32[0]) * v24) + v27.mVec128.m128_f32[0])
                          - v28;
  v23 = result;
  if ( (float)((float)((float)(*(float *)&v22 * v26.mVec128.m128_f32[2])
                     + (float)(v27.mVec128.m128_f32[1] * v26.mVec128.m128_f32[1]))
             + (float)(v27.mVec128.m128_f32[0] * v26.mVec128.m128_f32[0])) > v25 )
    *result = (btVector3)v27.mVec128;
  return v23;
}
