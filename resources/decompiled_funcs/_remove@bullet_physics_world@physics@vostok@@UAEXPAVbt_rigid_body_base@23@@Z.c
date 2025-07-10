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
