void __thiscall btSortedOverlappingPairCache::setOverlapFilterCallback(
        btSortedOverlappingPairCache *this,
        btOverlapFilterCallback *callback)
{
  this->m_overlapFilterCallback = callback;
}
