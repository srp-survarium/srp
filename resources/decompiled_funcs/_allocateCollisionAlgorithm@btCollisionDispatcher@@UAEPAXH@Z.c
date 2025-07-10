void **__thiscall btCollisionDispatcher::allocateCollisionAlgorithm(btCollisionDispatcher *this, unsigned int size)
{
  btPoolAllocator *m_collisionAlgorithmPoolAllocator; // ecx
  void **result; // eax
  void *v4; // edx

  m_collisionAlgorithmPoolAllocator = this->m_collisionAlgorithmPoolAllocator;
  if ( m_collisionAlgorithmPoolAllocator->m_freeCount )
  {
    result = (void **)m_collisionAlgorithmPoolAllocator->m_firstFree;
    v4 = *result;
    --m_collisionAlgorithmPoolAllocator->m_freeCount;
    m_collisionAlgorithmPoolAllocator->m_firstFree = v4;
  }
  else
  {
    ++gNumAlignedAllocs;
    return (void **)sAlignedAllocFunc(size, 16);
  }
  return result;
}
