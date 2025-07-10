void __thiscall btBvhTriangleMeshShape::serializeSingleBvh(btBvhTriangleMeshShape *this, btSerializer *serializer)
{
  unsigned int v3; // eax
  btChunk *v4; // ebx
  const char *v5; // eax

  if ( this->m_bvh )
  {
    v3 = this->m_bvh->calculateSerializeBufferSizeNew(this->m_bvh);
    v4 = serializer->allocate(serializer, v3, 1);
    v5 = this->m_bvh->serialize(this->m_bvh, v4->m_oldPtr, serializer);
    serializer->finalizeChunk(serializer, v4, v5, 1213612625, this->m_bvh);
  }
}
