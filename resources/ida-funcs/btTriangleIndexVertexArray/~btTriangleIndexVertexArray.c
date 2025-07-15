void __thiscall btTriangleIndexVertexArray::~btTriangleIndexVertexArray(btTriangleIndexVertexArray *this)
{
  this->__vftable = (btTriangleIndexVertexArray_vtbl *)&btTriangleIndexVertexArray::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_indexedMeshes);
  this->__vftable = (btTriangleIndexVertexArray_vtbl *)&btStridingMeshInterface::`vftable';
}
