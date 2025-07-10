void __thiscall btSphereSphereCollisionAlgorithm::getAllContactManifolds(
        btSphereSphereCollisionAlgorithm *this,
        btAlignedObjectArray<btPersistentManifold *> *manifoldArray)
{
  btSphereSphereCollisionAlgorithm *v2; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v5; // edi
  btPersistentManifold **v6; // ebp
  int v7; // edx
  int v8; // eax
  btPersistentManifold **v9; // ecx
  btPersistentManifold **m_data; // eax
  btPersistentManifold **v11; // eax

  v2 = this;
  if ( this->m_manifoldPtr && this->m_ownManifold )
  {
    m_capacity = manifoldArray->m_capacity;
    m_size = manifoldArray->m_size;
    if ( m_size == m_capacity )
    {
      v5 = 2 * m_size;
      if ( !m_size )
        v5 = 1;
      if ( m_capacity < v5 )
      {
        if ( v5 )
        {
          ++gNumAlignedAllocs;
          v6 = (btPersistentManifold **)sAlignedAllocFunc(4 * v5, 16);
        }
        else
        {
          v6 = 0;
        }
        v7 = manifoldArray->m_size;
        v8 = 0;
        if ( v7 > 0 )
        {
          v9 = v6;
          do
          {
            if ( v9 )
            {
              *v9 = manifoldArray->m_data[v8];
              v2 = this;
            }
            ++v8;
            ++v9;
          }
          while ( v8 < v7 );
        }
        m_data = manifoldArray->m_data;
        if ( m_data )
        {
          if ( manifoldArray->m_ownsMemory )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(m_data);
          }
          manifoldArray->m_data = 0;
        }
        manifoldArray->m_data = v6;
        manifoldArray->m_ownsMemory = 1;
        manifoldArray->m_capacity = v5;
      }
    }
    v11 = &manifoldArray->m_data[manifoldArray->m_size];
    if ( v11 )
      *v11 = v2->m_manifoldPtr;
    ++manifoldArray->m_size;
  }
}
