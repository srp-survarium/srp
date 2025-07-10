double __thiscall btSphereShape::getMargin(btSphereShape *this)
{
  return this->m_implicitShapeDimensions.mVec128.m128_f32[0] * this->m_localScaling.mVec128.m128_f32[0];
}
