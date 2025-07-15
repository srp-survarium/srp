const char *__thiscall btBvhTriangleMeshShape::serialize(
        btBvhTriangleMeshShape *this,
        char *dataBuffer,
        btSerializer *serializer)
{
  void *v4; // eax
  unsigned int v5; // eax
  btChunk *v6; // ebp
  const char *v7; // eax
  void *v8; // eax
  unsigned int v10; // eax
  btChunk *v11; // ebx
  const char *v12; // eax

  btCollisionShape::serialize(this, dataBuffer, serializer);
  this->m_meshInterface->serialize(this->m_meshInterface, dataBuffer + 12, serializer);
  *((float *)dataBuffer + 13) = this->m_collisionMargin;
  if ( !this->m_bvh || (serializer->getSerializationFlags(serializer) & 1) != 0 )
  {
    *((_DWORD *)dataBuffer + 10) = 0;
    goto LABEL_7;
  }
  v4 = serializer->findPointer(serializer, this->m_bvh);
  if ( v4 )
  {
    *((_DWORD *)dataBuffer + 10) = v4;
LABEL_7:
    *((_DWORD *)dataBuffer + 11) = 0;
    goto LABEL_8;
  }
  *((_DWORD *)dataBuffer + 10) = serializer->getUniquePointer(serializer, this->m_bvh);
  *((_DWORD *)dataBuffer + 11) = 0;
  v5 = this->m_bvh->calculateSerializeBufferSizeNew(this->m_bvh);
  v6 = serializer->allocate(serializer, v5, 1);
  v7 = this->m_bvh->serialize(this->m_bvh, v6->m_oldPtr, serializer);
  serializer->finalizeChunk(serializer, v6, v7, 1213612625, this->m_bvh);
LABEL_8:
  if ( !this->m_triangleInfoMap || (serializer->getSerializationFlags(serializer) & 2) != 0 )
  {
    *((_DWORD *)dataBuffer + 12) = 0;
    return "btTriangleMeshShapeData";
  }
  else
  {
    v8 = serializer->findPointer(serializer, this->m_triangleInfoMap);
    if ( v8 )
    {
      *((_DWORD *)dataBuffer + 12) = v8;
    }
    else
    {
      *((_DWORD *)dataBuffer + 12) = serializer->getUniquePointer(serializer, this->m_triangleInfoMap);
      v10 = this->m_triangleInfoMap->calculateSerializeBufferSize(this->m_triangleInfoMap);
      v11 = serializer->allocate(serializer, v10, 1);
      v12 = this->m_triangleInfoMap->serialize(this->m_triangleInfoMap, v11->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v11, v12, 1346456916, this->m_triangleInfoMap);
    }
    return "btTriangleMeshShapeData";
  }
}
