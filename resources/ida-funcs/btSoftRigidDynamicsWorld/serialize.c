void __thiscall btSoftRigidDynamicsWorld::serialize(btSoftRigidDynamicsWorld *this, btSerializer *serializer)
{
  btCollisionWorld *v3; // ecx

  serializer->startSerialization(serializer);
  btSoftRigidDynamicsWorld::serializeSoftBodies(serializer, this);
  btDiscreteDynamicsWorld::serializeRigidBodies(serializer, this);
  btCollisionWorld::serializeCollisionObjects(v3, (int)this, serializer);
  serializer->finishSerialization(serializer);
}
