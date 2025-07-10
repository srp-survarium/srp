void __thiscall btCollisionWorld::serialize(btCollisionWorld *this, btSerializer *serializer)
{
  btCollisionWorld *v3; // ecx

  serializer->startSerialization(serializer);
  btCollisionWorld::serializeCollisionObjects(v3, (int)this, serializer);
  serializer->finishSerialization(serializer);
}
