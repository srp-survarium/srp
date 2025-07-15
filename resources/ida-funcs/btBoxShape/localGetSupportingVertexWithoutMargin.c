btVector3 *__thiscall btBoxShape::localGetSupportingVertexWithoutMargin(
        btBoxShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  int v3; // xmm3_4
  int v4; // xmm2_4
  int v5; // xmm0_4
  btVector3 *v6; // eax

  v3 = this->m_implicitShapeDimensions.mVec128.m128_i32[2];
  if ( vec->mVec128.m128_f32[2] < 0.0 )
    v3 ^= _mask__NegFloat_;
  v4 = this->m_implicitShapeDimensions.mVec128.m128_i32[1];
  if ( vec->mVec128.m128_f32[1] < 0.0 )
    v4 ^= _mask__NegFloat_;
  v5 = this->m_implicitShapeDimensions.mVec128.m128_i32[0];
  if ( vec->mVec128.m128_f32[0] < 0.0 )
    v5 ^= _mask__NegFloat_;
  v6 = result;
  result->mVec128.m128_i32[0] = v5;
  result->mVec128.m128_i32[1] = v4;
  result->mVec128.m128_u64[1] = (unsigned int)v3;
  return v6;
}
