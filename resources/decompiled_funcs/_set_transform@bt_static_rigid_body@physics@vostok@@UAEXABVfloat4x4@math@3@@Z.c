void __thiscall vostok::physics::bt_static_rigid_body::set_transform(
        vostok::physics::bt_static_rigid_body *this,
        const vostok::math::float4x4 *transform)
{
  const btTransform *v3; // eax

  v3 = vostok::physics::from_vostok(transform);
  btCollisionObject::setWorldTransform(this->m_bt_body, v3);
  btCollisionObject::setInterpolationWorldTransform(this->m_bt_body, &this->m_bt_body->m_worldTransform);
}
