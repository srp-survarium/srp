void __thiscall btConvexPolyhedron::~btConvexPolyhedron(btConvexPolyhedron *this)
{
  btAlignedObjectArray<btFace> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx

  this->__vftable = (btConvexPolyhedron_vtbl *)&btConvexPolyhedron::`vftable';
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    (int)&this->m_uniqueEdges);
  btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>(v2, (int)&this->m_faces);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, (int)&this->m_vertices);
}
