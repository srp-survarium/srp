btVector3 *__thiscall btCapsuleShape::localGetSupportingVertexWithoutMargin(
        btCapsuleShape *this,
        btVector3 *result,
        const btVector3 *vec0)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  int m_upAxis; // ecx
  double v10; // st7
  btCapsuleShape_vtbl *v11; // eax
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  int v19; // eax
  double v20; // st7
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v25; // [esp+18h] [ebp-38h]
  float v26; // [esp+1Ch] [ebp-34h]
  float v27; // [esp+20h] [ebp-30h]
  float v28; // [esp+24h] [ebp-2Ch]
  float v29; // [esp+28h] [ebp-28h]
  btVector3 v30; // [esp+30h] [ebp-20h] BYREF
  float v31; // [esp+40h] [ebp-10h]
  float v32; // [esp+44h] [ebp-Ch]
  float v33; // [esp+48h] [ebp-8h]

  v26 = FLOAT_N9_9999998e17;
  v4 = vec0->mVec128.m128_f32[2];
  v5 = vec0->mVec128.m128_f32[1];
  v6 = vec0->mVec128.m128_f32[0];
  v7 = (float)((float)(v4 * v4) + (float)(v5 * v5)) + (float)(v6 * v6);
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  if ( v7 >= 0.000099999997 )
  {
    v8 = fsqrt(v7);
    v27 = v6 * (float)(s_bm_current_air_resistance / v8);
    v28 = v5 * (float)(s_bm_current_air_resistance / v8);
    v29 = v4 * (float)(s_bm_current_air_resistance / v8);
  }
  else
  {
    v27 = s_bm_current_air_resistance;
    v28 = 0.0;
    v29 = 0.0;
  }
  m_upAxis = this->m_upAxis;
  v10 = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis];
  v11 = this->__vftable;
  memset(&v30, 0, 12);
  v30.mVec128.m128_f32[m_upAxis] = v10;
  v25 = this->m_implicitShapeDimensions.mVec128.m128_f32[(m_upAxis + 2) % 3];
  v12 = ((double (__thiscall *)(btCapsuleShape *))v11->getMargin)(this);
  v13 = this->m_localScaling.mVec128.m128_f32[1];
  v31 = v27 * v12;
  v14 = this->m_localScaling.mVec128.m128_f32[2];
  v15 = this->m_localScaling.mVec128.m128_f32[0];
  v32 = v28 * v12;
  v33 = v12 * v29;
  v16 = (float)((float)((float)(v14 * v29) * v25) + v30.mVec128.m128_f32[2]) - v33;
  v17 = (float)((float)((float)(v13 * v28) * v25) + v30.mVec128.m128_f32[1]) - v32;
  v18 = (float)((float)((float)(v15 * v27) * v25) + v30.mVec128.m128_f32[0]) - v31;
  v30.mVec128.m128_u64[1] = LODWORD(v16);
  v30.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v17), LODWORD(v18));
  if ( (float)((float)((float)(v16 * v29) + (float)(v17 * v28)) + (float)(v18 * v27)) > -9.9999998e17 )
  {
    *result = (btVector3)v30.mVec128;
    v26 = (float)((float)(v16 * v29) + (float)(v17 * v28)) + (float)(v18 * v27);
  }
  v19 = this->m_upAxis;
  memset(&v30, 0, 12);
  v30.mVec128.m128_i32[v19] = this->m_implicitShapeDimensions.mVec128.m128_i32[v19] ^ _mask__NegFloat_;
  v20 = ((double (__thiscall *)(btCapsuleShape *))this->getMargin)(this);
  v21 = this->m_localScaling.mVec128.m128_f32[0];
  v31 = v27 * v20;
  v22 = this->m_localScaling.mVec128.m128_f32[2];
  v23 = this->m_localScaling.mVec128.m128_f32[1];
  v32 = v28 * v20;
  v33 = v20 * v29;
  v30.mVec128.m128_f32[2] = (float)((float)((float)(v22 * v29) * v25) + v30.mVec128.m128_f32[2]) - v33;
  v30.mVec128.m128_f32[1] = (float)((float)((float)(v23 * v28) * v25) + v30.mVec128.m128_f32[1]) - v32;
  v30.mVec128.m128_f32[0] = (float)((float)((float)(v21 * v27) * v25) + v30.mVec128.m128_f32[0]) - v31;
  v30.mVec128.m128_i32[3] = 0;
  if ( (float)((float)((float)(v30.mVec128.m128_f32[2] * v29) + (float)(v30.mVec128.m128_f32[1] * v28))
             + (float)(v30.mVec128.m128_f32[0] * v27)) > v26 )
    *result = (btVector3)v30.mVec128;
  return result;
}
