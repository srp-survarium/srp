void __thiscall btPairCachingGhostObject::removeOverlappingObjectInternal(
        btPairCachingGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btDispatcher *dispatcher,
        btBroadphaseProxy *thisProxy1)
{
  btBroadphaseProxy *m_broadphaseHandle; // ebx
  int m_size; // eax
  int v6; // edx
  btCollisionObject **m_data; // esi
  int v8; // esi

  m_broadphaseHandle = thisProxy1;
  if ( !thisProxy1 )
    m_broadphaseHandle = this->m_broadphaseHandle;
  m_size = this->m_overlappingObjects.m_size;
  v6 = 0;
  if ( m_size > 0 )
  {
    m_data = this->m_overlappingObjects.m_data;
    while ( *m_data != otherProxy->m_clientObject )
    {
      ++v6;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_9;
    }
    m_size = v6;
  }
LABEL_9:
  v8 = this->m_overlappingObjects.m_size;
  if ( m_size < v8 )
  {
    this->m_overlappingObjects.m_data[m_size] = this->m_overlappingObjects.m_data[v8 - 1];
    --this->m_overlappingObjects.m_size;
    this->m_hashPairCache->removeOverlappingPair(this->m_hashPairCache, m_broadphaseHandle, otherProxy, dispatcher);
  }
}
