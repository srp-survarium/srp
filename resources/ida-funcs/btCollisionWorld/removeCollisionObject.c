void __thiscall btCollisionWorld::removeCollisionObject(btCollisionWorld *this, btCollisionObject *collisionObject)
{
  btCollisionObject *v2; // edi
  btBroadphaseProxy *m_broadphaseHandle; // ebx
  btOverlappingPairCache *v5; // eax
  btAlignedObjectArray<int> *p_m_collisionObjects; // esi
  int LinearSearch; // eax
  int m_size; // edx
  int *m_data; // ecx
  int *v10; // eax
  int v11; // edi
  int v12; // edx

  v2 = collisionObject;
  m_broadphaseHandle = collisionObject->m_broadphaseHandle;
  if ( m_broadphaseHandle )
  {
    v5 = this->m_broadphasePairCache->getOverlappingPairCache(this->m_broadphasePairCache);
    v5->cleanProxyFromPairs(v5, m_broadphaseHandle, this->m_dispatcher1);
    this->m_broadphasePairCache->destroyProxy(this->m_broadphasePairCache, m_broadphaseHandle, this->m_dispatcher1);
    v2->m_broadphaseHandle = 0;
  }
  p_m_collisionObjects = (btAlignedObjectArray<int> *)&this->m_collisionObjects;
  LinearSearch = btAlignedObjectArray<int>::findLinearSearch(p_m_collisionObjects, (int *)&collisionObject);
  m_size = p_m_collisionObjects->m_size;
  if ( LinearSearch < m_size )
  {
    m_data = p_m_collisionObjects->m_data;
    v10 = &m_data[LinearSearch];
    v11 = *v10;
    v12 = 4 * m_size - 4;
    *v10 = *(int *)((char *)m_data + v12);
    *(int *)((char *)p_m_collisionObjects->m_data + v12) = v11;
    --p_m_collisionObjects->m_size;
  }
}
