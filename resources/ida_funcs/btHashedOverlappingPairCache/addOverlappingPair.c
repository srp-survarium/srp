btBroadphasePair *__thiscall btHashedOverlappingPairCache::addOverlappingPair(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  bool v3; // al

  v3 = 1;
  ++gAddedPairs;
  if ( this->m_overlapFilterCallback )
  {
    v3 = this->m_overlapFilterCallback->needBroadphaseCollision(this->m_overlapFilterCallback, proxy0, proxy1);
  }
  else
  {
    LOWORD(this) = proxy0->m_collisionFilterGroup;
    if ( ((unsigned __int16)this & proxy1->m_collisionFilterMask) == 0
      || (proxy0->m_collisionFilterMask & proxy1->m_collisionFilterGroup) == 0 )
    {
      v3 = 0;
    }
  }
  if ( v3 )
    return btHashedOverlappingPairCache::internalAddPair(this, proxy0, proxy1);
  else
    return 0;
}
