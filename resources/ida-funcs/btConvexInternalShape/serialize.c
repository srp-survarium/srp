const char *__thiscall btConvexInternalShape::serialize(
        btConvexInternalShape *this,
        char *dataBuffer,
        btSerializer *serializer)
{
  const char *result; // eax

  btCollisionShape::serialize(this, dataBuffer, serializer);
  *(btVector3 *)(dataBuffer + 28) = this->m_implicitShapeDimensions;
  result = "btConvexInternalShapeData";
  *(btVector3 *)(dataBuffer + 12) = this->m_localScaling;
  *((float *)dataBuffer + 11) = this->m_collisionMargin;
  return result;
}
