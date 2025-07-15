void __thiscall btPairCachingGhostObject::removeOverlappingObjectInternal(
        btPairCachingGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btDispatcher *dispatcher,
        btBroadphaseProxy *thisProxy1)
{
  btBroadphaseProxy *m_broadphaseHandle; // ebx
  int LinearSearch; // eax
  int m_size; // edx
  void *m_clientObject; // [esp+Ch] [ebp-4h] BYREF

  m_broadphaseHandle = thisProxy1;
  m_clientObject = otherProxy->m_clientObject;
  if ( !thisProxy1 )
    m_broadphaseHandle = this->m_broadphaseHandle;
  LinearSearch = btAlignedObjectArray<int>::findLinearSearch(
                   (btAlignedObjectArray<int> *)&this->m_overlappingObjects,
                   (int *)&m_clientObject);
  m_size = this->m_overlappingObjects.m_size;
  if ( LinearSearch < m_size )
  {
    this->m_overlappingObjects.m_data[LinearSearch] = this->m_overlappingObjects.m_data[m_size - 1];
    --this->m_overlappingObjects.m_size;
    this->m_hashPairCache->removeOverlappingPair(this->m_hashPairCache, m_broadphaseHandle, otherProxy, dispatcher);
  }
}
