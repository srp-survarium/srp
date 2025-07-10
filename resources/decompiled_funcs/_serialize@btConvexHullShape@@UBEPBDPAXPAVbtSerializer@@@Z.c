const char *__thiscall btConvexHullShape::serialize(
        btConvexHullShape *this,
        char *dataBuffer,
        btSerializer *serializer)
{
  int m_size; // ebx
  void *v5; // eax
  btChunk *v6; // eax
  float *m_oldPtr; // edx
  int v8; // edi
  btVector3 *m_data; // ecx
  double v10; // st7
  float *m128_f32; // ecx

  btCollisionShape::serialize(this, dataBuffer, serializer);
  *(btVector3 *)(dataBuffer + 28) = this->m_implicitShapeDimensions;
  *(btVector3 *)(dataBuffer + 12) = this->m_localScaling;
  *((float *)dataBuffer + 11) = this->m_collisionMargin;
  m_size = this->m_unscaledPoints.m_size;
  *((_DWORD *)dataBuffer + 15) = m_size;
  if ( m_size )
    v5 = serializer->getUniquePointer(serializer, this->m_unscaledPoints.m_data);
  else
    v5 = 0;
  *((_DWORD *)dataBuffer + 13) = v5;
  *((_DWORD *)dataBuffer + 14) = 0;
  if ( m_size )
  {
    v6 = serializer->allocate(serializer, 16, m_size);
    m_oldPtr = (float *)v6->m_oldPtr;
    if ( m_size > 0 )
    {
      v8 = 0;
      do
      {
        m_data = this->m_unscaledPoints.m_data;
        v10 = m_data[v8].mVec128.m128_f32[0];
        m128_f32 = m_data[v8].mVec128.m128_f32;
        *m_oldPtr = v10;
        ++v8;
        m_oldPtr += 4;
        --m_size;
        *(m_oldPtr - 3) = m128_f32[1];
        *(m_oldPtr - 2) = m128_f32[2];
        *(m_oldPtr - 1) = m128_f32[3];
      }
      while ( m_size );
    }
    serializer->finalizeChunk(serializer, v6, "btVector3FloatData", 1497453121, this->m_unscaledPoints.m_data);
  }
  return "btConvexHullShapeData";
}
