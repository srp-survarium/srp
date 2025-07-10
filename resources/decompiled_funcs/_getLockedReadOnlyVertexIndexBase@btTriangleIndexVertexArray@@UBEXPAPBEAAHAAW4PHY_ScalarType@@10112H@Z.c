void __thiscall btTriangleIndexVertexArray::getLockedReadOnlyVertexIndexBase(
        btTriangleIndexVertexArray *this,
        const unsigned __int8 **vertexbase,
        int *numverts,
        PHY_ScalarType *type,
        int *vertexStride,
        const unsigned __int8 **indexbase,
        int *indexstride,
        int *numfaces,
        PHY_ScalarType *indicestype,
        int subpart)
{
  btIndexedMesh *v10; // eax

  v10 = &this->m_indexedMeshes.m_data[subpart];
  *numverts = v10->m_numVertices;
  *vertexbase = v10->m_vertexBase;
  *type = v10->m_vertexType;
  *vertexStride = v10->m_vertexStride;
  *numfaces = v10->m_numTriangles;
  *indexbase = v10->m_triangleIndexBase;
  *indexstride = v10->m_triangleIndexStride;
  *indicestype = v10->m_indexType;
}
