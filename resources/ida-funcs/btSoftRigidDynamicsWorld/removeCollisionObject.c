void __thiscall btSoftRigidDynamicsWorld::removeCollisionObject(
        btSoftRigidDynamicsWorld *this,
        btRigidBody *collisionObject)
{
  if ( (collisionObject->m_internalType == 8 ? (unsigned int)collisionObject : 0) != 0 )
    btSoftRigidDynamicsWorld::removeSoftBody(
      this,
      collisionObject->m_internalType == 8 ? (btSoftBody *)collisionObject : 0);
  else
    btDiscreteDynamicsWorld::removeCollisionObject(this, collisionObject);
}
