void __userpurge btSoftBodyConcaveCollisionAlgorithm::processCollision(
        btSoftBodyConcaveCollisionAlgorithm *this@<ecx>,
        struct btManifoldResult *a2@<ebx>,
        btCollisionObject *body0,
        btCollisionObject *body1,
        const btDispatcherInfo *dispatchInfo,
        btManifoldResult *resultOut)
{
  btCollisionShape *m_collisionShape; // esi
  btSoftBodyTriangleCallback *v9; // ecx
  float v10; // [esp+10h] [ebp+8h]

  if ( !this->m_isSwapped )
    body0 = body1;
  m_collisionShape = body0->m_collisionShape;
  if ( (unsigned int)(m_collisionShape->m_shapeType - 21) <= 8 )
  {
    v10 = m_collisionShape->getMargin(m_collisionShape);
    btSoftBodyTriangleCallback::setTimeStepAndCounters(
      v9,
      dispatchInfo,
      (const float *)this,
      v10,
      &this->m_btSoftBodyTriangleCallback,
      resultOut,
      a2);
    ((void (__thiscall *)(btCollisionShape *, btSoftBodyTriangleCallback *, btVector3 *, btVector3 *))m_collisionShape->__vftable[1].~btCollisionShape)(
      m_collisionShape,
      &this->m_btSoftBodyTriangleCallback,
      &this->m_btSoftBodyTriangleCallback.m_aabbMin,
      &this->m_btSoftBodyTriangleCallback.m_aabbMax);
  }
}
