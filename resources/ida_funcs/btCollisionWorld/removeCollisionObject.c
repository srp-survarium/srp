void __thiscall btCollisionWorld::removeCollisionObject(btCollisionWorld *this, btCollisionObject *collisionObject)
{
  btCollisionObject *v2; // ebx
  btBroadphaseProxy *m_broadphaseHandle; // edi
  btOverlappingPairCache *v5; // eax

  v2 = collisionObject;
  m_broadphaseHandle = collisionObject->m_broadphaseHandle;
  if ( m_broadphaseHandle )
  {
    v5 = this->m_broadphasePairCache->getOverlappingPairCache(this->m_broadphasePairCache);
    v5->cleanProxyFromPairs(v5, m_broadphaseHandle, this->m_dispatcher1);
    this->m_broadphasePairCache->destroyProxy(this->m_broadphasePairCache, m_broadphaseHandle, this->m_dispatcher1);
    v2->m_broadphaseHandle = 0;
  }
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)&collisionObject,
    (int)&this->m_collisionObjects,
    (btSoftBody *const *)&collisionObject);
}
