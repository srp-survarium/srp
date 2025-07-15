btNullPairCache *__thiscall btNullPairCache::`scalar deleting destructor'(btNullPairCache *this, char a2)
{
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_overlappingPairArray);
  this->__vftable = (btNullPairCache_vtbl *)&btOverlappingPairCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
