void __thiscall btBoxShape::setLocalScaling(btCapsuleShape *this, const btVector3 *scaling)
{
  unsigned int v3; // xmm2_4
  float v4; // [esp+98h] [ebp-28h]
  float v5; // [esp+9Ch] [ebp-24h]
  float v6; // [esp+A0h] [ebp-20h]
  unsigned __int64 v7; // [esp+A0h] [ebp-20h]
  float v8; // [esp+A4h] [ebp-1Ch]
  float v9; // [esp+A8h] [ebp-18h]
  float v10; // [esp+B0h] [ebp-10h]

  v5 = this->getMargin(this);
  v4 = this->getMargin(this);
  v10 = this->getMargin(this);
  v6 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v10) / this->m_localScaling.mVec128.m128_f32[0];
  v8 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v4) / this->m_localScaling.mVec128.m128_f32[1];
  v9 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[2] + v5) / this->m_localScaling.mVec128.m128_f32[2];
  btConvexInternalShape::setLocalScaling(this, scaling);
  *(float *)&v3 = (float)(this->m_localScaling.mVec128.m128_f32[2] * v9) - v5;
  *(float *)&v7 = (float)(this->m_localScaling.mVec128.m128_f32[0] * v6) - v10;
  *((float *)&v7 + 1) = (float)(this->m_localScaling.mVec128.m128_f32[1] * v8) - v4;
  this->m_implicitShapeDimensions.mVec128.m128_u64[0] = v7;
  this->m_implicitShapeDimensions.mVec128.m128_u64[1] = v3;
}
