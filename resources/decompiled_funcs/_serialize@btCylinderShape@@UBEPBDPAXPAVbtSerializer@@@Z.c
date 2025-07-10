const char *__thiscall btCylinderShape::serialize(btCylinderShape *this, char *dataBuffer, btSerializer *serializer)
{
  const char *result; // eax

  btCollisionShape::serialize(this, dataBuffer, serializer);
  *(btVector3 *)(dataBuffer + 28) = this->m_implicitShapeDimensions;
  result = "btCylinderShapeData";
  *(btVector3 *)(dataBuffer + 12) = this->m_localScaling;
  *((float *)dataBuffer + 11) = this->m_collisionMargin;
  *((_DWORD *)dataBuffer + 13) = this->m_upAxis;
  return result;
}
