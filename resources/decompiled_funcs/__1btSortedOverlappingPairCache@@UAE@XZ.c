void __thiscall btSortedOverlappingPairCache::~btSortedOverlappingPairCache(btSortedOverlappingPairCache *this)
{
  btBroadphasePair *m_data; // eax

  this->__vftable = (btSortedOverlappingPairCache_vtbl *)&btSortedOverlappingPairCache::`vftable';
  m_data = this->m_overlappingPairArray.m_data;
  if ( m_data )
  {
    if ( this->m_overlappingPairArray.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_overlappingPairArray.m_data = 0;
  }
  this->m_overlappingPairArray.m_data = 0;
  this->m_overlappingPairArray.m_size = 0;
  this->m_overlappingPairArray.m_capacity = 0;
  this->m_overlappingPairArray.m_ownsMemory = 1;
  this->__vftable = (btSortedOverlappingPairCache_vtbl *)&btOverlappingPairCallback::`vftable';
}
