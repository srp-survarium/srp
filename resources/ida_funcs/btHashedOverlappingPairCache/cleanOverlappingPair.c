void __thiscall btHashedOverlappingPairCache::cleanOverlappingPair(
        btHashedOverlappingPairCache *this,
        btBroadphasePair *pair,
        btDispatcher *dispatcher)
{
  btCollisionAlgorithm *m_algorithm; // ecx

  m_algorithm = pair->m_algorithm;
  if ( m_algorithm )
  {
    ((void (__thiscall *)(btCollisionAlgorithm *, _DWORD))m_algorithm->~btCollisionAlgorithm)(m_algorithm, 0);
    dispatcher->freeCollisionAlgorithm(dispatcher, pair->m_algorithm);
    pair->m_algorithm = 0;
  }
}
