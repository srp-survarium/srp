void __thiscall btCollisionDispatcher::freeCollisionAlgorithm(btCollisionDispatcher *this, void **ptr)
{
  btPoolAllocator *m_collisionAlgorithmPoolAllocator; // eax
  unsigned int m_pool; // edx

  m_collisionAlgorithmPoolAllocator = this->m_collisionAlgorithmPoolAllocator;
  if ( ptr )
  {
    m_pool = (unsigned int)m_collisionAlgorithmPoolAllocator->m_pool;
    if ( (unsigned int)ptr < m_pool
      || (unsigned int)ptr >= m_pool
                            + m_collisionAlgorithmPoolAllocator->m_elemSize
                            * m_collisionAlgorithmPoolAllocator->m_maxElements )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(ptr);
    }
    else
    {
      *ptr = m_collisionAlgorithmPoolAllocator->m_firstFree;
      ++m_collisionAlgorithmPoolAllocator->m_freeCount;
      m_collisionAlgorithmPoolAllocator->m_firstFree = ptr;
    }
  }
}
