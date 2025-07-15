void __thiscall btConvexConcaveCollisionAlgorithm::getAllContactManifolds(
        btConvexConcaveCollisionAlgorithm *this,
        btAlignedObjectArray<btPersistentManifold *> *manifoldArray)
{
  btConvexConcaveCollisionAlgorithm *v2; // ebx
  int m_capacity; // ecx
  int m_size; // eax
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  btPersistentManifold **v9; // eax
  btPersistentManifold **v10; // eax
  btPersistentManifold **v12; // [esp+10h] [ebp+8h]

  v2 = this;
  if ( this->m_btConvexTriangleCallback.m_manifoldPtr )
  {
    m_capacity = manifoldArray->m_capacity;
    m_size = manifoldArray->m_size;
    if ( m_size == m_capacity )
    {
      v6 = m_size ? 2 * m_size : 1;
      if ( m_capacity < v6 )
      {
        if ( v6 )
          v12 = (btPersistentManifold **)btAlignedAllocInternal(4 * v6);
        else
          v12 = 0;
        v7 = manifoldArray->m_size;
        v8 = 0;
        if ( v7 > 0 )
        {
          v9 = v12;
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
        if ( manifoldArray->m_data )
        {
          if ( manifoldArray->m_ownsMemory )
            btAlignedFreeInternal(manifoldArray->m_data);
          manifoldArray->m_data = 0;
        }
        manifoldArray->m_ownsMemory = 1;
        manifoldArray->m_data = v12;
        manifoldArray->m_capacity = v6;
      }
    }
    v10 = &manifoldArray->m_data[manifoldArray->m_size];
    if ( v10 )
      *v10 = v2->m_btConvexTriangleCallback.m_manifoldPtr;
    ++manifoldArray->m_size;
  }
}
