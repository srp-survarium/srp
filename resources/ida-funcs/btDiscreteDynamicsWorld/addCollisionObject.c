// attributes: thunk
void __thiscall btDiscreteDynamicsWorld::addCollisionObject(
        btDiscreteDynamicsWorld *this,
        btCollisionObject *collisionObject,
        int collisionFilterGroup,
        int collisionFilterMask)
{
  btCollisionWorld::addCollisionObject(this, collisionObject, collisionFilterGroup, collisionFilterMask);
}
