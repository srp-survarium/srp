void __userpurge btSoftRigidDynamicsWorld::removeSoftBody(
        btSoftRigidDynamicsWorld *this@<ecx>,
        btCollisionWorld *a2@<esi>,
        btSoftBody *body)
{
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)this,
    (int)&a2[3].m_collisionObjects.m_size,
    &body);
  btCollisionWorld::removeCollisionObject(a2, body);
}
