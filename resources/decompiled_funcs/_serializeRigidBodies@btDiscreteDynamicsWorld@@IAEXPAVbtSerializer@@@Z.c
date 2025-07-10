void __userpurge btDiscreteDynamicsWorld::serializeRigidBodies(
        btSerializer *serializer@<esi>,
        btDiscreteDynamicsWorld *this)
{
  btDiscreteDynamicsWorld *v2; // ebp
  int v3; // eax
  btCollisionObject *v4; // edi
  unsigned int v5; // eax
  btChunk *v6; // ebx
  const char *v7; // eax
  int v8; // ebx
  btTypedConstraint *v9; // edi
  unsigned int v10; // eax
  btChunk *v11; // ebp
  const char *v12; // eax
  int i; // [esp+38h] [ebp-4h]

  v2 = this;
  v3 = 0;
  for ( i = 0; v3 < this->m_collisionObjects.m_size; i = v3 )
  {
    v4 = this->m_collisionObjects.m_data[v3];
    if ( (v4->m_internalType & 2) != 0 )
    {
      v5 = v4->calculateSerializeBufferSize(v4);
      v6 = serializer->allocate(serializer, v5, 1);
      v7 = v4->serialize(v4, v6->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v6, v7, 1497645650, v4);
      v3 = i;
    }
    ++v3;
  }
  v8 = 0;
  if ( this->m_constraints.m_size > 0 )
  {
    while ( 1 )
    {
      v9 = v2->m_constraints.m_data[v8];
      v10 = v9->calculateSerializeBufferSize(v9);
      v11 = serializer->allocate(serializer, v10, 1);
      v12 = v9->serialize(v9, v11->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v11, v12, 1397641027, v9);
      if ( ++v8 >= this->m_constraints.m_size )
        break;
      v2 = this;
    }
  }
}
