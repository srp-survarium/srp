void __thiscall btGhostObject::addOverlappingObjectInternal(
        btGhostObject *this,
        btCollisionObject *otherProxy,
        btBroadphaseProxy *thisProxy)
{
  btCollisionObject *v3; // ebx
  int m_size; // ecx
  int v6; // eax
  btCollisionObject **m_data; // edx
  int m_capacity; // ecx
  int v9; // eax
  int v10; // edi
  btCollisionObject **v11; // ebp
  int v12; // edx
  int v13; // eax
  btCollisionObject **v14; // ecx
  btCollisionObject **v15; // eax
  btCollisionObject **v16; // eax
  btCollisionObject *otherObject; // [esp+Ch] [ebp+4h]

  v3 = (btCollisionObject *)otherProxy->__vftable;
  m_size = this->m_overlappingObjects.m_size;
  v6 = 0;
  otherObject = (btCollisionObject *)otherProxy->__vftable;
  if ( m_size > 0 )
  {
    m_data = this->m_overlappingObjects.m_data;
    while ( *m_data != v3 )
    {
      ++v6;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_7;
    }
    m_size = v6;
  }
LABEL_7:
  if ( m_size == this->m_overlappingObjects.m_size )
  {
    m_capacity = this->m_overlappingObjects.m_capacity;
    v9 = this->m_overlappingObjects.m_size;
    if ( v9 == m_capacity )
    {
      v10 = 2 * v9;
      if ( !v9 )
        v10 = 1;
      if ( m_capacity < v10 )
      {
        if ( v10 )
        {
          ++gNumAlignedAllocs;
          v11 = (btCollisionObject **)sAlignedAllocFunc(4 * v10, 16);
        }
        else
        {
          v11 = 0;
        }
        v12 = this->m_overlappingObjects.m_size;
        v13 = 0;
        if ( v12 > 0 )
        {
          v14 = v11;
          do
          {
            if ( v14 )
            {
              *v14 = this->m_overlappingObjects.m_data[v13];
              v3 = otherObject;
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v12 );
        }
        v15 = this->m_overlappingObjects.m_data;
        if ( v15 )
        {
          if ( this->m_overlappingObjects.m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v15);
          }
          this->m_overlappingObjects.m_data = 0;
        }
        this->m_overlappingObjects.m_data = v11;
        this->m_overlappingObjects.m_ownsMemory = 1;
        this->m_overlappingObjects.m_capacity = v10;
      }
    }
    v16 = &this->m_overlappingObjects.m_data[this->m_overlappingObjects.m_size];
    if ( v16 )
      *v16 = v3;
    ++this->m_overlappingObjects.m_size;
  }
}
