void __usercall btCylinderShape::btCylinderShape(btCylinderShape *this@<eax>, btConvexInternalShape *halfExtents@<edi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  float m_collisionMargin; // xmm5_4
  btVector3 v5; // [esp+Ch] [ebp-10h]

  v2 = clear_value;
  this->m_shapeType = 35;
  this->m_userPointer = 0;
  this->m_localScaling.mVec128.m128_i32[0] = (int)v2;
  this->m_localScaling.mVec128.m128_i32[1] = (int)v2;
  this->m_localScaling.mVec128.m128_u64[1] = (unsigned int)v2;
  this->m_collisionMargin = 0.039999999;
  this->__vftable = (btCylinderShape_vtbl *)&btCylinderShape::`vftable';
  this->m_upAxis = 1;
  btConvexInternalShape::setSafeMargin(halfExtents, (int)this);
  m_collisionMargin = this->m_collisionMargin;
  v5.mVec128.m128_f32[0] = (float)(*(float *)&halfExtents->__vftable * this->m_localScaling.mVec128.m128_f32[0])
                         - m_collisionMargin;
  v5.mVec128.m128_i32[3] = 0;
  v5.mVec128.m128_f32[1] = (float)(this->m_localScaling.mVec128.m128_f32[1] * *(float *)&halfExtents->m_shapeType)
                         - m_collisionMargin;
  v5.mVec128.m128_f32[2] = (float)(this->m_localScaling.mVec128.m128_f32[2] * *(float *)&halfExtents->m_userPointer)
                         - m_collisionMargin;
  this->m_implicitShapeDimensions = (btVector3)v5.mVec128;
  this->m_shapeType = 13;
}
