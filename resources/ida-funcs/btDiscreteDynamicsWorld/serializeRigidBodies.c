void __userpurge btDiscreteDynamicsWorld::serializeRigidBodies(
        btSerializer *serializer@<esi>,
        btDiscreteDynamicsWorld *this)
{
  btCollisionObject *v3; // edi
  unsigned int v4; // eax
  const char *v5; // eax
  btTypedConstraint *v6; // edi
  unsigned int v7; // eax
  const char *v8; // eax
  btChunk *v9; // [esp+8h] [ebp-4h]
  btChunk *v10; // [esp+8h] [ebp-4h]
  int i; // [esp+14h] [ebp+8h]
  int j; // [esp+14h] [ebp+8h]

  for ( i = 0; i < this->m_collisionObjects.m_size; ++i )
  {
    v3 = this->m_collisionObjects.m_data[i];
    if ( (v3->m_internalType & 2) != 0 )
    {
      v4 = v3->calculateSerializeBufferSize(v3);
      v9 = serializer->allocate(serializer, v4, 1);
      v5 = v3->serialize(v3, v9->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v9, v5, 1497645650, v3);
    }
  }
  for ( j = 0; j < this->m_constraints.m_size; ++j )
  {
    v6 = this->m_constraints.m_data[j];
    v7 = v6->calculateSerializeBufferSize(v6);
    v10 = serializer->allocate(serializer, v7, 1);
    v8 = v6->serialize(v6, v10->m_oldPtr, serializer);
    serializer->finalizeChunk(serializer, v10, v8, 1397641027, v6);
  }
}
