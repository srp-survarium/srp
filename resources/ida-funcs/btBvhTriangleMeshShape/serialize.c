const char *__thiscall btBvhTriangleMeshShape::serialize(
        btBvhTriangleMeshShape *this,
        float *dataBuffer,
        btSerializer *serializer)
{
  void *v5; // eax
  void *v6; // eax
  unsigned int v7; // eax
  const char *v8; // eax
  void *v9; // eax
  unsigned int v10; // eax
  btChunk *v11; // ebx
  const char *v12; // eax
  btChunk *v14; // [esp+18h] [ebp+Ch]

  btCollisionShape::serialize(this, dataBuffer, serializer);
  this->m_meshInterface->serialize(this->m_meshInterface, dataBuffer + 3, serializer);
  dataBuffer[13] = this->m_collisionMargin;
  if ( !this->m_bvh || (serializer->getSerializationFlags(serializer) & 1) != 0 )
  {
    dataBuffer[10] = 0.0;
    goto LABEL_7;
  }
  v5 = serializer->findPointer(serializer, this->m_bvh);
  if ( v5 )
  {
    *((_DWORD *)dataBuffer + 10) = v5;
LABEL_7:
    dataBuffer[11] = 0.0;
    goto LABEL_8;
  }
  v6 = serializer->getUniquePointer(serializer, this->m_bvh);
  dataBuffer[11] = 0.0;
  *((_DWORD *)dataBuffer + 10) = v6;
  v7 = this->m_bvh->calculateSerializeBufferSizeNew(this->m_bvh);
  v14 = serializer->allocate(serializer, v7, 1);
  v8 = this->m_bvh->serialize(this->m_bvh, v14->m_oldPtr, serializer);
  serializer->finalizeChunk(serializer, v14, v8, 1213612625, this->m_bvh);
LABEL_8:
  if ( !this->m_triangleInfoMap || (serializer->getSerializationFlags(serializer) & 2) != 0 )
  {
    dataBuffer[12] = 0.0;
  }
  else
  {
    v9 = serializer->findPointer(serializer, this->m_triangleInfoMap);
    if ( v9 )
    {
      *((_DWORD *)dataBuffer + 12) = v9;
    }
    else
    {
      *((_DWORD *)dataBuffer + 12) = serializer->getUniquePointer(serializer, this->m_triangleInfoMap);
      v10 = this->m_triangleInfoMap->calculateSerializeBufferSize(this->m_triangleInfoMap);
      v11 = serializer->allocate(serializer, v10, 1);
      v12 = this->m_triangleInfoMap->serialize(this->m_triangleInfoMap, v11->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v11, v12, 1346456916, this->m_triangleInfoMap);
    }
  }
  return "btTriangleMeshShapeData";
}
