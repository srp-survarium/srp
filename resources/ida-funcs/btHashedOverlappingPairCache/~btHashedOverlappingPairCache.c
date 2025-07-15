void __thiscall btHashedOverlappingPairCache::~btHashedOverlappingPairCache(btHashedOverlappingPairCache *this)
{
  int *m_data; // eax
  int *v3; // eax
  btBroadphasePair *v4; // eax

  this->__vftable = (btHashedOverlappingPairCache_vtbl *)&btHashedOverlappingPairCache::`vftable';
  m_data = this->m_next.m_data;
  if ( m_data )
  {
    if ( this->m_next.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_next.m_data = 0;
  }
  this->m_next.m_ownsMemory = 1;
  this->m_next.m_data = 0;
  this->m_next.m_size = 0;
  this->m_next.m_capacity = 0;
  v3 = this->m_hashTable.m_data;
  if ( v3 )
  {
    if ( this->m_hashTable.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    this->m_hashTable.m_data = 0;
  }
  this->m_hashTable.m_ownsMemory = 1;
  this->m_hashTable.m_data = 0;
  this->m_hashTable.m_size = 0;
  this->m_hashTable.m_capacity = 0;
  v4 = this->m_overlappingPairArray.m_data;
  if ( v4 )
  {
    if ( this->m_overlappingPairArray.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
    this->m_overlappingPairArray.m_data = 0;
  }
  this->m_overlappingPairArray.m_data = 0;
  this->m_overlappingPairArray.m_size = 0;
  this->m_overlappingPairArray.m_capacity = 0;
  this->m_overlappingPairArray.m_ownsMemory = 1;
  this->__vftable = (btHashedOverlappingPairCache_vtbl *)&btOverlappingPairCallback::`vftable';
}
