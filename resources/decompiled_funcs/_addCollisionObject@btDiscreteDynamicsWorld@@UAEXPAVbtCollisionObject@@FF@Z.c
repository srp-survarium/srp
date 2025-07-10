// attributes: thunk
void __thiscall btDiscreteDynamicsWorld::addCollisionObject(
        btDiscreteDynamicsWorld *this,
        btCollisionObject *collisionObject,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask)
{
  btCollisionWorld::addCollisionObject(this, collisionObject, collisionFilterGroup, collisionFilterMask);
}
