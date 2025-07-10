void __userpurge btSoftRigidDynamicsWorld::serializeSoftBodies(
        btSerializer *serializer@<edi>,
        btSoftRigidDynamicsWorld *this)
{
  btSoftRigidDynamicsWorld *v2; // eax
  int i; // ebx
  btCollisionObject **m_data; // ecx
  btCollisionObject *v5; // esi
  unsigned int v6; // eax
  btChunk *v7; // ebp
  const char *v8; // eax

  v2 = this;
  for ( i = 0; i < v2->m_collisionObjects.m_size; ++i )
  {
    m_data = v2->m_collisionObjects.m_data;
    v5 = m_data[i];
    if ( (v5->m_internalType & 8) != 0 )
    {
      v6 = v5->calculateSerializeBufferSize(m_data[i]);
      v7 = serializer->allocate(serializer, v6, 1);
      v8 = v5->serialize(v5, v7->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v7, v8, 1497645651, v5);
      v2 = this;
    }
  }
}
