void __thiscall btHashedOverlappingPairCache::processAllOverlappingPairs(
        btHashedOverlappingPairCache *this,
        btOverlapCallback *callback,
        btDispatcher *dispatcher)
{
  btBroadphasePair *v4; // esi
  int v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( this->m_overlappingPairArray.m_size > 0 )
  {
    v6 = 0;
    do
    {
      v4 = &this->m_overlappingPairArray.m_data[v6];
      if ( callback->processOverlap(callback, v4) )
      {
        this->removeOverlappingPair(this, v4->m_pProxy0, v4->m_pProxy1, dispatcher);
        --gOverlappingPairs;
      }
      else
      {
        ++v5;
        ++v6;
      }
    }
    while ( v5 < this->m_overlappingPairArray.m_size );
  }
}
