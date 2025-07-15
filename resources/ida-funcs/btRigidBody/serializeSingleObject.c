void __thiscall btRigidBody::serializeSingleObject(btRigidBody *this, btSerializer *serializer)
{
  btSerializer_vtbl *v2; // ebx
  int v4; // eax
  btChunk *v5; // ebx
  const char *v6; // eax

  v2 = serializer->__vftable;
  v4 = ((int (__thiscall *)(btRigidBody *, int))this->calculateSerializeBufferSize)(this, 1);
  v5 = (btChunk *)((int (__thiscall *)(btSerializer *, int))v2->allocate)(serializer, v4);
  v6 = this->serialize(this, v5->m_oldPtr, serializer);
  serializer->finalizeChunk(serializer, v5, v6, 1497645650, this);
}
