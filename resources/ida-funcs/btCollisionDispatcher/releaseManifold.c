void __thiscall btCollisionDispatcher::releaseManifold(btCollisionDispatcher *this, btPersistentManifold *manifold)
{
  int m_index1a; // ecx
  btPersistentManifold **m_data; // edx
  int v5; // eax
  btPersistentManifold **v6; // edi
  btPersistentManifold *v7; // ebx
  btPoolAllocator *m_persistentManifoldPoolAllocator; // esi

  --gNumManifold;
  this->clearManifold(this, manifold);
  m_index1a = manifold->m_index1a;
  m_data = this->m_manifoldsPtr.m_data;
  v5 = this->m_manifoldsPtr.m_size - 1;
  v6 = &m_data[m_index1a];
  v7 = *v6;
  *v6 = m_data[v5];
  this->m_manifoldsPtr.m_data[v5] = v7;
  this->m_manifoldsPtr.m_data[m_index1a]->m_index1a = m_index1a;
  --this->m_manifoldsPtr.m_size;
  m_persistentManifoldPoolAllocator = this->m_persistentManifoldPoolAllocator;
  if ( btPoolAllocator::validPtr(
         (btPoolAllocator *)m_index1a,
         m_persistentManifoldPoolAllocator,
         (unsigned int)manifold) )
  {
    manifold->m_objectType = (int)m_persistentManifoldPoolAllocator->m_firstFree;
    ++m_persistentManifoldPoolAllocator->m_freeCount;
    m_persistentManifoldPoolAllocator->m_firstFree = manifold;
  }
  else
  {
    btAlignedFreeInternal(manifold);
  }
}
