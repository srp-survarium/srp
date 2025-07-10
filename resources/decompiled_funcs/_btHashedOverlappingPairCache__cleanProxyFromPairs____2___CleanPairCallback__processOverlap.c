bool __thiscall btHashedOverlappingPairCache::cleanProxyFromPairs_::_2_::CleanPairCallback::processOverlap(
        btHashedOverlappingPairCache::cleanProxyFromPairs::__l2::CleanPairCallback *this,
        btBroadphasePair *pair)
{
  btBroadphaseProxy *m_cleanProxy; // ecx

  m_cleanProxy = this->m_cleanProxy;
  if ( pair->m_pProxy0 == m_cleanProxy || pair->m_pProxy1 == m_cleanProxy )
    this->m_pairCache->cleanOverlappingPair(this->m_pairCache, pair, this->m_dispatcher);
  return 0;
}
