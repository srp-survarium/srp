void __usercall btBoxShape::btBoxShape(btBoxShape *this@<eax>, btConvexInternalShape *boxHalfExtents@<edi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  float m_collisionMargin; // xmm5_4
  btVector3 v5; // [esp+Ch] [ebp-10h]

  v2 = clear_value;
  this->m_userPointer = 0;
  this->m_localScaling.mVec128.m128_i32[0] = (int)v2;
  this->m_localScaling.mVec128.m128_i32[1] = (int)v2;
  this->m_localScaling.mVec128.m128_u64[1] = (unsigned int)v2;
  this->m_collisionMargin = 0.039999999;
  this->m_polyhedron = 0;
  this->__vftable = (btBoxShape_vtbl *)&btBoxShape::`vftable';
  this->m_shapeType = 0;
  btConvexInternalShape::setSafeMargin(boxHalfExtents, (int)this);
  m_collisionMargin = this->m_collisionMargin;
  v5.mVec128.m128_f32[0] = (float)(*(float *)&boxHalfExtents->__vftable * this->m_localScaling.mVec128.m128_f32[0])
                         - m_collisionMargin;
  v5.mVec128.m128_i32[3] = 0;
  v5.mVec128.m128_f32[1] = (float)(this->m_localScaling.mVec128.m128_f32[1] * *(float *)&boxHalfExtents->m_shapeType)
                         - m_collisionMargin;
  v5.mVec128.m128_f32[2] = (float)(this->m_localScaling.mVec128.m128_f32[2] * *(float *)&boxHalfExtents->m_userPointer)
                         - m_collisionMargin;
  this->m_implicitShapeDimensions = (btVector3)v5.mVec128;
}
