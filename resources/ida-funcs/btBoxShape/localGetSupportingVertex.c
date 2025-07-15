btVector3 *__thiscall btBoxShape::localGetSupportingVertex(btBoxShape *this, btVector3 *result, const btVector3 *vec)
{
  float v4; // xmm3_4
  int v5; // xmm2_4
  int v6; // xmm0_4
  btVector3 *v7; // eax
  float v8; // [esp+18h] [ebp-18h]
  float v9; // [esp+1Ch] [ebp-14h]
  unsigned __int64 v10; // [esp+20h] [ebp-10h]
  float v11; // [esp+20h] [ebp-10h]
  float v12; // [esp+24h] [ebp-Ch]
  float v13; // [esp+28h] [ebp-8h]
  float v14; // [esp+28h] [ebp-8h]

  v10 = this->m_implicitShapeDimensions.mVec128.m128_u64[0];
  v13 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
  v9 = ((double (*)(void))this->getMargin)();
  v8 = this->getMargin(this);
  v11 = ((double (__thiscall *)(btBoxShape *))this->getMargin)(this) + *(float *)&v10;
  v12 = *((float *)&v10 + 1) + v8;
  v14 = v13 + v9;
  v4 = v14;
  if ( vec->mVec128.m128_f32[2] < 0.0 )
    LODWORD(v4) = LODWORD(v14) ^ _mask__NegFloat_;
  v5 = LODWORD(v12);
  if ( vec->mVec128.m128_f32[1] < 0.0 )
    v5 = LODWORD(v12) ^ _mask__NegFloat_;
  v6 = LODWORD(v11);
  if ( vec->mVec128.m128_f32[0] < 0.0 )
    v6 = LODWORD(v11) ^ _mask__NegFloat_;
  v7 = result;
  result->mVec128.m128_i32[0] = v6;
  result->mVec128.m128_i32[1] = v5;
  result->mVec128.m128_u64[1] = LODWORD(v4);
  return v7;
}
