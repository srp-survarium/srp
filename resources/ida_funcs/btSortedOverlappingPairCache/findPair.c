btBroadphasePair *__thiscall btSortedOverlappingPairCache::findPair(
        btSortedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  bool v4; // al
  int LinearSearch; // eax
  btBroadphasePair key; // [esp+20h] [ebp-10h] BYREF

  if ( this->m_overlapFilterCallback )
    v4 = this->m_overlapFilterCallback->needBroadphaseCollision(this->m_overlapFilterCallback, proxy0, proxy1);
  else
    v4 = (proxy0->m_collisionFilterGroup & proxy1->m_collisionFilterMask) != 0
      && (proxy0->m_collisionFilterMask & proxy1->m_collisionFilterGroup) != 0;
  if ( v4
    && (proxy0->m_uniqueId >= proxy1->m_uniqueId
      ? (key.m_pProxy0 = proxy1, key.m_pProxy1 = proxy0)
      : (key.m_pProxy0 = proxy0, key.m_pProxy1 = proxy1),
        key.m_algorithm = 0,
        key.m_internalTmpValue = 0,
        LinearSearch = btAlignedObjectArray<btBroadphasePair>::findLinearSearch(&this->m_overlappingPairArray, &key),
        LinearSearch < this->m_overlappingPairArray.m_size) )
  {
    return &this->m_overlappingPairArray.m_data[LinearSearch];
  }
  else
  {
    return 0;
  }
}
