btVector3 *__thiscall btBoxShape::localGetSupportingVertex(btBoxShape *this, btVector3 *result, const btVector3 *vec)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  btVector3 *v7; // eax
  float v8; // [esp+18h] [ebp-18h]
  float v9; // [esp+1Ch] [ebp-14h]
  btVector3 v10; // [esp+20h] [ebp-10h]
  float v11; // [esp+20h] [ebp-10h]
  float v12; // [esp+24h] [ebp-Ch]
  float v13; // [esp+28h] [ebp-8h]

  v10.mVec128 = (__m128)this->m_implicitShapeDimensions;
  v9 = ((double (*)(void))this->getMargin)();
  v8 = this->getMargin(this);
  v11 = ((double (__thiscall *)(btBoxShape *))this->getMargin)(this) + v10.mVec128.m128_f32[0];
  v12 = v10.mVec128.m128_f32[1] + v8;
  v13 = v10.mVec128.m128_f32[2] + v9;
  v4 = v13;
  if ( vec->mVec128.m128_f32[2] < 0.0 )
    v4 = -v13;
  v5 = v12;
  if ( vec->mVec128.m128_f32[1] < 0.0 )
    v5 = -v12;
  v6 = v11;
  if ( vec->mVec128.m128_f32[0] < 0.0 )
    v6 = -v11;
  v7 = result;
  result->mVec128.m128_f32[0] = v6;
  result->mVec128.m128_f32[1] = v5;
  result->mVec128.m128_u64[1] = LODWORD(v4);
  return v7;
}
