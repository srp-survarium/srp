void __thiscall vostok::physics::bullet_physics_world::move(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_rigid_body_base *body,
        const vostok::math::float4x4 *new_transform)
{
  vostok::physics::bullet_physics_world_vtbl *v4; // edi
  btRigidBody *v5; // eax

  body->set_transform(body, new_transform);
  if ( body->get_rigid_body(body)->m_broadphaseHandle )
  {
    v4 = this->__vftable;
    v5 = body->get_rigid_body(body);
    v4->update_single_aabb(this, v5);
  }
}
