void __thiscall btTriangleIndexVertexArray::~btTriangleIndexVertexArray(btTriangleIndexVertexArray *this)
{
  btIndexedMesh *m_data; // eax

  this->__vftable = (btTriangleIndexVertexArray_vtbl *)&btTriangleIndexVertexArray::`vftable';
  m_data = this->m_indexedMeshes.m_data;
  if ( m_data )
  {
    if ( this->m_indexedMeshes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_indexedMeshes.m_data = 0;
  }
  this->m_indexedMeshes.m_data = 0;
  this->m_indexedMeshes.m_size = 0;
  this->m_indexedMeshes.m_capacity = 0;
  this->m_indexedMeshes.m_ownsMemory = 1;
  this->__vftable = (btTriangleIndexVertexArray_vtbl *)&btStridingMeshInterface::`vftable';
}
