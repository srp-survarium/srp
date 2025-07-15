void **__thiscall btCollisionDispatcher::allocateCollisionAlgorithm(btCollisionDispatcher *this, unsigned int size)
{
  btPoolAllocator *m_collisionAlgorithmPoolAllocator; // ecx
  void **result; // eax
  void *v4; // edx

  m_collisionAlgorithmPoolAllocator = this->m_collisionAlgorithmPoolAllocator;
  if ( !m_collisionAlgorithmPoolAllocator->m_freeCount )
    return (void **)btAlignedAllocInternal(size);
  result = (void **)m_collisionAlgorithmPoolAllocator->m_firstFree;
  v4 = *result;
  --m_collisionAlgorithmPoolAllocator->m_freeCount;
  m_collisionAlgorithmPoolAllocator->m_firstFree = v4;
  return result;
}
