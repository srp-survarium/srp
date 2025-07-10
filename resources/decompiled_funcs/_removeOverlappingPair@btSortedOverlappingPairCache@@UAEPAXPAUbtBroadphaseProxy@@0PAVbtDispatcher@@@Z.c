void *__thiscall btSortedOverlappingPairCache::removeOverlappingPair(
        btSortedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1,
        btDispatcher *dispatcher)
{
  int LinearSearch; // eax
  int v6; // edi
  void (__thiscall *cleanOverlappingPair)(struct btSortedOverlappingPairCache *, btBroadphasePair *, btDispatcher *); // edx
  btBroadphasePair *v8; // eax
  void *m_internalInfo1; // [esp+30h] [ebp-14h]
  btBroadphasePair key; // [esp+34h] [ebp-10h] BYREF

  if ( this->hasDeferredRemoval(this) )
    return 0;
  if ( proxy0->m_uniqueId >= proxy1->m_uniqueId )
  {
    key.m_pProxy0 = proxy1;
    key.m_pProxy1 = proxy0;
  }
  else
  {
    key.m_pProxy0 = proxy0;
    key.m_pProxy1 = proxy1;
  }
  key.m_algorithm = 0;
  key.m_internalTmpValue = 0;
  LinearSearch = btAlignedObjectArray<btBroadphasePair>::findLinearSearch(&this->m_overlappingPairArray, &key);
  v6 = LinearSearch;
  if ( LinearSearch >= this->m_overlappingPairArray.m_size )
    return 0;
  cleanOverlappingPair = this->cleanOverlappingPair;
  --gOverlappingPairs;
  v8 = &this->m_overlappingPairArray.m_data[LinearSearch];
  m_internalInfo1 = v8->m_internalInfo1;
  cleanOverlappingPair(this, v8, dispatcher);
  if ( this->m_ghostPairCallback )
    this->m_ghostPairCallback->removeOverlappingPair(this->m_ghostPairCallback, proxy0, proxy1, dispatcher);
  btAlignedObjectArray<btBroadphasePair>::swap(
    &this->m_overlappingPairArray,
    v6,
    this->m_overlappingPairArray.m_capacity - 1);
  --this->m_overlappingPairArray.m_size;
  return m_internalInfo1;
}
