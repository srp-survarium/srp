void __thiscall btSoftBodyConcaveCollisionAlgorithm::processCollision(
        btSoftBodyConcaveCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionShape *m_collisionShape; // edi
  float collisionMarginTriangle; // [esp+Ch] [ebp+4h]

  if ( !this->m_isSwapped )
    body0 = body1;
  m_collisionShape = body0->m_collisionShape;
  if ( (unsigned int)(m_collisionShape->m_shapeType - 21) <= 8 )
  {
    collisionMarginTriangle = m_collisionShape->getMargin(m_collisionShape);
    btSoftBodyTriangleCallback::setTimeStepAndCounters(
      (btSoftBodyTriangleCallback *)resultOut,
      (int)dispatchInfo,
      (int)&this->m_btSoftBodyTriangleCallback,
      collisionMarginTriangle);
    ((void (__thiscall *)(btCollisionShape *, btSoftBodyTriangleCallback *, btVector3 *, btVector3 *))m_collisionShape->__vftable[1].~btCollisionShape)(
      m_collisionShape,
      &this->m_btSoftBodyTriangleCallback,
      &this->m_btSoftBodyTriangleCallback.m_aabbMin,
      &this->m_btSoftBodyTriangleCallback.m_aabbMax);
  }
}
