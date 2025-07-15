void __thiscall btDiscreteDynamicsWorld::removeRigidBody(btDiscreteDynamicsWorld *this, btRigidBody *body)
{
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)this,
    (int)&this->m_nonStaticRigidBodies,
    (btSoftBody *const *)&body);
  btCollisionWorld::removeCollisionObject(this, body);
}
