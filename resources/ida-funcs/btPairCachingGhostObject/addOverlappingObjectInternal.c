void __thiscall btPairCachingGhostObject::addOverlappingObjectInternal(
        btPairCachingGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btBroadphaseProxy *thisProxy)
{
  btBroadphaseProxy *m_broadphaseHandle; // eax
  btPairCachingGhostObject *v4; // ebx
  btAlignedObjectArray<btCollisionObject *> *p_m_overlappingObjects; // esi
  int m_capacity; // ecx
  int m_size; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  _DWORD *v11; // eax
  btCollisionObject **v12; // eax
  btBroadphaseProxy *v14; // [esp+Ch] [ebp-8h]
  btCollisionObject *m_clientObject; // [esp+10h] [ebp-4h] BYREF
  _DWORD *v16; // [esp+20h] [ebp+Ch]

  m_broadphaseHandle = thisProxy;
  v4 = this;
  if ( !thisProxy )
    m_broadphaseHandle = this->m_broadphaseHandle;
  v14 = m_broadphaseHandle;
  p_m_overlappingObjects = &this->m_overlappingObjects;
  m_clientObject = (btCollisionObject *)otherProxy->m_clientObject;
  if ( btAlignedObjectArray<int>::findLinearSearch(
         (btAlignedObjectArray<int> *)&this->m_overlappingObjects,
         (int *)&m_clientObject) == this->m_overlappingObjects.m_size )
  {
    m_capacity = v4->m_overlappingObjects.m_capacity;
    m_size = v4->m_overlappingObjects.m_size;
    if ( m_size == m_capacity )
    {
      v8 = m_size ? 2 * m_size : 1;
      if ( m_capacity < v8 )
      {
        if ( v8 )
          v16 = btAlignedAllocInternal(4 * v8);
        else
          v16 = 0;
        v9 = v4->m_overlappingObjects.m_size;
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v16;
          do
          {
            if ( v11 )
            {
              *v11 = p_m_overlappingObjects->m_data[v10];
              v4 = this;
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        if ( p_m_overlappingObjects->m_data )
        {
          if ( p_m_overlappingObjects->m_ownsMemory )
            btAlignedFreeInternal(p_m_overlappingObjects->m_data);
          p_m_overlappingObjects->m_data = 0;
        }
        p_m_overlappingObjects->m_ownsMemory = 1;
        p_m_overlappingObjects->m_data = (btCollisionObject **)v16;
        p_m_overlappingObjects->m_capacity = v8;
      }
    }
    v12 = &p_m_overlappingObjects->m_data[p_m_overlappingObjects->m_size];
    if ( v12 )
      *v12 = m_clientObject;
    ++p_m_overlappingObjects->m_size;
    v4->m_hashPairCache->addOverlappingPair(v4->m_hashPairCache, v14, otherProxy);
  }
}
