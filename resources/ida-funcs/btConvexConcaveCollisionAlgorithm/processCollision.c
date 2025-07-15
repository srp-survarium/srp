void __thiscall btConvexConcaveCollisionAlgorithm::processCollision(
        btConvexConcaveCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool m_isSwapped; // al
  btCollisionShape *m_collisionShape; // edi
  btPersistentManifold *m_manifoldPtr; // eax
  btPersistentManifold *v10; // eax
  float collisionMarginTrianglea; // [esp+0h] [ebp-14h]
  btPersistentManifold *collisionMarginTriangle; // [esp+0h] [ebp-14h]
  btCollisionObject *convexBody; // [esp+18h] [ebp+4h]

  m_isSwapped = this->m_isSwapped;
  convexBody = body1;
  if ( m_isSwapped )
    body1 = body0;
  else
    convexBody = body0;
  m_collisionShape = body1->m_collisionShape;
  if ( (unsigned int)(m_collisionShape->m_shapeType - 21) <= 8 && convexBody->m_collisionShape->m_shapeType < 20 )
  {
    collisionMarginTrianglea = m_collisionShape->getMargin(m_collisionShape);
    resultOut->m_manifoldPtr = this->m_btConvexTriangleCallback.m_manifoldPtr;
    btConvexTriangleCallback::setTimeStepAndCounters(
      dispatchInfo,
      resultOut,
      &this->m_btConvexTriangleCallback,
      collisionMarginTrianglea);
    m_manifoldPtr = this->m_btConvexTriangleCallback.m_manifoldPtr;
    m_manifoldPtr->m_body0 = convexBody;
    m_manifoldPtr->m_body1 = body1;
    ((void (__thiscall *)(btCollisionShape *, btConvexTriangleCallback *, btVector3 *, btVector3 *))m_collisionShape->__vftable[1].~btCollisionShape)(
      m_collisionShape,
      &this->m_btConvexTriangleCallback,
      &this->m_btConvexTriangleCallback.m_aabbMin,
      &this->m_btConvexTriangleCallback.m_aabbMax);
    v10 = resultOut->m_manifoldPtr;
    if ( v10->m_cachedPoints )
    {
      collisionMarginTriangle = resultOut->m_manifoldPtr;
      if ( v10->m_body0 == resultOut->m_body0 )
        btPersistentManifold::refreshContactPoints(
          collisionMarginTriangle,
          &resultOut->m_rootTransA,
          &resultOut->m_rootTransB);
      else
        btPersistentManifold::refreshContactPoints(
          collisionMarginTriangle,
          &resultOut->m_rootTransB,
          &resultOut->m_rootTransA);
    }
  }
}
