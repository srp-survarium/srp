void __thiscall btBoxShape::setLocalScaling(btCylinderShape *this, const btVector3 *scaling)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // [esp+8h] [ebp-18h]
  float v7; // [esp+Ch] [ebp-14h]
  float v8; // [esp+10h] [ebp-10h]
  float v9; // [esp+14h] [ebp-Ch]
  float v10; // [esp+18h] [ebp-8h]

  v7 = this->getMargin(this);
  v6 = this->getMargin(this);
  v8 = this->getMargin(this);
  v3 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[0] + v8) / this->m_localScaling.mVec128.m128_f32[0];
  v4 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[1] + v6) / this->m_localScaling.mVec128.m128_f32[1];
  v5 = (float)(this->m_implicitShapeDimensions.mVec128.m128_f32[2] + v7) / this->m_localScaling.mVec128.m128_f32[2];
  btConvexInternalShape::setLocalScaling(this, scaling);
  v9 = (float)(this->m_localScaling.mVec128.m128_f32[1] * v4) - v6;
  v10 = (float)(this->m_localScaling.mVec128.m128_f32[2] * v5) - v7;
  this->m_implicitShapeDimensions.mVec128.m128_f32[0] = (float)(this->m_localScaling.mVec128.m128_f32[0] * v3) - v8;
  this->m_implicitShapeDimensions.mVec128.m128_f32[1] = v9;
  this->m_implicitShapeDimensions.mVec128.m128_f32[2] = v10;
  this->m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
}
