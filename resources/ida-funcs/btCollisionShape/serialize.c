const char *__thiscall btCollisionShape::serialize(
        btCollisionShape *this,
        _DWORD *dataBuffer,
        btSerializer *serializer)
{
  const char *v4; // edi
  void *v5; // eax

  v4 = serializer->findNameForPointer(serializer, this);
  v5 = serializer->getUniquePointer(serializer, v4);
  *dataBuffer = v5;
  if ( v5 )
    serializer->serializeName(serializer, v4);
  dataBuffer[1] = this->m_shapeType;
  return "btCollisionShapeData";
}
