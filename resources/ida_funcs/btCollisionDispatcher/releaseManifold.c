void __thiscall btCollisionDispatcher::releaseManifold(btCollisionDispatcher *this, btPersistentManifold *manifold)
{
  int m_size; // ecx
  btPersistentManifold **m_data; // edx
  int m_index1a; // eax
  btPersistentManifold *v6; // ebx
  btPoolAllocator *m_persistentManifoldPoolAllocator; // esi
  unsigned int m_pool; // eax

  --gNumManifold;
  this->clearManifold(this, manifold);
  m_size = this->m_manifoldsPtr.m_size;
  m_data = this->m_manifoldsPtr.m_data;
  m_index1a = manifold->m_index1a;
  v6 = m_data[m_index1a];
  m_data[m_index1a] = m_data[m_size - 1];
  this->m_manifoldsPtr.m_data[m_size - 1] = v6;
  this->m_manifoldsPtr.m_data[m_index1a]->m_index1a = m_index1a;
  --this->m_manifoldsPtr.m_size;
  m_persistentManifoldPoolAllocator = this->m_persistentManifoldPoolAllocator;
  m_pool = (unsigned int)m_persistentManifoldPoolAllocator->m_pool;
  if ( (unsigned int)manifold < m_pool
    || (unsigned int)manifold >= m_pool
                               + m_persistentManifoldPoolAllocator->m_elemSize
                               * m_persistentManifoldPoolAllocator->m_maxElements )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(manifold);
  }
  else
  {
    manifold->m_objectType = (int)m_persistentManifoldPoolAllocator->m_firstFree;
    ++m_persistentManifoldPoolAllocator->m_freeCount;
    m_persistentManifoldPoolAllocator->m_firstFree = manifold;
  }
}
