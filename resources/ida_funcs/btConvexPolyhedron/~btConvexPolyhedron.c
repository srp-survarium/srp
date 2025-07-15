void __thiscall btConvexPolyhedron::~btConvexPolyhedron(btConvexPolyhedron *this)
{
  btVector3 *m_data; // eax
  btVector3 *v3; // eax

  this->__vftable = (btConvexPolyhedron_vtbl *)&btConvexPolyhedron::`vftable';
  m_data = this->m_uniqueEdges.m_data;
  if ( m_data )
  {
    if ( this->m_uniqueEdges.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_uniqueEdges.m_data = 0;
  }
  this->m_uniqueEdges.m_ownsMemory = 1;
  this->m_uniqueEdges.m_data = 0;
  this->m_uniqueEdges.m_size = 0;
  this->m_uniqueEdges.m_capacity = 0;
  btAlignedObjectArray<btFace>::~btAlignedObjectArray<btFace>((btAlignedObjectArray<btFace> *)this, &this->m_faces);
  v3 = this->m_vertices.m_data;
  if ( v3 )
  {
    if ( this->m_vertices.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
    this->m_vertices.m_data = 0;
  }
  this->m_vertices.m_data = 0;
  this->m_vertices.m_size = 0;
  this->m_vertices.m_capacity = 0;
  this->m_vertices.m_ownsMemory = 1;
}
