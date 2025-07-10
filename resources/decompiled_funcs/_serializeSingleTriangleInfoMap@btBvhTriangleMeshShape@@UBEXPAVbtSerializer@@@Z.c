void __thiscall btBvhTriangleMeshShape::serializeSingleTriangleInfoMap(
        btBvhTriangleMeshShape *this,
        btSerializer *serializer)
{
  unsigned int v3; // eax
  btChunk *v4; // ebx
  const char *v5; // eax

  if ( this->m_triangleInfoMap )
  {
    v3 = this->m_triangleInfoMap->calculateSerializeBufferSize(this->m_triangleInfoMap);
    v4 = serializer->allocate(serializer, v3, 1);
    v5 = this->m_triangleInfoMap->serialize(this->m_triangleInfoMap, v4->m_oldPtr, serializer);
    serializer->finalizeChunk(serializer, v4, v5, 1346456916, this->m_triangleInfoMap);
  }
}
