void __thiscall btPairCachingGhostObject::addOverlappingObjectInternal(
        btPairCachingGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btBroadphaseProxy *thisProxy)
{
  btBroadphaseProxy *m_broadphaseHandle; // eax
  btCollisionObject *m_clientObject; // ebx
  int m_size; // eax
  int v7; // ecx
  btCollisionObject **m_data; // edx
  int m_capacity; // ecx
  int v10; // eax
  int v11; // edi
  btCollisionObject **v12; // ebp
  int v13; // edx
  int v14; // eax
  btCollisionObject **v15; // ecx
  btCollisionObject **v16; // eax
  btCollisionObject **v17; // eax
  btCollisionObject *otherObject; // [esp+8h] [ebp-4h]
  btBroadphaseProxy *thisProxya; // [esp+14h] [ebp+8h]

  m_broadphaseHandle = thisProxy;
  if ( !thisProxy )
    m_broadphaseHandle = this->m_broadphaseHandle;
  m_clientObject = (btCollisionObject *)otherProxy->m_clientObject;
  thisProxya = m_broadphaseHandle;
  m_size = this->m_overlappingObjects.m_size;
  v7 = 0;
  otherObject = (btCollisionObject *)otherProxy->m_clientObject;
  if ( m_size > 0 )
  {
    m_data = this->m_overlappingObjects.m_data;
    while ( *m_data != m_clientObject )
    {
      ++v7;
      ++m_data;
      if ( v7 >= m_size )
        goto LABEL_9;
    }
    m_size = v7;
  }
LABEL_9:
  if ( m_size == this->m_overlappingObjects.m_size )
  {
    m_capacity = this->m_overlappingObjects.m_capacity;
    v10 = this->m_overlappingObjects.m_size;
    if ( v10 == m_capacity )
    {
      v11 = 2 * v10;
      if ( !v10 )
        v11 = 1;
      if ( m_capacity < v11 )
      {
        if ( v11 )
        {
          ++gNumAlignedAllocs;
          v12 = (btCollisionObject **)sAlignedAllocFunc(4 * v11, 16);
        }
        else
        {
          v12 = 0;
        }
        v13 = this->m_overlappingObjects.m_size;
        v14 = 0;
        if ( v13 > 0 )
        {
          v15 = v12;
          do
          {
            if ( v15 )
            {
              *v15 = this->m_overlappingObjects.m_data[v14];
              m_clientObject = otherObject;
            }
            ++v14;
            ++v15;
          }
          while ( v14 < v13 );
        }
        v16 = this->m_overlappingObjects.m_data;
        if ( v16 )
        {
          if ( this->m_overlappingObjects.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v16);
          }
          this->m_overlappingObjects.m_data = 0;
        }
        this->m_overlappingObjects.m_data = v12;
        this->m_overlappingObjects.m_ownsMemory = 1;
        this->m_overlappingObjects.m_capacity = v11;
      }
    }
    v17 = &this->m_overlappingObjects.m_data[this->m_overlappingObjects.m_size];
    if ( v17 )
      *v17 = m_clientObject;
    ++this->m_overlappingObjects.m_size;
    this->m_hashPairCache->addOverlappingPair(this->m_hashPairCache, thisProxya, otherProxy);
  }
}
