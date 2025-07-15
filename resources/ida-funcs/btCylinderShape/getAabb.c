void __thiscall btCylinderShape::getAabb(
        btCylinderShape *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  double v5; // st7
  double v6; // st7
  int v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  unsigned int v14; // xmm0_4
  const float *v15; // [esp+0h] [ebp-80h]
  float v16; // [esp+Ch] [ebp-74h] BYREF
  int v17; // [esp+10h] [ebp-70h] BYREF
  int v18; // [esp+14h] [ebp-6Ch] BYREF
  int v19; // [esp+18h] [ebp-68h] BYREF
  int v20; // [esp+1Ch] [ebp-64h] BYREF
  int v21; // [esp+20h] [ebp-60h] BYREF
  int v22; // [esp+24h] [ebp-5Ch] BYREF
  int v23; // [esp+28h] [ebp-58h] BYREF
  btMatrix3x3 v24; // [esp+2Ch] [ebp-54h] BYREF
  float v25; // [esp+60h] [ebp-20h]
  float v26; // [esp+64h] [ebp-1Ch]
  float v27; // [esp+68h] [ebp-18h]
  float v28; // [esp+70h] [ebp-10h]
  float v29; // [esp+74h] [ebp-Ch]
  float v30; // [esp+78h] [ebp-8h]

  v16 = this->getMargin(this);
  v5 = this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v16;
  v24.m_el[0].mVec128.m128_f32[3] = this->m_implicitShapeDimensions.mVec128.m128_f32[2] + v16;
  v24.m_el[0].mVec128.m128_f32[1] = v5;
  v6 = this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v16;
  LODWORD(v16) = t->m_basis.m_el[2].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v7 = t->m_basis.m_el[2].mVec128.m128_i32[1];
  v24.m_el[0].mVec128.m128_f32[2] = v6;
  v17 = v7 & _mask__AbsFloat_;
  v18 = t->m_basis.m_el[2].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v19 = t->m_basis.m_el[1].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v20 = t->m_basis.m_el[1].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v21 = t->m_basis.m_el[1].mVec128.m128_i32[0] & _mask__AbsFloat_;
  v22 = t->m_basis.m_el[0].mVec128.m128_i32[2] & _mask__AbsFloat_;
  v23 = t->m_basis.m_el[0].mVec128.m128_i32[1] & _mask__AbsFloat_;
  v24.m_el[0].mVec128.m128_i32[0] = t->m_basis.m_el[0].mVec128.m128_i32[0] & _mask__AbsFloat_;
  btMatrix3x3::setValue(
    &v24,
    (int)&v24.m_el[2].mVec128.m128_i32[1],
    (float *)&v23,
    (float *)&v22,
    (float *)&v21,
    (float *)&v20,
    (float *)&v19,
    (float *)&v18,
    (float *)&v17,
    &v16,
    v15);
  *(unsigned __int64 *)((char *)v24.m_el[1].mVec128.m128_u64 + 4) = t->m_origin.mVec128.m128_u64[0];
  v24.m_el[1].mVec128.m128_i32[3] = t->m_origin.mVec128.m128_i32[2];
  v8 = (float)((float)(v24.m_el[2].mVec128.m128_f32[3] * v24.m_el[0].mVec128.m128_f32[3])
             + (float)(v24.m_el[2].mVec128.m128_f32[2] * v24.m_el[0].mVec128.m128_f32[2]))
     + (float)(v24.m_el[2].mVec128.m128_f32[1] * v24.m_el[0].mVec128.m128_f32[1]);
  v9 = v24.m_el[1].mVec128.m128_f32[1];
  v10 = v24.m_el[1].mVec128.m128_f32[2];
  v11 = (float)((float)(v27 * v24.m_el[0].mVec128.m128_f32[3]) + (float)(v26 * v24.m_el[0].mVec128.m128_f32[2]))
      + (float)(v25 * v24.m_el[0].mVec128.m128_f32[1]);
  v12 = (float)((float)(v30 * v24.m_el[0].mVec128.m128_f32[3]) + (float)(v29 * v24.m_el[0].mVec128.m128_f32[2]))
      + (float)(v28 * v24.m_el[0].mVec128.m128_f32[1]);
  v24.m_el[0].mVec128.m128_f32[2] = v24.m_el[1].mVec128.m128_f32[2] - v11;
  v13 = v24.m_el[1].mVec128.m128_f32[3] - v12;
  *(float *)&v14 = v12 + v24.m_el[1].mVec128.m128_f32[3];
  v24.m_el[0].mVec128.m128_f32[3] = v13;
  v24.m_el[1].mVec128.m128_i32[0] = 0;
  aabbMin->mVec128.m128_f32[0] = v24.m_el[1].mVec128.m128_f32[1] - v8;
  *(unsigned __int64 *)((char *)aabbMin->mVec128.m128_u64 + 4) = v24.m_el[0].mVec128.m128_u64[1];
  aabbMin->mVec128.m128_i32[3] = v24.m_el[1].mVec128.m128_i32[0];
  *(unsigned __int64 *)((char *)&v24.m_el[0].mVec128.m128_u64[1] + 4) = v14;
  v24.m_el[0].mVec128.m128_f32[2] = v10 + v11;
  aabbMax->mVec128.m128_f32[0] = v9 + v8;
  *(unsigned __int64 *)((char *)aabbMax->mVec128.m128_u64 + 4) = v24.m_el[0].mVec128.m128_u64[1];
  aabbMax->mVec128.m128_i32[3] = v24.m_el[1].mVec128.m128_i32[0];
}
