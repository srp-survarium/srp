void __thiscall btTriangleIndexVertexArray::getLockedVertexIndexBase(
        btTriangleIndexVertexArray *this,
        unsigned __int8 **vertexbase,
        int *numverts,
        PHY_ScalarType *type,
        int *vertexStride,
        unsigned __int8 **indexbase,
        int *indexstride,
        int *numfaces,
        PHY_ScalarType *indicestype,
        int subpart)
{
  btIndexedMesh *v10; // eax

  v10 = &this->m_indexedMeshes.m_data[subpart];
  *numverts = v10->m_numVertices;
  *vertexbase = (unsigned __int8 *)v10->m_vertexBase;
  *type = v10->m_vertexType;
  *vertexStride = v10->m_vertexStride;
  *numfaces = v10->m_numTriangles;
  *indexbase = (unsigned __int8 *)v10->m_triangleIndexBase;
  *indexstride = v10->m_triangleIndexStride;
  *indicestype = v10->m_indexType;
}
