void __thiscall btHashedOverlappingPairCache::setOverlapFilterCallback(
        btHashedOverlappingPairCache *this,
        btOverlapFilterCallback *callback)
{
  this->m_overlapFilterCallback = callback;
}
