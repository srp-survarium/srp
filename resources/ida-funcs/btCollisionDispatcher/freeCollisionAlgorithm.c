void __thiscall btCollisionDispatcher::freeCollisionAlgorithm(btCollisionDispatcher *this, void **ptr)
{
  btPoolAllocator *m_collisionAlgorithmPoolAllocator; // esi

  m_collisionAlgorithmPoolAllocator = this->m_collisionAlgorithmPoolAllocator;
  if ( btPoolAllocator::validPtr((btPoolAllocator *)this, m_collisionAlgorithmPoolAllocator, (unsigned int)ptr) )
  {
    if ( ptr )
    {
      *ptr = m_collisionAlgorithmPoolAllocator->m_firstFree;
      ++m_collisionAlgorithmPoolAllocator->m_freeCount;
      m_collisionAlgorithmPoolAllocator->m_firstFree = ptr;
    }
  }
  else
  {
    btAlignedFreeInternal(ptr);
  }
}
