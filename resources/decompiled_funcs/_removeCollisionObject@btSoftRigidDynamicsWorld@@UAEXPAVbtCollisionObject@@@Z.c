void __thiscall btSoftRigidDynamicsWorld::removeCollisionObject(
        btSoftRigidDynamicsWorld *this,
        btRigidBody *collisionObject)
{
  btCollisionObject *v2; // edi
  int m_internalType; // eax
  btSoftRigidDynamicsWorld *v4; // esi

  v2 = collisionObject;
  m_internalType = collisionObject->m_internalType;
  v4 = this;
  if ( m_internalType == 8 )
  {
    btAlignedObjectArray<btSoftBody::Joint *>::remove(
      (btAlignedObjectArray<btSoftBody *> *)this,
      (int)&this->m_softBodies,
      (btSoftBody *const *)&collisionObject);
    this = v4;
LABEL_3:
    btCollisionWorld::removeCollisionObject(this, v2);
    return;
  }
  if ( (m_internalType & 2) == 0 )
    goto LABEL_3;
  this->removeRigidBody(this, collisionObject);
}
