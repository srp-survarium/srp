const char *__thiscall btCylinderShape::serialize(btCylinderShape *this, float *dataBuffer, btSerializer *serializer)
{
  float *v4; // ecx
  btVector3 *p_m_implicitShapeDimensions; // eax
  int v6; // ebx
  double v7; // st7
  float *v8; // ecx
  btVector3 *p_m_localScaling; // eax
  int v10; // ebx
  double v11; // st7

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
  dataBuffer[13] = *(float *)&this->m_upAxis;
  return "btCylinderShapeData";
}
