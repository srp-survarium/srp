void __stdcall btCylinderShape::btCylinderShape(btCylinderShape *this)
{
  const btVector3 *v1; // eax
  btConvexInternalShape *v2; // ecx
  const btVector3 *v3; // edi
  float m_collisionMargin; // xmm5_4
  unsigned __int64 v5; // [esp+14h] [ebp-Ch]

  v3 = v1;
  btConvexInternalShape::btConvexInternalShape(v2, this);
  this->__vftable = (btCylinderShape_vtbl *)&btCylinderShape::`vftable';
  this->m_upAxis = 1;
  btConvexInternalShape::setSafeMargin(this, v3);
  m_collisionMargin = this->m_collisionMargin;
  *(float *)&v5 = (float)(this->m_localScaling.mVec128.m128_f32[1] * v3->mVec128.m128_f32[1]) - m_collisionMargin;
  *((float *)&v5 + 1) = (float)(this->m_localScaling.mVec128.m128_f32[2] * v3->mVec128.m128_f32[2]) - m_collisionMargin;
  this->m_implicitShapeDimensions.mVec128.m128_f32[0] = (float)(this->m_localScaling.mVec128.m128_f32[0]
                                                              * v3->mVec128.m128_f32[0])
                                                      - m_collisionMargin;
  *(unsigned __int64 *)((char *)this->m_implicitShapeDimensions.mVec128.m128_u64 + 4) = v5;
  this->m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
  this->m_shapeType = 13;
}
