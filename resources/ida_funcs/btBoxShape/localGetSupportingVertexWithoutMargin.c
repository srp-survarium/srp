btVector3 *__thiscall btBoxShape::localGetSupportingVertexWithoutMargin(
        btBoxShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  btVector3 *v6; // eax

  v3 = this->m_implicitShapeDimensions.mVec128.m128_f32[2];
  if ( vec->mVec128.m128_f32[2] < 0.0 )
    v3 = -v3;
  v4 = this->m_implicitShapeDimensions.mVec128.m128_f32[1];
  if ( vec->mVec128.m128_f32[1] < 0.0 )
    v4 = -v4;
  v5 = this->m_implicitShapeDimensions.mVec128.m128_f32[0];
  if ( vec->mVec128.m128_f32[0] < 0.0 )
    v5 = -v5;
  v6 = result;
  result->mVec128.m128_f32[0] = v5;
  result->mVec128.m128_f32[1] = v4;
  result->mVec128.m128_u64[1] = LODWORD(v3);
  return v6;
}
