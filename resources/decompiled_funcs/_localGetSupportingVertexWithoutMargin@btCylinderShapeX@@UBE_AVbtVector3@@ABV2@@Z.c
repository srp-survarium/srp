btVector3 *__thiscall btCylinderShapeX::localGetSupportingVertexWithoutMargin(
        btCylinderShapeX *this,
        btVector3 *result,
        const btVector3 *vec)
{
  long double v3; // st7
  btVector3 *v4; // eax
  float v5; // xmm0_4
  bool v6; // cc
  float v7; // xmm0_4
  unsigned __int64 v8; // [esp+8h] [ebp-Ch]
  float v9; // [esp+10h] [ebp-4h]

  v8 = this->m_implicitShapeDimensions.mVec128.m128_u64[0];
  v3 = sqrtf(
         (float)(vec->mVec128.m128_f32[1] * vec->mVec128.m128_f32[1])
       + (float)(vec->mVec128.m128_f32[2] * vec->mVec128.m128_f32[2]));
  v9 = v3;
  v4 = result;
  if ( v3 == 0.0 )
  {
    v6 = vec->mVec128.m128_f32[0] >= 0.0;
    result->mVec128.m128_i32[1] = HIDWORD(v8);
    v7 = *(float *)&v8;
    if ( !v6 )
      v7 = -*(float *)&v8;
    result->mVec128.m128_f32[0] = v7;
    result->mVec128.m128_i32[2] = 0;
  }
  else
  {
    result->mVec128.m128_f32[1] = vec->mVec128.m128_f32[1] * (float)(*((float *)&v8 + 1) / v9);
    v5 = *(float *)&v8;
    if ( vec->mVec128.m128_f32[0] < 0.0 )
      v5 = -*(float *)&v8;
    result->mVec128.m128_f32[0] = v5;
    result->mVec128.m128_f32[2] = vec->mVec128.m128_f32[2] * (float)(*((float *)&v8 + 1) / v9);
  }
  return v4;
}
