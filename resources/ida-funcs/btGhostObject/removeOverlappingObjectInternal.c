void __thiscall btGhostObject::removeOverlappingObjectInternal(
        btGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btDispatcher *dispatcher,
        btBroadphaseProxy *thisProxy)
{
  btAlignedObjectArray<btCollisionObject *> *p_m_overlappingObjects; // esi
  int LinearSearch; // eax
  int m_size; // edx

  p_m_overlappingObjects = &this->m_overlappingObjects;
  otherProxy = (btBroadphaseProxy *)otherProxy->m_clientObject;
  LinearSearch = btAlignedObjectArray<int>::findLinearSearch(
                   (btAlignedObjectArray<int> *)&this->m_overlappingObjects,
                   (int *)&otherProxy);
  m_size = this->m_overlappingObjects.m_size;
  if ( LinearSearch < m_size )
  {
    this->m_overlappingObjects.m_data[LinearSearch] = this->m_overlappingObjects.m_data[m_size - 1];
    --p_m_overlappingObjects->m_size;
  }
}
