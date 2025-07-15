void __thiscall btGhostObject::addOverlappingObjectInternal(
        btGhostObject *this,
        btBroadphaseProxy *otherProxy,
        btBroadphaseProxy *thisProxy)
{
  btAlignedObjectArray<btCollisionObject *> *p_m_overlappingObjects; // esi
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  _DWORD *v9; // eax
  btCollisionObject **v10; // eax
  btCollisionObject *m_clientObject; // [esp+8h] [ebp-4h] BYREF
  _DWORD *v12; // [esp+14h] [ebp+8h]

  p_m_overlappingObjects = &this->m_overlappingObjects;
  m_clientObject = (btCollisionObject *)otherProxy->m_clientObject;
  if ( btAlignedObjectArray<int>::findLinearSearch(
         (btAlignedObjectArray<int> *)&this->m_overlappingObjects,
         (int *)&m_clientObject) == this->m_overlappingObjects.m_size )
  {
    m_capacity = p_m_overlappingObjects->m_capacity;
    m_size = p_m_overlappingObjects->m_size;
    if ( m_size == m_capacity )
    {
      v6 = m_size ? 2 * m_size : 1;
      if ( m_capacity < v6 )
      {
        if ( v6 )
          v12 = btAlignedAllocInternal(4 * v6);
        else
          v12 = 0;
        v7 = p_m_overlappingObjects->m_size;
        v8 = 0;
        if ( v7 > 0 )
        {
          v9 = v12;
          do
          {
            if ( v9 )
              *v9 = p_m_overlappingObjects->m_data[v8];
            ++v8;
            ++v9;
          }
          while ( v8 < v7 );
        }
        if ( p_m_overlappingObjects->m_data )
        {
          if ( p_m_overlappingObjects->m_ownsMemory )
            btAlignedFreeInternal(p_m_overlappingObjects->m_data);
          p_m_overlappingObjects->m_data = 0;
        }
        p_m_overlappingObjects->m_ownsMemory = 1;
        p_m_overlappingObjects->m_data = (btCollisionObject **)v12;
        p_m_overlappingObjects->m_capacity = v6;
      }
    }
    v10 = &p_m_overlappingObjects->m_data[p_m_overlappingObjects->m_size];
    if ( v10 )
      *v10 = m_clientObject;
    ++p_m_overlappingObjects->m_size;
  }
}
