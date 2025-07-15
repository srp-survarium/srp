void __thiscall btDiscreteDynamicsWorld::removeCollisionObject(
        btDiscreteDynamicsWorld *this,
        btRigidBody *collisionObject)
{
  if ( ((collisionObject->m_internalType & 2) != 0 ? (unsigned int)collisionObject : 0) != 0 )
    this->removeRigidBody(this, (collisionObject->m_internalType & 2) != 0 ? collisionObject : 0);
  else
    btCollisionWorld::removeCollisionObject(this, collisionObject);
}
