void __thiscall btBoxShape::getAabb(btBoxShape *this, const btTransform *t, btVector3 *aabbMin, btVector3 *aabbMax)
{
  double v5; // st7
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // [esp+10h] [ebp-44h]
  float v12; // [esp+14h] [ebp-40h]
  float v13; // [esp+18h] [ebp-3Ch]
  float v14; // [esp+1Ch] [ebp-38h]
  float v15; // [esp+20h] [ebp-34h]
  float v16; // [esp+24h] [ebp-30h]
  float v17; // [esp+28h] [ebp-2Ch]
  float v18; // [esp+2Ch] [ebp-28h]
  float v19; // [esp+30h] [ebp-24h]
  float v20; // [esp+34h] [ebp-20h]
  unsigned __int64 v21; // [esp+34h] [ebp-20h]
  float v22; // [esp+38h] [ebp-1Ch]
  float v23; // [esp+3Ch] [ebp-18h]
  unsigned __int64 v24; // [esp+44h] [ebp-10h]

  v5 = ((double (__thiscall *)(btBoxShape *))this->getMargin)(this);
  v20 = this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v5;
  v22 = this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v5;
  v23 = v5 + this->m_implicitShapeDimensions.mVec128.m128_f32[2];
  v18 = fabsf(t->m_basis.m_el[2].mVec128.m128_f32[2]);
  v17 = fabsf(t->m_basis.m_el[2].mVec128.m128_f32[1]);
  v19 = fabsf(t->m_basis.m_el[2].mVec128.m128_f32[0]);
  v14 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[2]);
  v16 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[1]);
  v15 = fabsf(t->m_basis.m_el[1].mVec128.m128_f32[0]);
  v12 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[2]);
  v11 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[1]);
  v13 = fabsf(t->m_basis.m_el[0].mVec128.m128_f32[0]);
  v24 = t->m_origin.mVec128.m128_u64[0];
  v6 = (float)((float)(v22 * v11) + (float)(v23 * v12)) + (float)(v13 * v20);
  v7 = (float)((float)(v23 * v14) + (float)(v15 * v20)) + (float)(v22 * v16);
  v8 = (float)((float)(v22 * v17) + (float)(v23 * v18)) + (float)(v20 * v19);
  *(float *)&v21 = *(float *)&v24 - v6;
  v9 = t->m_origin.mVec128.m128_f32[1];
  *((float *)&v21 + 1) = *((float *)&v24 + 1) - v7;
  v10 = t->m_origin.mVec128.m128_f32[2];
  aabbMin->mVec128.m128_u64[0] = v21;
  aabbMin->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v10 - v8);
  *(float *)&v21 = *(float *)&v24 + v6;
  *((float *)&v21 + 1) = v9 + v7;
  aabbMax->mVec128.m128_u64[0] = v21;
  aabbMax->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v10 + v8);
}
