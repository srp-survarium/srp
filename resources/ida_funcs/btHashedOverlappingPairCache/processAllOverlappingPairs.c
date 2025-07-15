void __thiscall btHashedOverlappingPairCache::processAllOverlappingPairs(
        btHashedOverlappingPairCache *this,
        btOverlapCallback *callback,
        btDispatcher *dispatcher)
{
  int v3; // ebx
  btBroadphasePair *v5; // esi
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  i = 0;
  while ( i < this->m_overlappingPairArray.m_size )
  {
    v5 = &this->m_overlappingPairArray.m_data[v3];
    if ( callback->processOverlap(callback, v5) )
    {
      this->removeOverlappingPair(this, v5->m_pProxy0, v5->m_pProxy1, dispatcher);
      --gOverlappingPairs;
    }
    else
    {
      ++i;
      ++v3;
    }
  }
}
