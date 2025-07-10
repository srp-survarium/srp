void __thiscall btCapsuleShape::getAabb(
        btCapsuleShape *this,
        const btTransform *t,
        btVector3 *aabbMin,
        btVector3 *aabbMax)
{
  int m_upAxis; // ecx
  float v6; // xmm1_4
  float (__thiscall *getMargin)(struct btCapsuleShape *); // edx
  double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float _X; // [esp+2Ch] [ebp-54h]
  float v16; // [esp+3Ch] [ebp-44h]
  float v17; // [esp+3Ch] [ebp-44h]
  float v18; // [esp+40h] [ebp-40h]
  float v19; // [esp+40h] [ebp-40h]
  float v20; // [esp+44h] [ebp-3Ch]
  float v21; // [esp+48h] [ebp-38h]
  float v22; // [esp+4Ch] [ebp-34h]
  float v23; // [esp+50h] [ebp-30h]
  float v24; // [esp+54h] [ebp-2Ch]
  float v25; // [esp+58h] [ebp-28h]
  float v26; // [esp+5Ch] [ebp-24h]
  unsigned __int64 v27; // [esp+60h] [ebp-20h]
  __int64 v28; // [esp+68h] [ebp-18h]
  btVector3 v29; // [esp+70h] [ebp-10h]

  m_upAxis = this->m_upAxis;
  v6 = this->m_implicitShapeDimensions.mVec128.m128_f32[m_upAxis];
  getMargin = this->getMargin;
  LODWORD(v27) = this->m_implicitShapeDimensions.mVec128.m128_i32[(m_upAxis + 2) % 3];
  HIDWORD(v27) = v27;
  LODWORD(v28) = v27;
  *((float *)&v27 + m_upAxis) = v6 + *(float *)&v27;
  v18 = getMargin(this);
  v16 = this->getMargin(this);
  v29.mVec128.m128_f32[0] = this->getMargin(this);
  v8 = t->m_basis.m_el[2].mVec128.m128_f32[2];
  *(float *)&v27 = v29.mVec128.m128_f32[0] + *(float *)&v27;
  *((float *)&v27 + 1) = *((float *)&v27 + 1) + v16;
  _X = v8;
  *(float *)&v28 = *(float *)&v28 + v18;
  v24 = fabsf(_X);
  v25 = fabsf(t->m_basis.m_el[2].mVec128.m128_f32[1]);
  v26 = fabsf(t->m_basis.m_el[2].mVec128.m128_f32[0]);
  v22 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[2]);
  v21 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[1]);
  v23 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[0]);
  v17 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[2]);
  v19 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[1]);
  v20 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[0]);
  v29.mVec128 = (__m128)t->m_origin;
  v9 = (float)((float)(*((float *)&v27 + 1) * v19) + (float)(*(float *)&v28 * v17)) + (float)(v20 * *(float *)&v27);
  v10 = (float)((float)(*(float *)&v28 * v24) + (float)(*((float *)&v27 + 1) * v25)) + (float)(v26 * *(float *)&v27);
  v11 = v29.mVec128.m128_f32[0];
  v12 = (float)((float)(*((float *)&v27 + 1) * v21) + (float)(*(float *)&v28 * v22)) + (float)(v23 * *(float *)&v27);
  *(float *)&v27 = v29.mVec128.m128_f32[0] - v9;
  v13 = v29.mVec128.m128_f32[1];
  *((float *)&v27 + 1) = v29.mVec128.m128_f32[1] - v12;
  v14 = v29.mVec128.m128_f32[2];
  *(float *)&v28 = v29.mVec128.m128_f32[2] - v10;
  aabbMin->mVec128.m128_u64[0] = v27;
  aabbMin->mVec128.m128_u64[1] = (unsigned int)v28;
  *(float *)&v27 = v11 + v9;
  *((float *)&v27 + 1) = v13 + v12;
  aabbMax->mVec128.m128_u64[0] = v27;
  aabbMax->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v14 + v10);
}
