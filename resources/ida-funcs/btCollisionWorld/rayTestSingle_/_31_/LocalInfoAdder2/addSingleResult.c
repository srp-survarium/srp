void __thiscall btCollisionWorld::rayTestSingle_::_31_::LocalInfoAdder2::addSingleResult(
        btCollisionWorld::rayTestSingle::__l31::LocalInfoAdder2 *this,
        btCollisionWorld::LocalRayResult *r,
        BOOL b)
{
  bool v4; // zf
  btCollisionWorld::LocalShapeInfo shapeInfo; // [esp+8h] [ebp-Ch] BYREF

  shapeInfo.m_triangleIndex = this->m_i;
  v4 = r->m_localShapeInfo == 0;
  shapeInfo.m_shapePart = -1;
  shapeInfo.m_is_shape_index = 1;
  if ( v4 )
    r->m_localShapeInfo = &shapeInfo;
  this->m_userCallback->addSingleResult(this->m_userCallback, r, b);
  this->m_closestHitFraction = this->m_userCallback->m_closestHitFraction;
}
