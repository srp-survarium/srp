void __thiscall btGhostObject::removeOverlappingObjectInternal(
        btGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btDispatcher *dispatcher,
        btBroadphaseProxy *thisProxy)
{
  int m_size; // eax
  int v5; // edx
  btCollisionObject **m_data; // esi
  int v7; // esi

  m_size = this->m_overlappingObjects.m_size;
  v5 = 0;
  if ( m_size > 0 )
  {
    m_data = this->m_overlappingObjects.m_data;
    while ( *m_data != otherProxy->m_clientObject )
    {
      ++v5;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_7;
    }
    m_size = v5;
  }
LABEL_7:
  v7 = this->m_overlappingObjects.m_size;
  if ( m_size < v7 )
  {
    this->m_overlappingObjects.m_data[m_size] = this->m_overlappingObjects.m_data[v7 - 1];
    --this->m_overlappingObjects.m_size;
  }
}
