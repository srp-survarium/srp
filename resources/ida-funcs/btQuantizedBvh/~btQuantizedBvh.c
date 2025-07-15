void __thiscall btQuantizedBvh::~btQuantizedBvh(btQuantizedBvh *this)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  btAlignedObjectArray<GrahamVector2> *v4; // ecx
  btAlignedObjectArray<GrahamVector2> *v5; // ecx

  this->__vftable = (btQuantizedBvh_vtbl *)&btQuantizedBvh::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_SubtreeHeaders);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    v2,
    (int)&this->m_quantizedContiguousNodes);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&this->m_quantizedLeafNodes);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v4, (int)&this->m_contiguousNodes);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v5, (int)&this->m_leafNodes);
}
