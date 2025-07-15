void __thiscall btHashedOverlappingPairCache::~btHashedOverlappingPairCache(btHashedOverlappingPairCache *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx

  this->__vftable = (btHashedOverlappingPairCache_vtbl *)&btHashedOverlappingPairCache::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_next);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v2, (int)&this->m_hashTable);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&this->m_overlappingPairArray);
  this->__vftable = (btHashedOverlappingPairCache_vtbl *)&btOverlappingPairCallback::`vftable';
}
