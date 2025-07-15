void __thiscall btHashedOverlappingPairCache::addOverlappingPair(
        btHashedOverlappingPairCache *this,
        btBroadphaseProxy *proxy0,
        btBroadphaseProxy *proxy1)
{
  bool v4; // al

  ++gAddedPairs;
  if ( this->m_overlapFilterCallback )
    v4 = this->m_overlapFilterCallback->needBroadphaseCollision(this->m_overlapFilterCallback, proxy0, proxy1);
  else
    v4 = (proxy0->m_collisionFilterGroup & proxy1->m_collisionFilterMask) != 0
      && (proxy0->m_collisionFilterMask & proxy1->m_collisionFilterGroup) != 0;
  if ( v4 )
    btHashedOverlappingPairCache::internalAddPair(this, (int)this, proxy0, proxy1);
}
