void __thiscall btSortedOverlappingPairCache::processAllOverlappingPairs(
        btSortedOverlappingPairCache *this,
        btOverlapCallback *callback,
        btDispatcher *dispatcher)
{
  int v4; // ebx
  btBroadphasePair *v5; // esi
  int v6; // [esp+Ch] [ebp-4h]

  v4 = 0;
  if ( this->m_overlappingPairArray.m_size > 0 )
  {
    v6 = 0;
    do
    {
      v5 = &this->m_overlappingPairArray.m_data[v6];
      if ( callback->processOverlap(callback, v5) )
      {
        this->cleanOverlappingPair(this, v5, dispatcher);
        v5->m_pProxy0 = 0;
        v5->m_pProxy1 = 0;
        btAlignedObjectArray<btBroadphasePair>::swap(
          &this->m_overlappingPairArray,
          v4,
          this->m_overlappingPairArray.m_size - 1);
        --this->m_overlappingPairArray.m_size;
        --gOverlappingPairs;
      }
      else
      {
        ++v4;
        ++v6;
      }
    }
    while ( v4 < this->m_overlappingPairArray.m_size );
  }
}
