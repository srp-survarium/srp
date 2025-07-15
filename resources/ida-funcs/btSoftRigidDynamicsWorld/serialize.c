void __thiscall btSoftRigidDynamicsWorld::serialize(btSoftRigidDynamicsWorld *this, btSerializer *serializer)
{
  btCollisionObject *v4; // edi
  unsigned int v5; // eax
  const char *v6; // eax
  btCollisionWorld *v7; // ecx
  btChunk *v8; // [esp+8h] [ebp-4h]
  int serializera; // [esp+14h] [ebp+8h]

  serializer->startSerialization(serializer);
  for ( serializera = 0; serializera < this->m_collisionObjects.m_size; ++serializera )
  {
    v4 = this->m_collisionObjects.m_data[serializera];
    if ( (v4->m_internalType & 8) != 0 )
    {
      v5 = v4->calculateSerializeBufferSize(v4);
      v8 = serializer->allocate(serializer, v5, 1);
      v6 = v4->serialize(v4, v8->m_oldPtr, serializer);
      serializer->finalizeChunk(serializer, v8, v6, 1497645651, v4);
    }
  }
  btDiscreteDynamicsWorld::serializeRigidBodies(serializer, this);
  btCollisionWorld::serializeCollisionObjects(v7, (int)this, serializer);
  serializer->finishSerialization(serializer);
}
