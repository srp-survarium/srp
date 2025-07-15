void __thiscall btConvexConcaveCollisionAlgorithm::processCollision(
        btConvexConcaveCollisionAlgorithm *this,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  bool m_isSwapped; // al
  btCollisionShape *m_collisionShape; // ebx
  double v9; // st7
  btPersistentManifold *m_manifoldPtr; // eax
  btPersistentManifold *v11; // eax
  btTransform *p_m_rootTransB; // ecx
  btTransform *p_m_rootTransA; // edx
  float v14; // [esp+0h] [ebp-14h]
  btCollisionObject *v15; // [esp+1Ch] [ebp+8h]

  m_isSwapped = this->m_isSwapped;
  v15 = body1;
  if ( m_isSwapped )
    body1 = body0;
  else
    v15 = body0;
  m_collisionShape = body1->m_collisionShape;
  if ( (unsigned int)(m_collisionShape->m_shapeType - 21) <= 8 && v15->m_collisionShape->m_shapeType < 20 )
  {
    v9 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
    resultOut->m_manifoldPtr = this->m_btConvexTriangleCallback.m_manifoldPtr;
    v14 = v9;
    btConvexTriangleCallback::setTimeStepAndCounters(dispatchInfo, &this->m_btConvexTriangleCallback, v14, resultOut);
    m_manifoldPtr = this->m_btConvexTriangleCallback.m_manifoldPtr;
    m_manifoldPtr->m_body0 = v15;
    m_manifoldPtr->m_body1 = body1;
    ((void (__thiscall *)(btCollisionShape *, btConvexTriangleCallback *, btVector3 *, btVector3 *))m_collisionShape->__vftable[1].~btCollisionShape)(
      m_collisionShape,
      &this->m_btConvexTriangleCallback,
      &this->m_btConvexTriangleCallback.m_aabbMin,
      &this->m_btConvexTriangleCallback.m_aabbMax);
    v11 = resultOut->m_manifoldPtr;
    if ( v11->m_cachedPoints )
    {
      if ( v11->m_body0 == resultOut->m_body0 )
      {
        p_m_rootTransB = &resultOut->m_rootTransB;
        p_m_rootTransA = &resultOut->m_rootTransA;
      }
      else
      {
        p_m_rootTransB = &resultOut->m_rootTransA;
        p_m_rootTransA = &resultOut->m_rootTransB;
      }
      btPersistentManifold::refreshContactPoints(
        (btPersistentManifold *)p_m_rootTransB,
        p_m_rootTransA,
        resultOut->m_manifoldPtr);
    }
  }
}
