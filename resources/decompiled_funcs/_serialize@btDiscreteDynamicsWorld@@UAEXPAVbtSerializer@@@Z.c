void __thiscall btDiscreteDynamicsWorld::serialize(btDiscreteDynamicsWorld *this, btSerializer *serializer)
{
  btCollisionWorld *v3; // ecx

  serializer->startSerialization(serializer);
  btDiscreteDynamicsWorld::serializeRigidBodies(serializer, this);
  btCollisionWorld::serializeCollisionObjects(v3, serializer);
  serializer->finishSerialization(serializer);
}
