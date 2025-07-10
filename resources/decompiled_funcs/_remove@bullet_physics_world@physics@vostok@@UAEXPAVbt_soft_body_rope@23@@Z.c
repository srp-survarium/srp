void __thiscall vostok::physics::bullet_physics_world::remove(
        vostok::physics::bullet_physics_world *this,
        btSoftBody *body)
{
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // esi
  btCollisionObject *v3; // edi

  m_dynamicsWorld = this->m_dynamicsWorld;
  body = (btSoftBody *)body->__vftable;
  v3 = body;
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)&body,
    (int)&m_dynamicsWorld->m_softBodies,
    &body);
  btCollisionWorld::removeCollisionObject(m_dynamicsWorld, v3);
}
