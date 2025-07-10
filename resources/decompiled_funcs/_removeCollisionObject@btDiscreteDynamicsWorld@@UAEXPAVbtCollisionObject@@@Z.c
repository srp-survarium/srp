void __thiscall btDiscreteDynamicsWorld::removeCollisionObject(
        btDiscreteDynamicsWorld *this,
        btRigidBody *collisionObject)
{
  if ( (collisionObject->m_internalType & 2) != 0 )
    this->removeRigidBody(this, collisionObject);
  else
    btCollisionWorld::removeCollisionObject(this, collisionObject);
}
