void __thiscall btHashedOverlappingPairCache::setInternalGhostPairCallback(
        btHashedOverlappingPairCache *this,
        btOverlappingPairCallback *ghostPairCallback)
{
  this->m_ghostPairCallback = ghostPairCallback;
}
