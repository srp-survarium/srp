void __thiscall vostok::physics::bullet_physics_world::remove(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_constraint *constraint)
{
  this->m_dynamicsWorld->removeConstraint(this->m_dynamicsWorld, constraint->m_bt_typed_constraint);
}


void __thiscall vostok::physics::bullet_physics_world::remove(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_rigid_body_base *body)
{
  btSoftRigidDynamicsWorld_vtbl *v3; // edi
  btRigidBody *v4; // eax

  v3 = this->m_dynamicsWorld->__vftable;
  v4 = body->get_rigid_body(body);
  v3->removeRigidBody(this->m_dynamicsWorld, v4);
}


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
