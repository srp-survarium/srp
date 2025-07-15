BOOL __thiscall btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy_::_2_::RemovePairCallback::processOverlap(
        btHashedOverlappingPairCache::removeOverlappingPairsContainingProxy::__l2::RemovePairCallback *this,
        btBroadphasePair *pair)
{
  btBroadphaseProxy *m_obsoleteProxy; // eax

  m_obsoleteProxy = this->m_obsoleteProxy;
  return pair->m_pProxy0 == m_obsoleteProxy || pair->m_pProxy1 == m_obsoleteProxy;
}
