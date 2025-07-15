const char *__thiscall btCollisionShape::serialize(
        btCollisionShape *this,
        _DWORD *dataBuffer,
        btSerializer *serializer)
{
  void *v5; // eax
  const char *v7; // [esp+18h] [ebp+Ch]

  v7 = serializer->findNameForPointer(serializer, this);
  v5 = serializer->getUniquePointer(serializer, v7);
  *dataBuffer = v5;
  if ( v5 )
    serializer->serializeName(serializer, v7);
  dataBuffer[1] = this->m_shapeType;
  return "btCollisionShapeData";
}
