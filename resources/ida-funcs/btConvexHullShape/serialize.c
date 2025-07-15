const char *__thiscall btConvexHullShape::serialize(
        btConvexHullShape *this,
        float *dataBuffer,
        btSerializer *serializer)
{
  float *v4; // ecx
  btVector3 *p_m_implicitShapeDimensions; // eax
  int v6; // ebx
  double v7; // st7
  float *v8; // ecx
  btVector3 *p_m_localScaling; // eax
  int v10; // ebx
  double v11; // st7
  int m_size; // ebx
  void *v13; // eax
  float *m_oldPtr; // eax
  float *v16; // edx
  char *v17; // ecx
  int v18; // ebx
  btChunk *v20; // [esp+Ch] [ebp-4h]
  int v21; // [esp+18h] [ebp+8h]
  int v22; // [esp+1Ch] [ebp+Ch]

  btCollisionShape::serialize(this, dataBuffer, serializer);
  v4 = dataBuffer + 7;
  p_m_implicitShapeDimensions = &this->m_implicitShapeDimensions;
  v6 = 4;
  do
  {
    v7 = p_m_implicitShapeDimensions->mVec128.m128_f32[0];
    p_m_implicitShapeDimensions = (btVector3 *)((char *)p_m_implicitShapeDimensions + 4);
    *v4++ = v7;
    --v6;
  }
  while ( v6 );
  v8 = dataBuffer + 3;
  p_m_localScaling = &this->m_localScaling;
  v10 = 4;
  do
  {
    v11 = p_m_localScaling->mVec128.m128_f32[0];
    p_m_localScaling = (btVector3 *)((char *)p_m_localScaling + 4);
    *v8++ = v11;
    --v10;
  }
  while ( v10 );
  dataBuffer[11] = this->m_collisionMargin;
  m_size = this->m_unscaledPoints.m_size;
  *((_DWORD *)dataBuffer + 15) = m_size;
  if ( m_size )
    v13 = serializer->getUniquePointer(serializer, this->m_unscaledPoints.m_data);
  else
    v13 = 0;
  dataBuffer[14] = 0.0;
  *((_DWORD *)dataBuffer + 13) = v13;
  if ( m_size )
  {
    v20 = serializer->allocate(serializer, 16, m_size);
    m_oldPtr = (float *)v20->m_oldPtr;
    if ( m_size > 0 )
    {
      v22 = 0;
      v21 = m_size;
      do
      {
        v16 = m_oldPtr;
        v17 = (char *)((char *)&this->m_unscaledPoints.m_data[v22] - (char *)m_oldPtr);
        v18 = 4;
        do
        {
          *v16 = *(float *)((char *)v16 + (_DWORD)v17);
          ++v16;
          --v18;
        }
        while ( v18 );
        ++v22;
        m_oldPtr += 4;
        --v21;
      }
      while ( v21 );
    }
    serializer->finalizeChunk(serializer, v20, "btVector3FloatData", 1497453121, this->m_unscaledPoints.m_data);
  }
  return "btConvexHullShapeData";
}
