btTriangleIndexVertexArray *__thiscall btTriangleIndexVertexArray::`scalar deleting destructor'(
        btTriangleIndexVertexArray *this,
        char a2)
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
  this->m_indexedMeshes.m_ownsMemory = 1;
  this->m_indexedMeshes.m_data = 0;
  this->m_indexedMeshes.m_size = 0;
  this->m_indexedMeshes.m_capacity = 0;
  this->__vftable = (btTriangleIndexVertexArray_vtbl *)&btStridingMeshInterface::`vftable';
  if ( (a2 & 1) != 0 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(this);
  }
  return this;
}
