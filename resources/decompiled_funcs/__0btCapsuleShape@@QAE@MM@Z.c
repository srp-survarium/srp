void __userpurge btCapsuleShape::btCapsuleShape(btCapsuleShape *this@<eax>, float a2@<xmm2>, unsigned int radius)
{
  const vostok::math::float4x4 *v4; // xmm0_4

  v4 = clear_value;
  this->m_userPointer = 0;
  this->m_localScaling.mVec128.m128_i32[0] = (int)v4;
  this->m_localScaling.mVec128.m128_i32[1] = (int)v4;
  this->m_localScaling.mVec128.m128_u64[1] = (unsigned int)v4;
  this->m_collisionMargin = 0.039999999;
  this->__vftable = (btCapsuleShape_vtbl *)&btCapsuleShape::`vftable';
  this->m_shapeType = 10;
  this->m_upAxis = 1;
  this->m_implicitShapeDimensions.mVec128.m128_f32[0] = *(float *)&radius;
  this->m_implicitShapeDimensions.mVec128.m128_f32[1] = a2 * 0.5;
  this->m_implicitShapeDimensions.mVec128.m128_u64[1] = radius;
}
