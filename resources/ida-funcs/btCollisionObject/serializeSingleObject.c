void __thiscall btCollisionObject::serializeSingleObject(btCollisionObject *this, btSerializer *serializer)
{
  unsigned int v3; // eax
  btChunk *v4; // ebx
  const char *v5; // eax

  v3 = this->calculateSerializeBufferSize(this);
  v4 = serializer->allocate(serializer, v3, 1);
  v5 = this->serialize(this, v4->m_oldPtr, serializer);
  serializer->finalizeChunk(serializer, v4, v5, 1245859651, this);
}
